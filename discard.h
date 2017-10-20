//---------------------------------------------------------------------------

#ifndef discardH
#define discardH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TDisCardForm : public TForm
{
__published:	// IDE-managed Components
    TEdit *edCard;
    TButton *Button1;
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall edCardKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations


public:		// User declarations
    AnsiString UserCard;

    __fastcall TDisCardForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDisCardForm *DisCardForm;
//---------------------------------------------------------------------------
#endif
