//---------------------------------------------------------------------------

#ifndef repAdWorkDayH
#define repAdWorkDayH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QRCtrls.hpp>
#include <QuickRpt.hpp>
//---------------------------------------------------------------------------
class TRepAdWorkDayForm : public TForm
{
__published:	// IDE-managed Components
    TQuickRep *QuickRep1;
    TQRStringsBand *QRlines;
    TQRExpr *QRLogin;
    TQRExpr *QRBegTime;
    TQRExpr *QREndTime;
    TQRExpr *QRWorkTime;
    TQRBand *QRBand1;
    TQRBand *QRBand2;
    TQRExpr *QRPage;
    TQRLabel *QRCreated;
    TQRBand *QRBand3;
    TQRLabel *QRHeader;
    TQRBand *QRBand5;
    TQRChildBand *ChildBand2;
    TQRLabel *QRLabel1;
    TQRLabel *QRLabel4;
    TQRLabel *QRLabel5;
    TQRLabel *QRLabel7;
    void __fastcall QRPagePrint(TObject *sender, AnsiString &Value);
    void __fastcall QRLoginPrint(TObject *sender, AnsiString &Value);
    void __fastcall QRlinesBeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
    void __fastcall QRBegTimePrint(TObject *sender, AnsiString &Value);
    void __fastcall QREndTimePrint(TObject *sender, AnsiString &Value);
    void __fastcall QRWorkTimePrint(TObject *sender, AnsiString &Value);
private:	// User declarations
public:		// User declarations
    __fastcall TRepAdWorkDayForm(TComponent* Owner);

    bool fCol;
};
//---------------------------------------------------------------------------
extern PACKAGE TRepAdWorkDayForm *RepAdWorkDayForm;
//---------------------------------------------------------------------------
#endif
