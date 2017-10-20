//---------------------------------------------------------------------------

#ifndef dt_intervalH
#define dt_intervalH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TDateIntervalForm : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label1;
    TLabel *Label2;
    TBevel *Bevel1;
    TButton *Button1;
    TButton *Button2;
    TDateTimePicker *dtpBegDate;
    TDateTimePicker *dtpEndDate;
    TLabel *laUsers;
    TComboBox *lbUsers;
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall dtpEndDateExit(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TDateIntervalForm(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TDateIntervalForm *DateIntervalForm;
//---------------------------------------------------------------------------
#endif
