//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "visits.h"
#include "accounts.h"
#include "i_visits.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TVisitsForm *VisitsForm;

extern const char *DBName;
extern __int64 UserID;
extern __int64 ClientID;
extern const char *MoneyFormat;
extern int FormResult;

extern __int64 AbonementID;
extern __int64 AbonementSPAID;

extern bool AdminMode;
extern unsigned char UserGrants[FORMS_COUNT];
//extern double LastAbVisitPrice;
//---------------------------------------------------------------------------

//***************************************************************************
//******************************* CALLBACKS *********************************
//***************************************************************************

//---------------------------------------------------------------------------
static int visits_select(void *NotUsed, int argc, char **argv, char **azColName)
{
    // Date,BegTime,EndTime,ServiceID,PersonalID,Price,RowID
    if((unsigned)VisitsForm->IDs.Length <= VisitsForm->Counter)
        VisitsForm->IDs.Length = VisitsForm->Counter + 10;
    VisitsForm->IDs[VisitsForm->Counter++] = _atoi64(argv[6]);

    // Date - argv[0]
    TDateTime dt;
    if(argv[0])
        dt = atoi(argv[0]);
    else
        dt = 0;

    if((int)dt)
        VisitsForm->sgVisits->Cells[0][VisitsForm->Counter] = dt.DateString();
    else
        VisitsForm->sgVisits->Cells[0][VisitsForm->Counter] = "";

    // BegTime - argv[1]
    if(argv[1])
        dt = atof(argv[1]);
    else
        dt = 0;

    VisitsForm->sgVisits->Cells[1][VisitsForm->Counter] = dt.FormatString("hh:nn");

    // EndTime - argv[2]
    if(argv[2])
        dt = atof(argv[2]);
    else
        dt = 0;

    VisitsForm->sgVisits->Cells[2][VisitsForm->Counter] = dt.FormatString("hh:nn");

    // ServiceID - argv[3]
    __int64 ID;
    if(argv[3])
        ID = _atoi64(argv[3]);
    else
        ID = 0;

    if(ID)
    {
        if(AbonementID)
            SQL_exefun(DBName,("select Name from Services where RowID="+(AnsiString)ID).c_str(),&(VisitsForm->retString));
        else
            SQL_exefun(DBName,
("select '['||b.Name||']'||a.Name from Services a left outer join Services b on a.ParentID=b.RowID where a.RowID="+AnsiString(ID)).c_str(),&(VisitsForm->retString));

        VisitsForm->sgVisits->Cells[3][VisitsForm->Counter] = (VisitsForm->retString);
    }
    else
        VisitsForm->sgVisits->Cells[3][VisitsForm->Counter] = "";

    // PersonID - argv[4]
    if(argv[4])
        ID = _atoi64(argv[4]);
    else
        ID = 0;

    if(ID)
    {
        SQL_exefun(DBName,("select Name from Personal where RowID="+(AnsiString)ID).c_str(),&(VisitsForm->retString));
        VisitsForm->sgVisits->Cells[4][VisitsForm->Counter] = (VisitsForm->retString);
    }
    else
        VisitsForm->sgVisits->Cells[4][VisitsForm->Counter] = "";

    // Price - argv[5]
    double price;
    if(argv[5])
        price = strtof(argv[5]);
    else
        price = 0.0;

    VisitsForm->sgVisits->Cells[5][VisitsForm->Counter] = FormatFloat(MoneyFormat,price).TrimLeft();

    return 0;
}
//---------------------------------------------------------------------------
static int visits_setinfo(void *NotUsed,int argc,char **argv,char **azColName)
{
    if(argv[0])
        VisitsForm->CDate = atof(argv[0]);
    else
        VisitsForm->CDate = 0;

    VisitsForm->CUID = (argv[1])? _atoi64(argv[1]) : -1;

    if(argv[2])
        VisitsForm->EDate = atof(argv[2]);
    else
        VisitsForm->EDate = 0;

    VisitsForm->EUID = (argv[3])? _atoi64(argv[3]) : -1;

    return 0;
}
//---------------------------------------------------------------------------

//***************************************************************************
//*************************** END CALLBACKS *********************************
//***************************************************************************

