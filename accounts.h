//---------------------------------------------------------------------------
#ifndef accountsH
#define accountsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include <ToolWin.hpp>

#include "md5.h"
#include "sqlite3.h"
#include "lib.h"

#define FORMS_COUNT     19
//---------------------------------------------------------------------------
class TAccountsForm : public TForm
{
__published:	// IDE-managed Components
    TTreeView *tvAccounts;
    TSplitter *Splitter1;
    TTreeView *tvGrants;
    TImageList *ilGrants;
    TStatusBar *sbAccounts;
    TImageList *ilAccounts;
    TEdit *edInput;
    TToolBar *tbAccounts;
    TToolButton *tbAdd;
    TToolButton *tbEdit;
    TImageList *ilTools;
    TToolButton *tbDel;
    TToolButton *tbExpand;
    TToolButton *tbCollapse;
    void __fastcall tvGrantsDblClick(TObject *Sender);
    void __fastcall tvAccountsChange(TObject *Sender, TTreeNode *Node);
    void __fastcall edInputExit(TObject *Sender);
    void __fastcall edInputKeyPress(TObject *Sender, char &Key);
    void __fastcall tbEditClick(TObject *Sender);
    void __fastcall tbAddClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall tbExpandClick(TObject *Sender);
    void __fastcall tbCollapseClick(TObject *Sender);
    void __fastcall tbDelClick(TObject *Sender);
    void __fastcall tvAccountsDeletion(TObject *Sender, TTreeNode *Node);
private:	// User declarations
public:		// User declarations
    __fastcall TAccountsForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAccountsForm *AccountsForm;
//---------------------------------------------------------------------------
#endif
