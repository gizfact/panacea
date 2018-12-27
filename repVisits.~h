//---------------------------------------------------------------------------

#ifndef repVisitsH
#define repVisitsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QRCtrls.hpp>
#include <QuickRpt.hpp>
//---------------------------------------------------------------------------
class TrepVisitsForm : public TForm
{
__published:	// IDE-managed Components
    TQuickRep *QuickRep1;
    TQRStringsBand *QRlines;
    TQRExpr *QRClient;
    TQRExpr *QRVisit;
    TQRExpr *QRAbonement;
    TQRExpr *QRCoach;
    TQRBand *QRBand1;
    TQRBand *QRBand2;
    TQRExpr *QRPage;
    TQRLabel *QRCreated;
    TQRBand *QRBand3;
    TQRLabel *QRHeader;
    TQRChildBand *QRChildBand1;
    TQRLabel *QRLabel1;
    TQRLabel *QRLabel2;
    TQRLabel *QRLabel3;
    TQRLabel *QRLabel4;
    TQRBand *QRBand4;
    TQRLabel *QRLabel8;
    TQRExpr *QRVisitSum;
    TQRExpr *QRAbonementSum;
    void __fastcall QRPagePrint(TObject *sender, AnsiString &Value);
    void __fastcall QRlinesBeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
    void __fastcall QRVisitSumPrint(TObject *sender, AnsiString &Value);
    void __fastcall QRAbonementSumPrint(TObject *sender,
          AnsiString &Value);
    void __fastcall QuickRep1BeforePrint(TCustomQuickRep *Sender,
          bool &PrintReport);
    void __fastcall QRCoachPrint(TObject *sender, AnsiString &Value);
    void __fastcall QRVisitPrint(TObject *sender, AnsiString &Value);
    void __fastcall QRAbonementPrint(TObject *sender, AnsiString &Value);
    void __fastcall QRClientPrint(TObject *sender, AnsiString &Value);
private:	// User declarations
public:		// User declarations
    __fastcall TrepVisitsForm(TComponent* Owner);

    double VisitsSum, AbonementsSum, VisitsSumTotal, AbonementsSumTotal;
    unsigned VisitsCnt, AbonementsCnt, VisitsCntTotal, AbonementsCntTotal;
    
    bool fCol, ShowCounters;
    TList *pPrint;
};
//---------------------------------------------------------------------------
extern PACKAGE TrepVisitsForm *repVisitsForm;
//---------------------------------------------------------------------------
#endif
