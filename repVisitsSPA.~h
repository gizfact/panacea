//---------------------------------------------------------------------------

#ifndef repVisitsSPAH
#define repVisitsSPAH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QRCtrls.hpp>
#include <QuickRpt.hpp>
//---------------------------------------------------------------------------
class TrepVisitsSPAForm : public TForm
{
__published:	// IDE-managed Components
    TQuickRep *QuickRep1;
    TQRStringsBand *QRlines;
    TQRExpr *QRClient;
    TQRExpr *QRVisit;
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
    TQRBand *QRBand4;
    TQRLabel *QRLabel8;
    TQRExpr *QRVisitSum;
    void __fastcall QRPagePrint(TObject *sender, AnsiString &Value);
    void __fastcall QRCoachPrint(TObject *sender, AnsiString &Value);
    void __fastcall QRClientPrint(TObject *sender, AnsiString &Value);
    void __fastcall QRlinesBeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
    void __fastcall QRVisitPrint(TObject *sender, AnsiString &Value);
 
    void __fastcall QRVisitSumPrint(TObject *sender, AnsiString &Value);
  
    void __fastcall QRAbSumPrint(TObject *sender, AnsiString &Value);
    void __fastcall QuickRep1BeforePrint(TCustomQuickRep *Sender,
          bool &PrintReport);
private:	// User declarations
public:		// User declarations
    double VisitsSum, VisitsPSum, AbSum, VisitsSumTotal, VisitsPSumTotal, AbSumTotal;
    unsigned VisitsTime, VisitsTimeTotal, VisitsCnt, AbCnt, VisitsCntTotal, AbCntTotal;

    bool FromAbs;

    bool fCol, ShowCounters;
    TList *pPrint;
    
    __fastcall TrepVisitsSPAForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TrepVisitsSPAForm *repVisitsSPAForm;
//---------------------------------------------------------------------------
#endif
