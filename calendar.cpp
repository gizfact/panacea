//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "calendar.h"
#include "lib.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
extern const char *DBName;
extern const char *_MonthNames[];

extern bool AdminMode;
extern __int64 UserID;

TCalendarForm *CalendarForm;

const char *_days[] = { "Âñ", "Ïí", "Âò", "Ñð", "×ò", "Ïò", "Ñá" };

//---------------------------------------------------------------------------
static int services_fill(void *NotUsed,int argc,char **argv,char **azColName)
{
    // SID,Name

    CalendarForm->cbServices->AddItem((argv[1]),(TObject *)_atoi64(argv[0]));

    return 0;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TCalendarForm::FullUpdate(void)
{
    ScrollBox1->Visible = false;
    ClearCalendar();

    int FirstDay = CurrentFDay.DayOfWeek() - 1;
    int k;
    TPanel *pPan;

    unsigned short year, month, day;
    CurrentFDay.DecodeDate(&year,&month,&day);
    DaysCount = monthdays(year,month);

    pHeaders = new int *[DaysCount<<1];
    for(unsigned i = 0; i < DaysCount; i++)
    {
        pPan = new TPanel(ScrollBox1);
        pPan->Parent = ScrollBox1;
        pPan->Width = 24;
        pPan->Height = 24;
        pPan->Left = 200 + 25 * i;
        pPan->Top = 0;
        pPan->Caption = i + 1;
        pPan->Font->Color = clWhite;
        if(FirstDay == 0 || FirstDay == 6)
            pPan->Color = clRed;
        else
            pPan->Color = clSkyBlue;

        pHeaders[i] = (int *)pPan;

        pPan = new TPanel(ScrollBox1);
        pPan->Parent = ScrollBox1;
        pPan->Width = 24;
        pPan->Height = 24;
        pPan->Left = 200 + 25 * i;
        pPan->Top = 25;
        pPan->Caption = _days[FirstDay];
        pPan->Font->Color = clWhite;
        if(FirstDay == 0 || FirstDay == 6)
            pPan->Color = clRed;
        else
            pPan->Color = clSkyBlue;

        if(++FirstDay > 6) FirstDay = 0;

        pHeaders[i+DaysCount] = (int *)pPan;
    }

    if(!cbServices->Items->Objects[cbServices->ItemIndex])
    {
        // Admins
        if(TDateTime().CurrentDate() < CurrentFDay)
            PersonCount = SQL_fldKeyCollect(DBName,"StarsUser","from Stars where StarsLock=0 and RowID!=4 order by StarsUser",&pPersonIDs,&pPersonNames);
        else
            PersonCount = SQL_fldKeyCollect(DBName,"a.StarsUser",
        ("from Stars a inner join Calendar b on a.RowID=-b.PersonID where b.CalendarYear=" + AnsiString(year) +
        " and b.CalendarMonth=" + AnsiString(month) +
        " and a.RowID!=4 and b.Days+b.HDays!=0 order by a.StarsUser").c_str(),&pPersonIDs,&pPersonNames);

        for(int i = 0; i < PersonCount; i++)
            pPersonIDs[i] = -pPersonIDs[i];
    }
    else
        PersonCount = SQL_fldKeyCollect(DBName,"Name",("from Personal where Alive=1 and ServiceID="+AnsiString((__int64)cbServices->Items->Objects[cbServices->ItemIndex])+
    " order by Name").c_str(),&pPersonIDs,&pPersonNames,true);



    pPersons = new int *[PersonCount];

    for(unsigned i = 0; i < PersonCount; i++)
    {
        pPan = new TPanel(ScrollBox1);
        pPan->Parent = ScrollBox1;
        pPan->Width = 200;
        pPan->Height = 24;
        pPan->Left = 0;
        pPan->Top = 50 + 25 * i;
        pPan->Caption = " " + pPersonNames[i];
        pPan->Alignment = taLeftJustify;
        //pPan->OnMouseDown = PanClick;

        pPersons[i] = (int *)pPan;
    }

    pDays = new int *[DaysCount*PersonCount];
    AnsiString sRet, sHDays;

    for(unsigned j = 0; j < PersonCount; j++)
    {
        SQL_exefun2(DBName,("select Days,HDays from Calendar where PersonID="+AnsiString(pPersonIDs[j])+" and CalendarYear="+AnsiString(year)+" and CalendarMonth="+AnsiString(month)).c_str(),&sRet,&sHDays);
        unsigned mask = atoi(sRet.c_str());
        unsigned hmask = atoi(sHDays.c_str());

        for(unsigned i = 0; i < DaysCount; i++)
        {
            k = j * DaysCount + i;

            pPan = new TPanel(ScrollBox1);
            pPan->Parent = ScrollBox1;
            pPan->Width = 24;
            pPan->Height = 24;
            pPan->Left = 201 + 25 * i;
            pPan->Top = 50 + 25 * j;

            if(hmask & (1 << i))
            {
                pPan->BevelOuter = bvLowered;
                pPan->Color = clBlue;
            }
            else if(mask & (1 << i))
            {
                pPan->BevelOuter = bvLowered;
                pPan->Color = clGreen;
            }
            else
                pPan->Color = clWhite;

            pPan->Tag = k;

            pPan->OnMouseDown = PanClick;

            pDays[k] = (int *)pPan;
        }
    }

    ScrollBox1->Visible = true;
}
//---------------------------------------------------------------------------
__fastcall TCalendarForm::TCalendarForm(TComponent* Owner)
    : TForm(Owner)
{
    DaysCount = 0;
    PersonCount = 0;

    pDays = NULL;
    pHeaders = NULL;
    pPersons = NULL;
    pPersonIDs = NULL;
    pPersonNames = NULL;

    TDateTime dt = Now();
    unsigned short year, month, day;
    dt.DecodeDate(&year,&month,&day);

    DaysCount = monthdays(year,month);
    CurrentFDay = TDateTime(year,month,1);

    paPeriod->Caption = AnsiString(_MonthNames[month-1]) + " " + AnsiString(year);
}
//---------------------------------------------------------------------------
void __fastcall TCalendarForm::PanClick(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if(!AdminMode && UserID != 4) return;

    TPanel *pPan = (TPanel *)Sender;
    int pid = pPan->Tag / DaysCount;
    int did = pPan->Tag % DaysCount;

    unsigned short year, month, day;
    CurrentFDay.DecodeDate(&year,&month,&day);

    AnsiString sID, sDays, sHDays, sql = "select RowID,Days,HDays from Calendar where PersonID=";
    sql += pPersonIDs[pid];
    sql += " and CalendarYear=";
    sql += year;
    sql += " and CalendarMonth=";
    sql += month;

    SQL_exefun3(DBName,sql.c_str(),&sID,&sDays,&sHDays);
    __int64 ID = _atoi64(sID.c_str());

    if(pPan->Color != clBlue)
    {
        pPan->BevelOuter = bvLowered;
        if(pPan->Color == clGreen)
            pPan->Color = clBlue;
        else
            pPan->Color = clGreen;

        if(!ID)
        {
            SQL_iniInsert(DBName,"Calendar");
            SQL_addInsert("PersonID",pPersonIDs[pid]);
            SQL_addInsert("CalendarYear",year);
            SQL_addInsert("CalendarMonth",month);
            if(pPan->Color == clBlue)
                SQL_addInsert("HDays",1 << did);
            SQL_exeInsert("Days",1 << did);
        }
        else
        {
            SQL_iniUpdate(DBName,"Calendar",ID);
            if(pPan->Color == clBlue)
                SQL_addUpdate("HDays",atoi(sHDays.c_str()) | (1 << did));
            SQL_exeUpdate("Days",atoi(sDays.c_str()) | (1 << did));
        }
    }
    else
    {
        pPan->BevelOuter = bvRaised;
        pPan->Color = clWhite;

        SQL_iniUpdate(DBName,"Calendar",ID);
        SQL_addUpdate("HDays",atoi(sHDays.c_str()) & (0xFFFFFFFF ^ (1 << did)));
        SQL_exeUpdate("Days",atoi(sDays.c_str()) & (0xFFFFFFFF ^ (1 << did)));
    }
}
//---------------------------------------------------------------------------
void __fastcall TCalendarForm::tbExitClick(TObject *Sender)
{
    Close();    
}
//---------------------------------------------------------------------------
void __fastcall TCalendarForm::ClearCalendar(void)
{
    TPanel *pPan;

    if(pDays)
    {
        for(unsigned i = 0; i < DaysCount * PersonCount; i++)
        {
            pPan = (TPanel *)pDays[i];
            delete pPan;
        }

        delete [] pDays;
        pDays = NULL;
    }

    if(pHeaders)
    {
        for(unsigned i = 0; i < DaysCount << 1; i++)
        {
            pPan = (TPanel *)pHeaders[i];
            delete pPan;
        }

        delete [] pHeaders;
        pHeaders = NULL;
    }

    if(pPersons)
    {
        for(unsigned i = 0; i < PersonCount; i++)
        {
            pPan = (TPanel *)pPersons[i];
            delete pPan;
        }

        delete [] pPersons;
        delete [] pPersonIDs;
        delete [] pPersonNames;
        pPersons = NULL;
        pPersonIDs = NULL;
        pPersonNames = NULL;
    }
}
//---------------------------------------------------------------------------
void __fastcall TCalendarForm::FormShow(TObject *Sender)
{
    AnsiString sql = "select SID,Name from "
        "( "
            "select distinct ServiceID as SID from Personal "
        ") inner join Services on SID=Services.RowID where SID!=1 order by Name";

    SQL_exe(DBName,sql.c_str(),services_fill);

    CalendarForm->cbServices->AddItem("Àäìèíèñòðàòîðû",NULL);

    cbServices->ItemIndex = 0;

    FullUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TCalendarForm::FormDestroy(TObject *Sender)
{
    ClearCalendar();
}
//---------------------------------------------------------------------------
void __fastcall TCalendarForm::cbServicesChange(TObject *Sender)
{
    FullUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TCalendarForm::sbLeftClick(TObject *Sender)
{
    unsigned short year, month, day;
    CurrentFDay.DecodeDate(&year,&month,&day);

    if(!--month)
    {
        month = 12;
        year--;
    }

    //DaysCount = monthdays(year,month);
    CurrentFDay = TDateTime(year,month,1);

    paPeriod->Caption = AnsiString(_MonthNames[month-1]) + " " + AnsiString(year);

    FullUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TCalendarForm::sbRightClick(TObject *Sender)
{
    unsigned short year, month, day;
    CurrentFDay.DecodeDate(&year,&month,&day);

    if(++month > 12)
    {
        month = 1;
        year++;
    }

    //DaysCount = monthdays(year,month);
    CurrentFDay = TDateTime(year,month,1);

    paPeriod->Caption = AnsiString(_MonthNames[month-1]) + " " + AnsiString(year);

    FullUpdate();
}
//---------------------------------------------------------------------------

