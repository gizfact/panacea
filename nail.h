//---------------------------------------------------------------------------

#ifndef nailH
#define nailH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CSPIN.h"
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TNailForm : public TForm
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
    TLabel *laPrice;
    TLabel *laMins;
    TLabel *Label2;
    TButton *bCancel;
    TComboBox *lbPersonal;
    TButton *bOK;
    TDateTimePicker *dtpBegTime;
    TDateTimePicker *dtpEndTime;
    TEdit *Edit1;
    TCSpinButton *CSpinButton1;
    TCSpinEdit *seGroupCnt;
    TPanel *paBath;
    TSplitter *Splitter1;
    TSplitter *Splitter2;
    TListBox *lbLevel01;
    TListBox *lbLevel02;
    TListBox *lbLevel03;
    TPanel *Panel2;
    TLabel *Label1;
    TRadioButton *RadioButton1;
    TRadioButton *RadioButton2;
    TButton *Button1;
    TButton *Button2;
    TEdit *edColor;
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall lbLevel01Click(TObject *Sender);
    void __fastcall lbLevel02Click(TObject *Sender);
    void __fastcall lbLevel03Click(TObject *Sender);
    void __fastcall bOKClick(TObject *Sender);
    void __fastcall bCancelClick(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall lbLevel01Enter(TObject *Sender);
    void __fastcall lbLevel02Enter(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall edColorKeyPress(TObject *Sender, char &Key);
    void __fastcall seGroupCntChange(TObject *Sender);
    void __fastcall FormPaint(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TNailForm(TComponent* Owner);

    __int64 VisitID;

    double SPABalanse;

    __int64 ResServiceID;
    __int64 ResPersonID;
    TDateTime ResBegDate;
    TDateTime ResEndDate;

    int Timed, AddOp;
    double AddPrice;
    int AddType, AddCount;

    double Price;
    double PersonPrice;

    int Personify;
    AnsiString retString;

    unsigned Level2Counter;
    __int64 *pLevel2IDs;
    AnsiString *pLevel2;

    unsigned ServicesCounter;
    __int64 *pServicesIDs;
    AnsiString *pServices;

    unsigned Services2Counter;
    __int64 *pServices2IDs;
    AnsiString *pServices2;

    unsigned PersonalCounter;
    __int64 *pPersonalIDs;
    AnsiString *pPersonal;

    bool CloseFlag;

    void __fastcall lbServicesUpdate(void);
    void __fastcall lbServices2Update(void);
    void __fastcall lbPersonalUpdate(void);
    void __fastcall laPriceUpdate(void);

    double __fastcall GroupAnalyze(AnsiString group,int cnt);
};
//---------------------------------------------------------------------------
extern PACKAGE TNailForm *NailForm;
//---------------------------------------------------------------------------
#endif
