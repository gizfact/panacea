//---------------------------------------------------------------------------

#ifndef purchaseH
#define purchaseH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TPurchaseForm : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label1;
    TLabel *Label2;
    TEdit *edQTTY;
    TEdit *edSum;
    TPanel *Panel1;
    TButton *Button1;
    TButton *Button2;
    TLabel *Label3;
    TComboBox *lbGoods;
    void __fastcall edQTTYKeyPress(TObject *Sender, char &Key);
    void __fastcall edSumKeyPress(TObject *Sender, char &Key);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations

    AnsiString *pGoods;
    int Count;


    __fastcall TPurchaseForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPurchaseForm *PurchaseForm;
//---------------------------------------------------------------------------
#endif
