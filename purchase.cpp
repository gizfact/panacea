//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "purchase.h"
#include "lib.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPurchaseForm *PurchaseForm;

extern int FormResult;
//---------------------------------------------------------------------------
__fastcall TPurchaseForm::TPurchaseForm(TComponent* Owner)
    : TForm(Owner)
{
    pGoods = NULL;
    Count = 0;
}
//---------------------------------------------------------------------------
void __fastcall TPurchaseForm::edQTTYKeyPress(TObject *Sender, char &Key)
{
   ui_keyfilter(Key);
}
//---------------------------------------------------------------------------
void __fastcall TPurchaseForm::edSumKeyPress(TObject *Sender, char &Key)
{
    ud_keyfilter(Key);
}
//---------------------------------------------------------------------------
void __fastcall TPurchaseForm::Button2Click(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TPurchaseForm::Button1Click(TObject *Sender)
{
    if(lbGoods->ItemIndex < 0)
    {
        Application->MessageBox("Внимание!\nНе выбран товар для закупки.","",MB_OK);
            return;
    }

    if(atoi(edQTTY->Text.c_str()) <= 0)
    {
        Application->MessageBox("Внимание!\nУказано некорректное количество.","",MB_OK);
        return;
    }

    if(atof(edSum->Text.c_str()) <= 0.0)
    {
        Application->MessageBox("Внимание!\nУказана некорректная сумма.","",MB_OK);
        return;
    }

    FormResult = 1;
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TPurchaseForm::FormShow(TObject *Sender)
{
    for(int i = 0; i < Count; i++)
        lbGoods->Items->Add(pGoods[i]);

    lbGoods->ItemIndex = 0;
}
//---------------------------------------------------------------------------


