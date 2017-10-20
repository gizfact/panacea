//---------------------------------------------------------------------------

#ifndef servicesH
#define servicesH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
class TServicesForm : public TForm
{
__published:	// IDE-managed Components
    TTreeView *tvServices;
    TToolBar *ToolBar1;
    TToolButton *tbD1;
    TToolButton *tbNew;
    TToolButton *tbEdit;
    TToolButton *tbSave;
    TToolButton *tbD2;
    TToolButton *tbExit;
    TToolButton *tbD3;
    TImageList *ilServices;
    TEdit *edInput;
    TStatusBar *sbServices;
    TTreeView *tvLayer;
    TPanel *Panel1;
    TToolButton *tbToPan;
    TPopupMenu *pmService;
    TMenuItem *N1;
    TMenuItem *N501;
    TMenuItem *N502;
    TMenuItem *N1001;
    TMenuItem *N1002;
    TMenuItem *N2;
    TMenuItem *N3;
    TMenuItem *N4;
    TMenuItem *N5;
    TMenuItem *N6;
    TMenuItem *miSpec;
    TMenuItem *N8;
    TMenuItem *N9;
    TMenuItem *N10;
    TMenuItem *N7;
    TMenuItem *N11;
    TMenuItem *N12;
    TMenuItem *N5001;
    TMenuItem *N5002;
    void __fastcall tbNewClick(TObject *Sender);
    void __fastcall edInputExit(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall tvServicesDblClick(TObject *Sender);
    void __fastcall tvServicesChange(TObject *Sender, TTreeNode *Node);
    void __fastcall tbExitClick(TObject *Sender);
    void __fastcall tbSaveClick(TObject *Sender);
    void __fastcall tbToPanClick(TObject *Sender);
    void __fastcall tvServicesDeletion(TObject *Sender, TTreeNode *Node);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall edInputKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall tvServicesKeyPress(TObject *Sender, char &Key);
    void __fastcall edInputEnter(TObject *Sender);
    void __fastcall tvServicesMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
  
private:	// User declarations
void __fastcall PopupMenuItemsClick(TObject *Sender);
public:		// User declarations
    __fastcall TServicesForm(TComponent* Owner);
    void __fastcall sgServicesRowInfo(__int64 *pID, unsigned cnt);
    void __fastcall tvWindowProc(Messages::TMessage& Msg);

    void __fastcall UpdateBranchTags(__int64,AnsiString);
    void __fastcall recUpdateBranchTags(__int64,AnsiString);
};
//---------------------------------------------------------------------------
extern PACKAGE TServicesForm *ServicesForm;
//---------------------------------------------------------------------------
#endif
