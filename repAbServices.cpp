//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "repAbServices.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TrepAbServicesForm *repAbServicesForm;

extern const char *MoneyFormat;
//---------------------------------------------------------------------------
__fastcall TrepAbServicesForm::TrepAbServicesForm(TComponent* Owner)
    : TForm(Owner)
{
    PageNumber = 0;
    fCol = true;

    Total0 = Total1 = Total2 = Total3 = Total4 = Total5 = Total6 = Total7 = Total8 = 0.0;
}
//---------------------------------------------------------------------------
void __fastcall TrepAbServicesForm::QRlinesBeforePrint(
      TQRCustomBand *Sender, bool &PrintBand)
{
    char ch = (QRlines->Items->Strings[QRlines->Index])[1];

    if(ch == 'H')
    {
        fCol = true;

        QRlines->Color = clSilver;
        QRFirst->Color = clSilver;
        QRCoach0->Color = clSilver;
        QRCoach1->Color = clSilver;
        QRCoach2->Color = clSilver;
        QRCoach3->Color = clSilver;
        QRCoach4->Color = clSilver;
        QRCoach5->Color = clSilver;
        QRCoach6->Color = clSilver;
        QRCoach7->Color = clSilver;
        QRCoach8->Color = clSilver;
    }
    else if(ch == 'C')
    {
        if(!fCol )
        {
            QRlines->Color = clBtnFace;
            QRFirst->Color = clBtnFace;
            QRCoach0->Color = clBtnFace;
            QRCoach1->Color = clBtnFace;
            QRCoach2->Color = clBtnFace;
            QRCoach3->Color = clBtnFace;
            QRCoach4->Color = clBtnFace;
            QRCoach5->Color = clBtnFace;
            QRCoach6->Color = clBtnFace;
            QRCoach7->Color = clBtnFace;
            QRCoach8->Color = clBtnFace;
        }
        else
        {
            QRlines->Color = clWhite;
            QRFirst->Color = clWhite;
            QRCoach0->Color = clWhite;
            QRCoach1->Color = clWhite;
            QRCoach2->Color = clWhite;
            QRCoach3->Color = clWhite;
            QRCoach4->Color = clWhite;
            QRCoach5->Color = clWhite;
            QRCoach6->Color = clWhite;
            QRCoach7->Color = clWhite;
            QRCoach8->Color = clWhite;
        }

        fCol = !fCol;
    }
    else
    {
        QRlines->Color = clWhite;
        QRFirst->Color = clWhite;
        QRCoach0->Color = clWhite;
        QRCoach1->Color = clWhite;
        QRCoach2->Color = clWhite;
        QRCoach3->Color = clWhite;
        QRCoach4->Color = clWhite;
        QRCoach5->Color = clWhite;
        QRCoach6->Color = clWhite;
        QRCoach7->Color = clWhite;
        QRCoach8->Color = clWhite;
    }

   

    //QuickRep1->NewPage();
}
//---------------------------------------------------------------------------
void __fastcall TrepAbServicesForm::QRCoach0Print(TObject *sender,
      AnsiString &Value)
{
    char ch = Value[1];

    if(ch == 'H')
    {
        //QRCoach0->Font->Style = TFontStyles() << fsBold;
        //QRlines->Color = clSilver;
        //QRFirst->Color = clSilver;
        //QRCoach0->Color = clSilver;
        //QRCoach1->Color = clSilver;
        //QRCoach2->Color = clSilver;
        //QRCoach3->Color = clSilver;
        //QRCoach4->Color = clSilver;
        //QRCoach5->Color = clSilver;
        //QRCoach6->Color = clSilver;
        //QRCoach7->Color = clSilver;
        //QRCoach8->Color = clSilver;
        //unsigned i = atoi(Value.c_str()+1);

        //Value = (((AnsiString *)pPrint->Items[QRlines->Index])[1]);
        Value = "";
    }
    else if(ch == 'S')
    {
        QRCoach0->Font->Style = TFontStyles() << fsBold;
        //QRlines->Color = clWhite;
        //QRFirst->Color = clWhite;
        //QRCoach0->Color = clWhite;
        //QRCoach1->Color = clWhite;
        //QRCoach2->Color = clWhite;
        //QRCoach3->Color = clWhite;
        //QRCoach4->Color = clWhite;
        //QRCoach5->Color = clWhite;
        //QRCoach6->Color = clWhite;
        //QRCoach7->Color = clWhite;
        //QRCoach8->Color = clWhite;

        //unsigned i = atoi(Value.c_str()+1);

        Value = (((AnsiString *)pPrint->Items[QRlines->Index])[0]);
    }
    else if(ch == 'C')
    {
        QRCoach0->Font->Style = TFontStyles();
        //QRlines->Color = clWhite;
        //QRFirst->Color = clWhite;
        //QRCoach0->Color = clWhite;
        //QRCoach1->Color = clWhite;
        //QRCoach2->Color = clWhite;
        //QRCoach3->Color = clWhite;
        //QRCoach4->Color = clWhite;
        //QRCoach5->Color = clWhite;
        //QRCoach6->Color = clWhite;
        //QRCoach7->Color = clWhite;
        //QRCoach8->Color = clWhite;
        //unsigned i = atoi(Value.c_str()+1);
        Value = ((AnsiString *)pPrint->Items[QRlines->Index])[1];
        //unsigned pos = Value.Pos("(");
        //if(pos > 0)
        //{
        double d = atof(Value.c_str());
        Sum0 += d;
        Total0 += d;
        //}

    }
    else if(ch == 'I')
    {
        if(Sum0 != 0.0)
        {
            QRCoach0->Font->Style = TFontStyles() << fsBold;
            Value = FormatFloat(MoneyFormat,Sum0);
            Sum0 = 0.0;
        }
        else
            Value = "";
    }
    else
    {
        //QRCoach0->Font->Style = TFontStyles();
        //QRCoach0->Color = clWhite;
        Value = "";
    }
}
//---------------------------------------------------------------------------
void __fastcall TrepAbServicesForm::QRPagePrint(TObject *sender,
      AnsiString &Value)
{
    Value = "Страница " + (AnsiString)PageNumber;
}
//---------------------------------------------------------------------------
void __fastcall TrepAbServicesForm::QuickRep1StartPage(
      TCustomQuickRep *Sender)
{
    PageNumber++;
}
//---------------------------------------------------------------------------

