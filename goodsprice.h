//---------------------------------------------------------------------------

#ifndef goodspriceH
#define goodspriceH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ToolWin.hpp>
#include <Grids.hpp>
#include <ImgList.hpp>
//---------------------------------------------------------------------------
class TGoodsPriceForm : public TForm
{
__published:	// IDE-managed Components
    TStatusBar *sbGoodsPrice;
    TToolBar *ToolBar1;
    TToolButton *tbD1;
    TToolButton *tbEdit;
    TToolButton *tbSave;
    TToolButton *ToolButton2;
    TToolButton *tbExit;
    TToolButton *ToolButton4;
    TImageList *ilGoodsPrice;
    void __fastcall tbExitClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TGoodsPriceForm(TComponent* Owner);
  
};
//---------------------------------------------------------------------------
extern PACKAGE TGoodsPriceForm *GoodsPriceForm;
//---------------------------------------------------------------------------
#endif
