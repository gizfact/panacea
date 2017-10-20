//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "visitsbath.h"
#include "accounts.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TVisitsBathForm *VisitsBathForm;

extern const char *DBName;
extern __int64 UserID;
extern __int64 ClientID;
extern const char *MoneyFormat;
extern int FormResult;

extern __int64 AbonementBathID;


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
    if((unsigned)VisitsBathForm->IDs.Length <= VisitsBathForm->Counter)
        VisitsBathForm->IDs.Length = VisitsBathForm->Counter + 10;
    VisitsBathForm->IDs[VisitsBathForm->Counter++] = _atoi64(argv[6]);

    // Date - argv[0]
    TDateTime dt;
    if(argv[0])
        dt = atoi(argv[0]);
    else
        dt = 0;

    if((int)dt)
        VisitsBathForm->sgVisits->Cells[0][VisitsBathForm->Counter] = dt.DateString();
    else
        VisitsBathForm->sgVisits->Cells[0][VisitsBathForm->Counter] = "";

    // BegTime - argv[1]
    if(argv[1])
        dt = atof(argv[1]);
    else
        dt = 0;

    VisitsBathForm->sgVisits->Cells[1][VisitsBathForm->Counter] = dt.FormatString("hh:nn");

    // EndTime - argv[2]
    if(argv[2])
        dt = atof(argv[2]);
    else
        dt = 0;

    VisitsBathForm->sgVisits->Cells[2][VisitsBathForm->Counter] = dt.FormatString("hh:nn");

    // ServiceID - argv[3]
    __int64 ID;
    if(argv[3])
        ID = _atoi64(argv[3]);
    else
        ID = 0;

    if(ID)
    {

            SQL_exefun(DBName,
("select '['||b.Name||']'||a.Name from Services a left outer join Services b on a.ParentID=b.RowID where a.RowID="+AnsiString(ID)).c_str(),&(VisitsBathForm->retString));

        VisitsBathForm->sgVisits->Cells[3][VisitsBathForm->Counter] = (VisitsBathForm->retString);
    }
    else
        VisitsBathForm->sgVisits->Cells[3][VisitsBathForm->Counter] = "";

    // PersonID - argv[4]
    if(argv[4])
        ID = _atoi64(argv[4]);
    else
        ID = 0;

    if(ID)
    {
        SQL_exefun(DBName,("select Name from Personal where RowID="+(AnsiString)ID).c_str(),&(VisitsBathForm->retString));
        VisitsBathForm->sgVisits->Cells[4][VisitsBathForm->Counter] = (VisitsBathForm->retString);
    }
    else
        VisitsBathForm->sgVisits->Cells[4][VisitsBathForm->Counter] = "";

    // Price - argv[5]
    double price;
    if(argv[5])
        price = strtof(argv[5]);
    else
        price = 0.0;

    VisitsBathForm->sgVisits->Cells[5][VisitsBathForm->Counter] = FormatFloat(MoneyFormat,price).TrimLeft();

    return 0;
}
//---------------------------------------------------------------------------

//***************************************************************************
//*************************** END CALLBACKS *********************************
//***************************************************************************

//---------------------------------------------------------------------------
void __fastcall TVisitsBathForm::sgVisitsWindowProc(Messages::TMessage& Msg)
{
    sgWindowProc(Msg,sgVisits,VisitsWidths,sgOVisitsWindowProc);
}
//---------------------------------------------------------------------------
__fastcall TVisitsBathForm::TVisitsBathForm(TComponent* Owner)
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
void __fastcall TVisitsBathForm::FormShow(TObject *Sender)
{
    //if(AbonementSPAID)
    //    cbChoice->Visible = false;

    sgSetHeaders(sgVisits,"����","������","�����","���������","����������","���.");
    sgSetWidths(sgVisits,&VisitsWidths,100,70,70,300,150);

    UsersCounter = UserInit(DBName,&pUserIDs,&pUsers);

    sgOVisitsWindowProc = sgVisits->WindowProc;
    sgVisits->WindowProc = sgVisitsWindowProc;

    sgVisitsFullUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TVisitsBathForm::sgVisitsFullUpdate(void)
{
    SQL_BeginTransaction();

    SQL_exefun(DBName,("select count(*) from Visits_Bath where AbonementID="+(AnsiString)AbonementBathID).c_str(),&retString);

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

        SQL_exe(DBName,("select Visits_BathDate,BegTime,EndTime,ServiceID,PersonID,Price,RowID from Visits_Bath where AbonementID="+AnsiString(AbonementBathID)+" order by Visits_BathDate desc,RowID desc").c_str(),visits_select);

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
void __fastcall TVisitsBathForm::sgVisitsRowInfo(DynamicArray<__int64> pID, unsigned cnt)
{
    if((unsigned)pID.Length >= Counter && Counter > 0)
    {
        AnsiString status = "ID: " + (AnsiString)pID[cnt];
    }
    else
    {
        sbVisits->SimpleText = "ID: ";
    }
}
//---------------------------------------------------------------------------
void __fastcall TVisitsBathForm::sgVisitsDrawCell(TObject *Sender,
      int ACol, int ARow, TRect &Rect, TGridDrawState State)
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
void __fastcall TVisitsBathForm::tbExitClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TVisitsBathForm::FormDestroy(TObject *Sender)
{
    delete [] pUserIDs;
    delete [] pUsers;

    delete [] VisitsWidths;
}
//---------------------------------------------------------------------------
void __fastcall TVisitsBathForm::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key == VK_ESCAPE)
        Close();
}
//---------------------------------------------------------------------------

