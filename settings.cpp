//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "settings.h"
#include "lib.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSettingsForm *SettingsForm;

extern const char *DBName;

extern int SQL_RepeatCount;
extern int SQL_ExecDelay;
//---------------------------------------------------------------------------
__fastcall TSettingsForm::TSettingsForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSettingsForm::FormShow(TObject *Sender)
{
    AnsiString Val, Key;

    for(int i = 1; i < vlSettings->RowCount; i++)
    {
        SQL_exefun2(DBName,("select SettingsKey,SettingsVal from Settings where SettingsKey='"+vlSettings->Cells[0][i]+"'").c_str(),&Key,&Val);
        if(Key == vlSettings->Cells[0][i])
            vlSettings->Cells[1][i] = Val;
        else
        {
            SQL_iniInsert(DBName,"Settings");
            SQL_addInsert("!SettingsKey",vlSettings->Cells[0][i]);
            SQL_exeInsert("!SettingsVal",vlSettings->Cells[1][i]);
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TSettingsForm::vlSettingsKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
    if(Key != VK_RETURN) return;
    Key = 0;

    AnsiString Val;
    __int64 ID;

    SQL_exefun(DBName,("select RowID from Settings where SettingsKey='"+vlSettings->Cells[0][vlSettings->Row]+"'").c_str(),&Val);
    ID = _atoi64(Val.c_str());
    if(!ID) return;

    SQL_iniUpdate(DBName,"Settings",ID);
    SQL_exeUpdate("!SettingsVal",vlSettings->Cells[1][vlSettings->Row]);

    if(vlSettings->Cells[0][vlSettings->Row] == "SQL_RepeatCount")
    {
        int ival = atoi(vlSettings->Cells[1][vlSettings->Row].c_str());
        if(ival) SQL_RepeatCount = ival;
    }
    else if(vlSettings->Cells[0][vlSettings->Row] == "SQL_ExecDelay")
    {
        int ival = atoi(vlSettings->Cells[1][vlSettings->Row].c_str());
        if(ival) SQL_ExecDelay = ival;
    }
}
//---------------------------------------------------------------------------

