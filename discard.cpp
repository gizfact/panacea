//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "discard.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDisCardForm *DisCardForm;

extern int FormResult;
//---------------------------------------------------------------------------
__fastcall TDisCardForm::TDisCardForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDisCardForm::Button1Click(TObject *Sender)
{
    Close();    
}
//---------------------------------------------------------------------------
void __fastcall TDisCardForm::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if(Key == VK_ESCAPE)
    {
        Key = 0;
        Close();
    }
    else if(Key == VK_INSERT)
        edCard->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TDisCardForm::edCardKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key == VK_RETURN)
    {
        Key = 0;
        if(UserCard == edCard->Text) FormResult = 1;

        Close();
    }
}
//---------------------------------------------------------------------------
