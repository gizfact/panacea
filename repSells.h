//---------------------------------------------------------------------------

#ifndef repSellsH
#define repSellsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QRCtrls.hpp>
#include <QuickRpt.hpp>
//---------------------------------------------------------------------------
class TrepSellsForm : public TForm
{
__published:	// IDE-managed Components
    TQuickRep *QuickRep1;
    TQRStringsBand *QRlines;
    TQRExpr *QRFName;
    TQRExpr *QRBegBalanse;
    TQRExpr *QRFromBalanse;
    TQRExpr *QRToBalanse;
    TQRExpr *QREndBalanse;
    TQRBand *QRBand1;
    TQRBand *QRBand2;
    TQRExpr *QRPage;
    TQRLabel *QRCreated;
    TQRBand *QRBand3;
    TQRLabel *QRHeader;
    TQRChildBand *ChildBand2;
    TQRLabel *QRLabel1;
    TQRLabel *QRLabel4;
    TQRLabel *QRLabel5;
    TQRLabel *QRLabel2;
    TQRLabel *QRLabel7;
    TQRExpr *QRSName;
    TQRLabel *QRLabel3;
    void __fastcall QRPagePrint(TObject *sender, AnsiString &Value);
    void __fastcall QRFNamePrint(TObject *sender, AnsiString &Value);
    void __fastcall QRlinesBeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
    void __fastcall QRSNamePrint(TObject *sender, AnsiString &Value);
    void __fastcall QRBegBalansePrint(TObject *sender, AnsiString &Value);
    void __fastcall QRFromBalansePrint(TObject *sender, AnsiString &Value);
    void __fastcall QRToBalansePrint(TObject *sender, AnsiString &Value);
    void __fastcall QREndBalansePrint(TObject *sender, AnsiString &Value);
private:	// User declarations

    bool fCol;
public:		// User declarations
    TList *pPrint;

    __fastcall TrepSellsForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TrepSellsForm *repSellsForm;
//---------------------------------------------------------------------------
#endif
