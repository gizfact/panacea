//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "SevenZipVCL.hpp"
//---------------------------------------------------------------------------
#include <stdio.h>

#include "main.h"
#include "login.h"
#include "accounts.h"
#include "clients.h"
#include "services.h"
#include "goods.h"
#include "goodsincome.h"
//#include "servicesprice.h"
#include "settings.h"
#include "abtypes.h"
#include "personal.h"
#include "repBalanse.h"
#include "repBalanseSPA.h"
#include "repNegBalanse.h"
#include "dt_interval.h"
#include "repAbServices.h"
#include "repVisits.h"
#include "repVisitsSPA.h"
#include "purchase.h"
#include "repSells.h"
#include "repGoodsSPA.h"
#include "servicegoods.h"
//#include "tables.h"
#include "sells.h"
#include "calendar.h"
#include "fitgroup.h"

#include "pwd.h"

#include "dm_main.h"
#include "sync.h"

#include <math.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TMainForm *MainForm;

const char *AppForms[FORMS_COUNT] = {   "����������", "�������", "���� �����������", "������",
                                        "����� �������", "�����-�����", "������", "�������",
                                        "������", "���� �� ������", "����� �������������", "����� ���������",
                                        "����� ������", "����� ��������� SPA", "����� ���������� SPA", "������ - ���������",
                                        "������������� ������", "���������� ��������� �������", "���������"
                                    };

bool AppExit = false;
bool AdminMode = false;

__int64 UserID = 0;
AnsiString UserAcc;
unsigned char UserGrants[FORMS_COUNT];

extern AnsiString _AppPath;

TMenuItem *AppMenus[FORMS_COUNT];
const char *DBName = NULL;
static AnsiString _DBName;

AnsiString ImgPath;
AnsiString ExpPath;

int FormResult = 0;

int CurDayOfWeek;

const char *MoneyFormat = "0.00";
const char *CountFormat = "0.000";
const char *MoneyWideFormat = "### ### ### ##0.00";

extern TDateTime DTI_BegDate;
extern TDateTime DTI_EndDate;

__int64 KassaBillID = -1;

extern int SQL_RepeatCount;
extern int SQL_ExecDelay;
extern bool SQL_ShowErrors;

int SearchDelay;

bool NegBalanseFlag = false;
bool WriteACheck = false;

bool SyncFlag = false;
unsigned SyncPeriod = 10;
TSync *pSync = NULL;
bool ReserveFlag = false;

