//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "resbath.h"
#include "clients.h"
#include "lib.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#define M_COUNT 77
#define F_COUNT 76

TResBathForm *ResBathForm;

extern const char *_DayNames[];
extern __int64 ClientID;
extern __int64 UserID;

//extern __int64 *IDs;
//extern unsigned Counter;
//***************************************************************************
//******************************* CALLBACKS *********************************
//***************************************************************************
//---------------------------------------------------------------------------
//static int resbath_fill(void *NotUsed, int argc, char **argv, char **azColName)
//{
//    return 0;
//}
//---------------------------------------------------------------------------
__fastcall TResBathForm::TResBathForm(TComponent* Owner)
    : TForm(Owner)
{
    DoubleBuffered = true;

    fldAlignM1 = "Lrr";
    //fldAlignM2 = fldAlignM1;
    //fldAlignM3 = fldAlignM1;
    for(int i = 1; i < 31; i++)
    {
        sgM1->Cells[0][i] = i;
        sgM2->Cells[0][i] = i + 30;
        if(i <= M_COUNT - 60)
            sgM3->Cells[0][i] = i + 60;


        sgF1->Cells[0][i] = i;
        sgF2->Cells[0][i] = i + 30;
        if(i <= F_COUNT - 60)
            sgF3->Cells[0][i] = i + 60;
    }

    pFitButtons[0] = sbFitMo;
    pFitButtons[1] = sbFitTu;
    pFitButtons[2] = sbFitWe;
    pFitButtons[3] = sbFitTh;
    pFitButtons[4] = sbFitFr;
    pFitButtons[5] = sbFitSa;
    pFitButtons[6] = sbFitSu;
    pFitButtons[7] = sbFitAlt;

    TDateTime dt = FitCurrentDay = (int)Now();
    int dw = dt.DayOfWeek() - 2;
    if(dw < 0) dw = 6;

    for(int i = 0; i < 8; i++)
    {
        pFitButtons[i]->Caption = AnsiString(_DayNames[dw]) + " / " + dt.FormatString("dd.mm");

        dt++;
        if(++dw > 6) dw = 0;
    }

    pFitButtons[FitCurButton]->Font->Color = clBlack;

    FitCurButton = 0;
    sbFitMo->Down = true;

    pFitButtons[FitCurButton]->Font->Color = clRed;

    EditMode = false;

    sgCur = sgM1;
    ResTime = 0;
}
//---------------------------------------------------------------------------
void __fastcall TResBathForm::FormDestroy(TObject *Sender)
{
    delete [] M1Widths;
}
//---------------------------------------------------------------------------
void __fastcall TResBathForm::sgM1WindowProc(Messages::TMessage& Msg)
{
    sgWindowProc(Msg,sgM1,M1Widths,sgOM1WindowProc);
}

void __fastcall TResBathForm::sgM2WindowProc(Messages::TMessage& Msg)
{
    sgWindowProc(Msg,sgM2,M2Widths,sgOM2WindowProc);
}

void __fastcall TResBathForm::sgM3WindowProc(Messages::TMessage& Msg)
{
    sgWindowProc(Msg,sgM3,M3Widths,sgOM3WindowProc);
}

void __fastcall TResBathForm::sgF1WindowProc(Messages::TMessage& Msg)
{
    sgWindowProc(Msg,sgF1,F1Widths,sgOF1WindowProc);
}

void __fastcall TResBathForm::sgF2WindowProc(Messages::TMessage& Msg)
{
    sgWindowProc(Msg,sgF2,F2Widths,sgOF2WindowProc);
}

