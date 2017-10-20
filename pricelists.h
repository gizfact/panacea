//---------------------------------------------------------------------------

#ifndef pricelistsH
#define pricelistsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TPriceListsForm : public TForm
{
__published:	// IDE-managed Components
    TStringGrid *sgPriceLists;
    TToolBar *ToolBar1;
    TToolButton *tbNew;
    TToolButton *tbEdit;
    TToolButton *tbSave;
    TImageList *ilPriceLists;
    TStatusBar *sbPriceLists;
    TEdit *edInput;
    TToolButton *ToolButton1;
    TToolButton *ToolButton2;
    TToolButton *ToolButton3;
    TToolButton *ToolButton4;
    TPanel *Panel1;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall sgPriceListsSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
    void __fastcall sgPriceListsDrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State);
    void __fastcall sgPriceListsDblClick(TObject *Sender);
    void __fastcall edInputExit(TObject *Sender);
    void __fastcall tbSaveClick(TObject *Sender);
    void __fastcall tbNewClick(TObject *Sender);
    void __fastcall ToolButton3Click(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall edInputKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall sgPriceListsKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
    __fastcall TPriceListsForm(TComponent* Owner);
    void __fastcall sgPriceListsFullUpdate(void);
    void __fastcall sgPriceListsRowInfo(__int64 *pID, unsigned cnt);
    void __fastcall sgWindowProc(Messages::TMessage& Msg);
};
//---------------------------------------------------------------------------
extern PACKAGE TPriceListsForm *PriceListsForm;
//---------------------------------------------------------------------------
#endif
