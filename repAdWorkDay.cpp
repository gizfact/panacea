//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "repAdWorkDay.h"
#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TRepAdWorkDayForm *RepAdWorkDayForm;

extern const char *MoneyFormat;
extern const char *MoneyWideFormat;
//---------------------------------------------------------------------------
__fastcall TRepAdWorkDayForm::TRepAdWorkDayForm(TComponent* Owner)
    : TForm(Owner)
{
    fCol = true;
}
//---------------------------------------------------------------------------
void __fastcall TRepAdWorkDayForm::QRPagePrint(TObject *sender,
      AnsiString &Value)
{
    Value = "Страница " + (AnsiString)QuickRep1->PageNumber;
}
//---------------------------------------------------------------------------
void __fastcall TRepAdWorkDayForm::QRlinesBeforePrint(
      TQRCustomBand *Sender, bool &PrintBand)
{
    if(!fCol)
    {
        QRlines->Color = clBtnFace;
        QRLogin->Color = clBtnFace;
        QRBegTime->Color = clBtnFace;
        QREndTime->Color = clBtnFace;
        QRWorkTime->Color = clBtnFace;
    }
    else
    {
        QRlines->Color = clWhite;
        QRLogin->Color = clWhite;
        QRBegTime->Color = clWhite;
        QREndTime->Color = clWhite;
        QRWorkTime->Color = clWhite;
    }

    fCol = !fCol;
}
//---------------------------------------------------------------------------
void __fastcall TRepAdWorkDayForm::QRLoginPrint(TObject *sender,
      AnsiString &Value)
{
    unsigned i = Value.ToInt();

    Value = MainForm->repClientsFNames[i];
}
//---------------------------------------------------------------------------
void __fastcall TRepAdWorkDayForm::QRBegTimePrint(TObject *sender,
      AnsiString &Value)
{
    unsigned i = Value.ToInt();

    Value = MainForm->repClientsSNames[i];
}
//---------------------------------------------------------------------------
void __fastcall TRepAdWorkDayForm::QREndTimePrint(TObject *sender,
      AnsiString &Value)
{
    unsigned i = Value.ToInt();

    Value = MainForm->repClientsTNames[i];
}
//---------------------------------------------------------------------------
void __fastcall TRepAdWorkDayForm::QRWorkTimePrint(TObject *sender,
      AnsiString &Value)
{
    unsigned i = Value.ToInt();

    Value = MainForm->repClientsBegBalanse[i];
}
//---------------------------------------------------------------------------
