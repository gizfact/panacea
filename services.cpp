//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "services.h"
#include "lib.h"
#include "dm_main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TServicesForm *ServicesForm;
static TTreeNode *pNewNode = NULL;

int ServicesFormMode = 0;
__int64 ServicesFormRetID = 0;
AnsiString ServicesFormRetStr;

extern const char *DBName;
extern __int64 UserID;
extern bool AdminMode;

static TDateTime CDate, EDate;
static __int64 CUID, EUID;

static AnsiString *pUsers = NULL;
static __int64 *pUserIDs = NULL;
static unsigned UsersCounter = 0;

static AnsiString retString;
static bool SetRowInfo = false;

static TWndMethod tvOWindowProc;
//***************************************************************************
//******************************* CALLBACKS *********************************
//***************************************************************************

//---------------------------------------------------------------------------
static int services_select(void *NotUsed, int argc, char **argv, char **azColName)
{
    if(!argv[0] || !argv[1] || !argv[2]) return 0;

    TTreeNode *pNode;
    TTreeNode *pParent = ServicesForm->tvServices->Selected;

    if(atoi(argv[1]) == 0)
        pNode = ServicesForm->tvServices->Items->Add(NULL,(argv[2]));
    else
    {
        pNode = ServicesForm->tvServices->Items->AddChild(pParent,(argv[2]));
    }

    pNode->Data = new __int64;
    *((__int64 *)(pNode->Data)) = _atoi64(argv[0]);

    ServicesForm->tvServices->Selected = pNode;

    SQL_exe(DBName,((AnsiString)"select RowID,ParentID,Name from Services where ParentID="+argv[0]).c_str(),services_select);

    ServicesForm->tvServices->Selected = pParent;

    return 0;
}
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
static int services_setinfo(void *NotUsed,int argc,char **argv,char **azColName)
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

//***************************************************************************
//*************************** END CALLBACKS *********************************
//***************************************************************************

