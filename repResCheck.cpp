//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "repResCheck.h"
#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TrepResCheckForm *repResCheckForm;

extern const char *MoneyFormat;
extern const char *MoneyWideFormat;
//---------------------------------------------------------------------------
__fastcall TrepResCheckForm::TrepResCheckForm(TComponent* Owner)
    : TForm(Owner)
{
    fCol = true;
}
//---------------------------------------------------------------------------
void __fastcall TrepResCheckForm::QRPagePrint(TObject *sender,
      AnsiString &Value)
{
    Value = "Страница " + (AnsiString)QuickRep1->PageNumber;
}
//---------------------------------------------------------------------------
void __fastcall TrepResCheckForm::QRDatePrint(TObject *sender,
      AnsiString &Value)
{
    unsigned i = Value.ToInt();

    Value = MainForm->pResCheck[i].pDate;
}
//---------------------------------------------------------------------------
void __fastcall TrepResCheckForm::QRUserPrint(TObject *sender,
      AnsiString &Value)
{
    unsigned i = Value.ToInt();

    Value = MainForm->pResCheck[i].pUser;
}
//---------------------------------------------------------------------------
void __fastcall TrepResCheckForm::QRCDatePrint(TObject *sender,
      AnsiString &Value)
{
    unsigned i = Value.ToInt();

    Value = MainForm->pResCheck[i].pCDate;    
}
//---------------------------------------------------------------------------
void __fastcall TrepResCheckForm::QRGroupPrint(TObject *sender,
      AnsiString &Value)
{
    unsigned i = Value.ToInt();

    Value = MainForm->pResCheck[i].pGroup;    
}
//---------------------------------------------------------------------------
void __fastcall TrepResCheckForm::QRClientPrint(TObject *sender,
      AnsiString &Value)
{
    unsigned i = Value.ToInt();

    Value = MainForm->pResCheck[i].pClient;    
}
//---------------------------------------------------------------------------
void __fastcall TrepResCheckForm::QRServicePrint(TObject *sender,
      AnsiString &Value)
{
    unsigned i = Value.ToInt();

    Value = MainForm->pResCheck[i].pService;    
}
//---------------------------------------------------------------------------
void __fastcall TrepResCheckForm::QRStatusPrint(TObject *sender,
      AnsiString &Value)
{
    unsigned i = Value.ToInt();

    Value = MainForm->pResCheck[i].pStatus;
}
//---------------------------------------------------------------------------
void __fastcall TrepResCheckForm::QRDeletedPrint(TObject *sender,
      AnsiString &Value)
{
    unsigned i = Value.ToInt();

    Value = MainForm->pResCheck[i].pDeleted;
}
//---------------------------------------------------------------------------
void __fastcall TrepResCheckForm::QRlinesBeforePrint(TQRCustomBand *Sender,
      bool &PrintBand)
{
    if(!fCol)
    {
        QRlines->Color = clBtnFace;
        QRDate->Color = clBtnFace;
        QRUser->Color = clBtnFace;
        QRCDate->Color = clBtnFace;
        QRGroup->Color = clBtnFace;
        QRClient->Color = clBtnFace;
        QRService->Color = clBtnFace;
        QRStatus->Color = clBtnFace;
        QRDeleted->Color = clBtnFace;
    }
    else
    {
        QRlines->Color = clWhite;
        QRDate->Color = clWhite;
        QRUser->Color = clWhite;
        QRCDate->Color = clWhite;
        QRGroup->Color = clWhite;
        QRClient->Color = clWhite;
        QRService->Color = clWhite;
        QRStatus->Color = clWhite;
        QRDeleted->Color = clWhite;
    }

    fCol = !fCol;
}
//---------------------------------------------------------------------------

