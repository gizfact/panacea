//---------------------------------------------------------------------------
#ifndef calendarH
#define calendarH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------
class TCalendarForm : public TForm
{
__published:	// IDE-managed Components
    TToolBar *tbClients;
    TToolButton *tbExit;
    TImageList *ilBtnVisits;
    TImageList *ilBtnHotVisits;
    TScrollBox *ScrollBox1;
    TPanel *Panel1;
    TComboBox *cbServices;
    TSpeedButton *sbLeft;
    TSpeedButton *sbRight;
    TPanel *paPeriod;
    void __fastcall tbExitClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall cbServicesChange(TObject *Sender);
    void __fastcall sbLeftClick(TObject *Sender);
    void __fastcall sbRightClick(TObject *Sender);
private:	// User declarations
   

    void __fastcall PanClick(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
public:		// User declarations
    //__int64 *pServiceIDs;

    int **pDays;
    unsigned DaysCount;
    int **pPersons;
    __int64 *pPersonIDs;
    AnsiString *pPersonNames;
    unsigned PersonCount;
    int **pHeaders;
    TDateTime CurrentFDay;

    __fastcall TCalendarForm(TComponent* Owner);
   void __fastcall FullUpdate(void);
   void __fastcall ClearCalendar(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TCalendarForm *CalendarForm;
//---------------------------------------------------------------------------
#endif
