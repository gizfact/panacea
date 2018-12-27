//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "personal.h"
#include "lib.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPersonalForm *PersonalForm;

extern const char *DBName;
extern __int64 UserID;
extern const char *MoneyFormat;
extern int FormResult;
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//***************************************************************************
//******************************* CALLBACKS *********************************
//***************************************************************************

//---------------------------------------------------------------------------
static int users_select(void *NotUsed, int argc, char **argv, char **azColName)
{
    PersonalForm->pUserIDs[PersonalForm->UsersCounter] = (argv[0])? _atoi64(argv[0]) : -1;
    if(argv[1])
        PersonalForm->pUsers[(PersonalForm->UsersCounter)++] = (argv[1]);
    else
        PersonalForm->pUsers[(PersonalForm->UsersCounter)++] = "unknown";

    return 0;
}
//---------------------------------------------------------------------------
static int personal_setinfo(void *NotUsed,int argc,char **argv,char **azColName)
{
    if(argv[0])
        PersonalForm->CDate = atof(argv[0]);
    else
        PersonalForm->CDate = 0;

    PersonalForm->CUID = (argv[1])? _atoi64(argv[1]) : -1;

    if(argv[2])
        PersonalForm->EDate = atof(argv[2]);
    else
        PersonalForm->EDate = 0;

    PersonalForm->EUID = (argv[3])? _atoi64(argv[3]) : -1;

    return 0;
}
//---------------------------------------------------------------------------
static int personal_rowupdate(void *NotUsed,int argc,char **argv,char **azColName)
{
    // Alive
    if(argv[0])
        PersonalForm->sgPersonal->Cells[0][PersonalForm->UpdatedRow] = (atoi(argv[0]))? "" : " ";
    else
        PersonalForm->sgPersonal->Cells[0][PersonalForm->UpdatedRow] = "";

    // Name
    PersonalForm->sgPersonal->Cells[1][PersonalForm->UpdatedRow] = (argv[1]);

    // Job
    if(argv[2])
        PersonalForm->sgPersonal->Cells[2][PersonalForm->UpdatedRow] = (argv[2]);
    else
        PersonalForm->sgPersonal->Cells[2][PersonalForm->UpdatedRow] = "";

    return 0;
}
//---------------------------------------------------------------------------
static int personal_select(void *NotUsed, int argc, char **argv, char **azColName)
{
    if((unsigned)PersonalForm->IDs.Length <= PersonalForm->Counter)
        PersonalForm->IDs.Length = PersonalForm->Counter + 10;
    PersonalForm->IDs[PersonalForm->Counter] = _atoi64(argv[0]);

    // Alive
    if(argv[1])
        PersonalForm->sgPersonal->Cells[0][++(PersonalForm->Counter)] = (atoi(argv[1]))? "" : " ";
    else
        PersonalForm->sgPersonal->Cells[0][++(PersonalForm->Counter)] = "";
    // Name
    PersonalForm->sgPersonal->Cells[1][PersonalForm->Counter] = (argv[2]);

    // Job
    PersonalForm->sgPersonal->Cells[2][PersonalForm->Counter] = (argv[3]);

    // Service
    PersonalForm->sgPersonal->Cells[3][PersonalForm->Counter] = (argv[4]);

    return 0;
}
//---------------------------------------------------------------------------

//***************************************************************************
//*************************** END CALLBACKS *********************************
//***************************************************************************

