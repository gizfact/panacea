//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "abparam.h"
#include "lib.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAbParamForm *AbParamForm;

extern const char *DBName;
extern int FormResult;
extern int CurDayOfWeek;
//---------------------------------------------------------------------------
__fastcall TAbParamForm::TAbParamForm(TComponent* Owner)
    : TForm(Owner)
{
    pPersonalIDs = NULL;
    pPersonal = NULL;
    pServicesIDs = NULL;
    pServices = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TAbParamForm::FormShow(TObject *Sender)
{
    if(Tag == "SPA" || Tag == "Bath")
    {
        if(Tag == "Bath")
            laBalanse->Caption = "Абонемент в Баню";
        laBalanse->Visible = true;
        edBalanse->Visible = true;
        lbServices->Visible = false;
        lbPersonal->Visible = false;
        Label1->Visible = false;
        Label2->Visible = false;
    }
    else
    {
        edBalanse->Visible = false;
        laBalanse->Visible = false;

        unsigned cnt_services = SQL_fldKeyCollect(DBName,"Name",("from Services where bin_and(WeekDays,"+AnsiString(CurDayOfWeek)+")!=0 and Tag like '~"+(Tag)+"~%' and RowID not in (select ParentID from Services where ParentID!=0) order by Name,CDate").c_str(),&pServicesIDs,&pServices);

        for(unsigned i = 0; i < cnt_services; i++)
            lbServices->Items->Add(pServices[i]);

        lbServices->ItemIndex = lbServices->Items->IndexOf("Персональные тренировки");

        if(lbServices->ItemIndex < 0) lbServices->ItemIndex = 0;

        AnsiString retString;
        SQL_exefun(DBName,("select RowID from Services where Name='"+(Tag)+"'").c_str(),&retString);
        unsigned cnt_persons = SQL_fldKeyCollect(DBName,"Name",("from Personal where Alive!=0 and ServiceID="+AnsiString(atoi(retString.c_str()))+" order by Name").c_str(),&pPersonalIDs,&pPersonal);

        for(unsigned i = 0; i < cnt_persons; i++)
            lbPersonal->Items->Add(pPersonal[i]);
        lbPersonal->ItemIndex = 0;
    }
    laDate->Caption = "Дата: " + Now().DateString();
}
//---------------------------------------------------------------------------
void __fastcall TAbParamForm::bCancelClick(TObject *Sender)
{
    Close();    
}
//---------------------------------------------------------------------------
void __fastcall TAbParamForm::bOKClick(TObject *Sender)
{
    if(Tag == "SPA" || Tag == "Bath")
    {
        Balanse = atof(edBalanse->Text.c_str());
        
        if(Balanse <= 0.0)
        {
            Application->MessageBox("Внимание!\nНеправильная сумма.","",MB_OK);
            return;
        }

        FormResult = 1;
        AbParamSID = 0;
        AbParamPID = 0;
    }
    else
    {
        FormResult = 1;
        AbParamSID = pServicesIDs[lbServices->ItemIndex];
        AbParamPID = pPersonalIDs[lbPersonal->ItemIndex];
    }

    Close();
}
//---------------------------------------------------------------------------
void __fastcall TAbParamForm::FormDestroy(TObject *Sender)
{
    PDEL(pPersonalIDs);
    PDEL(pPersonal);
    PDEL(pServicesIDs);
    PDEL(pServices);
}
//---------------------------------------------------------------------------
void __fastcall TAbParamForm::edBalanseKeyPress(TObject *Sender, char &Key)
{
    ud_keyfilter(Key);
}
//---------------------------------------------------------------------------

