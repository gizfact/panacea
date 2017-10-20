//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "pricelists.h"
#include "lib.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPriceListsForm *PriceListsForm;

extern const char *DBName;
extern __int64 UserID;

static AnsiString *pUsers = NULL;
static __int64 *pUserIDs = NULL;
static unsigned UsersCounter = 0;

static __int64 *IDs = NULL;
static unsigned Counter = 0;

static AnsiString retString;

static TDateTime CDate, EDate;
static __int64 CUID, EUID, PriceListID;
static bool NewFlag = false;

static unsigned UpdatedRow = 0;

static TWndMethod sgOWindowProc;
//---------------------------------------------------------------------------

//***************************************************************************
//******************************* CALLBACKS *********************************
//***************************************************************************

//---------------------------------------------------------------------------
static int pricelists_select(void *NotUsed, int argc, char **argv, char **azColName)
{
    if(IDs)
        IDs[Counter] = _atoi64(argv[0]);
    else
        return 0;

    PriceListsForm->sgPriceLists->Cells[0][++Counter] = Utf8ToAnsi(argv[1]);

    return 0;
}
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
static int pricelists_setinfo(void *NotUsed,int argc,char **argv,char **azColName)
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
void match_ru(sqlite3_context *context, int argc, sqlite3_value **argv)
{
    if(argc < 2)
    {
        sqlite3_result_error(context,"must be 2 params",-1);
        return;
    }

    AnsiString s1 = (Utf8ToAnsi((char *)sqlite3_value_text(argv[0]))).LowerCase();
    AnsiString s2 = (char *)sqlite3_value_text(argv[1]);

    sqlite3_result_int(context,s1 == s2.LowerCase());
}
//---------------------------------------------------------------------------

//***************************************************************************
//*************************** END CALLBACKS *********************************
//***************************************************************************

