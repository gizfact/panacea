//---------------------------------------------------------------------------

#ifndef rescontrolH
#define rescontrolH
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
class TResControlForm : public TForm
{
__published:	// IDE-managed Components
    TToolBar *tbClients;
    TToolButton *tbExit;
    TPanel *Panel1;
    TStringGrid *sgResControl;
    TImageList *ilBtnVisits;
    TImageList *ilBtnHotVisits;
    TDateTimePicker *dtpBegDate;
    TDateTimePicker *dtpEndDate;
    TEdit *edFilter;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall sgResControlDrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State);
    void __fastcall tbExitClick(TObject *Sender);
    void __fastcall dtpBegDateCloseUp(TObject *Sender);
    void __fastcall dtpEndDateCloseUp(TObject *Sender);
    void __fastcall edFilterKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations

    int *ResControlWidths;
    const char *fldAlignResControl;

    TWndMethod sgOResControlWindowProc;

    void __fastcall sgResControlWindowProc(Messages::TMessage& Msg);

    void __fastcall sgResControlFullUpdate(void);
public:		// User declarations


    __fastcall TResControlForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TResControlForm *ResControlForm;
//---------------------------------------------------------------------------
#endif
