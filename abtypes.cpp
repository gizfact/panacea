//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "abtypes.h"
#include "lib.h"
#include "i_abtypes.h"
#include "abparam.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAbTypesForm *AbTypesForm;

extern const char *DBName;

static TDateTime CDate, EDate;
static __int64 CUID, EUID;

static __int64 *IDs = NULL;
static unsigned Counter = 0;
static unsigned UpdatedRow = 0;
extern int FormResult;

extern const char *MoneyFormat;

__int64 AbTypeID = 0;

static AnsiString *pUsers = NULL;
static __int64 *pUserIDs = NULL;
static unsigned UsersCounter = 0;

static AnsiString retString;
static TWndMethod sgOWindowProc;

int AbTypesFormMode = 0;
__int64 AbTypesFormRetID = 0;
AnsiString AbTypesFormRet1 = "";
AnsiString AbTypesFormRet2 = "";
AnsiString AbTypesFormRet3 = "";
AnsiString AbTypesFormRet4 = "";
//---------------------------------------------------------------------------

//***************************************************************************
//******************************* CALLBACKS *********************************
//***************************************************************************

//---------------------------------------------------------------------------
static int users_select(void *NotUsed, int argc, char **argv, char **azColName)
{
    pUserIDs[UsersCounter] = (argv[0])? _atoi64(argv[0]) : -1;
    if(argv[1])
        pUsers[UsersCounter++] = (argv[1]);
    else
        pUsers[UsersCounter++] = "unknown";

    return 0;
}
//---------------------------------------------------------------------------
static int abtypes_setinfo(void *NotUsed,int argc,char **argv,char **azColName)
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
static int abtypes_rowupdate(void *NotUsed,int argc,char **argv,char **azColName)
{
    // Alive
    if(argv[0])
        AbTypesForm->sgAbTypes->Cells[0][UpdatedRow] = (atoi(argv[0]))? "" : " ";
    else
        AbTypesForm->sgAbTypes->Cells[0][UpdatedRow] = "";

    // Name
    AbTypesForm->sgAbTypes->Cells[1][UpdatedRow] = (argv[1]);

    // Price
    if(argv[2])
        AbTypesForm->sgAbTypes->Cells[2][UpdatedRow] = FormatFloat(MoneyFormat,strtof(argv[2])).TrimLeft();
    else
        AbTypesForm->sgAbTypes->Cells[2][UpdatedRow] = "0.00";

    // Days
    if(argv[3])
        AbTypesForm->sgAbTypes->Cells[3][UpdatedRow] = argv[3];
    else
        AbTypesForm->sgAbTypes->Cells[3][UpdatedRow] = "0";

    // Count
    if(argv[4])
        AbTypesForm->sgAbTypes->Cells[4][UpdatedRow] = argv[4];
    else
        AbTypesForm->sgAbTypes->Cells[4][UpdatedRow] = "0";

    return 0;
}
//---------------------------------------------------------------------------
static int abtypes_select(void *NotUsed, int argc, char **argv, char **azColName)
{
    if(IDs)
        IDs[Counter] = _atoi64(argv[0]);
    else
        return 0;

    // Alive
    if(argv[1])
        AbTypesForm->sgAbTypes->Cells[0][++Counter] = (atoi(argv[1]))? "" : " ";
    else
        AbTypesForm->sgAbTypes->Cells[0][++Counter] = "";
    // Name
    AbTypesForm->sgAbTypes->Cells[1][Counter] = (argv[2]);

    // Price
    if(argv[3])
        AbTypesForm->sgAbTypes->Cells[2][Counter] = FormatFloat(MoneyFormat,strtof(argv[3])).TrimLeft();
    else
        AbTypesForm->sgAbTypes->Cells[2][Counter] = "0.00";

    // Days
    if(argv[4])
    {
        unsigned period = atoi(argv[4]);
        if(period)
        {
            if(period < 30)
                AbTypesForm->sgAbTypes->Cells[3][Counter] = AnsiString(period) + " день";
            else
            {
                period /= 30;
                AbTypesForm->sgAbTypes->Cells[3][Counter] = AnsiString(period) + " мес.";
            }
        }
        else
            AbTypesForm->sgAbTypes->Cells[3][Counter] = "";
    }
    else
        AbTypesForm->sgAbTypes->Cells[3][Counter] = "";

    // Count
    if(argv[5])
        AbTypesForm->sgAbTypes->Cells[4][Counter] = argv[5];
    else
        AbTypesForm->sgAbTypes->Cells[4][Counter] = "0";

    return 0;
}
//---------------------------------------------------------------------------

//***************************************************************************
//*************************** END CALLBACKS *********************************
//***************************************************************************