//---------------------------------------------------------------------------
void __fastcall TVisitsForm::sgVisitsWindowProc(Messages::TMessage& Msg)
{
    sgWindowProc(Msg,sgVisits,VisitsWidths,sgOVisitsWindowProc);
}
//---------------------------------------------------------------------------
__fastcall TVisitsForm::TVisitsForm(TComponent* Owner)
    : TForm(Owner)
{
    fldAlignVisits = "lllllR";

    AbsModified = false;

    if(AdminMode || UserGrants[12] != '0')
    {
        tbDel->Visible = true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TVisitsForm::FormShow(TObject *Sender)
{
    if(AbonementID)
    {
        sgSetHeaders(sgVisits,"Дата","Начало","Конец","Занятие","Тренер","руб.");
        sgSetWidths(sgVisits,&VisitsWidths,100,70,70,250,150);

        cbChoice->Visible = false;
    }
    else
    {
        if(AbonementSPAID)
            cbChoice->Visible = false;

        sgSetHeaders(sgVisits,"Дата","Начало","Конец","Процедура","Специалист","руб.");
        sgSetWidths(sgVisits,&VisitsWidths,100,70,70,300,150);
    }


    UsersCounter = UserInit(DBName,&pUserIDs,&pUsers);

    sgOVisitsWindowProc = sgVisits->WindowProc;
    sgVisits->WindowProc = sgVisitsWindowProc;

    sgVisitsFullUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TVisitsForm::sgVisitsFullUpdate(void)
{
    SQL_BeginTransaction();

    if(AbonementID)
        SQL_exefun(DBName,("select count(*) from Visits where AbonementID="+(AnsiString)AbonementID).c_str(),&retString);
    else
    {
        if(!AbonementSPAID)
        {
            if(cbChoice->ItemIndex > 0)
                SQL_exefun(DBName,("select count(*) from Visits_SPA left outer join Services on ServiceID=Services.RowID where Tag like '~"+(cbChoice->Items->Strings[cbChoice->ItemIndex])+
                    "~%' and AbonementID=0 and ClientID="+AnsiString(ClientID)).c_str(),&retString);
            else
                SQL_exefun(DBName,("select count(*) from Visits_SPA where AbonementID=0 and ClientID="+AnsiString(ClientID)).c_str(),&retString);

        }
        else
            SQL_exefun(DBName,("select count(*) from Visits_SPA where AbonementID="+(AnsiString)AbonementSPAID).c_str(),&retString);
    }
    __int64 SelRowID = (Counter)? IDs[sgVisits->Row-1] : 0;

    int icnt = atoi(retString.c_str());
    sgVisits->RowCount = (!icnt)? 2 : icnt + 1;
    sgVisits->Rows[sgVisits->RowCount-1]->Clear();
    sgVisits->Cells[0][1] = "";

    Counter = 0;
    if(icnt)
    {
        if(IDs.Length < icnt)
            IDs.Length = icnt + 10;

        if(AbonementID)
            SQL_exe(DBName,("select VisitsDate,BegTime,EndTime,ServiceID,PersonID,Price,RowID from Visits where AbonementID="+AnsiString(AbonementID)+" order by VisitsDate desc,CDate desc").c_str(),visits_select);
        else
        {
            if(!AbonementSPAID)
                if(cbChoice->ItemIndex > 0)
                    SQL_exe(DBName,("select Visits_SPADate,BegTime,EndTime,ServiceID,PersonID,Visits_SPA.Price,Visits_SPA.RowID from Visits_SPA left outer join Services on ServiceID=Services.RowID where Tag like '~"+(cbChoice->Items->Strings[cbChoice->ItemIndex])+"~%' and AbonementID=0 and ClientID="+AnsiString(ClientID)+" order by Visits_SPADate desc,Visits_SPA.CDate desc").c_str(),visits_select);
                else
                    SQL_exe(DBName,("select Visits_SPADate,BegTime,EndTime,ServiceID,PersonID,Price,RowID from Visits_SPA where AbonementID=0 and ClientID="+AnsiString(ClientID)+" order by Visits_SPADate desc,CDate desc").c_str(),visits_select);
            else
                SQL_exe(DBName,("select Visits_SPADate,BegTime,EndTime,ServiceID,PersonID,Price,RowID from Visits_SPA where AbonementID="+AnsiString(AbonementSPAID)+" order by Visits_SPADate desc,CDate desc").c_str(),visits_select);
        }
        if(SelRowID)
        {
            unsigned i;
            for(i = 0; i < Counter; i++)
                if(IDs[i] == SelRowID) break;
            if(i == Counter)
                sgVisits->Row = 1;
            else
                sgVisits->Row = i + 1;
        }
        else
            sgVisits->Row = 1;
    }
    else
        sgVisits->Row = 1;

    sgVisitsRowInfo(IDs,sgVisits->Row-1);

    SQL_CancelTransaction();
}
//---------------------------------------------------------------------------
void __fastcall TVisitsForm::sgVisitsRowInfo(DynamicArray<__int64> pID, unsigned cnt)
{
    if((unsigned)pID.Length >= Counter && Counter > 0)
    {
        AnsiString status = "ID: " + (AnsiString)pID[cnt];

        CDate = 0;
        CUID = -1;
        EDate = 0;
        EUID = -1;

        SQL_exe(DBName,("select CDate,CUID,EDate,EUID from Visits where RowID="+(AnsiString)pID[cnt]).c_str(),visits_setinfo);

        unsigned i;
        for(i = 0; i < UsersCounter; i++)
            if(pUserIDs[i] == CUID) break;

        if(i == UsersCounter)
            status += "   C:[unknown - ";
        else
            status += ("   C:[" + pUsers[i] + " - ");

        if((double)CDate == 0)
            status += "?]";
        else
            status += (CDate.DateTimeString() + "]");

        for(i = 0; i < UsersCounter; i++)
            if(pUserIDs[i] == EUID) break;

        if(i == UsersCounter)
            status += "   E:[unknown - ";
        else
            status += ("   E:[" + pUsers[i] + " - ");

        if((double)EDate == 0)
            status += "?]";
        else
            status += (EDate.DateTimeString() + "]");

        sbVisits->SimpleText = status;
    }
    else
    {
        sbVisits->SimpleText = "ID: ";
    }
}
//---------------------------------------------------------------------------
void __fastcall TVisitsForm::sgVisitsDrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
    if(State.Contains(gdFixed))
    {
        sgVisits->Canvas->Font->Style = TFontStyles() << fsBold;
        sgVisits->Canvas->Font->Color = HEADER_COLOR;

        int lft = Rect.Width() - sgVisits->Canvas->TextWidth(sgVisits->Cells[ACol][0]);
        if(lft < 2) lft = 2;
        else lft >>= 1;
        sgVisits->Canvas->TextRect(Rect,Rect.left+lft,Rect.top+1,sgVisits->Cells[ACol][0]);
    }
    else
    {
        if(State.Contains(gdSelected))
        {
            sgVisits->Canvas->Brush->Color = SelColor;
            //SEL_COLOR;
            sgVisits->Canvas->FillRect(Rect);
        }
        else
        {
            sgVisits->Canvas->Brush->Color = clWhite;
            sgVisits->Canvas->FillRect(Rect);
        }

        sgVisits->Canvas->Font->Color = clBlack;
        sgAlignTextDraw(sgVisits,ACol,ARow,Rect,fldAlignVisits);
    }
}
//---------------------------------------------------------------------------
void __fastcall TVisitsForm::tbExitClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TVisitsForm::sgVisitsSelectCell(TObject *Sender, int ACol,
      int ARow, bool &CanSelect)
{
    if(ARow == sgVisits->Row) return;

    sgVisitsRowInfo(IDs,ARow-1);
}
//---------------------------------------------------------------------------
void __fastcall TVisitsForm::FormDestroy(TObject *Sender)
{
    delete [] pUserIDs;
    delete [] pUsers;

    delete [] VisitsWidths;
}
//---------------------------------------------------------------------------
void __fastcall TVisitsForm::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key == VK_ESCAPE)
        Close();    
}
//---------------------------------------------------------------------------
void __fastcall TVisitsForm::cbChoiceSelect(TObject *Sender)
{
    if(cbChoice->Visible)
        sgVisitsFullUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TVisitsForm::tbDelClick(TObject *Sender)
{
    if(!Counter) return;
    __int64 VID = IDs[sgVisits->Row-1];

    if(!VID) return;

    if(AbonementID)
    {
        // Аннулирование услуги Фитнесс (с закрытого?)
        SQL_BeginTransaction();

        SQL_iniUpdate(NULL,"Abonements",AbonementID);
        SQL_exeUpdate("Closed",0);

        SQL_exe(NULL,("delete from Visits where RowID="+AnsiString(VID)).c_str());

        SQL_CommitTransaction();


        sgVisitsFullUpdate();

        AbsModified = true;

        return;
    }

    // Аннулирование услуги SPA
    // Аннулируем
    SQL_BeginTransaction();

    // Было списание товаров?
    AnsiString *pRow;
    const char *pFN[] = { "GoodID", "OutcomeCount", "Part", "RowID" };
    AnsiString sRet[3];

    __int64 ID;
    int cnt = SQL_Collect(NULL,4,pFN,("from Outcome where Visit_SPAID="+AnsiString(VID)).c_str(),NULL,&pRow);

    for(int i = 0; i < cnt; i++)
    {
        // Есть товар - восстанавливаем Stock
        SQL_exefun3(NULL,("select RowID,StockCount,Part from Stock where GoodID="+pRow[i*4]).c_str(),&sRet[0],&sRet[1],&sRet[2]);

        int orate = 1000 * atoi(pRow[(i*4)+1].c_str()) + atoi(pRow[(i*4)+2].c_str());
        int srate = 1000 * atoi(sRet[1].c_str()) + atoi(sRet[2].c_str()) - orate;

        ID = _atoi64(sRet[0].c_str());
        if(ID)
        {
            // Есть запись в Stock-е

            SQL_iniUpdate(DBName,"Stock",ID);
            SQL_addUpdate("StockCount",srate / 1000);
            SQL_exeUpdate("Part",srate % 1000);
        }
        else
        {
            // Ничего нет

            SQL_iniInsert(DBName,"Stock");
            SQL_addInsert("GoodID",pRow[(i*4)]);
            SQL_addInsert("StockCount",srate / 1000);
            SQL_exeInsert("Part",srate % 1000);
        }

        SQL_exe(NULL,("delete from Outcome where RowID="+pRow[(i*4)+3]).c_str());
    }

    delete [] pRow;

    // Далее, это списание с Абонемента?
    if(AbonementSPAID)
    {
        SQL_exefun(NULL,("select Balanse from Abonements_SPA where RowID="+AnsiString(AbonementSPAID)).c_str(),&sRet[0]);
        SQL_exefun(NULL,("select Price from Visits_SPA where RowID="+AnsiString(VID)).c_str(),&sRet[1]);
        SQL_iniUpdate(NULL,"Abonements_SPA",AbonementSPAID);
        SQL_addUpdate("Balanse",atof(sRet[0].c_str())+atof(sRet[1].c_str()));
        SQL_exeUpdate("Closed",0);

        AbsModified = true;
    }
    else
    {
        // Через кассу или автосписание
        SQL_exefun3(NULL,("select RowID,BillID,Price from BillItems where VisitID="+AnsiString(VID)).c_str(),&sRet[0],&sRet[1],&sRet[2]);

        ID = _atoi64(sRet[0].c_str());
        __int64 BID = _atoi64(sRet[1].c_str());

        //if(GetKeyState(VK_CONTROL) & 0x80 || (ID && BID))
        if(ID && BID)
        {
            // Чек найден
            SQL_exefun(NULL,("select Total from Bills where RowID="+AnsiString(BID)).c_str(),&sRet[0]);

            SQL_iniUpdate(NULL,"Bills",BID);
            SQL_exeUpdate("Total",atof(sRet[0].c_str())-atof(sRet[2].c_str()));

            SQL_exe(NULL,("delete from BillItems where RowID="+AnsiString(ID)).c_str());
            SQL_exe(NULL,("delete from AddOp where BillItemsID="+AnsiString(BID)).c_str());
        }
        //else
        //{
        //    SQL_CancelTransaction();
        //   Application->MessageBox("Внимание!\nНе найден чек, аннулирование данной услуги невозможно.","",MB_OK);
        //    return;
        //}
    }


    SQL_exe(NULL,("delete from AddOp where Visits_SPAID="+AnsiString(VID)).c_str());


    SQL_exe(NULL,("delete from Visits_SPA where RowID="+AnsiString(VID)).c_str());

    SQL_CommitTransaction();

    sgVisitsFullUpdate();
}
//---------------------------------------------------------------------------

