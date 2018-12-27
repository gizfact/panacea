//---------------------------------------------------------------------------

#ifndef abtypesH
#define abtypesH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TAbTypesForm : public TForm
{
__published:	// IDE-managed Components
    TStatusBar *sbAbTypes;
    TToolBar *tbClients;
    TToolButton *ToolButton2;
    TToolButton *tbNew;
    TToolButton *tbEdit;
    TToolButton *tbHome;
    TToolButton *ToolButton5;
    TToolButton *tbExit;
    TToolButton *ToolButton1;
    TPanel *Panel1;
    TStringGrid *sgAbTypes;
    TImageList *ilBtnAbTypes;
    TImageList *ilAbTypes;
    TImageList *ImageList1;
    TToolButton *ToolButton3;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall sgAbTypesDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
    void __fastcall tbNewClick(TObject *Sender);
    void __fastcall tbExitClick(TObject *Sender);
    void __fastcall tbEditClick(TObject *Sender);
    void __fastcall sgAbTypesSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
    void __fastcall sgAbTypesDblClick(TObject *Sender);
    void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall sgAbTypesKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall ToolButton3Click(TObject *Sender);
private:	// User declarations


    int StartW, StartH;
    int DefW, DefH;

    int *AbTypesWidths;
    //, DefL, DefT;
public:		// User declarations
    char *fldAlign;

    __fastcall TAbTypesForm(TComponent* Owner);
    void __fastcall sgAbTypesWindowProc(Messages::TMessage& Msg);
    //void __fastcall sgWindowProc(Messages::TMessage& Msg);
    void __fastcall sgAbTypesRowInfo(__int64 *pID, unsigned cnt);
    void __fastcall sgAbTypesRowUpdate(__int64 *pID, unsigned cnt);
    void __fastcall sgAbTypesFullUpdate(void);
    void __fastcall sgAbTypesNew(void);
    void __fastcall sgAbTypesEdit(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TAbTypesForm *AbTypesForm;
//---------------------------------------------------------------------------
#endif
