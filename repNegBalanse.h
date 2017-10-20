//---------------------------------------------------------------------------

#ifndef repNegBalanseH
#define repNegBalanseH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QRCtrls.hpp>
#include <QuickRpt.hpp>
//---------------------------------------------------------------------------
class TrepNegBalanseForm : public TForm
{
__published:	// IDE-managed Components
    TQuickRep *QuickRep1;
    TQRStringsBand *QRlines;
    TQRExpr *QRExpr1;
    TQRExpr *QRExpr2;
    TQRExpr *QRExpr3;
    TQRExpr *QRExpr7;
    TQRBand *QRBand1;
    TQRBand *QRBand2;
    TQRExpr *QRExpr0;
    TQRLabel *QRCreated;
    TQRBand *QRBand3;
    TQRLabel *QRHeader;
    TQRBand *QRBand5;
    TQRChildBand *ChildBand1;
    TQRLabel *QRLabel8;
    TQRExpr *QRExpr11;
    TQRChildBand *ChildBand2;
    TQRLabel *QRLabel1;
    TQRLabel *QRLabel2;
    TQRLabel *QRLabel3;
    TQRLabel *QRLabel7;
    void __fastcall QRExpr0Print(TObject *sender, AnsiString &Value);
    void __fastcall QRExpr1Print(TObject *sender, AnsiString &Value);
    void __fastcall QRExpr2Print(TObject *sender, AnsiString &Value);
    void __fastcall QRExpr3Print(TObject *sender, AnsiString &Value);
    void __fastcall QRExpr7Print(TObject *sender, AnsiString &Value);
    void __fastcall QRExpr11Print(TObject *sender, AnsiString &Value);
    void __fastcall QRlinesBeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
private:	// User declarations
public:		// User declarations
    //int PageNumber;
    bool fCol;
    __fastcall TrepNegBalanseForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TrepNegBalanseForm *repNegBalanseForm;
//---------------------------------------------------------------------------
#endif
