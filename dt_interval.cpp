//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "dt_interval.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDateIntervalForm *DateIntervalForm;

TDateTime DTI_BegDate = 0;
TDateTime DTI_EndDate = 0;

extern int FormResult;
//---------------------------------------------------------------------------
__fastcall TDateIntervalForm::TDateIntervalForm(TComponent* Owner)
    : TForm(Owner)
{
    if((int)DTI_BegDate == 0)
    {
        DTI_BegDate = Now();
        DTI_EndDate = DTI_BegDate;
    }
}
//---------------------------------------------------------------------------
void __fastcall TDateIntervalForm::Button1Click(TObject *Sender)
{
    DTI_BegDate = dtpBegDate->DateTime;
    DTI_EndDate = dtpEndDate->DateTime;

    if((int)DTI_BegDate > (int)DTI_EndDate)
    {
        Application->MessageBox("Внимание!\nНачальная дата не должна превышать конечную.","Некорректные данные",MB_OK);
        return;
    }

    FormResult = 1;
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TDateIntervalForm::Button2Click(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TDateIntervalForm::dtpEndDateExit(TObject *Sender)
{
    if(dtpEndDate->Date < dtpBegDate->Date)
        dtpEndDate->DateTime = dtpBegDate->DateTime;
}
//---------------------------------------------------------------------------
void __fastcall TDateIntervalForm::FormShow(TObject *Sender)
{
    dtpBegDate->DateTime = DTI_BegDate;
    dtpEndDate->DateTime = DTI_EndDate;
}
//---------------------------------------------------------------------------
