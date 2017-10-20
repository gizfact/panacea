//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "pwd.h"
#include "md5.h"
#include "lib.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPwdForm *PwdForm;

extern const char *DBName;
//extern __int64 ClientID;
//extern __int64 BillsID;
extern __int64 UserID;
//---------------------------------------------------------------------------
__fastcall TPwdForm::TPwdForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TPwdForm::Button1Click(TObject *Sender)
{
    AnsiString sRet;

    char md5pass[33];
    md5::md5(edOld->Text.c_str(),md5pass);

    SQL_exefun(DBName,(AnsiString("select count(*) from Stars where RowID=")+AnsiString(UserID)+" and Passwd='"+md5pass+"'").c_str(),&sRet);
    if(atoi(sRet.c_str()) == 0)
    {
        Application->MessageBox("Не верный пароль!","",MB_OK);
        Close();
        return;
    }

    if(edNew1->Text != edNew2->Text)
    {
        Application->MessageBox("Не совпадают значения нового пароля!","",MB_OK);
        return;
    }

    if(edNew1->Text.Length() == 0)
    {
        Application->MessageBox("Не введен новый пароль!","",MB_OK);
        return;
    }

    md5::md5(edNew1->Text.c_str(),md5pass);

    SQL_iniUpdate(DBName,"Stars",UserID);
    SQL_addUpdate("!Passwd",md5pass);
    if(SQL_exeUpdate("EDate",(double)Now()) == SQLITE_OK)
    {
        Application->MessageBox("Новый пароль успешно создан.","",MB_OK);
        Close();
        return;
    }

    Application->MessageBox("Сбой при создании нового пароля!","",MB_OK);
}
//---------------------------------------------------------------------------
void __fastcall TPwdForm::Button2Click(TObject *Sender)
{
    Close();
    return;    
}
//---------------------------------------------------------------------------
