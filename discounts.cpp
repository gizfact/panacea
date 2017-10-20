//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "discounts.h"
#include "lib.h"
#include "i_discounts.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDiscountsForm *DiscountsForm;

extern const char *DBName;

//extern AnsiString ImgPath;
static TDateTime CDate, EDate;
static __int64 CUID, EUID;

__int64 DiscountID = 0;

static __int64 *IDs = NULL;
static unsigned Counter = 0;
static unsigned UpdatedRow = 0;
extern int FormResult;

static AnsiString *pUsers = NULL;
static __int64 *pUserIDs = NULL;
static unsigned UsersCounter = 0;

static AnsiString retString;
static TWndMethod sgOWindowProc;
//---------------------------------------------------------------------------

//***************************************************************************
//******************************* CALLBACKS *********************************
//***************************************************************************

//---------------------------------------------------------------------------
static int users_select(void *NotUsed, int argc, char **argv, char **azColName)
{
    pUserIDs[UsersCounter] = (argv[0])? _atoi64(argv[0]) : -1;
    if(argv[1])
        pUsers[UsersCounter++] = Utf8ToAnsi(argv[1]);
    else
        pUsers[UsersCounter++] = "unknown";

    return 0;
}
//---------------------------------------------------------------------------
static int discounts_select(void *NotUsed, int argc, char **argv, char **azColName)
{
    if(IDs)
        IDs[Counter] = _atoi64(argv[0]);
    else
        return 0;

    // Alive
    if(argv[1])
        DiscountsForm->sgDiscounts->Cells[0][++Counter] = (atoi(argv[1]))? "" : " ";
    else
        DiscountsForm->sgDiscounts->Cells[0][++Counter] = "";
    // Name
    DiscountsForm->sgDiscounts->Cells[1][Counter] = Utf8ToAnsi(argv[2]);

    if(argv[3])
        DiscountsForm->sgDiscounts->Cells[2][Counter] = FormatFloat("##0.00",strtof(argv[3])).TrimLeft();
    else
        DiscountsForm->sgDiscounts->Cells[2][Counter] = "";
    
    // BegDate
    if(argv[4])
    {
        TDateTime dt = TDateTime(atof(argv[4]));
        if((double)dt == 0)
            DiscountsForm->sgDiscounts->Cells[3][Counter] = "";
        else
            DiscountsForm->sgDiscounts->Cells[3][Counter] = dt;
    }
    else
        DiscountsForm->sgDiscounts->Cells[3][Counter] = "";

    if(argv[5])
    {
        TDateTime dt = TDateTime(atof(argv[5]));
        if((double)dt == 0)
            DiscountsForm->sgDiscounts->Cells[4][Counter] = "";
        else
            DiscountsForm->sgDiscounts->Cells[4][Counter] = dt;
    }
    else
        DiscountsForm->sgDiscounts->Cells[4][Counter] = "";

    return 0;
}
//---------------------------------------------------------------------------
static int discounts_setinfo(void *NotUsed,int argc,char **argv,char **azColName)
{
    if(argv[0])
        CDate = atof(argv[0]);
    else
        CDate = 0;

    CUID = (argv[1])? _atoi64(argv[1]) : -1;

    if(argv[2])
        EDate = atof(argv[2]);
    else
        EDate = 0;

    EUID = (argv[3])? _atoi64(argv[3]) : -1;

    return 0;
}
//---------------------------------------------------------------------------
static int discounts_rowupdate(void *NotUsed,int argc,char **argv,char **azColName)
{
    // Alive
    if(argv[0])
        DiscountsForm->sgDiscounts->Cells[0][UpdatedRow] = (atoi(argv[0]))? "" : " ";
    else
        DiscountsForm->sgDiscounts->Cells[0][UpdatedRow] = "";

    // Name
    DiscountsForm->sgDiscounts->Cells[1][UpdatedRow] = Utf8ToAnsi(argv[1]);
    // Percent
    if(argv[2])
        DiscountsForm->sgDiscounts->Cells[2][UpdatedRow] = FormatFloat("##0.00",strtof(argv[2])).TrimLeft();
    else
        DiscountsForm->sgDiscounts->Cells[2][UpdatedRow] = "";

    // BegDate
    if(argv[3])
    {
        TDateTime dt = TDateTime(atof(argv[3]));
        if((double)dt == 0)
            DiscountsForm->sgDiscounts->Cells[3][UpdatedRow] = "";
        else
            DiscountsForm->sgDiscounts->Cells[3][UpdatedRow] = dt;
    }
    else
        DiscountsForm->sgDiscounts->Cells[3][UpdatedRow] = "";

    if(argv[4])
    {
        TDateTime dt = TDateTime(atof(argv[4]));
        if((double)dt == 0)
            DiscountsForm->sgDiscounts->Cells[4][UpdatedRow] = "";
        else
            DiscountsForm->sgDiscounts->Cells[4][UpdatedRow] = dt;
    }
    else
        DiscountsForm->sgDiscounts->Cells[4][UpdatedRow] = "";

    return 0;
}
//---------------------------------------------------------------------------