//---------------------------------------------------------------------------
void __fastcall TServicesForm::tvWindowProc(Messages::TMessage& Msg)
{
    if(!edInput->Focused()) tvOWindowProc(Msg);
    else if(Msg.Msg != WM_VSCROLL && Msg.Msg != WM_HSCROLL && Msg.Msg != WM_MOUSEWHEEL)
        tvOWindowProc(Msg);
}
//---------------------------------------------------------------------------
__fastcall TServicesForm::TServicesForm(TComponent* Owner)
    : TForm(Owner)
{
    for(int i = 0; i < pmService->Items->Count; i++)
    {
        if(pmService->Items->Items[i]->Tag)
            pmService->Items->Items[i]->OnClick = PopupMenuItemsClick;
        else
            pmService->Items->Items[i]->Enabled = false;
    }
}
//---------------------------------------------------------------------------
void __fastcall TServicesForm::sgServicesRowInfo(__int64 *pID, unsigned cnt)
{
    if(!SetRowInfo) return;
    if(pID)
    {
        AnsiString status = "ID: " + (AnsiString)pID[cnt];

        CDate = 0;
        CUID = -1;
        EDate = 0;
        EUID = -1;

        SQL_exe(DBName,("select CDate,CUID,EDate,EUID from Services where RowID="+(AnsiString)pID[cnt]).c_str(),services_setinfo);

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

        sbServices->SimpleText = status;

    }
    else
    {

        sbServices->SimpleText = "ID: ";

    }
}
//---------------------------------------------------------------------------
void __fastcall TServicesForm::tbNewClick(TObject *Sender)
{
    // TTreeView
    TTreeNode *pNode = tvServices->Selected;

    if(GetKeyState(VK_LCONTROL) < 0)
        pNode = tvServices->Items->Add(NULL,"...");
    else if(pNode)
        pNode = tvServices->Items->AddChild(pNode,"...");
    else return;

        if(pNode)
        {
            tvServices->Selected = pNode;
            pNewNode = pNode;
//            pNode->EditText();
            TRect rect = pNode->DisplayRect(true);

            edInput->Text = pNode->Text;
            edInput->Left = rect.Left + 2;
            edInput->Top = rect.Top + tvServices->Top + 1;
            edInput->Width = tvServices->Width - edInput->Left - 20;
            //edInput->Width = (rect.Width() > 120)? rect.Width() : 120;
            edInput->Height = rect.Height() + 2;
            edInput->Enabled = true;
            edInput->Visible = true;
            edInput->SetFocus();
        }

}
//---------------------------------------------------------------------------
void __fastcall TServicesForm::edInputExit(TObject *Sender)
{
    edInput->Visible = false;
    edInput->Enabled = false;

    if(pNewNode && edInput->Text == "...")
        pNewNode->Delete();
    //else
      //  tvServices->Selected->Text = edInput->Text;
    pNewNode = NULL;

    ShowScrollBar(tvServices->Handle,SB_VERT,true);
    ShowScrollBar(tvServices->Handle,SB_HORZ,true);
}
//---------------------------------------------------------------------------
void __fastcall TServicesForm::FormShow(TObject *Sender)
{
    if(AdminMode)
    {
        //tbFromSPA->Visible = true;
        //tbToPan->Visible = true;
    }

    if(ServicesFormMode)
    {
        tbNew->Visible = false;
        tbEdit->Visible = false;
        tbSave->Visible = false;
        tbD1->Visible = false;

        ServicesFormRetID = 0;
        ServicesFormRetStr = "";
    }

    tvOWindowProc = tvServices->WindowProc;
    tvServices->WindowProc = tvWindowProc;

    SQL_exefun(DBName,"select count(*) from Stars",&retString);

    pUsers = new AnsiString[atoi(retString.c_str()) + 1];
    if(!pUsers) Close();
    pUserIDs = new __int64[atoi(retString.c_str()) + 1];
    if(!pUserIDs) Close();
    UsersCounter = 1;
    pUsers[0] = "admin";
    pUserIDs[0] = 0;
    SQL_exe(DBName,"select RowID,StarsUser from Stars",users_select);

    tvServices->Items->Clear();
    SQL_BeginTransaction();
    SQL_exe(DBName,"select RowID,ParentID,Name from Services where ParentID=0",services_select);
    SQL_CancelTransaction();
    tvServices->FullCollapse();
    tvServices->SortType = Comctrls::stText;
    SetRowInfo = true;
    tvServices->Selected = tvServices->Items->GetFirstNode();
    tvServices->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TServicesForm::tvServicesDblClick(TObject *Sender)
{
    TTreeNode *pNode = tvServices->Selected;

    if(pNode)
    {
        if(ServicesFormMode)
        {
            if(pNode->Data)
                ServicesFormRetID = *((__int64 *)pNode->Data);
            else
                ServicesFormRetID = 0;
            ServicesFormRetStr = pNode->Text;
            Close();

        }

        TRect rect = pNode->DisplayRect(true);

        edInput->Text = pNode->Text;
        edInput->Left = rect.Left + 2;
        edInput->Top = rect.Top + tvServices->Top + 1;
        if(GetWindowLong(tvServices->Handle,GWL_STYLE) & WS_VSCROLL)
            edInput->Width = tvServices->Width - edInput->Left - 18;
        else
            edInput->Width = tvServices->Width - edInput->Left;
        //edInput->Width = tvServices->Width - edInput->Left;
        // - 20;
        //edInput->Width = (rect.Width() > 120)? rect.Width() : 120;
        edInput->Height = rect.Height() + 2;
        edInput->Enabled = true;
        edInput->Visible = true;
        edInput->SetFocus();
    }
}
//---------------------------------------------------------------------------
void __fastcall TServicesForm::tvServicesChange(TObject *Sender,
      TTreeNode *Node)
{
    if(tvServices->Selected)
        sgServicesRowInfo((__int64 *)(tvServices->Selected->Data),0);
}
//---------------------------------------------------------------------------
void __fastcall TServicesForm::tbExitClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TServicesForm::tbSaveClick(TObject *Sender)
{
    if(!edInput->Focused()) return;
    if(edInput->Text == "...") return;
    if(!edInput->Modified)
    {
        tvServices->SetFocus();
        return;
    }

    TDateTime dt;
    dt = dt.CurrentDateTime();

    if(pNewNode)
    {
        __int64 ID = 0;
        SQL_iniInsert(DBName,"Services",&ID);
        SQL_addInsert("#Name",edInput->Text);
        if(pNewNode->Parent && pNewNode->Parent->Data)
            SQL_addInsert("ParentID",*((__int64 *)pNewNode->Parent->Data));

        if(pNewNode->Level > 0)
        {
            TTreeNode *pParent = pNewNode;
            AnsiString Tag = "~";

            while(pParent->Parent)
            {
                pParent = pParent->Parent;
                Tag = "~" + pParent->Text + Tag;
            }
            SQL_addInsert("#Tag",Tag);
        }
        SQL_addInsert("CDate",(double)dt);
        SQL_addInsert("CUID",UserID);
        SQL_addInsert("EDate",(double)dt);
        SQL_exeInsert("EUID",UserID);

        pNewNode->Data = new __int64;
        *((__int64 *)pNewNode->Data) = ID;


    }
    else
    {
        SQL_iniUpdate(DBName,"Services",*(__int64 *)(tvServices->Selected->Data));
        SQL_addUpdate("#Name",edInput->Text);
        SQL_addUpdate("EDate",(double)dt);
        SQL_exeUpdate("EUID",UserID);

        AnsiString Tag;
        SQL_exefun(DBName,("select Tag from Services where RowID="+AnsiString(*(__int64 *)(tvServices->Selected->Data))).c_str(),&Tag);

        Tag += ((edInput->Text) + "~");

        UpdateBranchTags(*(__int64 *)(tvServices->Selected->Data),Tag);


    }

    tvServices->Selected->Text = edInput->Text;
    sgServicesRowInfo((__int64 *)(tvServices->Selected->Data),0);

    edInput->Modified = false;

    tvServices->SetFocus();
}
//---------------------------------------------------------------------------
void import_fun(TTreeNode *pNode,__int64 ID)
{
    // pNode - вставляемый, ID - верхнего уровня

    if(!pNode) return;

    //AnsiString s = pNode->Text;
    if(SQL_BeginTransaction() != SQLITE_OK) return;

    __int64 newID = 0;
    TDateTime dt;
    dt = dt.CurrentDateTime();

    SQL_iniInsert(DBName,"Services",&newID);
    SQL_addInsert("#Name",pNode->Text);
    if(pNode->Parent)
        SQL_addInsert("ParentID",ID);
    if(pNode->Level > 0)
    {
        TTreeNode *pParent = pNode;
        while(pParent->Parent)
            pParent = pParent->Parent;
        SQL_addInsert("#Tag",pParent->Text);
    }
    SQL_addInsert("CDate",(double)dt);
    SQL_addInsert("CUID",UserID);
    SQL_addInsert("EDate",(double)dt);
    SQL_exeInsert("EUID",UserID);

    pNode->Data = new __int64;
    *((__int64 *)pNode->Data) = newID;

    TTreeNode *pChild = pNode->getFirstChild();
    while(pChild)
    {
        import_fun(pChild,newID);
        pChild = pNode->GetNextChild(pChild);
    }

    SQL_CommitTransaction();
}
//---------------------------------------------------------------------------
void __fastcall TServicesForm::tbToPanClick(TObject *Sender)
{
    // Импорт в базу
    AnsiString s, s1, s2, s3;

    // А теперь это экспорт ветки в файл

    TTreeNode *pNode = tvServices->Selected;
    // Должна быть ветвь верхнего уровня
    if(!pNode || pNode->Level) return;

    if(!dmMain->dlgSave->Execute()) return;

    // Обход ветки
    tvServices->SaveToFile(dmMain->dlgSave->FileName);
}
//---------------------------------------------------------------------------
void __fastcall TServicesForm::tvServicesDeletion(TObject *Sender,
      TTreeNode *Node)
{
    PDEL((__int64 *)(Node->Data));
}
//---------------------------------------------------------------------------
void __fastcall TServicesForm::FormDestroy(TObject *Sender)
{
    PDEL(pUsers);
    PDEL(pUserIDs);
}
//---------------------------------------------------------------------------
void __fastcall TServicesForm::edInputKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key == VK_ESCAPE)
    {
        tvServices->SetFocus();
    }
    else if(Key == VK_RETURN)
    {
        tbSaveClick(Sender);
    }
    else if(Key == VK_UP)
    {
        tbSaveClick(Sender);

        TTreeNode *pNode = tvServices->Selected->GetPrev();
        //getPrevSibling();

        if(pNode)
        {
            tvServices->Selected = pNode;
            pNode->Collapse(false);
            TRect rect = pNode->DisplayRect(true);

            PostMessage(tvServices->Handle,WM_LBUTTONDBLCLK,MK_LBUTTON,((rect.top + 5) << 16) + rect.left + 5);
            //tvServicesDblClick(Sender);
        }
    }
    else if(Key == VK_DOWN)
    {

        tbSaveClick(Sender);

        TTreeNode *pNode = tvServices->Selected->GetNext();
        //getNextSibling();

        if(pNode)
        {
            tvServices->Selected = pNode;
            pNode->Collapse(false);
            TRect rect = pNode->DisplayRect(true);

            PostMessage(tvServices->Handle,WM_LBUTTONDBLCLK,MK_LBUTTON,((rect.top + 5) << 16) + rect.left + 5);
            //tvServicesDblClick(Sender);
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TServicesForm::tvServicesKeyPress(TObject *Sender,
      char &Key)
{
    if(Key == 13)
        tvServicesDblClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TServicesForm::edInputEnter(TObject *Sender)
{
    ShowScrollBar(((TWinControl *)tvServices)->Handle,SB_VERT,false);
    //ShowScrollBar(((TWinControl *)tvServices)->Handle,SB_HORZ,false);
}
//---------------------------------------------------------------------------
void __fastcall TServicesForm::recUpdateBranchTags(__int64 ID,AnsiString Tag)
{
    __int64 *pIDs;
    AnsiString *pNames;
    AnsiString sTag;

    unsigned cnt = SQL_fldKeyCollect(DBName,"Name",("from Services where ParentID="+AnsiString(ID)).c_str(),&pIDs,&pNames);

    for(unsigned i = 0; i < cnt; i++)
    {
        SQL_iniUpdate(DBName,"Services",pIDs[i]);
        SQL_exeUpdate("!Tag",Tag);

        sTag = Tag + pNames[i] + "~";
        recUpdateBranchTags(pIDs[i],sTag);
    }

    PDEL(pNames);
    PDEL(pIDs);
}
//---------------------------------------------------------------------------
void __fastcall TServicesForm::UpdateBranchTags(__int64 ID,AnsiString Tag)
{
    if(SQL_BeginTransaction() != SQLITE_OK) return;

    recUpdateBranchTags(ID,Tag);

    SQL_CommitTransaction();
}
//---------------------------------------------------------------------------
void __fastcall TServicesForm::tvServicesMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if(Button == mbRight && tvServices->Selected)
    {


        // Данные Items-а
        AnsiString sDays, sRet;
        __int64 ID = *(__int64 *)tvServices->Selected->Data;

        SQL_exefun3(NULL,("select Price,WeekDays,Personify from Services where RowID="+AnsiString(ID)).c_str(),&retString,&sDays,&sRet);


        pmService->Items->Items[0]->Caption = "Цена: " + AnsiString(atof(retString.c_str()));
        pmService->Items->Items[8]->Caption = "Дни в услуге: " + AnsiString(atoi(sDays.c_str()));
        pmService->Items->Items[12]->Caption = "Специалист: " + AnsiString(atoi(sRet.c_str()));
    }
}
//---------------------------------------------------------------------------
void __fastcall TServicesForm::PopupMenuItemsClick(TObject *Sender)
{
    static char *set[] = { "+50", "-50", "+100", "-100", "+500", "-500", "0", "127", "1", "-1", "0", "1", "-1", "0" };

    TMenuItem *ClickedItem = dynamic_cast<TMenuItem *>(Sender);
    if(ClickedItem && ClickedItem->Tag)
    {
        if(ClickedItem->Tag <= 6)
        {
            SQL_BeginTransaction();
            SQL_exe(NULL,(AnsiString("update Services set Price=Price")+set[ClickedItem->Tag-1]+",PersonPrice=PersonPrice"+set[ClickedItem->Tag-1]+" where RowID="+AnsiString(*(__int64 *)tvServices->Selected->Data)).c_str());
            SQL_CommitTransaction();
        }
        else if(ClickedItem->Tag <= 8)
        {
            SQL_BeginTransaction();
            SQL_exe(NULL,(AnsiString("update Services set WeekDays=")+set[ClickedItem->Tag-1]+" where RowID="+AnsiString(*(__int64 *)tvServices->Selected->Data)).c_str());
            SQL_CommitTransaction();
        }
        else if(ClickedItem->Tag <= 11)
        {
            SQL_BeginTransaction();
              SQL_exe(NULL,(AnsiString("update Services set Personify=")+set[ClickedItem->Tag-1]+" where RowID="+AnsiString(*(__int64 *)tvServices->Selected->Data)).c_str());
            SQL_CommitTransaction();
        }
        else if(ClickedItem->Tag <= 14)
        {
            __int64 ID = *(__int64 *)tvServices->Selected->Data;

            SQL_exefun(NULL, ("select Tag from Services where RowID=" + AnsiString(ID)).c_str(), &retString);
            retString += tvServices->Selected->Text + "~%";

            SQL_BeginTransaction();
              SQL_exe(NULL,(AnsiString("update Services set Personify=")+set[ClickedItem->Tag-1]+" where RowID="+AnsiString(ID)).c_str());
              SQL_exe(NULL,(AnsiString("update Services set Personify=")+set[ClickedItem->Tag-1]+" where Tag like '" + retString + "'").c_str());
            SQL_CommitTransaction();
        }
    }
}
//---------------------------------------------------------------------------



