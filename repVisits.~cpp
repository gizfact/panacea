//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "repVisits.h"
#include "lib.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TrepVisitsForm *repVisitsForm;

extern const char *DBName;
extern const char *MoneyFormat;
//---------------------------------------------------------------------------
__fastcall TrepVisitsForm::TrepVisitsForm(TComponent* Owner)
    : TForm(Owner)
{
    VisitsSum = AbonementsSum = 0.0;
    VisitsSumTotal = AbonementsSumTotal = 0.0;
    VisitsCnt = AbonementsCnt = 0;
    VisitsCntTotal = AbonementsCntTotal = 0;
    AnsiString s;
    SQL_exefun(DBName,"select SettingsVal from Settings where SettingsKey='repVisitsCounters'",&s);
    ShowCounters = !(atoi(s.c_str()) == 0);
}
//---------------------------------------------------------------------------
void __fastcall TrepVisitsForm::QRPagePrint(TObject *sender, AnsiString &Value)
{
    Value = "Страница " + (AnsiString)QuickRep1->PageNumber;
}
//---------------------------------------------------------------------------
void __fastcall TrepVisitsForm::QRlinesBeforePrint(TQRCustomBand *Sender,
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
        QRCoach->Color = clSilver;
        QRClient->Color = clSilver;
        QRVisit->Color = clSilver;
        QRAbonement->Color = clSilver;
    }
    else if(fCol)
    {
        QRlines->Color = clBtnFace;
        QRCoach->Color = clBtnFace;
        QRClient->Color = clBtnFace;
        QRVisit->Color = clBtnFace;
        QRAbonement->Color = clBtnFace;
    }
    else
    {
        QRlines->Color = clWhite;
        QRCoach->Color = clWhite;
        QRClient->Color = clWhite;
        QRVisit->Color = clWhite;
        QRAbonement->Color = clWhite;
    }

}
//---------------------------------------------------------------------------
void __fastcall TrepVisitsForm::QRVisitSumPrint(TObject *sender,
      AnsiString &Value)
{
    Value = FormatFloat(MoneyFormat,VisitsSumTotal) + " (" + VisitsCntTotal + ")";
}
//---------------------------------------------------------------------------
void __fastcall TrepVisitsForm::QRAbonementSumPrint(TObject *sender,
      AnsiString &Value)
{
    Value = FormatFloat(MoneyFormat,AbonementsSumTotal) + " (" + AbonementsCntTotal + ")";
}
//---------------------------------------------------------------------------
void __fastcall TrepVisitsForm::QuickRep1BeforePrint(
      TCustomQuickRep *Sender, bool &PrintReport)
{
    VisitsSum = AbonementsSum = 0.0;
    VisitsSumTotal = AbonementsSumTotal = 0.0;
    VisitsCnt = AbonementsCnt = 0;
    VisitsCntTotal = AbonementsCntTotal = 0;
}
//---------------------------------------------------------------------------
void __fastcall TrepVisitsForm::QRCoachPrint(TObject *sender,
      AnsiString &Value)
{
    char ch = Value[1];

    switch(ch)
    {
case 'H':
        QRCoach->Font->Style = TFontStyles() << fsBold << fsItalic;
        Value = ((AnsiString *)pPrint->Items[QRlines->Index])[0]; break;
case 'I':
        QRCoach->Font->Style = TFontStyles() << fsBold;
        Value = ((AnsiString *)pPrint->Items[QRlines->Index])[0]; break;
default:
        Value = "";
    }
}
//---------------------------------------------------------------------------
void __fastcall TrepVisitsForm::QRVisitPrint(TObject *sender,
      AnsiString &Value)
{
    char ch = Value[1];

    switch(ch)
    {
case 'H':
case 'L':
        QRVisit->Font->Style = TFontStyles();
        Value = ((AnsiString *)pPrint->Items[QRlines->Index])[2];
        if(Value.Length() > 0)
        {
            unsigned pos = Value.Pos("(");
            VisitsSum += atof(Value.SubString(1,pos-2).c_str());
            VisitsCnt += atoi(Value.SubString(pos+1,Value.Length()-pos-1).c_str());

            if(!ShowCounters)
                Value = Value.SubString(1,pos-2);
        }
        break;
case 'I':
        QRVisit->Font->Style = TFontStyles() << fsBold;
        VisitsSumTotal += VisitsSum;
        VisitsCntTotal += VisitsCnt;
        if(VisitsSum != 0.0)
            Value = FormatFloat(MoneyFormat,VisitsSum) + " (" + (AnsiString)VisitsCnt + ")";
        else
            Value = "";
     
        VisitsSum = 0.0;
        VisitsCnt = 0;
        break;
default:
        Value = "";
    }
}
//---------------------------------------------------------------------------
void __fastcall TrepVisitsForm::QRAbonementPrint(TObject *sender,
      AnsiString &Value)
{
    char ch = Value[1];

    switch(ch)
    {
case 'H':
case 'L':
        QRAbonement->Font->Style = TFontStyles();
        Value = ((AnsiString *)pPrint->Items[QRlines->Index])[3];
        if(Value.Length() > 0)
        {
            unsigned pos = Value.Pos("(");
            AbonementsSum += atof(Value.SubString(1,pos-2).c_str());
            AbonementsCnt += atoi(Value.SubString(pos+1,Value.Length()-pos-1).c_str());

            if(!ShowCounters)
                Value = Value.SubString(1,pos-2);
        }
        break;
case 'I':
        QRAbonement->Font->Style = TFontStyles() << fsBold;
        AbonementsSumTotal += AbonementsSum;
        AbonementsCntTotal += AbonementsCnt;
        if(AbonementsSum != 0.0)
            Value = FormatFloat(MoneyFormat,AbonementsSum) + " (" + (AnsiString)AbonementsCnt + ")";
        else
            Value = "";

        AbonementsSum = 0.0;
        AbonementsCnt = 0;
        break;
default:
        Value = "";
    }
}
//---------------------------------------------------------------------------
void __fastcall TrepVisitsForm::QRClientPrint(TObject *sender,
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

