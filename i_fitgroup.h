//---------------------------------------------------------------------------

#ifndef i_fitgroupH
#define i_fitgroupH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TiFitGroupForm : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TLabel *Label5;
    TButton *Button1;
    TButton *Button2;
    TComboBox *cbService;
    TComboBox *cbPerson;
    TEdit *edBegTime;
    TEdit *edEndTime;
    TEdit *edCount;
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TiFitGroupForm(TComponent* Owner);

    __int64 CurrentID;
    int CurrentWDay;
    TDateTime CurrentDay;
};
//---------------------------------------------------------------------------
extern PACKAGE TiFitGroupForm *iFitGroupForm;
//---------------------------------------------------------------------------
#endif
