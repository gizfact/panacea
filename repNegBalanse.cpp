//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "repNegBalanse.h"
#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TrepNegBalanseForm *repNegBalanseForm;

extern const char *MoneyFormat;
//---------------------------------------------------------------------------
__fastcall TrepNegBalanseForm::TrepNegBalanseForm(TComponent* Owner)
    : TForm(Owner)
{
    //PageNumber = 0;
    fCol = true;
}
//---------------------------------------------------------------------------
void __fastcall TrepNegBalanseForm::QRExpr0Print(TObject *sender,
      AnsiString &Value)
{
    Value = "Страница " + (AnsiString)QuickRep1->PageNumber;
}
//---------------------------------------------------------------------------
void __fastcall TrepNegBalanseForm::QRExpr1Print(TObject *sender,
      AnsiString &Value)
{
    unsigned i = Value.ToInt();

    Value = MainForm->repClientsFNames[i];
}
//---------------------------------------------------------------------------
void __fastcall TrepNegBalanseForm::QRExpr2Print(TObject *sender,
      AnsiString &Value)
{
    unsigned i = Value.ToInt();

    Value = MainForm->repClientsSNames[i];
}
//---------------------------------------------------------------------------
void __fastcall TrepNegBalanseForm::QRExpr3Print(TObject *sender,
      AnsiString &Value)
{
    unsigned i = Value.ToInt();

    Value = MainForm->repClientsTNames[i];
}
//---------------------------------------------------------------------------
void __fastcall TrepNegBalanseForm::QRExpr7Print(TObject *sender,
      AnsiString &Value)
{
    unsigned i = Value.ToInt();

    Value = FormatFloat(MoneyFormat,atof(MainForm->repClientsEndBalanse[i].c_str()));
}
//---------------------------------------------------------------------------
void __fastcall TrepNegBalanseForm::QRExpr11Print(TObject *sender,
      AnsiString &Value)
{
    Value = FormatFloat(MoneyFormat,MainForm->repEndBalanseSum);
}
//---------------------------------------------------------------------------
void __fastcall TrepNegBalanseForm::QRlinesBeforePrint(
      TQRCustomBand *Sender, bool &PrintBand)
{
    if(!fCol)
    {
        QRlines->Color = clBtnFace;
        QRExpr1->Color = clBtnFace;
        QRExpr2->Color = clBtnFace;
        QRExpr3->Color = clBtnFace;
        QRExpr7->Color = clBtnFace;
    }
    else
    {
        QRlines->Color = clWhite;
        QRExpr1->Color = clWhite;
        QRExpr2->Color = clWhite;
        QRExpr3->Color = clWhite;
        QRExpr7->Color = clWhite;
    }
    fCol = !fCol;
}
//---------------------------------------------------------------------------