void __fastcall TResBathForm::sgF3WindowProc(Messages::TMessage& Msg)
{
    sgWindowProc(Msg,sgF3,F3Widths,sgOF3WindowProc);
}
//---------------------------------------------------------------------------
void __fastcall TResBathForm::FormShow(TObject *Sender)
{
    sgSetHeaders(sgM1,"№","Запись 2","Запись 1");
    sgSetWidths(sgM1,&M1Widths,64,100);

    sgOM1WindowProc = sgM1->WindowProc;
    sgM1->WindowProc = sgM1WindowProc;

    sgSetHeaders(sgM2,"№","Запись 2","Запись 1");
    sgSetWidths(sgM2,&M2Widths,64,100);

    sgOM2WindowProc = sgM2->WindowProc;
    sgM2->WindowProc = sgM2WindowProc;

    sgSetHeaders(sgM3,"№","Запись 2","Запись 1");
    sgSetWidths(sgM3,&M3Widths,64,100);

    sgOM3WindowProc = sgM3->WindowProc;
    sgM3->WindowProc = sgM3WindowProc;

    sgSetHeaders(sgF1,"№","Запись 2","Запись 1");
    sgSetWidths(sgF1,&F1Widths,64,100);

    sgOF1WindowProc = sgF1->WindowProc;
    sgF1->WindowProc = sgF1WindowProc;

    sgSetHeaders(sgF2,"№","Запись 2","Запись 1");
    sgSetWidths(sgF2,&F2Widths,64,100);

    sgOF2WindowProc = sgF2->WindowProc;
    sgF2->WindowProc = sgF2WindowProc;

    sgSetHeaders(sgF3,"№","Запись 2","Запись 1");
    sgSetWidths(sgF3,&F3Widths,64,100);

    sgOF3WindowProc = sgF3->WindowProc;
    sgF3->WindowProc = sgF3WindowProc;

    sgM1->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TResBathForm::sgM1DrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
    TStringGrid *pGrid = (TStringGrid *)Sender;

    if(State.Contains(gdFixed))
    {
        pGrid->Canvas->Font->Style = TFontStyles() << fsBold;
        pGrid->Canvas->Font->Color = HEADER_COLOR;

        pGrid->Canvas->Brush->Color = clBtnFace;
        pGrid->Canvas->FillRect(Rect);

        int lft = Rect.Width() - pGrid->Canvas->TextWidth(pGrid->Cells[ACol][0]);
        if(lft < 2) lft = 2;
        else lft >>= 1;
        Frame3D(pGrid->Canvas,Rect,clBtnHighlight,clBtnShadow,1);
        pGrid->Canvas->TextRect(Rect,Rect.left+lft,Rect.top+1,pGrid->Cells[ACol][0]);
    }
    else
    {
        //pGrid->Canvas->Font->Style = fType;

        if(State.Contains(gdSelected))
           pGrid->Canvas->Brush->Color = SelColor;
        else
        if(ACol > 0)
        {
            int status = (int)pGrid->Rows[ARow]->Objects[0];

            if(ACol == 1)
                status &= 0xFFFF;
            else
                status = (status & 0xFFFF0000) >> 16;

            if(status == 0)
                pGrid->Canvas->Brush->Color = clWhite;
            else if(status == 1)
                pGrid->Canvas->Brush->Color = RGB(250,250,0);
            else
                pGrid->Canvas->Brush->Color = clRed;
        }
        else
            pGrid->Canvas->Brush->Color = clWhite;

        pGrid->Canvas->FillRect(Rect);
        if(sgCli == pGrid && ARow == CliRow && ACol == CliCol)
        //pGrid->Canvas->Font->Color = clGreen;
            //Frame3D(pGrid->Canvas,Rect,clBtnHighlight,clBtnShadow,1);
        Frame3D(pGrid->Canvas,Rect,clBlue,clBlue,1);

        //pGrid->Canvas->Font->Style = TFontStyles() << fType;
      
        pGrid->Canvas->Font->Color = clBlack;
        //fCol;

        sgAlignTextDraw(pGrid,ACol,ARow,Rect,fldAlignM1);


    }
}
//---------------------------------------------------------------------------
void __fastcall TResBathForm::sgM1KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    TStringGrid *g1, *g2, *g3;

    if(pcResBath->ActivePageIndex == 0)
    {
        g1 = sgM1;
        g2 = sgM2;
        g3 = sgM3;
    }
    else
    {
        g1 = sgF1;
        g2 = sgF2;
        g3 = sgF3;
    }

    TStringGrid *pTo, *pGrid = (TStringGrid *)Sender;

    if(Key == VK_LEFT && pGrid->Col == 0)
    {
        pTo = (pGrid == g1)? g3 : (pGrid == g2)? g1 : g2;
        pTo->Col = 2;
        pTo->Row = pGrid->Row;
        pTo->SetFocus();
        Key = 0;
    }
    else if(Key == VK_RIGHT && pGrid->Col == 2)
    {
        pTo = (pGrid == g1)? g2 : (pGrid == g2)? g3 : g1;
        pTo->Col = 0;
        pTo->Row = pGrid->Row;
        pTo->SetFocus();
        Key = 0;
    }
    else if(Key == VK_UP && pGrid->Row == 1)
    {
        pGrid->Row = pGrid->RowCount - 1;
        Key = 0;
    }
    else if(Key == VK_DOWN && pGrid->Row == pGrid->RowCount - 1)
    {
        pGrid->Row = 1;
        Key = 0;
    }
    else if(Key == VK_RETURN)
    {
        //Reserve(pGrid);
        Key = 0;
    }

}
//---------------------------------------------------------------------------
void __fastcall TResBathForm::sbFitMoClick(TObject *Sender)
{
    sgCur->SetFocus();

    pFitButtons[FitCurButton]->Font->Color = clBlack;
    FitCurButton = ((TSpeedButton *)Sender)->Tag - 1;
    ((TSpeedButton *)Sender)->Font->Color = clRed;
    sgResBathSheduleFullUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TResBathForm::TabSheet1Show(TObject *Sender)
{
    sgCur = sgM1;
    sgCur->SetFocus();

    sgResBathSheduleFullUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TResBathForm::TabSheet2Show(TObject *Sender)
{
    sgCur = sgF1;
    sgCur->SetFocus();

    sgResBathSheduleFullUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TResBathForm::sgResBathSheduleFullUpdate(void)
{
    TStringGrid *g1, *g2, *g3;

    if(pcResBath->ActivePageIndex == 0)
    {
        g1 = sgM1;
        g2 = sgM2;
        g3 = sgM3;
    }
    else
    {
        g1 = sgF1;
        g2 = sgF2;
        g3 = sgF3;
    }

    // Чистка
    for(int i = 1; i < 31; i++)
    {
        g1->Cells[1][i] = "";
        g1->Cells[2][i] = "";
        g1->Rows[i]->Objects[0] = NULL;
        g1->Rows[i]->Objects[1] = NULL;
        g1->Rows[i]->Objects[2] = NULL;

        g2->Cells[1][i] = "";
        g2->Cells[2][i] = "";
        g2->Rows[i]->Objects[0] = NULL;
        g2->Rows[i]->Objects[1] = NULL;
        g2->Rows[i]->Objects[2] = NULL;

        g3->Cells[1][i] = "";
        g3->Cells[2][i] = "";
        g3->Rows[i]->Objects[0] = NULL;
        g3->Rows[i]->Objects[1] = NULL;
        g3->Rows[i]->Objects[2] = NULL;
    }

    AnsiString sql =

    "from RESERVE where SERVICEID=";

    sql += BATH_VISIT;
    sql += " and trunc(BEGDATE)=";
    sql += (int)FitCurrentDay + FitCurButton;
    //sql += " and bin_and(b.WEEKDAYS,2)!=0 "
    sql += " and STATUS<=2";

    static const char *pF[] = {"NUM", "BEGDATE", "STATUS", "CLIENTID" };

    AnsiString *pRes;
    //unsigned __fastcall SQL_Collect(const char *,unsigned fld_cnt,const char **fNames,const char *sql_from,const char *sql_order,AnsiString ** pFld,char *mask=NULL);
    unsigned cnt = SQL_Collect(NULL,4,pF,sql.c_str(),"order by 1,2 desc",&pRes);

    int n, num, status;
    __int64 CID;
    TDateTime dt;
    unsigned pos = 0;
    TStringGrid *pGrid = NULL;

    for(unsigned i = 0; i < cnt; i++)
    {
        num = abs(atoi(pRes[pos++].c_str()));
        dt = atof(pRes[pos++].c_str());
        status = atoi(pRes[pos++].c_str());
        CID = _atoi64(pRes[pos++].c_str());

        if(num <= 30)
            pGrid = g1;
        else if(num <= 60)
        {
            pGrid = g2;
            num -= 30;
        }
        else
        {
            pGrid = g3;
            num -= 60;
        }

        n = 2;

        if(pGrid->Cells[2][num].Length() > 0)
            n--;

        pGrid->Cells[n][num] = dt.FormatString("hh:nn");

        // Status записи
        if(n == 1)
            pGrid->Rows[num]->Objects[0] = (TObject *)(status | (int)pGrid->Rows[num]->Objects[0]);
        else
            pGrid->Rows[num]->Objects[0] = (TObject *)((status << 16) | (int)pGrid->Rows[num]->Objects[0]);

        // ClientID
        pGrid->Rows[num]->Objects[n] = (TObject *)CID;
    }

    PDEL(pRes);

    AnsiString sRet;
    double begday = (int)FitCurrentDay + FitCurButton;
    sql = "select BEGDATE-trunc(BEGDATE) from RESERVE where CLIENTID=" + AnsiString(ClientID) + " and SERVICEID=" + AnsiString(BATH_VISIT) + " and trunc(BEGDATE)=" + AnsiString(begday);
    SQL_exefun(NULL,sql.c_str(),&sRet);
    ResTime = TDateTime(ATOF(sRet.c_str()));

    sgCli = NULL;
    int col, row;
    for(row = 0; pGrid && row < pGrid->RowCount; row++)
    {
        col = 1;
        if((unsigned)pGrid->Rows[row]->Objects[col] == ClientID) break;
        col = 2;
        if((unsigned)pGrid->Rows[row]->Objects[col] == ClientID) break;
    }

    if(pGrid && row < pGrid->RowCount)
    {
        sgCli = pGrid;
        CliCol = col;
        CliRow = row;
    }
}
//---------------------------------------------------------------------------
void __fastcall TResBathForm::sgEdit(void)
{
    if(sgCur->Row > 0)
    {
        if(!EditMode)
        {
            TPoint pos;
            GetCursorPos(&pos);
            pos = sgCur->ScreenToClient(pos);

            int Col, Row;

            sgCur->MouseToCell(pos.x,pos.y,Col,Row);

            if(Col < 1)
                Col = 1;
            else if(Col > 2)
                Col = 2;

            sgCur->Col = Col;
        }

        TRect rect = sgCur->CellRect(sgCur->Col,sgCur->Row);
        edInput->Parent = sgCur;
        edInput->Left = rect.Left + 2 + sgCur->Left;
        edInput->Top = rect.Top + sgCur->Top + 2 + sgCur->Top;
        edInput->Width = rect.Width();
        edInput->Height = rect.Height();

        //Date2 = sgCur->Cells[1][sgCur->Row];
        //Date1 = sgCur->Cells[2][sgCur->Row];

        edInput->Text = sgCur->Cells[sgCur->Col][sgCur->Row];

        edInput->Visible = true;
        edInput->SetFocus();
    }

    EditMode = false;
}
//---------------------------------------------------------------------------
void __fastcall TResBathForm::sgM1DblClick(TObject *Sender)
{
    sgCur = (TStringGrid *)Sender;

    if(sgCur->Cells[0][sgCur->Row].Length() == 0) return;

    // Если есть ResTime
    if((double)ResTime > 0)
    {
        if(sgCur != sgCli || CliRow != sgCur->Row || CliCol != sgCur->Col)
        {
            // Заход в эту ячейку?
            Application->MessageBox("Внимание!\nУ клиента уже есть запись на этот день.","Недопустимая операция",ID_OK);
            return;
        }
    }

    if(sgCur->Cells[sgCur->Col][sgCur->Row].Length() != 0)
    {
        if(sgCur != sgCli || CliRow != sgCur->Row || CliCol != sgCur->Col)
        {
            Application->MessageBox("Внимание!\nЗапрещено редактировать чужие записи.","Недопустимая операция",ID_OK);
            return;
        }
    }

    AnsiString sql, sCounter, sRet, sAID;
    unsigned abs_cnt;
    double begday = (int)FitCurrentDay + FitCurButton;

    SQL_exefun(NULL,("select count(*) from Abonements_Bath where Closed=0 and FixSum>=0 and EndDate>="+AnsiString(begday)+" and ClientID="+AnsiString(ClientID)).c_str(),&sCounter);
    abs_cnt = atoi(sCounter.c_str());

    if(!abs_cnt)
    {
        Application->MessageBox("Внимание!\nНет абонементов с доступными посещениями.","Недопустимая операция",ID_OK);
        return;
    }

    SQL_exefun(NULL,("select count(*) from Abonements_Bath where Closed=0 and AbonementsCount=0 and FixSum>0 and ClientID="+AnsiString(ClientID)).c_str(),&sRet);

    CurAb = BATH_VISIT_ALL;

    if(atoi(sRet.c_str()) == 0)
    {
        // Не клубная карта
        AnsiString sql =
        "select ACNT,case when VCNT is null then 0 else VCNT end,RID from "
        "( "
            "select first 1 RowID as RID,AbonementsCount as ACNT from Abonements_Bath where Closed=0 and FixSum>=0 and ClientID=";

        sql += ClientID;
        sql +=

        " order by 1 desc) "
        "left outer join "
        "( "
            "select AbonementID as AID,sum(case when AbonementID is null then 0 else 1 end) as VCNT from Visits_Bath "
            "group by AbonementID "
        ") "
        "on RID=AID";

        SQL_exefun3(NULL,sql.c_str(),&sCounter,&sRet,&sAID);

        if(atoi(sCounter.c_str()) - atoi(sRet.c_str()) <= 0)
        {
            Application->MessageBox("Внимание!\nНет абонементов с доступными посещениями.","Недопустимая операция",ID_OK);
            return;
        }

        SQL_exefun(NULL,("select a.ABTYPE from ABTYPES a inner join ABONEMENTS_BATH b on a.ROWID=b.ABTYPEID and b.ROWID=" + sAID).c_str(),&sRet);
        CurAb = atoi(sRet.c_str());
    }

    // Можно ли в этот день?
    int day = (FitCurrentDay + FitCurButton).DayOfWeek();
    if(day >= 6 || day == 1)
    {
        if(CurAb == BATH_VISIT_MWD || CurAb == BATH_VISIT_WD)
        {
            Application->MessageBox("Внимание!\nНет абонемента с посещениями выходного дня.","Недопустимая операция",ID_OK);
            return;
        }
    }

    sgEdit();
}
//---------------------------------------------------------------------------
void __fastcall TResBathForm::ReserveSave(void)
{
    if(!edInput->Visible || !edInput->Modified) return;

    TDateTime dt = Now();

    // Новая или нет?
    if(!sgCur->Rows[sgCur->Row]->Objects[sgCur->Col])
    {
        double bd = (int)FitCurrentDay + FitCurButton;
        // Новая запись
        SQL_iniInsert(NULL,"RESERVE");
        SQL_addInsert("CLIENTID", ClientID);
        SQL_addInsert("BEGDATE", (double)Date1>0? bd+(double)Date1 : bd+(double)Date2);
        SQL_addInsert("ENDDATE", (double)Date1>0? bd+(double)Date1 : bd+(double)Date2);
        SQL_addInsert("PERSONID", 0);
        SQL_addInsert("SERVICEID", BATH_VISIT);
        SQL_addInsert("STATUS", 1);
        SQL_addInsert("FITGROUPID", 0);
        SQL_addInsert("QUAN", 1);
        SQL_addInsert("PARENTID", 0);
        SQL_addInsert("CDATE", (double)dt);
        SQL_addInsert("CUID", UserID);
        if(pcResBath->ActivePageIndex == 0)
            SQL_addInsert("NUM", sgCur->Row + (30 * sgCur->Tag));
        else
            SQL_addInsert("NUM", -(sgCur->Row + (30 * sgCur->Tag)));
        SQL_exeInsert("PRICE", 0);

        sgCur->Rows[sgCur->Row]->Objects[sgCur->Col] = (TObject *)ClientID;
        unsigned status = (unsigned)sgCur->Rows[sgCur->Row]->Objects[0];
        if(sgCur->Col == 1)
            status |= 1;
        else
            status |= 0x10000;

        sgCur->Rows[sgCur->Row]->Objects[0] = (TObject *)status;

        sgCli = sgCur;
        CliRow = sgCur->Row;
        CliCol = sgCur->Col;
    }
    else
    {
        AnsiString sRet;
        double bd = (int)FitCurrentDay + FitCurButton;

        SQL_exefun(NULL,("select ROWID from RESERVE where CLIENTID=" + AnsiString((unsigned)sgCur->Rows[CliRow]->Objects[CliCol]) + " and SERVICEID=" + AnsiString(BATH_VISIT) + " and trunc(BEGDATE)=" + AnsiString((int)FitCurrentDay + FitCurButton)).c_str(),&sRet);

        SQL_iniUpdate(NULL,"RESERVE",_atoi64(sRet.c_str()));
        SQL_addUpdate("BEGDATE",(double)Date1>0? bd+(double)Date1 : bd+(double)Date2);
        SQL_exeUpdate("ENDDATE",(double)Date1>0? bd+(double)Date1 : bd+(double)Date2);
        //SQL_exeUpdate("FITGROUPID",UserID);
    }

    // CLIENTID,BEGDATE,ENDDATE,PERSONID,SERVICEID,STATUS,FITGROUPID,QUAN,PARENTID,CDATE,CUID,SYNC,NUM,PRICE

    //SQL_iniUpdate(DBName,"Personal",PersonID);
    //SQL_addUpdate("#Name",PersonName);
    //SQL_addUpdate("#Job",PersonJob);
    //SQL_addUpdate("EDate",(double)dt);
    //SQL_exeUpdate("EUID",UserID);

    edInput->Modified = false;

    sgCur->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TResBathForm::edInputExit(TObject *Sender)
{
    if(!edInput->Modified)
    {
        edInput->Visible = false;
        return;
    }

    TDateTime dt;

    try
    {
        dt = TDateTime(edInput->Text,TDateTime::Time);
    }
    catch(...)
    {
        edInput->SetFocus();
        return;
    }

    // Возможна ли запись?
    if(CurAb == BATH_VISIT_MWD || CurAb == BATH_VISIT_MALL)
    {
        double d = dt - (int)dt;

        if(d >= BATH_REDLINE)
        {
            Application->MessageBox("Внимание!\nНет абонемента с вечерними посещениями.","Недопустимая операция",ID_OK);
            edInput->SetFocus();
            return;
        }
    }

    sgCur->Cells[sgCur->Col][sgCur->Row] = edInput->Text;

    if(sgCur->Col == 1)
    {
        Date1 = 0;
        Date2 = dt;
    }
    else
    {
        Date1 = dt;
        Date2 = 0;
    }

    ReserveSave();

    edInput->Modified = false;
    edInput->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TResBathForm::sgM1SelectCell(TObject *Sender, int ACol,
      int ARow, bool &CanSelect)
{
    //edInputExit(NULL);
    sgCur = (TStringGrid *)Sender;
    sgCur->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TResBathForm::Button2Click(TObject *Sender)
{
    if(sgCli == sgCur && CliRow == sgCur->Row && CliCol == sgCur->Col)
    {
        unsigned status;

        if(sgCur->Col == 1)
        {
            status = (unsigned)sgCur->Rows[sgCur->Row]->Objects[0];
            if((status & 0xFFFF) == 1)
            {
                status = (status & 0xFFFF0000) | 2;
                sgCur->Rows[sgCur->Row]->Objects[0] = (TObject *)status;
                // Резерв в статус 2
                AnsiString sRet;

                SQL_exefun(NULL,("select ROWID from RESERVE where CLIENTID=" + AnsiString((unsigned)sgCur->Rows[CliRow]->Objects[CliCol]) + " and SERVICEID=" + AnsiString(BATH_VISIT) + " and trunc(BEGDATE)=" + AnsiString((int)FitCurrentDay + FitCurButton)).c_str(),&sRet);

                SQL_iniUpdate(NULL,"RESERVE",_atoi64(sRet.c_str()));
                SQL_exeUpdate("STATUS",2);
                //SQL_exeUpdate("FITGROUPID",UserID);

                // И списать с абонемента
                ClientsForm->sbBathVisitClick(NULL);

                sgResBathSheduleFullUpdate();
            }
        }
        else
        {
            status = (unsigned)sgCur->Rows[sgCur->Row]->Objects[0];
            if((status & 0xFFFF0000) == 0x10000)
            {
                status = (status & 0xFFFF) | 0x20000;
                sgCur->Rows[sgCur->Row]->Objects[0] = (TObject *)status;
                // Резерв в статус 2
                AnsiString sRet;

                SQL_exefun(NULL,("select ROWID from RESERVE where CLIENTID=" + AnsiString((unsigned)sgCur->Rows[CliRow]->Objects[CliCol]) + " and SERVICEID=" + AnsiString(BATH_VISIT) + " and trunc(BEGDATE)=" + AnsiString((int)FitCurrentDay + FitCurButton)).c_str(),&sRet);

                SQL_iniUpdate(NULL,"RESERVE",_atoi64(sRet.c_str()));
                SQL_exeUpdate("STATUS",2);
                //SQL_exeUpdate("FITGROUPID",UserID);

                // И списать с абонемента
                ClientsForm->sbBathVisitClick(NULL);

                sgResBathSheduleFullUpdate();
            }
        }
    }

    sgCur->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TResBathForm::Button1Click(TObject *Sender)
{
    if(sgCli == sgCur && CliRow == sgCur->Row && CliCol == sgCur->Col)
    {
        unsigned status;
        AnsiString sRet;

        if(sgCur->Col == 1)
        {
            status = (unsigned)sgCur->Rows[sgCur->Row]->Objects[0];
            if((status & 0xFFFF) == 2)
            {
                status = (status & 0xFFFF0000) | 3;
                sgCur->Rows[sgCur->Row]->Objects[0] = (TObject *)status;
                // Резерв в статус 3


                SQL_exefun(NULL,("select ROWID from RESERVE where CLIENTID=" + AnsiString((unsigned)sgCur->Rows[CliRow]->Objects[CliCol]) + " and SERVICEID=" + AnsiString(BATH_VISIT) + " and trunc(BEGDATE)=" + AnsiString((int)FitCurrentDay + FitCurButton)).c_str(),&sRet);

                SQL_iniUpdate(NULL,"RESERVE",_atoi64(sRet.c_str()));
                SQL_addUpdate("ENDDATE",(double)Now());
                SQL_exeUpdate("STATUS",3);
                //SQL_exeUpdate("FITGROUPID",UserID);
                sgCli = NULL;
                sgResBathSheduleFullUpdate();
            }
        }
        else
        {
            status = (unsigned)sgCur->Rows[sgCur->Row]->Objects[0];
            if((status & 0xFFFF0000) == 0x20000)
            {
                status = (status & 0xFFFF) | 0x30000;
                sgCur->Rows[sgCur->Row]->Objects[0] = (TObject *)status;
                // Резерв в статус 3
                AnsiString sRet;

                SQL_exefun(NULL,("select ROWID from RESERVE where CLIENTID=" + AnsiString((unsigned)sgCur->Rows[CliRow]->Objects[CliCol]) + " and SERVICEID=" + AnsiString(BATH_VISIT) + " and trunc(BEGDATE)=" + AnsiString((int)FitCurrentDay + FitCurButton)).c_str(),&sRet);

                SQL_iniUpdate(NULL,"RESERVE",_atoi64(sRet.c_str()));
                SQL_addUpdate("ENDDATE",(double)Now());
                SQL_exeUpdate("STATUS",3);
                //SQL_exeUpdate("FITGROUPID",UserID);
                sgCli = NULL;
                sgResBathSheduleFullUpdate();
            }
        }
    }

    sgCur->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TResBathForm::Button3Click(TObject *Sender)
{
    if(sgCli == sgCur && CliRow == sgCur->Row && CliCol == sgCur->Col)
    {
        unsigned status;
        AnsiString sRet;

        SQL_BeginTransaction();
        SQL_exefun(NULL,("select ROWID from RESERVE where CLIENTID=" + AnsiString((unsigned)sgCur->Rows[CliRow]->Objects[CliCol]) + " and SERVICEID=" + AnsiString(BATH_VISIT) + " and trunc(BEGDATE)=" + AnsiString((int)FitCurrentDay + FitCurButton)).c_str(),&sRet);

        SQL_exe(NULL,("insert into Reserve_Del select Reserve.*,null,null from Reserve where RowID="+sRet+" or ParentID="+sRet).c_str());
        SQL_exe(NULL,(AnsiString("update Reserve_Del set EDATE=")+(double)Now()+",EUID="+AnsiString(UserID)+" where EDATE is null and EUID is null").c_str());

        SQL_exe(NULL,("delete from Reserve where RowID="+sRet+" or ParentID="+sRet).c_str());

        SQL_CommitTransaction();

        if(sgCur->Col == 1)
            status = 0xFFFF0000 & (unsigned)sgCur->Rows[sgCur->Row]->Objects[0];
        else
            status = 0xFFFF & (unsigned)sgCur->Rows[sgCur->Row]->Objects[0];

        sgCur->Rows[sgCur->Row]->Objects[0] = (TObject *)status;
        sgCli = NULL;
        sgResBathSheduleFullUpdate();
    }

    sgCur->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TResBathForm::Button4Click(TObject *Sender)
{
    // Переход к Клиенту
    if(sgCur->Col == 0 || sgCur->Cells[sgCur->Col][sgCur->Row].Length() == 0) return;

    __int64 ID = (unsigned)sgCur->Rows[sgCur->Row]->Objects[sgCur->Col];



    if(!ID || !ClientsForm->IDs) return;

    unsigned i;
    for(i = 0; i < ClientsForm->Counter; i++)
        if(ID == ClientsForm->IDs[i]) break;

    //ClientsForm->BackFlag = true;

    if(i < ClientsForm->Counter)
    {
        ClientsForm->sgClients->Row = i + 1;
        ClientsForm->sgClients->TopRow = i + 1;
    }
    else
    {
        // Возможно, это выборка
        //edSearchStr->Text = "";
        //edPSearchStr->Text = "";


        ClientsForm->sgClientsFullUpdate();

        for(i = 0; i < ClientsForm->Counter; i++)
            if(ID == ClientsForm->IDs[i]) break;

        if(i < ClientsForm->Counter)
        {
            ClientsForm->sgClients->Row = i + 1;
            ClientsForm->sgClients->TopRow = i + 1;
        }
    }

    //ClientsForm->BackFlag = false;

    sgResBathSheduleFullUpdate();

    sgCur->SetFocus();
}
//---------------------------------------------------------------------------

