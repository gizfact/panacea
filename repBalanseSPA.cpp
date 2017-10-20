//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "repBalanseSPA.h"
#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TrepBalanseSPAForm *repBalanseSPAForm;

extern const char *MoneyFormat;
extern const char *MoneyWideFormat;
//---------------------------------------------------------------------------
__fastcall TrepBalanseSPAForm::TrepBalanseSPAForm(TComponent* Owner)
    : TForm(Owner)
{
    //PageNumber = 0;
    fCol = true;
}
//---------------------------------------------------------------------------
void __fastcall TrepBalanseSPAForm::QRPagePrint(TObject *sender,
      AnsiString &Value)
{
    Value = "Страница " + (AnsiString)QuickRep1->PageNumber;
}
//---------------------------------------------------------------------------
void __fastcall TrepBalanseSPAForm::QRFNamePrint(TObject *sender,
      AnsiString &Value)
{
    unsigned i = Value.ToInt();

    Value = MainForm->repClientsFNames[i];
}
//---------------------------------------------------------------------------
void __fastcall TrepBalanseSPAForm::QRlinesBeforePrint(
      TQRCustomBand *Sender, bool &PrintBand)
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
        //QRToBalanseBN->Color = clBtnFace;
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
        //QRToBalanseBN->Color = clWhite;
        QREndBalanse->Color = clWhite;
    }
    
    fCol = !fCol;
}
//---------------------------------------------------------------------------
void __fastcall TrepBalanseSPAForm::QRSNamePrint(TObject *sender,
      AnsiString &Value)
{
    unsigned i = Value.ToInt();

    Value = MainForm->repClientsSNames[i];
}
//---------------------------------------------------------------------------
void __fastcall TrepBalanseSPAForm::QRTNamePrint(TObject *sender,
      AnsiString &Value)
{
   unsigned i = Value.ToInt();

    Value = MainForm->repClientsTNames[i];
}
//---------------------------------------------------------------------------
void __fastcall TrepBalanseSPAForm::QRBegBalansePrint(TObject *sender,
      AnsiString &Value)
{
   unsigned i = Value.ToInt();

    Value = MainForm->repClientsBegBalanse[i];
}
//---------------------------------------------------------------------------
void __fastcall TrepBalanseSPAForm::QRFromBalansePrint(TObject *sender,
      AnsiString &Value)
{
   unsigned i = Value.ToInt();

   Value = MainForm->repClientsFromBalanse[i];
}
//---------------------------------------------------------------------------
void __fastcall TrepBalanseSPAForm::QRFromBalanseSumPrint(TObject *sender,
      AnsiString &Value)
{
    Value = FormatFloat(MoneyFormat,MainForm->repFromBalanseSum);
}
//---------------------------------------------------------------------------
void __fastcall TrepBalanseSPAForm::QRToBalanseSumPrint(TObject *sender,
      AnsiString &Value)
{
    Value = FormatFloat(MoneyFormat,MainForm->repToBalanseSum);
}
//---------------------------------------------------------------------------
void __fastcall TrepBalanseSPAForm::QRToBalansePrint(TObject *sender,
      AnsiString &Value)
{
    unsigned i = Value.ToInt();

    Value = MainForm->repClientsToBalanse[i];
}
//---------------------------------------------------------------------------
void __fastcall TrepBalanseSPAForm::QREndBalansePrint(TObject *sender,
      AnsiString &Value)
{
    unsigned i = Value.ToInt();

    Value = MainForm->repClientsEndBalanse[i];
}
//---------------------------------------------------------------------------
void __fastcall TrepBalanseSPAForm::QRBalanseNAllPrint(TObject *sender,
      AnsiString &Value)
{
   Value = FormatFloat(MoneyFormat,MainForm->repToBalanseSum - MainForm->repFromBalanseSum);
}
//---------------------------------------------------------------------------