void __fastcall TrepAbServicesForm::QRFirstPrint(TObject *sender,
      AnsiString &Value)
{
    char ch = Value[1];

    if(ch == 'H')
    {
        QRFirst->Font->Style = TFontStyles() << fsBold;

        Value = "Клиент \\ Тренер";
    }
    else if(ch == 'S')
    {
        QRFirst->Font->Style = TFontStyles() << fsBold;

        //unsigned i = atoi(Value.c_str()+1);

        //Value = (((AnsiString *)pPrint->Items[i])[0]);
        Value = "Посещение:";
    }
    else if(ch == 'C')
    {
        QRFirst->Font->Style = TFontStyles();
        unsigned i = atoi(Value.c_str()+1);

        Value = (((AnsiString *)pPrint->Items[i])[0]);
    }
    else if(ch == 'I')
    {
        QRFirst->Font->Style = TFontStyles() << fsBold;
        Value = "Итого:";

    }
    else
    {
        QRFirst->Font->Style = TFontStyles();

        Value = "";
    }
}
//---------------------------------------------------------------------------
void __fastcall TrepAbServicesForm::QRCoach1Print(TObject *sender,
      AnsiString &Value)
{
    char ch = Value[1];

    if(ch == 'H')
    {
        QRCoach1->Font->Style = TFontStyles() << fsBold;
        //QRlines->Color = clSilver;
        //QRFirst->Color = clSilver;
        //QRCoach0->Color = clSilver;
        //QRCoach1->Color = clSilver;
        //QRCoach2->Color = clSilver;
        //QRCoach3->Color = clSilver;
        //QRCoach4->Color = clSilver;
        //QRCoach5->Color = clSilver;
        //QRCoach6->Color = clSilver;
        //QRCoach7->Color = clSilver;
        //QRCoach8->Color = clSilver;
        //unsigned i = atoi(Value.c_str()+1);

        Value = (((AnsiString *)pPrint->Items[QRlines->Index])[2]);
    }
    else if(ch == 'S')
    {
        //QRlines->Color = clWhite;
        //QRFirst->Color = clWhite;
        //QRCoach0->Color = clWhite;
        //QRCoach1->Color = clWhite;
        //QRCoach2->Color = clWhite;
        //QRCoach3->Color = clWhite;
        //QRCoach4->Color = clWhite;
        //QRCoach5->Color = clWhite;
        //QRCoach6->Color = clWhite;
        //QRCoach7->Color = clWhite;
        //QRCoach8->Color = clWhite;

        //unsigned i = atoi(Value.c_str()+1);

        Value = "";
    }
    else if(ch == 'C')
    {
        QRCoach1->Font->Style = TFontStyles();

        Value = ((AnsiString *)pPrint->Items[QRlines->Index])[2];
        //unsigned pos = Value.Pos("(");
        //if(pos > 0)
        //{
        double d = atof(Value.c_str());
        Sum1 += d;
        Total1 += d;
        //}
    }
    else if(ch == 'I')
    {
        if(Sum1 != 0.0)
        {
            QRCoach1->Font->Style = TFontStyles() << fsBold;
            Value = FormatFloat(MoneyFormat,Sum1);
            Sum1 = 0.0;
        }
        else
            Value = "";
    }
    else
    {
        //QRCoach1->Font->Style = TFontStyles();
        //QRlines->Color = clWhite;
        //QRFirst->Color = clWhite;
        //QRCoach0->Color = clWhite;
        //QRCoach1->Color = clWhite;
        //QRCoach2->Color = clWhite;
        //QRCoach3->Color = clWhite;
        //QRCoach4->Color = clWhite;
        //QRCoach5->Color = clWhite;
        //QRCoach6->Color = clWhite;
        //QRCoach7->Color = clWhite;
        //QRCoach8->Color = clWhite;

        Value = "";
    }
}
//---------------------------------------------------------------------------

