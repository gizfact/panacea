//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "repGoodsSPA.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TrepGoodsSPAForm *repGoodsSPAForm;
//---------------------------------------------------------------------------
__fastcall TrepGoodsSPAForm::TrepGoodsSPAForm(TComponent* Owner)
    : TForm(Owner)
{
    fCol = true;
}
//---------------------------------------------------------------------------
void __fastcall TrepGoodsSPAForm::QRPagePrint(TObject *sender,
      AnsiString &Value)
{
    Value = "Страница " + (AnsiString)QuickRep1->PageNumber;
}
//---------------------------------------------------------------------------
void __fastcall TrepGoodsSPAForm::QRlinesBeforePrint(TQRCustomBand *Sender,
      bool &PrintBand)
{
    char ch = (QRlines->Items->Strings[QRlines->Index])[1];

    switch(ch)
    {
case 'H': fCol = true; break;
case 'L': fCol = !fCol; break;

default: fCol = false;

    }

    if(ch == 'I')
    {
        QRlines->Color = clSilver;
        QRGood->Color = clSilver;
        QRIncome->Color = clSilver;
        QROutcome->Color = clSilver;
        QRStock->Color = clSilver;
    }
    else if(fCol)
    {
        QRlines->Color = clBtnFace;
        QRGood->Color = clBtnFace;
        QRIncome->Color = clBtnFace;
        QROutcome->Color = clBtnFace;
        QRStock->Color = clBtnFace;
    }
    else
    {
        QRlines->Color = clWhite;
        QRGood->Color = clWhite;
        QRIncome->Color = clWhite;
        QROutcome->Color = clWhite;
        QRStock->Color = clWhite;
    }
}
//---------------------------------------------------------------------------

void __fastcall TrepGoodsSPAForm::QRGoodPrint(TObject *sender,
      AnsiString &Value)
{
    char ch = Value[1];

    switch(ch)
    {
case 'H':
case 'L':
        Value = ((AnsiString *)pPrint->Items[QRlines->Index])[0]; break;
default:
        Value = "";
    }
}
//---------------------------------------------------------------------------

void __fastcall TrepGoodsSPAForm::QRIncomePrint(TObject *sender,
      AnsiString &Value)
{
    char ch = Value[1];

    switch(ch)
    {
case 'H':
case 'L':
        Value = ((AnsiString *)pPrint->Items[QRlines->Index])[1]; break;
default:
        Value = "";
    }
}
//---------------------------------------------------------------------------

void __fastcall TrepGoodsSPAForm::QROutcomePrint(TObject *sender,
      AnsiString &Value)
{
    char ch = Value[1];

    switch(ch)
    {
case 'H':
case 'L':
        Value = ((AnsiString *)pPrint->Items[QRlines->Index])[2]; break;
default:
        Value = "";
    }    
}
//---------------------------------------------------------------------------

void __fastcall TrepGoodsSPAForm::QRStockPrint(TObject *sender,
      AnsiString &Value)
{
    char ch = Value[1];

    switch(ch)
    {
case 'H':
case 'L':
        Value = ((AnsiString *)pPrint->Items[QRlines->Index])[3]; break;
default:
        Value = "";
    }    
}
//---------------------------------------------------------------------------

