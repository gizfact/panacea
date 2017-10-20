//---------------------------------------------------------------------------

#ifndef abparamH
#define abparamH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TAbParamForm : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TBevel *Bevel1;
    TLabel *laDate;
    TLabel *Label1;
    TLabel *Label2;
    TBevel *Bevel2;
    TButton *bCancel;
    TComboBox *lbPersonal;
    TComboBox *lbServices;
    TButton *bOK;
    TEdit *edBalanse;
    TLabel *laBalanse;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall bCancelClick(TObject *Sender);
    void __fastcall bOKClick(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall edBalanseKeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
    __int64 *pPersonalIDs;
    AnsiString *pPersonal;
    __int64 *pServicesIDs;
    AnsiString *pServices;

    AnsiString Tag;

    __int64 AbParamPID;
    __int64 AbParamSID;
    double Balanse;

    __fastcall TAbParamForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAbParamForm *AbParamForm;
//---------------------------------------------------------------------------
#endif
