//---------------------------------------------------------------------------

#ifndef discountsH
#define discountsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <ToolWin.hpp>
#include <Grids.hpp>
#include <ImgList.hpp>
//---------------------------------------------------------------------------
class TDiscountsForm : public TForm
{
__published:	// IDE-managed Components
    TStatusBar *sbDiscounts;
    TToolBar *tbClients;
    TToolButton *ToolButton2;
    TToolButton *tbAdd;
    TToolButton *tbEdit;
    TToolButton *tbHome;
    TToolButton *tbExit;
    TToolButton *ToolButton1;
    TToolButton *tbPrint;
    TToolButton *ToolButton3;
    TPanel *Panel1;
    TStringGrid *sgDiscounts;
    TImageList *ilBtnDiscounts;
    TImageList *ilDiscounts;
    TToolButton *ToolButton5;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall sgDiscountsDrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State);
    void __fastcall tbExitClick(TObject *Sender);
    void __fastcall tbHomeClick(TObject *Sender);
    void __fastcall tbAddClick(TObject *Sender);
    void __fastcall tbEditClick(TObject *Sender);
    void __fastcall sgDiscountsKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall sgDiscountsSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
private:	// User declarations
public:		// User declarations
    __fastcall TDiscountsForm(TComponent* Owner);
    void __fastcall sgWindowProc(Messages::TMessage& Msg);
    void __fastcall sgDiscountsRowUpdate(__int64 *pID, unsigned cnt);
    void __fastcall sgDiscountsFullUpdate(void);
    void __fastcall sgDiscountsRowInfo(__int64 *pID, unsigned cnt);
};
//---------------------------------------------------------------------------
extern PACKAGE TDiscountsForm *DiscountsForm;
//---------------------------------------------------------------------------
#endif
