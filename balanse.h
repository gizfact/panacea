//---------------------------------------------------------------------------

#ifndef balanseH
#define balanseH
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
class TBalanseForm : public TForm
{
__published:	// IDE-managed Components
    TStatusBar *sbBalanse;
    TToolBar *tbClients;
    TToolButton *tbExit;
    TPanel *Panel1;
    TStringGrid *sgBalanse;
    TImageList *ilBtnBalanse;
    TImageList *ilBtnHotBalanse;
    TDateTimePicker *dtpBalanse;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall sgBalanseDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
    void __fastcall dtpBalanseChange(TObject *Sender);
    void __fastcall tbExitClick(TObject *Sender);
    void __fastcall sgBalanseSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
private:	// User declarations
    const char *fldAlign;
    int *BalanseWidths;
    unsigned UsersCounter;

    __int64 *pUserIDs;
    AnsiString *pUsers;



    TWndMethod sgOBalanseWindowProc;

    void __fastcall sgBalanseWindowProc(Messages::TMessage& Msg);

public:		// User declarations
    __int64 CUID, EUID;
    TDateTime CDate, EDate;

    DynamicArray<__int64> IDs;

    unsigned BalanseCounter;

    __fastcall TBalanseForm(TComponent* Owner);

    void __fastcall sgBalanseFullUpdate(void);
    void __fastcall sgBalanseUI(int);
    __int64 ClientID;
};
//---------------------------------------------------------------------------
extern PACKAGE TBalanseForm *BalanseForm;
//---------------------------------------------------------------------------
#endif
