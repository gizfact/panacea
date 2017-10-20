//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "rescaltime.h"
#include <math.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TRescalTimeForm *RescalTimeForm;

extern int FormResult;
//---------------------------------------------------------------------------
__fastcall TRescalTimeForm::TRescalTimeForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TRescalTimeForm::CSpinButton1DownClick(TObject *Sender)
{
    // Вниз
    int period = 5;

    unsigned pos = Edit1->Text.Pos(":");
    int itime = 60 * atoi(Edit1->Text.c_str());
    itime += (atoi(Edit1->Text.SubString(pos+1,Edit1->Text.Length()-pos).c_str()) - period);

    if(itime < 0)
        itime += 1440;

    //double d = itime;
    //d /= 1440.0;


    Edit1->Text = Edit1->Text.sprintf("%02d:%02d",itime/60,itime%60);


}
//---------------------------------------------------------------------------
void __fastcall TRescalTimeForm::CSpinButton1UpClick(TObject *Sender)
{
    // Вверх
    int period = 5;

    unsigned pos = Edit1->Text.Pos(":");
    int itime = 60 * atoi(Edit1->Text.c_str());
    itime += (atoi(Edit1->Text.SubString(pos+1,Edit1->Text.Length()-pos).c_str()) + period);

    if(itime >= 1440)
        itime -= 1440;

    //double d = itime;
    //d /= 1440.0;

    Edit1->Text = Edit1->Text.sprintf("%02d:%02d",itime/60,itime%60);


}
//---------------------------------------------------------------------------
void __fastcall TRescalTimeForm::Button1Click(TObject *Sender)
{
    unsigned pos = Edit1->Text.Pos(":");
    int itime1 = 60 * atoi(Edit1->Text.c_str());
    if(pos > 0)
        itime1 += (atoi(Edit1->Text.SubString(pos+1,Edit1->Text.Length()-pos).c_str()));

    if(itime1 < 0)
        itime1 += 1440;

    if(CheckTime)
    {
        double x, d = itime1;
        d /= 1440.0;

        if(d < modf(Now(),&x))
        {
            Application->MessageBox("Внимание!\nНе корректное время записи.","",MB_OK);
            return;

        }
    }

    pos = Edit2->Text.Pos(":");
    int itime2 = 60 * atoi(Edit2->Text.c_str());
    if(pos > 0)
        itime2 += (atoi(Edit2->Text.SubString(pos+1,Edit2->Text.Length()-pos).c_str()));

    if(itime2 < 0)
        itime2 += 1440;

    if(itime1 >= itime2)
    {
        Application->MessageBox("Внимание!\nНе корректное время записи.","",MB_OK);
        return;
    }

    if(itime1 < 480 || itime1 > 1350)
    {
        Application->MessageBox("Внимание!\nВремя начала должно быть в интервале с 8:00 и до 22:30.","",MB_OK);

        return;

    }

    BegTime = itime1;
    //BegTime /= 1440.0;
    EndTime = itime2;
    //EndTime /= 1440.0;
    FormResult = 1;
    Close();    
}
//---------------------------------------------------------------------------
void __fastcall TRescalTimeForm::Button2Click(TObject *Sender)
{
    Close();    
}
//---------------------------------------------------------------------------
void __fastcall TRescalTimeForm::CSpinButton2DownClick(TObject *Sender)
{
    // Вниз
    int period = 5;

    unsigned pos = Edit2->Text.Pos(":");
    int itime = 60 * atoi(Edit2->Text.c_str());
    itime += (atoi(Edit2->Text.SubString(pos+1,Edit2->Text.Length()-pos).c_str()) - period);

    if(itime < 0)
        itime += 1440;

    //double d = itime;
    //d /= 1440.0;

    Edit2->Text = Edit2->Text.sprintf("%02d:%02d",itime/60,itime%60);

}
//---------------------------------------------------------------------------
void __fastcall TRescalTimeForm::CSpinButton2UpClick(TObject *Sender)
{
    // Вверх
    int period = 5;

    unsigned pos = Edit2->Text.Pos(":");
    int itime = 60 * atoi(Edit2->Text.c_str());
    itime += (atoi(Edit2->Text.SubString(pos+1,Edit2->Text.Length()-pos).c_str()) + period);

    if(itime >= 1440)
        itime -= 1440;

    //double d = itime;
    //d /= 1440.0;

    Edit2->Text = Edit2->Text.sprintf("%02d:%02d",itime/60,itime%60);
}
//---------------------------------------------------------------------------
void __fastcall TRescalTimeForm::sbQuanUpClick(TObject *Sender)
{
    int i = atoi(edQuan->Text.c_str()) + 1;

    if(i <= 0) i = 1;
    else if(i > 12) i = 12;

    edQuan->Text = i;
}
//---------------------------------------------------------------------------
void __fastcall TRescalTimeForm::sbQuanDownClick(TObject *Sender)
{
    int i = atoi(edQuan->Text.c_str()) - 1;

    if(i <= 0) i = 1;
    else if(i > 12) i = 12;

    edQuan->Text = i;
}
//---------------------------------------------------------------------------
void __fastcall TRescalTimeForm::FormShow(TObject *Sender)
{
    if(ShowQuan)
    {
        laQuan->Visible = true;
        edQuan->Visible = true;
        sbQuan->Visible = true;
    }
}
//---------------------------------------------------------------------------

