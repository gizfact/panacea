//---------------------------------------------------------------------------

#ifndef repAbServicesH
#define repAbServicesH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QRCtrls.hpp>
#include <QuickRpt.hpp>
//---------------------------------------------------------------------------
class TrepAbServicesForm : public TForm
{
__published:	// IDE-managed Components
    TQuickRep *QuickRep1;
    TQRStringsBand *QRlines;
    TQRExpr *QRCoach0;
    TQRExpr *QRCoach1;
    TQRExpr *QRCoach2;
    TQRExpr *QRCoach3;
    TQRExpr *QRCoach4;
    TQRExpr *QRCoach5;
    TQRBand *QRBand1;
    TQRBand *QRBand2;
    TQRExpr *QRPage;
    TQRLabel *QRCreated;
    TQRBand *QRBand3;
    TQRLabel *QRHeader;
    TQRBand *QRBand5;
    TQRChildBand *ChildBand1;
    TQRLabel *QRLabel8;
    TQRExpr *QRCoach0Sum;
    TQRExpr *QRCoach6;
    TQRExpr *QRCoach7;
    TQRExpr *QRCoach8;
    TQRExpr *QRFirst;
    TQRExpr *QRCoach1Sum;
    TQRExpr *QRCoach2Sum;
    TQRExpr *QRCoach3Sum;
    TQRExpr *QRCoach4Sum;
    TQRExpr *QRCoach5Sum;
    TQRExpr *QRCoach6Sum;
    TQRExpr *QRCoach7Sum;
    TQRExpr *QRCoach8Sum;
    void __fastcall QRlinesBeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
    void __fastcall QRCoach0Print(TObject *sender, AnsiString &Value);
    void __fastcall QRPagePrint(TObject *sender, AnsiString &Value);
    void __fastcall QuickRep1StartPage(TCustomQuickRep *Sender);
    void __fastcall QRFirstPrint(TObject *sender, AnsiString &Value);
    void __fastcall QRCoach1Print(TObject *sender, AnsiString &Value);
    void __fastcall QRCoach2Print(TObject *sender, AnsiString &Value);
    void __fastcall QRCoach3Print(TObject *sender, AnsiString &Value);
    void __fastcall QRCoach4Print(TObject *sender, AnsiString &Value);
    void __fastcall QRCoach5Print(TObject *sender, AnsiString &Value);
    void __fastcall QRCoach6Print(TObject *sender, AnsiString &Value);
    void __fastcall QRCoach7Print(TObject *sender, AnsiString &Value);
    void __fastcall QRCoach8Print(TObject *sender, AnsiString &Value);
    void __fastcall QRCoach0SumPrint(TObject *sender, AnsiString &Value);
    void __fastcall QRCoach1SumPrint(TObject *sender, AnsiString &Value);
    void __fastcall QRCoach2SumPrint(TObject *sender, AnsiString &Value);
    void __fastcall QRCoach3SumPrint(TObject *sender, AnsiString &Value);
    void __fastcall QRCoach4SumPrint(TObject *sender, AnsiString &Value);
    void __fastcall QRCoach5SumPrint(TObject *sender, AnsiString &Value);
    void __fastcall QRCoach6SumPrint(TObject *sender, AnsiString &Value);
    void __fastcall QRCoach7SumPrint(TObject *sender, AnsiString &Value);
    void __fastcall QRCoach8SumPrint(TObject *sender, AnsiString &Value);
private:	// User declarations
public:		// User declarations
    int PageNumber;
    bool fCol;

    double Total0, Total1, Total2, Total3, Total4, Total5, Total6, Total7, Total8;
    double Sum0, Sum1, Sum2, Sum3, Sum4, Sum5, Sum6, Sum7, Sum8;

    TList *pPrint;

    __fastcall TrepAbServicesForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TrepAbServicesForm *repAbServicesForm;
//---------------------------------------------------------------------------
#endif
