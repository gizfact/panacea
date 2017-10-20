//---------------------------------------------------------------------------

#ifndef repGoodsSPAH
#define repGoodsSPAH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QRCtrls.hpp>
#include <QuickRpt.hpp>
//---------------------------------------------------------------------------
class TrepGoodsSPAForm : public TForm
{
__published:	// IDE-managed Components
    TQuickRep *QuickRep1;
    TQRStringsBand *QRlines;
    TQRExpr *QRIncome;
    TQRExpr *QROutcome;
    TQRExpr *QRStock;
    TQRExpr *QRGood;
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
    void __fastcall QRPagePrint(TObject *sender, AnsiString &Value);
    void __fastcall QRlinesBeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
    void __fastcall QRGoodPrint(TObject *sender, AnsiString &Value);
    void __fastcall QRIncomePrint(TObject *sender, AnsiString &Value);
    void __fastcall QROutcomePrint(TObject *sender, AnsiString &Value);
    void __fastcall QRStockPrint(TObject *sender, AnsiString &Value);
private:	// User declarations
public:		// User declarations
    TList *pPrint;
    bool fCol;

    __fastcall TrepGoodsSPAForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TrepGoodsSPAForm *repGoodsSPAForm;
//---------------------------------------------------------------------------
#endif