//---------------------------------------------------------------------------
void __fastcall TAbTypesForm::sgAbTypesWindowProc(Messages::TMessage& Msg)
{
    sgWindowProc(Msg,sgAbTypes,AbTypesWidths,sgOWindowProc);
}
//---------------------------------------------------------------------------
__fastcall TAbTypesForm::TAbTypesForm(TComponent* Owner)
    : TForm(Owner)
{
    fldAlign = "clrrr";

    DefW = Width;
    DefH = Height;
    //DefL = Left;
    //DefT = Top;

    SQL_exefun(DBName,"select SettingsVal from Settings where SettingsKey='AbTypesWidth'",&retString);
    StartW = atoi(retString.c_str());

    SQL_exefun(DBName,"select SettingsVal from Settings where SettingsKey='AbTypesHeight'",&retString);
    StartH = atoi(retString.c_str());

    if(!StartW) StartW = Width;
    else        Width = StartW;
    if(!StartH) StartH = Height;
    else        Height = StartH;
}
//---------------------------------------------------------------------------
void __fastcall TAbTypesForm::FormShow(TObject *Sender)
{
    if(AbTypesFormMode)
    {
        tbNew->Visible = false;
        tbEdit->Visible = false;
        //tbSave->Visible = false;
        //tbD1->Visible = false;

        AbTypesFormRetID = 0;
        AbTypesFormRet1 = "";
        AbTypesFormRet2 = "";
    }

    sgSetHeaders(sgAbTypes,"","Наименование","Цена","Время действия","Кол-во занятий");
    sgSetWidths(sgAbTypes,&AbTypesWidths,16,250,70,70);

    sgOWindowProc = sgAbTypes->WindowProc;
    sgAbTypes->WindowProc = sgAbTypesWindowProc;

    SQL_exefun(DBName,"select count(*) from Stars",&retString);

    pUsers = new AnsiString[atoi(retString.c_str()) + 1];
    if(!pUsers) Close();
    pUserIDs = new __int64[atoi(retString.c_str()) + 1];
    if(!pUserIDs) Close();
    UsersCounter = 1;
    pUsers[0] = "admin";
    pUserIDs[0] = 0;
    SQL_exe(DBName,"select RowID,StarsUser from Stars",users_select);

    sgAbTypesFullUpdate();

    sgAbTypes->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TAbTypesForm::FormDestroy(TObject *Sender)
{
    PDEL(IDs);
    PDEL(pUsers);
    PDEL(pUserIDs);

    delete [] AbTypesWidths;

    if(WindowState == wsNormal && BorderStyle == bsSizeable)
    {
        SQL_BeginTransaction();
        if(Width != StartW)
            SQL_exe(DBName,("update Settings set SettingsVal='"+AnsiString(Width)+"' where SettingsKey='AbTypesWidth'").c_str());
        if(Height != StartH)
            SQL_exe(DBName,("update Settings set SettingsVal='"+AnsiString(Height)+"' where SettingsKey='AbTypesHeight'").c_str());
        SQL_CommitTransaction();
    }
}
//---------------------------------------------------------------------------
void __fastcall TAbTypesForm::sgAbTypesDrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
    if(State.Contains(gdFixed))
    {
        sgAbTypes->Canvas->Font->Style = TFontStyles() << fsBold;
        sgAbTypes->Canvas->Font->Color = HEADER_COLOR;

        int lft = Rect.Width() - sgAbTypes->Canvas->TextWidth(sgAbTypes->Cells[ACol][0]);
        if(lft < 2) lft = 2;
        else lft >>= 1;
        sgAbTypes->Canvas->TextRect(Rect,Rect.left+lft,Rect.top+1,sgAbTypes->Cells[ACol][0]);
    }
    else
    {
        if(State.Contains(gdSelected))
        {
            sgAbTypes->Canvas->Brush->Color = SelColor;
            //SEL_COLOR;
            sgAbTypes->Canvas->FillRect(Rect);
        }
        else
        {
            sgAbTypes->Canvas->Brush->Color = clWhite;
            sgAbTypes->Canvas->FillRect(Rect);
        }

        if(ACol == 0)
        {
            if(IDs)
            {
                if((sgAbTypes->Cells[ACol][ARow]).Length() == 0)
                    ilAbTypes->Draw(sgAbTypes->Canvas,Rect.left,Rect.top,0);
                else
                    ilAbTypes->Draw(sgAbTypes->Canvas,Rect.left,Rect.top,1);
            }
        }
        else
        {
            sgAbTypes->Canvas->Font->Color = clBlack;
            sgAlignTextDraw(sgAbTypes,ACol,ARow,Rect,fldAlign);
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TAbTypesForm::sgAbTypesRowInfo(__int64 *pID, unsigned cnt)
{
    if(pID)
    {
        AnsiString status = "ID: " + (AnsiString)pID[cnt];

        CDate = 0;
        CUID = -1;
        EDate = 0;
        EUID = -1;

        SQL_exe(DBName,("select CDate,CUID,EDate,EUID from AbTypes where RowID="+(AnsiString)pID[cnt]).c_str(),abtypes_setinfo);

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

        sbAbTypes->SimpleText = status;
    }
    else
    {
        sbAbTypes->SimpleText = "ID: ";
    }
}
//---------------------------------------------------------------------------
void __fastcall TAbTypesForm::sgAbTypesRowUpdate(__int64 *pID, unsigned cnt)
{
    if(pID)
        SQL_exe(DBName,("select Alive,Name,Price,Days,AbTypesCount from AbTypes where RowID=" + (AnsiString)pID[cnt]).c_str(),abtypes_rowupdate);
    else
    {
        sgAbTypes->Cells[0][UpdatedRow] = "";
        sgAbTypes->Cells[1][UpdatedRow] = "";
        sgAbTypes->Cells[2][UpdatedRow] = "";
        sgAbTypes->Cells[3][UpdatedRow] = "";
        sgAbTypes->Cells[4][UpdatedRow] = "";
    }

    sgAbTypesRowInfo(pID,cnt);
}
//---------------------------------------------------------------------------
void __fastcall TAbTypesForm::sgAbTypesFullUpdate(void)
{
    if(AbTypesFormMode == 1)
        SQL_exefun(DBName,"select count(*) from AbTypes where Bath=0 or Name like 'Клубная%'",&retString);
    else if(AbTypesFormMode == 2)
        SQL_exefun(DBName,"select count(*) from AbTypes where Bath=1 and Name not like 'Клубная%'",&retString);
    else
        SQL_exefun(DBName,"select count(*) from AbTypes",&retString);

    __int64 SelRowID;
    bool SelFlag = false;
    if(IDs)
    {
        SelFlag = true;
        SelRowID = IDs[sgAbTypes->Row-1];
        PDEL(IDs);
    }

    int icnt = atoi(retString.c_str());
    sgAbTypes->RowCount = (!icnt)? 2 : icnt + 1;
    sgAbTypes->Rows[sgAbTypes->RowCount-1]->Clear();
    sgAbTypes->Cells[0][1] = "";

    Counter = 0;

    if(icnt)
    {
        IDs = new __int64[icnt];
        if(!IDs) Close();

        if(AbTypesFormMode == 1)
            SQL_exe(DBName,"select RowID,Alive,Name,Price,Days,AbTypesCount from AbTypes where Bath=0 or Name like 'Клубная%' order by Name,EDate",abtypes_select);
        else if(AbTypesFormMode == 2)
            SQL_exe(DBName,"select RowID,Alive,Name,Price,Days,AbTypesCount from AbTypes where Bath=1 and Name not like 'Клубная%' order by Name,EDate",abtypes_select);
        else
            SQL_exe(DBName,"select RowID,Alive,Name,Price,Days,AbTypesCount from AbTypes order by Name,EDate",abtypes_select);

        if(SelFlag)
        {
            unsigned i;
            for(i = 0; i < Counter; i++)
                if(IDs[i] == SelRowID) break;
            if(i == Counter)
                sgAbTypes->Row = 1;
            else
                sgAbTypes->Row = i + 1;
        }
        else
            sgAbTypes->Row = 1;
    }
    else
        sgAbTypes->Row = 1;

    sgAbTypesRowInfo(IDs,sgAbTypes->Row-1);
}
//---------------------------------------------------------------------------
void __fastcall TAbTypesForm::sgAbTypesEdit(void)
{
    if(sgAbTypes->Row > 0 && Counter > 0)
    {
        if(!IDs) return;

        AbTypeID = IDs[sgAbTypes->Row-1];
        iAbTypesForm = new TiAbTypesForm(this);
        iAbTypesForm->ShowModal();
        if(FormResult == -1)
        {
            // Обновить запись
            UpdatedRow = sgAbTypes->Row;
            SQL_exe(DBName,("select Alive,Name,Price,Days,AbTypesCount from AbTypes where RowID=" + (AnsiString)AbTypeID).c_str(),abtypes_rowupdate);
            sgAbTypesRowInfo(&AbTypeID,0);
        }
        delete iAbTypesForm;
    }
}
//---------------------------------------------------------------------------
void __fastcall TAbTypesForm::sgAbTypesNew(void)
{
    AbTypeID = 0;
    FormResult = 0;
    iAbTypesForm = new TiAbTypesForm(this);
    iAbTypesForm->ShowModal();
    delete iAbTypesForm;
    
    if(FormResult == 1)
    {
        __int64 *newIDs = new __int64[++Counter];
        if(!newIDs) Close();

        newIDs[0] = AbTypeID;
        for(unsigned i = 1; i < Counter; i++)
            newIDs[i] = IDs[i-1];
        PDEL(IDs);
        IDs = newIDs;

        if(Counter > 1)
        {
            sgAbTypes->RowCount++;

        // Сдвинуть все вниз
            for(unsigned i = Counter; i > 1; i--)
                sgAbTypes->Rows[i] = sgAbTypes->Rows[i-1];
        }

        sgAbTypes->Row = 1;
        UpdatedRow = 1;
        sgAbTypesRowUpdate(IDs,0);
    }
}
//---------------------------------------------------------------------------
void __fastcall TAbTypesForm::tbNewClick(TObject *Sender)
{
    sgAbTypesNew();
}
//---------------------------------------------------------------------------
void __fastcall TAbTypesForm::tbExitClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TAbTypesForm::tbEditClick(TObject *Sender)
{
    sgAbTypesEdit();
}
//---------------------------------------------------------------------------
void __fastcall TAbTypesForm::sgAbTypesSelectCell(TObject *Sender,
      int ACol, int ARow, bool &CanSelect)
{
    sgAbTypesRowInfo(IDs,ARow-1);
}
//---------------------------------------------------------------------------
void __fastcall TAbTypesForm::sgAbTypesDblClick(TObject *Sender)
{
    if(sgAbTypes->Row <= 0 || Counter <= 0 || !IDs) return;

    if(AbTypesFormMode == 1)
    {
        SQL_exefun(DBName,("select FixSum from AbTypes where RowID="+(AnsiString)IDs[sgAbTypes->Row-1]).c_str(),&retString);
        double fixsum = atof(retString.c_str());

        if(fixsum >= 0.0)
        {
            AbParamForm = new TAbParamForm(this);
            AbParamForm->Tag = "Фитнесс";
            AbParamForm->ShowModal();
            if(FormResult == 1)
            {
                AbTypesFormRet3 = AbParamForm->AbParamPID;
                AbTypesFormRet4 = AbParamForm->AbParamSID;

                AbTypesFormRetID = IDs[sgAbTypes->Row-1];

                AbTypesFormRet1 = sgAbTypes->Cells[1][sgAbTypes->Row];
                AbTypesFormRet2 = sgAbTypes->Cells[2][sgAbTypes->Row];
            }

            delete AbParamForm;
        }
        else
        {
            AbTypesFormRet3 = "0";
            AbTypesFormRet4 = "0";

            AbTypesFormRetID = IDs[sgAbTypes->Row-1];

            AbTypesFormRet1 = sgAbTypes->Cells[1][sgAbTypes->Row];
            AbTypesFormRet2 = sgAbTypes->Cells[2][sgAbTypes->Row];
            FormResult = 1;
        }

        Close();
    }
    else if(AbTypesFormMode == 2)
    {
        AbTypesFormRet3 = "0";
        AbTypesFormRet4 = BATH_VISIT;

        AbTypesFormRetID = IDs[sgAbTypes->Row-1];

        AbTypesFormRet1 = sgAbTypes->Cells[1][sgAbTypes->Row];
        AbTypesFormRet2 = sgAbTypes->Cells[2][sgAbTypes->Row];
        FormResult = 1;

        Close();
    }
    else
        sgAbTypesEdit();
}
//---------------------------------------------------------------------------
void __fastcall TAbTypesForm::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key == VK_RETURN && AbTypesFormMode)
    {
        AbTypesFormRetID = IDs[sgAbTypes->Row-1];

        AbTypesFormRet1 = sgAbTypes->Cells[1][sgAbTypes->Row];
        AbTypesFormRet2 = sgAbTypes->Cells[2][sgAbTypes->Row];
        //SQL_exefun(DBName,("select FixSum from AbTypes where RowID="+(AnsiString)AbTypesFormRetID).c_str(),&AbTypesFormRet3);

        Close();
    }
}
//---------------------------------------------------------------------------
void __fastcall TAbTypesForm::sgAbTypesKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key == VK_RETURN)
        sgAbTypesDblClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TAbTypesForm::ToolButton3Click(TObject *Sender)
{
    sgAbTypes->WindowProc = sgOWindowProc;

    WindowState = wsNormal;

    Width = DefW;
    Height = DefH;
    Position = poScreenCenter;

    sgSetWidths(sgAbTypes,&AbTypesWidths,16,250,70,70);

    sgAbTypes->WindowProc = sgAbTypesWindowProc;
}
//---------------------------------------------------------------------------

