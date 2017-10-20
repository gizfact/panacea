//---------------------------------------------------------------------------

#ifndef visitsH
#define visitsH
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
class TVisitsForm : public TForm
{
__published:	// IDE-managed Components
    TStatusBar *sbVisits;
    TToolBar *tbClients;
    TToolButton *tbExit;
    TPanel *Panel1;
    TStringGrid *sgVisits;
    TImageList *ilBtnVisits;
    TImageList *ilBtnHotVisits;
    TComboBox *cbChoice;
    TToolButton *tbDel;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall sgVisitsDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
    void __fastcall tbExitClick(TObject *Sender);
    void __fastcall sgVisitsSelectCell(TObject *Sender, int ACol, int ARow,
          bool &CanSelect);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall cbChoiceSelect(TObject *Sender);
    void __fastcall tbDelClick(TObject *Sender);
private:	// User declarations
    int *VisitsWidths;
    const char *fldAlignVisits;
public:		// User declarations
    bool AbsModified;

    DynamicArray<__int64> IDs;
    unsigned Counter;

    AnsiString *pUsers;
    __int64 *pUserIDs;
    unsigned UsersCounter;

    TDateTime CDate, EDate;
    __int64 CUID, EUID, PersonID;
    AnsiString retString;
    TWndMethod sgOVisitsWindowProc;

    __fastcall TVisitsForm(TComponent* Owner);

    void __fastcall sgVisitsWindowProc(Messages::TMessage& Msg);

    void __fastcall sgVisitsFullUpdate(void);
    void __fastcall sgVisitsRowInfo(DynamicArray<__int64> pID, unsigned cnt);
};
//---------------------------------------------------------------------------
extern PACKAGE TVisitsForm *VisitsForm;
//---------------------------------------------------------------------------
#endif