//---------------------------------------------------------------------------
void __fastcall TPriceListsForm::sgWindowProc(Messages::TMessage& Msg)
{
    if(!edInput->Focused()) sgOWindowProc(Msg);
    else if(Msg.Msg != WM_VSCROLL && Msg.Msg != WM_HSCROLL && Msg.Msg != WM_MOUSEWHEEL)
        sgOWindowProc(Msg);
}
//---------------------------------------------------------------------------
int _grid_scrolling(TStringGrid* gr,int i)
{
//если i=0 - Скроллирование таблицы запрещается
//если i=1 - Скроллирование таблицы разрешается
    struct GridScrollPos
    {
        TStringGrid* grid;
        int LeftCol1;
        int TopRow1;
        int pr_Interdiction;
    };

    static GridScrollPos* BaseGridScrollPos;
    static unsigned int SizeBaseGridScrollPos;
    unsigned int i1 = 0;

    while((i1 < SizeBaseGridScrollPos) && (BaseGridScrollPos[i1].grid != gr)) i1++;
    if(i1 == SizeBaseGridScrollPos)
    {
        (void*)BaseGridScrollPos = realloc(BaseGridScrollPos,(SizeBaseGridScrollPos+1)*sizeof(GridScrollPos));
        SizeBaseGridScrollPos++;
        BaseGridScrollPos[i1].grid = gr;
        BaseGridScrollPos[i1].pr_Interdiction = 0;
    }
    switch (i)
    {
case 0:
        BaseGridScrollPos[i1].LeftCol1 = gr->LeftCol;
        BaseGridScrollPos[i1].TopRow1 = gr->TopRow;
        BaseGridScrollPos[i1].pr_Interdiction = 1;
        break;
case 1:
        BaseGridScrollPos[i1].pr_Interdiction = 0;
        break;
case 2:
        return BaseGridScrollPos[i1].LeftCol1;

case 3:
        return BaseGridScrollPos[i1].TopRow1;

case 4:
        return BaseGridScrollPos[i1].pr_Interdiction;

    }
    return 0;
}
//---------------------------------------------------------------------------
__fastcall TPriceListsForm::TPriceListsForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TPriceListsForm::sgPriceListsFullUpdate(void)
{
    SQL_exefun(DBName,"select count(*) from PriceLists",&retString);

    __int64 SelRowID;
    bool SelFlag = false;
    if(IDs)
    {
        SelFlag = true;
        SelRowID = IDs[sgPriceLists->Row-1];
        PDEL(IDs);
    }

    int icnt = atoi(retString.c_str());
    sgPriceLists->RowCount = (!icnt)? 2 : icnt + 1;
    sgPriceLists->Rows[sgPriceLists->RowCount-1]->Clear();
    sgPriceLists->Cells[0][1] = "";

    Counter = 0;

    if(icnt)
    {
        IDs = new(nothrow) __int64[icnt];
        if(!IDs) Close();

        SQL_exe(DBName,"select RowID,Name from PriceLists order by Name,RowID",pricelists_select);

        if(SelFlag)
        {
            unsigned i;
            for(i = 0; i < Counter; i++)
                if(IDs[i] == SelRowID) break;
            if(i == Counter)
                sgPriceLists->Row = 1;
            else
                sgPriceLists->Row = i + 1;
        }
        else
            sgPriceLists->Row = 1;
    }
    else
        sgPriceLists->Row = 1;

    sgPriceListsRowInfo(IDs,sgPriceLists->Row-1);
}
//---------------------------------------------------------------------------
void __fastcall TPriceListsForm::sgPriceListsRowInfo(__int64 *pID, unsigned cnt)
{
    if(pID)
    {
        AnsiString status = "ID: " + (AnsiString)pID[cnt];

        CDate = 0;
        CUID = -1;
        EDate = 0;
        EUID = -1;

        SQL_exe(DBName,("select CDate,CUID,EDate,EUID from PriceLists where RowID="+(AnsiString)pID[cnt]).c_str(),pricelists_setinfo);

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

        sbPriceLists->SimpleText = status;
    }
    else
    {
        sbPriceLists->SimpleText = "ID: ";
    }
}
//---------------------------------------------------------------------------
void __fastcall TPriceListsForm::FormShow(TObject *Sender)
{
    // - 27;
    sgPriceLists->Cells[0][0] = "Наименование";

    sgOWindowProc = sgPriceLists->WindowProc;
    sgPriceLists->WindowProc = sgWindowProc;

    SQL_exefun(DBName,"select count(*) from Stars",&retString);

    pUsers = new(nothrow) AnsiString[atoi(retString.c_str()) + 1];
    if(!pUsers) Close();
    pUserIDs = new(nothrow) __int64[atoi(retString.c_str()) + 1];
    if(!pUserIDs) Close();
    UsersCounter = 1;
    pUsers[0] = "admin";
    pUserIDs[0] = 0;
    SQL_exe(DBName,"select RowID,User from Stars",users_select);

    sgPriceListsFullUpdate();
    sgPriceLists->ColWidths[0] = sgPriceLists->ClientWidth;
    sgPriceLists->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TPriceListsForm::sgPriceListsSelectCell(TObject *Sender,
      int ACol, int ARow, bool &CanSelect)
{
    sgPriceListsRowInfo(IDs,ARow-1);
}
//---------------------------------------------------------------------------
void __fastcall TPriceListsForm::sgPriceListsDrawCell(TObject *Sender,
      int ACol, int ARow, TRect &Rect, TGridDrawState State)
{
    if(State.Contains(gdFixed))
    {
        sgPriceLists->Canvas->Font->Style = TFontStyles() << fsBold;
        // << fsItalic;

        sgPriceLists->Canvas->Font->Color = HEADER_COLOR;

        int lft = Rect.Width() - sgPriceLists->Canvas->TextWidth(sgPriceLists->Cells[ACol][0]);
        if(lft < 2) lft = 2;
        else lft >>= 1;
        sgPriceLists->Canvas->TextRect(Rect,Rect.left+lft,Rect.top+1,sgPriceLists->Cells[ACol][0]);
    }
}
//---------------------------------------------------------------------------
void __fastcall TPriceListsForm::sgPriceListsDblClick(TObject *Sender)
{
    if(sgPriceLists->Row > 0 && Counter > 0)
    {
        if(!IDs && !NewFlag) return;

        TRect rect = sgPriceLists->CellRect(sgPriceLists->Col,sgPriceLists->Row);
        edInput->Left = rect.Left + 2;
        edInput->Top = rect.Top + sgPriceLists->Top + 2;
        edInput->Width = rect.Width();
        edInput->Height = rect.Height() + 2;
        edInput->Text = sgPriceLists->Cells[sgPriceLists->Col][sgPriceLists->Row];

        if(!NewFlag)
            PriceListID = IDs[sgPriceLists->Row-1];
        else
            PriceListID = 0;

        edInput->Visible = true;
        edInput->Enabled = true;
        edInput->SetFocus();
    }
}
//---------------------------------------------------------------------------
void __fastcall TPriceListsForm::edInputExit(TObject *Sender)
{
    edInput->Visible = false;
    edInput->Enabled = false;
    //grid_scrolling(sgPriceLists,1);

    if(NewFlag && Counter)
    {
        // Откат
        for(unsigned i = 2; i < Counter + 2; i++)
            sgPriceLists->Rows[i-1] = sgPriceLists->Rows[i];
        sgPriceLists->RowCount--;

        sgPriceLists->Row = UpdatedRow;
    }
}
//---------------------------------------------------------------------------
void __fastcall TPriceListsForm::tbSaveClick(TObject *Sender)
{
    if(!edInput->Visible) return;

    if(!edInput->Modified)
    {
        sgPriceLists->SetFocus();
        return;
    }

    SQL_exefunalt(DBName,("select count(*) from PriceLists where sqlfun(Name,'"+edInput->Text + "')<>0").c_str(),match_ru,&retString);

    if(atoi(retString.c_str()) > 0)
    {
        Application->MessageBox(("Прайс-лист со схожим '" + edInput->Text + "' именем уже существует.").c_str(),"");
        return;
    }

    TDateTime dt;
    dt = dt.CurrentDateTime();

    if(NewFlag)
    {
        NewFlag = false;
        SQL_iniInsert(DBName,"PriceLists",&PriceListID);
        SQL_addInsert("#Name",edInput->Text);
        SQL_addInsert("CDate",(double)dt);
        SQL_addInsert("CUID",UserID);
        SQL_addInsert("EDate",(double)dt);
        SQL_exeInsert("EUID",UserID);
        PDEL(IDs);
        IDs = new __int64;
        IDs[0] = PriceListID;
    }
    else
    {
        SQL_iniUpdate(DBName,"PriceLists",PriceListID);
        SQL_addUpdate("#Name",edInput->Text);
        SQL_addUpdate("EDate",(double)dt);
        SQL_exeUpdate("EUID",UserID);
    }

    sgPriceListsFullUpdate();

    sgPriceLists->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TPriceListsForm::tbNewClick(TObject *Sender)
{
    UpdatedRow = sgPriceLists->Row;

    if(Counter > 1)
    {
        sgPriceLists->RowCount++;

        // Сдвинуть все вниз
        for(unsigned i = Counter + 1; i > 1; i--)
            sgPriceLists->Rows[i] = sgPriceLists->Rows[i-1];

        sgPriceLists->Rows[1]->Clear();
    }

    sgPriceLists->Row = 1;

    NewFlag = true;
    sgPriceListsDblClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TPriceListsForm::ToolButton3Click(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TPriceListsForm::FormDestroy(TObject *Sender)
{
    PDEL(IDs);
    PDEL(pUsers);
    PDEL(pUserIDs);
}
//---------------------------------------------------------------------------
void __fastcall TPriceListsForm::edInputKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key == VK_ESCAPE)
    {
        sgPriceLists->SetFocus();
    }
    else if(Key == VK_RETURN)
    {
        tbSaveClick(Sender);
    }
    else if(Key == VK_UP && sgPriceLists->Row > 1)
    {
        tbSaveClick(Sender);
        sgPriceLists->Row--;
        PostMessage(sgPriceLists->Handle,WM_LBUTTONDBLCLK,MK_LBUTTON,0);
        //sgPriceListsDblClick(Sender);
    }
    else if(Key == VK_DOWN && (unsigned)sgPriceLists->Row < Counter)
    {
        tbSaveClick(Sender);
        sgPriceLists->Row++;
        PostMessage(sgPriceLists->Handle,WM_LBUTTONDBLCLK,MK_LBUTTON,0);
        //sgPriceListsDblClick(Sender);
    }
}
//---------------------------------------------------------------------------
void __fastcall TPriceListsForm::sgPriceListsKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
    if(Key == VK_RETURN)
        sgPriceListsDblClick(Sender);
}
//---------------------------------------------------------------------------

