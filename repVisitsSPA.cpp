//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "repVisitsSPA.h"
#include "lib.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TrepVisitsSPAForm *repVisitsSPAForm;

extern const char *DBName;
extern const char *MoneyFormat;
//---------------------------------------------------------------------------
__fastcall TrepVisitsSPAForm::TrepVisitsSPAForm(TComponent* Owner)
    : TForm(Owner)
{
    VisitsSum = VisitsPSum = AbSum = 0.0;
    VisitsSumTotal = VisitsPSumTotal = AbSumTotal = 0.0;
    VisitsCnt = AbCnt = 0;
    VisitsCntTotal = AbCntTotal = 0;
    VisitsTime = VisitsTimeTotal = 0;
    AnsiString s;
    SQL_exefun(DBName,"select SettingsVal from Settings where SettingsKey='repVisitsSPACounters'",&s);
    ShowCounters = !(atoi(s.c_str()) == 0);
}
//---------------------------------------------------------------------------
void __fastcall TrepVisitsSPAForm::QRPagePrint(TObject *sender,
      AnsiString &Value)
{
    Value = "Страница " + (AnsiString)QuickRep1->PageNumber;    
}
//---------------------------------------------------------------------------
void __fastcall TrepVisitsSPAForm::QRCoachPrint(TObject *sender,
      AnsiString &Value)
{
    char ch = Value[1];

    switch(ch)
    {
case 'L':
        QRCoach->Font->Style = TFontStyles();
        Value = ((AnsiString *)pPrint->Items[QRlines->Index])[0]; break;
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
void __fastcall TrepVisitsSPAForm::QRClientPrint(TObject *sender,
      AnsiString &Value)
{
    char ch = Value[1];
    unsigned pos;
    
    FromAbs = false;

    switch(ch)
    {
case 'H':
case 'L':
        Value = ((AnsiString *)pPrint->Items[QRlines->Index])[1];
        pos = Value.Length();
        if(pos > 0)
        {
            ch = Value[pos];
            if(ch == '$')
            {
            // С абонемента
                Value.SetLength(Value.Length()-1);
                FromAbs = true;
            }
        }
        break;
default:
        Value = "";
    }    
}
//---------------------------------------------------------------------------
void __fastcall TrepVisitsSPAForm::QRlinesBeforePrint(
      TQRCustomBand *Sender, bool &PrintBand)
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
        //QRAb->Color = clSilver;
    }
    else if(fCol)
    {
        QRlines->Color = clBtnFace;
        QRCoach->Color = clBtnFace;
        QRClient->Color = clBtnFace;
        QRVisit->Color = clBtnFace;
        //QRAb->Color = clBtnFace;
    }
    else
    {
        QRlines->Color = clWhite;
        QRCoach->Color = clWhite;
        QRClient->Color = clWhite;
        QRVisit->Color = clWhite;
        //QRAb->Color = clWhite;
    }
}
//---------------------------------------------------------------------------
void __fastcall TrepVisitsSPAForm::QRVisitPrint(TObject *sender,
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
            AnsiString s = Value;
            unsigned pos = s.Pos(")");
            if(pos)
                s = s.SubString(pos+1,s.Length()-pos);

            pos = s.Pos("/");

            VisitsSum += atof(s.SubString(1,pos-1).c_str());

            s = s.SubString(pos+1,Value.Length()-pos);

            VisitsPSum += atof(s.c_str());

            VisitsCnt++;

            // Timed?
            pos = s.Pos("-");
            if(pos > 0)
                VisitsTime += atoi(s.SubString(pos+1,s.Length()-pos).c_str());
        }
        break;
case 'I':
        QRVisit->Font->Style = TFontStyles() << fsBold;
        VisitsSumTotal += VisitsSum;
        VisitsPSumTotal += VisitsPSum;
        VisitsCntTotal += VisitsCnt;
        VisitsTimeTotal += VisitsTime;

        if(VisitsSum != 0.0 || VisitsPSum != 0.0)
        {
            Value = FormatFloat(MoneyFormat,VisitsSum) + "/" + FormatFloat(MoneyFormat,VisitsPSum) + " (" + (AnsiString)VisitsCnt + ")";
            if(VisitsTime)
                Value += AnsiString(" - ") + VisitsTime;
        }
        else
            Value = "";

        VisitsSum = 0.0;
        VisitsPSum = 0.0;
        VisitsCnt = 0;
        VisitsTime = 0;

        break;
default:
        Value = "";
    }
}
//---------------------------------------------------------------------------
void __fastcall TrepVisitsSPAForm::QRVisitSumPrint(TObject *sender,
      AnsiString &Value)
{
    Value = FormatFloat(MoneyFormat,VisitsSumTotal) + "/" + FormatFloat(MoneyFormat,VisitsPSumTotal) + " (" + VisitsCntTotal + ")";
    if(VisitsTimeTotal)
        Value += AnsiString(" - ") + VisitsTimeTotal;
}
//---------------------------------------------------------------------------
void __fastcall TrepVisitsSPAForm::QRAbSumPrint(TObject *sender,
      AnsiString &Value)
{
    Value = FormatFloat(MoneyFormat,AbSumTotal) + " (" + AbCntTotal + ")";
}
//---------------------------------------------------------------------------
void __fastcall TrepVisitsSPAForm::QuickRep1BeforePrint(
      TCustomQuickRep *Sender, bool &PrintReport)
{
    VisitsSum = VisitsPSum = AbSum = 0.0;
    VisitsSumTotal = VisitsPSumTotal = AbSumTotal = 0.0;
    VisitsCnt = AbCnt = 0;
    VisitsCntTotal = AbCntTotal = 0;
    VisitsTime = VisitsTimeTotal = 0;
}
//---------------------------------------------------------------------------