void __fastcall TrepAbServicesForm::QRCoach2Print(TObject *sender,
      AnsiString &Value)
{
    char ch = Value[1];

    if(ch == 'H')
    {
        QRCoach2->Font->Style = TFontStyles() << fsBold;
        //QRlines->Color = clSilver;
        //QRFirst->Color = clSilver;
        //QRCoach0->Color = clSilver;
        //QRCoach1->Color = clSilver;
        //QRCoach2->Color = clSilver;
        //QRCoach3->Color = clSilver;
        //QRCoach4->Color = clSilver;
        //QRCoach5->Color = clSilver;
        //QRCoach6->Color = clSilver;
        //QRCoach7->Color = clSilver;
        //QRCoach8->Color = clSilver;
        //unsigned i = atoi(Value.c_str()+1);

        Value = (((AnsiString *)pPrint->Items[QRlines->Index])[3]);
    }
    else if(ch == 'S')
    {
        //QRlines->Color = clWhite;
        //QRFirst->Color = clWhite;
        //QRCoach0->Color = clWhite;
        //QRCoach1->Color = clWhite;
        //QRCoach2->Color = clWhite;
        //QRCoach3->Color = clWhite;
        //QRCoach4->Color = clWhite;
        //QRCoach5->Color = clWhite;
        //QRCoach6->Color = clWhite;
        //QRCoach7->Color = clWhite;
        //QRCoach8->Color = clWhite;

        //unsigned i = atoi(Value.c_str()+1);

        Value = "";
    }
    else if(ch == 'C')
    {
        QRCoach2->Font->Style = TFontStyles();

        Value = ((AnsiString *)pPrint->Items[QRlines->Index])[3];
        //unsigned pos = Value.Pos("(");
        //if(pos > 0)
        //{
        double d = atof(Value.c_str());
        Sum2 += d;
        Total2 += d;
        //}

    }
    else if(ch == 'I')
    {
        if(Sum2 != 0.0)
        {
            QRCoach2->Font->Style = TFontStyles() << fsBold;
            Value = FormatFloat(MoneyFormat,Sum2);
            Sum2 = 0.0;
        }
        else
            Value = "";
    }
    else
    {
        //QRCoach2->Font->Style = TFontStyles();
        //QRlines->Color = clWhite;
        //QRFirst->Color = clWhite;
        //QRCoach0->Color = clWhite;
        //QRCoach1->Color = clWhite;
        //QRCoach2->Color = clWhite;
        //QRCoach3->Color = clWhite;
        //QRCoach4->Color = clWhite;
        //QRCoach5->Color = clWhite;
        //QRCoach6->Color = clWhite;
        //QRCoach7->Color = clWhite;
        //QRCoach8->Color = clWhite;

        Value = "";
    }
}
//---------------------------------------------------------------------------

