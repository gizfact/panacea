//---------------------------------------------------------------------------
#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <ToolWin.hpp>
#include <IniFiles.hpp>
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
    TStatusBar *sbMain;
    TMainMenu *mmMain;
    TMenuItem *mmnProgram;
    TToolBar *tbMain;
    TMenuItem *mmnAdmin;
    TMenuItem *mmnUserlist;
    TMenuItem *mmnExit;
    TMenuItem *mmnService;
    TMenuItem *mmnClient;
    TMenuItem *mmnRefbook;
    TMenuItem *mmnPersonal;
    TMenuItem *mmnAbType;
    TMenuItem *mmnReport;
    TMenuItem *mmnRepBalanse;
    TMenuItem *mmnServices;
    TMenuItem *mmnSettings;
    TProgressBar *pbProgress;
    TMenuItem *mmnRepNegBalanse;
    TMenuItem *mmnRepVisits;
    TMenuItem *DelClients1;
    TMenuItem *mmnGoodsList;
    TMenuItem *mmnGoodsInput;
    TMenuItem *mmnGoods;
    TMenuItem *mmnRepFitness;
    TMenuItem *mmnRepSPA;
    TMenuItem *mmnRepVisitsSPA;
    TMenuItem *UpdateAllTags1;
    TMenuItem *mmnRepAbsSPA;
    TMenuItem *N1;
    TMenuItem *mmnPurchase;
    TMenuItem *N3;
    TMenuItem *N2;
    TMenuItem *mmnRepSells;
    TMenuItem *mmnServiceGoods;
    TMenuItem *N4;
    TMenuItem *N5;
    TMenuItem *N6;
    TMenuItem *N7;
    TMenuItem *mmnVersion;
    TMenuItem *N9;
    TMenuItem *N21;
    TMenuItem *PPrice1;
    TMenuItem *VisitsSPA1;
    TMenuItem *ClientsExport1;
    TMenuItem *Export1;
    TMenuItem *N11;
    TMenuItem *N12;
    TMenuItem *N13;
    TMenuItem *N14;
    TMenuItem *N15;
    TMenuItem *N16;
    TMenuItem *N17;
    TMenuItem *CorrectSIDs1;
    TMenuItem *N18;
    TMenuItem *StockRecalc1;
    TMenuItem *mmnCalendar;
    TMenuItem *mmnFitGroup;
    TTimer *tiReserve;
    TMenuItem *txt1;
    TMenuItem *N8;
    TMenuItem *N10;
    TMenuItem *ReserveFitGroupExport1;
    TTimer *tiSync;
    TLabel *laSyncEnd;
    TMenuItem *Income2;
    TMenuItem *N19;
    TMenuItem *mmnRepWorkDay;
    TMenuItem *mmnBalCheck;
    TMenuItem *N20;
    TMenuItem *N22;
    TMenuItem *N23;
    TMenuItem *N24;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall mmnUserlistClick(TObject *Sender);
    void __fastcall mmnExitClick(TObject *Sender);
    void __fastcall mmnClientClick(TObject *Sender);
    void __fastcall mmnServicesClick(TObject *Sender);
    void __fastcall mmnSettingsClick(TObject *Sender);
    void __fastcall mmnAbTypeClick(TObject *Sender);
    void __fastcall mmnPersonalClick(TObject *Sender);
    void __fastcall mmnRepBalanseClick(TObject *Sender);
    void __fastcall mmnRepNegBalanseClick(TObject *Sender);
    void __fastcall mmnRepVisitsClick(TObject *Sender);
    void __fastcall DelClients1Click(TObject *Sender);
    void __fastcall mmnGoodsListClick(TObject *Sender);
    void __fastcall mmnGoodsInputClick(TObject *Sender);
    void __fastcall mmnRepVisitsSPAClick(TObject *Sender);
    void __fastcall UpdateAllTags1Click(TObject *Sender);
    void __fastcall mmnRepAbsSPAClick(TObject *Sender);
    void __fastcall mmnPurchaseClick(TObject *Sender);
    void __fastcall N5Click(TObject *Sender);
    void __fastcall N7Click(TObject *Sender);
    void __fastcall mmnVersionClick(TObject *Sender);
    void __fastcall N21Click(TObject *Sender);
    void __fastcall PPrice1Click(TObject *Sender);
    void __fastcall VisitsSPA1Click(TObject *Sender);
    void __fastcall ClientsExport1Click(TObject *Sender);
    void __fastcall Export1Click(TObject *Sender);
    void __fastcall N11Click(TObject *Sender);
    void __fastcall N13Click(TObject *Sender);
    void __fastcall N14Click(TObject *Sender);
    void __fastcall N16Click(TObject *Sender);
    void __fastcall N17Click(TObject *Sender);
    void __fastcall CorrectSIDs1Click(TObject *Sender);
    void __fastcall N18Click(TObject *Sender);
    void __fastcall StockRecalc1Click(TObject *Sender);
    void __fastcall mmnCalendarClick(TObject *Sender);
    void __fastcall mmnFitGroupClick(TObject *Sender);
    void __fastcall tiReserveTimer(TObject *Sender);
    void __fastcall txt1Click(TObject *Sender);
    void __fastcall N10Click(TObject *Sender);
    void __fastcall ReserveFitGroupExport1Click(TObject *Sender);
    void __fastcall tiSyncTimer(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall mmnServiceGoodsClick(TObject *Sender);
    void __fastcall N4Click(TObject *Sender);
    void __fastcall Income2Click(TObject *Sender);
    void __fastcall mmnRepSellsClick(TObject *Sender);
    void __fastcall mmnRepWorkDayClick(TObject *Sender);
    void __fastcall mmnBalCheckClick(TObject *Sender);
    void __fastcall N20Click(TObject *Sender);
    void __fastcall N22Click(TObject *Sender);
    void __fastcall N23Click(TObject *Sender);
    void __fastcall N24Click(TObject *Sender);
private:	    // User declarations
    //__int64 PurchaseID;
    AnsiString __fastcall repCreated(bool);
    void __fastcall BaseConvert(void);

    bool __fastcall TableExport(const char *pFileName,const char *pTable,const char **pFNames,char *pFMasks,unsigned fcnt,const char *pFrom);
    void __fastcall AllExport(void);

    void __fastcall PersonalExport(void);
    void __fastcall ClientsExport(void);
    void __fastcall ServicesExport(void);

    void __fastcall ArchExport(void);

public:		    // User declarations
    //AnsiString ConString;

    __int64 *IDs;
    unsigned Counter;

    __int64 CurrentID;
    AnsiString retString;
    unsigned ImportLines;

    double SessionKey;

    __int64 *repClientsIDs;

    int *repDates;
    bool repShowDate;
 
    AnsiString *repClientsFNames;
    AnsiString *repClientsSNames;
    AnsiString *repClientsTNames;
    AnsiString *repClientsBegBalanse;
    AnsiString *repClientsToBalanse;
    AnsiString *repClientsToBalanseBN;
    AnsiString *repClientsFromBalanse;
    AnsiString *repClientsEndBalanse;
    double repBegBalanseSum;
    double repFromBalanseSum;
    double repToBalanseSum;
    double repToBalanseBNSum;

    double repEndBalanseSum;
    unsigned repBillsCounter;
    unsigned repClientsCounter;

    __fastcall TMainForm(TComponent* Owner);

    void __fastcall UpdateBranchTags(__int64,AnsiString);
    void __fastcall UpdateAllTags(void);

    void __fastcall AbonementsSPAFullUpdate(void);

    //double __fastcall GroupAnalyze(AnsiString group,int cnt);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