//***************************************************************************
//*************************** END CALLBACKS *********************************
//***************************************************************************

//---------------------------------------------------------------------------
void __fastcall TDiscountsForm::sgWindowProc(Messages::TMessage& Msg)
{
    //if(!edInput->Focused()) sgOWindowProc(Msg);
    //else if(Msg.Msg != WM_VSCROLL && Msg.Msg != WM_HSCROLL && Msg.Msg != WM_MOUSEWHEEL)
    if(Msg.Msg == WM_SIZE)
    {
        int width = sgDiscounts->Width;
        for(int i = 0; i < sgDiscounts->ColCount - 1; i++)
            width -= sgDiscounts->ColWidths[i];
        if(GetWindowLong(sgDiscounts->Handle,GWL_STYLE) & WS_VSCROLL)
            sgDiscounts->ColWidths[sgDiscounts->ColCount-1] = width - 20;
        else
            sgDiscounts->ColWidths[sgDiscounts->ColCount-1] = width - 8;
    }
    else
        sgOWindowProc(Msg);
}
//---------------------------------------------------------------------------
__fastcall TDiscountsForm::TDiscountsForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDiscountsForm::FormShow(TObject *Sender)
{
    sgDiscounts->ColWidths[0] = 16;
    sgDiscounts->ColWidths[1] = 220;
    sgDiscounts->ColWidths[2] = 60;
    sgDiscounts->ColWidths[3] = 90;
    sgDiscounts->ColWidths[4] = sgDiscounts->Width-sgDiscounts->ColWidths[0]-sgDiscounts->ColWidths[1]-sgDiscounts->ColWidths[2]-sgDiscounts->ColWidths[3] - 8;

    sgDiscounts->Cells[1][0] = "Наименование";
    sgDiscounts->Cells[2][0] = "Скидка (%)";
    sgDiscounts->Cells[3][0] = "Начало";
    sgDiscounts->Cells[4][0] = "Конец";

    sgOWindowProc = sgDiscounts->WindowProc;
    sgDiscounts->WindowProc = sgWindowProc;

    SQL_exefun(DBName,"select count(*) from Stars",&retString);

    pUsers = new(nothrow) AnsiString[atoi(retString.c_str()) + 1];
    if(!pUsers) Close();
    pUserIDs = new(nothrow) __int64[atoi(retString.c_str()) + 1];
    if(!pUserIDs) Close();
    UsersCounter = 1;
    pUsers[0] = "admin";
    pUserIDs[0] = 0;
    SQL_exe(DBName,"select RowID,User from Stars",users_select);

    sgDiscountsFullUpdate();

    sgDiscounts->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TDiscountsForm::FormDestroy(TObject *Sender)
{
    PDEL(IDs);
    PDEL(pUsers);
    PDEL(pUserIDs);
}
//---------------------------------------------------------------------------
void __fastcall TDiscountsForm::sgDiscountsRowInfo(__int64 *pID, unsigned cnt)
{
    if(pID)
    {
        AnsiString status = "ID: " + (AnsiString)pID[cnt];

        CDate = 0;
        CUID = -1;
        EDate = 0;
        EUID = -1;

        SQL_exe(DBName,("select CDate,CUID,EDate,EUID from Discounts where RowID="+(AnsiString)pID[cnt]).c_str(),discounts_setinfo);

        unsigned i;
        for(i = 0; i < UsersCounter; i++)
            if(pUserIDs[i] == CUID) break;

        if(i == UsersCounter)
            status += "   C:[unknown]";
        else
            status += ("   C:[" + pUsers[i] + " - ");

        if((double)CDate == 0)
            status += "?]";
        else
            status += (CDate.DateTimeString() + "]");

        for(i = 0; i < UsersCounter; i++)
            if(pUserIDs[i] == EUID) break;

        if(i == UsersCounter)
            status += "   E:[unknown]";
        else
            status += ("   E:[" + pUsers[i] + " - ");

        if((double)EDate == 0)
            status += "?]";
        else
            status += (EDate.DateTimeString() + "]");

        sbDiscounts->SimpleText = status;
    }
    else
    {
        sbDiscounts->SimpleText = "ID: ";
    }
}
//---------------------------------------------------------------------------
void __fastcall TDiscountsForm::sgDiscountsRowUpdate(__int64 *pID, unsigned cnt)
{
    if(pID)
        SQL_exe(DBName,("select Alive,Name,Percent,BegDate,EndDate from Discounts where RowID=" + (AnsiString)pID[cnt]).c_str(),discounts_rowupdate);
    else
    {
        sgDiscounts->Cells[0][UpdatedRow] = "";
        sgDiscounts->Cells[1][UpdatedRow] = "";
        sgDiscounts->Cells[2][UpdatedRow] = "";
        sgDiscounts->Cells[3][UpdatedRow] = "";
        sgDiscounts->Cells[4][UpdatedRow] = "";
    }

    sgDiscountsRowInfo(pID,cnt);
}
//---------------------------------------------------------------------------
void __fastcall TDiscountsForm::sgDiscountsFullUpdate(void)
{
    SQL_exefun(DBName,"select count(*) from Discounts",&retString);

    __int64 SelRowID;
    bool SelFlag = false;
    if(IDs)
    {
        SelFlag = true;
        SelRowID = IDs[sgDiscounts->Row-1];
        PDEL(IDs);
    }

    int icnt = atoi(retString.c_str());
    sgDiscounts->RowCount = (!icnt)? 2 : icnt + 1;
    sgDiscounts->Rows[sgDiscounts->RowCount-1]->Clear();
    sgDiscounts->Cells[0][1] = "";

    Counter = 0;

    if(icnt)
    {
        IDs = new(nothrow) __int64[icnt];
        if(!IDs) Close();

        SQL_exe(DBName,"select RowID,Alive,Name,Percent,BegDate,EndDate from Discounts order by Name,RowID",discounts_select);

        if(SelFlag)
        {
            unsigned i;
            for(i = 0; i < Counter; i++)
                if(IDs[i] == SelRowID) break;
            if(i == Counter)
                sgDiscounts->Row = 1;
            else
                sgDiscounts->Row = i + 1;
        }
        else
            sgDiscounts->Row = 1;
    }
    else
        sgDiscounts->Row = 1;

    sgDiscountsRowInfo(IDs,sgDiscounts->Row-1);
}
//---------------------------------------------------------------------------
void __fastcall TDiscountsForm::sgDiscountsDrawCell(TObject *Sender,
      int ACol, int ARow, TRect &Rect, TGridDrawState State)
{
    if(State.Contains(gdFixed))
    {
        sgDiscounts->Canvas->Font->Style = TFontStyles() << fsBold;
        // << fsItalic;
        sgDiscounts->Canvas->Font->Color = HEADER_COLOR;

        int lft = Rect.Width() - sgDiscounts->Canvas->TextWidth(sgDiscounts->Cells[ACol][0]);
        if(lft < 2) lft = 2;
        else lft >>= 1;
        sgDiscounts->Canvas->TextRect(Rect,Rect.left+lft,Rect.top+1,sgDiscounts->Cells[ACol][0]);
    }
    else if(ACol == 0 )
    {
        if(IDs)
        {
            if((sgDiscounts->Cells[ACol][ARow]).Length() == 0)
                ilDiscounts->Draw(sgDiscounts->Canvas,Rect.left,Rect.top,0);
            else
                ilDiscounts->Draw(sgDiscounts->Canvas,Rect.left,Rect.top,1);
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TDiscountsForm::tbExitClick(TObject *Sender)
{
    Close();    
}
//---------------------------------------------------------------------------
void __fastcall TDiscountsForm::tbHomeClick(TObject *Sender)
{
    sgDiscounts->Row = 1;
}
//---------------------------------------------------------------------------
void __fastcall TDiscountsForm::tbAddClick(TObject *Sender)
{
    DiscountID = 0;
    FormResult = 0;
    iDiscountsForm = new TiDiscountsForm(this);
    iDiscountsForm->ShowModal();
    delete iDiscountsForm;
    if(FormResult == 1)
    {
        __int64 *newIDs = new(nothrow) __int64[++Counter];
        if(!newIDs) Close();

        newIDs[0] = DiscountID;
        for(unsigned i = 1; i < Counter; i++)
            newIDs[i] = IDs[i-1];
        PDEL(IDs);
        IDs = newIDs;

        if(Counter > 1)
        {
            sgDiscounts->RowCount++;

        // Сдвинуть все вниз
            for(unsigned i = Counter; i > 1; i--)
                sgDiscounts->Rows[i] = sgDiscounts->Rows[i-1];
        }
        //sgClientsFullUpdate();
        //unsigned i;
        //for(i = 0; i < Counter; i++)
          //  if(IDs[i] == ClientID) break;
        sgDiscounts->Row = 1;
        UpdatedRow = 1;
        sgDiscountsRowUpdate(IDs,0);
        //sgClients->TopRow = 1;

    }
}
//---------------------------------------------------------------------------
void __fastcall TDiscountsForm::tbEditClick(TObject *Sender)
{
    if(sgDiscounts->Row > 0 && Counter > 0)
    {
        if(!IDs) return;

        DiscountID = IDs[sgDiscounts->Row-1];
        iDiscountsForm = new TiDiscountsForm(this);
        iDiscountsForm->ShowModal();
        if(FormResult == -1)
        {
            // Обновить запись
            UpdatedRow = sgDiscounts->Row;
            SQL_exe(DBName,("select Alive,Name,Percent,BegDate,EndDate from Discounts where RowID=" + (AnsiString)DiscountID).c_str(),discounts_rowupdate);
            sgDiscountsRowInfo(&DiscountID,0);
        }
        delete iDiscountsForm;
    }
}
//---------------------------------------------------------------------------
void __fastcall TDiscountsForm::sgDiscountsKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
    if(Key == VK_RETURN)
        tbEditClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TDiscountsForm::sgDiscountsSelectCell(TObject *Sender,
      int ACol, int ARow, bool &CanSelect)
{
   sgDiscountsRowInfo(IDs,ARow-1);
}
//---------------------------------------------------------------------------