void __fastcall TrepAbServicesForm::QRCoach3Print(TObject *sender,
      AnsiString &Value)
{
    char ch = Value[1];

    if(ch == 'H')
    {
        QRCoach3->Font->Style = TFontStyles() << fsBold;
        //QRlines->Color = clSilver;
        //QRFirst->Color = clSilver;
        //QRCoach0->Color = clSilver;
        //QRCoach1->Color = clSilver;
        //QRCoach2->Color = clSilver;
        //QRCoach3->Color = clSilver;
        //QRCoach4->Color = clSilver;
        //QRCoach5->Color = clSilver;
        //QRCoach6->Color = clSilver;
        //QRCoach7->Color = clSilver;
        //QRCoach8->Color = clSilver;
        //unsigned i = atoi(Value.c_str()+1);

        Value = (((AnsiString *)pPrint->Items[QRlines->Index])[4]);
    }
    else if(ch == 'S')
    {
        //QRlines->Color = clWhite;
        //QRFirst->Color = clWhite;
        //QRCoach0->Color = clWhite;
        //QRCoach1->Color = clWhite;
        //QRCoach2->Color = clWhite;
        //QRCoach3->Color = clWhite;
        //QRCoach4->Color = clWhite;
        //QRCoach5->Color = clWhite;
        //QRCoach6->Color = clWhite;
        //QRCoach7->Color = clWhite;
        //QRCoach8->Color = clWhite;

        //unsigned i = atoi(Value.c_str()+1);

        Value = "";
    }
    else if(ch == 'C')
    {
        QRCoach3->Font->Style = TFontStyles();

        Value = ((AnsiString *)pPrint->Items[QRlines->Index])[4];
        //unsigned pos = Value.Pos("(");
        //if(pos > 0)
        //{
        double d = atof(Value.c_str());
        Sum3 += d;
        Total3 += d;
        //}
    }
    else if(ch == 'I')
    {
        if(Sum3 != 0.0)
        {
            QRCoach3->Font->Style = TFontStyles() << fsBold;
            Value = FormatFloat(MoneyFormat,Sum3);
            Sum3 = 0.0;
        }
        else
            Value = "";
    }
    else
    {
        //QRCoach3->Font->Style = TFontStyles();
        //QRlines->Color = clWhite;
        //QRFirst->Color = clWhite;
        //QRCoach0->Color = clWhite;
        //QRCoach1->Color = clWhite;
        //QRCoach2->Color = clWhite;
        //QRCoach3->Color = clWhite;
        //QRCoach4->Color = clWhite;
        //QRCoach5->Color = clWhite;
        //QRCoach6->Color = clWhite;
        //QRCoach7->Color = clWhite;
        //QRCoach8->Color = clWhite;

        Value = "";
    }
}
//---------------------------------------------------------------------------

