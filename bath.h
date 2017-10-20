//---------------------------------------------------------------------------

#ifndef bathH
#define bathH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include "CSPIN.h"
//---------------------------------------------------------------------------
class TBathForm : public TForm
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
    TButton *bCancel;
    TComboBox *lbPersonal;
    TButton *bOK;
    TDateTimePicker *dtpBegTime;
    TDateTimePicker *dtpEndTime;
    TEdit *Edit1;
    TCSpinButton *CSpinButton1;
    TCSpinEdit *seGroupCnt;
    TLabel *Label2;
    TPanel *paBath;
    TSplitter *Splitter1;
    TSplitter *Splitter2;
    TListBox *lbLevel01;
    TListBox *lbLevel02;
    TListBox *lbLevel03;
    void __fastcall bCancelClick(TObject *Sender);
    void __fastcall edMinsKeyPress(TObject *Sender, char &Key);
    void __fastcall dtpBegTimeChange(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall bOKClick(TObject *Sender);
    void __fastcall CSpinButton1DownClick(TObject *Sender);
    void __fastcall CSpinButton1UpClick(TObject *Sender);
    void __fastcall seGroupCntChange(TObject *Sender);
    void __fastcall lbLevel01Click(TObject *Sender);
    void __fastcall lbLevel02Click(TObject *Sender);
    void __fastcall lbLevel03Click(TObject *Sender);
    void __fastcall FormPaint(TObject *Sender);
private:	// User declarations
public:		// User declarations
    //__int64 *pUserIDs;
    //AnsiString *pUsers;
    //unsigned UsersCounter;
    //bool LymphoRu, LymphoHa;
    __int64 VisitID;

    double SPABalanse;

    TDateTime ResBegDate;
    TDateTime ResEndDate;

    int ResQuan;

    __int64 ResServiceID;
    __int64 ResPersonID;

    int Timed;

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

    __fastcall TBathForm(TComponent* Owner);
    void __fastcall lbServicesUpdate(void);
    void __fastcall lbServices2Update(void);
    void __fastcall lbPersonalUpdate(void);
    void __fastcall laPriceUpdate(void);

    //double __fastcall GroupAnalyze(AnsiString group,int cnt);
};
//---------------------------------------------------------------------------
extern PACKAGE TBathForm *BathForm;
//---------------------------------------------------------------------------
#endif
