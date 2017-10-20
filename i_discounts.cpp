//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "i_discounts.h"
#include "lib.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TiDiscountsForm *iDiscountsForm;

extern const char *DBName;
extern __int64 DiscountID;
extern __int64 UserID;
extern int FormResult;

extern const char *MoneyFormat;

static AnsiString DiscountName;

//---------------------------------------------------------------------------
static int idiscounts_select(void *NotUsed,int argc,char **argv,char **azColName)
{
    iDiscountsForm->cbAlive->Checked = (argv[0])? (atoi(argv[0]) != 0) : false;

    DiscountName = Utf8ToAnsi(argv[1]);
    iDiscountsForm->edName->Text = DiscountName;

    if(argv[2])
    {
        iDiscountsForm->dtpBegDate->DateTime = atof(argv[2]);
            //iClientsForm->dtpBirthDate->Time = TDateTime(0,0,0,0);
    }
    else
    {
        iDiscountsForm->dtpBegDate->Date = TDate(1900,1,1);
            //iClientsForm->dtpBirthDate->Time = TTime(0,0,0,0);
    }

    if(argv[3])
    {
        iDiscountsForm->dtpEndDate->DateTime = atof(argv[3]);
            //iClientsForm->dtpBirthDate->Time = TDateTime(0,0,0,0);
    }
    else
    {
        iDiscountsForm->dtpEndDate->Date = TDate(1900,1,1);
            //iClientsForm->dtpBirthDate->Time = TTime(0,0,0,0);
    }

    if(argv[4])
        iDiscountsForm->edPercent->Text = FormatFloat(MoneyFormat,strtof(argv[4])).TrimLeft();
    else
        iDiscountsForm->edPercent->Text = "0.00";

    int WeekDays = (argv[5])? atoi(argv[5]) : 0;

    iDiscountsForm->cbMon->Checked = WeekDays & 1;
    iDiscountsForm->cbTue->Checked = WeekDays & 2;
    iDiscountsForm->cbWed->Checked = WeekDays & 4;
    iDiscountsForm->cbThu->Checked = WeekDays & 8;
    iDiscountsForm->cbFri->Checked = WeekDays & 16;
    iDiscountsForm->cbSat->Checked = WeekDays & 32;
    iDiscountsForm->cbSun->Checked = WeekDays & 64;



    return 0;
}
//---------------------------------------------------------------------------
__fastcall TiDiscountsForm::TiDiscountsForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TiDiscountsForm::tbSaveClick(TObject *Sender)
{
    edName->Text = edName->Text.Trim();

    if(edName->Text.Length() > 0 && edName->Text != DiscountName)
    {
        AnsiString sql = "select count(*) from Discounts where Name='";
        sql += AnsiToUtf8(edName->Text.Trim());
        sql += "'";

        if(SQL_exefun(DBName,sql.c_str(),&sql) == SQLITE_OK)
        {
            if(atoi(sql.c_str()) > 0)
            {
                Application->MessageBox(("Скидка с наименованием "+edName->Text.Trim()+" уже существует.").c_str(),"");
                return;
            }
        }
    }

    double Percent = strtof(edPercent->Text.c_str());
    if(Percent <= 0.0 || Percent > 100.0)
    {
        Application->MessageBox(("Недопустимое значение процента скидки "+edPercent->Text).c_str(),"");
        return;
    }

    if(dtpBegDate->Date != TDate(1900,1,1) && dtpEndDate->Date != TDate(1900,1,1))
        if(dtpEndDate->Date < dtpBegDate->Date)
        {
            Application->MessageBox("Недопустимое значение конечной даты скидки - должно быть позже начальной даты","");
            return;
        }

    TDateTime dt;
    dt = dt.CurrentDateTime();

    if(!DiscountID)
    {
        __int64 ID;

        SQL_iniInsert(DBName,"Discounts",&ID);

        SQL_addInsert("#Name",edName->Text);

        if((double)dtpBegDate->DateTime != 0)
            SQL_addInsert("BegDate",(double)(dtpBegDate->DateTime));

        if((double)dtpEndDate->DateTime != 0)
            SQL_addInsert("EndDate",(double)(dtpEndDate->DateTime));

        SQL_addInsert("Percent",Percent);

        int WeekDays = 0;
        WeekDays |= cbMon->Checked;
        WeekDays |= (cbTue->Checked<<1);
        WeekDays |= (cbWed->Checked<<2);
        WeekDays |= (cbThu->Checked<<3);
        WeekDays |= (cbFri->Checked<<4);
        WeekDays |= (cbSat->Checked<<5);
        WeekDays |= (cbSun->Checked<<6);

        SQL_addInsert("WeekDays",WeekDays);

        SQL_addInsert("Alive",(int)(cbAlive->Checked));

        SQL_addInsert("CDate",(double)dt);
        SQL_addInsert("EDate",(double)dt);
        SQL_addInsert("CUID",UserID);
        SQL_exeInsert("EUID",UserID);
        DiscountID = ID;
        FormResult = 1;
    }
    else
    {
        SQL_iniUpdate(DBName,"Discounts",DiscountID);

        SQL_addUpdate("#Name",edName->Text);

        if((double)dtpBegDate->DateTime != 0)
            SQL_addUpdate("BegDate",(double)(dtpBegDate->DateTime));

        if((double)dtpEndDate->DateTime != 0)
            SQL_addUpdate("EndDate",(double)(dtpEndDate->DateTime));

        SQL_addUpdate("Percent",Percent);

        int WeekDays = 0;
        WeekDays |= cbMon->Checked;
        WeekDays |= (cbTue->Checked<<1);
        WeekDays |= (cbWed->Checked<<2);
        WeekDays |= (cbThu->Checked<<3);
        WeekDays |= (cbFri->Checked<<4);
        WeekDays |= (cbSat->Checked<<5);
        WeekDays |= (cbSun->Checked<<6);

        SQL_addUpdate("WeekDays",WeekDays);

        SQL_addUpdate("Alive",(int)(cbAlive->Checked));

        //SQL_addUpdate("CDate",tim);
        SQL_addUpdate("EDate",(double)dt);
        SQL_exeUpdate("EUID",UserID);
        //ClientID = ID;

        FormResult = -1;
    }
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TiDiscountsForm::FormShow(TObject *Sender)
{
    if(DiscountID != 0)
        SQL_exe(DBName,("select Alive,Name,BegDate,EndDate,Percent,WeekDays from Discounts where RowID=" + (AnsiString)DiscountID).c_str(),idiscounts_select);
    else
    {
        cbAlive->Checked = true;
        DiscountName = "";
        dtpBegDate->DateTime = 0;
        dtpEndDate->DateTime = 0;
    }

    FormResult = 0;
    
    edName->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TiDiscountsForm::FormKeyPress(TObject *Sender, char &Key)
{
    if(Key == 27)
        Close();
}
//---------------------------------------------------------------------------
void __fastcall TiDiscountsForm::ToolButton2Click(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

