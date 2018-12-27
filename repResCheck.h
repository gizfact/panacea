//---------------------------------------------------------------------------

#ifndef repResCheckH
#define repResCheckH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QRCtrls.hpp>
#include <QuickRpt.hpp>
//---------------------------------------------------------------------------
class TrepResCheckForm : public TForm
{
__published:	// IDE-managed Components
    TQuickRep *QuickRep1;
    TQRStringsBand *QRlines;
    TQRExpr *QRDate;
    TQRExpr *QRUser;
    TQRExpr *QRCDate;
    TQRExpr *QRGroup;
    TQRExpr *QRClient;
    TQRExpr *QRService;
    TQRExpr *QRStatus;
    TQRBand *QRBand1;
    TQRBand *QRBand2;
    TQRExpr *QRPage;
    TQRLabel *QRCreated;
    TQRBand *QRBand3;
    TQRLabel *QRHeader;
    TQRBand *QRBand5;
    TQRChildBand *ChildBand1;
    TQRChildBand *ChildBand2;
    TQRLabel *QRLabel1;
    TQRLabel *QRLabel4;
    TQRLabel *QRLabel5;
    TQRLabel *QRLabel2;
    TQRLabel *QRLabel3;
    TQRLabel *QRLabel10;
    TQRLabel *QRLabel11;
    TQRLabel *QRLabel6;
    TQRExpr *QRDeleted;
    void __fastcall QRPagePrint(TObject *sender, AnsiString &Value);
    void __fastcall QRDatePrint(TObject *sender, AnsiString &Value);
    void __fastcall QRUserPrint(TObject *sender, AnsiString &Value);
    void __fastcall QRCDatePrint(TObject *sender, AnsiString &Value);
    void __fastcall QRGroupPrint(TObject *sender, AnsiString &Value);
    void __fastcall QRClientPrint(TObject *sender, AnsiString &Value);
    void __fastcall QRServicePrint(TObject *sender, AnsiString &Value);
    void __fastcall QRStatusPrint(TObject *sender, AnsiString &Value);
    void __fastcall QRlinesBeforePrint(TQRCustomBand *Sender,
          bool &PrintBand);
    void __fastcall QRDeletedPrint(TObject *sender, AnsiString &Value);
private:	// User declarations
public:		// User declarations
    bool fCol;

    __fastcall TrepResCheckForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TrepResCheckForm *repResCheckForm;
//---------------------------------------------------------------------------
#endif
