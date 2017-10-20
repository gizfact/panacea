//---------------------------------------------------------------------------
#include <vcl.h>

#pragma hdrstop

#include "kkm_outcome.h"
#include "lib.h"
#include "kkm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TKKMOutForm *KKMOutForm;

extern __int64 UserID;
//---------------------------------------------------------------------------
__fastcall TKKMOutForm::TKKMOutForm(TComponent* Owner,bool income)
    : TForm(Owner)
{
    if(income)
        laOp->Caption = "Сумма внесения";

    Op = income;
}
//---------------------------------------------------------------------------
void __fastcall TKKMOutForm::bCancelClick(TObject *Sender)
{
    Close();    
}
//---------------------------------------------------------------------------
void __fastcall TKKMOutForm::bOKClick(TObject *Sender)
{
    int cash = atoi(edOutcome->Text.c_str());
    if(cash <= 0)
    {
        Application->MessageBox("Неправильная сумма!\nСумма должна быть больше нуля.", Application->Title.c_str(), MB_ICONERROR + MB_OK);
        edOutcome->Text = "0";
        edOutcome->SetFocus();
        return;
    }

    // Пробуем снять/внести
    TDateTime dt = dt.CurrentDateTime();

    if(!Op)
    {
        if(kkm_outcome(cash) != 0)
            Application->MessageBox("Ошибка снятия!\nУстраните ошибку.", Application->Title.c_str(), MB_ICONERROR + MB_OK);
        else
        {
            SQL_iniInsert(NULL, "KKM");
            SQL_addInsert("OpDate", (double)dt);
            SQL_addInsert("SUMM", -cash);
            SQL_exeInsert("STARID", UserID);
        }
    }
    else
    {
        if(kkm_income(cash) != 0)
            Application->MessageBox("Ошибка внесения!\nУстраните ошибку.", Application->Title.c_str(), MB_ICONERROR + MB_OK);
        else
        {
            SQL_iniInsert(NULL, "KKM");
            SQL_addInsert("OpDate", (double)dt);
            SQL_addInsert("SUMM", cash);
            SQL_exeInsert("STARID", UserID);
        }
    }

    Close();
}
//---------------------------------------------------------------------------
void __fastcall TKKMOutForm::edOutcomeKeyPress(TObject *Sender, char &Key)
{
    ui_keyfilter(Key);
}
//---------------------------------------------------------------------------
void __fastcall TKKMOutForm::FormShow(TObject *Sender)
{
    if(!Op)
    {
        double d = kkm_getsum();

        if(d > 0)
            edOutcome->Text = d;
    }
}
//---------------------------------------------------------------------------