void __fastcall TrepAbServicesForm::QRCoach4Print(TObject *sender,
      AnsiString &Value)
{
    char ch = Value[1];

    if(ch == 'H')
    {
        QRCoach4->Font->Style = TFontStyles() << fsBold;
        //QRlines->Color = clSilver;
        //QRFirst->Color = clSilver;
        //QRCoach0->Color = clSilver;
        //QRCoach1->Color = clSilver;
        //QRCoach2->Color = clSilver;
        //QRCoach3->Color = clSilver;
        //QRCoach4->Color = clSilver;
        //QRCoach5->Color = clSilver;
        //QRCoach6->Color = clSilver;
        //QRCoach7->Color = clSilver;
        //QRCoach8->Color = clSilver;
        //unsigned i = atoi(Value.c_str()+1);

        Value = (((AnsiString *)pPrint->Items[QRlines->Index])[5]);
    }
    else if(ch == 'S')
    {
        //QRlines->Color = clWhite;
        //QRFirst->Color = clWhite;
        //QRCoach0->Color = clWhite;
        //QRCoach1->Color = clWhite;
        //QRCoach2->Color = clWhite;
        //QRCoach3->Color = clWhite;
        //QRCoach4->Color = clWhite;
        //QRCoach5->Color = clWhite;
        //QRCoach6->Color = clWhite;
        //QRCoach7->Color = clWhite;
        //QRCoach8->Color = clWhite;

        //unsigned i = atoi(Value.c_str()+1);

        Value = "";
    }
    else if(ch == 'C')
    {
        QRCoach4->Font->Style = TFontStyles();

        Value = ((AnsiString *)pPrint->Items[QRlines->Index])[5];
        //unsigned pos = Value.Pos("(");
        //if(pos > 0)
        //{
        double d = atof(Value.c_str());
        Sum4 += d;
        Total4 += d;
        //}
    }
    else if(ch == 'I')
    {
        if(Sum4 != 0.0)
        {
            QRCoach4->Font->Style = TFontStyles() << fsBold;
            Value = FormatFloat(MoneyFormat,Sum4);
            Sum4 = 0.0;
        }
        else
            Value = "";
    }
    else
    {
        //QRCoach4->Font->Style = TFontStyles();
        //QRlines->Color = clWhite;
        //QRFirst->Color = clWhite;
        //QRCoach0->Color = clWhite;
        //QRCoach1->Color = clWhite;
        //QRCoach2->Color = clWhite;
        //QRCoach3->Color = clWhite;
        //QRCoach4->Color = clWhite;
        //QRCoach5->Color = clWhite;
        //QRCoach6->Color = clWhite;
        //QRCoach7->Color = clWhite;
        //QRCoach8->Color = clWhite;

        Value = "";
    }
}
//---------------------------------------------------------------------------

