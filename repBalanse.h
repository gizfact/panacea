//---------------------------------------------------------------------------

#ifndef repBalanseH
#define repBalanseH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QuickRpt.hpp>
#include <QRCtrls.hpp>
//---------------------------------------------------------------------------
class TrepBalanseForm : public TForm
{
__published:	// IDE-managed Components
    TQuickRep *QuickRep1;
    TQRStringsBand *QRlines;
    TQRExpr *QRFName;
    TQRBand *QRBand1;
    TQRBand *QRBand2;
    TQRExpr *QRPage;
    TQRBand *QRBand3;
    TQRExpr *QRSName;
    TQRExpr *QRTName;
    TQRExpr *QRBegBalanse;
    TQRExpr *QRFromBalanse;
    TQRBand *QRBand5;
    TQRChildBand *ChildBand1;
    TQRExpr *QRFromBalanseSum;
    TQRExpr *QRToBalanseSum;
    TQRLabel *QRLabel9;
    TQRChildBand *ChildBand2;
    TQRLabel *QRLabel1;
    TQRLabel *QRLabel4;
    TQRLabel *QRLabel5;
    TQRLabel *QRLabel6;
    TQRLabel *QRHeader;
    TQRLabel *QRCreated;
    TQRLabel *QRLabel2;
    TQRLabel *QRLabel3;
    TQRLabel *QRLabel10;
    TQRLabel *QRLabel11;
    TQRExpr *QRToBalanse;
    TQRExpr *QRToBalanseBN;
    TQRLabel *QRLabel7;
    TQRExpr *QREndBalanse;
    TQRExpr *QRToBalanseBNSum;
    TQRExpr *QRBalanseNAll;
    void __fastcall QRPagePrint(TObject *sender, AnsiString &Value);
    void __fastcall QRFNamePrint(TObject *sender, AnsiString &Value);
    void __fastcall QRlinesBeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
    void __fastcall QRSNamePrint(TObject *sender, AnsiString &Value);
    void __fastcall QRTNamePrint(TObject *sender, AnsiString &Value);
    void __fastcall QRBegBalansePrint(TObject *sender, AnsiString &Value);
    void __fastcall QRFromBalansePrint(TObject *sender, AnsiString &Value);
    void __fastcall QRFromBalanseSumPrint(TObject *sender, AnsiString &Value);
    void __fastcall QRToBalanseSumPrint(TObject *sender, AnsiString &Value);
    void __fastcall QRBalanseSumAllPrint(TObject *sender, AnsiString &Value);
    void __fastcall QRToBalansePrint(TObject *sender, AnsiString &Value);
    void __fastcall QRToBalanseBNPrint(TObject *sender, AnsiString &Value);
    void __fastcall QREndBalansePrint(TObject *sender, AnsiString &Value);
    void __fastcall QRToBalanseBNSumPrint(TObject *sender,
          AnsiString &Value);
    void __fastcall QRBalanseNAllPrint(TObject *sender, AnsiString &Value);
private:	// User declarations
public:		// User declarations
    //int PageNumber;
    bool fCol;

    __fastcall TrepBalanseForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TrepBalanseForm *repBalanseForm;
//---------------------------------------------------------------------------
#endif
