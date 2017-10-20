//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <stdlib.h>
#include "accounts.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"      
//---------------------------------------------------------------------------
TAccountsForm *AccountsForm;

extern const char *AppForms[];
extern const char *DBName;



static bool PassChange = false;
static bool AccChange = false;
static TTreeNode *pSelectedNode = NULL;
static TTreeNode *pCurNode = NULL;
static const char *pCDateText = "Дата создания: ";
static const char *pEDateText = "Дата изменения: ";
static const char *pPasswdText = "Пароль";
static const char *pCreateText = "Создание";
static const char *pChangeText = "Изменение";
static const char *pReadText = "Чтение";
const char *pDefUserText = "somebody";

static const char *pDefGrants = "0700700700770770000";

typedef struct
{
    __int64 ID;
    unsigned char Grants[FORMS_COUNT];

} UG;
//---------------------------------------------------------------------------
static int acc_select(void *NotUsed, int argc, char **argv, char **azColName)
{
    TTreeNode *pNode, *pChild;

    pNode = AccountsForm->tvAccounts->Items->Add(NULL,argv[1]);

    pNode->Data = new UG;
    memset(((UG *)pNode->Data)->Grants,'0',FORMS_COUNT);
    ((UG *)pNode->Data)->ID = _atoi64(argv[0]);

    unsigned len = (argv[6] == NULL)? 0 : strlen(argv[6]);
    if(len > FORMS_COUNT) len = FORMS_COUNT;

    //for(unsigned i = 0; i < len; i++)
    //    ((UG *)pNode->Data)->Grants[i] = argv[6][i] - '0';
    memcpy(((UG *)pNode->Data)->Grants,argv[6],len);

    if(!argv[5] || !atoi(argv[5]))
        pNode->ImageIndex = 0;
    else
        pNode->ImageIndex = 1;
 
    pNode->SelectedIndex = pNode->ImageIndex;

    pChild = AccountsForm->tvAccounts->Items->AddChild(pNode,pPasswdText);
    pChild->ImageIndex = 2;
    pChild->SelectedIndex = 2;
    pChild = AccountsForm->tvAccounts->Items->AddChild(pChild,argv[2]);
    pChild->ImageIndex = 3;
    pChild->SelectedIndex = 3;
    TDateTime dt;
    if(argv[3])
        dt = atof(argv[3]);
    else
        dt = 0;


    pChild = AccountsForm->tvAccounts->Items->AddChild(pNode,pCDateText + dt);
    pChild->ImageIndex = 4;
    pChild->SelectedIndex = 4;
    if(argv[4])
        dt = atof(argv[4]);
    else
        dt = 0;

    pChild = AccountsForm->tvAccounts->Items->AddChild(pNode,pEDateText + dt);
    pChild->ImageIndex = 5;
    pChild->SelectedIndex = 5;

    return 0;
}
//---------------------------------------------------------------------------
__fastcall TAccountsForm::TAccountsForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TAccountsForm::tvGrantsDblClick(TObject *Sender)
{
    TTreeNode *pNode = tvGrants->Selected;
    if(!pNode) return;
    if(pNode->ImageIndex == 0) return;

    TTreeNode *pAccNode = tvAccounts->Selected;
    if(!pAccNode) return;
    TTreeNode *pParent = pAccNode;
    for(int i = 0; i < pAccNode->Level; i++)
        pParent = pParent->Parent;
    if(!pParent->Data) return;

    unsigned inx = (pNode->SelectedIndex == 2)? 1 : 2;
    unsigned char curGrants[FORMS_COUNT+1];
    curGrants[FORMS_COUNT] = 0;
    memcpy(curGrants,((UG *)pParent->Data)->Grants,FORMS_COUNT);

    curGrants[(unsigned)pNode->Data] = ((curGrants[(unsigned)pNode->Data] - '0') ^ (1 << pNode->Index)) + '0';
    //curGrants[(unsigned)pNode->Data] += '0';

    __int64 ID = ((UG *)pParent->Data)->ID;

    TDateTime dt;
    dt = dt.CurrentDateTime();

    SQL_iniUpdate(DBName,"Stars",ID);
    SQL_addUpdate("!Grants",(char *)curGrants);
    if(SQL_exeUpdate("EDate",(double)dt) == SQLITE_OK)
    {
        ((UG *)pParent->Data)->Grants[(unsigned)pNode->Data] = ((((UG *)pParent->Data)->Grants[(unsigned)pNode->Data] - '0') ^ (1 << pNode->Index)) + '0';
        pNode->SelectedIndex = inx;
        pNode->ImageIndex = inx;
        (pParent->GetLastChild())->Text = pEDateText + dt;
    }
}
//---------------------------------------------------------------------------
void __fastcall TAccountsForm::tvAccountsChange(TObject *Sender,
      TTreeNode *pAccNode)
{
    TTreeNode *pParent = pAccNode;
    for(int i = 0; i < pAccNode->Level; i++)
        pParent = pParent->Parent;

    if(pParent == pCurNode) return;
    pCurNode = pParent;
    tvGrants->Visible = false;
    tvGrants->Items->Clear();
    TTreeNode *pNode, *pChild;

    if(pParent->ImageIndex == 6)
    for(unsigned i = 0; i < FORMS_COUNT; i++)
    {
        pNode = tvGrants->Items->Add(NULL,AppForms[i]);
        pNode->ImageIndex = 0;
        pNode->SelectedIndex = 0;
        pChild = tvGrants->Items->AddChild(pNode,pCreateText);
        pChild->ImageIndex = 1;
        pChild->SelectedIndex = 1;
        pChild = tvGrants->Items->AddChild(pNode,pChangeText);
        pChild->ImageIndex = 1;
        pChild->SelectedIndex = 1;
        pChild = tvGrants->Items->AddChild(pNode,pReadText);
        pChild->ImageIndex = 1;
        pChild->SelectedIndex = 1;
        pNode->Expanded = true;
    }
    else
    for(unsigned i = 0; i < FORMS_COUNT; i++)
    {
        pNode = tvGrants->Items->Add(NULL,AppForms[i]);
        pNode->ImageIndex = 0;
        pNode->SelectedIndex = 0;
        pChild = tvGrants->Items->AddChild(pNode,pCreateText);
        pChild->ImageIndex = ((((UG *)pParent->Data)->Grants[i]-'0') & 1)? 1 : 2;
        pChild->SelectedIndex = pChild->ImageIndex;
        pChild->Data = (void *)i;
        pChild = tvGrants->Items->AddChild(pNode,pChangeText);
        pChild->ImageIndex = ((((UG *)pParent->Data)->Grants[i]-'0') & 2)? 1 : 2;
        pChild->SelectedIndex = pChild->ImageIndex;
        pChild->Data = (void *)i;
        pChild = tvGrants->Items->AddChild(pNode,pReadText);
        pChild->ImageIndex = ((((UG *)pParent->Data)->Grants[i]-'0') & 4)? 1 : 2;
        pChild->SelectedIndex = pChild->ImageIndex;
        pChild->Data = (void *)i;
        pNode->Expanded = true;
    }

    tvGrants->Visible = true;

    if(pParent->ImageIndex == 6)
    {
        tbDel->ImageIndex = 5;
    }
    else
    {
        if(pParent->ImageIndex == 1) tbDel->ImageIndex = 5;
        else tbDel->ImageIndex = 2;
    }

    __int64 ID = 0;
    if(pParent->Data) ID = ((UG *)pParent->Data)->ID;
    sbAccounts->Panels->Items[0]->Text = "ID: " + (AnsiString)ID;
}
//---------------------------------------------------------------------------
void __fastcall TAccountsForm::edInputExit(TObject *Sender)
{
    edInput->Visible = false;
    edInput->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TAccountsForm::edInputKeyPress(TObject *Sender, char &Key)
{
    if(Key == 13)
    {
        if(pSelectedNode)
        {
            char md5pass[33];

            TTreeNode *pParent = pSelectedNode;
            for(int i = 0; i < pSelectedNode->Level; i++)
                pParent = pParent->Parent;

            __int64 ID = ((UG *)pParent->Data)->ID;

            TDateTime dt;
            dt = dt.CurrentDateTime();

            if(PassChange)
            {
                md5::md5(edInput->Text.c_str(),md5pass);
                SQL_iniUpdate(DBName,"Stars",ID);
                SQL_addUpdate("!Passwd",md5pass);
                if(SQL_exeUpdate("EDate",(double)dt) == SQLITE_OK)
                {
                    pSelectedNode->Text = md5pass;
                    (pParent->GetLastChild())->Text = pEDateText + dt;
                }
                PassChange = false;
                tvAccounts->SetFocus();
            }
            else if(AccChange)
            {
                TTreeNode *pNode = tvAccounts->Items->Item[0];

                if(edInput->Text.Trim().LowerCase() != "admin")
                {
                    while(pNode != NULL)
                    {
                        if(edInput->Text.Trim().LowerCase() == pNode->Text.Trim().LowerCase()) break;
                        pNode = pNode->getNextSibling();
                    }
                }
                if(!pNode)
                {
                    SQL_iniUpdate(DBName,"Stars",ID);
                    SQL_addUpdate("#StarsUser",edInput->Text);
                    if(SQL_exeUpdate("EDate",(double)dt) == SQLITE_OK)
                    {
                        pSelectedNode->Text = edInput->Text;
                        (pParent->GetLastChild())->Text = pEDateText + dt;
                    }
                }
                else
                    Application->MessageBox("Введенное имя не может быть использовано.","");
                AccChange = false;
                tvAccounts->SetFocus();
            }
            else return;
        }
    }
    else if(Key == 27)
    {
        PassChange = false;
        AccChange = false;
        tvAccounts->SetFocus();
    }
}
//---------------------------------------------------------------------------
void __fastcall TAccountsForm::tbEditClick(TObject *Sender)
{
    pSelectedNode = tvAccounts->Selected;

    if(pSelectedNode)
    {
        PassChange = false;
        AccChange = false;

        if(pSelectedNode->ImageIndex == 3)
        {
            TRect rect = pSelectedNode->DisplayRect(true);
            PassChange = true;
            edInput->Text = "";
            edInput->Left = rect.Left + 2;
            edInput->Top = rect.Top + tvAccounts->Top + 1;
            edInput->Width = (rect.Width() > 120)? rect.Width() : 120;
            edInput->Height = rect.Height() + 2;
            edInput->Enabled = true;
            edInput->Visible = true;
            edInput->SetFocus();
        }
        else if(pSelectedNode->ImageIndex == 0 || pSelectedNode->ImageIndex == 1)
        {
            TRect rect = pSelectedNode->DisplayRect(true);
            AccChange = true;
            edInput->Text = pSelectedNode->Text;
            edInput->Left = rect.Left + 2;
            edInput->Top = rect.Top + tvAccounts->Top + 1;
            edInput->Height = rect.Height() + 2;
            edInput->Enabled = true;
            edInput->Visible = true;
            edInput->SetFocus();
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TAccountsForm::tbAddClick(TObject *Sender)
{
    __int64 ID;
    unsigned char curGrants[FORMS_COUNT+1];
    memset(curGrants,'0',FORMS_COUNT);
    curGrants[FORMS_COUNT] = 0;
    int maxlen = strlen(pDefGrants);
    if(maxlen > FORMS_COUNT) maxlen = FORMS_COUNT;
    strncpy(curGrants,pDefGrants,maxlen);


//    unsigned cnt = 0;
    TTreeNode *pNode, *pChild;
//    pNode = tvAccounts->Items->Item[0];
//    while(pNode != NULL)
//    {
//        if(pNode->Text.Pos(pDefUserText)
//        pNode = pNode->getNextSibling();
//    }
    pNode = tvAccounts->Items->Item[0];
    while(pNode != NULL)
    {
        if(pNode->Text.Trim().LowerCase() == pDefUserText) break;
        pNode = pNode->getNextSibling();
    }

    if(pNode)
    {
        Application->MessageBox("Пользователь 'somebody' уже существует.","");
        return;
    }

    TDateTime dt;
    dt = dt.CurrentDateTime();
    
    SQL_iniInsert(DBName,"Stars",&ID);
    SQL_addInsert("!StarsUser",pDefUserText);
    SQL_addInsert("CDate",(double)dt);
    SQL_addInsert("EDate",(double)dt);

    if(SQL_exeInsert("!Grants",(char *)curGrants) == SQLITE_OK)
    {
        pNode = tvAccounts->Items->Add(NULL,pDefUserText);
        pNode->Data = new UG;
        ((UG *)pNode->Data)->ID = ID;
        memcpy(((UG *)pNode->Data)->Grants,curGrants,FORMS_COUNT);
        pNode->ImageIndex = 1;
        pNode->SelectedIndex = 1;
        pChild = tvAccounts->Items->AddChild(pNode,pPasswdText);
        pChild->ImageIndex = 2;
        pChild->SelectedIndex = 2;
        pChild = tvAccounts->Items->AddChild(pChild,"");
        pChild->ImageIndex = 3;
        pChild->SelectedIndex = 3;

        pChild = tvAccounts->Items->AddChild(pNode,pCDateText + dt);
        pChild->ImageIndex = 4;
        pChild->SelectedIndex = 4;
        pChild = tvAccounts->Items->AddChild(pNode,pEDateText + dt);
        pChild->ImageIndex = 5;
        pChild->SelectedIndex = 5;

        pNode->Expanded = true;
        pNode->Selected = true;
        pNode->MakeVisible();
    }
}
//---------------------------------------------------------------------------
void __fastcall TAccountsForm::FormShow(TObject *Sender)
{
    SQL_exe(DBName,"select RowID,StarsUser,Passwd,CDate,EDate,StarsLock,Grants from Stars order by StarsUser,RowID",acc_select);
}
//---------------------------------------------------------------------------
void __fastcall TAccountsForm::tbExpandClick(TObject *Sender)
{
    for(int i = 0; i < tvAccounts->Items->Count; i++)
    {

        if(tvAccounts->Items->Item[i]->Parent == NULL)
            tvAccounts->Items->Item[i]->Expanded = true;
        else
            tvAccounts->Items->Item[i]->Expanded = false;
    }
    tvAccounts->Items->Item[0]->MakeVisible();
}
//---------------------------------------------------------------------------
void __fastcall TAccountsForm::tbCollapseClick(TObject *Sender)
{
    for(int i = 0; i < tvAccounts->Items->Count; i++)
        tvAccounts->Items->Item[i]->Expanded = false;
    tvAccounts->Items->Item[0]->MakeVisible();
}
//---------------------------------------------------------------------------
void __fastcall TAccountsForm::tbDelClick(TObject *Sender)
{
    pSelectedNode = tvAccounts->Selected;

    if(pSelectedNode)
    {
        TTreeNode *pParent = pSelectedNode;
        for(int i = 0; i < pSelectedNode->Level; i++)
            pParent = pParent->Parent;

        if(pParent->Text.LowerCase() == pDefUserText)
        {
            Application->MessageBox("Невозможно изменить статус пользователя 'somebody'.","");
            return;
        }
        if(!pParent->Data) return;
        __int64 ID = ((UG *)pParent->Data)->ID;
        unsigned mode = (pParent->ImageIndex == 1)? 0 : 1;

        TDateTime dt;
        dt = dt.CurrentDateTime();

        SQL_iniUpdate(DBName,"Stars",ID);
        SQL_addUpdate("StarsLock",mode);
        if(SQL_exeUpdate("EDate",(double)dt) == SQLITE_OK)
        {
            pParent->ImageIndex = mode;
            pParent->SelectedIndex = mode;
            if(mode == 1) tbDel->ImageIndex = 5;
            else tbDel->ImageIndex = 2;
            (pParent->GetLastChild())->Text = pEDateText + dt;
            tvAccounts->Refresh();
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TAccountsForm::tvAccountsDeletion(TObject *Sender,
      TTreeNode *Node)
{
    delete Node->Data;
}
//---------------------------------------------------------------------------