void __fastcall TrepAbServicesForm::QRCoach5Print(TObject *sender,
      AnsiString &Value)
{
    char ch = Value[1];

    if(ch == 'H')
    {
        QRCoach5->Font->Style = TFontStyles() << fsBold;
        //QRlines->Color = clSilver;
        //QRFirst->Color = clSilver;
        //QRCoach0->Color = clSilver;
        //QRCoach1->Color = clSilver;
        //QRCoach2->Color = clSilver;
        //QRCoach3->Color = clSilver;
        //QRCoach4->Color = clSilver;
        //QRCoach5->Color = clSilver;
        //QRCoach6->Color = clSilver;
        //QRCoach7->Color = clSilver;
        //QRCoach8->Color = clSilver;
        //unsigned i = atoi(Value.c_str()+1);

        Value = (((AnsiString *)pPrint->Items[QRlines->Index])[6]);
    }
    else if(ch == 'S')
    {
        //QRlines->Color = clWhite;
        //QRFirst->Color = clWhite;
        //QRCoach0->Color = clWhite;
        //QRCoach1->Color = clWhite;
        //QRCoach2->Color = clWhite;
        //QRCoach3->Color = clWhite;
        //QRCoach4->Color = clWhite;
        //QRCoach5->Color = clWhite;
        //QRCoach6->Color = clWhite;
        //QRCoach7->Color = clWhite;
        //QRCoach8->Color = clWhite;

        //unsigned i = atoi(Value.c_str()+1);

        Value = "";
    }
    else if(ch == 'C')
    {
        QRCoach5->Font->Style = TFontStyles();

        Value = ((AnsiString *)pPrint->Items[QRlines->Index])[6];
        //unsigned pos = Value.Pos("(");
        //if(pos > 0)
        //{
        double d = atof(Value.c_str());
        Sum5 += d;
        Total5 += d;
        //}
    }
    else if(ch == 'I')
    {
        if(Sum5 != 0.0)
        {
            QRCoach5->Font->Style = TFontStyles() << fsBold;
            Value = FormatFloat(MoneyFormat,Sum5);
            Sum5 = 0.0;
        }
        else
            Value = "";
    }
    else
    {
        //QRCoach5->Font->Style = TFontStyles();
        //QRlines->Color = clWhite;
        //QRFirst->Color = clWhite;
        //QRCoach0->Color = clWhite;
        //QRCoach1->Color = clWhite;
        //QRCoach2->Color = clWhite;
        //QRCoach3->Color = clWhite;
        //QRCoach4->Color = clWhite;
        //QRCoach5->Color = clWhite;
        //QRCoach6->Color = clWhite;
        //QRCoach7->Color = clWhite;
        //QRCoach8->Color = clWhite;

        Value = "";
    }
}
//---------------------------------------------------------------------------

void __fastcall TrepAbServicesForm::QRCoach6Print(TObject *sender,
      AnsiString &Value)
{
    char ch = Value[1];

    if(ch == 'H')
    {
        QRCoach6->Font->Style = TFontStyles() << fsBold;
        //QRlines->Color = clSilver;
        //QRFirst->Color = clSilver;
        //QRCoach0->Color = clSilver;
        //QRCoach1->Color = clSilver;
        //QRCoach2->Color = clSilver;
        //QRCoach3->Color = clSilver;
        //QRCoach4->Color = clSilver;
        //QRCoach5->Color = clSilver;
        //QRCoach6->Color = clSilver;
        //QRCoach7->Color = clSilver;
        //QRCoach8->Color = clSilver;
        //unsigned i = atoi(Value.c_str()+1);

        Value = (((AnsiString *)pPrint->Items[QRlines->Index])[7]);
    }
    else if(ch == 'S')
    {
        //QRlines->Color = clWhite;
        //QRFirst->Color = clWhite;
        //QRCoach0->Color = clWhite;
        //QRCoach1->Color = clWhite;
        //QRCoach2->Color = clWhite;
        //QRCoach3->Color = clWhite;
        //QRCoach4->Color = clWhite;
        //QRCoach5->Color = clWhite;
        //QRCoach6->Color = clWhite;
        //QRCoach7->Color = clWhite;
        //QRCoach8->Color = clWhite;

        //unsigned i = atoi(Value.c_str()+1);

        Value = "";
    }
    else if(ch == 'C')
    {
        QRCoach6->Font->Style = TFontStyles();

        Value = ((AnsiString *)pPrint->Items[QRlines->Index])[7];
        //unsigned pos = Value.Pos("(");
        //if(pos > 0)
        //{
        double d = atof(Value.c_str());
        Sum6 += d;
        Total6 += d;
        //}
    }
    else if(ch == 'I')
    {
        if(Sum6 != 0.0)
        {
            QRCoach6->Font->Style = TFontStyles() << fsBold;
            Value = FormatFloat(MoneyFormat,Sum6);
            Sum6 = 0.0;
        }
        else
            Value = "";
    }
    else
    {
        //QRCoach6->Font->Style = TFontStyles();
        //QRlines->Color = clWhite;
        //QRFirst->Color = clWhite;
        //QRCoach0->Color = clWhite;
        //QRCoach1->Color = clWhite;
        //QRCoach2->Color = clWhite;
        //QRCoach3->Color = clWhite;
        //QRCoach4->Color = clWhite;
        //QRCoach5->Color = clWhite;
        //QRCoach6->Color = clWhite;
        //QRCoach7->Color = clWhite;
        //QRCoach8->Color = clWhite;

        Value = "";
    }
}
//---------------------------------------------------------------------------