AnsiString ConString;
//---------------------------------------------------------------------------
static int billstorep_select(void *NotUsed, int argc, char **argv, char **azColName)
{
    int payment = ATOI(argv[4]);

    double x;
    if(!MainForm->repBillsCounter)
    {
        x = (argv[0])? strtof(argv[0]) : 0.0;
        MainForm->repClientsBegBalanse[MainForm->repClientsCounter] = FormatFloat(MoneyFormat,x);
    }

    x = ATOF(argv[1]);

    if(MainForm->repBillsCounter)
        MainForm->repClientsFromBalanse[MainForm->repClientsCounter] = x + atof(MainForm->repClientsFromBalanse[MainForm->repClientsCounter].c_str());
    else
        MainForm->repClientsFromBalanse[MainForm->repClientsCounter] = x;

    x = ATOF(argv[2]);
    if(MainForm->repBillsCounter++)
    {
        if(!payment)
        {
            MainForm->repClientsToBalanse[MainForm->repClientsCounter] = x + atof(MainForm->repClientsToBalanse[MainForm->repClientsCounter].c_str());
            //MainForm->repClientsToBalanseBN[MainForm->repClientsCounter] = 0.0;
        }
        else if(payment == 1 || payment == -1)
        {
            MainForm->repClientsToBalanseBN[MainForm->repClientsCounter] = x + atof(MainForm->repClientsToBalanseBN[MainForm->repClientsCounter].c_str());
            //MainForm->repClientsToBalanse[MainForm->repClientsCounter] = 0.0;
        }
    }
    else
    {
        if(!payment)
        {
            MainForm->repClientsToBalanse[MainForm->repClientsCounter] = x;
            MainForm->repClientsToBalanseBN[MainForm->repClientsCounter] = 0.0;
        }
        else if(payment == 1 || payment == -1)
        {
            MainForm->repClientsToBalanse[MainForm->repClientsCounter] = 0.0;
            MainForm->repClientsToBalanseBN[MainForm->repClientsCounter] = x;
        }
    }
    x = (argv[3])? strtof(argv[3]) : 0.0;
    MainForm->repClientsEndBalanse[MainForm->repClientsCounter] = FormatFloat(MoneyFormat,x);

    return 0;
}
//---------------------------------------------------------------------------
static int clientsfrombills_select(void *NotUsed, int argc, char **argv, char **azColName)
{
    if(!argv[0]) return 0;
    __int64 ID = _atoi64(argv[0]);
    if(!ID) return 0;

    MainForm->repClientsIDs[MainForm->repClientsCounter] = ID;

    MainForm->repClientsFNames[MainForm->repClientsCounter] = argv[1];
    MainForm->repClientsSNames[MainForm->repClientsCounter] = argv[2];
    MainForm->repClientsTNames[MainForm->repClientsCounter++] = argv[3];

    return 0;
}
//---------------------------------------------------------------------------
static int goodsfrombills_select(void *NotUsed, int argc, char **argv, char **azColName)
{
    if(!argv[0]) return 0;
    __int64 ID = _atoi64(argv[0]);
    if(!ID) return 0;

    MainForm->repClientsIDs[MainForm->repClientsCounter] = ID;

    MainForm->repClientsFNames[MainForm->repClientsCounter] = argv[1];
    MainForm->repClientsSNames[MainForm->repClientsCounter++] = (argv[2])? argv[2] : "0";

    return 0;
}
//---------------------------------------------------------------------------
static int IDs_fun(void *NotUsed,int argc,char **argv,char **azColName)
{
    if(argc > 0) MainForm->IDs[MainForm->Counter++] = (argv[0])? _atoi64(argv[0]) : 0;

    return 0;
}
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
    : TForm(Owner)
{
    IDs = NULL;
    Counter = 0;

    TIniFile *pIni = new TIniFile(_AppPath+"panacea.ini");
    AnsiString sPath = pIni->ReadString("Settings","DBPath",_AppPath);
    AnsiString sBillID = pIni->ReadString("Node","ID","1");

    AnsiString sServer, sPort, sDatabase;

    if(pIni->SectionExists("Connection"))
    {
        sServer = pIni->ReadString("Connection","Server","");
        sPort = pIni->ReadString("Connection","Port","");
        sDatabase = pIni->ReadString("Connection","Database","");
    }
    else
    {
        pIni->WriteString("Connection","Server","localhost");
        pIni->WriteString("Connection","Port","3050");
        pIni->WriteString("Connection","Database","c:\\pdb\\db\\panacea.pdb");

        sServer = "localhost";
        sPort = "3050";
        sDatabase = "c:\\pdb\\db\\panacea.pdb";
    }

    if(sServer == "" || sPort == "")
        ConString = sDatabase;
    else
        ConString = sServer + "/" + sPort + ":" + sDatabase;

    delete pIni;

    dmMain = new TdmMain(this);

    if(dmMain->DBConnect(ConString) == false)
    {
        // Oooops...
        Application->MessageBox("��������!\n������ ��������� ����������.","[ERROR 111]",MB_OK);

        delete dmMain;

        TerminateProcess(GetCurrentProcess(),1);
        return;
    }


    _DBName = sPath + "db\\panacea.pdb";

    //if(FileExists(_DBName) == false)
    //{
        // Oooops...
    //    Application->MessageBox("��������!\n������ ��������� ����������.","[ERROR 117]",MB_OK);

    //    TerminateProcess(GetCurrentProcess(),1);
    //    return;
    //}
    
    // ������������� ����������� ID ��� �����
    KassaBillID = -_atoi64(sBillID.c_str());
    //KassaBillID = 0;

    DBName = _DBName.c_str();
    ImgPath = sPath + "img\\";
    ExpPath = sPath;

    TDateTime dtb, dte;

    //SQL_exefun(DBName,"PRAGMA page_size",&retString);

    //SQL_exe(DBName,"PRAGMA journal_mode=delete");
    //SQL_exe(DBName,"PRAGMA page_size=4096");

    SQL_exefun(DBName,"select max(BegDate) from Sessions",&retString);
    dtb = atof(retString.c_str());
    SQL_exefun(DBName,"select max(EndDate) from Sessions",&retString);
    dte = atof(retString.c_str());
    if(dtb > dte) dte = dtb;

    dtb = Now();

    if(dte > dtb)
    {
        Application->MessageBox("��������!\n������ ��������� ����������.","[ERROR 126]",MB_OK);

        TerminateProcess(GetCurrentProcess(),1);
        return;
    }

    CurDayOfWeek = dtb.DayOfWeek() - 1;
    if(!CurDayOfWeek) CurDayOfWeek = 7;

    //CurDayOfWeek = 1 << CurDayOfWeek;

    Left = 0;       
    Top = 0;

    AppMenus[0] = mmnPersonal;
    AppMenus[1] = mmnClient;
    AppMenus[2] = mmnAbType;
    AppMenus[3] = NULL;
    AppMenus[4] = mmnRepBalanse;
    AppMenus[5] = NULL;
    AppMenus[6] = mmnServices;
    AppMenus[7] = mmnGoodsList;
    AppMenus[8] = mmnGoodsInput;
    AppMenus[9] = NULL;
    AppMenus[10] = mmnRepNegBalanse;
    AppMenus[11] = mmnRepVisits;
    AppMenus[12] = NULL;
    AppMenus[13] = mmnRepVisitsSPA;
    AppMenus[14] = mmnRepAbsSPA;
    AppMenus[15] = mmnServiceGoods;
    AppMenus[16] = NULL;
    AppMenus[17] = mmnFitGroup;
    AppMenus[18] = mmnCalendar;

    DecimalSeparator = '.';
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormShow(TObject *Sender)
{
    LoginForm = new TLoginForm(this);
    LoginForm->ShowModal();
    delete LoginForm;

    if(AppExit)
    {
        TerminateProcess(GetCurrentProcess(),1);
        return;
    }

    mmnRefbook->Enabled = true;
    mmnService->Enabled = true;
    mmnReport->Enabled = true;

    TDateTime dt = Now();

    if(AdminMode)
    {
        mmnAdmin->Enabled = true;
        mmnAdmin->Visible = true;
        //mmnCalendar->Visible = true;
        mmnFitGroup->Visible = true;

        NegBalanseFlag = true;
        
        sbMain->Panels->Items[0]->Text = "   root, " + dt;
    }
    else
    {
        for(unsigned i = 0; i < FORMS_COUNT; i++)
        if(UserGrants[i] == '0' && AppMenus[i])
            AppMenus[i]->Visible = false;

        if(UserGrants[16] == '7') NegBalanseFlag = true;

        //if(!mmnServicesPrice->Visible)
        //    mmnPrices->Visible = false;

        //if(UserID == 4)
        //{
            //mmnCalendar->Visible = true;
          //  mmnFitGroup->Visible = true;
        //}

        sbMain->Panels->Items[0]->Text = "   " + UserAcc + " [" + UserID + "]   " + dt;
    }

    SessionKey = dt;

    SQL_iniInsert(DBName,"Sessions");
    SQL_addInsert("UserID",UserID);

    if(SQL_exeInsert("BegDate",SessionKey) != SQLITE_OK)
    {
        Application->MessageBox("��������!\n���������� ������� ������ - ������ ��������� ����� ��������.","������ ��",MB_OK);
        TerminateProcess(GetCurrentProcess(),1);
        return;
    }

    SQL_exefun(DBName,"select SettingsVal from Settings where SettingsKey='SQL_RepeatCount'",&retString);
    int val = atoi(retString.c_str());
    if(val) SQL_RepeatCount = val;
    SQL_exefun(DBName,"select SettingsVal from Settings where SettingsKey='SQL_ExecDelay'",&retString);
    val = atoi(retString.c_str());
    if(val) SQL_ExecDelay = val;
    SQL_exefun(DBName,"select SettingsVal from Settings where SettingsKey='SQL_ShowErrors'",&retString);
    if(retString.Length() > 0)
        SQL_ShowErrors = atoi(retString.c_str());

    SQL_exefun(DBName,"select SettingsVal from Settings where SettingsKey='SearchDelay'",&retString);
    if(retString.Length() > 0)
        SearchDelay = atoi(retString.c_str());
    else
        SearchDelay = 1000;

    SQL_exefun(NULL,"select SettingsVal from Settings where SettingsKey='WriteACheck'",&retString);
    if(retString.Length() > 0)
        WriteACheck = (atoi(retString.c_str()) != 0);
    else
        WriteACheck = false;
    // �������� ���������� FitGroup
    //if(!CurDayOfWeek)
    SQL_BeginTransaction();
    {
        SQL_exefun(DBName,("select count(*) from FitGroup where BegDate>="+AnsiString((int)dt)+" and EndDate<"+AnsiString((int)(dt+7))).c_str(),&retString);
        if(atoi(retString.c_str()) == 0)
        {
            // ������ ���, ��������
            int pd = (int)dt - 7;
            SQL_exe(DBName,("insert into FitGroup select null,FitGroupDay,a.ServiceID,a.PersonID,BegDate+7,EndDate+7,FitGroupCount,0,0 from FitGroup a,Personal,Services where BegDate>="+AnsiString(pd)+" and EndDate<"+AnsiString(pd+7)+" and PersonID=Personal.RowID and Personal.ServiceID=Services.RowID and Alive=1 and bin_and(WeekDays,127)!=0").c_str());

        }

        dt += 7;
        SQL_exefun(DBName,("select count(*) from FitGroup where BegDate>="+AnsiString((int)dt)+" and EndDate<"+AnsiString((int)(dt+7))).c_str(),&retString);
        if(atoi(retString.c_str()) == 0)
        {
            // ������ ���, �������� �� ������ ������
            int pd = (int)dt - 7;
            SQL_exe(DBName,("insert into FitGroup select null,FitGroupDay,a.ServiceID,a.PersonID,BegDate+7,EndDate+7,FitGroupCount,0,0 from FitGroup a,Personal,Services where BegDate>="+AnsiString(pd)+" and EndDate<"+AnsiString(pd+7)+" and PersonID=Personal.RowID and Personal.ServiceID=Services.RowID and Alive=1 and bin_and(WeekDays,127)!=0").c_str());
        }
    }
    SQL_CommitTransaction();

    // ������, ������������ �����
    if(KassaBillID == -1)
        tiReserve->Enabled = true;

    if(!SyncFlag) return;


    tiSync->Interval = SyncPeriod * 60000;
    pSync = new TSync(true);
    tiSync->Enabled = true;

    //bool x = dmMain->SendMail("it@aptekar76.ru","������!","��� �������� �����");

    //x = 0;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::mmnUserlistClick(TObject *Sender)
{
    AccountsForm = new TAccountsForm(this);
    AccountsForm->ShowModal();
    delete AccountsForm;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::mmnExitClick(TObject *Sender)
{
    if(!pbProgress->Visible)
        Close();
    else
        TerminateProcess(GetCurrentProcess(),1);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::mmnClientClick(TObject *Sender)
{
    ClientsForm = new TClientsForm(this);
    ClientsForm->ShowModal();
    delete ClientsForm;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::mmnServicesClick(TObject *Sender)
{
    ServicesForm = new TServicesForm(this);
    ServicesForm->ShowModal();
    delete ServicesForm;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::mmnSettingsClick(TObject *Sender)
{
    SettingsForm = new TSettingsForm(this);
    SettingsForm->ShowModal();
    delete SettingsForm;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::mmnAbTypeClick(TObject *Sender)
{
    AbTypesForm = new TAbTypesForm(this);
    AbTypesForm->ShowModal();
    delete AbTypesForm;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::mmnPersonalClick(TObject *Sender)
{
    PersonalForm = new TPersonalForm(this);
    PersonalForm->ShowModal();
    delete PersonalForm;
}
//---------------------------------------------------------------------------
AnsiString __fastcall TMainForm::repCreated(bool fPeriod)
{
    AnsiString sCap = "������������: " + Now() + " [";

    if(fPeriod)
    {
        if(UserID == 0)
            sCap += "root]";
        else
            sCap += (UserAcc + "]");
        return sCap;
    }

    AnsiString *pUsers;
    int ucnt = SQL_fldCollect(DBName,"StarsUser",("from Stars inner join Sessions on Stars.RowID=UserID where UserID!=0 and UserID!=4 and BegDate>="+AnsiString((int)Now())+" order by StarsUser").c_str(),&pUsers,true,false,true);
    for(int ui = 0; ui < ucnt; ui++)
        sCap += (pUsers[ui]+",");
    delete [] pUsers;
    if(ucnt > 0)
        sCap.SetLength(sCap.Length()-1);
    sCap += "]";

    if(UserID == 0)
        sCap += " - root";
    else if(UserID == 4)
        sCap += " - �������";

    return sCap;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::mmnRepBalanseClick(TObject *Sender)
{
    AbonementsSPAFullUpdate();
    bool Period = true;

    if(AdminMode || UserGrants[12] != '0')
    {
        SQL_exefun(DBName,"select SettingsVal from Settings where SettingsKey='repBalansePeriod'",&retString);
        Period = !(atoi(retString.c_str()) == 0);
    }

    TDateTime bdt;
    TDateTime edt;

    if(Period)
    {
        DateIntervalForm = new TDateIntervalForm(this);

        DTI_BegDate = Now();
        DTI_EndDate = DTI_BegDate;
        FormResult = 0;
        DateIntervalForm->ShowModal();
        delete DateIntervalForm;

        if(FormResult != 1) return;
        bdt = DTI_BegDate;
        edt = DTI_EndDate + 1;
    }
    else
    {
         bdt = Now();
         edt = bdt + 1;
    }

    unsigned Start = (int)bdt;
    unsigned Finish = (int)edt;

    //AnsiString sql = "select count(*) from Clients inner join (";
    //sql += "select distinct ClientID from Bills where BegBalanse!=EndBalanse and CDate>=";
    //sql += Start;
    //sql += " and EDate<";
    //sql += Finish;
    //sql += ") on RowID=ClientID";

    //SQL_BeginTransaction(NULL,NULL);

    AnsiString sql = "select count(distinct a.RowID) from Clients a inner join Bills b on a.RowID=ClientID where b.CDate>=";
    sql += Start;
    sql += " and b.EDate<";
    sql += Finish;
    sql += " and BegBalanse!=EndBalanse";

    SQL_exefun(DBName,sql.c_str(),&retString);
    unsigned cnt = atoi(retString.c_str());
    //if(!cnt)
    //{
    //    Application->MessageBox("��������!\n��� ������ ��� ������.","������ �����",MB_OK);
    //    return;
    //}

    pbProgress->Width = ClientWidth;
    pbProgress->Height = ClientHeight;
    pbProgress->Left = 0;
    pbProgress->Top = 0;
    pbProgress->Step = 1;
    pbProgress->Min = 0;
    pbProgress->Position = 0;

    if(cnt)
        pbProgress->Max = cnt - 1;
    else
        pbProgress->Max = 0;

    pbProgress->Visible = true;

    bool mV[5], mE[5];
    mV[0] = mmnRefbook->Visible;
    mV[1] = mmnService->Visible;
    mV[2] = mmnReport->Visible;
    mV[3] = mmnAdmin->Visible;
    mV[4] = mmnGoods->Visible;

    mE[0] = mmnRefbook->Enabled;
    mE[1] = mmnService->Enabled;
    mE[2] = mmnReport->Enabled;
    mE[3] = mmnAdmin->Enabled;
    mE[4] = mmnGoods->Enabled;

    mmnRefbook->Enabled = false;
    mmnService->Enabled = false;
    mmnReport->Enabled = false;
    mmnAdmin->Enabled = false;
    mmnGoods->Enabled = false;

    sql = "select distinct a.RowID,FName,SName,TName from Clients a inner join Bills b on a.RowID=ClientID where b.CDate>=";
    sql += Start;
    sql += " and b.EDate<";
    sql += Finish;
    sql += " and BegBalanse!=EndBalanse order by b.CDate";

    //sql = "select RowID,FName,SName,TName from Clients inner join (";
    //sql += "select distinct ClientID from Bills where BegBalanse!=EndBalanse and CDate>=";
    //sql += Start;
    //sql += " and EDate<";
    //sql += Finish;
    //sql += ") on RowID=ClientID order by FName,SName,TName";

    repClientsIDs = new __int64[cnt];
    repClientsFNames = new AnsiString[cnt];
    repClientsSNames = new AnsiString[cnt];
    repClientsTNames = new AnsiString[cnt];
    repClientsBegBalanse = new AnsiString[cnt];

    repClientsToBalanseBN = new AnsiString[cnt];

    repClientsToBalanse = new AnsiString[cnt];
    repClientsFromBalanse = new AnsiString[cnt];
    repClientsEndBalanse = new AnsiString[cnt];
    repClientsCounter = 0;

    SQL_exe(DBName,sql.c_str(),clientsfrombills_select);

    // ��������� �����
    repBalanseForm = new TrepBalanseForm(this);
    repBegBalanseSum = 0.0;
    repFromBalanseSum = 0.0;
    repToBalanseSum = 0.0;
    repToBalanseBNSum = 0.0;

    repEndBalanseSum = 0.0;

    for(repClientsCounter = 0; repClientsCounter < cnt; repClientsCounter++)
    {
        sql = "select BegBalanse,FromBalanse,ToBalanse,EndBalanse,Payment from Bills where ClientID=";
        sql += repClientsIDs[repClientsCounter];
        sql += " and BegBalanse!=EndBalanse and CDate>=";
        sql += Start;
        sql += " and EDate<";
        sql += Finish;
        //sql += " order by CDate";

        repBillsCounter = 0;

        SQL_exe(DBName,sql.c_str(),billstorep_select);

        repClientsFromBalanse[repClientsCounter] = FormatFloat(MoneyFormat,-strtof(repClientsFromBalanse[repClientsCounter].c_str()));
        repClientsToBalanse[repClientsCounter] = FormatFloat(MoneyFormat,strtof(repClientsToBalanse[repClientsCounter].c_str()));
        repClientsToBalanseBN[repClientsCounter] = FormatFloat(MoneyFormat,strtof(repClientsToBalanseBN[repClientsCounter].c_str()));

        repBalanseForm->QRlines->Items->Add(repClientsCounter);

        repBegBalanseSum += atof(repClientsBegBalanse[repClientsCounter].c_str());
        repFromBalanseSum += atof(repClientsFromBalanse[repClientsCounter].c_str());
        repToBalanseSum += atof(repClientsToBalanse[repClientsCounter].c_str());
        repToBalanseBNSum += atof(repClientsToBalanseBN[repClientsCounter].c_str());
        repEndBalanseSum += atof(repClientsEndBalanse[repClientsCounter].c_str());

        pbProgress->StepIt();
        Application->ProcessMessages();
    }

    //SQL_CancelTransaction();

    if(Period)
        repBalanseForm->QRHeader->Caption = "����� �� ���������� �������� � "+bdt.DateString()+" �� "+(edt-1).DateString();
    else
        repBalanseForm->QRHeader->Caption = "����� �� ���������� �������� �� "+bdt.DateString();

    repBalanseForm->QRCreated->Caption = repCreated(Start < (Finish - 1));

    pbProgress->Visible = false;
    repBalanseForm->QuickRep1->Preview();

    PDEL(repClientsIDs);
    PDEL(repClientsFNames);
    PDEL(repClientsSNames);
    PDEL(repClientsTNames);
    PDEL(repClientsBegBalanse);
    PDEL(repClientsToBalanse);
    PDEL(repClientsToBalanseBN);
    PDEL(repClientsFromBalanse);
    PDEL(repClientsEndBalanse);

    delete repBalanseForm;

    mmnRefbook->Visible = mV[0];
    mmnService->Visible = mV[1];
    mmnReport->Visible = mV[2];
    mmnAdmin->Visible = mV[3];
    mmnGoods->Visible = mV[4];

    mmnRefbook->Enabled = mE[0];
    mmnService->Enabled = mE[1];
    mmnReport->Enabled = mE[2];
    mmnAdmin->Enabled = mE[3];
    mmnGoods->Enabled = mE[4];
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::mmnRepNegBalanseClick(TObject *Sender)
{
    AbonementsSPAFullUpdate();

    TDateTime dt = Now();

    AnsiString sql = "select count(*) from Clients where Balanse<0";

    SQL_exefun(DBName,sql.c_str(),&retString);
    unsigned cnt = atoi(retString.c_str());
    //if(!cnt)
    //{
    //    Application->MessageBox("��������!\n��� ������ ��� ������.","������ �����",MB_OK);
    //    return;
    //}

    sql = "select RowID,FName,SName,TName from Clients where Balanse<0 order by FName,SName,TName";

    repClientsIDs = new __int64[cnt];
    repClientsFNames = new AnsiString[cnt];
    repClientsSNames = new AnsiString[cnt];
    repClientsTNames = new AnsiString[cnt];
    repClientsEndBalanse = new AnsiString[cnt];
    repClientsCounter = 0;

    SQL_exe(DBName,sql.c_str(),clientsfrombills_select);

    // ��������� �����
    repNegBalanseForm = new TrepNegBalanseForm(this);
    repEndBalanseSum = 0.0;

    for(repClientsCounter = 0; repClientsCounter < cnt; repClientsCounter++)
    {
        SQL_exefun(DBName,("select Balanse from Clients where RowID="+(AnsiString)repClientsIDs[repClientsCounter]).c_str(),&repClientsEndBalanse[repClientsCounter]);

        repNegBalanseForm->QRlines->Items->Add(repClientsCounter);
        repEndBalanseSum += atof(repClientsEndBalanse[repClientsCounter].c_str());
    }

    repNegBalanseForm->QRHeader->Caption = "����� �� ���������� �������������� �� " + dt.DateString();
    repNegBalanseForm->QRCreated->Caption = repCreated(false);

    repNegBalanseForm->QuickRep1->Preview();

    PDEL(repClientsIDs);
    PDEL(repClientsFNames);
    PDEL(repClientsSNames);
    PDEL(repClientsTNames);
    PDEL(repClientsEndBalanse);

    delete repNegBalanseForm;
}
//---------------------------------------------------------------------------
static int getid_clients(void *NotUsed, int argc, char **argv, char **azColName)
{
    __int64 ID = ATOI64(argv[0]);

    if(!ID) return 0;

    MainForm->repClientsIDs[MainForm->repClientsCounter++] = ID;

    return 0;
}
//---------------------------------------------------------------------------
__int64 zRowID[2],zAbTypeID[2];
double zPrice[2];
double zPriceReal[2];
unsigned zCount[2];
unsigned zCountReal[2];
unsigned zVisits[2];
TDateTime zBegDate[2];
TDateTime zEndDate[2];
double zFixSum[2];
unsigned zCounter;

static int abs_patch(void *NotUsed, int argc, char **argv, char **azColName)
{
    __int64 ID = (argv[0])? _atoi64(argv[0]) : 0;
    __int64 AbTypeID = (argv[1])? _atoi64(argv[1]) : 0;

    if(!ID || !AbTypeID) return 0;

    SQL_exefun(DBName,("select count(*) from Visits where AbonementID="+(AnsiString)ID).c_str(),&MainForm->retString);
    zVisits[zCounter] = atoi(MainForm->retString.c_str());
    AnsiString price;
    SQL_exefun2(DBName,("select AbTypesCount,Price from AbTypes where RowID="+(AnsiString)AbTypeID).c_str(),&MainForm->retString,&price);
    zCountReal[zCounter] = atoi(MainForm->retString.c_str());
    zPriceReal[zCounter] = atof(price.c_str());

    zRowID[zCounter] = ID;
    zAbTypeID[zCounter] = AbTypeID;
    zPrice[zCounter] = (argv[2])? atof(argv[2]) : 0.0;
    zCount[zCounter] = (argv[3])? atoi(argv[3]) : 0;

    zBegDate[zCounter] = (argv[4])? atoi(argv[4]) : 0;
    zEndDate[zCounter] = (argv[5])? atoi(argv[5]) : 0;
    zFixSum[zCounter] = (argv[6])? atof(argv[6]) : 0.0;

    zCounter++;

    return 0;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::mmnRepVisitsClick(TObject *Sender)
{
    SQL_exefun(DBName,"select SettingsVal from Settings where SettingsKey='NoAbsToRep'",&retString);
    bool OnlyAbsToRep = atoi(retString.c_str()) == 0;

    bool Period = true;

    if(AdminMode || UserGrants[12] != '0')
    {
        SQL_exefun(DBName,"select SettingsVal from Settings where SettingsKey='repVisitsPeriod'",&retString);
        Period = !(atoi(retString.c_str()) == 0);
    }
    
    TDateTime bdt;
    TDateTime edt;

    if(Period)
    {
        DateIntervalForm = new TDateIntervalForm(this);

        DTI_BegDate = Now();
        DTI_EndDate = DTI_BegDate;
        FormResult = 0;
        DateIntervalForm->ShowModal();
        delete DateIntervalForm;

        if(FormResult != 1) return;
        bdt = DTI_BegDate;
        edt = DTI_EndDate + 1;
    }
    else
    {
         bdt = Now();
         edt = bdt + 1;
    }

    unsigned Start = (int)bdt;
    unsigned Finish = (int)edt;

    // ����� ������� ������ ������/�������
    AnsiString *psPID, *psPID2;

    AnsiString sql = "from Visits where VisitsDate>=";
    sql += Start;
    sql += " and VisitsDate<";
    sql += Finish;
    unsigned cnt_visits = SQL_fldCollect(DBName,"PersonID",sql.c_str(),&psPID,false,false,true);

    // � ��� �� ��������� �����������

    sql = "from Abonements where CDate>=";
    sql += Start;
    sql += " and CDate<";
    sql += Finish;
    if(OnlyAbsToRep)
        sql += " and FixSum>=0";
    unsigned cnt_abonements = SQL_fldCollect(DBName,"PersonID",sql.c_str(),&psPID2,false,false,true);

    //if(cnt_visits + cnt_abonements == 0)
    //{
    //    Application->MessageBox("��������!\n��� ������ ��� ������.","������ �����",MB_OK);
    //    return;
    //}

    pbProgress->Width = ClientWidth;
    pbProgress->Height = ClientHeight;
    pbProgress->Left = 0;
    pbProgress->Top = 0;
    pbProgress->Step = 1;
    pbProgress->Min = 0;
    pbProgress->Position = 0;

    bool mV[5], mE[5];
    mV[0] = mmnRefbook->Visible;
    mV[1] = mmnService->Visible;
    mV[2] = mmnReport->Visible;
    mV[3] = mmnAdmin->Visible;
    mV[4] = mmnGoods->Visible;

    mE[0] = mmnRefbook->Enabled;
    mE[1] = mmnService->Enabled;
    mE[2] = mmnReport->Enabled;
    mE[3] = mmnAdmin->Enabled;
    mE[4] = mmnGoods->Enabled;

    mmnRefbook->Enabled = false;
    mmnService->Enabled = false;
    mmnReport->Enabled = false;
    mmnAdmin->Enabled = false;
    mmnGoods->Enabled = false;

    // ������� ������
    unsigned i;
    bool fZero = false;

    sql = "from Personal where RowID in (0,";
    for(i = 0; i < cnt_visits; i++)
    {
        if(_atoi64(psPID[i].c_str()) == 0)
            fZero = true;

        sql += (AnsiString(psPID[i]) + ",");
    }

    for(i = 0; i < cnt_abonements; i++)
    {
        if(_atoi64(psPID2[i].c_str()) == 0)
            fZero = true;
        else
            sql += (AnsiString(psPID2[i]) + ",");
    }

//    if(cnt_visits + cnt_abonements == 0)
//        sql += "0";
//    else
    sql.SetLength(sql.Length() - 1);

    sql += ") order by Name,CDate";

    delete [] psPID;
    delete [] psPID2;

    __int64 *pPIDs;

    unsigned cnt_persons = SQL_fldKeyCollect(DBName,"Name",sql.c_str(),&pPIDs,&psPID,true,fZero);

    if(fZero)
    {
        pPIDs[0] = 0;
        psPID[0] = "��� �������";
    }

    if(cnt_persons)
        pbProgress->Max = cnt_persons - 1;
    else
        pbProgress->Max = 0;
    pbProgress->Visible = true;

    TList *pList = new TList;
    AnsiString *pLines;

    repVisitsForm = new TrepVisitsForm(this);
    if(Period)
        repVisitsForm->QRHeader->Caption = "����� �� ������� ������� � " + bdt.DateString() + " �� " + (edt-1).DateString();
    else
        repVisitsForm->QRHeader->Caption = "����� �� ������� ������� �� " + (edt-1).DateString();
    repVisitsForm->QRCreated->Caption = repCreated(Start < (Finish - 1));

    repVisitsForm->pPrint = pList;

    pList->Add(NULL);
    repVisitsForm->QRlines->Items->Add("E");

    for(unsigned cnt_p = 0; cnt_p < cnt_persons; cnt_p++)
    {
        // ������� ����� �� ������� ?

        AnsiString *psSID, *psSID2;

        sql = "from Visits where PersonID=";
        sql += pPIDs[cnt_p];
        sql += " and VisitsDate>=";
        sql += Start;
        sql += " and VisitsDate<";
        sql += Finish;
        cnt_visits = SQL_fldCollect(DBName,"ServiceID",sql.c_str(),&psSID,false,false,true);

        sql = "from Abonements where PersonID=";
        sql += pPIDs[cnt_p];
        sql += " and CDate>=";
        sql += Start;
        sql += " and CDate<";
        sql += Finish;
        if(OnlyAbsToRep)
            sql += " and FixSum>=0";
        cnt_abonements = SQL_fldCollect(DBName,"ServiceID",sql.c_str(),&psSID2,false,false,true);

        // ������� ������
        unsigned cnt_services = 0;
        fZero = false;
        __int64 *pSIDs = NULL;

        if(cnt_visits + cnt_abonements)
        {
            sql = "from Services where RowID in (0,";
            for(i = 0; i < cnt_visits; i++)
            {
                if(_atoi64(psSID[i].c_str()) == 0)
                    fZero = true;
                else
                    sql += (AnsiString(psSID[i]) + ",");
            }

            for(i = 0; i < cnt_abonements; i++)
            {
                if(_atoi64(psSID2[i].c_str()) == 0)
                    fZero = true;
                else
                    sql += (AnsiString(psSID2[i]) + ",");
            }

            sql.SetLength(sql.Length() - 1);
            sql += ") order by Name,CDate";

            delete [] psSID;
            delete [] psSID2;

            cnt_services = SQL_fldKeyCollect(DBName,"Name",sql.c_str(),&pSIDs,&psSID,true,fZero,true);

            if(fZero)
            {
                pSIDs[0] = 0;
                psSID[0] = "�� �������";
            }
        }

        for(unsigned cnt_s = 0; cnt_s < cnt_services; cnt_s++)
        {
            // ������� ����� - ������.������� - ���������� - ��������� - ���������
            AnsiString *psCID, *psCID2;

            sql = "from Abonements inner join (select AbonementID from Visits where PersonID=";
            sql += pPIDs[cnt_p];
            sql += " and ServiceID=";
            sql += pSIDs[cnt_s];
            sql += " and VisitsDate>=";
            sql += Start;
            sql += " and VisitsDate<";
            sql += Finish;
            sql += ") on RowID=AbonementID";

            cnt_visits = SQL_fldCollect(DBName,"ClientID",sql.c_str(),&psCID,false,false,true);

            sql = "from Abonements where PersonID=";
            sql += pPIDs[cnt_p];
            sql += " and ServiceID=";
            sql += pSIDs[cnt_s];
            sql += " and CDate>=";
            sql += Start;
            sql += " and CDate<";
            sql += Finish;
            if(OnlyAbsToRep)
                sql += " and FixSum>=0";

            cnt_abonements = SQL_fldCollect(DBName,"ClientID",sql.c_str(),&psCID2,false,false,true);

             __int64 *pCIDs = NULL;
             unsigned cnt_clients = 0;

            if(cnt_visits + cnt_abonements)
            {
                sql = "from Clients where RowID in (0,";
                for(i = 0; i < cnt_visits; i++)
                    sql += (AnsiString(psCID[i]) + ",");

                for(i = 0; i < cnt_abonements; i++)
                    sql += (AnsiString(psCID2[i]) + ",");

                sql.SetLength(sql.Length() - 1);
                sql += ") order by FullName,CDate";

                delete [] psCID;
                delete [] psCID2;

                cnt_clients = SQL_fldKeyCollect(DBName,"FullName",sql.c_str(),&pCIDs,&psCID,true,false,true);
            }
            
            AnsiString *pLines;

            for(unsigned cnt_c = 0; cnt_c < cnt_clients; cnt_c++)
            {
                pLines = new AnsiString[4];

                if(!cnt_c)
                {
                    pLines[0] = psPID[cnt_p] + " / " + psSID[cnt_s];
                    repVisitsForm->QRlines->Items->Add("H");
                }
                else
                    repVisitsForm->QRlines->Items->Add("L");

                pLines[1] = psCID[cnt_c];

                // ���������
                sql = "from Visits where PersonID=";
                sql += pPIDs[cnt_p];
                sql += " and ServiceID=";
                sql += pSIDs[cnt_s];
                sql += " and VisitsDate>=";
                sql += Start;
                sql += " and VisitsDate<";
                sql += Finish;
                sql += " and AbonementID in (select RowID from Abonements where ClientID=";
                sql += pCIDs[cnt_c];
                sql += ")";

                cnt_visits = SQL_fldCollect(DBName,"Price",sql.c_str(),&psCID2);

                double price;

                if(cnt_visits)
                {
                    price = 0.0;
                    for(unsigned i = 0; i < cnt_visits; i++)
                        price += atof(psCID2[i].c_str());

                    delete [] psCID2;
                    pLines[2] = FormatFloat(MoneyFormat,price) + " (" + cnt_visits + ")";
                }

                // ����������
                sql = "from Abonements where PersonID=";
                sql += pPIDs[cnt_p];
                sql += " and ServiceID=";
                sql += pSIDs[cnt_s];
                sql += " and CDate>=";
                sql += Start;
                sql += " and CDate<";
                sql += Finish;
                sql += " and ClientID=";
                sql += pCIDs[cnt_c];
                if(OnlyAbsToRep)
                    sql += " and FixSum>=0";

                cnt_abonements = SQL_fldCollect(DBName,"Price",sql.c_str(),&psCID2);

                if(cnt_abonements)
                {
                    price = 0.0;
                    for(unsigned i = 0; i < cnt_abonements; i++)
                        price += atof(psCID2[i].c_str());

                    delete [] psCID2;
                    pLines[3] = FormatFloat(MoneyFormat,price) + " (" + cnt_abonements + ")";
                }
                
                pList->Add(pLines);

            }

            pLines = new AnsiString[4];
            pLines[0] = "�����:";
            pList->Add(pLines);
            repVisitsForm->QRlines->Items->Add("I");
            pList->Add(NULL);
            repVisitsForm->QRlines->Items->Add("E");

            delete [] psCID;
            delete [] pCIDs;
        }

        delete [] psSID;
        delete [] pSIDs;

        pbProgress->StepIt();
        Application->ProcessMessages();
    }

    delete [] psPID;
    delete [] pPIDs;

    pbProgress->Visible = false;
    repVisitsForm->QuickRep1->Preview();

    AnsiString *pS;

    for(int i = 0; i < pList->Count; i++)
        if((pS = (AnsiString *)pList->Items[i]) != NULL) delete [] pS;
        
    delete pList;
    delete repVisitsForm;

    mmnRefbook->Visible = mV[0];
    mmnService->Visible = mV[1];
    mmnReport->Visible = mV[2];
    mmnAdmin->Visible = mV[3];
    mmnGoods->Visible = mV[4];

    mmnRefbook->Enabled = mE[0];
    mmnService->Enabled = mE[1];
    mmnReport->Enabled = mE[2];
    mmnAdmin->Enabled = mE[3];
    mmnGoods->Enabled = mE[4];
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DelClients1Click(TObject *Sender)
{
    SQL_BeginTransaction();

    SQL_exe(DBName,"delete from Clients where Alive=0");

    SQL_exe(DBName,"delete from Bills where ClientID not in (select RowID from Clients)");
    SQL_exe(DBName,"delete from BillItems where BillID not in (select RowID from Bills)");

    SQL_exe(DBName,"delete from Abonements where ClientID not in (select RowID from Clients)");
    SQL_exe(DBName,"delete from Visits where AbonementID not in (select RowID from Abonements)");

    SQL_exe(DBName,"delete from Abonements_SPA where ClientID not in (select RowID from Clients)");
    SQL_exe(DBName,"delete from Visits_SPA where ClientID=0 and AbonementID not in (select RowID from Abonements_SPA)");

    SQL_CommitTransaction();

    Application->MessageBox("���������� ������� �������.","�������� ��������",MB_OK);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::mmnGoodsListClick(TObject *Sender)
{
    GoodsForm = new TGoodsForm(this);
    GoodsForm->KassaMode = false;
    GoodsForm->ShowModal();
    delete GoodsForm;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::mmnGoodsInputClick(TObject *Sender)
{
    GoodsIncomeForm = new TGoodsIncomeForm(this);
    GoodsIncomeForm->ShowModal();
    delete GoodsIncomeForm;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::mmnRepVisitsSPAClick(TObject *Sender)
{
    bool Period = true;

    if(AdminMode || UserGrants[12] != '0')
    {
        SQL_exefun(DBName,"select SettingsVal from Settings where SettingsKey='repVisitsSPAPeriod'",&retString);
        Period = !(atoi(retString.c_str()) == 0);
    }

    TDateTime bdt;
    TDateTime edt;

    if(Period)
    {
        DateIntervalForm = new TDateIntervalForm(this);

        DTI_BegDate = Now();
        DTI_EndDate = DTI_BegDate;
        FormResult = 0;
        DateIntervalForm->ShowModal();
        delete DateIntervalForm;

        if(FormResult != 1) return;
        bdt = DTI_BegDate;
        edt = DTI_EndDate + 1;
    }
    else
    {
         bdt = Now();
         edt = bdt + 1;
    }

    unsigned Start = (int)bdt;
    unsigned Finish = (int)edt;

    AnsiString *psPID;

    AnsiString sql = "from Visits_SPA inner join Services on ServiceID=Services.RowID where Visits_SPADate>=";
    sql += Start;
    sql += " and Visits_SPADate<";
    sql += Finish;
    sql += " and Tag like '~SPA~%'";

    unsigned cnt_visits = SQL_fldCollect(DBName,"PersonID",sql.c_str(),&psPID,false,false,true);

    //if(cnt_visits == 0)
    //{
    //    Application->MessageBox("��������!\n��� ������ ��� ������.","������ �����",MB_OK);
    //    return;
    //}

    pbProgress->Width = ClientWidth;
    pbProgress->Height = ClientHeight;
    pbProgress->Left = 0;
    pbProgress->Top = 0;
    pbProgress->Step = 1;
    pbProgress->Min = 0;
    pbProgress->Position = 0;

    bool mV[5], mE[5];
    mV[0] = mmnRefbook->Visible;
    mV[1] = mmnService->Visible;
    mV[2] = mmnReport->Visible;
    mV[3] = mmnAdmin->Visible;
    mV[4] = mmnGoods->Visible;

    mE[0] = mmnRefbook->Enabled;
    mE[1] = mmnService->Enabled;
    mE[2] = mmnReport->Enabled;
    mE[3] = mmnAdmin->Enabled;
    mE[4] = mmnGoods->Enabled;

    mmnRefbook->Enabled = false;
    mmnService->Enabled = false;
    mmnReport->Enabled = false;
    mmnAdmin->Enabled = false;
    mmnGoods->Enabled = false;

    unsigned i;
    bool fZero = false;

    sql = "from Personal where RowID in (";
    for(i = 0; i < cnt_visits; i++)
    {
        if(_atoi64(psPID[i].c_str()) == 0)
            fZero = true;

        sql += (AnsiString(psPID[i]) + ",");
    }

    if(cnt_visits)
        sql.SetLength(sql.Length() - 1);
    else
        sql += "0";

    sql += ") order by Name,CDate";

    delete [] psPID;

    __int64 *pPIDs;

    unsigned cnt_persons = SQL_fldKeyCollect(DBName,"Name",sql.c_str(),&pPIDs,&psPID,true,fZero);

    if(fZero)
    {
        pPIDs[0] = 0;
        psPID[0] = "��� �����������";
    }

    if(cnt_persons)
        pbProgress->Max = cnt_persons - 1;
    else
        pbProgress->Max = 0;
    pbProgress->Visible = true;

    TList *pList = new TList;
    AnsiString *pLines;
    AnsiString sRow[5];
    AnsiString *psVID;

    //char *Tags[] = { "������", "�����������" };
    AnsiString *Tags;

    unsigned l2cnt = SQL_fldCollect(NULL,"Name","from Services where Tag='~SPA~'",&Tags);

    repVisitsSPAForm = new TrepVisitsSPAForm(this);
    if(Period)
        repVisitsSPAForm->QRHeader->Caption = "����� �� ������� SPA � " + bdt.DateString() + " �� " + (edt-1).DateString();
    else
        repVisitsSPAForm->QRHeader->Caption = "����� �� ������� SPA �� " + (edt-1).DateString();
    repVisitsSPAForm->QRCreated->Caption = repCreated(Start < (Finish - 1));

    repVisitsSPAForm->pPrint = pList;

    pList->Add(NULL);
    repVisitsSPAForm->QRlines->Items->Add("E");

    for(unsigned cnt_p = 0; cnt_p < cnt_persons; cnt_p++)
    {
        for(unsigned tags_cnt = 0; tags_cnt < l2cnt; tags_cnt++)
        {
            sql = "from Visits_SPA where PersonID=";
            sql += pPIDs[cnt_p];
            sql += " and Visits_SPADate>=";
            sql += Start;
            sql += " and Visits_SPADate<";
            sql += Finish;
            sql += (AnsiString(" and ServiceID in (select RowID from Services where Tag like '~SPA~") + Tags[tags_cnt] + "~%') order by CDate");

            cnt_visits = SQL_fldCollect(DBName,"RowID",sql.c_str(),&psVID);

            if(cnt_visits)
            {
                pLines = new AnsiString[4];
                pLines[0] = psPID[cnt_p] + " / " + Tags[tags_cnt];
                pList->Add(pLines);
                repVisitsSPAForm->QRlines->Items->Add("H");
            }
            else
                continue;

            for(unsigned cnt_v = 0; cnt_v < cnt_visits; cnt_v++)
            {
                pLines = new AnsiString[4];

                SQL_exefunrow(DBName,("select ServiceID,AbonementID,ClientID,Price,PersonPrice from Visits_SPA where RowID="+AnsiString(_atoi64(psVID[cnt_v].c_str()))).c_str(),5,sRow);
                SQL_exefun(DBName,("select '['||b.Name||']'||a.Name from Services a left outer join Services b on a.ParentID=b.RowID where a.RowID="+AnsiString(_atoi64(sRow[0].c_str()))).c_str(),&retString);

                pLines[0] = retString;

                if(!_atoi64(sRow[1].c_str()))
                    SQL_exefun(DBName,("select FName||' '||SName||' '||TName from Clients where RowID="+AnsiString(_atoi64(sRow[2].c_str()))).c_str(),&retString);
                else
                    SQL_exefun(DBName,("select FName||' '||SName||' '||TName from Clients where RowID=(select ClientID from Abonements_SPA where RowID="+AnsiString(_atoi64(sRow[1].c_str()))+")").c_str(),&retString);

                pLines[1] = retString;

                double price = atof(sRow[3].c_str());
                double pprice = atof(sRow[4].c_str());

                //if(pprice == 0.0)
                //    pLines[2] = FormatFloat(MoneyFormat,price) + " / 0.00";
                //else
                pLines[2] = FormatFloat(MoneyFormat,pprice) + " / " + FormatFloat(MoneyFormat,price-pprice);

                repVisitsSPAForm->QRlines->Items->Add("L");

                pList->Add(pLines);

            }

            pLines = new AnsiString[4];
            pLines[0] = "�����:";
            pList->Add(pLines);
            repVisitsSPAForm->QRlines->Items->Add("I");
            pList->Add(NULL);
            repVisitsSPAForm->QRlines->Items->Add("E");

            delete [] psVID;
        }

        pbProgress->StepIt();
        Application->ProcessMessages();
    }

    delete [] psPID;
    delete [] pPIDs;

    delete [] Tags;

    pbProgress->Visible = false;
    repVisitsSPAForm->QuickRep1->Preview();

    AnsiString *pS;

    for(int i = 0; i < pList->Count; i++)
        if((pS = (AnsiString *)pList->Items[i]) != NULL) delete [] pS;

    delete pList;
    delete repVisitsSPAForm;

    mmnRefbook->Visible = mV[0];
    mmnService->Visible = mV[1];
    mmnReport->Visible = mV[2];
    mmnAdmin->Visible = mV[3];
    mmnGoods->Visible = mV[4];

    mmnRefbook->Enabled = mE[0];
    mmnService->Enabled = mE[1];
    mmnReport->Enabled = mE[2];
    mmnAdmin->Enabled = mE[3];
    mmnGoods->Enabled = mE[4];
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::UpdateBranchTags(__int64 ID,AnsiString Tag)
{
    //if(SQL_BeginTransaction(DBName,"main.UpdateBranchTags") != SQLITE_OK) return;

    __int64 *pIDs;
    AnsiString *pNames;
    AnsiString sTag;

    unsigned cnt = SQL_fldKeyCollect(DBName,"Name",("from Services where ParentID="+AnsiString(ID)).c_str(),&pIDs,&pNames);

    for(unsigned i = 0; i < cnt; i++)
    {
        SQL_iniUpdate(DBName,"Services",pIDs[i]);
        SQL_exeUpdate("!Tag",Tag);

        sTag = Tag + pNames[i] + "~";
        UpdateBranchTags(pIDs[i],sTag);
    }

    //SQL_CommitTransaction("main.UpdateBranchTags");

    delete [] pNames;
    delete [] pIDs;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::UpdateAllTags(void)
{
    SQL_BeginTransaction();

    SQL_exe(DBName,"update Services set Tag='~' where ParentID=0");

    __int64 *pIDs;
    AnsiString *pNames;
    AnsiString sTag;

    unsigned cnt = SQL_fldKeyCollect(DBName,"Name","from Services where ParentID=0",&pIDs,&pNames);

    for(unsigned i = 0; i < cnt; i++)
    {
        sTag = "~" + pNames[i] + "~";
        UpdateBranchTags(pIDs[i],sTag);
    }

    SQL_CommitTransaction();

    delete [] pNames;
    delete [] pIDs;

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::UpdateAllTags1Click(TObject *Sender)
{
    UpdateAllTags();
    Application->MessageBox("All Tags updated.","",MB_OK);    
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::mmnRepAbsSPAClick(TObject *Sender)
{
    AbonementsSPAFullUpdate();

    bool Period = true;

    if(AdminMode || UserGrants[12] != '0')
    {
        SQL_exefun(DBName,"select SettingsVal from Settings where SettingsKey='repBalanseSPAPeriod'",&retString);
        Period = !(atoi(retString.c_str()) == 0);
    }

    TDateTime bdt;
    TDateTime edt;

    if(Period)
    {
        DateIntervalForm = new TDateIntervalForm(this);

        DTI_BegDate = Now();
        DTI_EndDate = DTI_BegDate;
        FormResult = 0;
        DateIntervalForm->ShowModal();
        delete DateIntervalForm;

        if(FormResult != 1) return;
        bdt = DTI_BegDate;
        edt = DTI_EndDate + 1;
    }
    else
    {
         bdt = Now();
         edt = bdt + 1;
    }

    unsigned Start = (int)bdt;
    unsigned Finish = (int)edt;

    AnsiString sql =

"select count(*) from Clients c "
"inner join "
"( "
    "select a.ClientID as SCID from Abonements_SPA a where a.CDate>=";

    sql += Start;
    sql +=

    " and a.CDate<";

    sql += Finish;
    sql +=

    " union "
    "select case when b.ClientID=0 then d.ClientID else b.ClientID end as SCID from Visits_SPA b "
    "inner join Abonements_SPA d on AbonementID=d.RowID "
    "where b.Visits_SPADate>=";

    sql += Start;
    sql +=

    " and b.Visits_SPADate<";
    sql += Finish;
    sql +=

    " ) on c.RowID=SCID";

    SQL_exefun(DBName,sql.c_str(),&retString);
    unsigned cnt = atoi(retString.c_str());

    //if(!cnt)
    //{
    //    Application->MessageBox("��������!\n��� ������ ��� ������.","������ �����",MB_OK);
    //    return;
    //}

    pbProgress->Width = ClientWidth;
    pbProgress->Height = ClientHeight;
    pbProgress->Left = 0;
    pbProgress->Top = 0;
    pbProgress->Step = 1;
    pbProgress->Min = 0;
    pbProgress->Position = 0;
    if(cnt)
        pbProgress->Max = cnt - 1;
    else
        pbProgress->Max = 0;
    pbProgress->Visible = true;

    bool mV[5], mE[5];
    mV[0] = mmnRefbook->Visible;
    mV[1] = mmnService->Visible;
    mV[2] = mmnReport->Visible;
    mV[3] = mmnAdmin->Visible;
    mV[4] = mmnGoods->Visible;

    mE[0] = mmnRefbook->Enabled;
    mE[1] = mmnService->Enabled;
    mE[2] = mmnReport->Enabled;
    mE[3] = mmnAdmin->Enabled;
    mE[4] = mmnGoods->Enabled;

    mmnRefbook->Enabled = false;
    mmnService->Enabled = false;
    mmnReport->Enabled = false;
    mmnAdmin->Enabled = false;
    mmnGoods->Enabled = false;

    //sql = "select distinct RowID,FName,SName,TName from Clients where RowID in (";
    //sql += "select ClientID from Abonements_SPA where CDate>=";
    //sql += Start;
    //sql += " and CDate<";
    //sql += Finish;
    //sql += ") or RowID in (";
    //sql += "select Abonements_SPA.ClientID from Visits_SPA inner join Abonements_SPA on AbonementID=Abonements_SPA.RowID where Visits_SPADate>=";
    //sql += Start;
    //sql += " and Visits_SPADate<";
    //sql += Finish;
    //sql += ") order by FName,SName,TName";

    sql = StringReplace(sql,"count(*)","c.RowID,c.FName,c.SName,c.TName",TReplaceFlags());
    sql += " order by c.FullName";

    repClientsIDs = new __int64[cnt];
    repClientsFNames = new AnsiString[cnt];
    repClientsSNames = new AnsiString[cnt];
    repClientsTNames = new AnsiString[cnt];
    repClientsBegBalanse = new AnsiString[cnt];

    repClientsToBalanseBN = new AnsiString[cnt];

    repClientsToBalanse = new AnsiString[cnt];
    repClientsFromBalanse = new AnsiString[cnt];
    repClientsEndBalanse = new AnsiString[cnt];
    repClientsCounter = 0;

    SQL_exe(DBName,sql.c_str(),clientsfrombills_select);

    // ��������� �����
    repBalanseSPAForm = new TrepBalanseSPAForm(this);
    repBegBalanseSum = 0.0;
    repFromBalanseSum = 0.0;
    repToBalanseSum = 0.0;
    repToBalanseBNSum = 0.0;

    repEndBalanseSum = 0.0;

    for(repClientsCounter = 0; repClientsCounter < cnt; repClientsCounter++)
    {
        //SQL_exefun(DBName,("select sum(Balanse) from Abonements_SPA where CDate<"+AnsiString(Start)+" and ClientID="+AnsiString(repClientsIDs[repClientsCounter])).c_str(),&retString);
        double BegBalanse; // ���������!!
        // = atof(retString.c_str());

        sql = "select sum(Price) from Visits_SPA where Visits_SPADate>=";
        sql += Start;
        sql += " and Visits_SPADate<";
        sql += Finish;
        sql += " and AbonementID in (";
        sql += "select RowID from Abonements_SPA where ClientID=";
        sql += repClientsIDs[repClientsCounter];
        sql += ")";

        SQL_exefun(DBName,sql.c_str(),&retString);
        double FromBalanse = atof(retString.c_str()); // �������!!

        sql = "select sum(ToBalanse) from Bills where Payment=-1 and CDate>=";
        sql += Start;
        sql += " and CDate<";
        sql += Finish;
        sql += " and ClientID=";
        sql += repClientsIDs[repClientsCounter];

        SQL_exefun(DBName,sql.c_str(),&retString);
        double FromBalanseBN = atof(retString.c_str()); // ��������!!

        sql = "select sum(Total) from BillItems where Op=16 and BillID in (";
        sql += "select RowID from Bills where CDate>=";
        sql += Start;
        sql += " and CDate<";
        sql += Finish;
        sql += " and ClientID=";
        sql += repClientsIDs[repClientsCounter];
        sql += ")";

        SQL_exefun(DBName,sql.c_str(),&retString);
        double ToBalanse = atof(retString.c_str()); // ����������!!

        //double EndBalanse = BegBalanse + ToBalanse - FromBalanse;
        SQL_exefun(DBName,("select sum(Balanse) from Abonements_SPA where ClientID="+AnsiString(repClientsIDs[repClientsCounter])).c_str(),&retString);

        double EndBalanse = atof(retString.c_str());
        BegBalanse = EndBalanse - ToBalanse + FromBalanse + FromBalanseBN;

        MainForm->repClientsBegBalanse[MainForm->repClientsCounter] = FormatFloat(MoneyFormat,BegBalanse);
        MainForm->repClientsFromBalanse[MainForm->repClientsCounter] = FormatFloat(MoneyFormat,FromBalanse);

        MainForm->repClientsToBalanse[MainForm->repClientsCounter] = FormatFloat(MoneyFormat,ToBalanse);

        MainForm->repClientsEndBalanse[MainForm->repClientsCounter] = FormatFloat(MoneyFormat,EndBalanse);

        repBalanseSPAForm->QRlines->Items->Add(repClientsCounter);

        repBegBalanseSum += atof(repClientsBegBalanse[repClientsCounter].c_str());
        repFromBalanseSum += atof(repClientsFromBalanse[repClientsCounter].c_str());
        repToBalanseSum += atof(repClientsToBalanse[repClientsCounter].c_str());
        repEndBalanseSum += atof(repClientsEndBalanse[repClientsCounter].c_str());

        pbProgress->StepIt();
        Application->ProcessMessages();
    }

    if(Period)
        repBalanseSPAForm->QRHeader->Caption = "����� �� ����������� SPA � " + bdt.DateString() + " �� " + (edt-1).DateString();
    else
        repBalanseSPAForm->QRHeader->Caption = "����� �� ����������� SPA �� " + bdt.DateString();
    repBalanseSPAForm->QRCreated->Caption = repCreated(Start < (Finish - 1));

    pbProgress->Visible = false;
    repBalanseSPAForm->QuickRep1->Preview();

    PDEL(repClientsIDs);
    PDEL(repClientsFNames);
    PDEL(repClientsSNames);
    PDEL(repClientsTNames);
    PDEL(repClientsBegBalanse);
    PDEL(repClientsToBalanse);
    PDEL(repClientsFromBalanse);
    PDEL(repClientsEndBalanse);

    delete repBalanseSPAForm;

    mmnRefbook->Visible = mV[0];
    mmnService->Visible = mV[1];
    mmnReport->Visible = mV[2];
    mmnAdmin->Visible = mV[3];
    mmnGoods->Visible = mV[4];

    mmnRefbook->Enabled = mE[0];
    mmnService->Enabled = mE[1];
    mmnReport->Enabled = mE[2];
    mmnAdmin->Enabled = mE[3];
    mmnGoods->Enabled = mE[4];
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::AbonementsSPAFullUpdate(void)
{
    if(SQL_BeginTransaction() != SQLITE_OK) return;

    AnsiString sID, sEndDate;
    double x;

    SQL_exe(DBName,"update Abonements_SPA set Closed=1,Balanse=0 where Closed=0 and Balanse<=0");

    AnsiString *pClientIDs;
    unsigned cnt = SQL_fldCollect(DBName,"ClientID","from Abonements_SPA where Closed=0",&pClientIDs,false,false,true);
    __int64 ID;
    TDateTime dt = Now();

    for(unsigned i = 0; i < cnt; i++)
    {
        ID = _atoi64(pClientIDs[i].c_str());
        SQL_exefun2(DBName,("select first 1 RowID,EndDate from Abonements_SPA where Closed=0 and ClientID="+AnsiString(ID)+" order by BegDate desc,CDate desc").c_str(),&sID,&sEndDate);

        if(atoi(sEndDate.c_str()) < (int)dt)
        {
            SQL_exefun(DBName,("select sum(Balanse) from Abonements_SPA where Closed=0 and ClientID="+AnsiString(ID)).c_str(),&retString);
            x = atof(retString.c_str());
            SQL_exe(DBName,("update Abonements_SPA set Closed=1,Balanse=0 where Closed=0 and ClientID="+AnsiString(ID)).c_str());
        }
        else
        {
            SQL_exefun(DBName,("select sum(Balanse) from Abonements_SPA where Closed=0 and RowID!="+sID+" and ClientID="+AnsiString(ID)).c_str(),&retString);
            x = atof(retString.c_str());
            SQL_exe(DBName,("update Abonements_SPA set Closed=1,Balanse=0 where Closed=0 and RowID!="+sID+" and ClientID="+AnsiString(ID)).c_str());
        }

        if(x != 0.0)
        {
            //const char *pMethod = "main.AbonementsSPAFullUpdate";

            //if(SQL_BeginTransaction(DBName,pMethod) == SQLITE_OK)
            {
                SQL_exefun(DBName,("select Balanse from Clients where RowID="+AnsiString(ID)).c_str(),&retString);

                double balanse = atof(retString.c_str());

                SQL_iniInsert(DBName,"Bills");
                SQL_addInsert("ClientID",ID);

                SQL_addInsert("BegBalanse",balanse);
                SQL_addInsert("ToBalanse",x);
                SQL_addInsert("Payment",-1);
                balanse += x;
                SQL_addInsert("EndBalanse",balanse);
                SQL_addInsert("Total",x);
                SQL_addInsert("CDate",(double)dt);
                SQL_addInsert("CUID",UserID);
                SQL_addInsert("EDate",(double)dt);
                SQL_exeInsert("EUID",UserID);

                SQL_iniUpdate(DBName,"Clients",ID);
                SQL_exeUpdate("Balanse",balanse);

                //SQL_CommitTransaction(pMethod);

            }
            //----------------------------------------------------------------
        }
    }

    SQL_CommitTransaction();

    delete [] pClientIDs;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::mmnPurchaseClick(TObject *Sender)
{
    // ������� �������
    __int64 *pGIDs;
    AnsiString *pGoods;

    unsigned cnt = SQL_fldKeyCollect(DBName,"Name","from Goods where Purchase!=0 order by Name",&pGIDs,&pGoods,true);

    if(!cnt) return;

    FormResult = 0;

    PurchaseForm = new TPurchaseForm(this);
    PurchaseForm->pGoods = pGoods;
    PurchaseForm->Count = cnt;
    PurchaseForm->ShowModal();

    if(FormResult != 1)
    {
        delete PurchaseForm;
        delete [] pGIDs;
        delete [] pGoods;
        return;
    }

    __int64 GID, ID;
    GID = pGIDs[PurchaseForm->lbGoods->ItemIndex];

    int income = atoi(PurchaseForm->edQTTY->Text.c_str());
    double sum = atof(PurchaseForm->edSum->Text.c_str());

    delete PurchaseForm;
    delete [] pGIDs;
    delete [] pGoods;

    double dt = Now();

    SQL_iniInsert(DBName,"Docs",&ID);
    SQL_addInsert("Section",0);
    SQL_addInsert("Closed",1);
    SQL_addInsert("Type",1);
    SQL_addInsert("PurchaseSum",sum);
    SQL_addInsert("CDate",dt);
    SQL_addInsert("EDate",dt);
    SQL_addInsert("CUID",UserID);
    SQL_addInsert("EUID",UserID);

    //const char *pMethod = "main.mmnPurchaseClick";

    if(SQL_BeginTransaction() == SQLITE_OK)
    {
        SQL_exeInsert("DocsDate",dt);

        SQL_exefun(NULL,("select Price from Goods where RowID="+AnsiString(GID)).c_str(),&retString);

        SQL_iniInsert(DBName,"Income");
        SQL_addInsert("GoodID",GID);
        SQL_addInsert("DocID",ID);
        double d = atof(retString.c_str());
        SQL_addInsert("Price",d);
        SQL_addInsert("Total",d * income);
        SQL_exeInsert("IncomeCount",income);

        SQL_exefun(DBName,("select StockCount from Stock where GoodID="+AnsiString(GID)).c_str(),&retString);
        int count = atoi(retString.c_str());

        if(count)
            SQL_exe(DBName,("update Stock set StockCount="+AnsiString(count+income)+" where GoodID="+AnsiString(GID)).c_str());
        else
        {
            SQL_iniInsert(DBName,"Stock");
            SQL_addInsert("GoodID",GID);
            SQL_exeInsert("IncomeCount",income);
        }

        if(SQL_CommitTransaction() == SQLITE_OK)
            Application->MessageBox(("������� ����������� "+AnsiString(income)+" �� ����� "+FormatFloat(MoneyFormat,sum)+" ���. ������� ���������.").c_str(),"",MB_OK);
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::N5Click(TObject *Sender)
{
    bool Period = true;

    if(AdminMode || UserGrants[12] != '0')
    {
        SQL_exefun(DBName,"select SettingsVal from Settings where SettingsKey='repGoodsSPAPeriod'",&retString);
        Period = !(atoi(retString.c_str()) == 0);
    }

    TDateTime bdt;
    TDateTime edt;

    if(Period)
    {
        DateIntervalForm = new TDateIntervalForm(this);

        DTI_BegDate = Now();
        DTI_EndDate = DTI_BegDate;
        FormResult = 0;
        DateIntervalForm->ShowModal();
        delete DateIntervalForm;

        if(FormResult != 1) return;
        bdt = DTI_BegDate;
        edt = DTI_EndDate + 1;
    }
    else
    {
         bdt = Now();
         edt = bdt + 1;
    }

    unsigned Start = (int)bdt;
    unsigned Finish = (int)edt;

    // ������, ������, �������?

    AnsiString sql = "select count(distinct RowID) from Goods where RowID in (";
    sql += "select GoodID from Outcome inner join (select Visits_SPA.RowID as VID from Visits_SPA inner join Services on ServiceID=Services.RowID where Visits_SPA.EDate>=";
    sql += Start;
    sql += " and Visits_SPA.CDate<";
    sql += Finish;
    sql += (" and Tag like '~����~%') on Visit_SPAID=VID");

    //sql += ") or RowID in (";
    //sql += "select GoodID from Income inner join Docs on DocID=Docs.RowID where Closed!=0 and EDate>=";
    //sql += Start;
    //sql += " and EDate<";
    //sql += Finish;
    sql += ")";

    SQL_exefun(DBName,sql.c_str(),&retString);
    unsigned cnt = atoi(retString.c_str());

    //if(!cnt)
    //{
    //    Application->MessageBox("��������!\n��� ������ ��� ������.","������ �����",MB_OK);
    //    return;
    //}
    //-----------------------------------------------------------------------------------------------

    pbProgress->Width = ClientWidth;
    pbProgress->Height = ClientHeight;
    pbProgress->Left = 0;
    pbProgress->Top = 0;
    pbProgress->Step = 1;
    pbProgress->Min = 0;
    pbProgress->Position = 0;

    bool mV[5], mE[5];
    mV[0] = mmnRefbook->Visible;
    mV[1] = mmnService->Visible;
    mV[2] = mmnReport->Visible;
    mV[3] = mmnAdmin->Visible;
    mV[4] = mmnGoods->Visible;

    mE[0] = mmnRefbook->Enabled;
    mE[1] = mmnService->Enabled;
    mE[2] = mmnReport->Enabled;
    mE[3] = mmnAdmin->Enabled;
    mE[4] = mmnGoods->Enabled;

    mmnRefbook->Enabled = false;
    mmnService->Enabled = false;
    mmnReport->Enabled = false;
    mmnAdmin->Enabled = false;
    mmnGoods->Enabled = false;
    if(cnt)
        pbProgress->Max = cnt - 1;
    else
        pbProgress->Max = 0;
    pbProgress->Visible = true;

    AnsiString *pLines;
    TList *pList = new TList;

    repGoodsSPAForm = new TrepGoodsSPAForm(this);
    if(Period)
        repGoodsSPAForm->QRHeader->Caption = "����� �� ��������� ���������� (����) � " + bdt.DateString() + " �� " + (edt-1).DateString();
    else
        repGoodsSPAForm->QRHeader->Caption = "����� �� ��������� ���������� (����) �� " + (edt-1).DateString();
    repGoodsSPAForm->QRCreated->Caption = repCreated(Start < (Finish - 1));

    repGoodsSPAForm->pPrint = pList;

    pList->Add(NULL);
    repGoodsSPAForm->QRlines->Items->Add("E");

    sql = "from Goods where RowID in (";
    sql += "select GoodID from Outcome inner join (select Visits_SPA.RowID as VID from Visits_SPA inner join Services on ServiceID=Services.RowID where Visits_SPA.EDate>=";
    sql += Start;
    sql += " and Visits_SPA.CDate<";
    sql += Finish;
    sql += (" and Tag like '~����~%') on Visit_SPAID=VID");

    //sql += ") or RowID in (";
    //sql += "select GoodID from Income inner join Docs on DocID=Docs.RowID where Closed!=0 and EDate>=";
    //sql += Start;
    //sql += " and EDate<";
    //sql += Finish;
    sql += ") order by Name,RowID";
    //unsigned __fastcall SQL_fldCollect(const char *dbname,const char *fName,const char *sql_from,AnsiString **pFld,bool ToAnsi,bool FirstZero,bool Distinct)
    __int64 *pIDs;
    AnsiString *pGoods;
    cnt = SQL_fldKeyCollect(DBName,"Name",sql.c_str(),&pIDs,&pGoods,true,false,true);

    AnsiString sVal;
    double income, outcome, stock;

    for(unsigned counter = 0; counter < cnt; counter++)
    {
        // ������
        sql = "select sum(IncomeCount) from Income inner join Docs on DocID=Docs.RowID where Closed!=0 and Income.GoodID="+AnsiString(pIDs[counter]);
        sql += " and EDate>=";
        sql += Start;
        sql += " and EDate<";
        sql += Finish;

        SQL_exefun(DBName,sql.c_str(),&retString);
        income = atoi(retString.c_str());

        // �������
        sql = "select StockCount,Part from Stock where GoodID="+AnsiString(pIDs[counter]);

        SQL_exefun2(DBName,sql.c_str(),&retString,&sVal);

        stock = atof(retString.c_str()) + (atof(sVal.c_str()) / 1000.0);

        // ������
        sql = "select sum(OutcomeCount),sum(Part) from Outcome inner join (select Visits_SPA.RowID as VID from Visits_SPA inner join Services on ServiceID=Services.RowID where Visits_SPA.EDate>=";
        sql += Start;
        sql += " and Visits_SPA.CDate<";
        sql += Finish;
        sql += (" and Tag like '~����~%') on Visit_SPAID=VID");
        sql += " where GoodID=";
        sql += AnsiString(pIDs[counter]);

        SQL_exefun2(DBName,sql.c_str(),&retString,&sVal);

        outcome = atof(retString.c_str()) + (atof(sVal.c_str()) / 1000.0);

        pLines = new AnsiString[4];
        pLines[0] = pGoods[counter];
        pLines[1] = FormatFloat(CountFormat,income);
        pLines[2] = FormatFloat(CountFormat,outcome);
        pLines[3] = FormatFloat(CountFormat,stock);

        pList->Add(pLines);
        repGoodsSPAForm->QRlines->Items->Add("L");

        //pLines = new AnsiString[4];
        //pLines[0] = psPID[cnt_p] + " / " + Tags[tags_cnt];
        //pList->Add(pLines);
        //repGoodsSPAForm->QRlines->Items->Add("H");

        //pLines = new AnsiString[4];
        //pLines[0] = "�����:";
        //pList->Add(pLines);
        //repGoodsSPAForm->QRlines->Items->Add("I");
        //pList->Add(NULL);
        //repGoodsSPAForm->QRlines->Items->Add("E");

        pbProgress->StepIt();
        Application->ProcessMessages();
    }

    delete [] pIDs;

    pList->Add(NULL);
    repGoodsSPAForm->QRlines->Items->Add("E");

    pbProgress->Visible = false;
    repGoodsSPAForm->QuickRep1->Preview();

    for(int i = 0; i < pList->Count; i++)
        if((pLines = (AnsiString *)pList->Items[i]) != NULL) delete [] pLines;

    delete pList;
    delete repGoodsSPAForm;

    mmnRefbook->Visible = mV[0];
    mmnService->Visible = mV[1];
    mmnReport->Visible = mV[2];
    mmnAdmin->Visible = mV[3];
    mmnGoods->Visible = mV[4];

    mmnRefbook->Enabled = mE[0];
    mmnService->Enabled = mE[1];
    mmnReport->Enabled = mE[2];
    mmnAdmin->Enabled = mE[3];
    mmnGoods->Enabled = mE[4];
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::N7Click(TObject *Sender)
{
    bool Period = true;

    if(AdminMode || UserGrants[12] != '0')
    {
        SQL_exefun(DBName,"select SettingsVal from Settings where SettingsKey='repGoodsSPAPeriod'",&retString);
        Period = !(atoi(retString.c_str()) == 0);
    }

    TDateTime bdt;
    TDateTime edt;

    if(Period)
    {
        DateIntervalForm = new TDateIntervalForm(this);

        DTI_BegDate = Now();
        DTI_EndDate = DTI_BegDate;
        FormResult = 0;
        DateIntervalForm->ShowModal();
        delete DateIntervalForm;

        if(FormResult != 1) return;
        bdt = DTI_BegDate;
        edt = DTI_EndDate + 1;
    }
    else
    {
         bdt = Now();
         edt = bdt + 1;
    }

    unsigned Start = (int)bdt;
    unsigned Finish = (int)edt;

    // ������, ������, �������?

    AnsiString sql = "select count(distinct RowID) from Goods where RowID in (";
    sql += "select GoodID from Outcome inner join (select Visits_SPA.RowID as VID from Visits_SPA inner join Services on ServiceID=Services.RowID where Visits_SPA.EDate>=";
    sql += Start;
    sql += " and Visits_SPA.CDate<";
    sql += Finish;
    sql += (" and Tag like '~SPA~%') on Visit_SPAID=VID");

    //sql += ") or RowID in (";
    //sql += "select GoodID from Income inner join Docs on DocID=Docs.RowID where Closed!=0 and EDate>=";
    //sql += Start;
    //sql += " and EDate<";
    //sql += Finish;
    sql += ")";

    SQL_exefun(DBName,sql.c_str(),&retString);
    unsigned cnt = atoi(retString.c_str());

    //if(!cnt)
    //{
    //    Application->MessageBox("��������!\n��� ������ ��� ������.","������ �����",MB_OK);
    //    return;
    //}
    //-----------------------------------------------------------------------------------------------

    pbProgress->Width = ClientWidth;
    pbProgress->Height = ClientHeight;
    pbProgress->Left = 0;
    pbProgress->Top = 0;
    pbProgress->Step = 1;
    pbProgress->Min = 0;
    pbProgress->Position = 0;

    bool mV[5], mE[5];
    mV[0] = mmnRefbook->Visible;
    mV[1] = mmnService->Visible;
    mV[2] = mmnReport->Visible;
    mV[3] = mmnAdmin->Visible;
    mV[4] = mmnGoods->Visible;

    mE[0] = mmnRefbook->Enabled;
    mE[1] = mmnService->Enabled;
    mE[2] = mmnReport->Enabled;
    mE[3] = mmnAdmin->Enabled;
    mE[4] = mmnGoods->Enabled;

    mmnRefbook->Enabled = false;
    mmnService->Enabled = false;
    mmnReport->Enabled = false;
    mmnAdmin->Enabled = false;
    mmnGoods->Enabled = false;
    if(cnt)
        pbProgress->Max = cnt - 1;
    else
        pbProgress->Max = 0;
    pbProgress->Visible = true;

    AnsiString *pLines;
    TList *pList = new TList;

    repGoodsSPAForm = new TrepGoodsSPAForm(this);
    if(Period)
        repGoodsSPAForm->QRHeader->Caption = "����� �� ��������� ���������� (SPA) � " + bdt.DateString() + " �� " + (edt-1).DateString();
    else
        repGoodsSPAForm->QRHeader->Caption = "����� �� ��������� ���������� (SPA) �� " + (edt-1).DateString();
    repGoodsSPAForm->QRCreated->Caption = repCreated(Start < (Finish - 1));

    repGoodsSPAForm->pPrint = pList;

    pList->Add(NULL);
    repGoodsSPAForm->QRlines->Items->Add("E");

    sql = "from Goods where RowID in (";
    sql += "select GoodID from Outcome inner join (select Visits_SPA.RowID as VID from Visits_SPA inner join Services on ServiceID=Services.RowID where Visits_SPA.EDate>=";
    sql += Start;
    sql += " and Visits_SPA.CDate<";
    sql += Finish;
    sql += (" and Tag like '~SPA~%') on Visit_SPAID=VID");

    //sql += ") or RowID in (";
    //sql += "select GoodID from Income inner join Docs on DocID=Docs.RowID where Closed!=0 and EDate>=";
    //sql += Start;
    //sql += " and EDate<";
    //sql += Finish;
    sql += ") order by Name,RowID";
    //unsigned __fastcall SQL_fldCollect(const char *dbname,const char *fName,const char *sql_from,AnsiString **pFld,bool ToAnsi,bool FirstZero,bool Distinct)
    __int64 *pIDs;
    AnsiString *pGoods;
    cnt = SQL_fldKeyCollect(DBName,"Name",sql.c_str(),&pIDs,&pGoods,true,false,true);

    AnsiString sVal;
    double income, outcome, stock;

    for(unsigned counter = 0; counter < cnt; counter++)
    {
        // ������
        sql = "select sum(IncomeCount) from Income inner join Docs on DocID=Docs.RowID where Closed!=0 and Income.GoodID="+AnsiString(pIDs[counter]);
        sql += " and EDate>=";
        sql += Start;
        sql += " and EDate<";
        sql += Finish;

        SQL_exefun(DBName,sql.c_str(),&retString);
        income = atoi(retString.c_str());

        // �������
        sql = "select StockCount,Part from Stock where GoodID="+AnsiString(pIDs[counter]);

        SQL_exefun2(DBName,sql.c_str(),&retString,&sVal);

        stock = atof(retString.c_str()) + (atof(sVal.c_str()) / 1000.0);

        // ������
        sql = "select sum(OutcomeCount),sum(Part) from Outcome inner join (select Visits_SPA.RowID as VID from Visits_SPA inner join Services on ServiceID=Services.RowID where Visits_SPA.EDate>=";
        sql += Start;
        sql += " and Visits_SPA.CDate<";
        sql += Finish;
        sql += (" and Tag like '~SPA~%') on Visit_SPAID=VID");
        sql += " where GoodID=";
        sql += AnsiString(pIDs[counter]);

        SQL_exefun2(DBName,sql.c_str(),&retString,&sVal);

        outcome = atof(retString.c_str()) + (atof(sVal.c_str()) / 1000.0);

        pLines = new AnsiString[4];
        pLines[0] = pGoods[counter];
        pLines[1] = FormatFloat(CountFormat,income);
        pLines[2] = FormatFloat(CountFormat,outcome);
        pLines[3] = FormatFloat(CountFormat,stock);

        pList->Add(pLines);
        repGoodsSPAForm->QRlines->Items->Add("L");

        pbProgress->StepIt();
        Application->ProcessMessages();
    }

    delete [] pIDs;

    pList->Add(NULL);
    repGoodsSPAForm->QRlines->Items->Add("E");

    pbProgress->Visible = false;
    repGoodsSPAForm->QuickRep1->Preview();

    for(int i = 0; i < pList->Count; i++)
        if((pLines = (AnsiString *)pList->Items[i]) != NULL) delete [] pLines;

    delete pList;
    delete repGoodsSPAForm;

    mmnRefbook->Visible = mV[0];
    mmnService->Visible = mV[1];
    mmnReport->Visible = mV[2];
    mmnAdmin->Visible = mV[3];
    mmnGoods->Visible = mV[4];

    mmnRefbook->Enabled = mE[0];
    mmnService->Enabled = mE[1];
    mmnReport->Enabled = mE[2];
    mmnAdmin->Enabled = mE[3];
    mmnGoods->Enabled = mE[4];    
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::mmnVersionClick(TObject *Sender)
{
    char version[16];
    AnsiString s = "������ ��: ";

    if(GetFileVersion("panacea.exe",version,16))
        s += version;
    else
        s += "unknown";

    Application->MessageBox(s.c_str(),"About",MB_OK);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::N21Click(TObject *Sender)
{
    bool Period = true;

    if(AdminMode || UserGrants[12] != '0')
    {
        SQL_exefun(DBName,"select SettingsVal from Settings where SettingsKey='repVisitsSPAPeriod'",&retString);
        Period = !(atoi(retString.c_str()) == 0);
    }

    TDateTime bdt;
    TDateTime edt;

    if(Period)
    {
        DateIntervalForm = new TDateIntervalForm(this);

        DTI_BegDate = Now();
        DTI_EndDate = DTI_BegDate;
        FormResult = 0;
        DateIntervalForm->ShowModal();
        delete DateIntervalForm;

        if(FormResult != 1) return;
        bdt = DTI_BegDate;
        edt = DTI_EndDate + 1;
    }
    else
    {
         bdt = Now();
         edt = bdt + 1;
    }

    unsigned Start = (int)bdt;
    unsigned Finish = (int)edt;

    AnsiString *psPID;

    AnsiString sql = "from Visits_SPA inner join Services on ServiceID=Services.RowID where Visits_SPADate>=";
    sql += Start;
    sql += " and Visits_SPADate<";
    sql += Finish;
    sql += " and Tag like '~";
    sql += ("����");
    sql += "~%'";

    unsigned cnt_visits = SQL_fldCollect(DBName,"PersonID",sql.c_str(),&psPID,false,false,true);

    //if(cnt_visits == 0)
    //{
    //    Application->MessageBox("��������!\n��� ������ ��� ������.","������ �����",MB_OK);
    //    return;
    //}

    pbProgress->Width = ClientWidth;
    pbProgress->Height = ClientHeight;
    pbProgress->Left = 0;
    pbProgress->Top = 0;
    pbProgress->Step = 1;
    pbProgress->Min = 0;
    pbProgress->Position = 0;

    bool mV[5], mE[5];
    mV[0] = mmnRefbook->Visible;
    mV[1] = mmnService->Visible;
    mV[2] = mmnReport->Visible;
    mV[3] = mmnAdmin->Visible;
    mV[4] = mmnGoods->Visible;

    mE[0] = mmnRefbook->Enabled;
    mE[1] = mmnService->Enabled;
    mE[2] = mmnReport->Enabled;
    mE[3] = mmnAdmin->Enabled;
    mE[4] = mmnGoods->Enabled;

    mmnRefbook->Enabled = false;
    mmnService->Enabled = false;
    mmnReport->Enabled = false;
    mmnAdmin->Enabled = false;
    mmnGoods->Enabled = false;

    unsigned i;
    bool fZero = false;

    sql = "from Personal where RowID in (";
    for(i = 0; i < cnt_visits; i++)
    {
        if(_atoi64(psPID[i].c_str()) == 0)
            fZero = true;

        sql += (AnsiString(psPID[i]) + ",");
    }
    if(cnt_visits)
        sql.SetLength(sql.Length() - 1);
    else
        sql += "0";

    sql += ") order by Name,CDate";

    delete [] psPID;

    __int64 *pPIDs;

    unsigned cnt_persons = SQL_fldKeyCollect(DBName,"Name",sql.c_str(),&pPIDs,&psPID,true,fZero);

    if(fZero)
    {
        pPIDs[0] = 0;
        psPID[0] = "��� �����������";
    }

    if(cnt_persons)
        pbProgress->Max = cnt_persons - 1;
    else
        pbProgress->Max = 0;
    pbProgress->Visible = true;

    TList *pList = new TList;
    AnsiString *pLines;
    AnsiString sRow[8];
    AnsiString *psVID;
    //char *Tags[] = { "������� ���� (� ������������)", "������� ���� (� �����������)", "������ (� ������������)", "������ (� �����������)" };
    AnsiString *Tags;

    unsigned l2cnt = SQL_fldCollect(NULL,"Name","from Services where Tag='~����~'",&Tags);

    repVisitsSPAForm = new TrepVisitsSPAForm(this);
    if(Period)
        repVisitsSPAForm->QRHeader->Caption = "����� �� ������� ������� ��������� � " + bdt.DateString() + " �� " + (edt-1).DateString();
    else
        repVisitsSPAForm->QRHeader->Caption = "����� �� ������� ������� ��������� �� " + (edt-1).DateString();
    repVisitsSPAForm->QRCreated->Caption = repCreated(Start < (Finish - 1));

    repVisitsSPAForm->pPrint = pList;

    pList->Add(NULL);
    repVisitsSPAForm->QRlines->Items->Add("E");

    for(unsigned cnt_p = 0; cnt_p < cnt_persons; cnt_p++)
    {
        for(unsigned tags_cnt = 0; tags_cnt < l2cnt; tags_cnt++)
        {
            sql = "from Visits_SPA where PersonID=";
            sql += pPIDs[cnt_p];
            sql += " and Visits_SPADate>=";
            sql += Start;
            sql += " and Visits_SPADate<";
            sql += Finish;
            sql += (" and ServiceID in (select RowID from Services where Tag like '~" + (AnsiString("����~")+Tags[tags_cnt]) + "~%') order by CDate");

            cnt_visits = SQL_fldCollect(DBName,"RowID",sql.c_str(),&psVID);

            if(cnt_visits)
            {
                pLines = new AnsiString[4];
                pLines[0] = psPID[cnt_p] + " / " + Tags[tags_cnt];
                pList->Add(pLines);
                repVisitsSPAForm->QRlines->Items->Add("H");
            }
            else
                continue;

            for(unsigned cnt_v = 0; cnt_v < cnt_visits; cnt_v++)
            {
                pLines = new AnsiString[4];


                SQL_exefunrow(DBName,("select ServiceID,AbonementID,ClientID,Price,PersonPrice,GroupCnt,BegTime,EndTime from Visits_SPA where RowID="+AnsiString(_atoi64(psVID[cnt_v].c_str()))).c_str(),8,sRow);
                SQL_exefun(DBName,("select '['||b.Name||']'||a.Name from Services a left outer join Services b on a.ParentID=b.RowID where a.RowID="+AnsiString(_atoi64(sRow[0].c_str()))).c_str(),&retString);

                pLines[0] = retString;

                if(!_atoi64(sRow[1].c_str()))
                    SQL_exefun(DBName,("select FName||' '||SName||' '||TName from Clients where RowID="+AnsiString(_atoi64(sRow[2].c_str()))).c_str(),&retString);
                else
                    SQL_exefun(DBName,("select FName||' '||SName||' '||TName from Clients where RowID=(select ClientID from Abonements_SPA where RowID="+AnsiString(_atoi64(sRow[1].c_str()))+")").c_str(),&retString);

                pLines[1] = retString;

                double price = atof(sRow[3].c_str());
                double pprice = atof(sRow[4].c_str());

                //if(pprice == 0.0)
                //{
                    // ��������� ��������� ��������????????????/
                    //SQL_exefun
                //    pprice = price;
                //}
                //if(pprice == 0.0)
                //    pLines[2] = FormatFloat(MoneyFormat,price) + " / 0.00";
                //else
                //sRow[5], sRow[6], sRow[7]
                SQL_exefun(DBName,("select Timed from Services where RowID="+AnsiString(_atoi64(sRow[0].c_str()))).c_str(),&retString);

                if(atoi(retString.c_str()) > 0)
                    pLines[2] = "(" + sRow[5] + "-" + TDateTime(atof(sRow[7].c_str()) - atof(sRow[6].c_str())).FormatString("h:nn") + ") ";
                //else
                //    pLines[2] = FormatFloat(MoneyFormat,pprice) + " / " + FormatFloat(MoneyFormat,price-pprice);

                pLines[2] += (FormatFloat(MoneyFormat,pprice) + " / " + FormatFloat(MoneyFormat,price-pprice));

                repVisitsSPAForm->QRlines->Items->Add("L");

                pList->Add(pLines);

            }

            pLines = new AnsiString[4];
            pLines[0] = "�����:";
            pList->Add(pLines);
            repVisitsSPAForm->QRlines->Items->Add("I");
            pList->Add(NULL);
            repVisitsSPAForm->QRlines->Items->Add("E");

            delete [] psVID;
        }

        pbProgress->StepIt();
        Application->ProcessMessages();
    }

    delete [] psPID;
    delete [] pPIDs;

    delete [] Tags;

    pbProgress->Visible = false;
    repVisitsSPAForm->QuickRep1->Preview();

    AnsiString *pS;

    for(int i = 0; i < pList->Count; i++)
        if((pS = (AnsiString *)pList->Items[i]) != NULL) delete [] pS;

    delete pList;
    delete repVisitsSPAForm;

    mmnRefbook->Visible = mV[0];
    mmnService->Visible = mV[1];
    mmnReport->Visible = mV[2];
    mmnAdmin->Visible = mV[3];
    mmnGoods->Visible = mV[4];

    mmnRefbook->Enabled = mE[0];
    mmnService->Enabled = mE[1];
    mmnReport->Enabled = mE[2];
    mmnAdmin->Enabled = mE[3];
    mmnGoods->Enabled = mE[4];
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PPrice1Click(TObject *Sender)
{
    AnsiString sSPrice, sVPrice;
    AnsiString *pIDs;
    double pprice, sprice, vprice;

    SQL_BeginTransaction();

    unsigned cnt = SQL_fldCollect(DBName,"RID","from (select Visits_SPA.RowID as RID from Visits_SPA inner join Services on ServiceID=Services.RowID where Tag like '~SPA~%' and Visits_SPA.PersonPrice=0 and Services.RowID!=91)",&pIDs);
    for(unsigned i = 0; i < cnt; i++)
    {
        SQL_exefun3(DBName,("select Services.PersonPrice,Services.Price,Visits_SPA.Price from Services inner join Visits_SPA on Services.RowID=ServiceID where Visits_SPA.RowID="+pIDs[i]).c_str(),&retString,&sSPrice,&sVPrice);

        pprice = atof(retString.c_str());
        sprice = atof(sSPrice.c_str());
        vprice = atof(sVPrice.c_str());
        if(sprice == 0.0)
            pprice = 0.0;
        else
            pprice = pprice - ((pprice * (sprice - vprice)) / sprice);

        SQL_iniUpdate(DBName,"Visits_SPA",_atoi64(pIDs[i].c_str()));
        SQL_exeUpdate("PersonPrice",pprice);

    }

    delete [] pIDs;

    SQL_CommitTransaction();

    Application->MessageBox("���������.","",MB_OK);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::VisitsSPA1Click(TObject *Sender)
{
    __int64 *pIDs;
    AnsiString *pPrice, sCID;

    SQL_BeginTransaction();
    // �������� ������
    unsigned cnt = SQL_fldKeyCollect(DBName,"Price","from Visits_SPA where ClientID=0 and AbonementID=0",&pIDs,&pPrice);

    for(unsigned i = 0; i < cnt; i++)
    {
        SQL_exefun2(DBName,("select first 1 RowID,ClientID from Visits_SPA where RowID>"+AnsiString(pIDs[i])+" and Price="+pPrice[i]+" order by RowID").c_str(),&retString,&sCID);

        if(_atoi64(sCID.c_str()) != 0 && _atoi64(retString.c_str()) != 0)
        {
            SQL_iniUpdate(DBName,"Visits_SPA",pIDs[i]);
            SQL_exeUpdate("ClientID",sCID);

            SQL_exe(DBName,("delete from Visits_SPA where RowID="+retString).c_str());
        }
    }

    delete [] pIDs;
    delete [] pPrice;

    if(SQL_CommitTransaction() == SQLITE_OK)
        Application->MessageBox("���������.","",MB_OK);
    else
        Application->MessageBox("�� ���������!","",MB_OK);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::AllExport(void)
{
    TIniFile *pIni = new TIniFile(_AppPath+"export.ini");
    TStringList *pList = new TStringList;
    AnsiString sFile, sFields, sMask, sSQL;
    int fCnt;
    char *pTok;
    //AnsiString *pFields;
    char **pFields;

    pIni->ReadSections(pList);
    int j;

    for(int i = 0; i < pList->Count; i++)
    {
        fCnt = atoi(pIni->ReadString(pList->Strings[i],"Count","0").Trim().c_str());
        if(fCnt <= 0) continue;
        sSQL = pIni->ReadString(pList->Strings[i],"SQL","").Trim();
        if(sSQL.Length() == 0) continue;

        pFields = new char *[fCnt];

        sFile = pIni->ReadString(pList->Strings[i],"File",pList->Strings[i]+".exp").Trim();

        sFields = pIni->ReadString(pList->Strings[i],"Fields","");
        j = 0;
        pTok = strtok(sFields.c_str(),",");
        while(pTok && j < fCnt)
        {
            pFields[j++] = strdup(AnsiString(pTok).Trim().c_str());
            pTok = strtok(NULL,",");
        }

        if(j == fCnt)
        {
            sMask = pIni->ReadString(pList->Strings[i],"Mask","").Trim();
            if(sMask.Length() < fCnt)
                sMask += AnsiString::StringOfChar('#',fCnt - sMask.Length());

            TableExport(sFile.c_str(),pList->Strings[i].c_str(),(const char **)pFields,sMask.c_str(),fCnt,sSQL.c_str());
        }

        for(j = 0; j < fCnt; j++)
            free(pFields[j]);
        delete [] pFields;

    }

    delete pList;
    delete pIni;
}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::TableExport(const char *pFileName,const char *pTable,const char **pFNames,char *pFMasks,unsigned fcnt,const char *pFrom)
{
    AnsiString buf, *pFields;

    unsigned cnt = SQL_Collect(DBName,fcnt,pFNames,pFrom,NULL,&pFields,pFMasks);

    int handle = FileCreate(ExpPath+pFileName);
    //buf = AnsiString("<") + pTable + ">\n";
    //FileWrite(handle,buf.c_str(),buf.Length());
    buf = "INSERT INTO " + AnsiString(pTable).UpperCase() + "(";

    for(unsigned j = 0; j < fcnt; j++)
    {
        //buf += (AnsiString("<") + pFNames[j] + ">" + pFields[i*fcnt+j] + "</" + pFNames[j] + ">");
        buf += AnsiString(pFNames[j]).UpperCase();
        buf += ",";
    }

    buf.SetLength(buf.Length()-1);

    buf += ") VALUES\n";
    FileWrite(handle,buf.c_str(),buf.Length());
    buf = "";

    for(unsigned i = 0; i < cnt; i++)
    {
        //buf = "<Row>";
        //buf = "REPLACE INTO " + AnsiString(pTable).UpperCase() + "(";
        buf += "(";

        for(unsigned j = 0; j < fcnt; j++)
        {
            //buf += (AnsiString("<") + pFNames[j] + ">" + pFields[i*fcnt+j] + "</" + pFNames[j] + ">");
            if(pFMasks[j] == '#' || pFMasks[j] == '!')
            {
                buf += "'";
                buf += StringReplace(pFields[i*fcnt+j],"'","''",TReplaceFlags() << rfReplaceAll);
                buf += "'";
            }
            else
            {
                if(atof(pFields[i*fcnt+j].c_str()) == 0)
                    buf += "0";
                else
                    buf += pFields[i*fcnt+j];
            }
            buf += ",";
        }

        buf.SetLength(buf.Length()-1);

        buf += "),\n";



        //buf += "</Row>\n";


    }

    buf.SetLength(buf.Length()-2);
    buf += "\n";

    FileWrite(handle,buf.c_str(),buf.Length());
    //buf = AnsiString("</") + pTable + ">\n";
    
    //FileWrite(handle,buf.c_str(),buf.Length());
    FileClose(handle);

    delete [] pFields;
    return true;
    //Application->MessageBox("Done.","",MB_OK);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ClientsExport1Click(TObject *Sender)
{
    const char *pFields[] = { "RowID", "FName", "SName", "TName", "Balanse" };
    //ClientsExport();
    //ArchExport();
    TableExport("clients.sql","Clients",pFields,"@###@",5,"from Clients where Alive!=0");
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ArchExport(void)
{
    DeleteFile(_AppPath + "db\\export.7z");

    TSevenZip *pSZ = new TSevenZip(this);
    //pSZ->SZFileName = "Drivers.7z";
    //pSZ->ExtrBaseDir = "";

    //pSZ->ExtractOptions = pSZ->ExtractOptions << ExtractOverwrite;
    //pSZ->Files->Clear();
    //pSZ->OnPreProgress = SZipPreProgress;
    //pSZ->OnProgress = SZipProgress;
    //pSZ->Extract();




        //var i:integer;
//begin
 //opendialog1.InitialDir := 'c:\';
// if not opendialog1.Execute then exit;
    pSZ->LZMACompressStrength = ULTRA;
    
//Set archive filname
    pSZ->SZFileName = _AppPath + "db\\export.7z";
    pSZ->AddOptions = pSZ->AddOptions << AddStoreOnlyFilename;
//Set Volumesize
 //sevenzip1.VolumeSize := strtoint(volsize.text);

//Set rootdir for recuresive folder (if wanted)
    pSZ->AddRootDir = ExpPath;

 //If password7z.Text <> '' then Sevenzip1.Password := password7z.Text;

//Clear filelist
    pSZ->Files->Clear();

    pSZ->Files->AddString(ExpPath+"*.exp");
    //pSZ->Files->AddString(ExpPath+"services.exp");
    //pSZ->Files->AddString(ExpPath+"personal.exp");

// for i := 0 to opendialog1.Files.count-1 do
//  sevenzip1.Files.AddString(opendialog1.Files[i]);

//add files
    pSZ->Add();

    delete pSZ;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Export1Click(TObject *Sender)
{
    AllExport();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::N11Click(TObject *Sender)
{
    //TPwdForm *PwdForm;
    //if(UserID != 4) return;

    PwdForm = new TPwdForm(this);
    PwdForm->ShowModal();
    delete PwdForm;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::N13Click(TObject *Sender)
{
    bool Period = true;

    if(AdminMode || UserGrants[12] != '0')
    {
        SQL_exefun(DBName,"select SettingsVal from Settings where SettingsKey='repVisitsSPAPeriod'",&retString);
        Period = !(atoi(retString.c_str()) == 0);
    }

    TDateTime bdt;
    TDateTime edt;

    if(Period)
    {
        DateIntervalForm = new TDateIntervalForm(this);

        DTI_BegDate = Now();
        DTI_EndDate = DTI_BegDate;
        FormResult = 0;
        DateIntervalForm->ShowModal();
        delete DateIntervalForm;

        if(FormResult != 1) return;
        bdt = DTI_BegDate;
        edt = DTI_EndDate + 1;
    }
    else
    {
         bdt = Now();
         edt = bdt + 1;
    }

    unsigned Start = (int)bdt;
    unsigned Finish = (int)edt;

    AnsiString *psPID;

    AnsiString sql = "from Visits_SPA inner join Services on ServiceID=Services.RowID where Visits_SPADate>=";
    sql += Start;
    sql += " and Visits_SPADate<";
    sql += Finish;
    sql += " and Tag like '~";
    sql += ("��������������");
    sql += "~%'";

    unsigned cnt_visits = SQL_fldCollect(DBName,"PersonID",sql.c_str(),&psPID,false,false,true);

    //if(cnt_visits == 0)
    //{
    //    Application->MessageBox("��������!\n��� ������ ��� ������.","������ �����",MB_OK);
    //    return;
    //}

    pbProgress->Width = ClientWidth;
    pbProgress->Height = ClientHeight;
    pbProgress->Left = 0;
    pbProgress->Top = 0;
    pbProgress->Step = 1;
    pbProgress->Min = 0;
    pbProgress->Position = 0;

    bool mV[5], mE[5];
    mV[0] = mmnRefbook->Visible;
    mV[1] = mmnService->Visible;
    mV[2] = mmnReport->Visible;
    mV[3] = mmnAdmin->Visible;
    mV[4] = mmnGoods->Visible;

    mE[0] = mmnRefbook->Enabled;
    mE[1] = mmnService->Enabled;
    mE[2] = mmnReport->Enabled;
    mE[3] = mmnAdmin->Enabled;
    mE[4] = mmnGoods->Enabled;

    mmnRefbook->Enabled = false;
    mmnService->Enabled = false;
    mmnReport->Enabled = false;
    mmnAdmin->Enabled = false;
    mmnGoods->Enabled = false;

    unsigned i;
    bool fZero = false;

    sql = "from Personal where RowID in (";
    for(i = 0; i < cnt_visits; i++)
    {
        if(_atoi64(psPID[i].c_str()) == 0)
            fZero = true;

        sql += (AnsiString(psPID[i]) + ",");
    }
    if(cnt_visits)
        sql.SetLength(sql.Length() - 1);
    else
        sql += "0";

    sql += ") order by Name,CDate";

    delete [] psPID;

    __int64 *pPIDs;

    unsigned cnt_persons = SQL_fldKeyCollect(DBName,"Name",sql.c_str(),&pPIDs,&psPID,true,fZero);

    if(fZero)
    {
        pPIDs[0] = 0;
        psPID[0] = "��� �����������";
    }
    if(cnt_persons)
        pbProgress->Max = cnt_persons - 1;
    else
        pbProgress->Max = 0;
    pbProgress->Visible = true;

    TList *pList = new TList;
    AnsiString *pLines;
    AnsiString sRow[8];
    AnsiString *psVID;

    //char *Tags[] = { "������� ���", "������� ���", "������� ���" };
    AnsiString *Tags;

    unsigned l2cnt = SQL_fldCollect(NULL,"Name","from Services where Tag='~��������������~'",&Tags);

    repVisitsSPAForm = new TrepVisitsSPAForm(this);
    if(Period)
        repVisitsSPAForm->QRHeader->Caption = "����� �� ������� �������������� � " + bdt.DateString() + " �� " + (edt-1).DateString();
    else
        repVisitsSPAForm->QRHeader->Caption = "����� �� ������� �������������� �� " + (edt-1).DateString();
    repVisitsSPAForm->QRCreated->Caption = repCreated(Start < (Finish - 1));

    repVisitsSPAForm->pPrint = pList;

    pList->Add(NULL);
    repVisitsSPAForm->QRlines->Items->Add("E");

    for(unsigned cnt_p = 0; cnt_p < cnt_persons; cnt_p++)
    {
        for(unsigned tags_cnt = 0; tags_cnt < l2cnt; tags_cnt++)
        {
            sql = "from Visits_SPA where PersonID=";
            sql += pPIDs[cnt_p];
            sql += " and Visits_SPADate>=";
            sql += Start;
            sql += " and Visits_SPADate<";
            sql += Finish;
            sql += (" and ServiceID in (select RowID from Services where Tag like '~" + (AnsiString("��������������~")+Tags[tags_cnt]) + "~%') order by CDate");

            cnt_visits = SQL_fldCollect(DBName,"RowID",sql.c_str(),&psVID);

            if(cnt_visits)
            {
                pLines = new AnsiString[4];
                pLines[0] = psPID[cnt_p] + " / " + Tags[tags_cnt];
                pList->Add(pLines);
                repVisitsSPAForm->QRlines->Items->Add("H");
            }
            else
                continue;

            for(unsigned cnt_v = 0; cnt_v < cnt_visits; cnt_v++)
            {
                pLines = new AnsiString[4];


                SQL_exefunrow(DBName,("select ServiceID,AbonementID,ClientID,Price,PersonPrice,GroupCnt,BegTime,EndTime from Visits_SPA where RowID="+AnsiString(_atoi64(psVID[cnt_v].c_str()))).c_str(),8,sRow);
                SQL_exefun(DBName,("select '['||b.Name||']'||a.Name from Services a left outer join Services b on a.ParentID=b.RowID where a.RowID="+AnsiString(_atoi64(sRow[0].c_str()))).c_str(),&retString);

                pLines[0] = retString;

                if(!_atoi64(sRow[1].c_str()))
                    SQL_exefun(DBName,("select FName||' '||SName||' '||TName from Clients where RowID="+AnsiString(_atoi64(sRow[2].c_str()))).c_str(),&retString);
                else
                    SQL_exefun(DBName,("select FName||' '||SName||' '||TName from Clients where RowID=(select ClientID from Abonements_SPA where RowID="+AnsiString(_atoi64(sRow[1].c_str()))+")").c_str(),&retString);

                pLines[1] = retString;

                double price = atof(sRow[3].c_str());
                double pprice = atof(sRow[4].c_str());

                //if(pprice == 0.0)
                //{
                    // ��������� ��������� ��������????????????/
                    //SQL_exefun
                //    pprice = price;
                //}
                //if(pprice == 0.0)
                //    pLines[2] = FormatFloat(MoneyFormat,price) + " / 0.00";
                //else
                //sRow[5], sRow[6], sRow[7]
                SQL_exefun(DBName,("select Timed from Services where RowID="+AnsiString(_atoi64(sRow[0].c_str()))).c_str(),&retString);

                if(atoi(retString.c_str()) > 0)
                    pLines[2] = "(" + sRow[5] + "-" + TDateTime(atof(sRow[7].c_str()) - atof(sRow[6].c_str())).FormatString("h:nn") + ") ";
                //else
                //    pLines[2] = FormatFloat(MoneyFormat,pprice) + " / " + FormatFloat(MoneyFormat,price-pprice);

                pLines[2] += (FormatFloat(MoneyFormat,pprice) + " / " + FormatFloat(MoneyFormat,price-pprice));

                repVisitsSPAForm->QRlines->Items->Add("L");

                pList->Add(pLines);

            }

            pLines = new AnsiString[4];
            pLines[0] = "�����:";
            pList->Add(pLines);
            repVisitsSPAForm->QRlines->Items->Add("I");
            pList->Add(NULL);
            repVisitsSPAForm->QRlines->Items->Add("E");

            delete [] psVID;
        }

        pbProgress->StepIt();
        Application->ProcessMessages();
    }

    delete [] psPID;
    delete [] pPIDs;

    delete [] Tags;

    pbProgress->Visible = false;
    repVisitsSPAForm->QuickRep1->Preview();

    AnsiString *pS;

    for(int i = 0; i < pList->Count; i++)
        if((pS = (AnsiString *)pList->Items[i]) != NULL) delete [] pS;

    delete pList;
    delete repVisitsSPAForm;

    mmnRefbook->Visible = mV[0];
    mmnService->Visible = mV[1];
    mmnReport->Visible = mV[2];
    mmnAdmin->Visible = mV[3];
    mmnGoods->Visible = mV[4];

    mmnRefbook->Enabled = mE[0];
    mmnService->Enabled = mE[1];
    mmnReport->Enabled = mE[2];
    mmnAdmin->Enabled = mE[3];
    mmnGoods->Enabled = mE[4];
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::N14Click(TObject *Sender)
{
    bool Period = true;

    if(AdminMode || UserGrants[12] != '0')
    {
        SQL_exefun(DBName,"select SettingsVal from Settings where SettingsKey='repGoodsSPAPeriod'",&retString);
        Period = !(atoi(retString.c_str()) == 0);
    }

    TDateTime bdt;
    TDateTime edt;

    if(Period)
    {
        DateIntervalForm = new TDateIntervalForm(this);

        DTI_BegDate = Now();
        DTI_EndDate = DTI_BegDate;
        FormResult = 0;
        DateIntervalForm->ShowModal();
        delete DateIntervalForm;

        if(FormResult != 1) return;
        bdt = DTI_BegDate;
        edt = DTI_EndDate + 1;
    }
    else
    {
         bdt = Now();
         edt = bdt + 1;
    }

    unsigned Start = (int)bdt;
    unsigned Finish = (int)edt;

    // ������, ������, �������?

    AnsiString sql = "select count(distinct RowID) from Goods where RowID in (";
    sql += "select GoodID from Outcome inner join (select Visits_SPA.RowID as VID from Visits_SPA inner join Services on ServiceID=Services.RowID where Visits_SPA.EDate>=";
    sql += Start;
    sql += " and Visits_SPA.CDate<";
    sql += Finish;
    sql += (" and Tag like '~��������������~%') on Visit_SPAID=VID");

    //sql += ") or RowID in (";
    //sql += "select GoodID from Income inner join Docs on DocID=Docs.RowID where Closed!=0 and EDate>=";
    //sql += Start;
    //sql += " and EDate<";
    //sql += Finish;
    sql += ")";

    SQL_exefun(DBName,sql.c_str(),&retString);
    unsigned cnt = atoi(retString.c_str());

    //if(!cnt)
    //{
    //    Application->MessageBox("��������!\n��� ������ ��� ������.","������ �����",MB_OK);
    //    return;
    //}
    //-----------------------------------------------------------------------------------------------

    pbProgress->Width = ClientWidth;
    pbProgress->Height = ClientHeight;
    pbProgress->Left = 0;
    pbProgress->Top = 0;
    pbProgress->Step = 1;
    pbProgress->Min = 0;
    pbProgress->Position = 0;

    bool mV[5], mE[5];
    mV[0] = mmnRefbook->Visible;
    mV[1] = mmnService->Visible;
    mV[2] = mmnReport->Visible;
    mV[3] = mmnAdmin->Visible;
    mV[4] = mmnGoods->Visible;

    mE[0] = mmnRefbook->Enabled;
    mE[1] = mmnService->Enabled;
    mE[2] = mmnReport->Enabled;
    mE[3] = mmnAdmin->Enabled;
    mE[4] = mmnGoods->Enabled;

    mmnRefbook->Enabled = false;
    mmnService->Enabled = false;
    mmnReport->Enabled = false;
    mmnAdmin->Enabled = false;
    mmnGoods->Enabled = false;
    if(cnt)
        pbProgress->Max = cnt - 1;
    else
        pbProgress->Max = 0;
    pbProgress->Visible = true;

    AnsiString *pLines;
    TList *pList = new TList;

    repGoodsSPAForm = new TrepGoodsSPAForm(this);
    if(Period)
        repGoodsSPAForm->QRHeader->Caption = "����� �� ��������� ���������� (��������������) � " + bdt.DateString() + " �� " + (edt-1).DateString();
    else
        repGoodsSPAForm->QRHeader->Caption = "����� �� ��������� ���������� (��������������) �� " + (edt-1).DateString();
    repGoodsSPAForm->QRCreated->Caption = repCreated(Start < (Finish - 1));

    repGoodsSPAForm->pPrint = pList;

    pList->Add(NULL);
    repGoodsSPAForm->QRlines->Items->Add("E");

    sql = "from Goods where RowID in (";
    sql += "select GoodID from Outcome inner join (select Visits_SPA.RowID as VID from Visits_SPA inner join Services on ServiceID=Services.RowID where Visits_SPA.EDate>=";
    sql += Start;
    sql += " and Visits_SPA.CDate<";
    sql += Finish;
    sql += (" and Tag like '~��������������~%') on Visit_SPAID=VID");

    //sql += ") or RowID in (";
    //sql += "select GoodID from Income inner join Docs on DocID=Docs.RowID where Closed!=0 and EDate>=";
    //sql += Start;
    //sql += " and EDate<";
    //sql += Finish;
    sql += ") order by Name,RowID";
    //unsigned __fastcall SQL_fldCollect(const char *dbname,const char *fName,const char *sql_from,AnsiString **pFld,bool ToAnsi,bool FirstZero,bool Distinct)
    __int64 *pIDs;
    AnsiString *pGoods;
    cnt = SQL_fldKeyCollect(DBName,"Name",sql.c_str(),&pIDs,&pGoods,true,false,true);

    AnsiString sVal;
    double income, outcome, stock;

    for(unsigned counter = 0; counter < cnt; counter++)
    {
        // ������
        sql = "select sum(IncomeCount) from Income inner join Docs on DocID=Docs.RowID where Closed!=0 and Income.GoodID="+AnsiString(pIDs[counter]);
        sql += " and EDate>=";
        sql += Start;
        sql += " and EDate<";
        sql += Finish;

        SQL_exefun(DBName,sql.c_str(),&retString);
        income = atoi(retString.c_str());

        // �������
        sql = "select StockCount,Part from Stock where GoodID="+AnsiString(pIDs[counter]);

        SQL_exefun2(DBName,sql.c_str(),&retString,&sVal);

        stock = atof(retString.c_str()) + (atof(sVal.c_str()) / 1000.0);

        // ������
        sql = "select sum(OutcomeCount),sum(Part) from Outcome inner join (select Visits_SPA.RowID as VID from Visits_SPA inner join Services on ServiceID=Services.RowID where Visits_SPA.EDate>=";
        sql += Start;
        sql += " and Visits_SPA.CDate<";
        sql += Finish;
        sql += (" and Tag like '~��������������~%') on Visit_SPAID=VID");
        sql += " where GoodID=";
        sql += AnsiString(pIDs[counter]);

        SQL_exefun2(DBName,sql.c_str(),&retString,&sVal);

        outcome = atof(retString.c_str()) + (atof(sVal.c_str()) / 1000.0);

        pLines = new AnsiString[4];
        pLines[0] = pGoods[counter];
        pLines[1] = FormatFloat(CountFormat,income);
        pLines[2] = FormatFloat(CountFormat,outcome);
        pLines[3] = FormatFloat(CountFormat,stock);

        pList->Add(pLines);
        repGoodsSPAForm->QRlines->Items->Add("L");

        //pLines = new AnsiString[4];
        //pLines[0] = psPID[cnt_p] + " / " + Tags[tags_cnt];
        //pList->Add(pLines);
        //repGoodsSPAForm->QRlines->Items->Add("H");

        //pLines = new AnsiString[4];
        //pLines[0] = "�����:";
        //pList->Add(pLines);
        //repGoodsSPAForm->QRlines->Items->Add("I");
        //pList->Add(NULL);
        //repGoodsSPAForm->QRlines->Items->Add("E");

        pbProgress->StepIt();
        Application->ProcessMessages();
    }

    delete [] pIDs;

    pList->Add(NULL);
    repGoodsSPAForm->QRlines->Items->Add("E");

    pbProgress->Visible = false;
    repGoodsSPAForm->QuickRep1->Preview();

    for(int i = 0; i < pList->Count; i++)
        if((pLines = (AnsiString *)pList->Items[i]) != NULL) delete [] pLines;

    delete pList;
    delete repGoodsSPAForm;

    mmnRefbook->Visible = mV[0];
    mmnService->Visible = mV[1];
    mmnReport->Visible = mV[2];
    mmnAdmin->Visible = mV[3];
    mmnGoods->Visible = mV[4];

    mmnRefbook->Enabled = mE[0];
    mmnService->Enabled = mE[1];
    mmnReport->Enabled = mE[2];
    mmnAdmin->Enabled = mE[3];
    mmnGoods->Enabled = mE[4];
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::N16Click(TObject *Sender)
{
    bool Period = true;

    if(AdminMode || UserGrants[12] != '0')
    {
        SQL_exefun(DBName,"select SettingsVal from Settings where SettingsKey='repVisitsSPAPeriod'",&retString);
        Period = !(atoi(retString.c_str()) == 0);
    }

    TDateTime bdt;
    TDateTime edt;

    if(Period)
    {
        DateIntervalForm = new TDateIntervalForm(this);

        DTI_BegDate = Now();
        DTI_EndDate = DTI_BegDate;
        FormResult = 0;
        DateIntervalForm->ShowModal();
        delete DateIntervalForm;

        if(FormResult != 1) return;
        bdt = DTI_BegDate;
        edt = DTI_EndDate + 1;
    }
    else
    {
         bdt = Now();
         edt = bdt + 1;
    }

    unsigned Start = (int)bdt;
    unsigned Finish = (int)edt;

    AnsiString *psPID;

    AnsiString sql = "from Visits_SPA inner join Services on ServiceID=Services.RowID where Visits_SPADate>=";
    sql += Start;
    sql += " and Visits_SPADate<";
    sql += Finish;
    sql += " and Tag like '~";
    sql += ("�������� ������");
    sql += "~%'";

    unsigned cnt_visits = SQL_fldCollect(DBName,"PersonID",sql.c_str(),&psPID,false,false,true);

    //if(cnt_visits == 0)
    //{
    //    Application->MessageBox("��������!\n��� ������ ��� ������.","������ �����",MB_OK);
    //    return;
    //}

    pbProgress->Width = ClientWidth;
    pbProgress->Height = ClientHeight;
    pbProgress->Left = 0;
    pbProgress->Top = 0;
    pbProgress->Step = 1;
    pbProgress->Min = 0;
    pbProgress->Position = 0;

    bool mV[5], mE[5];
    mV[0] = mmnRefbook->Visible;
    mV[1] = mmnService->Visible;
    mV[2] = mmnReport->Visible;
    mV[3] = mmnAdmin->Visible;
    mV[4] = mmnGoods->Visible;

    mE[0] = mmnRefbook->Enabled;
    mE[1] = mmnService->Enabled;
    mE[2] = mmnReport->Enabled;
    mE[3] = mmnAdmin->Enabled;
    mE[4] = mmnGoods->Enabled;

    mmnRefbook->Enabled = false;
    mmnService->Enabled = false;
    mmnReport->Enabled = false;
    mmnAdmin->Enabled = false;
    mmnGoods->Enabled = false;

    unsigned i;
    bool fZero = false;

    sql = "from Personal where RowID in (";
    for(i = 0; i < cnt_visits; i++)
    {
        if(_atoi64(psPID[i].c_str()) == 0)
            fZero = true;

        sql += (AnsiString(psPID[i]) + ",");
    }
    if(cnt_visits)
        sql.SetLength(sql.Length() - 1);
    else
        sql += "0";

    sql += ") order by Name,CDate";

    delete [] psPID;

    __int64 *pPIDs;

    unsigned cnt_persons = SQL_fldKeyCollect(DBName,"Name",sql.c_str(),&pPIDs,&psPID,true,fZero);

    if(fZero)
    {
        pPIDs[0] = 0;
        psPID[0] = "��� �����������";
    }
    if(cnt_persons)
        pbProgress->Max = cnt_persons - 1;
    else
        pbProgress->Max = 0;
    pbProgress->Visible = true;

    TList *pList = new TList;
    AnsiString *pLines;
    AnsiString sRow[8];
    AnsiString *psVID;

    //char *Tags[] = { "����", "����", "����� ����", "�������", "������� (�����)" };
    AnsiString *Tags;

    unsigned l2cnt = SQL_fldCollect(NULL,"Name","from Services where Tag='~�������� ������~'",&Tags);



    repVisitsSPAForm = new TrepVisitsSPAForm(this);
    if(Period)
        repVisitsSPAForm->QRHeader->Caption = "����� �� ������� ��������� ������� � " + bdt.DateString() + " �� " + (edt-1).DateString();
    else
        repVisitsSPAForm->QRHeader->Caption = "����� �� ������� ��������� ������� �� " + (edt-1).DateString();
    repVisitsSPAForm->QRCreated->Caption = repCreated(Start < (Finish - 1));

    repVisitsSPAForm->pPrint = pList;

    pList->Add(NULL);
    repVisitsSPAForm->QRlines->Items->Add("E");

    for(unsigned cnt_p = 0; cnt_p < cnt_persons; cnt_p++)
    {
        for(unsigned tags_cnt = 0; tags_cnt < l2cnt; tags_cnt++)
        {
            sql = "from Visits_SPA where PersonID=";
            sql += pPIDs[cnt_p];
            sql += " and Visits_SPADate>=";
            sql += Start;
            sql += " and Visits_SPADate<";
            sql += Finish;
            sql += (" and ServiceID in (select RowID from Services where Tag like '~" + (AnsiString("�������� ������~")+Tags[tags_cnt]) + "~%') order by CDate");

            cnt_visits = SQL_fldCollect(DBName,"RowID",sql.c_str(),&psVID);

            if(cnt_visits)
            {
                pLines = new AnsiString[4];
                pLines[0] = psPID[cnt_p] + " / " + Tags[tags_cnt];
                pList->Add(pLines);
                repVisitsSPAForm->QRlines->Items->Add("H");
            }
            else
                continue;

            for(unsigned cnt_v = 0; cnt_v < cnt_visits; cnt_v++)
            {
                pLines = new AnsiString[4];


                SQL_exefunrow(DBName,("select ServiceID,AbonementID,ClientID,Price,PersonPrice,GroupCnt,BegTime,EndTime from Visits_SPA where RowID="+AnsiString(_atoi64(psVID[cnt_v].c_str()))).c_str(),8,sRow);
                SQL_exefun(DBName,("select '['||b.Name||']'||a.Name from Services a left outer join Services b on a.ParentID=b.RowID where a.RowID="+AnsiString(_atoi64(sRow[0].c_str()))).c_str(),&retString);

                pLines[0] = retString;

                if(!_atoi64(sRow[1].c_str()))
                    SQL_exefun(DBName,("select FName||' '||SName||' '||TName from Clients where RowID="+AnsiString(_atoi64(sRow[2].c_str()))).c_str(),&retString);
                else
                    SQL_exefun(DBName,("select FName||' '||SName||' '||TName from Clients where RowID=(select ClientID from Abonements_SPA where RowID="+AnsiString(_atoi64(sRow[1].c_str()))+")").c_str(),&retString);

                pLines[1] = retString;

                double price = atof(sRow[3].c_str());
                double pprice = atof(sRow[4].c_str());

                //if(pprice == 0.0)
                //{
                    // ��������� ��������� ��������????????????/
                    //SQL_exefun
                //    pprice = price;
                //}
                //if(pprice == 0.0)
                //    pLines[2] = FormatFloat(MoneyFormat,price) + " / 0.00";
                //else
                //sRow[5], sRow[6], sRow[7]
                SQL_exefun(DBName,("select Timed from Services where RowID="+AnsiString(_atoi64(sRow[0].c_str()))).c_str(),&retString);

                if(atoi(retString.c_str()) > 0)
                    pLines[2] = "(" + sRow[5] + "-" + TDateTime(atof(sRow[7].c_str()) - atof(sRow[6].c_str())).FormatString("h:nn") + ") ";
                //else
                //    pLines[2] = FormatFloat(MoneyFormat,pprice) + " / " + FormatFloat(MoneyFormat,price-pprice);

                pLines[2] += (FormatFloat(MoneyFormat,pprice) + " / " + FormatFloat(MoneyFormat,price-pprice));

                repVisitsSPAForm->QRlines->Items->Add("L");

                pList->Add(pLines);

            }

            pLines = new AnsiString[4];
            pLines[0] = "�����:";
            pList->Add(pLines);
            repVisitsSPAForm->QRlines->Items->Add("I");
            pList->Add(NULL);
            repVisitsSPAForm->QRlines->Items->Add("E");

            delete [] psVID;
        }

        pbProgress->StepIt();
        Application->ProcessMessages();
    }

    delete [] psPID;
    delete [] pPIDs;

    delete [] Tags;

    pbProgress->Visible = false;
    repVisitsSPAForm->QuickRep1->Preview();

    AnsiString *pS;

    for(int i = 0; i < pList->Count; i++)
        if((pS = (AnsiString *)pList->Items[i]) != NULL) delete [] pS;

    delete pList;
    delete repVisitsSPAForm;

    mmnRefbook->Visible = mV[0];
    mmnService->Visible = mV[1];
    mmnReport->Visible = mV[2];
    mmnAdmin->Visible = mV[3];
    mmnGoods->Visible = mV[4];

    mmnRefbook->Enabled = mE[0];
    mmnService->Enabled = mE[1];
    mmnReport->Enabled = mE[2];
    mmnAdmin->Enabled = mE[3];
    mmnGoods->Enabled = mE[4];
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::N17Click(TObject *Sender)
{
    bool Period = true;

    if(AdminMode || UserGrants[12] != '0')
    {
        SQL_exefun(DBName,"select SettingsVal from Settings where SettingsKey='repVisitsSPAPeriod'",&retString);
        Period = !(atoi(retString.c_str()) == 0);
    }

    TDateTime bdt;
    TDateTime edt;

    if(Period)
    {
        DateIntervalForm = new TDateIntervalForm(this);

        DTI_BegDate = Now();
        DTI_EndDate = DTI_BegDate;
        FormResult = 0;
        DateIntervalForm->ShowModal();
        delete DateIntervalForm;

        if(FormResult != 1) return;
        bdt = DTI_BegDate;
        edt = DTI_EndDate + 1;
    }
    else
    {
         bdt = Now();
         edt = bdt + 1;
    }

    unsigned Start = (int)bdt;
    unsigned Finish = (int)edt;

    AnsiString *psPID;

    AnsiString sql = "from Visits_SPA inner join Services on ServiceID=Services.RowID where Visits_SPADate>=";
    sql += Start;
    sql += " and Visits_SPADate<";
    sql += Finish;
    sql += " and (Tag like '~SPA~%' or Tag like '~����~%' or Tag like '~��������������~%' or Tag like '~�������� ������~%')";

    unsigned cnt_visits = SQL_fldCollect(DBName,"PersonID",sql.c_str(),&psPID,false,false,true);

    if(cnt_visits == 0)
    {
        Application->MessageBox("��������!\n��� ������ ��� ������.","������ �����",MB_OK);
        return;
    }

    pbProgress->Width = ClientWidth;
    pbProgress->Height = ClientHeight;
    pbProgress->Left = 0;
    pbProgress->Top = 0;
    pbProgress->Step = 1;
    pbProgress->Min = 0;
    pbProgress->Position = 0;

    bool mV[5], mE[5];
    mV[0] = mmnRefbook->Visible;
    mV[1] = mmnService->Visible;
    mV[2] = mmnReport->Visible;
    mV[3] = mmnAdmin->Visible;
    mV[4] = mmnGoods->Visible;

    mE[0] = mmnRefbook->Enabled;
    mE[1] = mmnService->Enabled;
    mE[2] = mmnReport->Enabled;
    mE[3] = mmnAdmin->Enabled;
    mE[4] = mmnGoods->Enabled;

    mmnRefbook->Enabled = false;
    mmnService->Enabled = false;
    mmnReport->Enabled = false;
    mmnAdmin->Enabled = false;
    mmnGoods->Enabled = false;

    unsigned i;
    bool fZero = false;

    sql = "from Personal where RowID in (";
    for(i = 0; i < cnt_visits; i++)
    {
        if(_atoi64(psPID[i].c_str()) == 0)
            fZero = true;

        sql += (AnsiString(psPID[i]) + ",");
    }

    sql.SetLength(sql.Length() - 1);

    sql += ") order by Name,CDate";

    delete [] psPID;

    __int64 *pPIDs;

    unsigned cnt_persons = SQL_fldKeyCollect(DBName,"Name",sql.c_str(),&pPIDs,&psPID,true,fZero);

    if(fZero)
    {
        pPIDs[0] = 0;
        psPID[0] = "��� �����������";
    }

    pbProgress->Max = cnt_persons - 1;
    pbProgress->Visible = true;

    TList *pList = new TList;
    AnsiString *pLines;
    AnsiString sRow[5];
    AnsiString *psVID;
    char *Tags[] =  {   "������", "�����������",
                        "������� ���� (� ������������)", "������� ���� (� �����������)", "������ (� ������������)", "������ (� �����������)",
                        "������� ���", "������� ���", "������� ���",
                        "����", "����", "����� ����"
                    };

    char *pRoot[] = { "SPA", "����", "��������������", "�������� ������" };
    char *pLink[12];

    pLink[0] = pLink[1] = pRoot[0];
    pLink[2] = pLink[3] = pLink[4] = pLink[5] = pRoot[1];
    pLink[6] = pLink[7] = pLink[8] = pRoot[2];
    pLink[9] = pLink[10] = pLink[11] = pRoot[3];

    repVisitsSPAForm = new TrepVisitsSPAForm(this);
    if(Period)
        repVisitsSPAForm->QRHeader->Caption = "����� �� ������� SPA � " + bdt.DateString() + " �� " + (edt-1).DateString();
    else
        repVisitsSPAForm->QRHeader->Caption = "����� �� ������� SPA �� " + (edt-1).DateString();
    repVisitsSPAForm->QRCreated->Caption = repCreated(Start < (Finish - 1));

    repVisitsSPAForm->pPrint = pList;

    pList->Add(NULL);
    repVisitsSPAForm->QRlines->Items->Add("E");

    for(unsigned cnt_p = 0; cnt_p < cnt_persons; cnt_p++)
    {
        for(unsigned tags_cnt = 0; tags_cnt < 12; tags_cnt++)
        {
            sql = "from Visits_SPA where PersonID=";
            sql += pPIDs[cnt_p];
            sql += " and Visits_SPADate>=";
            sql += Start;
            sql += " and Visits_SPADate<";
            sql += Finish;
            sql += (AnsiString(" and ServiceID in (select RowID from Services where Tag like '~") + pLink[tags_cnt] +



            "~" + (Tags[tags_cnt]) + "~%') order by CDate");

            cnt_visits = SQL_fldCollect(DBName,"RowID",sql.c_str(),&psVID);

            if(cnt_visits)
            {
                pLines = new AnsiString[4];
                pLines[0] = psPID[cnt_p] + " / " + Tags[tags_cnt];
                pList->Add(pLines);
                repVisitsSPAForm->QRlines->Items->Add("H");
            }
            else
                continue;

            for(unsigned cnt_v = 0; cnt_v < cnt_visits; cnt_v++)
            {
                pLines = new AnsiString[4];

                SQL_exefunrow(DBName,("select ServiceID,AbonementID,ClientID,Price,PersonPrice from Visits_SPA where RowID="+AnsiString(_atoi64(psVID[cnt_v].c_str()))).c_str(),5,sRow);
                SQL_exefun(DBName,("select '['||b.Name||']'||a.Name from Services a left outer join Services b on a.ParentID=b.RowID where a.RowID="+AnsiString(_atoi64(sRow[0].c_str()))).c_str(),&retString);

                pLines[0] = retString;

                if(!_atoi64(sRow[1].c_str()))
                    SQL_exefun(DBName,("select FName||' '||SName||' '||TName from Clients where RowID="+AnsiString(_atoi64(sRow[2].c_str()))).c_str(),&retString);
                else
                    SQL_exefun(DBName,("select FName||' '||SName||' '||TName from Clients where RowID=(select ClientID from Abonements_SPA where RowID="+AnsiString(_atoi64(sRow[1].c_str()))+")").c_str(),&retString);

                pLines[1] = retString;

                double price = atof(sRow[3].c_str());
                double pprice = atof(sRow[4].c_str());

                //if(pprice == 0.0)
                //    pLines[2] = FormatFloat(MoneyFormat,price) + " / 0.00";
                //else
                pLines[2] = FormatFloat(MoneyFormat,pprice) + " / " + FormatFloat(MoneyFormat,price-pprice);

                repVisitsSPAForm->QRlines->Items->Add("L");

                pList->Add(pLines);

            }

            pLines = new AnsiString[4];
            pLines[0] = "�����:";
            pList->Add(pLines);
            repVisitsSPAForm->QRlines->Items->Add("I");
            pList->Add(NULL);
            repVisitsSPAForm->QRlines->Items->Add("E");

            delete [] psVID;
        }

        pbProgress->StepIt();
        Application->ProcessMessages();
    }

    delete [] psPID;
    delete [] pPIDs;

    pbProgress->Visible = false;
    repVisitsSPAForm->QuickRep1->Preview();

    AnsiString *pS;

    for(int i = 0; i < pList->Count; i++)
        if((pS = (AnsiString *)pList->Items[i]) != NULL) delete [] pS;

    delete pList;
    delete repVisitsSPAForm;

    mmnRefbook->Visible = mV[0];
    mmnService->Visible = mV[1];
    mmnReport->Visible = mV[2];
    mmnAdmin->Visible = mV[3];
    mmnGoods->Visible = mV[4];

    mmnRefbook->Enabled = mE[0];
    mmnService->Enabled = mE[1];
    mmnReport->Enabled = mE[2];
    mmnAdmin->Enabled = mE[3];
    mmnGoods->Enabled = mE[4];
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CorrectSIDs1Click(TObject *Sender)
{
    __int64 *pIDs;
    AnsiString *pPIDs;

    __int64 ID;
    int cnt = SQL_fldKeyCollect(DBName,"ParentID","from Services where RowID>=307 order by ID",&pIDs,&pPIDs);

    for(int i = cnt - 1; i >= 0; i--)
    {
        ID = _atoi64(pPIDs[i].c_str());
        SQL_iniUpdate(DBName,"Services",pIDs[i]);
        if(ID)
            SQL_addUpdate("ParentID",ID+2);
        SQL_exeUpdate("ID",pIDs[i]+2);
    }

    delete [] pPIDs;
    delete [] pIDs;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::N18Click(TObject *Sender)
{
    SellsForm = new TSellsForm(this);
    SellsForm->ShowModal();
    delete SellsForm;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::StockRecalc1Click(TObject *Sender)
{
    // Stock Recalc
    SQL_BeginTransaction();
    SQL_exe(DBName,"delete from Stock");
    SQL_exe(DBName,"delete from Income where DocID not in (select RowID from Docs)");
    // ���� �� ��������
    AnsiString sql, sPart, *pIDs;
    double QTTY, ToBalanse, FromBalanse;

    unsigned cnt = SQL_fldCollect(DBName,"GoodID","from Income",&pIDs,false,false,true);

    for(unsigned i = 0; i < cnt; i++)
    {
        ///////////////////////////////////////////////////////////////
        // ������

        sql = "select sum(IncomeCount),sum(Part) from Income inner join Docs on DocID=Docs.RowID where Closed!=0 and GoodID=";
        sql += pIDs[i];


        SQL_exefun2(DBName,sql.c_str(),&retString,&sPart);
        ToBalanse = (atof(sPart.c_str()) / 1000) + atof(retString.c_str());


        ///////////////////////////////////////////////////////////////
        // �������

        sql = "select sum(BillItemsCount) from BillItems inner join Bills on BillID=Bills.RowID where Op=4 and GoodID=";
        sql += pIDs[i];


        SQL_exefun(DBName,sql.c_str(),&retString);
        FromBalanse = atof(retString.c_str());

        QTTY = ToBalanse - FromBalanse;

        SQL_iniInsert(DBName,"Stock");
        SQL_addInsert("GoodID",pIDs[i]);
        SQL_exeInsert("StockCount",(int)SimpleRoundTo(QTTY,0));

    }

    SQL_CommitTransaction();

    delete [] pIDs;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::mmnCalendarClick(TObject *Sender)
{
    CalendarForm = new TCalendarForm(this);
    CalendarForm->ShowModal();
    delete CalendarForm;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::mmnFitGroupClick(TObject *Sender)
{
    FitGroupForm = new TFitGroupForm(this);
    FitGroupForm->ShowModal();
    delete FitGroupForm;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::tiReserveTimer(TObject *Sender)
{

    // �������������� �������� �������
    ReserveFlag = true;

    TDateTime dt = (double)Now() - (15.0 / 1440.0);

    AnsiString *psIDs;

    TIBTransaction *pTrans = new TIBTransaction(NULL);
    pTrans->DefaultDatabase = dmMain->DBMain;
    pTrans->Params->Clear();
    pTrans->Params->Add("read_committed");
    pTrans->Params->Add("rec_version");
    pTrans->Params->Add("nowait");

    //read_committed
    //rec_version
    //nowait


    TIBQuery *pQue = new TIBQuery(NULL);
    pQue->Database = dmMain->DBMain;
    pQue->Transaction = pTrans;
    
    TDataSource *pDS = new TDataSource(NULL);
    pDS->DataSet = pQue;

    pTrans->Active = true;


    AnsiString sql = "select RowID from FitGroup where Closed=0 and BegDate<" + AnsiString((double)dt);

    pQue->SQL->Add(sql);
    pQue->Prepare();
    pQue->Open();

    if(pQue->Eof)
    {
        pQue->Close();
        pTrans->Active = false;
        delete pDS;
        delete pQue;
        delete pTrans;

        ReserveFlag = false;
        return;
    }

    pQue->FetchAll();

    unsigned cnt = pQue->RecordCount;
    psIDs = new AnsiString[cnt];
    for(unsigned i = 0; i < cnt; i++)
    {
        psIDs[i] = pQue->Fields->Fields[0]->AsString;
        pQue->Next();
    }

    pQue->Close();

    for(unsigned i = 0; i < cnt; i++)
    {
        AnsiString *psCIDs;
        __int64 *pRIDs;

        sql = "select RowID,ClientID from Reserve where FitGroupID="+psIDs[i]+" and Status=1";
        pQue->SQL->Clear();
        pQue->SQL->Add(sql);
        pQue->Prepare();
        pQue->Open();

        if(pQue->Eof)
        {
            pQue->Close();
            continue;
        }

        pQue->FetchAll();
        unsigned rcnt = pQue->RecordCount;

        pRIDs = new __int64[rcnt];
        psCIDs = new AnsiString[rcnt];

        for(unsigned j = 0; j < rcnt; j++)
        {
            pRIDs[j] = _atoi64(pQue->Fields->Fields[0]->AsString.c_str());
            psCIDs[j] = pQue->Fields->Fields[1]->AsString;

            pQue->Next();
        }

        pQue->Close();

        for(unsigned j = 0; j < rcnt; j++)
        {

            __int64 RID = pRIDs[j];

            if(!RID) continue;

            //AnsiString sFixSum, sCounter;


            pQue->SQL->Clear();
            pQue->SQL->Add("select count(*) from Abonements where Closed=0 and FixSum>=0 and ClientID="+psCIDs[j]);
            pQue->Prepare();
            pQue->Open();
            unsigned abs_cnt = 0;
            if(!pQue->Eof)
                abs_cnt = pQue->Fields->Fields[0]->AsInteger;
            pQue->Close();

            if(!abs_cnt)
            {
                continue;
            }


            pQue->SQL->Clear();
            pQue->SQL->Add("select first 1 FixSum from Abonements where Closed=0 and FixSum>=0 and ClientID="+psCIDs[j]+" order by BegDate,CDate");

            pQue->Prepare();
            pQue->Open();

            if(!pQue->Eof)
            {
                if(pQue->Fields->Fields[0]->AsFloat == 0.0)
                {
                    pQue->Close();
                    pQue->SQL->Clear();
                    pQue->SQL->Add("select count(*) from Abonements where Closed=0 and FixSum>=0 and EndDate>="+AnsiString((int)Now())+" and ClientID="+psCIDs[j]);
                    pQue->Prepare();
                    pQue->Open();

                    abs_cnt = (pQue->Eof)? 0 : pQue->Fields->Fields[0]->AsInteger;

                    pQue->Close();
                    // ��������� �������� �� ����� ����������� ���������

                    if(!abs_cnt)
                    {
                        continue;
                    }
                }
            }

            pQue->Close();

            //-----------------------------------------------------
            AnsiString pRowRes[4];

            pQue->SQL->Clear();
            pQue->SQL->Add("select BegDate,EndDate,ServiceID,PersonID from Reserve where RowID="+AnsiString(RID));
            pQue->Prepare();
            pQue->Open();

            // �������� ������ ���������
            if(!pQue->Eof)
            {
                pRowRes[0] = pQue->Fields->Fields[0]->AsString;
                pRowRes[1] = pQue->Fields->Fields[1]->AsString;
                pRowRes[2] = pQue->Fields->Fields[2]->AsString;
                pRowRes[3] = pQue->Fields->Fields[3]->AsString;
            }

            pQue->Close();

            AnsiString pRow[4];

            pQue->SQL->Clear();
            pQue->SQL->Add("select first 1 RowID,Price,AbonementsCount,FixSum from Abonements where Closed=0 and FixSum>=0 and ClientID="+psCIDs[j]+" order by BegDate,CDate");
            pQue->Prepare();
            pQue->Open();

            if(!pQue->Eof)
            {
                pRow[0] = pQue->Fields->Fields[0]->AsString;
                pRow[1] = pQue->Fields->Fields[1]->AsString;
                pRow[2] = pQue->Fields->Fields[2]->AsString;
                pRow[3] = pQue->Fields->Fields[3]->AsString;
            }

            pQue->Close();

            __int64 AbID = _atoi64(pRow[0].c_str());

            double price = atof(pRow[1].c_str());
            unsigned count = atoi(pRow[2].c_str());
            double fixsum = atof(pRow[3].c_str());

            //-----------------------------------------
            //pQue->SQL->Clear();

            sql = "insert into Visits (AbonementID,VisitsDate,BegTime,EndTime,Price,PersonID,ServiceID,CDate,CUID,EDate,EUID) values (";

            sql += AbID;

            TDateTime bd = atof(pRowRes[0].c_str());
            TDateTime ed = atof(pRowRes[1].c_str());
            double x;
            sql += ",";
            sql += (int)bd;
            sql += ",";
            sql += modf(bd,&x);
            sql += ",";
            sql += modf(ed,&x);

            sql += ",";
            if(fixsum > 0.0)
                sql += fixsum;
            else
            {
                if(count != 0.0)
                    sql += price/count;
                else
                {
                    continue;
                }
            }
            sql += ",";
            sql += _atoi64(pRowRes[3].c_str());
            sql += ",";
            sql += _atoi64(pRowRes[2].c_str());
            dt = Now();
            sql += ",";
            sql += (double)dt;
            sql += ",";
            sql += UserID;
            sql += ",";
            sql += (double)dt;
            sql += ",";
            sql += UserID;
            sql += ")";

            pQue->SQL->Clear();
            pQue->SQL->Add(sql);
            pQue->Prepare();
            pQue->ExecSQL();
            pQue->Close();

            price -= fixsum;

            if(count == 1 && fixsum != 0.0 && price > 0.0)
            {
                // ������� ������� �� �������
                pQue->SQL->Clear();
                pQue->SQL->Add("select RowID from Services where Name='�������'");
                pQue->Prepare();
                pQue->Open();

                __int64 ID = (pQue->Eof)? 0 : _atoi64(pQue->Fields->Fields[0]->AsString.c_str());

                pQue->Close();

                if(!ID)
                {
                    continue;
                }

                //pQue->SQL->Clear();

                sql = "insert into Visits (AbonementID,VisitsDate,BegTime,EndTime,Price,PersonID,ServiceID,CDate,CUID,EDate,EUID) values (";

                sql += AbID;
                sql += ",";
                sql += (int)bd;
                sql += ",";
                sql += modf(bd,&x);
                sql += ",";
                sql += modf(ed,&x);
                sql += ",";
                sql += price;
                sql += ",0";
                sql += ",";
                sql += ID;
                sql += ",";
                sql += (double)dt;
                sql += ",";
                sql += UserID;
                sql += ",";
                sql += (double)dt;
                sql += ",";
                sql += UserID;
                sql += ")";

                pQue->SQL->Clear();
                pQue->SQL->Add(sql);
                pQue->Prepare();
                pQue->ExecSQL();
                pQue->Close();
            }

            // � ������ �� ������
            //SQL_iniUpdate(DBName,"Reserve",pRIDs[j]);
            //SQL_exeUpdate("Status",2);
        }

        delete [] pRIDs;
        delete [] psCIDs;
    }

    if(cnt)
    {
        sql = "update FitGroup set Closed=1 where RowID in (";

        for(unsigned i = 0; i < cnt; i++)
            sql += psIDs[i] + ",";

        sql.SetLength(sql.Length()-1);
        sql += ")";

        pQue->SQL->Clear();
        pQue->SQL->Add(sql);
        pQue->Prepare();
        pQue->ExecSQL();
        pQue->Close();
    }

    delete [] psIDs;

    pTrans->Commit();
    pTrans->Active = false;
    
    delete pDS;
    delete pQue;
    delete pTrans;

    ReserveFlag = false;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::txt1Click(TObject *Sender)
{
    TStringList *pList = new TStringList;

    pList->LoadFromFile("iserv.txt");

    for(int i = 0,j = 0; i < pList->Count; i++)
        if(pList->Strings[j].IsEmpty()) pList->Delete(j);
        else j++;

    if(pList->Count)
    {
        double price;
        double dt;
        AnsiString s, Tag1, Tag2, Tag3, Tag, sGroup;
        int level;
        __int64 ID1, ID2, ID3, PID, ID;

        ID1 = ID2 = ID3 = PID = 0;

        SQL_BeginTransaction();

        for(int i = 0; i < pList->Count; i++)
        {
            level = 0;
            sGroup.SetLength(0);

            if(pList->Strings[i][1] == '#')
            {
                level++;
                if(pList->Strings[i][2] == '#')
                {
                    level++;
                    if(pList->Strings[i][3] == '#')
                        level++;
                }
            }

            // �������

            s = pList->Strings[i].SubString(level+1,pList->Strings[i].Length()-level);
            int pos = s.Pos("^");

            if(pos > 0)
            {
                price = atof(s.c_str()+pos);

                // � ����� ���� ��� GroupPrice
                char *p = strchr(s.c_str()+pos,'^');
                if(p)
                    sGroup = p + 1;


                s = s.SubString(1,pos-1);


            }
            else
                price = 0.0;





            switch(level)
            {
case 0:         Tag = "~"; Tag1 = "~" + s + "~"; break;
case 1:         if(!ID1) continue; Tag = Tag1; Tag2 = Tag1 + s + "~"; PID = ID1; break;
case 2:         if(!ID2) continue; Tag = Tag2; Tag3 = Tag2 + s + "~"; PID = ID2; break;
case 3:         if(!ID3) continue; Tag = Tag3; PID = ID3;
            }

            // ����� � ������������
            SQL_exefun(NULL,("select RowID from Services where Tag='" + Tag + "' and Name='" + s + "'").c_str(),&retString);

            ID = _atoi64(retString.c_str());
            dt = Now();

            if(ID)
            {
                // ���� �����, �������� ����!
                SQL_iniUpdate(NULL,"Services",ID);
                SQL_addUpdate("Price",price);

                if(sGroup.IsEmpty())
                    SQL_addUpdate("PersonPrice",price);
                else
                {
                    SQL_addUpdate("PersonPrice",0);
                    SQL_addUpdate("IsGroup",sGroup.Length());
                    SQL_addUpdate("!GroupPrice",sGroup);
                }

                SQL_addUpdate("EDate",dt);
                SQL_exeUpdate("EUID",UserID);
            }
            else
            {
                SQL_iniInsert(NULL,"Services",&ID);
                SQL_addInsert("!Name",s);
                if(level)
                    SQL_addInsert("ParentID",PID);

                SQL_addInsert("!Tag",Tag);

                SQL_addInsert("Price",price);

                if(sGroup.IsEmpty())
                    SQL_addInsert("PersonPrice",price);
                else
                {
                    SQL_addInsert("PersonPrice",0);
                    SQL_addInsert("IsGroup",sGroup.Length());
                    SQL_addInsert("!GroupPrice",sGroup);
                }

                SQL_addInsert("Personify",1);

                SQL_addInsert("CDate",dt);
                SQL_addInsert("CUID",UserID);
                SQL_addInsert("EDate",dt);
                SQL_exeInsert("EUID",UserID);
            }

            switch(level)
            {
case 0:         ID1 = ID; ID2 = 0; ID3 = 0; break;
case 1:         ID2 = ID; ID3 = 0; break;
case 2:         ID3 = ID;
            }
        }

        SQL_CommitTransaction();

        Application->MessageBox("������!","",MB_OK);
    }
    else Application->MessageBox("������ �������������!","",MB_OK);

    delete pList;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::N10Click(TObject *Sender)
{
    bool Period = true;

    if(AdminMode || UserGrants[12] != '0')
    {
        SQL_exefun(DBName,"select SettingsVal from Settings where SettingsKey='repVisitsSPAPeriod'",&retString);
        Period = !(atoi(retString.c_str()) == 0);
    }

    TDateTime bdt;
    TDateTime edt;

    if(Period)
    {
        DateIntervalForm = new TDateIntervalForm(this);

        DTI_BegDate = Now();
        DTI_EndDate = DTI_BegDate;
        FormResult = 0;
        DateIntervalForm->ShowModal();
        delete DateIntervalForm;

        if(FormResult != 1) return;
        bdt = DTI_BegDate;
        edt = DTI_EndDate + 1;
    }
    else
    {
         bdt = Now();
         edt = bdt + 1;
    }

    unsigned Start = (int)bdt;
    unsigned Finish = (int)edt;

    AnsiString *psPID;

    AnsiString sql = "from Visits_SPA inner join Services on ServiceID=Services.RowID where Visits_SPADate>=";
    sql += Start;
    sql += " and Visits_SPADate<";
    sql += Finish;
    sql += " and Tag like '~";
    sql += ("������� ������������");
    sql += "~%'";

    unsigned cnt_visits = SQL_fldCollect(DBName,"PersonID",sql.c_str(),&psPID,false,false,true);

    //if(cnt_visits == 0)
    //{
    //    Application->MessageBox("��������!\n��� ������ ��� ������.","������ �����",MB_OK);
    //    return;
    //}

    pbProgress->Width = ClientWidth;
    pbProgress->Height = ClientHeight;
    pbProgress->Left = 0;
    pbProgress->Top = 0;
    pbProgress->Step = 1;
    pbProgress->Min = 0;
    pbProgress->Position = 0;

    bool mV[5], mE[5];
    mV[0] = mmnRefbook->Visible;
    mV[1] = mmnService->Visible;
    mV[2] = mmnReport->Visible;
    mV[3] = mmnAdmin->Visible;
    mV[4] = mmnGoods->Visible;

    mE[0] = mmnRefbook->Enabled;
    mE[1] = mmnService->Enabled;
    mE[2] = mmnReport->Enabled;
    mE[3] = mmnAdmin->Enabled;
    mE[4] = mmnGoods->Enabled;

    mmnRefbook->Enabled = false;
    mmnService->Enabled = false;
    mmnReport->Enabled = false;
    mmnAdmin->Enabled = false;
    mmnGoods->Enabled = false;

    unsigned i;
    bool fZero = false;

    sql = "from Personal where RowID in (";
    for(i = 0; i < cnt_visits; i++)
    {
        if(_atoi64(psPID[i].c_str()) == 0)
            fZero = true;

        sql += (AnsiString(psPID[i]) + ",");
    }
    if(cnt_visits)
        sql.SetLength(sql.Length() - 1);
    else
        sql += "0";

    sql += ") order by Name,CDate";

    delete [] psPID;

    __int64 *pPIDs;

    unsigned cnt_persons = SQL_fldKeyCollect(DBName,"Name",sql.c_str(),&pPIDs,&psPID,true,fZero);

    if(fZero)
    {
        pPIDs[0] = 0;
        psPID[0] = "��� �����������";
    }
    if(cnt_persons)
        pbProgress->Max = cnt_persons - 1;
    else
        pbProgress->Max = 0;
    pbProgress->Visible = true;

    TList *pList = new TList;
    AnsiString *pLines;
    AnsiString sRow[8];
    AnsiString *psVID;

    AnsiString *Tags;

    unsigned l2cnt = SQL_fldCollect(NULL,"Name","from Services where Tag='~������� ������������~'",&Tags);

    //char *Tags[] = { "����", "����", "����� ����" };

    repVisitsSPAForm = new TrepVisitsSPAForm(this);
    if(Period)
        repVisitsSPAForm->QRHeader->Caption = "����� �� ������� ������������ � " + bdt.DateString() + " �� " + (edt-1).DateString();
    else
        repVisitsSPAForm->QRHeader->Caption = "����� �� ������� ������������ �� " + (edt-1).DateString();
    repVisitsSPAForm->QRCreated->Caption = repCreated(Start < (Finish - 1));

    repVisitsSPAForm->pPrint = pList;

    pList->Add(NULL);
    repVisitsSPAForm->QRlines->Items->Add("E");

    for(unsigned cnt_p = 0; cnt_p < cnt_persons; cnt_p++)
    {
        for(unsigned tags_cnt = 0; tags_cnt < l2cnt; tags_cnt++)
        {
            sql = "from Visits_SPA where PersonID=";
            sql += pPIDs[cnt_p];
            sql += " and Visits_SPADate>=";
            sql += Start;
            sql += " and Visits_SPADate<";
            sql += Finish;
            sql += (" and ServiceID in (select RowID from Services where Tag like '~" + (AnsiString("������� ������������~")+Tags[tags_cnt]) + "~%') order by CDate");

            cnt_visits = SQL_fldCollect(DBName,"RowID",sql.c_str(),&psVID);

            if(cnt_visits)
            {
                pLines = new AnsiString[4];
                pLines[0] = psPID[cnt_p] + " / " + Tags[tags_cnt];
                pList->Add(pLines);
                repVisitsSPAForm->QRlines->Items->Add("H");
            }
            else
                continue;

            for(unsigned cnt_v = 0; cnt_v < cnt_visits; cnt_v++)
            {
                pLines = new AnsiString[4];


                SQL_exefunrow(DBName,("select ServiceID,AbonementID,ClientID,Price,PersonPrice,GroupCnt,BegTime,EndTime from Visits_SPA where RowID="+AnsiString(_atoi64(psVID[cnt_v].c_str()))).c_str(),8,sRow);
                SQL_exefun(DBName,("select '['||b.Name||']'||a.Name from Services a left outer join Services b on a.ParentID=b.RowID where a.RowID="+AnsiString(_atoi64(sRow[0].c_str()))).c_str(),&retString);

                pLines[0] = retString;

                if(!_atoi64(sRow[1].c_str()))
                    SQL_exefun(DBName,("select FName||' '||SName||' '||TName from Clients where RowID="+AnsiString(_atoi64(sRow[2].c_str()))).c_str(),&retString);
                else
                    SQL_exefun(DBName,("select FName||' '||SName||' '||TName from Clients where RowID=(select ClientID from Abonements_SPA where RowID="+AnsiString(_atoi64(sRow[1].c_str()))+")").c_str(),&retString);

                pLines[1] = retString;

                double price = atof(sRow[3].c_str());
                double pprice = atof(sRow[4].c_str());

                //if(pprice == 0.0)
                //{
                    // ��������� ��������� ��������????????????/
                    //SQL_exefun
                //    pprice = price;
                //}
                //if(pprice == 0.0)
                //    pLines[2] = FormatFloat(MoneyFormat,price) + " / 0.00";
                //else
                //sRow[5], sRow[6], sRow[7]
                SQL_exefun(DBName,("select Timed from Services where RowID="+AnsiString(_atoi64(sRow[0].c_str()))).c_str(),&retString);

                if(atoi(retString.c_str()) > 0)
                    pLines[2] = "(" + sRow[5] + "-" + TDateTime(atof(sRow[7].c_str()) - atof(sRow[6].c_str())).FormatString("h:nn") + ") ";
                //else
                //    pLines[2] = FormatFloat(MoneyFormat,pprice) + " / " + FormatFloat(MoneyFormat,price-pprice);

                pLines[2] += (FormatFloat(MoneyFormat,pprice) + " / " + FormatFloat(MoneyFormat,price-pprice));

                repVisitsSPAForm->QRlines->Items->Add("L");

                pList->Add(pLines);

            }

            pLines = new AnsiString[4];
            pLines[0] = "�����:";
            pList->Add(pLines);
            repVisitsSPAForm->QRlines->Items->Add("I");
            pList->Add(NULL);
            repVisitsSPAForm->QRlines->Items->Add("E");

            delete [] psVID;
        }

        pbProgress->StepIt();
        Application->ProcessMessages();
    }

    delete [] psPID;
    delete [] pPIDs;

    delete [] Tags;

    pbProgress->Visible = false;
    repVisitsSPAForm->QuickRep1->Preview();

    AnsiString *pS;

    for(int i = 0; i < pList->Count; i++)
        if((pS = (AnsiString *)pList->Items[i]) != NULL) delete [] pS;

    delete pList;
    delete repVisitsSPAForm;

    mmnRefbook->Visible = mV[0];
    mmnService->Visible = mV[1];
    mmnReport->Visible = mV[2];
    mmnAdmin->Visible = mV[3];
    mmnGoods->Visible = mV[4];

    mmnRefbook->Enabled = mE[0];
    mmnService->Enabled = mE[1];
    mmnReport->Enabled = mE[2];
    mmnAdmin->Enabled = mE[3];
    mmnGoods->Enabled = mE[4];
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ReserveFitGroupExport1Click(TObject *Sender)
{
    const char *pFields0[] = { "RowID", "FitGroupDay", "ServiceID", "PersonID", "BegDate", "EndDate", "FitGroupCount", "Closed" };
    const char *pFields1[] = { "RowID", "ClientID", "BegDate", "EndDate", "PersonID", "ServiceID", "Status", "FitGroupID", "QUAN", "ParentID" };

    int cnt = sizeof(pFields0) / sizeof(char *);

    TableExport("fitgroup.sql","FitGroup",pFields0,"@@@@@@@@",cnt,"from FitGroup");

    cnt = sizeof(pFields1) / sizeof(char *);
    TableExport("reserve.sql","Reserve",pFields1,"@@@@@@@@@@",cnt,"from Reserve");
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::tiSyncTimer(TObject *Sender)
{
    // ��������� ����� Sync

    if(pSync->Suspended)
    {
        pSync->Resume();
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
    if(pSync)
    {
        tiSync->Enabled = false;

        if(!pSync->Suspended)
        {
            laSyncEnd->Visible = true;
            laSyncEnd->Repaint();
        }

        while(!pSync->Suspended)
            ::Sleep(1000);

        pSync->Terminate();
    }
    
    SQL_BeginTransaction();
    SQL_exe(DBName,("update Sessions set EndDate="+(AnsiString)((double)Now())+" where UserID="+(AnsiString)UserID+" and BegDate="+(AnsiString)SessionKey).c_str());
    SQL_CommitTransaction();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Income1Click(TObject *Sender)
{
    // TotalSum � ������� ����
    SQL_BeginTransaction();

    SQL_exe(NULL,"update Income a set a.PRICE = (select b.PRICE from Goods b where a.GOODID=b.ROWID)");
    SQL_exe(NULL,"update Income a set a.TOTAL = (select b.PRICE*(a.INCOMECOUNT+cast(a.PART as double precision)/1000.0) from Goods b where a.GOODID=b.ROWID)");

    SQL_CommitTransaction();

    Application->MessageBox("������!","",MB_OK);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormDestroy(TObject *Sender)
{
    SQL_BeginTransaction();
    SQL_exe(DBName,("update Sessions set EndDate="+(AnsiString)((double)Now())+" where UserID="+(AnsiString)UserID+" and BegDate="+(AnsiString)SessionKey).c_str());
    SQL_CommitTransaction();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::mmnServiceGoodsClick(TObject *Sender)
{
    ServiceGoodsForm = new TServiceGoodsForm(this);
    ServiceGoodsForm->ShowModal();
    delete ServiceGoodsForm;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::N4Click(TObject *Sender)
{
    bool Period = true;

    if(AdminMode || UserGrants[12] != '0')
    {
        SQL_exefun(DBName,"select SettingsVal from Settings where SettingsKey='repVisitsSPAPeriod'",&retString);
        Period = !(atoi(retString.c_str()) == 0);
    }

    TDateTime bdt;
    TDateTime edt;

    if(Period)
    {
        DateIntervalForm = new TDateIntervalForm(this);

        DTI_BegDate = Now();
        DTI_EndDate = DTI_BegDate;
        FormResult = 0;
        DateIntervalForm->ShowModal();
        delete DateIntervalForm;

        if(FormResult != 1) return;
        bdt = DTI_BegDate;
        edt = DTI_EndDate + 1;
    }
    else
    {
         bdt = Now();
         edt = bdt + 1;
    }

    unsigned Start = (int)bdt;
    unsigned Finish = (int)edt;

    AnsiString *psPID;

    AnsiString sql = "from Visits_SPA inner join Services on ServiceID=Services.RowID where Visits_SPADate>=";
    sql += Start;
    sql += " and Visits_SPADate<";
    sql += Finish;
    sql += (" and Tag like '~����~%'");

    unsigned cnt_visits = SQL_fldCollect(DBName,"PersonID",sql.c_str(),&psPID,false,false,true);

    if(cnt_visits == 0)
    {
        Application->MessageBox("��������!\n��� ������ ��� ������.","������ �����",MB_OK);
        return;
    }

    pbProgress->Width = ClientWidth;
    pbProgress->Height = ClientHeight;
    pbProgress->Left = 0;
    pbProgress->Top = 0;
    pbProgress->Step = 1;
    pbProgress->Min = 0;
    pbProgress->Position = 0;

    bool mV[5], mE[5];
    mV[0] = mmnRefbook->Visible;
    mV[1] = mmnService->Visible;
    mV[2] = mmnReport->Visible;
    mV[3] = mmnAdmin->Visible;
    mV[4] = mmnGoods->Visible;

    mE[0] = mmnRefbook->Enabled;
    mE[1] = mmnService->Enabled;
    mE[2] = mmnReport->Enabled;
    mE[3] = mmnAdmin->Enabled;
    mE[4] = mmnGoods->Enabled;

    mmnRefbook->Enabled = false;
    mmnService->Enabled = false;
    mmnReport->Enabled = false;
    mmnAdmin->Enabled = false;
    mmnGoods->Enabled = false;

    unsigned i;
    bool fZero = false;

    sql = "from Personal where RowID in (";
    for(i = 0; i < cnt_visits; i++)
    {
        if(_atoi64(psPID[i].c_str()) == 0)
            fZero = true;

        sql += (AnsiString(psPID[i]) + ",");
    }

    sql.SetLength(sql.Length() - 1);
    sql += ") order by Name,CDate";

    delete [] psPID;

    __int64 *pPIDs;

    unsigned cnt_persons = SQL_fldKeyCollect(DBName,"Name",sql.c_str(),&pPIDs,&psPID,true,fZero);

    if(fZero)
    {
        pPIDs[0] = 0;
        psPID[0] = "��� �����������";
    }

    pbProgress->Max = cnt_persons - 1;
    pbProgress->Visible = true;

    TList *pList = new TList;
    AnsiString *pLines;
    AnsiString sRow[5];
    AnsiString *psVID;
    char *Tags[] = { "����" };

    repVisitsSPAForm = new TrepVisitsSPAForm(this);
    if(Period)
        repVisitsSPAForm->QRHeader->Caption = "����� �� ������ ������� � " + bdt.DateString() + " �� " + (edt-1).DateString();
    else
        repVisitsSPAForm->QRHeader->Caption = "����� �� ������ ������� �� " + (edt-1).DateString();
    repVisitsSPAForm->QRCreated->Caption = repCreated(Start < (Finish - 1));

    repVisitsSPAForm->pPrint = pList;

    pList->Add(NULL);
    repVisitsSPAForm->QRlines->Items->Add("E");

    for(unsigned cnt_p = 0; cnt_p < cnt_persons; cnt_p++)
    {
        for(unsigned tags_cnt = 0; tags_cnt < 1; tags_cnt++)
        {
            sql = "from Visits_SPA where PersonID=";
            sql += pPIDs[cnt_p];
            sql += " and Visits_SPADate>=";
            sql += Start;
            sql += " and Visits_SPADate<";
            sql += Finish;
            sql += (AnsiString(" and ServiceID in (select RowID from Services where Tag like '~") + Tags[tags_cnt] + "~%') order by CDate");

            cnt_visits = SQL_fldCollect(DBName,"RowID",sql.c_str(),&psVID);

            if(cnt_visits)
            {
                pLines = new AnsiString[4];
                pLines[0] = psPID[cnt_p] + " / " + Tags[tags_cnt];
                pList->Add(pLines);
                repVisitsSPAForm->QRlines->Items->Add("H");
            }
            else
                continue;

            for(unsigned cnt_v = 0; cnt_v < cnt_visits; cnt_v++)
            {
                pLines = new AnsiString[4];

                SQL_exefunrow(DBName,("select ServiceID,AbonementID,ClientID,Price,PersonPrice from Visits_SPA where RowID="+AnsiString(_atoi64(psVID[cnt_v].c_str()))).c_str(),5,sRow);
                SQL_exefun(DBName,("select '['||b.Name||']'||a.Name from Services a left outer join Services b on a.ParentID=b.RowID where a.RowID="+AnsiString(_atoi64(sRow[0].c_str()))).c_str(),&retString);

                pLines[0] = retString;

                if(!_atoi64(sRow[1].c_str()))
                    SQL_exefun(DBName,("select FName||' '||SName||' '||TName from Clients where RowID="+AnsiString(_atoi64(sRow[2].c_str()))).c_str(),&retString);
                else
                    SQL_exefun(DBName,("select FName||' '||SName||' '||TName from Clients where RowID=(select ClientID from Abonements_SPA where RowID="+AnsiString(_atoi64(sRow[1].c_str()))+")").c_str(),&retString);

                pLines[1] = retString;

                double price = atof(sRow[3].c_str());
                double pprice = atof(sRow[4].c_str());

                pLines[2] = FormatFloat(MoneyFormat,pprice) + " / " + FormatFloat(MoneyFormat,price-pprice);

                repVisitsSPAForm->QRlines->Items->Add("L");

                pList->Add(pLines);

            }

            pLines = new AnsiString[4];
            pLines[0] = "�����:";
            pList->Add(pLines);
            repVisitsSPAForm->QRlines->Items->Add("I");
            pList->Add(NULL);
            repVisitsSPAForm->QRlines->Items->Add("E");

            delete [] psVID;
        }

        pbProgress->StepIt();
        Application->ProcessMessages();
    }

    delete [] psPID;
    delete [] pPIDs;

    pbProgress->Visible = false;
    repVisitsSPAForm->QuickRep1->Preview();

    AnsiString *pS;

    for(int i = 0; i < pList->Count; i++)
        if((pS = (AnsiString *)pList->Items[i]) != NULL) delete [] pS;

    delete pList;
    delete repVisitsSPAForm;

    mmnRefbook->Visible = mV[0];
    mmnService->Visible = mV[1];
    mmnReport->Visible = mV[2];
    mmnAdmin->Visible = mV[3];
    mmnGoods->Visible = mV[4];

    mmnRefbook->Enabled = mE[0];
    mmnService->Enabled = mE[1];
    mmnReport->Enabled = mE[2];
    mmnAdmin->Enabled = mE[3];
    mmnGoods->Enabled = mE[4];
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::mmnRepSellsClick(TObject *Sender)
{
    bool Period = true;

    if(AdminMode || UserGrants[12] != '0')
    {
        SQL_exefun(DBName,"select SettingsVal from Settings where SettingsKey='repSellsPeriod'",&retString);
        Period = !(atoi(retString.c_str()) == 0);
    }

    TDateTime bdt;
    TDateTime edt;

    if(Period)
    {
        DateIntervalForm = new TDateIntervalForm(this);

        DTI_BegDate = Now();
        DTI_EndDate = DTI_BegDate;
        FormResult = 0;
        DateIntervalForm->ShowModal();
        delete DateIntervalForm;

        if(FormResult != 1) return;
        bdt = DTI_BegDate;
        edt = DTI_EndDate + 1;
    }
    else
    {
         bdt = Now();
         edt = bdt + 1;
    }

    unsigned Start = (int)bdt;
    unsigned Finish = (int)edt;

    //AnsiString sql = "select count(distinct RowID) from Goods where RowID in (";
    //sql += "select GoodID from BillItems inner join Bills on BillID=Bills.RowID where Op=4 and CDate>=";
    //sql += Start;
    //sql += " and CDate<";
    //sql += Finish;
    //sql += ") or RowID in (";
    //sql += "select GoodID from Income inner join Docs on DocID=Docs.RowID where Closed!=0 and EDate>=";
    //sql += Start;
    //sql += " and EDate<";
    //sql += Finish;
    //sql += ")";

    AnsiString sql = "select count(*) from Goods where ForSale=1";

    SQL_exefun(DBName,sql.c_str(),&retString);
    unsigned cnt = atoi(retString.c_str());

    //if(!cnt)
    //{
    //    Application->MessageBox("????????!\n??? ?????? ??? ??????.","?????? ?????",MB_OK);
    //    return;
    //}

    pbProgress->Width = ClientWidth;
    pbProgress->Height = ClientHeight;
    pbProgress->Left = 0;
    pbProgress->Top = 0;
    pbProgress->Step = 1;
    pbProgress->Min = 0;
    pbProgress->Position = 0;
    if(cnt)
        pbProgress->Max = cnt - 1;
    else
        pbProgress->Max = 0;
    pbProgress->Visible = true;

    bool mV[5], mE[5];
    mV[0] = mmnRefbook->Visible;
    mV[1] = mmnService->Visible;
    mV[2] = mmnReport->Visible;
    mV[3] = mmnAdmin->Visible;
    mV[4] = mmnGoods->Visible;

    mE[0] = mmnRefbook->Enabled;
    mE[1] = mmnService->Enabled;
    mE[2] = mmnReport->Enabled;
    mE[3] = mmnAdmin->Enabled;
    mE[4] = mmnGoods->Enabled;

    mmnRefbook->Enabled = false;
    mmnService->Enabled = false;
    mmnReport->Enabled = false;
    mmnAdmin->Enabled = false;
    mmnGoods->Enabled = false;

    char *pSections[] = { "���", "���������", "������������� ������" };
    TList *pList = new TList;
    AnsiString *pLines;

    repSellsForm = new TrepSellsForm(this);

    double BegBalanse;
    double FromBalanse;
    double ToBalanse;
    double EndBalanse;

    double BegBalansePrice;
    double FromBalansePrice;
    double ToBalansePrice;
    double EndBalansePrice;

    double BegBalanseSum;
    double FromBalanseSum;
    double ToBalanseSum;
    double EndBalanseSum;

    double BegBalanseSumPrice;
    double FromBalanseSumPrice;
    double ToBalanseSumPrice;
    double EndBalanseSumPrice;

    double BegBalanseTotal = 0.0;
    double FromBalanseTotal = 0.0;
    double ToBalanseTotal = 0.0;
    double EndBalanseTotal = 0.0;

    double BegBalanseTotalPrice = 0.0;
    double FromBalanseTotalPrice = 0.0;
    double ToBalanseTotalPrice = 0.0;
    double EndBalanseTotalPrice = 0.0;

    double price;

    for(unsigned i = 0; i < 3; i++)
    {
        //sql = "select count(distinct RowID) from (";
        //sql += "select RowID,Section from Goods where RowID in (";
        //sql += "select GoodID from BillItems inner join Bills on BillID=Bills.RowID where Op=4 and CDate>=";
        //sql += Start;
        //sql += " and CDate<";
        //sql += Finish;
        //sql += ") or RowID in (";
        //sql += "select GoodID from Income inner join Docs on DocID=Docs.RowID where Closed!=0 and EDate>=";
        //sql += Start;
        //sql += " and EDate<";
        //sql += Finish;
        //sql += ")) where Section=";
        //sql += i;

        sql = "select count(*) from Goods where ForSale=1 and Section=";
        sql += i;

        SQL_exefun(DBName,sql.c_str(),&retString);
        cnt = atoi(retString.c_str());

        if(!cnt) continue;

        //sql = "select distinct RowID,Name,Price from (";
        //sql += "select RowID,Name,Price,Section from Goods where RowID in (";
        //sql += "select GoodID from BillItems inner join Bills on BillID=Bills.RowID where Op=4 and CDate>=";
        //sql += Start;
        //sql += " and CDate<";
        //sql += Finish;
        //sql += ") or RowID in (";
        //sql += "select GoodID from Income inner join Docs on DocID=Docs.RowID where Closed!=0 and EDate>=";
        //sql += Start;
        //sql += " and EDate<";
        //sql += Finish;
        //sql += ")) where Section=";
        //sql += i;
        //sql += " order by Name";

        sql = "select RowID,Name,Price from Goods where ForSale=1 and Section=";
        sql += i;
        sql += " order by Name";

        repClientsIDs = new __int64[cnt];
        repClientsFNames = new AnsiString[cnt]; // Good
        repClientsSNames = new AnsiString[cnt]; // Price

        repClientsCounter = 0;

        SQL_exe(DBName,sql.c_str(),goodsfrombills_select);

        pLines = new AnsiString[6];
        pLines[0] = pSections[i];
        pList->Add(pLines);
        repSellsForm->QRlines->Items->Add("H");

        BegBalanseSum = 0;
        FromBalanseSum = 0;
        ToBalanseSum = 0;
        EndBalanseSum = 0;

        BegBalanseSumPrice = 0.0;
        FromBalanseSumPrice = 0.0;
        ToBalanseSumPrice = 0.0;
        EndBalanseSumPrice = 0.0;

        AnsiString sPart, sRet, *pPrices;
        double x;


        for(repClientsCounter = 0; repClientsCounter < cnt; repClientsCounter++)
        {
            sql = "from (select distinct a.Price as P from BillItems a inner join Bills b on BillID=b.RowID where Op=4 and GoodID=";
            sql += repClientsIDs[repClientsCounter];
            sql += " and CDate>=";
            sql += Start;
            sql += " and CDate<";
            sql += Finish;
            sql += " union ";
            sql += "select distinct c.Price from Income c inner join Docs d on DocID=d.RowID where GoodID=";
            sql += repClientsIDs[repClientsCounter];
            sql += " and CDate>=";
            sql += Start;
            sql += " and CDate<";
            sql += Finish;
            sql += ")";

            unsigned cnt = SQL_fldCollect(NULL,"P",sql.c_str(),&pPrices);


            price = atof(repClientsSNames[repClientsCounter].c_str());
            ///////////////////////////////////////////////////////////////


            //SQL_exefun2(DBName,("select sum(IncomeCount),sum(Part) from Income inner join Docs on DocID=Docs.RowID where Closed!=0 and EDate<"+AnsiString(Start)+" and GoodID="+AnsiString(repClientsIDs[repClientsCounter])).c_str(),&retString,&sPart);
            //BegBalanse = (atof(sPart.c_str()) / 1000) + atof(retString.c_str());
            //SQL_exefun(DBName,("select sum(BillItemsCount) from BillItems inner join Bills on BillID=Bills.RowID where Op=4 and CDate<"+AnsiString(Start)+" and GoodID="+AnsiString(repClientsIDs[repClientsCounter])).c_str(),&retString);
            //BegBalanse -= atof(retString.c_str());
            //BegBalansePrice = price * BegBalanse;

            ///////////////////////////////////////////////////////////////


            sql = "select sum(IncomeCount),sum(Part),sum(Total) from Income inner join Docs on DocID=Docs.RowID where Closed!=0 and GoodID=";
            sql += repClientsIDs[repClientsCounter];
            sql += " and EDate>=";
            sql += Start;
            sql += " and EDate<";
            sql += Finish;

            SQL_exefun3(DBName,sql.c_str(),&retString,&sPart,&sRet);
            ToBalanse = (atof(sPart.c_str()) / 1000) + atof(retString.c_str());
            //ToBalansePrice = price * ToBalanse;
            ToBalansePrice = atof(sRet.c_str());

            ///////////////////////////////////////////////////////////////


            sql = "select sum(BillItemsCount),sum(a.Total) from BillItems a inner join Bills b on BillID=b.RowID where Op=4 and GoodID=";
            sql += repClientsIDs[repClientsCounter];
            sql += " and CDate>=";
            sql += Start;
            sql += " and CDate<";
            sql += Finish;

            SQL_exefun2(DBName,sql.c_str(),&retString,&sPart);
            FromBalanse = atof(retString.c_str());
            //FromBalansePrice = price * FromBalanse;
            FromBalansePrice = atof(sPart.c_str()) * FromBalanse;

            ///////////////////////////////////////////////////////////////


            SQL_exefun2(DBName,("select sum(StockCount),sum(Part) from Stock where GoodID="+AnsiString(repClientsIDs[repClientsCounter])).c_str(),&retString,&sPart);

            EndBalanse = (atof(sPart.c_str()) / 1000.0) + atof(retString.c_str());
            EndBalansePrice = price * EndBalanse;

            BegBalanse = EndBalanse + FromBalanse - ToBalanse;
            BegBalansePrice = EndBalansePrice + FromBalansePrice - ToBalansePrice;

            pLines = new AnsiString[6];
            pLines[0] = repClientsFNames[repClientsCounter];
            pLines[1] = repClientsSNames[repClientsCounter];


            if(modf(BegBalanse,&x) == 0.0)
                pLines[2] = (int)BegBalanse;
            else
                pLines[2] = FormatFloat(CountFormat,BegBalanse);
            pLines[2] += (" / " + FormatFloat(MoneyFormat,BegBalansePrice));

            if(modf(ToBalanse,&x) == 0.0)
                pLines[3] = (int)ToBalanse;
            else
                pLines[3] = FormatFloat(CountFormat,ToBalanse);
            pLines[3] += (" / " + FormatFloat(MoneyFormat,ToBalansePrice));

            if(modf(FromBalanse,&x) == 0.0)
                pLines[4] = (int)FromBalanse;
            else
                pLines[4] = FormatFloat(CountFormat,FromBalanse);
            pLines[4] += (" / " + FormatFloat(MoneyFormat,FromBalansePrice));

            if(modf(EndBalanse,&x) == 0.0)
                pLines[5] = (int)EndBalanse;
            else
                pLines[5] = FormatFloat(CountFormat,EndBalanse);
            pLines[5] += (" / " + FormatFloat(MoneyFormat,EndBalansePrice));

            pList->Add(pLines);
            repSellsForm->QRlines->Items->Add("L");

            BegBalanseSum += BegBalanse;
            FromBalanseSum += FromBalanse;
            ToBalanseSum += ToBalanse;
            EndBalanseSum += EndBalanse;

            BegBalanseSumPrice += BegBalansePrice;
            FromBalanseSumPrice += FromBalansePrice;
            ToBalanseSumPrice += ToBalansePrice;
            EndBalanseSumPrice += EndBalansePrice;

            pbProgress->StepIt();
            Application->ProcessMessages();
        }

        BegBalanseTotal += BegBalanseSum;
        FromBalanseTotal += FromBalanseSum;
        ToBalanseTotal += ToBalanseSum;
        EndBalanseTotal += EndBalanseSum;

        BegBalanseTotalPrice += BegBalanseSumPrice;
        FromBalanseTotalPrice += FromBalanseSumPrice;
        ToBalanseTotalPrice += ToBalanseSumPrice;
        EndBalanseTotalPrice += EndBalanseSumPrice;

        pLines = new AnsiString[6];
        //pLines[0] = repClientsFNames[repClientsCounter];
        //pLines[1] = repClientsSNames[repClientsCounter];
        pLines[2] = FormatFloat(MoneyFormat,BegBalanseSumPrice);
        //AnsiString(BegBalanseSum) + " / " + FormatFloat(MoneyFormat,BegBalanseSumPrice);
        pLines[3] = FormatFloat(MoneyFormat,ToBalanseSumPrice);
        //AnsiString(ToBalanseSum) + " / " + FormatFloat(MoneyFormat,ToBalanseSumPrice);
        pLines[4] = FormatFloat(MoneyFormat,FromBalanseSumPrice);
        //AnsiString(FromBalanseSum) + " / " + FormatFloat(MoneyFormat,FromBalanseSumPrice);
        pLines[5] = FormatFloat(MoneyFormat,EndBalanseSumPrice);
        //AnsiString(EndBalanseSum) + " / " + FormatFloat(MoneyFormat,EndBalanseSumPrice);
        pList->Add(pLines);
        repSellsForm->QRlines->Items->Add("I");
        pList->Add(NULL);
        repSellsForm->QRlines->Items->Add("E");

    }

    pList->Add(NULL);
    repSellsForm->QRlines->Items->Add("E");


    pLines = new AnsiString[6];

    //pLines[0] = repClientsFNames[repClientsCounter];
    //pLines[1] = repClientsSNames[repClientsCounter];
    pLines[2] = FormatFloat(MoneyFormat,BegBalanseTotalPrice);
    //AnsiString(BegBalanseTotal) + " / " + FormatFloat(MoneyFormat,BegBalanseTotalPrice);
    pLines[3] = FormatFloat(MoneyFormat,ToBalanseTotalPrice);
    //AnsiString(ToBalanseTotal) + " / " + FormatFloat(MoneyFormat,ToBalanseTotalPrice);
    pLines[4] = FormatFloat(MoneyFormat,FromBalanseTotalPrice);
    //AnsiString(FromBalanseTotal) + " / " + FormatFloat(MoneyFormat,FromBalanseTotalPrice);
    pLines[5] = FormatFloat(MoneyFormat,EndBalanseTotalPrice);
    //AnsiString(EndBalanseTotal) + " / " + FormatFloat(MoneyFormat,EndBalanseTotalPrice);
    pList->Add(pLines);
    repSellsForm->QRlines->Items->Add("A");

    repSellsForm->pPrint = pList;

    if(Period)
        repSellsForm->QRHeader->Caption = "����� �� �������� � " + bdt.DateString() + " �� " + (edt-1).DateString();
    else
        repSellsForm->QRHeader->Caption = "����� �� �������� �� " + bdt.DateString();
    repSellsForm->QRCreated->Caption = repCreated(Start < (Finish - 1));

    pbProgress->Visible = false;
    repSellsForm->QuickRep1->Preview();

    delete repSellsForm;

    AnsiString *pS;

    for(int i = 0; i < pList->Count; i++)
        if((pS = (AnsiString *)pList->Items[i]) != NULL) delete [] pS;

    delete pList;

    PDEL(repClientsIDs);
    PDEL(repClientsFNames);
    PDEL(repClientsSNames);

    mmnRefbook->Visible = mV[0];
    mmnService->Visible = mV[1];
    mmnReport->Visible = mV[2];
    mmnAdmin->Visible = mV[3];
    mmnGoods->Visible = mV[4];

    mmnRefbook->Enabled = mE[0];
    mmnService->Enabled = mE[1];
    mmnReport->Enabled = mE[2];
    mmnAdmin->Enabled = mE[3];
    mmnGoods->Enabled = mE[4];
}
//---------------------------------------------------------------------------

