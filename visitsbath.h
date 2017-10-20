//---------------------------------------------------------------------------
#ifndef visitsbathH
#define visitsbathH
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
class TVisitsBathForm : public TForm
{
__published:	// IDE-managed Components
    TStatusBar *sbVisits;
    TToolBar *tbClients;
    TToolButton *tbExit;
    TToolButton *tbDel;
    TPanel *Panel1;
    TStringGrid *sgVisits;
    TImageList *ilBtnVisits;
    TImageList *ilBtnHotVisits;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall sgVisitsDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
    void __fastcall tbExitClick(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
    int *VisitsWidths;
    const char *fldAlignVisits;
public:		// User declarations
    __fastcall TVisitsBathForm(TComponent* Owner);

    bool AbsModified;

    DynamicArray<__int64> IDs;
    unsigned Counter;

    AnsiString *pUsers;
    __int64 *pUserIDs;
    unsigned UsersCounter;

    //TDateTime CDate, EDate;
    //__int64 CUID, EUID, PersonID;
    AnsiString retString;
    TWndMethod sgOVisitsWindowProc;

  

    void __fastcall sgVisitsWindowProc(Messages::TMessage& Msg);

    void __fastcall sgVisitsFullUpdate(void);
    void __fastcall sgVisitsRowInfo(DynamicArray<__int64> pID, unsigned cnt);
};
//---------------------------------------------------------------------------
extern PACKAGE TVisitsBathForm *VisitsBathForm;
//---------------------------------------------------------------------------
#endif