void __fastcall TrepAbServicesForm::QRCoach7Print(TObject *sender,
      AnsiString &Value)
{
    char ch = Value[1];

    if(ch == 'H')
    {
        QRCoach7->Font->Style = TFontStyles() << fsBold;
        //QRlines->Color = clSilver;
        //QRFirst->Color = clSilver;
        //QRCoach0->Color = clSilver;
        //QRCoach1->Color = clSilver;
        //QRCoach2->Color = clSilver;
        //QRCoach3->Color = clSilver;
        //QRCoach4->Color = clSilver;
        //QRCoach5->Color = clSilver;
        //QRCoach6->Color = clSilver;
        //QRCoach7->Color = clSilver;
        //QRCoach8->Color = clSilver;
        //unsigned i = atoi(Value.c_str()+1);

        Value = (((AnsiString *)pPrint->Items[QRlines->Index])[8]);
    }
    else if(ch == 'S')
    {
        //QRlines->Color = clWhite;
        //QRFirst->Color = clWhite;
        //QRCoach0->Color = clWhite;
        //QRCoach1->Color = clWhite;
        //QRCoach2->Color = clWhite;
        //QRCoach3->Color = clWhite;
        //QRCoach4->Color = clWhite;
        //QRCoach5->Color = clWhite;
        //QRCoach6->Color = clWhite;
        //QRCoach7->Color = clWhite;
        //QRCoach8->Color = clWhite;

        //unsigned i = atoi(Value.c_str()+1);

        Value = "";
    }
    else if(ch == 'C')
    {
         QRCoach7->Font->Style = TFontStyles();

        Value = ((AnsiString *)pPrint->Items[QRlines->Index])[8];
        //unsigned pos = Value.Pos("(");
        //if(pos > 0)
        //{
        double d = atof(Value.c_str());
        Sum7 += d;
        Total7 += d;
        //}
    }
    else if(ch == 'I')
    {
        if(Sum7 != 0.0)
        {
            QRCoach7->Font->Style = TFontStyles() << fsBold;
            Value = FormatFloat(MoneyFormat,Sum7);
            Sum7 = 0.0;
        }
        else
            Value = "";
    }
    else
    {
        //QRCoach7->Font->Style = TFontStyles();
        //QRlines->Color = clWhite;
        //QRFirst->Color = clWhite;
        //QRCoach0->Color = clWhite;
        //QRCoach1->Color = clWhite;
        //QRCoach2->Color = clWhite;
        //QRCoach3->Color = clWhite;
        //QRCoach4->Color = clWhite;
        //QRCoach5->Color = clWhite;
        //QRCoach6->Color = clWhite;
        //QRCoach7->Color = clWhite;
        //QRCoach8->Color = clWhite;

        Value = "";
    }
}
//---------------------------------------------------------------------------

