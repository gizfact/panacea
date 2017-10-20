//---------------------------------------------------------------------------

#ifndef sellsH
#define sellsH
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
//---------------------------------------------------------------------------
class TSellsForm : public TForm
{
__published:	// IDE-managed Components
    TStatusBar *sbSells;
    TToolBar *tbClients;
    TToolButton *tbExit;
    TPanel *Panel1;
    TComboBox *cbChoice;
    TStringGrid *sgSells;
    TImageList *ilBtnVisits;
    TImageList *ilBtnHotVisits;
    TDateTimePicker *dtpBegDate;
    TEdit *edFilter;
    TDateTimePicker *dtpEndDate;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall sgSellsDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
    void __fastcall tbExitClick(TObject *Sender);
    void __fastcall dtpBegDateCloseUp(TObject *Sender);
    void __fastcall edFilterKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall dtpEndDateCloseUp(TObject *Sender);
private:	// User declarations
    int *SellsWidths;
    const char *fldAlignSells;
    TWndMethod sgOSellsWindowProc;

    void __fastcall sgSellsWindowProc(Messages::TMessage& Msg);
public:		// User declarations
    int TotalCount;
    int sgCounter;
    double TotalSum;

    __fastcall TSellsForm(TComponent* Owner);
    void __fastcall TSellsForm::sgSellsFullUpdate(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TSellsForm *SellsForm;
//---------------------------------------------------------------------------
#endif
