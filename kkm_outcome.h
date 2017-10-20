//---------------------------------------------------------------------------

#ifndef kkm_outcomeH
#define kkm_outcomeH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TKKMOutForm : public TForm
{
__published:	// IDE-managed Components
    TLabel *laOp;
    TEdit *edOutcome;
    TButton *bOK;
    TButton *bCancel;
    void __fastcall bCancelClick(TObject *Sender);
    void __fastcall bOKClick(TObject *Sender);
    void __fastcall edOutcomeKeyPress(TObject *Sender, char &Key);
    void __fastcall FormShow(TObject *Sender);
private:	// User declarations
    bool Op;
public:		// User declarations
    __fastcall TKKMOutForm(TComponent* Owner,bool income = false);
};
//---------------------------------------------------------------------------
extern PACKAGE TKKMOutForm *KKMOutForm;
//---------------------------------------------------------------------------
#endif