void __fastcall TrepAbServicesForm::QRCoach8Print(TObject *sender,
      AnsiString &Value)
{
    char ch = Value[1];

    if(ch == 'H')
    {
        QRCoach8->Font->Style = TFontStyles() << fsBold;
        //QRlines->Color = clSilver;
        //QRFirst->Color = clSilver;
        //QRCoach0->Color = clSilver;
        //QRCoach1->Color = clSilver;
        //QRCoach2->Color = clSilver;
        //QRCoach3->Color = clSilver;
        //QRCoach4->Color = clSilver;
        //QRCoach5->Color = clSilver;
        //QRCoach6->Color = clSilver;
        //QRCoach7->Color = clSilver;
        //QRCoach8->Color = clSilver;
        //unsigned i = atoi(Value.c_str()+1);

        Value = (((AnsiString *)pPrint->Items[QRlines->Index])[9]);
    }
    else if(ch == 'S')
    {
        //QRlines->Color = clWhite;
        //QRFirst->Color = clWhite;
        //QRCoach0->Color = clWhite;
        //QRCoach1->Color = clWhite;
        //QRCoach2->Color = clWhite;
        //QRCoach3->Color = clWhite;
        //QRCoach4->Color = clWhite;
        //QRCoach5->Color = clWhite;
        //QRCoach6->Color = clWhite;
        //QRCoach7->Color = clWhite;
        //QRCoach8->Color = clWhite;

        //unsigned i = atoi(Value.c_str()+1);

        Value = "";
    }
    else if(ch == 'C')
    {
        QRCoach8->Font->Style = TFontStyles();

        Value = ((AnsiString *)pPrint->Items[QRlines->Index])[9];
        //unsigned pos = Value.Pos("(");
        //if(pos > 0)
        //{
        double d = atof(Value.c_str());
        Sum8 += d;
        Total8 += d;
        //}
    }
    else if(ch == 'I')
    {
        if(Sum8 != 0.0)
        {
            QRCoach8->Font->Style = TFontStyles() << fsBold;
            Value = FormatFloat(MoneyFormat,Sum8);
            Sum8 = 0.0;
        }
        else
            Value = "";
    }
    else
    {
        //QRCoach8->Font->Style = TFontStyles();
        //QRlines->Color = clWhite;
        //QRFirst->Color = clWhite;
        //QRCoach0->Color = clWhite;
        //QRCoach1->Color = clWhite;
        //QRCoach2->Color = clWhite;
        //QRCoach3->Color = clWhite;
        //QRCoach4->Color = clWhite;
        //QRCoach5->Color = clWhite;
        //QRCoach6->Color = clWhite;
        //QRCoach7->Color = clWhite;
        //QRCoach8->Color = clWhite;

        Value = "";
    }
}
//---------------------------------------------------------------------------
void __fastcall TrepAbServicesForm::QRCoach0SumPrint(TObject *sender,
      AnsiString &Value)
{
    Value = FormatFloat(MoneyFormat,Total0);
}
//---------------------------------------------------------------------------


void __fastcall TrepAbServicesForm::QRCoach1SumPrint(TObject *sender,
      AnsiString &Value)
{
    Value = FormatFloat(MoneyFormat,Total1);    
}
//---------------------------------------------------------------------------

void __fastcall TrepAbServicesForm::QRCoach2SumPrint(TObject *sender,
      AnsiString &Value)
{
    Value = FormatFloat(MoneyFormat,Total2);    
}
//---------------------------------------------------------------------------

void __fastcall TrepAbServicesForm::QRCoach3SumPrint(TObject *sender,
      AnsiString &Value)
{
    Value = FormatFloat(MoneyFormat,Total3);    
}
//---------------------------------------------------------------------------

void __fastcall TrepAbServicesForm::QRCoach4SumPrint(TObject *sender,
      AnsiString &Value)
{
    Value = FormatFloat(MoneyFormat,Total4);    
}
//---------------------------------------------------------------------------

void __fastcall TrepAbServicesForm::QRCoach5SumPrint(TObject *sender,
      AnsiString &Value)
{
    Value = FormatFloat(MoneyFormat,Total5);    
}
//---------------------------------------------------------------------------

void __fastcall TrepAbServicesForm::QRCoach6SumPrint(TObject *sender,
      AnsiString &Value)
{
    Value = FormatFloat(MoneyFormat,Total6);    
}
//---------------------------------------------------------------------------

void __fastcall TrepAbServicesForm::QRCoach7SumPrint(TObject *sender,
      AnsiString &Value)
{
    Value = FormatFloat(MoneyFormat,Total7);    
}
//---------------------------------------------------------------------------

void __fastcall TrepAbServicesForm::QRCoach8SumPrint(TObject *sender,
      AnsiString &Value)
{
    Value = FormatFloat(MoneyFormat,Total8);
}
//---------------------------------------------------------------------------


