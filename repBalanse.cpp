//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "repBalanse.h"
#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TrepBalanseForm *repBalanseForm;

extern const char *MoneyFormat;
extern const char *MoneyWideFormat;
//---------------------------------------------------------------------------
__fastcall TrepBalanseForm::TrepBalanseForm(TComponent* Owner)
    : TForm(Owner)
{
    //PageNumber = 0;
    fCol = true;
}
//---------------------------------------------------------------------------
void __fastcall TrepBalanseForm::QRPagePrint(TObject *sender,
      AnsiString &Value)
{
    Value = "Страница " + (AnsiString)QuickRep1->PageNumber;
}
//---------------------------------------------------------------------------
void __fastcall TrepBalanseForm::QRFNamePrint(TObject *sender,
      AnsiString &Value)
{
    unsigned i = Value.ToInt();

    Value = MainForm->repClientsFNames[i];
}
//---------------------------------------------------------------------------
void __fastcall TrepBalanseForm::QRlinesBeforePrint(TQRCustomBand *Sender,
      bool &PrintBand)
{
  if(!fCol)
    {
        QRlines->Color = clBtnFace;
        QRFName->Color = clBtnFace;
        QRSName->Color = clBtnFace;
        QRTName->Color = clBtnFace;
        QRBegBalanse->Color = clBtnFace;
        QRFromBalanse->Color = clBtnFace;
        QRToBalanse->Color = clBtnFace;
        QRToBalanseBN->Color = clBtnFace;
        QREndBalanse->Color = clBtnFace;
    }
    else
    {
        QRlines->Color = clWhite;
        QRFName->Color = clWhite;
        QRSName->Color = clWhite;
        QRTName->Color = clWhite;
        QRBegBalanse->Color = clWhite;
        QRFromBalanse->Color = clWhite;
        QRToBalanse->Color = clWhite;
        QRToBalanseBN->Color = clWhite;
        QREndBalanse->Color = clWhite;
    }
    
    fCol = !fCol;
}
//---------------------------------------------------------------------------
void __fastcall TrepBalanseForm::QRSNamePrint(TObject *sender,
      AnsiString &Value)
{
    unsigned i = Value.ToInt();

    Value = MainForm->repClientsSNames[i];
}
//---------------------------------------------------------------------------
void __fastcall TrepBalanseForm::QRTNamePrint(TObject *sender,
      AnsiString &Value)
{
   unsigned i = Value.ToInt();

    Value = MainForm->repClientsTNames[i];
}
//---------------------------------------------------------------------------
void __fastcall TrepBalanseForm::QRBegBalansePrint(TObject *sender,
      AnsiString &Value)
{
   unsigned i = Value.ToInt();

    Value = MainForm->repClientsBegBalanse[i];
}
//---------------------------------------------------------------------------
void __fastcall TrepBalanseForm::QRFromBalansePrint(TObject *sender,
      AnsiString &Value)
{
   unsigned i = Value.ToInt();

   Value = MainForm->repClientsFromBalanse[i];
}
//---------------------------------------------------------------------------
void __fastcall TrepBalanseForm::QRFromBalanseSumPrint(TObject *sender,
      AnsiString &Value)
{
    Value = FormatFloat(MoneyFormat,MainForm->repFromBalanseSum);
}
//---------------------------------------------------------------------------
void __fastcall TrepBalanseForm::QRToBalanseSumPrint(TObject *sender,
      AnsiString &Value)
{
    Value = FormatFloat(MoneyFormat,MainForm->repToBalanseSum);
}
//---------------------------------------------------------------------------
void __fastcall TrepBalanseForm::QRBalanseSumAllPrint(TObject *sender,
      AnsiString &Value)
{
    Value = FormatFloat(MoneyFormat,MainForm->repToBalanseSum + MainForm->repToBalanseBNSum + MainForm->repFromBalanseSum);
}
//---------------------------------------------------------------------------
void __fastcall TrepBalanseForm::QRToBalansePrint(TObject *sender,
      AnsiString &Value)
{
    unsigned i = Value.ToInt();

    Value = MainForm->repClientsToBalanse[i];
}
//---------------------------------------------------------------------------
void __fastcall TrepBalanseForm::QRToBalanseBNPrint(TObject *sender,
      AnsiString &Value)
{
    unsigned i = Value.ToInt();

    Value = MainForm->repClientsToBalanseBN[i];
}
//---------------------------------------------------------------------------
void __fastcall TrepBalanseForm::QREndBalansePrint(TObject *sender,
      AnsiString &Value)
{
    unsigned i = Value.ToInt();

    Value = MainForm->repClientsEndBalanse[i];
}
//---------------------------------------------------------------------------
void __fastcall TrepBalanseForm::QRToBalanseBNSumPrint(TObject *sender,
      AnsiString &Value)
{
    Value = FormatFloat(MoneyFormat,MainForm->repToBalanseBNSum);
}
//---------------------------------------------------------------------------
void __fastcall TrepBalanseForm::QRBalanseNAllPrint(TObject *sender,
      AnsiString &Value)
{
   Value = FormatFloat(MoneyFormat,MainForm->repToBalanseSum + MainForm->repFromBalanseSum);
}
//---------------------------------------------------------------------------

