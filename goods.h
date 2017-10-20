//---------------------------------------------------------------------------
#ifndef goodsH
#define goodsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TGoodsForm : public TForm
{
__published:	// IDE-managed Components
    TToolBar *tbGoods;
    TToolButton *tbExit;
    TStatusBar *sbGoods;
    TImageList *ilGoods;
    TStringGrid *sgGoods;
    TPanel *Panel1;
    TLabel *Label2;
    TComboBox *cbSection;
    TImageList *ImageList1;
    void __fastcall tbExitClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall sgGoodsDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
    void __fastcall cbSectionSelect(TObject *Sender);
    void __fastcall sgGoodsDblClick(TObject *Sender);
private:	// User declarations
    int *GoodsWidths;
    const char *fldAlignGoods;
    TWndMethod sgOGoodsWindowProc;

    void __fastcall sgGoodsWindowProc(Messages::TMessage& Msg);

public:		// User declarations
    bool KassaMode;

     __int64 *pIDs;
     unsigned GoodsCount;

     __int64 SelID;
     AnsiString SelName;
     double SelPrice;
     int SelCount;
     AnsiString SelSection;

    __fastcall TGoodsForm(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TGoodsForm *GoodsForm;
//---------------------------------------------------------------------------
#endif
