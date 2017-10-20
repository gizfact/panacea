//---------------------------------------------------------------------------

#ifndef repBalanseSPAH
#define repBalanseSPAH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QRCtrls.hpp>
#include <QuickRpt.hpp>
//---------------------------------------------------------------------------
class TrepBalanseSPAForm : public TForm
{
__published:	// IDE-managed Components
    TQuickRep *QuickRep1;
    TQRStringsBand *QRlines;
    TQRExpr *QRFName;
    TQRExpr *QRSName;
    TQRExpr *QRTName;
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
    TQRBand *QRBand5;
    TQRChildBand *ChildBand1;
    TQRExpr *QRFromBalanseSum;
    TQRExpr *QRToBalanseSum;
    TQRLabel *QRLabel9;
    TQRExpr *QRBalanseNAll;
    TQRChildBand *ChildBand2;
    TQRLabel *QRLabel1;
    TQRLabel *QRLabel4;
    TQRLabel *QRLabel5;
    TQRLabel *QRLabel2;
    TQRLabel *QRLabel10;
    TQRLabel *QRLabel11;
    TQRLabel *QRLabel7;
    void __fastcall QRPagePrint(TObject *sender, AnsiString &Value);
    void __fastcall QRFNamePrint(TObject *sender, AnsiString &Value);
    void __fastcall QRlinesBeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
    void __fastcall QRSNamePrint(TObject *sender, AnsiString &Value);
    void __fastcall QRTNamePrint(TObject *sender, AnsiString &Value);
    void __fastcall QRBegBalansePrint(TObject *sender, AnsiString &Value);
    void __fastcall QRFromBalansePrint(TObject *sender, AnsiString &Value);
    void __fastcall QRFromBalanseSumPrint(TObject *sender,
          AnsiString &Value);
    void __fastcall QRToBalanseSumPrint(TObject *sender,
          AnsiString &Value);
    void __fastcall QRToBalansePrint(TObject *sender, AnsiString &Value);
    void __fastcall QREndBalansePrint(TObject *sender, AnsiString &Value);
    void __fastcall QRBalanseNAllPrint(TObject *sender, AnsiString &Value);
private:	// User declarations
public:		// User declarations
    __fastcall TrepBalanseSPAForm(TComponent* Owner);

    //int PageNumber;
    bool fCol;
};
//---------------------------------------------------------------------------
extern PACKAGE TrepBalanseSPAForm *repBalanseSPAForm;
//---------------------------------------------------------------------------
#endif
