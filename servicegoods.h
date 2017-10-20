//---------------------------------------------------------------------------
#ifndef servicegoodsH
#define servicegoodsH
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
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TServiceGoodsForm : public TForm
{
__published:	// IDE-managed Components
    TStatusBar *sbServiceGoods;
    TImageList *ilGoodsPrice;
    TImageList *ImageList1;
    TToolBar *ToolBar2;
    TToolButton *ToolButton7;
    TPanel *Panel3;
    TLabel *Label2;
    TComboBox *cbSection;
    TStringGrid *sgServices;
    TStringGrid *sgServiceGoods;
    TToolBar *ToolBar1;
    TToolButton *ToolButton5;
    TToolButton *ToolButton1;
    TStringGrid *sgGoods;
    TLabel *Label1;
    TComboBox *cbService1;
    TLabel *laService2;
    TComboBox *cbService2;
    TToolButton *ToolButton2;
    TEdit *edInput;
    TSplitter *Splitter1;
    TSplitter *Splitter2;
    TComboBox *cbService0;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall sgServicesDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
    void __fastcall sgServiceGoodsDrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State);
    void __fastcall sgGoodsDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
    void __fastcall ToolButton7Click(TObject *Sender);
    void __fastcall cbSectionSelect(TObject *Sender);
    void __fastcall sgGoodsMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall ToolButton2Click(TObject *Sender);
    void __fastcall ToolButton5Click(TObject *Sender);
    void __fastcall sgServicesSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
    void __fastcall edInputExit(TObject *Sender);
    void __fastcall edInputKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall sgServiceGoodsDblClick(TObject *Sender);
    void __fastcall edInputKeyPress(TObject *Sender, char &Key);
    void __fastcall sgServicesDblClick(TObject *Sender);
    void __fastcall ToolButton1Click(TObject *Sender);
    void __fastcall cbService0Select(TObject *Sender);
    void __fastcall cbService1Select(TObject *Sender);
    void __fastcall cbService2Select(TObject *Sender);
private:	// User declarations
    int edInputCol;
    int edInputMode;

    int *ServicesWidths;
    int *ServiceGoodsWidths;
    int *GoodsWidths;

    const char *fldAlignServices;
    const char *fldAlignServiceGoods;
    const char *fldAlignGoods;

    //__int64 ServiceID;

    TWndMethod sgOServicesWindowProc;
    TWndMethod sgOServiceGoodsWindowProc;
    TWndMethod sgOGoodsWindowProc;

    void __fastcall sgServicesWindowProc(Messages::TMessage& Msg);
    void __fastcall sgServiceGoodsWindowProc(Messages::TMessage& Msg);
    void __fastcall sgGoodsWindowProc(Messages::TMessage& Msg);

    void __fastcall FullUpdate(__int64 SID = 0,__int64 SGID = 0);
    void __fastcall UpdateServiceGoods(__int64 SGID = 0);
    void __fastcall UpdateGoods(void);

    void __fastcall Service0Update(void);
    void __fastcall Service1Update(void);
    void __fastcall Service2Update(void);

public:		// User declarations
    __int64 *IDsServices;
    unsigned ServicesCount;

    __int64 *IDsServiceGoods;
    unsigned ServiceGoodsCount;

    __int64 *IDsGoods;
    unsigned GoodsCount;

    __fastcall TServiceGoodsForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TServiceGoodsForm *ServiceGoodsForm;
//---------------------------------------------------------------------------
#endif
