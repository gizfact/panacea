//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "repSells.h"
#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TrepSellsForm *repSellsForm;

extern const char *MoneyFormat;

//---------------------------------------------------------------------------
__fastcall TrepSellsForm::TrepSellsForm(TComponent* Owner)
    : TForm(Owner)
{
    fCol = true;
}
//---------------------------------------------------------------------------
void __fastcall TrepSellsForm::QRPagePrint(TObject *sender,
      AnsiString &Value)
{
    Value = "Страница " + (AnsiString)QuickRep1->PageNumber;
}
//---------------------------------------------------------------------------
void __fastcall TrepSellsForm::QRFNamePrint(TObject *sender,
      AnsiString &Value)
{
    char ch = Value[1];

    switch(ch)
    {
case 'L':
        QRFName->Alignment = taRightJustify;
        QRFName->Font->Style = TFontStyles();
        Value = ((AnsiString *)pPrint->Items[QRlines->Index])[0]; break;
case 'H':
        QRFName->Alignment = taLeftJustify;
        QRFName->Font->Style = TFontStyles() << fsBold << fsItalic;
        Value = ((AnsiString *)pPrint->Items[QRlines->Index])[0]; break;
case 'A':
        QRFName->Font->Style = TFontStyles() << fsBold;
        Value = "Общий итог:"; break;
case 'I':
        QRFName->Font->Style = TFontStyles() << fsBold;
        Value = "Итого:"; break;
        //((AnsiString *)pPrint->Items[QRlines->Index])[0]; break;
default:
        Value = "";
    }
}
//---------------------------------------------------------------------------
void __fastcall TrepSellsForm::QRlinesBeforePrint(TQRCustomBand *Sender,
      bool &PrintBand)
{
    char ch = (QRlines->Items->Strings[QRlines->Index])[1];

    switch(ch)
    {
case 'H': fCol = true; break;
case 'L': fCol = !fCol; break;

default: fCol = false;

    }

    if(ch == 'I' || ch == 'A')
    {
        QRlines->Color = clSilver;
        QRFName->Color = clSilver;
        QRSName->Color = clSilver;
        QRBegBalanse->Color = clSilver;
        QRToBalanse->Color = clSilver;
        QRFromBalanse->Color = clSilver;
        QREndBalanse->Color = clSilver;
    }
    else if(fCol)
    {
        QRlines->Color = clBtnFace;
        QRFName->Color = clBtnFace;
        QRSName->Color = clBtnFace;
        QRBegBalanse->Color = clBtnFace;
        QRToBalanse->Color = clBtnFace;
        QRFromBalanse->Color = clBtnFace;
        QREndBalanse->Color = clBtnFace;
    }
    else
    {
        QRlines->Color = clWhite;
        QRFName->Color = clWhite;
        QRSName->Color = clWhite;
        QRBegBalanse->Color = clWhite;
        QRToBalanse->Color = clWhite;
        QRFromBalanse->Color = clWhite;
        QREndBalanse->Color = clWhite;
    }
}
//---------------------------------------------------------------------------
void __fastcall TrepSellsForm::QRSNamePrint(TObject *sender,
      AnsiString &Value)
{
    char ch = Value[1];

    switch(ch)
    {
case 'L':
        QRSName->Font->Style = TFontStyles();
        Value = ((AnsiString *)pPrint->Items[QRlines->Index])[1]; break;
case 'H':
        QRSName->Font->Style = TFontStyles() << fsBold << fsItalic;
        Value = ((AnsiString *)pPrint->Items[QRlines->Index])[1]; break;
case 'I':
        QRSName->Font->Style = TFontStyles() << fsBold;
        Value = ((AnsiString *)pPrint->Items[QRlines->Index])[1]; break;
default:
        Value = "";
    }
}
//---------------------------------------------------------------------------
void __fastcall TrepSellsForm::QRBegBalansePrint(TObject *sender,
      AnsiString &Value)
{
    char ch = Value[1];

    switch(ch)
    {
case 'L':
        QRBegBalanse->Font->Style = TFontStyles();
        Value = ((AnsiString *)pPrint->Items[QRlines->Index])[2]; break;
case 'H':
        QRBegBalanse->Font->Style = TFontStyles() << fsBold << fsItalic;
        Value = ((AnsiString *)pPrint->Items[QRlines->Index])[2]; break;
case 'I':
case 'A':
        QRBegBalanse->Font->Style = TFontStyles() << fsBold;
        Value = ((AnsiString *)pPrint->Items[QRlines->Index])[2]; break;
default:
        Value = "";
    }
}
//---------------------------------------------------------------------------
void __fastcall TrepSellsForm::QRFromBalansePrint(TObject *sender,
      AnsiString &Value)
{
    char ch = Value[1];

    switch(ch)
    {
case 'L':
        QRFromBalanse->Font->Style = TFontStyles();
        Value = ((AnsiString *)pPrint->Items[QRlines->Index])[4]; break;
case 'H':
        QRFromBalanse->Font->Style = TFontStyles() << fsBold << fsItalic;
        Value = ((AnsiString *)pPrint->Items[QRlines->Index])[4]; break;
case 'I':
case 'A':
        QRFromBalanse->Font->Style = TFontStyles() << fsBold;
        Value = ((AnsiString *)pPrint->Items[QRlines->Index])[4]; break;


default:
        Value = "";
    }
}
//---------------------------------------------------------------------------
void __fastcall TrepSellsForm::QRToBalansePrint(TObject *sender,
      AnsiString &Value)
{
    char ch = Value[1];

    switch(ch)
    {
case 'L':
        QRToBalanse->Font->Style = TFontStyles();
        Value = ((AnsiString *)pPrint->Items[QRlines->Index])[3]; break;
case 'H':
        QRToBalanse->Font->Style = TFontStyles() << fsBold << fsItalic;
        Value = ((AnsiString *)pPrint->Items[QRlines->Index])[3]; break;
case 'I':
case 'A':
        QRToBalanse->Font->Style = TFontStyles() << fsBold;
        Value = ((AnsiString *)pPrint->Items[QRlines->Index])[3]; break;
default:
        Value = "";
    }
}
//---------------------------------------------------------------------------
void __fastcall TrepSellsForm::QREndBalansePrint(TObject *sender,
      AnsiString &Value)
{
    char ch = Value[1];

    switch(ch)
    {
case 'L':
        QREndBalanse->Font->Style = TFontStyles();
        Value = ((AnsiString *)pPrint->Items[QRlines->Index])[5]; break;
case 'H':
        QREndBalanse->Font->Style = TFontStyles() << fsBold << fsItalic;
        Value = ((AnsiString *)pPrint->Items[QRlines->Index])[5]; break;
case 'I':
case 'A':
        QREndBalanse->Font->Style = TFontStyles() << fsBold;
        Value = ((AnsiString *)pPrint->Items[QRlines->Index])[5]; break;
default:
        Value = "";
    }
}
//---------------------------------------------------------------------------


