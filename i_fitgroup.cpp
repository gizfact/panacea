//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "i_fitgroup.h"
#include "lib.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TiFitGroupForm *iFitGroupForm;

extern const char *DBName;
extern int FormResult;
//---------------------------------------------------------------------------
__fastcall TiFitGroupForm::TiFitGroupForm(TComponent* Owner)
    : TForm(Owner)
{
    __int64 *pIDs;
    AnsiString *pNames;

    int mask = 1 << CurrentWDay;

    unsigned cnt = SQL_fldKeyCollect(DBName,"Name",("from Services where bin_and(WeekDays,"+AnsiString(mask)+")!=0 and Tag like '~Фитнесс~' order by Name").c_str(),&pIDs,&pNames,true);

    cbService->Items->Add("");
    cbService->Items->Objects[0] = 0;

    for(unsigned i = 0; i < cnt; i++)
    {
        cbService->Items->Add(pNames[i]);
        cbService->Items->Objects[i+1] = (TObject *)pIDs[i];
    }

    cbService->ItemIndex = 0;

    delete [] pIDs;
    delete [] pNames;

    cnt = SQL_fldKeyCollect(DBName,"Name","from Personal where Alive=1 and ServiceID=1 order by Name",&pIDs,&pNames,true);

    cbPerson->Items->Add("");
    cbPerson->Items->Objects[0] = 0;

    for(unsigned i = 0; i < cnt; i++)
    {
        cbPerson->Items->Add(pNames[i]);
        cbPerson->Items->Objects[i+1] = (TObject *)pIDs[i];
    }

    cbPerson->ItemIndex = 0;

    delete [] pIDs;
    delete [] pNames;

    CurrentID = 0;
}
//---------------------------------------------------------------------------
void __fastcall TiFitGroupForm::Button1Click(TObject *Sender)
{
    if(cbService->ItemIndex <= 0)
    {
        Application->MessageBox("Внимание!\nНеобходимо указать услугу.","",MB_OK);
        return;
    }

    if(cbPerson->ItemIndex <= 0)
    {
        Application->MessageBox("Внимание!\nНеобходимо указать специалиста.","",MB_OK);
        return;
    }

    int count = atoi(edCount->Text.c_str());

    if(count <= 0)
    {
        Application->MessageBox("Внимание!\nВведено не корректное значение для кол-ва.","",MB_OK);
        edCount->Text = count;
        return;
    }

    double bt = TimeStr2Double(edBegTime->Text.c_str());
    double et = TimeStr2Double(edEndTime->Text.c_str());

    if(bt >= et)
    {
        Application->MessageBox("Внимание!\nВведено не корректное значение временного интервала.","",MB_OK);
        edBegTime->Text = TDateTime(bt).FormatString("hh:nn");
        edEndTime->Text = TDateTime(et).FormatString("hh:nn");
        return;
    }

    //if(bt <= 1.0/3.0 || bt >= 11.0/12.0)
    //{
    //    Application->MessageBox("Внимание!\nВремя должно быть в интервале с 8:00 и до 22:00.","",MB_OK);

    //    return;

    //}

    double d = (int)CurrentDay;

    if(!CurrentID)
    {


        SQL_iniInsert(DBName,"FitGroup",&CurrentID);
        SQL_addInsert("FitGroupDay",CurrentWDay);
        SQL_addInsert("ServiceID",(__int64)cbService->Items->Objects[cbService->ItemIndex]);
        SQL_addInsert("PersonID",(__int64)cbPerson->Items->Objects[cbPerson->ItemIndex]);
        SQL_addInsert("BegDate",d+bt);
        SQL_addInsert("EndDate",d+et);
        SQL_exeInsert("FitGroupCount",count);
    }
    else
    {
        SQL_iniUpdate(DBName,"FitGroup",CurrentID);
        SQL_addUpdate("FitGroupDay",CurrentWDay);
        SQL_addUpdate("ServiceID",(__int64)cbService->Items->Objects[cbService->ItemIndex]);
        SQL_addUpdate("PersonID",(__int64)cbPerson->Items->Objects[cbPerson->ItemIndex]);
        SQL_addUpdate("BegDate",d+bt);
        SQL_addUpdate("EndDate",d+et);
        SQL_exeUpdate("FitGroupCount",count);
    }

    FormResult = 1;
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TiFitGroupForm::Button2Click(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TiFitGroupForm::FormShow(TObject *Sender)
{
    if(CurrentID)
    {
        // Редактирование
        //int __fastcall SQL_exefunrow(const char *dbname,const char *sql,unsigned count,AnsiString *pRet);
        AnsiString pRet[5];

        SQL_exefunrow(DBName,("select ServiceID,PersonID,BegDate,EndDate,FitGroupCount from FitGroup where RowID="+AnsiString(CurrentID)).c_str(),5,pRet);
        //if(pRet)
        {
            __int64 SID = _atoi64(pRet[0].c_str());
            __int64 PID = _atoi64(pRet[1].c_str());
            edBegTime->Text = TDateTime(atof(pRet[2].c_str())).FormatString("hh:nn");
            edEndTime->Text = TDateTime(atof(pRet[3].c_str())).FormatString("hh:nn");
            edCount->Text = atoi(pRet[4].c_str());

            for(int i = 0; i < cbService->Items->Count; i++)
            {
                if(SID == (__int64)cbService->Items->Objects[i])
                {
                    cbService->ItemIndex = i;
                    break;
                }
            }

            for(int i = 0; i < cbPerson->Items->Count; i++)
            {
                if(PID == (__int64)cbPerson->Items->Objects[i])
                {
                    cbPerson->ItemIndex = i;
                    break;
                }
            }
        }
    }
}
//---------------------------------------------------------------------------

