//---------------------------------------------------------------------------

#ifndef rescaltimeH
#define rescaltimeH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CSPIN.h"
//---------------------------------------------------------------------------
class TRescalTimeForm : public TForm
{
__published:	// IDE-managed Components
    TButton *Button1;
    TButton *Button2;
    TEdit *Edit1;
    TCSpinButton *CSpinButton1;
    TEdit *Edit2;
    TCSpinButton *CSpinButton2;
    TEdit *edQuan;
    TCSpinButton *sbQuan;
    TLabel *laQuan;
    void __fastcall CSpinButton1DownClick(TObject *Sender);
    void __fastcall CSpinButton1UpClick(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall CSpinButton2DownClick(TObject *Sender);
    void __fastcall CSpinButton2UpClick(TObject *Sender);
    void __fastcall sbQuanUpClick(TObject *Sender);
    void __fastcall sbQuanDownClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
    bool CheckTime;
    bool ShowQuan;

    int BegTime;
    int EndTime;

    __fastcall TRescalTimeForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TRescalTimeForm *RescalTimeForm;
//---------------------------------------------------------------------------
#endif
