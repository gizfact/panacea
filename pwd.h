//---------------------------------------------------------------------------

#ifndef pwdH
#define pwdH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TPwdForm : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TEdit *edOld;
    TEdit *edNew1;
    TEdit *edNew2;
    TButton *Button1;
    TButton *Button2;
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TPwdForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPwdForm *PwdForm;
//---------------------------------------------------------------------------
#endif
