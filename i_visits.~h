//---------------------------------------------------------------------------

#ifndef i_visitsH
#define i_visitsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TiVisitsForm : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TBevel *Bevel1;
    TLabel *laDate;
    TLabel *laPerson;
    TLabel *laProc;
    TLabel *laBeg;
    TLabel *laEnd;
    TBevel *Bevel2;
    TButton *bCancel;
    TComboBox *lbPersonal;
    TComboBox *lbServices;
    TButton *bOK;
    TDateTimePicker *dtpBegTime;
    TDateTimePicker *dtpEndTime;
    TPanel *paSPA;
    TListBox *lbLevel1;
    TListBox *lbLevel2;
    TSplitter *Splitter1;
    TSplitter *Splitter2;
    TListBox *lbLevel3;
    TLabel *laPrice;
    TLabel *laMins;
    TEdit *edMins;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall bCancelClick(TObject *Sender);
    void __fastcall bOKClick(TObject *Sender);
    void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall lbLevel1Click(TObject *Sender);
    void __fastcall lbLevel2Click(TObject *Sender);
    void __fastcall lbLevel3Click(TObject *Sender);
    void __fastcall dtpEndTimeChange(TObject *Sender);
    void __fastcall dtpBegTimeChange(TObject *Sender);
    void __fastcall edMinsExit(TObject *Sender);
    void __fastcall edMinsKeyPress(TObject *Sender, char &Key);
    void __fastcall FormPaint(TObject *Sender);
    void __fastcall PersonalUpdate(void);
private:	// User declarations
public:		// User declarations
    //AnsiString *pUsers;
    //__int64 *pUserIDs;
    //unsigned UsersCounter;
    double SPABalanse;

    TDateTime ResBegDate;
    TDateTime ResEndDate;

    __int64 ResServiceID;
    __int64 ResPersonID;
    __int64 VisitID;

    __int64 *pPersonalIDs;
    AnsiString *pPersonal;
    unsigned PersonalCounter;
    double PersonPrice;

    __int64 *pServicesIDs;
    AnsiString *pServices;
    //double *pServicesPrice;
    unsigned ServicesCounter;

    int Personify;

    AnsiString Tag;

    double Discount;

    AnsiString retString;

    bool CloseFlag;

    __fastcall TiVisitsForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TiVisitsForm *iVisitsForm;
//---------------------------------------------------------------------------
#endif
