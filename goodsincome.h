//---------------------------------------------------------------------------

#ifndef goodsincomeH
#define goodsincomeH
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
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TGoodsIncomeForm : public TForm
{
__published:	// IDE-managed Components
    TStatusBar *sbGoods;
    TToolBar *ToolBar1;
    TImageList *ilGoodsPrice;
    TStringGrid *sgGoodsIncome;
    TToolButton *ToolButton1;
    TStringGrid *sgGoods;
    TToolButton *ToolButton3;
    TImageList *ImageList1;
    TToolButton *ToolButton5;
    TToolBar *ToolBar2;
    TToolButton *ToolButton7;
    TToolButton *ToolButton6;
    TToolButton *tbClose;
    TImageList *ilDocs;
    TToolButton *ToolButton9;
    TToolButton *ToolButton2;
    TToolButton *tbReload;
    TPanel *Panel3;
    TComboBox *cbSection;
    TLabel *Label2;
    TStringGrid *sgDocs;
    TToolButton *ToolButton4;
    TToolButton *ToolButton8;
    TToolButton *ToolButton10;
    TCheckBox *cbForSale;
    void __fastcall tbExitClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall sgGoodsIncomeSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
    void __fastcall ToolButton1Click(TObject *Sender);
    void __fastcall sgGoodsSelectCell(TObject *Sender, int ACol, int ARow,
          bool &CanSelect);
    void __fastcall sgGoodsEnter(TObject *Sender);
    void __fastcall sgGoodsExit(TObject *Sender);
    void __fastcall sgGoodsDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
    void __fastcall sgGoodsGetEditText(TObject *Sender, int ACol, int ARow,
          AnsiString &Value);
    void __fastcall sgGoodsIncomeDrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State);
    void __fastcall sgGoodsIncomeEnter(TObject *Sender);
    void __fastcall sgGoodsIncomeGetEditText(TObject *Sender, int ACol,
          int ARow, AnsiString &Value);
    void __fastcall ToolButton3Click(TObject *Sender);
    void __fastcall sgGoodsIncomeExit(TObject *Sender);
    void __fastcall ToolButton5Click(TObject *Sender);
    void __fastcall sgDocsDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
    void __fastcall ToolButton9Click(TObject *Sender);
    void __fastcall sgDocsSelectCell(TObject *Sender, int ACol, int ARow,
          bool &CanSelect);
    void __fastcall tbCloseClick(TObject *Sender);
    void __fastcall tbReloadClick(TObject *Sender);
    void __fastcall cbSectionSelect(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall ToolButton4Click(TObject *Sender);
    void __fastcall ToolButton8Click(TObject *Sender);
    void __fastcall ToolButton10Click(TObject *Sender);
    void __fastcall cbForSaleClick(TObject *Sender);
private:	// User declarations
    __int64 *pUserIDs;
    AnsiString *pUsers;
    unsigned UsersCounter;

    bool GoodsFocus;
    bool GoodsIncomeFocus;

    bool GoodsIncomeSave;

    int CurCol, CurRow;
    AnsiString CurCell;

    int GCurCol, GCurRow;
    AnsiString GCurCell;

    const char *fldAlignGoods;
    const char *fldAlignGoodsIncome;
    const char *fldAlignDocs;

    int *DocsWidths;
    int *GoodsIncomeWidths;
    int *GoodsWidths;

    TWndMethod sgODocsWindowProc;
    TWndMethod sgOGoodsIncomeWindowProc;
    TWndMethod sgOGoodsWindowProc;

    void __fastcall sgDocsWindowProc(Messages::TMessage& Msg);
    void __fastcall sgGoodsIncomeWindowProc(Messages::TMessage& Msg);
    void __fastcall sgGoodsWindowProc(Messages::TMessage& Msg);

public:		// User declarations
    __int64 DocID;

     __int64 *pIDs, *ppGIDs;
     unsigned GoodsIncomeCount;

     __int64 *pGIDs;
     unsigned GoodsCount;

     __int64 *IDsDocs;
     unsigned DocsCount;

    __fastcall TGoodsIncomeForm(TComponent* Owner);

    //void __fastcall FullUpdate(void);
    void __fastcall UpdateGoodsIncome(__int64 ID);
    void __fastcall UpdateGoods(void);
    void __fastcall FullUpdate(void);
    void __fastcall UpdateStatus(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TGoodsIncomeForm *GoodsIncomeForm;
//---------------------------------------------------------------------------
#endif