//---------------------------------------------------------------------------
void __fastcall TPersonalForm::pmServicesClick(TObject *Sender)
{
    TMenuItem *ClickedItem = (TMenuItem *)Sender;
    //dynamic_cast<TMenuItem *>(Sender);
    if (ClickedItem)
    {
        TDateTime dt;
        dt = dt.CurrentDateTime();

        SQL_iniUpdate(DBName,"Personal",IDs[sgPersonal->Row-1]);
        SQL_addUpdate("ServiceID",pServicesIDs[ClickedItem->Tag]);
        SQL_addUpdate("EDate",(double)dt);
        SQL_exeUpdate("EUID",UserID);

        sgPersonal->Cells[3][sgPersonal->Row] = (pServices[ClickedItem->Tag]);
        sgPersonalRowInfo(IDs,sgPersonal->Row-1);
    }
}
//---------------------------------------------------------------------------
void __fastcall TPersonalForm::sgWindowProc(Messages::TMessage& Msg)
{
    if(Msg.Msg == WM_SIZE)
    {
        int width = sgPersonal->ClientWidth;
        for(int i = 0; i < sgPersonal->ColCount - 1; i++)
            width -= sgPersonal->ColWidths[i];

        if((width - sgPersonal->ColCount) < 16)
            sgPersonal->ColWidths[sgPersonal->ColCount-1] = 16;
        else
            sgPersonal->ColWidths[sgPersonal->ColCount-1] = width - sgPersonal->ColCount;
    }
    else
        sgOWindowProc(Msg);
}
//---------------------------------------------------------------------------
__fastcall TPersonalForm::TPersonalForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TPersonalForm::FormShow(TObject *Sender)
{
    sgPersonal->ColWidths[0] = 16;
    sgPersonal->ColWidths[1] = 160;
    sgPersonal->ColWidths[2] = 110;
    sgPersonal->ColWidths[3] = sgPersonal->ClientWidth - sgPersonal->ColWidths[0] - sgPersonal->ColWidths[1] - sgPersonal->ColWidths[2] - sgPersonal->ColCount;

    sgPersonal->Cells[1][0] = "Имя";
    sgPersonal->Cells[2][0] = "Должность";
    sgPersonal->Cells[3][0] = "Отдел";

    sgOWindowProc = sgPersonal->WindowProc;
    sgPersonal->WindowProc = sgWindowProc;

    pServicesIDs = NULL;
    pServices = NULL;
    unsigned cnt = SQL_fldKeyCollect(DBName,"Name","from Services where ParentID=0 order by Name",&pServicesIDs,&pServices);
    TMenuItem *pNewItem;

    for(unsigned i = 0; i < cnt; i++)
    {
        pNewItem = new TMenuItem(pmServices);
        pNewItem->Tag = i;
        pNewItem->Caption = (pServices[i]);
        pNewItem->OnClick = pmServicesClick;
        pmServices->Items->Add(pNewItem);
    }

    SQL_exefun(DBName,"select count(*) from Stars",&retString);

    pUsers = new AnsiString[atoi(retString.c_str()) + 1];
    if(!pUsers) Close();
    pUserIDs = new __int64[atoi(retString.c_str()) + 1];
    if(!pUserIDs) Close();
    UsersCounter = 1;
    pUsers[0] = "admin";
    pUserIDs[0] = 0;
    SQL_exe(DBName,"select RowID,StarsUser from Stars",users_select);

    sgPersonalFullUpdate();

    //sgPersonal->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TPersonalForm::sgPersonalRowInfo(DynamicArray<__int64> pID, unsigned cnt)
{
    if((unsigned)pID.Length >= Counter && Counter > 0)
    {
        AnsiString status = "ID: " + (AnsiString)pID[cnt];

        CDate = 0;
        CUID = -1;
        EDate = 0;
        EUID = -1;

        SQL_exe(DBName,("select CDate,CUID,EDate,EUID from Personal where RowID="+(AnsiString)pID[cnt]).c_str(),personal_setinfo);

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

        sbPersonal->SimpleText = status;
    }
    else
    {
        sbPersonal->SimpleText = "ID: ";
    }
}
//---------------------------------------------------------------------------
void __fastcall TPersonalForm::sgPersonalFullUpdate(void)
{
    SQL_exefun(DBName,"select count(*) from Personal",&retString);

    __int64 SelRowID = (Counter)? IDs[sgPersonal->Row-1] : 0;

    int icnt = atoi(retString.c_str());
    sgPersonal->RowCount = (!icnt)? 2 : icnt + 1;
    sgPersonal->Rows[sgPersonal->RowCount-1]->Clear();
    sgPersonal->Cells[0][1] = "";

    Counter = 0;

    if(icnt)
    {
        if(IDs.Length < icnt)
            IDs.Length = icnt + 10;

        SQL_exe(DBName,"select Personal.RowID,Alive,Personal.Name,Job,Services.Name from Personal left outer join Services on ServiceID=Services.RowID order by Personal.Name,Personal.CDate",personal_select);

        if(SelRowID)
        {
            unsigned i;
            for(i = 0; i < Counter; i++)
                if(IDs[i] == SelRowID) break;
            if(i == Counter)
                sgPersonal->Row = 1;
            else
                sgPersonal->Row = i + 1;
        }
        else
            sgPersonal->Row = 1;
    }
    else
        sgPersonal->Row = 1;

    sgPersonalRowInfo(IDs,sgPersonal->Row-1);
}
//---------------------------------------------------------------------------
void __fastcall TPersonalForm::sgPersonalDrawCell(TObject *Sender,
      int ACol, int ARow, TRect &Rect, TGridDrawState State)
{
    if(State.Contains(gdFixed))
    {
        sgPersonal->Canvas->Font->Style = TFontStyles() << fsBold;
        sgPersonal->Canvas->Font->Color = HEADER_COLOR;

        int lft = Rect.Width() - sgPersonal->Canvas->TextWidth(sgPersonal->Cells[ACol][0]);
        if(lft < 2) lft = 2;
        else lft >>= 1;
        sgPersonal->Canvas->TextRect(Rect,Rect.left+lft,Rect.top+1,sgPersonal->Cells[ACol][0]);
    }
    else
    {
        if(State.Contains(gdSelected))
        {
            sgPersonal->Canvas->Brush->Color = SelColor;
            //SEL_COLOR;
            sgPersonal->Canvas->FillRect(Rect);
        }
        else
        {
            sgPersonal->Canvas->Brush->Color = clWhite;
            sgPersonal->Canvas->FillRect(Rect);
        }

        if(ACol == 0)
        {
            if(IDs.Length)
            {
                if((sgPersonal->Cells[ACol][ARow]).Length() == 0)
                    ilPersonal->Draw(sgPersonal->Canvas,Rect.left,Rect.top,0);
                else
                    ilPersonal->Draw(sgPersonal->Canvas,Rect.left,Rect.top,1);
            }
        }
        else
        {
            sgPersonal->Canvas->Font->Color = clBlack;
            sgPersonal->Canvas->TextRect(Rect,Rect.left+2,Rect.top+1,sgPersonal->Cells[ACol][ARow]);
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TPersonalForm::FormDestroy(TObject *Sender)
{
    PDEL(pUsers);
    PDEL(pUserIDs);
    PDEL(pServicesIDs);
    PDEL(pServices);
}
//---------------------------------------------------------------------------
void __fastcall TPersonalForm::tbExitClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TPersonalForm::tbNewClick(TObject *Sender)
{
    sgPersonalNew();
}
//---------------------------------------------------------------------------
void __fastcall TPersonalForm::sgPersonalNew(void)
{
    UpdatedRow = sgPersonal->Row;

    if(Counter > 0)
    {
        sgPersonal->RowCount++;

        // Сдвинуть все вниз
        for(unsigned i = Counter + 1; i > 1; i--)
            sgPersonal->Rows[i] = sgPersonal->Rows[i-1];

        sgPersonal->Rows[1]->Clear();
    }

    sgPersonal->Row = 1;

    NewFlag = true;
    EditCol = 1;

    sgPersonalEdit();
}
//---------------------------------------------------------------------------
void __fastcall TPersonalForm::sgPersonalEdit(void)
{
    if(NewFlag || (sgPersonal->Row > 0 && Counter > 0))
    {
        if((unsigned)IDs.Length < Counter && !NewFlag) return;

        if(!EditMode)
        {
            TPoint pos;
            GetCursorPos(&pos);
            pos = sgPersonal->ScreenToClient(pos);

            int Row;

            sgPersonal->MouseToCell(pos.x,pos.y,EditCol,Row);

            if(EditCol < 1 || EditCol > 2)
                EditCol = 1;
        }

        TRect rect = sgPersonal->CellRect(EditCol,sgPersonal->Row);

        edInput->Left = rect.Left + 2;
        edInput->Top = rect.Top + sgPersonal->Top + 2;
        edInput->Width = rect.Width();
        edInput->Height = rect.Height();

        PersonName = sgPersonal->Cells[1][sgPersonal->Row];
        PersonJob = sgPersonal->Cells[2][sgPersonal->Row];

        edInput->Text = sgPersonal->Cells[EditCol][sgPersonal->Row];

        if(!NewFlag)
            PersonID = IDs[sgPersonal->Row-1];
        else
            PersonID = 0;

        edInput->Visible = true;
        edInput->SetFocus();
    }

    EditMode = false;
}
//---------------------------------------------------------------------------
void __fastcall TPersonalForm::sgPersonalDblClick(TObject *Sender)
{
    sgPersonalEdit();
}
//---------------------------------------------------------------------------
void __fastcall TPersonalForm::edInputExit(TObject *Sender)
{
    // Откат
    if(NewFlag && !edInput->Modified)
    {
        for(unsigned i = 2; i < Counter + 2; i++)
            sgPersonal->Rows[i-1] = sgPersonal->Rows[i];
        sgPersonal->RowCount--;

        sgPersonal->Row = UpdatedRow;
    }
    else
    {
        sgPersonal->Cells[EditCol][sgPersonal->Row] = edInput->Text;

        if(EditCol == 1)
            PersonName = edInput->Text;
        else
            PersonJob = edInput->Text;

        PersonalSave();

        edInput->Modified = false;
    }
    
    edInput->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TPersonalForm::edInputKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key == VK_ESCAPE)
    {
        //Key = 0;
        // Откат
        //if(NewFlag)
        //{
        //    for(unsigned i = 2; i < Counter + 2; i++)
        //        sgPersonal->Rows[i-1] = sgPersonal->Rows[i];
        //    sgPersonal->RowCount--;

        //    sgPersonal->Row = UpdatedRow;
        //}

        //NewFlag = false;

        sgPersonal->SetFocus();
    }
    else if(Key == VK_RETURN)
    {
        Key = 0;
        sgPersonal->SetFocus();

        if((unsigned)sgPersonal->Row <= Counter)
        {
            if((unsigned)sgPersonal->Row < Counter || EditCol == 1)
            {
                if(EditCol == 1)
                    EditCol = 2;
                else
                {
                    EditCol = 1;
                    sgPersonal->Row++;
                }

                EditMode = true;
                sgPersonalEdit();
            }
        }
    }
    else if(Key == VK_UP && Shift.Contains(ssCtrl) && sgPersonal->Row > 1)
    {
        Key = 0;
        sgPersonal->SetFocus();

        sgPersonal->Row--;
        EditMode = true;

        sgPersonalEdit();
    }
    else if(Key == VK_DOWN && Shift.Contains(ssCtrl) && (unsigned)sgPersonal->Row < Counter )
    {
        Key = 0;
        sgPersonal->SetFocus();
        sgPersonal->Row++;
        EditMode = true;

        sgPersonalEdit();
    }
    else if((Key == VK_RIGHT || Key == VK_LEFT) && Shift.Contains(ssCtrl))
    {
        Key = 0;
        sgPersonal->SetFocus();

        if(EditCol == 1)
        {
            PersonName = edInput->Text;
            sgPersonal->Cells[1][sgPersonal->Row] = PersonName;
            EditCol = 2;
        }
        else
        {
            PersonJob = edInput->Text;
            sgPersonal->Cells[2][sgPersonal->Row] = PersonJob;
            EditCol = 1;
        }

        //TRect rect = sgPersonal->CellRect(EditCol,sgPersonal->Row);

        EditMode = true;
        //TPoint pos(rect.left+1,rect.top+1);

         //GetCursorPos(&pos);
         //pos = sgPersonal->ScreenToClient(pos);
         //pos = sgPersonal->ClientToScreen(pos);
        //TPoint cur;
        //GetCursorPos(&cur);
        //SetCursorPos(pos.x,pos.y);
        //TMessage Msg;
        //Msg.Msg = WM_MOUSEMOVE;
        //Msg.WParam = 0;
        //Msg.LParamLo = pos.x;
        //Msg.LParamHi = pos.y;

        //PersonalForm->Broadcast(&Msg);



        //SendMessage(sgPersonal->Handle,WM_MOUSEMOVE,0,(pos.y<<16)+pos.x);

        //PostMessage(PersonalForm->Handle,WM_LBUTTONDBLCLK,MK_LBUTTON,0);

        //TMessage Msg;
        //Msg.Msg = WM_LBUTTONDBLCLK;
        //Msg.WParam = MK_LBUTTON;

        //PersonalForm->Broadcast(&Msg);
        sgPersonalEdit();
        //PostMessage(sgPersonal->Handle,WM_LBUTTONDBLCLK,MK_LBUTTON,0);

        //SetCursorPos(cur.x,cur.y);
        //sgPersonalDblClick(Sender);
    }
}
//---------------------------------------------------------------------------
void __fastcall TPersonalForm::PersonalSave(void)
{
    if(!edInput->Visible || !edInput->Modified) return;

    TDateTime dt;
    dt = dt.CurrentDateTime();

    if(NewFlag)
    {
        NewFlag = false;
        SQL_iniInsert(DBName,"Personal",&PersonID);
        SQL_addInsert("#Name",PersonName);
        SQL_addInsert("#Job",PersonJob);
        SQL_addInsert("CDate",(double)dt);
        SQL_addInsert("CUID",UserID);
        SQL_addInsert("EDate",(double)dt);
        SQL_exeInsert("EUID",UserID);

        Counter++;
        if((unsigned)IDs.Length < Counter)
            IDs.Length = Counter + 10;

        for(unsigned i = Counter - 1; i > 0; i--)
            IDs[i] = IDs[i-1];

        IDs[0] = PersonID;
    }
    else
    {
        SQL_iniUpdate(DBName,"Personal",PersonID);
        SQL_addUpdate("#Name",PersonName);
        SQL_addUpdate("#Job",PersonJob);
        SQL_addUpdate("EDate",(double)dt);
        SQL_exeUpdate("EUID",UserID);
    }

    //sgPersonalFullUpdate();
    edInput->Modified = false;

    sgPersonal->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TPersonalForm::tbSaveClick(TObject *Sender)
{
    PersonalSave();
}
//---------------------------------------------------------------------------
void __fastcall TPersonalForm::sgPersonalSelectCell(TObject *Sender,
      int ACol, int ARow, bool &CanSelect)
{
    sgPersonalRowInfo(IDs,ARow-1);
}
//---------------------------------------------------------------------------

void __fastcall TPersonalForm::tbEditClick(TObject *Sender)
{
    sgPersonalEdit();
}
//---------------------------------------------------------------------------
void __fastcall TPersonalForm::tbAliveClick(TObject *Sender)
{
    sgPersonal->SetFocus();

    if(sgPersonal->Row >= 1 && Counter > 0 && (unsigned)IDs.Length >= Counter)
    {
        TDateTime dt;
        dt = dt.CurrentDateTime();

        int alive;

        if(sgPersonal->Cells[0][sgPersonal->Row].Length())
        {
            sgPersonal->Cells[0][sgPersonal->Row] = "";
            alive = 1;
        }
        else
        {
            sgPersonal->Cells[0][sgPersonal->Row] = " ";
            alive = 0;
        }

        SQL_iniUpdate(DBName,"Personal",IDs[sgPersonal->Row-1]);
        SQL_addUpdate("Alive",alive);
        SQL_addUpdate("EDate",(double)dt);
        SQL_exeUpdate("EUID",UserID);

        sgPersonalRowInfo(IDs,sgPersonal->Row-1);
    }
    //sgPersonalFullUpdate();


    //sgPersonal->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TPersonalForm::sgPersonalKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
    if(Key == VK_INSERT)
    {
        Key = 0;
        sgPersonalNew();
    }
}
//---------------------------------------------------------------------------
void __fastcall TPersonalForm::sgPersonalMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if(Button == mbRight && sgPersonal->Row >= 1 && Counter > 0 && (unsigned)IDs.Length >= Counter)
    {
        TPoint pos(X,Y);

        pos = sgPersonal->ClientToScreen(pos);
        pmServices->Popup(pos.x,pos.y);
    }
}
//---------------------------------------------------------------------------

