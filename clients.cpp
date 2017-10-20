//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "clients.h"
#include "i_clients.h"
#include "accounts.h"
#include <Clipbrd.hpp>
#include <vfw.h>
#include <math.h>

#include "kassa.h"
#include "visits.h"
#include "i_visits.h"
#include "visitsbath.h"
#include "dt_interval.h"
#include "balanse.h"
#include "bath.h"
#include "barber.h"
#include "nail.h"
#include "cosmetic.h"
#include "rescaltime.h"
#include "gservlist.h"
#include "bills.h"
#include "rescontrol.h"

#include "kkm.h"
#include "kkm_outcome.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TClientsForm *ClientsForm;

extern const char *DBName;
extern bool AdminMode;
extern unsigned char UserGrants[FORMS_COUNT];

extern TDateTime DTI_BegDate, DTI_EndDate;

extern AnsiString ImgPath;
static TDateTime CDate, EDate;
static __int64 CUID, EUID;
__int64 ClientID = 0;
__int64 BillsID = 0;
__int64 AbonementID = 0;
__int64 AbonementSPAID = 0;
__int64 AbonementBathID = 0;
double UserBalanse = 0.0;
double UserDiscount = 0.0;
double UserDiscountSPA = 0.0;
//double UserDiscountBath = 0.0;

static __int64 *IDs = NULL;
static unsigned Counter = 0;

static __int64 *IDsAbonements = NULL;
static unsigned CounterAbonements = 0;

static __int64 *IDsAbonementsSPA = NULL;
static unsigned CounterAbonementsSPA = 0;

static __int64 *IDsAbonementsBath = NULL;
static unsigned CounterAbonementsBath = 0;

static unsigned UpdatedRow = 0;
extern int FormResult;

static AnsiString *pUsers = NULL;
static __int64 *pUserIDs = NULL;
static unsigned UsersCounter = 0;

static AnsiString retString;

HWND hWndC;


extern const char *_DayNames[];
extern const char *MoneyFormat;
extern __int64 UserID;

extern int KassaMode;
extern int iVisitMode;

extern int SearchDelay;

extern __int64 KassaBillID;
//---------------------------------------------------------------------------
double __fastcall GroupAnalyze(AnsiString group,int cnt)
{
    typedef struct
    {
        int Cnt1;
        int Cnt2;
        bool fixed;
        double price;
    } term;

    char *p, *pGroup = group.c_str() + 1;

    p = strtok(pGroup,"~");
    if(!p) return 0.0;

    TList *pRules = new TList;
    pRules->Add(p);

    while(p)
    {
        p = strtok(NULL,"~");
        if(p)
            pRules->Add(p);
    }

    int pos;
    AnsiString s;
    term *pTerm = new term[pRules->Count];

    for(int i = 0; i < pRules->Count; i++)
    {
        s = (char *)pRules->Items[i];


        pTerm[i].fixed = true;
        pTerm[i].Cnt1 = atoi(s.c_str());
        pos = s.Pos("-");
        if(!pos)
        {
            pTerm[i].Cnt1 = -1;
            continue;
        }
        pTerm[i].Cnt2 = atoi(s.c_str()+pos);
        pos = s.Pos("(");
        if(!pos)
        {
            pTerm[i].Cnt1 = -1;
            continue;
        }
        if(s[pos+1] == '+' || s[pos+1] == '-')
            pTerm[i].fixed = false;
        pTerm[i].price = atof(s.c_str()+pos);

    }

    // ������� �������, �������

    double price = 0.0;
    int fixcnt = 0;

    for(int i = 0; i < pRules->Count; i++)
    {
        if(pTerm[i].Cnt1 < 0) continue;

        if(pTerm[i].fixed)
        {
            price = pTerm[i].price;
            fixcnt = pTerm[i].Cnt2;
        }

        if(pTerm[i].Cnt2 == 0 || (cnt >= pTerm[i].Cnt1 && cnt <= pTerm[i].Cnt2))
        {
            if(cnt >= pTerm[i].Cnt1)
            {
                if(pTerm[i].fixed)
                {
                    price = pTerm[i].price;
                    break;
                }
                else
                {
                    // ������
                    price += ((double)(cnt - fixcnt) * pTerm[i].price);
                    break;
                }
            }
        }
    }

    delete pRules;
    delete [] pTerm;

    return price;
}
//---------------------------------------------------------------------------
bool __fastcall GetSPAServicePrice(double *pPrice,double *pPersonPrice,__int64 SID,unsigned cnt,unsigned minutes,bool fdiscount=true)
{
    AnsiString sql = "select Price,PersonPrice,Timed,IsGroup,GroupPrice,SUMP from Services left join "
                         "(select ServiceID as SID,sum(Price) as SUMP from ServiceGoods group by ServiceID) on Services.RowID=SID where Services.RowID=";
    sql += SID;

    AnsiString sRet[6];
    SQL_exefunrow(NULL,sql.c_str(),6,sRet);

    int timed = atoi(sRet[2].c_str());

    double zprice, pprice;
    bool isgroup = false;

    if(atoi(sRet[3].c_str()) > 0)
    {
        isgroup = true;
        zprice = GroupAnalyze(sRet[4],cnt);
        pprice = zprice - (atof(sRet[5].c_str()) * cnt);
    }
    else
    {
        zprice = atof(sRet[0].c_str());
        pprice = atof(sRet[1].c_str());
    }

    double discount = (fdiscount)? UserDiscountSPA : 0;

    if(timed)
    {
        *pPrice = minutes;
        *pPrice /= timed;

        *pPersonPrice = *pPrice;
        *pPrice = ((*pPrice) * zprice * (100.0 - discount)) / 100.0;

        *pPersonPrice = ((*pPersonPrice) * pprice * (100.0 - discount)) / 100.0;
    }
    else
    {
        *pPrice = (zprice * (100.0 - discount)) / 100.0;
        *pPersonPrice = (pprice * (100.0 - discount)) / 100.0;
    }

    return isgroup;
}
//---------------------------------------------------------------------------

//***************************************************************************
//******************************* CALLBACKS *********************************
//***************************************************************************
__int64 _PCID;
double _PBCDate;
//---------------------------------------------------------------------------
static int analyze_period(void *NotUsed, int argc, char **argv, char **azColName)
{
    //b.RowID,a.CDate
    //DynamicArray<__int64> AbonementsUpdIDs;
    //unsigned AbonementsUpdCounter;

    __int64 ID = _atoi64(argv[0]);

    if(ID == _PCID)
    {
        // � ���� � �������?
        if(ClientsForm->AbonementsUpdCounter && ID == ClientsForm->AbonementsUpdIDs[ClientsForm->AbonementsUpdCounter-1]) return 0;

        double dt = atof(argv[1]);

        if(dt-_PBCDate >= 730)
        {
            // ���� � ������


            if((unsigned)ClientsForm->AbonementsUpdIDs.Length == ClientsForm->AbonementsUpdCounter)
                ClientsForm->AbonementsUpdIDs.Length += 10;

            ClientsForm->AbonementsUpdIDs[ClientsForm->AbonementsUpdCounter++] = ID;

        }

        _PBCDate = dt;

        return 0;
    }

    //

    _PCID = _atoi64(argv[0]);
    _PBCDate = atof(argv[1]);

    return 0;
}
//---------------------------------------------------------------------------
static int bath_timing_fill(void *NotUsed, int argc, char **argv, char **azColName)
{
//select BegDate,EndDate,Services.Name,Personal.Name,Tag,Reserve.RowID

    TDateTime bd = atof(argv[0]);
    TDateTime ed = atof(argv[1]);
    if(bd >= ed) return 0;

    unsigned short hour, min, sec, msec;

    bd.DecodeTime(&hour,&min,&sec,&msec);

    if(hour < 8 || hour > 22) return 0;

    int pos;// = (hour - 8) * 2 + 1;
    // ����� ������ � �����

    for(pos = 1; pos < ClientsForm->sgBathTiming->RowCount; pos++)
        if(hour == atoi(ClientsForm->sgBathTiming->Cells[0][pos].c_str())) break;

    if(pos >= ClientsForm->sgBathTiming->RowCount) return 0;

    // ������ ���� ��������� ������
    if(ClientsForm->sgBathTiming->Cells[1][pos].Length() == 0)
    {
        // ������ �����

    }
    else if(ClientsForm->sgBathTiming->Cells[1][++pos].Length() == 0)
    {

    }
    else
    {
        // �������� ��������� ���� �������� ������

        // ���� ������� ����� �������� � ���� (��� ���� ���)
        //unsigned i;
        for(pos = pos + 1; pos < ClientsForm->sgBathTiming->RowCount; pos++)
            if(ClientsForm->sgBathTiming->Cells[1][pos].Length() == 0)
                break;

        // i - pos + 1 - ���-�� ������� � ����

        ClientsForm->sgBathTiming->RowCount++;

        // �������� ����, �������� � �����
        for(int j = ClientsForm->sgBathTiming->RowCount - 2; j >= pos; j--)
            ClientsForm->sgBathTiming->Rows[j+1] = ClientsForm->sgBathTiming->Rows[j];

        // ����� ������ � pos

        ClientsForm->sgBathTiming->Cells[0][pos] = "";


    }

    ClientsForm->sgBathTiming->Cells[1][pos] = bd.FormatString("hh:nn");
    ClientsForm->sgBathTiming->Cells[2][pos] = ed.FormatString("hh:nn");

    AnsiString s1, s = argv[4];
    s.SetLength(s.Length()-1);
    char *p = strrchr(s.c_str(),'~');
    if(p)
    {
        s1 = "[";
        s1 += (p + 1);
        s1 += "]";

    }

    //ClientsForm->sgReserve->Cells[3][ClientsForm->ReserveCounter] = s1 + argv[2];

    ClientsForm->sgBathTiming->Cells[3][pos] = s1 + argv[2];
    ClientsForm->sgBathTiming->Cells[4][pos] = argv[3];

    ClientsForm->sgBathTiming->Rows[pos]->Objects[0] = (TObject *)_atoi64(argv[5]);
    ClientsForm->sgBathTiming->Rows[pos]->Objects[1] = (TObject *)_atoi64(argv[6]);

    return 0;
}
//---------------------------------------------------------------------------
static int mg_timing_fill(void *NotUsed, int argc, char **argv, char **azColName)
{
//select BegDate,EndDate,Services.Name,Personal.Name,Tag,Reserve.RowID

    TDateTime bd = atof(argv[0]);
    TDateTime ed = atof(argv[1]);
    if(bd >= ed) return 0;

    unsigned short hour, min, sec, msec;

    bd.DecodeTime(&hour,&min,&sec,&msec);

    if(hour < 8 || hour > 22) return 0;

    int pos;// = (hour - 8) * 2 + 1;
    // ����� ������ � �����

    for(pos = 1; pos < ClientsForm->sgMGTiming->RowCount; pos++)
        if(hour == atoi(ClientsForm->sgMGTiming->Cells[0][pos].c_str())) break;

    if(pos >= ClientsForm->sgMGTiming->RowCount) return 0;

    // ������ ���� ��������� ������
    if(ClientsForm->sgMGTiming->Cells[1][pos].Length() == 0)
    {
        // ������ �����

    }
    else if(ClientsForm->sgMGTiming->Cells[1][++pos].Length() == 0)
    {

    }
    else
    {
        // �������� ��������� ���� �������� ������

        // ���� ������� ����� �������� � ���� (��� ���� ���)
        //unsigned i;
        for(pos = pos + 1; pos < ClientsForm->sgMGTiming->RowCount; pos++)
            if(ClientsForm->sgMGTiming->Cells[1][pos].Length() == 0)
                break;

        // i - pos + 1 - ���-�� ������� � ����

        ClientsForm->sgMGTiming->RowCount++;

        // �������� ����, �������� � �����
        for(int j = ClientsForm->sgMGTiming->RowCount - 2; j >= pos; j--)
            ClientsForm->sgMGTiming->Rows[j+1] = ClientsForm->sgMGTiming->Rows[j];

        // ����� ������ � pos

        ClientsForm->sgMGTiming->Cells[0][pos] = "";


    }

    ClientsForm->sgMGTiming->Cells[1][pos] = bd.FormatString("hh:nn");
    ClientsForm->sgMGTiming->Cells[2][pos] = ed.FormatString("hh:nn");

    AnsiString s1, s = argv[4];
    s.SetLength(s.Length()-1);
    char *p = strrchr(s.c_str(),'~');
    if(p)
    {
        s1 = "[";
        s1 += (p + 1);
        s1 += "]";

    }

    //ClientsForm->sgReserve->Cells[3][ClientsForm->ReserveCounter] = s1 + argv[2];

    ClientsForm->sgMGTiming->Cells[3][pos] = s1 + argv[2];
    ClientsForm->sgMGTiming->Cells[4][pos] = argv[3];

    ClientsForm->sgMGTiming->Rows[pos]->Objects[0] = (TObject *)_atoi64(argv[5]);
    ClientsForm->sgMGTiming->Rows[pos]->Objects[1] = (TObject *)_atoi64(argv[6]);

    return 0;
}
//---------------------------------------------------------------------------
static int sk_timing_fill(void *NotUsed, int argc, char **argv, char **azColName)
{
//select BegDate,EndDate,Services.Name,Personal.Name,Tag,Reserve.RowID

    TDateTime bd = atof(argv[0]);
    TDateTime ed = atof(argv[1]);
    if(bd >= ed) return 0;

    unsigned short hour, min, sec, msec;

    bd.DecodeTime(&hour,&min,&sec,&msec);

    if(hour < 8 || hour > 22) return 0;

    int pos;// = (hour - 8) * 2 + 1;
    // ����� ������ � �����

    for(pos = 1; pos < ClientsForm->sgSKTiming->RowCount; pos++)
        if(hour == atoi(ClientsForm->sgSKTiming->Cells[0][pos].c_str())) break;

    if(pos >= ClientsForm->sgSKTiming->RowCount) return 0;

    // ������ ���� ��������� ������
    if(ClientsForm->sgSKTiming->Cells[1][pos].Length() == 0)
    {
        // ������ �����

    }
    else if(ClientsForm->sgSKTiming->Cells[1][++pos].Length() == 0)
    {

    }
    else
    {
        // �������� ��������� ���� �������� ������

        // ���� ������� ����� �������� � ���� (��� ���� ���)
        //unsigned i;
        for(pos = pos + 1; pos < ClientsForm->sgSKTiming->RowCount; pos++)
            if(ClientsForm->sgSKTiming->Cells[1][pos].Length() == 0)
                break;

        // i - pos + 1 - ���-�� ������� � ����

        ClientsForm->sgSKTiming->RowCount++;

        // �������� ����, �������� � �����
        for(int j = ClientsForm->sgSKTiming->RowCount - 2; j >= pos; j--)
            ClientsForm->sgSKTiming->Rows[j+1] = ClientsForm->sgSKTiming->Rows[j];

        // ����� ������ � pos

        ClientsForm->sgSKTiming->Cells[0][pos] = "";


    }

    ClientsForm->sgSKTiming->Cells[1][pos] = bd.FormatString("hh:nn");
    ClientsForm->sgSKTiming->Cells[2][pos] = ed.FormatString("hh:nn");

    AnsiString s1, s = argv[4];
    s.SetLength(s.Length()-1);
    char *p = strrchr(s.c_str(),'~');
    if(p)
    {
        s1 = "[";
        s1 += (p + 1);
        s1 += "]";

    }

    //ClientsForm->sgReserve->Cells[3][ClientsForm->ReserveCounter] = s1 + argv[2];

    ClientsForm->sgSKTiming->Cells[3][pos] = s1 + argv[2];
    ClientsForm->sgSKTiming->Cells[4][pos] = argv[3];

    ClientsForm->sgSKTiming->Rows[pos]->Objects[0] = (TObject *)_atoi64(argv[5]);
    ClientsForm->sgSKTiming->Rows[pos]->Objects[1] = (TObject *)_atoi64(argv[6]);

    return 0;
}
//---------------------------------------------------------------------------
static int fitshedule_fill(void *NotUsed,int argc,char **argv,char **azColName)
{
    __int64 ID = atoi(argv[0]);
    if(!ID) return 0;

    AnsiString sRet;


    if(ClientsForm->sgFitShedule->Rows[1]->Objects[0])
        ClientsForm->sgFitShedule->RowCount++;

    int pos = ClientsForm->sgFitShedule->RowCount - 1;

    ClientsForm->sgFitShedule->Rows[pos]->Objects[0] = (TObject *)ID;

    SQL_exefun(DBName,("select BegDate from FitGroup where RowID="+AnsiString(ID)).c_str(),&sRet);
    if(atof(sRet.c_str()) + (15.0 / 1440.0) < (double)Now())
    {
        ClientsForm->sgFitShedule->Cells[0][pos] = " ";
        //SQL_exefun(DBName,("select count(*) from Reserve where FitGroupID="+AnsiString(ID)).c_str(),&sRet);
    }
    else
    {
        SQL_exefun(DBName,("select count(*) from Reserve where ClientID="+AnsiString(ClientID)+" and FitGroupID="+AnsiString(ID)).c_str(),&sRet);
        ClientsForm->sgFitShedule->Cells[0][pos] = atoi(sRet.c_str())? " " : "";
    }

    //ClientsForm->sgShedule->Cells[0][pos] = "";
    ClientsForm->sgFitShedule->Cells[1][pos] = argv[1];
    ClientsForm->sgFitShedule->Cells[2][pos] = argv[2];
    ClientsForm->sgFitShedule->Cells[3][pos] = TDateTime(atof(argv[3])).FormatString("hh:nn");
    //ClientsForm->sgFitShedule->Cells[4][pos] = TDateTime(atof(argv[4])).FormatString("hh:nn");
    SQL_exefun(DBName,("select count(*) from Reserve where FitGroupID="+AnsiString(ID)).c_str(),&sRet);
    ClientsForm->sgFitShedule->Cells[4][pos] = sRet;
    ClientsForm->sgFitShedule->Cells[5][pos] = atoi(argv[5]);

    return 0;
}
//---------------------------------------------------------------------------
static int clients_fill(void *NotUsed,int argc,char **argv,char **azColName)
{
    __int64 ID = atoi(argv[0]);
    if(!ID) return 0;

    //AnsiString sCnt;


    if(ClientsForm->sgResClients->Rows[1]->Objects[0])
        ClientsForm->sgResClients->RowCount++;

    int pos = ClientsForm->sgResClients->RowCount - 1;

    ClientsForm->sgResClients->Rows[pos]->Objects[0] = (TObject *)ID;
    ClientsForm->sgResClients->Cells[1][pos] = argv[1];
    ClientsForm->sgResClients->Cells[2][pos] = argv[2];
    ClientsForm->sgResClients->Cells[3][pos] = argv[3];

    // Status: 1 - yellow, 2 - red?

    int status = atoi(argv[4]);

    ClientsForm->sgResClients->Cells[0][pos] = (!status)? "" : (status == 1)? "\t" : " ";

    return 0;
}
//---------------------------------------------------------------------------
static int reserve_fill(void *NotUsed, int argc, char **argv, char **azColName)
{
//Reserve.RowID,BegDate,Services.Name,Personal.Name,Status,Tag from Reserve,Services,Personal where "
//  ReserveIDs = NULL;
//    ReserveCounter = 0;
    __int64 ID = atoi(argv[0]);
    if(!ID) return 0;

    ClientsForm->ReserveIDs[ClientsForm->ReserveCounter++] = ID;

    if(ClientsForm->sgReserve->Cells[1][1].Length() > 0)
        ClientsForm->sgReserve->RowCount++;

    if(argv[1])
    {
        if(atoi(argv[4]) == 2)
            ClientsForm->sgReserve->Cells[0][ClientsForm->ReserveCounter] = " ";
        else if(atof(argv[1]) + (15.0 / 1440.0) < (double)Now()) 
            ClientsForm->sgReserve->Cells[0][ClientsForm->ReserveCounter] = "\t";
        else
            ClientsForm->sgReserve->Cells[0][ClientsForm->ReserveCounter] = "";
    }
    else
        ClientsForm->sgReserve->Cells[0][ClientsForm->ReserveCounter] = " ";

    ClientsForm->sgReserve->Cells[1][ClientsForm->ReserveCounter] = TDateTime(atof(argv[1])).DateString();
    ClientsForm->sgReserve->Cells[2][ClientsForm->ReserveCounter] = TDateTime(atof(argv[1])).FormatString("hh:nn");

    AnsiString s1, s = argv[5];
    s.SetLength(s.Length()-1);
    char *p = strrchr(s.c_str(),'~');
    if(p)
    {
        int num = ATOI(argv[6]);

        s1 = "[";
        s1 += (p + 1);

        if(strcmp(p + 1,"����") == 0)
        {
            if(num == 0)
                s1 = "[������";
            else if(num == 1)
                s1 = "[��������� �������";
            else if(num == 2)
                s1 = "[������";
            else
            {
                s1 += " �";
                s1 += num;
            }
        }

        s1 += "]";

    }

    ClientsForm->sgReserve->Cells[3][ClientsForm->ReserveCounter] = s1 + argv[2];
    ClientsForm->sgReserve->Cells[4][ClientsForm->ReserveCounter] = argv[3];

    return 0;
}
//---------------------------------------------------------------------------
static int abonements_update(void *NotUsed, int argc, char **argv, char **azColName)
{
    // RowID - argv[0]
    // Count - argv[1]
    // EndDate - argv[2]
    // Visits - argv[3]
    // FixSum - argv[4]

    if(!argv[0]) return 0;
    __int64 ID = _atoi64(argv[0]);

    if(!ID) return 0;

    double fixsum = (argv[4])? atof(argv[4]) : 0.0;
    int edt = (argv[2])? atoi(argv[2]) : 0;

    if(fixsum != 0.0)
    {
        if((int)edt >= (int)Now())
        {
            int cnt = (argv[1])? atoi(argv[1]) : 0;
            if(!cnt) return 0;

            int vst = (argv[3])? atoi(argv[3]) : 0;

            if(cnt - vst > 0) return 0;
        }

        if(ClientsForm->AbonementsUpdCounter >= (unsigned)ClientsForm->AbonementsUpdIDs.Length)
            ClientsForm->AbonementsUpdIDs.Length += 10;
        ClientsForm->AbonementsUpdIDs[ClientsForm->AbonementsUpdCounter++] = ID;
    }
    else
    {
        int cnt = (argv[1])? atoi(argv[1]) : 0;
        int vst = (argv[3])? atoi(argv[3]) : 0;

        if(cnt - vst <= 0 || (int)addmonths(edt,2) < (int)Now())
        {
            if(ClientsForm->AbonementsUpdCounter >= (unsigned)ClientsForm->AbonementsUpdIDs.Length)
                ClientsForm->AbonementsUpdIDs.Length += 10;
            ClientsForm->AbonementsUpdIDs[ClientsForm->AbonementsUpdCounter++] = ID;
        }
    }

    return 0;
}
//---------------------------------------------------------------------------
static int abonements_select(void *NotUsed, int argc, char **argv, char **azColName)
{
    if(IDsAbonements)
        IDsAbonements[CounterAbonements++] = _atoi64(argv[0]);
    else
        return 0;

    double fixsum = (argv[7])? atof(argv[7]) : 0.0;
    //LastAbFixSum = fixsum;

    // Name - argv[2]
    ClientsForm->sgAbonements->Cells[1][CounterAbonements] = argv[2];

    // BegDate - argv[3]
    TDateTime dt;
    if(argv[3])
    {
        dt = atof(argv[3]);
        if((double)dt == 0)
            ClientsForm->sgAbonements->Cells[2][CounterAbonements] = "";
        else
            ClientsForm->sgAbonements->Cells[2][CounterAbonements] = dt.DateString();
    }
    else
        ClientsForm->sgAbonements->Cells[2][CounterAbonements] = "";

    // EndDate - argv[4]
    dt = 0;
    if(argv[4])
    {
        dt = atof(argv[4]);
        if((double)dt == 0)
            ClientsForm->sgAbonements->Cells[3][CounterAbonements] = "";
        else
            ClientsForm->sgAbonements->Cells[3][CounterAbonements] = dt.DateString();
    }
    else
        ClientsForm->sgAbonements->Cells[3][CounterAbonements] = "";

    // Closed - argv[1]
    if(argv[1])
        ClientsForm->sgAbonements->Cells[0][CounterAbonements] = (atoi(argv[1]))? " " : "";
    else
        ClientsForm->sgAbonements->Cells[0][CounterAbonements] = " ";

    if(ClientsForm->sgAbonements->Cells[0][CounterAbonements].Length() == 0 && (int)dt < (int)Now())
        ClientsForm->sgAbonements->Cells[0][CounterAbonements] = "\t";
    // Price - argv[5]

    SQL_exefun(DBName,((AnsiString)"select count(*) from Visits where AbonementID=" + argv[0]).c_str(),&retString);
    double price, amount;
    if(argv[5])
        price = atof(argv[5]);
    else
        price = 0.0;

    // Visits - argv[6], FixSum - argv[7]
    int visits;
    if(argv[6])
        visits = atoi(argv[6]);
    else
        visits = 0;

    if(fixsum > 0.0 && !visits)
    {
        ClientsForm->sgAbonements->Cells[4][CounterAbonements] = FormatFloat(MoneyFormat,price).TrimLeft();
        ClientsForm->sgAbonements->Cells[5][CounterAbonements] = atoi(retString.c_str());

        return 0;
    }
    else if(fixsum < 0.0)
    {
        ClientsForm->sgAbonements->Cells[4][CounterAbonements] = FormatFloat(MoneyFormat,price).TrimLeft();
        ClientsForm->sgAbonements->Cells[5][CounterAbonements] = "";

        return 0;
    }

    int z = visits - atoi(retString.c_str());
    if(z < 0) z = 0;

    if(visits)
        amount = (z * price) / visits;
    else
        amount = 0.0;

    ClientsForm->sgAbonements->Cells[4][CounterAbonements] = FormatFloat(MoneyFormat,amount).TrimLeft() + " / " + FormatFloat(MoneyFormat,price).TrimLeft();
    ClientsForm->sgAbonements->Cells[5][CounterAbonements] = (AnsiString)z + " / " + visits;

    return 0;
}
//---------------------------------------------------------------------------
static int notes_update(void *NotUsed, int argc, char **argv, char **azColName)
{
    if(!argv[0]) return 0;
    __int64 ID = _atoi64(argv[0]);

    if(!ID) return 0;

    ClientsForm->NoteIDs[ClientsForm->NoteCounter++] = ID;





    ClientsForm->sgNotes->Cells[0][ClientsForm->NoteCounter] = "[" + TDateTime(atof(argv[2])).DateTimeString() + "] " + argv[1];




    return 0;
}
//---------------------------------------------------------------------------
static int abonements_spa_update(void *NotUsed, int argc, char **argv, char **azColName)
{
    // RowID - argv[0]
    // EndDate - argv[1]

    if(!argv[0]) return 0;
    __int64 ID = _atoi64(argv[0]);

    if(!ID) return 0;

    int edt = (argv[1])? atoi(argv[1]) : 0;
    if((int)edt >= (int)Now()) return 0;

    if(ClientsForm->AbonementsSPAUpdCounter >= (unsigned)ClientsForm->AbonementsSPAUpdIDs.Length)
        ClientsForm->AbonementsSPAUpdIDs.Length += 10;
    ClientsForm->AbonementsSPAUpdIDs[ClientsForm->AbonementsSPAUpdCounter++] = ID;

    return 0;
}
//---------------------------------------------------------------------------
static int abonements_spa_select(void *NotUsed, int argc, char **argv, char **azColName)
{
    if(IDsAbonementsSPA)
        IDsAbonementsSPA[CounterAbonementsSPA++] = _atoi64(argv[0]);
    else
        return 0;

    // Closed - argv[1]
    if(argv[1])
        ClientsForm->sgAbonementsSPA->Cells[0][CounterAbonementsSPA] = (atoi(argv[1]))? " " : "";
    else
        ClientsForm->sgAbonementsSPA->Cells[0][CounterAbonementsSPA] = " ";

    // Name - argv[2]
    ClientsForm->sgAbonementsSPA->Cells[1][CounterAbonementsSPA] = argv[2];

    // BegDate - argv[3]
    TDateTime dt;
    if(argv[3])
    {
        dt = atof(argv[3]);
        if((double)dt == 0)
            ClientsForm->sgAbonementsSPA->Cells[2][CounterAbonementsSPA] = "";
        else
            ClientsForm->sgAbonementsSPA->Cells[2][CounterAbonementsSPA] = dt.DateString();
    }
    else
        ClientsForm->sgAbonementsSPA->Cells[2][CounterAbonementsSPA] = "";

    // EndDate - argv[4]
    dt = 0;
    if(argv[4])
    {
        dt = atof(argv[4]);
        if((double)dt == 0)
            ClientsForm->sgAbonementsSPA->Cells[3][CounterAbonementsSPA] = "";
        else
            ClientsForm->sgAbonementsSPA->Cells[3][CounterAbonementsSPA] = dt.DateString();
    }
    else
        ClientsForm->sgAbonementsSPA->Cells[3][CounterAbonementsSPA] = "";

    // Balanse - argv[5]
    double balanse;
    if(argv[5])
        balanse = atof(argv[5]);
    else
        balanse = 0.0;

    ClientsForm->sgAbonementsSPA->Cells[4][CounterAbonementsSPA] = FormatFloat(MoneyFormat,balanse).TrimLeft();

    AnsiString sCnt;
    SQL_exefun(DBName,("select count(*) from Visits_SPA where AbonementID="+AnsiString(IDsAbonementsSPA[CounterAbonementsSPA-1])).c_str(),&sCnt);
    ClientsForm->sgAbonementsSPA->Cells[5][CounterAbonementsSPA] = sCnt;

    return 0;
}
//---------------------------------------------------------------------------
static int abonements_bath_select(void *NotUsed, int argc, char **argv, char **azColName)
{
    if(IDsAbonementsBath)
        IDsAbonementsBath[CounterAbonementsBath++] = _atoi64(argv[0]);
    else
        return 0;

    // Closed - argv[1]
    if(argv[1])
        ClientsForm->sgAbonementsBath->Cells[0][CounterAbonementsBath] = (atoi(argv[1]))? " " : "";
    else
        ClientsForm->sgAbonementsBath->Cells[0][CounterAbonementsBath] = " ";

    // Name - argv[2]
    ClientsForm->sgAbonementsBath->Cells[1][CounterAbonementsBath] = argv[2];

    // BegDate - argv[3]
    TDateTime dt;
    if(argv[3])
    {
        dt = atof(argv[3]);
        if((double)dt == 0)
            ClientsForm->sgAbonementsBath->Cells[2][CounterAbonementsBath] = "";
        else
            ClientsForm->sgAbonementsBath->Cells[2][CounterAbonementsBath] = dt.DateString();
    }
    else
        ClientsForm->sgAbonementsBath->Cells[2][CounterAbonementsBath] = "";

    // EndDate - argv[4]
    dt = 0;
    if(argv[4])
    {
        dt = atof(argv[4]);
        if((double)dt == 0)
            ClientsForm->sgAbonementsBath->Cells[3][CounterAbonementsBath] = "";
        else
            ClientsForm->sgAbonementsBath->Cells[3][CounterAbonementsBath] = dt.DateString();
    }
    else
        ClientsForm->sgAbonementsBath->Cells[3][CounterAbonementsBath] = "";

    // Balanse - argv[5]
    double balanse;
    if(argv[5])
        balanse = atof(argv[5]);
    else
        balanse = 0.0;

    ClientsForm->sgAbonementsBath->Cells[4][CounterAbonementsBath] = FormatFloat(MoneyFormat,balanse).TrimLeft();

    AnsiString sCnt;
    SQL_exefun(DBName,("select count(*) from Visits_Bath where AbonementID="+AnsiString(IDsAbonementsBath[CounterAbonementsBath-1])).c_str(),&sCnt);
    ClientsForm->sgAbonementsBath->Cells[5][CounterAbonementsBath] = sCnt;

    return 0;
}
//---------------------------------------------------------------------------
static int clients_select(void *NotUsed, int argc, char **argv, char **azColName)
{
    if(IDs)
        IDs[Counter] = _atoi64(argv[0]);
    else
        return 0;

    if(argv[1])
        ClientsForm->sgClients->Cells[0][++Counter] = (atoi(argv[1]))? "" : " ";
    else
        ClientsForm->sgClients->Cells[0][++Counter] = "";

    ClientsForm->sgClients->Cells[1][Counter] = argv[2];
    ClientsForm->sgClients->Cells[2][Counter] = argv[3];
    ClientsForm->sgClients->Cells[3][Counter] = argv[4];
    ClientsForm->sgClients->Cells[4][Counter] = argv[5];

    return 0;
}
//---------------------------------------------------------------------------
static int clients_rowupdate(void *NotUsed,int argc,char **argv,char **azColName)
{
    if(argv[0])
        ClientsForm->sgClients->Cells[0][UpdatedRow] = (atoi(argv[0]))? "" : " ";
    else
        ClientsForm->sgClients->Cells[0][UpdatedRow] = "";

    ClientsForm->sgClients->Cells[1][UpdatedRow] = argv[1];
    ClientsForm->sgClients->Cells[2][UpdatedRow] = argv[2];
    ClientsForm->sgClients->Cells[3][UpdatedRow] = argv[3];
    ClientsForm->sgClients->Cells[4][UpdatedRow] = argv[4];

    return 0;
}
//---------------------------------------------------------------------------
static int clients_setinfo(void *NotUsed,int argc,char **argv,char **azColName)
{
    if(argv[0])
        ClientsForm->laRegDate->Caption = TDateTime(atof(argv[0])).DateString();
    else
        ClientsForm->laRegDate->Caption = "";

    if(atoi(argv[1]) > 0)
        ClientsForm->laCardDate->Caption = TDateTime(atof(argv[1])).DateTimeString();
    else
        ClientsForm->laCardDate->Caption = "";

    ClientsForm->laPhone1->Caption = (argv[2]);
    ClientsForm->laPhone2->Caption = (argv[3]);
    ClientsForm->laCardNum->Caption = (argv[4]);
    ClientsForm->meClients->Lines->Text = (argv[5]);
    ClientsForm->meNote->Lines->Text = (argv[14]);
    //retString = argv[6];

    if(argv[6])
    {
        try
        {
            if(strlen(argv[6]) > 0)
            {
                //ClientsForm->Panel3->Visible = false;
                ClientsForm->paPhoto->Caption = "";
                ClientsForm->imClients->Picture->LoadFromFile(ImgPath + argv[6]);
                //ClientsForm->Panel3->Visible = true;
            }
            else
            {
                ClientsForm->imClients->Picture = NULL;
                ClientsForm->paPhoto->Caption = "��� ����";
            }
        }
        catch(...)
        {
            ClientsForm->paPhoto->Caption = "��� ����";
        }
    }
    else
    {
        ClientsForm->imClients->Picture = NULL;
        ClientsForm->paPhoto->Caption = "��� ����";
    }

    if(argv[7])
        CDate = atof(argv[7]);
    else
        CDate = 0;

    CUID = (argv[8])? _atoi64(argv[8]) : -1;

    if(argv[9])
        EDate = atof(argv[9]);
    else
        EDate = 0;

    EUID = (argv[10])? _atoi64(argv[10]) : -1;

    if(argv[11])
    {
        UserBalanse = atof(argv[11]);
        ClientsForm->laBalanse->Caption = "������: " + FormatFloat(MoneyFormat,UserBalanse).TrimLeft();
    }
    else
    {
        UserBalanse = 0.0;
        ClientsForm->laBalanse->Caption = "������: 0.00";
    }

    UserDiscount = (argv[12])? atof(argv[12]) : 0.0;
    UserDiscountSPA = (argv[13])? atof(argv[13]) : 0.0;
    double x;

    if(UserDiscount > 0.0)
    {
        if(UserDiscountSPA > 0.0)
        {
            // ����� ������

            ClientsForm->laDiscount->Caption = "0%";
            ClientsForm->laDiscountSPA->Caption = "0%";
            if(modf(UserDiscount,&x) != 0.0)
                ClientsForm->laDiscountAll->Caption = (AnsiString)strtof(argv[12])+"%";
            else
                ClientsForm->laDiscountAll->Caption = (AnsiString)atoi(argv[12])+"%";
        }
        else
        {
            ClientsForm->laDiscountSPA->Caption = "0%";
            ClientsForm->laDiscountAll->Caption = "0%";
            if(modf(UserDiscount,&x) != 0.0)
                ClientsForm->laDiscount->Caption = (AnsiString)strtof(argv[12])+"%";
            else
                ClientsForm->laDiscount->Caption = (AnsiString)atoi(argv[12])+"%";
        }
    }
    else if(UserDiscountSPA > 0.0)
    {
        ClientsForm->laDiscount->Caption = "0%";
        ClientsForm->laDiscountAll->Caption = "0%";
        if(modf(UserDiscountSPA,&x) != 0.0)
            ClientsForm->laDiscountSPA->Caption = (AnsiString)strtof(argv[13])+"%";
        else
            ClientsForm->laDiscountSPA->Caption = (AnsiString)atoi(argv[13])+"%";
    }
    else
    {
        ClientsForm->laDiscount->Caption = "0%";
        ClientsForm->laDiscountSPA->Caption = "0%";
        ClientsForm->laDiscountAll->Caption = "0%";
    }

    return 0;
}
//---------------------------------------------------------------------------
//static int retfun(void *NotUsed,int argc,char **argv,char **azColName)
//{
//    retString = "";
//    if(argc > 0 && argv[0]) retString = argv[0];

//    return 0;
//}
//---------------------------------------------------------------------------

//***************************************************************************
//*************************** END CALLBACKS *********************************
//***************************************************************************

//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgReserveWindowProc(Messages::TMessage& Msg)
{
    sgWindowProc(Msg,sgReserve,ReserveWidths,sgOReserveWindowProc);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgAbonementsWindowProc(Messages::TMessage& Msg)
{
    sgWindowProc(Msg,sgAbonements,AbsWidths,sgOAbonementsWindowProc);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgNotesWindowProc(Messages::TMessage& Msg)
{
    sgWindowProc(Msg,sgNotes,NotesWidths,sgONotesWindowProc);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgAbonementsSPAWindowProc(Messages::TMessage& Msg)
{
    sgWindowProc(Msg,sgAbonementsSPA,AbsSPAWidths,sgOAbonementsSPAWindowProc);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgAbonementsBathWindowProc(Messages::TMessage& Msg)
{
    sgWindowProc(Msg,sgAbonementsBath,AbsBathWidths,sgOAbonementsBathWindowProc);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgCliWindowProc(Messages::TMessage& Msg)
{
    sgWindowProc(Msg,sgClients,ClientsWidths,sgOCliWindowProc);
}
//---------------------------------------------------------------------------
__fastcall TClientsForm::TClientsForm(TComponent* Owner)
    : TForm(Owner)
{
    timSearch->Interval = SearchDelay;

    BackFlag = false;

    fldAlignCli = "cllll";
    fldAlignAbs = "clllrr";
    fldAlignNotes = "l";
    fldAlignReserve = "cLRrr";



    fldAlignResClients = "cLll";

    fldAlignFitShedule = "cLrrrr";

    fldAlignBathBuf = "ccRr";

    fldAlignBathResGroup = "Lccrr";

    pFitButtons[0] = sbFitMo;
    pFitButtons[1] = sbFitTu;
    pFitButtons[2] = sbFitWe;
    pFitButtons[3] = sbFitTh;
    pFitButtons[4] = sbFitFr;
    pFitButtons[5] = sbFitSa;
    pFitButtons[6] = sbFitSu;
    pFitButtons[7] = sbFitAlt;

    pMGButtons[0] = sbMGMo;
    pMGButtons[1] = sbMGTu;
    pMGButtons[2] = sbMGWe;
    pMGButtons[3] = sbMGTh;
    pMGButtons[4] = sbMGFr;
    pMGButtons[5] = sbMGSa;
    pMGButtons[6] = sbMGSu;
    pMGButtons[7] = sbMGAlt;

    pSKButtons[0] = sbSKMo;
    pSKButtons[1] = sbSKTu;
    pSKButtons[2] = sbSKWe;
    pSKButtons[3] = sbSKTh;
    pSKButtons[4] = sbSKFr;
    pSKButtons[5] = sbSKSa;
    pSKButtons[6] = sbSKSu;
    pSKButtons[7] = sbSKAlt;

    pBathButtons[0] = sbBathMo;
    pBathButtons[1] = sbBathTu;
    pBathButtons[2] = sbBathWe;
    pBathButtons[3] = sbBathTh;
    pBathButtons[4] = sbBathFr;
    pBathButtons[5] = sbBathSa;
    pBathButtons[6] = sbBathSu;
    pBathButtons[7] = sbBathAlt;

    TDateTime dt = FitCurrentDay = MGCurrentDay = SKCurrentDay = BathCurrentDay = (int)Now();
    int dw = dt.DayOfWeek() - 2;
    if(dw < 0) dw = 6;

    for(int i = 0; i < 8; i++)
    {
        pFitButtons[i]->Caption = AnsiString(_DayNames[dw]) + " / " + dt.FormatString("dd.mm");
        pMGButtons[i]->Caption = pFitButtons[i]->Caption;
        pSKButtons[i]->Caption = pFitButtons[i]->Caption;
        pBathButtons[i]->Caption = pFitButtons[i]->Caption;
        dt++;
        if(++dw > 6) dw = 0;
    }
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgClientsSelectCell(TObject *Sender,
      int ACol, int ARow, bool &CanSelect)
{
    if(ARow != sgClients->Row)
    {
        //pcResTree->ActivePageIndex = 0;
        sgClientsRowInfo(IDs,ARow-1);

        // ����� ���� �������� �����
        if(!BackFlag && !paBathRes->Visible)
            sgFitSheduleFullUpdate(true);
    }
}
//---------------------------------------------------------------------------
double __fastcall TClientsForm::SPADiscount(__int64 ID)
{
    SQL_exefun(DBName,("select Discount from Abonements_SPA where Closed=0 and ClientID="+AnsiString(ID)+" order by BegDate desc,CDate desc").c_str(),&retString);
    double discount = atof(retString.c_str());

    AnsiString sDis, sDisSPA;
    SQL_exefun2(NULL,("select Discount,DiscountSPA from Clients where RowID="+AnsiString(ID)).c_str(),&sDis,&sDisSPA);
    double disSPA;

    disSPA = atof(sDisSPA.c_str());
    if(disSPA <= 0) disSPA = atof(sDis.c_str());

    discount = (discount > disSPA)? discount : disSPA;

    int dt = (int)Now();
    SQL_exefun(DBName,("select count(*) from Abonements where Closed=0 and EndDate>="+AnsiString(dt)+" and ClientID="+AnsiString(ID)).c_str(),&retString);
    dt = atoi(retString.c_str());

    if(dt > 0) dt = 10;

    return (discount >= dt)? discount : dt;
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::tbAddClick(TObject *Sender)
{
    ClientID = 0;
    iClientsForm = new TiClientsForm(this);
    iClientsForm->ShowModal();
    delete iClientsForm;
    if(FormResult == 1)
    {
        __int64 *newIDs = new __int64[++Counter];
        if(!newIDs) Close();

        newIDs[0] = ClientID;
        for(unsigned i = 1; i < Counter; i++)
            newIDs[i] = IDs[i-1];
        PDEL(IDs);
        IDs = newIDs;

        if(Counter > 1)
        {
            sgClients->RowCount++;

        // �������� ��� ����
            for(unsigned i = Counter; i > 1; i--)
                sgClients->Rows[i] = sgClients->Rows[i-1];
        }
        //sgClientsFullUpdate();
        //unsigned i;
        //for(i = 0; i < Counter; i++)
          //  if(IDs[i] == ClientID) break;
        sgClients->Row = 1;
        UpdatedRow = 1;
        sgClientsRowUpdate(IDs,0);
        //sgClients->TopRow = 1;

    }
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgAbonementsFullUpdate(__int64 ID,__int64 LastAbID)
{
    if(SQL_BeginTransaction() != SQLITE_OK) return;

    __int64 *AbIDs;
    AnsiString *pAbCounts;
    AnsiString sFixSum, sEndDate;

    // �������� �� ����������
    unsigned cnt = SQL_fldKeyCollect(DBName,"EndDate",("from Abonements where Closed=0 and AbonementsCount<1 and ClientID="+AnsiString(ClientID)).c_str(),&AbIDs,&pAbCounts);

    for(unsigned i = 0; i < cnt; i++)
    {
        if(atoi(pAbCounts[i].c_str()) < (int)Now())
            SQL_exe(DBName,("update Abonements set Closed=1 where RowID="+AnsiString(AbIDs[i])).c_str());
    }

    delete [] AbIDs;
    delete [] pAbCounts;

    cnt = SQL_fldKeyCollect(DBName,"EndDate",("from Abonements where Closed=0 and AbonementsCount=1 and ClientID="+AnsiString(ClientID)).c_str(),&AbIDs,&pAbCounts);

    for(unsigned i = 0; i < cnt; i++)
    {
        if(atoi(pAbCounts[i].c_str()) < (int)Now())
            SQL_exe(DBName,("update Abonements set Closed=1 where RowID="+AnsiString(AbIDs[i])).c_str());
        else
        {
            SQL_exefun(DBName,("select count(*) from Visits where AbonementID="+AnsiString(AbIDs[i])).c_str(),&retString);
            if(atoi(retString.c_str()) >= 1)
                SQL_exe(DBName,("update Abonements set Closed=1 where RowID="+AnsiString(AbIDs[i])).c_str());
        }
    }

    delete [] AbIDs;
    delete [] pAbCounts;




    cnt = SQL_fldKeyCollect(DBName,"AbonementsCount",("from Abonements where Closed=0 and AbonementsCount>1 and ClientID="+AnsiString(ClientID)+" order by BegDate").c_str(),&AbIDs,&pAbCounts);

    for(unsigned i = 0; i < cnt; i++)
    {
        SQL_exefun(DBName,("select count(*) from Visits where AbonementID="+AnsiString(AbIDs[i])).c_str(),&retString);

        if(atoi(retString.c_str()) >= atoi(pAbCounts[i].c_str()))
        {
            // ������� � ������
            SQL_exe(DBName,("update Abonements set Closed=1 where RowID="+AnsiString(AbIDs[i])).c_str());
            continue;
        }

        // ���� ���������!
        if(i == cnt - 1)
        {
            // ��������� ���������, �������� ������ ����
            SQL_exefun(DBName,("select EndDate from Abonements where RowID="+AnsiString(AbIDs[i])).c_str(),&sEndDate);

            if((int)addmonths(atoi(sEndDate.c_str()),2) < (int)Now())
            {
                // ������� � ������
                SQL_exe(DBName,("update Abonements set Closed=1 where RowID="+AnsiString(AbIDs[i])).c_str());
            }

            continue;
        }

        // ���� ����. ���������!
        SQL_exefun(DBName,("select EndDate from Abonements where RowID="+AnsiString(AbIDs[i])).c_str(),&sEndDate);
        SQL_exefun(DBName,("select CDate from Abonements where RowID="+AnsiString(AbIDs[i+1])).c_str(),&retString);
        if((int)addmonths(atoi(sEndDate.c_str()),2) < atoi(retString.c_str()))
        {
            // �������
            SQL_exe(DBName,("update Abonements set Closed=1 where RowID="+AnsiString(AbIDs[i])).c_str());
        }
    }

    delete [] AbIDs;
    delete [] pAbCounts;

    if(cbShowAbClosed->Checked)
        SQL_exefun(DBName,("select count(*) from Abonements where ClientID="+(AnsiString)ID).c_str(),&retString);
    else
    {
        if(LastAbID)
            SQL_exefun(DBName,("select count(*) from Abonements where (Closed=0 or RowID="+AnsiString(LastAbID)+") and ClientID="+(AnsiString)ID).c_str(),&retString);
        else
            SQL_exefun(DBName,("select count(*) from Abonements where Closed=0 and ClientID="+(AnsiString)ID).c_str(),&retString);
    }
    __int64 SelRowID;
    bool SelFlag = false;
    if(IDsAbonements)
    {
        SelFlag = true;
        SelRowID = IDsAbonements[sgAbonements->Row-1];
        PDEL(IDsAbonements);
    }

    int icnt = atoi(retString.c_str());
    sgAbonements->RowCount = (!icnt)? 2 : icnt + 1;
    sgAbonements->Rows[sgAbonements->RowCount-1]->Clear();
    sgAbonements->Cells[0][1] = "";
    //sgClients->Row = 1;

    CounterAbonements = 0;

    if(icnt)
    {
        IDsAbonements = new __int64[icnt];
        if(!IDsAbonements) Close();

        //LastAbID = 0;
        //SQL_exe(DBName,("select Bills.RowID,CDate,sum(Total) from Bills inner join BillItems on Bills.RowID=BillID where ClientID="+(AnsiString)ID+" group by BillID order by CDate desc").c_str(),sells_select);
        if(cbShowAbClosed->Checked)
            SQL_exe(DBName,("select RowID,Closed,Name,BegDate,EndDate,Price,AbonementsCount,FixSum from Abonements where ClientID="+(AnsiString)ID+" order by BegDate desc,CDate desc").c_str(),abonements_select);
        else
        {
            if(LastAbID)
                SQL_exe(DBName,("select RowID,Closed,Name,BegDate,EndDate,Price,AbonementsCount,FixSum from Abonements where (Closed=0 or RowID="+AnsiString(LastAbID)+") and ClientID="+(AnsiString)ID+" order by BegDate desc,CDate desc").c_str(),abonements_select);
            else
                SQL_exe(DBName,("select RowID,Closed,Name,BegDate,EndDate,Price,AbonementsCount,FixSum from Abonements where Closed=0 and ClientID="+(AnsiString)ID+" order by BegDate desc,CDate desc").c_str(),abonements_select);
        }
        if(SelFlag)
        {
            unsigned i;
            for(i = 0; i < CounterAbonements; i++)
                if(IDsAbonements[i] == SelRowID) break;
            if(i == CounterAbonements)
                sgAbonements->Row = 1;
            else
                sgAbonements->Row = i + 1;
        }
        else
            sgAbonements->Row = 1;
    }
    else
        sgAbonements->Row = 1;

    SQL_CommitTransaction();

}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgAbonementsSPAFullUpdate(__int64 ID,__int64 LastAbID)
{
    //const char *pMethod = "clients.sgAbonementsSPAFullUpdate";
    if(SQL_BeginTransaction() != SQLITE_OK) return;

    AnsiString sID, sEndDate;
    double x;

    {

        SQL_exe(DBName,("update Abonements_SPA set Closed=1,Balanse=0 where Closed=0 and Balanse<=0 and ClientID="+AnsiString(ClientID)).c_str());
        SQL_exefun2(DBName,("select first 1 RowID,EndDate from Abonements_SPA where Closed=0 and ClientID="+AnsiString(ClientID)+" order by BegDate desc,CDate desc").c_str(),&sID,&sEndDate);

        if(atoi(sEndDate.c_str()) < (int)Now())
        {
            SQL_exefun(DBName,("select sum(Balanse) from Abonements_SPA where Closed=0 and ClientID="+AnsiString(ClientID)).c_str(),&retString);
            x = atof(retString.c_str());
            SQL_exe(DBName,("update Abonements_SPA set Closed=1,Balanse=0 where Closed=0 and ClientID="+AnsiString(ClientID)).c_str());
        }
        else
        {
            SQL_exefun(DBName,("select sum(Balanse) from Abonements_SPA where Closed=0 and RowID!="+sID+" and ClientID="+AnsiString(ClientID)).c_str(),&retString);
            x = atof(retString.c_str());
        //SQL_exe(DBName,("update Abonements_SPA set Closed=1,Balanse=0 where RowID!="+sID+" and ClientID="+AnsiString(ClientID)).c_str());
            SQL_exe(DBName,("update Abonements_SPA set Closed=1,Balanse=0 where Closed=0 and RowID!="+sID+" and ClientID="+AnsiString(ClientID)).c_str());
        }


        if(x != 0.0)
        {
            TDateTime dt = Now();

            SQL_iniInsert(DBName,"Bills");
            SQL_addInsert("ClientID",ClientID);
            SQL_addInsert("BegBalanse",UserBalanse);
                //SQL_addInsert("FromBalanse",FromBalanse);
            SQL_addInsert("ToBalanse",x);
                //if(spbPayment->Caption == "�/�")
            SQL_addInsert("Payment",-1);
            UserBalanse += x;
            SQL_addInsert("EndBalanse",UserBalanse);
                //SQL_addInsert("GetSum",GetSum);
                //SQL_addInsert("Change",Change);
            SQL_addInsert("Total",x);
            SQL_addInsert("CDate",(double)dt);
            SQL_addInsert("CUID",UserID);
            SQL_addInsert("EDate",(double)dt);
            SQL_exeInsert("EUID",UserID);

            SQL_iniUpdate(DBName,"Clients",ClientID);
            SQL_exeUpdate("Balanse",UserBalanse);

            //if(SQL_CommitTransaction(pMethod) == SQLITE_OK)
            //    ClientsForm->laBalanse->Caption = "������: " + FormatFloat(MoneyFormat,UserBalanse).TrimLeft();
        }
    }

    if(cbShowAbSPAClosed->Checked)
        SQL_exefun(DBName,("select count(*) from Abonements_SPA where ClientID="+(AnsiString)ID).c_str(),&retString);
    else
    {
        if(LastAbID)
            SQL_exefun(DBName,("select count(*) from Abonements_SPA where (Closed=0 or RowID="+AnsiString(LastAbID)+") and ClientID="+(AnsiString)ID).c_str(),&retString);
        else
            SQL_exefun(DBName,("select count(*) from Abonements_SPA where Closed=0 and ClientID="+(AnsiString)ID).c_str(),&retString);
    }
    __int64 SelRowID;
    bool SelFlag = false;
    if(IDsAbonementsSPA)
    {
        SelFlag = true;
        SelRowID = IDsAbonementsSPA[sgAbonementsSPA->Row-1];
        PDEL(IDsAbonementsSPA);
    }

    int icnt = atoi(retString.c_str());
    sgAbonementsSPA->RowCount = (!icnt)? 2 : icnt + 1;
    sgAbonementsSPA->Rows[sgAbonementsSPA->RowCount-1]->Clear();
    sgAbonementsSPA->Cells[0][1] = "";

    CounterAbonementsSPA = 0;

    if(icnt)
    {
        IDsAbonementsSPA = new __int64[icnt];
        if(!IDsAbonementsSPA) Close();

        if(cbShowAbSPAClosed->Checked)
            SQL_exe(DBName,("select RowID,Closed,Name,BegDate,EndDate,Balanse from Abonements_SPA where ClientID="+(AnsiString)ID+" order by BegDate desc,CDate desc").c_str(),abonements_spa_select);
        else
        {
            if(LastAbID)
                SQL_exe(DBName,("select RowID,Closed,Name,BegDate,EndDate,Balanse from Abonements_SPA where (Closed=0 or RowID="+AnsiString(LastAbID)+") and ClientID="+(AnsiString)ID+" order by BegDate desc,CDate desc").c_str(),abonements_spa_select);
            else
                SQL_exe(DBName,("select RowID,Closed,Name,BegDate,EndDate,Balanse from Abonements_SPA where Closed=0 and ClientID="+(AnsiString)ID+" order by BegDate desc,CDate desc").c_str(),abonements_spa_select);
        }
        if(SelFlag)
        {
            unsigned i;
            for(i = 0; i < CounterAbonementsSPA; i++)
                if(IDsAbonementsSPA[i] == SelRowID) break;
            if(i == CounterAbonementsSPA)
                sgAbonementsSPA->Row = 1;
            else
                sgAbonementsSPA->Row = i + 1;
        }
        else
            sgAbonementsSPA->Row = 1;
    }
    else
        sgAbonementsSPA->Row = 1;

    UserDiscountSPA = SPADiscount(ClientID);

    if(modf(UserDiscountSPA,&x) != 0.0)
        ClientsForm->laDiscountSPA->Caption = (AnsiString)UserDiscountSPA+"%";
    else
        ClientsForm->laDiscountSPA->Caption = (AnsiString)(int)UserDiscountSPA+"%";

    SQL_CommitTransaction();
}
//---------------------------------------------------------------------------
/*
void __fastcall TClientsForm::sgAbonementsBathFullUpdate(__int64 ID)
{
    if(SQL_BeginTransaction() != SQLITE_OK) return;

    __int64 *AbIDs;
    AnsiString sEndDate, *pAbCounts;

    unsigned cnt = SQL_fldKeyCollect(DBName,"Balanse",("from Abonements_Bath where Closed=0 and ClientID="+AnsiString(ClientID)+" order by BegDate").c_str(),&AbIDs,&pAbCounts);

    for(unsigned i = 0; i < cnt; i++)
    {
        if(atoi(pAbCounts[i].c_str()) <= 0)
        {
            // ������� � ������
            SQL_exe(DBName,("update Abonements_Bath set Closed=1 where RowID="+AnsiString(AbIDs[i])).c_str());
            continue;
        }

        // ���� ���������!
        if(i == cnt - 1)
        {
            // ��������� ���������, �������� ������ ����
            SQL_exefun(DBName,("select EndDate from Abonements_Bath where RowID="+AnsiString(AbIDs[i])).c_str(),&sEndDate);

            if((int)addmonths(atoi(sEndDate.c_str()),2) < (int)Now())
            {
                // ������� � ������
                SQL_exe(DBName,("update Abonements_Bath set Closed=1 where RowID="+AnsiString(AbIDs[i])).c_str());
            }

            continue;
        }

        // ���� ����. ���������!
        SQL_exefun(DBName,("select EndDate from Abonements_Bath where RowID="+AnsiString(AbIDs[i])).c_str(),&sEndDate);
        SQL_exefun(DBName,("select BegDate from Abonements_Bath where RowID="+AnsiString(AbIDs[i+1])).c_str(),&retString);
        if((int)addmonths(atoi(sEndDate.c_str()),2) < atoi(retString.c_str()))
        {
            // �������
            SQL_exe(DBName,("update Abonements_Bath set Closed=1 where RowID="+AnsiString(AbIDs[i])).c_str());
        }
    }

    delete [] AbIDs;
    delete [] pAbCounts;

    if(cbShowAbBathClosed->Checked)
        SQL_exefun(DBName,("select count(*) from Abonements_Bath where ClientID="+(AnsiString)ID).c_str(),&retString);
    else
        SQL_exefun(DBName,("select count(*) from Abonements_Bath where Closed=0 and ClientID="+(AnsiString)ID).c_str(),&retString);

    __int64 SelRowID;
    bool SelFlag = false;
    if(IDsAbonementsBath)
    {
        SelFlag = true;
        SelRowID = IDsAbonementsBath[sgAbonementsBath->Row-1];
        PDEL(IDsAbonementsBath);
    }

    int icnt = atoi(retString.c_str());
    sgAbonementsBath->RowCount = (!icnt)? 2 : icnt + 1;
    sgAbonementsBath->Rows[sgAbonementsBath->RowCount-1]->Clear();
    sgAbonementsBath->Cells[0][1] = "";

    CounterAbonementsBath = 0;

    if(icnt)
    {
        IDsAbonementsBath = new __int64[icnt];
        if(!IDsAbonementsBath) Close();

        //LastAbID = 0;
        //SQL_exe(DBName,("select Bills.RowID,CDate,sum(Total) from Bills inner join BillItems on Bills.RowID=BillID where ClientID="+(AnsiString)ID+" group by BillID order by CDate desc").c_str(),sells_select);
        if(cbShowAbBathClosed->Checked)
            SQL_exe(DBName,("select RowID,Closed,Name,BegDate,EndDate,Balanse from Abonements_Bath where ClientID="+(AnsiString)ID+" order by BegDate desc,RowID desc").c_str(),abonements_bath_select);
        else
            SQL_exe(DBName,("select RowID,Closed,Name,BegDate,EndDate,Balanse from Abonements_Bath where Closed=0 and ClientID="+(AnsiString)ID+" order by BegDate desc,RowID desc").c_str(),abonements_bath_select);

        if(SelFlag)
        {
            unsigned i;
            for(i = 0; i < CounterAbonementsBath; i++)
                if(IDsAbonementsBath[i] == SelRowID) break;
            if(i == CounterAbonementsBath)
                sgAbonementsBath->Row = 1;
            else
                sgAbonementsBath->Row = i + 1;
        }
        else
            sgAbonementsBath->Row = 1;
    }
    else
        sgAbonementsBath->Row = 1;

    SQL_CommitTransaction();

}*/
//---------------------------------------------------------------------------
void __fastcall TClientsForm::NotesUpdate(__int64 *IDs, unsigned pos)
{
    //lvNotes->Clear();
    sgNotes->RowCount = 2;
    sgNotes->Cells[0][1] = "";
    sgNotes->Row = 1;

    delete [] NoteIDs;
    NoteIDs = NULL;
    NoteCounter = 0;


    SQL_exefun(DBName,"select count(*) from Clients where Note<>''",&retString);
    unsigned i = atoi(retString.c_str());

    if(!i) return;

    sgNotes->RowCount = i + 1;

    NoteIDs = new __int64[i];

    SQL_exe(DBName,"select RowID,Note,EDate from Clients where Note<>'' order by EDate",notes_update);


    if(!IDs) return;

    for(i = 0; i < NoteCounter; i++)
    {
        if(NoteIDs[i] == IDs[pos])
            break;
    }

    if(i < NoteCounter)
        sgNotes->Row = i + 1;
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgReserveFullUpdate(__int64 LastRecID)
{
    sgReserve->RowCount = 2;
    sgClearRow(sgReserve);

    sgReserve->Row = 1;

    delete [] ReserveIDs;
    ReserveIDs = NULL;
    ReserveCounter = 0;

    // ����������
    AnsiString sql =

    "select count(*) from Reserve inner join Services on Reserve.ServiceID=Services.RowID "
    "left join Personal on Reserve.PersonID=Personal.RowID where Reserve.ParentID is null and ";

    //BegDate,Services.Name,Personal.Name,Status from Reserve,Services,Personal where "
    if(!cbClosedReserve->Checked)
    {
        if(LastRecID)
        {
            sql += "(Reserve.RowID=";
            sql += LastRecID;
            sql += " or (";
            sql += "trunc(Reserve.BegDate,0)>=";
            sql += (int)Now();
            sql += " and Status=1)) and ";
        }
        else
        {
            sql += "trunc(Reserve.BegDate,0)>=";
            sql += (int)Now();
            sql += " and Status=1 and ";
        }
    }


    sql += "Reserve.ClientID=";
    sql += ClientID;



    //sql += " and Status";
    //sql += (cbClosedReserve->Checked)? ">0" : "=1";



    //sql += " and Reserve.ServiceID=Services.RowID";


    SQL_exefun(DBName,sql.c_str(),&retString);
    int cnt = atoi(retString.c_str());
    if(!cnt)
    {
        //sbRes4Nal->Visible = false;
        return;
    }

    ReserveIDs = new __int64[cnt];
    sql = StringReplace(sql,"count(*)","Reserve.RowID,BegDate,Services.Name,Personal.Name,Status,Tag,Num",TReplaceFlags());

    SQL_exe(DBName,(sql + " order by 2 desc,1 desc").c_str(),reserve_fill);


    /*
    if(ReserveIDs && sgReserve->Row > 0)
    {
        SQL_exefun(NULL,("select ServiceID from Reserve where RowID="+AnsiString(ReserveIDs[sgReserve->Row-1])).c_str(),&retString);

        if(atoi(retString.c_str()) == BATH_COMPLEXID)
        {
            sbRes4Nal->Visible = true;
        }
        else
            sbRes4Nal->Visible = false;
    }
    else
        sbRes4Nal->Visible = false;
    */
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgClientsFullUpdate(void)
{
    AnsiString sql;
    if(cbAlive->Checked ^ cbNotAlive->Checked)
    {
        if(cbAlive->Checked)
            sql = " where Alive<>0";
        if(cbNotAlive->Checked)
            sql = " where Alive=0";
    }

    //AnsiString cnt;
    SQL_exefun(DBName,("select count(*) from Clients"+sql).c_str(),&retString);

    __int64 SelRowID;
    bool SelFlag = false;
    if(IDs)
    {
        SelFlag = true;
        SelRowID = IDs[sgClients->Row-1];
        PDEL(IDs);
    }

    int icnt = atoi(retString.c_str());
    sgClients->RowCount = (!icnt)? 2 : icnt + 1;
    sgClients->Rows[sgClients->RowCount-1]->Clear();
    sgClients->Cells[0][1] = "";
    //sgClients->Row = 1;

    Counter = 0;

    if(icnt)
    {
        IDs = new __int64[icnt];
        if(!IDs) Close();

        SQL_exe(DBName,("select RowID,Alive,FName,SName,TName,CID from Clients"+sql+" order by FName,SName,TName,RowID").c_str(),clients_select);

        if(SelFlag)
        {
            unsigned i;
            for(i = 0; i < Counter; i++)
                if(IDs[i] == SelRowID) break;
            if(i == Counter)
                sgClients->Row = 1;
            else
                sgClients->Row = i + 1;
        }
        else
            sgClients->Row = 1;
    }
    else
        sgClients->Row = 1;

    //ClientID = (IDs)? IDs[sgClients->Row-1] : 0;

    sgClientsRowInfo(IDs,sgClients->Row-1);

    NotesUpdate(IDs,sgClients->Row-1);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::FormShow(TObject *Sender)
{
    //dtpResDate->DateTime = Now();

    SQL_exefun(DBName,"select SettingsVal from Settings where SettingsKey='ClientsWidth'",&retString);
    int width = atoi(retString.c_str());
    if(width <= 0) width = 400;
    sgClients->Width = width;
    SQL_exefun(DBName,"select SettingsVal from Settings where SettingsKey='ClientsNameWidth'",&retString);
    width = atoi(retString.c_str());
    if(width <= 0) width = 120;

    laBalanse->Left = sgClients->Width + 3;

    sgSetHeaders(sgClients,"","�������","���","��������","�����������");
    sgSetWidths(sgClients,&ClientsWidths,16,width,width,width);

    sgSetHeaders(sgAbonements,"","���","������","�����","�����","���������");
    sgSetWidths(sgAbonements,&AbsWidths,16,250,110,110,150);

    sgSetHeaders(sgAbonementsSPA,"","���","������","�����","�����","���������");
    sgSetWidths(sgAbonementsSPA,&AbsSPAWidths,16,250,110,110,150);

    sgSetHeaders(sgAbonementsBath,"","���","������","�����","�����","���������");
    sgSetWidths(sgAbonementsBath,&AbsBathWidths,16,250,110,110,150);

    sgSetHeaders(sgNotes,"�����������");
    sgSetWidths(sgNotes,&NotesWidths,100);

    sgSetHeaders(sgReserve,"","����","�����","������","����������");
    sgSetWidths(sgReserve,&ReserveWidths,16,100,60,250);

    sgSetHeaders(sgMGTiming,"�����","������","�����","������","����������");
    sgSetWidths(sgMGTiming,&sgMGTimingWidths,50,50,50,200);

    sgMGTimingAligns = "Lrrrr";

    sgOMGTimingWindowProc = sgMGTiming->WindowProc;
    sgMGTiming->WindowProc = sgMGTimingWindowProc;

    sgSetHeaders(sgSKTiming,"�����","������","�����","������","����������");
    sgSetWidths(sgSKTiming,&sgSKTimingWidths,50,50,50,200);

    sgSKTimingAligns = "Lrrrr";

    sgOSKTimingWindowProc = sgSKTiming->WindowProc;
    sgSKTiming->WindowProc = sgSKTimingWindowProc;




    sgSetHeaders(sgBathTiming,"�����","������","�����","������","����������");
    sgSetWidths(sgBathTiming,&sgBathTimingWidths,50,50,50,200);

    sgBathTimingAligns = "Lrrrr";

    sgOBathTimingWindowProc = sgBathTiming->WindowProc;
    sgBathTiming->WindowProc = sgBathTimingWindowProc;

    sgSetHeaders(sgBathBuf,"������","�����","������","���-�� ���.");
    sgSetWidths(sgBathBuf,&sgBathBufWidths,60,60,240);
    sgOBathBufWindowProc = sgBathBuf->WindowProc;
    sgBathBuf->WindowProc = sgBathBufWindowProc;

    sgSetHeaders(sgBathResGroup,"������","������","�����","������","����������");
    sgSetWidths(sgBathResGroup,&sgBathResGroupWidths,150,60,60,150);
    sgOBathResGroupWindowProc = sgBathResGroup->WindowProc;
    sgBathResGroup->WindowProc = sgBathResGroupWindowProc;

    AbonementsUpdIDs.Length = 10;
    AbonementsUpdCounter = 0;

    sgOCliWindowProc = sgClients->WindowProc;
    sgClients->WindowProc = sgCliWindowProc;

    sgOAbonementsWindowProc = sgAbonements->WindowProc;
    sgAbonements->WindowProc = sgAbonementsWindowProc;

    sgOAbonementsSPAWindowProc = sgAbonementsSPA->WindowProc;
    sgAbonementsSPA->WindowProc = sgAbonementsSPAWindowProc;

    sgOAbonementsBathWindowProc = sgAbonementsBath->WindowProc;
    sgAbonementsBath->WindowProc = sgAbonementsBathWindowProc;

    sgONotesWindowProc = sgNotes->WindowProc;
    sgNotes->WindowProc = sgNotesWindowProc;

    sgOReserveWindowProc = sgReserve->WindowProc;
    sgReserve->WindowProc = sgReserveWindowProc;

    if(AdminMode || UserGrants[12] != '0')
    {
        bVisPhone->Visible = true;

        spbClosing->Visible = true;
        spbFitDChange->Visible = true;

        spbClosingSPA->Visible = true;
        spbClosingBath->Visible = true;

        imGreen->Visible = true;
        imRed->Visible = true;
        cbAlive->Visible = true;
        cbNotAlive->Visible = true;

        tbDoubles->Visible = true;

        sbDelRes->Visible = true;
    }

    if(UserGrants[16] != '0')
        bVisPhone->Visible = true;

    UsersCounter = UserInit(DBName,&pUserIDs,&pUsers);

    sgClientsFullUpdate();

    //-------------------------------------------------




    sgSetHeaders(sgResClients,"","�������","���","��������");
    sgSetWidths(sgResClients,&ResClientsWidths,16,120,120);

    sgOResClientsWindowProc = sgResClients->WindowProc;
    sgResClients->WindowProc = sgResClientsWindowProc;


    sgSetHeaders(sgFitShedule,"","������","����������","������","���-��","�����");
    sgSetWidths(sgFitShedule,&FitSheduleWidths,16,180,120,80,50);

    sgOFitSheduleWindowProc = sgFitShedule->WindowProc;
    sgFitShedule->WindowProc = sgFitSheduleWindowProc;

    // 16,120,120,120,100
    LoadBoxSize("BathBuf",Panel19,sgBathBuf);
    LoadBoxSize("BathResGroup",Panel28,sgBathResGroup);

    LoadGridSize("BathBuf",sgBathBuf);
    LoadGridSize("BathResGroup",sgBathResGroup);



    LoadGridSize("Clients",sgClients);
    LoadGridSize("Abonements",sgAbonements);
    LoadGridSize("AbonementsSPA",sgAbonementsSPA);
    LoadGridSize("AbonementsBath",sgAbonementsBath);
    LoadGridSize("Reserve",sgReserve);

    LoadBoxSize("FitShedule",sgFitShedule,sgResClients);

    LoadGridSize("FitShedule",sgFitShedule);
    LoadGridSize("ResClients",sgResClients);

    LoadBoxSize("Massage",Panel16,sgMGTiming);
    LoadGridSize("MassageTiming",sgMGTiming);


    LoadBoxSize("Saloon",Panel21,sgSKTiming);
    LoadGridSize("SaloonTiming",sgSKTiming);

    LoadBoxSize("Bath",Panel19,sgBathTiming);
    LoadGridSize("BathTiming",sgBathTiming);

    CheckKKMButtons();

    edSearchStr->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgClientsRowInfo(__int64 *pID, unsigned cnt)
{
    if(!paBathRes->Visible)
    {
        sgBathResGroup->RowCount = 2;
        sgClearRow(sgBathResGroup);

        paBathBuf->Visible = false;
    }
    
    if(pID)
        ClientID = pID[cnt];
    else
        ClientID = 0;

    if(pID)
    {
        CDate = 0;
        CUID = -1;
        EDate = 0;
        EUID = -1;

        SQL_exe(DBName,("select CDate,CardDate,Phone1,Phone2,CardNum,Info,Photo,CDate,CUID,EDate,EUID,Balanse,Discount,DiscountSPA,Note from Clients where RowID="+AnsiString(pID[cnt])).c_str(),clients_setinfo);

        //SQL_exefun(DBName,("select Discount from Abonements_SPA where Closed=0 and ClientID="+AnsiString(ID)+" order by BegDate desc,CDate desc").c_str(),&retString);
        //double discount = atof(retString.c_str());
        //discount = (discount > UserDiscountSPA)? discount : UserDiscountSPA;

        int dt = (int)Now();
        SQL_exefun(DBName,("select count(*) from Abonements where Closed=0 and EndDate>="+AnsiString(dt)+" and ClientID="+AnsiString(pID[cnt])).c_str(),&retString);
        dt = atoi(retString.c_str());
        if(dt > 0 && UserDiscountSPA < 10)
            UserDiscountSPA = 10;
        SQL_exefun(DBName,("select Discount from Abonements_SPA where Closed=0 and ClientID="+AnsiString(pID[cnt])+" order by BegDate desc,CDate desc").c_str(),&retString);
        dt = atoi(retString.c_str());
        if(UserDiscountSPA < dt)
            UserDiscountSPA = dt;
        //UserDiscountSPA = (discount > UserDiscountSPA)? discount : UserDiscountSPA;
        //double x;

        ClientsForm->laDiscountSPA->Caption = (AnsiString)UserDiscountSPA + "%";


        AnsiString status = "ID: " + (AnsiString)pID[cnt];

        unsigned i;
        for(i = 0; i < UsersCounter; i++)
            if(pUserIDs[i] == CUID) break;

        if(i == UsersCounter)
            status += "   C:[unknown]";
        else
            status += ("   C:[" + pUsers[i] + " - ");

        if((double)CDate == 0)
            status += "?]";
        else
            status += (CDate.DateTimeString() + "]");

        for(i = 0; i < UsersCounter; i++)
            if(pUserIDs[i] == EUID) break;

        if(i == UsersCounter)
            status += "   E:[unknown]";
        else
            status += ("   E:[" + pUsers[i] + " - ");

        if((double)EDate == 0)
            status += "?]";
        else
            status += (EDate.DateTimeString() + "]");

        sbClients->SimpleText = status;

        //sgSellsFullUpdate(pID[cnt]);
        sgAbonementsFullUpdate(pID[cnt]);
        sgAbonementsSPAFullUpdate(pID[cnt]);
        //sgAbonementsBathFullUpdate(pID[cnt]);

        sgReserveFullUpdate();
    }
    else
    {
        imClients->Picture = NULL;
        sbClients->SimpleText = "ID: ";
        laRegDate->Caption = "";
        laCardDate->Caption = "";
        laPhone1->Caption = "";
        laPhone2->Caption = "";
        laCardNum->Caption = "";
        meClients->Clear();
        meNote->Clear();

        //PDEL(IDsSells);
        //CounterSells = 0;
        //sgSells->RowCount = 2;
        //sgSells->Cells[0][1] = "";
        //sgSells->Cells[1][1] = "";
        //sgSells->Row = 1;

        PDEL(IDsAbonements);
        CounterAbonements = 0;
        sgAbonements->RowCount = 2;
        sgAbonements->Cells[0][1] = "";
        sgAbonements->Cells[1][1] = "";
        sgAbonements->Cells[2][1] = "";
        sgAbonements->Cells[3][1] = "";
        sgAbonements->Cells[4][1] = "";
        sgAbonements->Cells[5][1] = "";
        sgAbonements->Row = 1;

        laBalanse->Caption = "������: 0.00";
        laDiscount->Caption = "0%";
        laDiscountSPA->Caption = "0%";
        laDiscountAll->Caption = "0%";
    }


}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgClientsRowUpdate(__int64 *pID, unsigned cnt)
{
    if(pID)
        SQL_exe(DBName,("select Alive,FName,SName,TName,CID from Clients where RowID=" + (AnsiString)pID[cnt]).c_str(),clients_rowupdate);
    else
    {
        sgClients->Cells[0][UpdatedRow] = "";
        sgClients->Cells[1][UpdatedRow] = "";
        sgClients->Cells[2][UpdatedRow] = "";
        sgClients->Cells[3][UpdatedRow] = "";
        sgClients->Cells[4][UpdatedRow] = "";
    }

    sgClientsRowInfo(pID,cnt);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgClientsDrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
    sgDrawCell(Sender,ACol,ARow,Rect,State,fldAlignCli,IDs != NULL,ilClients);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::tbReloadClick(TObject *Sender)
{
    edSearchStr->Text = "";
    edPSearchStr->Text = "";
    sgClientsFullUpdate();

    //if(sgClients->Row > 0 && Counter > 0)
    //{
    //    if(!IDs) return;
    //    AnsiString sql = "delete from Clients where RowID=" + (AnsiString)IDs[sgClients->Row-1];

    //    SQL_exe(DBName,sql.c_str());
    //    sgClientsUpdate();
    //}
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::timPhotoTimer(TObject *Sender)
{
    capGrabFrame(hWndC);
    if(capEditCopy(hWndC))
        imClients->Picture->LoadFromClipboardFormat(CF_BITMAP, Clipboard()->GetAsHandle(CF_BITMAP),0);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::Button1Click(TObject *Sender)
{
    hWndC = capCreateCaptureWindow("",WS_CHILD, this->Left, this->Top, this->Width, this->Height, this->Handle, 11011);
    capDriverConnect (hWndC,0);
    timPhoto->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::cbFNameClick(TObject *Sender)
{
    static bool SelfCheck = false;

    if(cbFName->Checked)
    {
        if(!SelfCheck)
            sgClientsUpdate();
        else
            SelfCheck = false;
    }
    else if(!cbSName->Checked && !cbTName->Checked && !cbCID->Checked)
    {
        SelfCheck = true;
        cbFName->Checked = true;
    }
    else
        sgClientsUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::cbSNameClick(TObject *Sender)
{
    static bool SelfCheck = false;

    if(cbSName->Checked)
    {
        if(!SelfCheck)
            sgClientsUpdate();
        else
            SelfCheck = false;
    }
    else if(!cbFName->Checked && !cbTName->Checked && !cbCID->Checked)
    {
        SelfCheck = true;
        cbSName->Checked = true;
    }
    else
           sgClientsUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::cbTNameClick(TObject *Sender)
{
    static bool SelfCheck = false;

    if(cbTName->Checked)
    {
        if(!SelfCheck)
               sgClientsUpdate();
        else
            SelfCheck = false;
    }
    else if(!cbFName->Checked && !cbSName->Checked && !cbCID->Checked)
    {
        SelfCheck = true;
        cbTName->Checked = true;
    }
    else
           sgClientsUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::Button2Click(TObject *Sender)
{
    capDriverDisconnect(hWndC);
    timPhoto->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::cbCIDClick(TObject *Sender)
{
    static bool SelfCheck = false;

    if(cbCID->Checked)
    {
        if(!SelfCheck)
               sgClientsUpdate();
        else
            SelfCheck = false;
    }
    else if(!cbFName->Checked && !cbSName->Checked && !cbTName->Checked)
    {
        SelfCheck = true;
        cbCID->Checked = true;
    }
    else
           sgClientsUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::cbAliveClick(TObject *Sender)
{
    static bool SelfCheck = false;

    if(cbAlive->Checked)
    {
        if(!SelfCheck)
               sgClientsUpdate();
        else
            SelfCheck = false;
    }
    else if(!cbNotAlive->Checked)
    {
        SelfCheck = true;
        cbAlive->Checked = true;
    }
    else
           sgClientsUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::cbNotAliveClick(TObject *Sender)
{
    static bool SelfCheck = false;

    if(cbNotAlive->Checked)
    {
        if(!SelfCheck)
               sgClientsUpdate();
        else
            SelfCheck = false;
    }
    else if(!cbAlive->Checked)
    {
        SelfCheck = true;
        cbNotAlive->Checked = true;
    }
    else
           sgClientsUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgClientsUpdate(void)
{
    AnsiString txt;

    if(edSearchStr->Focused())
        txt = edSearchStr->Text;
    else
        txt = edPSearchStr->Text;

    if(txt.Length() == 0)
    {
        sgClientsFullUpdate();
        return;
    }

    AnsiString sql;

    if(edSearchStr->Focused())
    {
        sql = "select count(*) from Clients where Upper(FullName) like ";
        sql += ("'%" + txt.UpperCase() + "%'");
    }
    else
    {
        sql = "select count(*) from Clients where Upper(case when CID is null then '' else CID end || case when Phone1 is null then '' else Phone1 end || case when Phone2 is null then '' else Phone2 end || case when Phone3 is null then '' else Phone3 end) like ";
        sql += ("'%" + txt.UpperCase() + "%'");
    }
    if(cbAlive->Checked ^ cbNotAlive->Checked)
    {
        if(cbAlive->Checked)
            sql += " and Alive<>0";
        if(cbNotAlive->Checked)
            sql += " and Alive=0";
    }

    SQL_exefun(DBName,sql.c_str(),&retString);

    __int64 SelRowID;
    bool SelFlag = false;
    if(IDs)
    {
        SelFlag = true;
        SelRowID = IDs[sgClients->Row-1];
        PDEL(IDs);
    }

    int icnt = atoi(retString.c_str());
    sgClients->RowCount = (!icnt)? 2 : icnt + 1;
    sgClients->Rows[sgClients->RowCount-1]->Clear();
    sgClients->Cells[0][1] = "";

    Counter = 0;

    if(icnt)
    {
        IDs = new __int64[icnt];
        if(!IDs) Close();
    }
    else
    {
        sgClients->Row = 1;
        sgClientsRowInfo(IDs,sgClients->Row-1);
        return;
    }

    if(ClientsForm->edSearchStr->Focused())
    {
        sql = "select RowID,Alive,FName,SName,TName,CID from Clients where Upper(FullName) like ";
        sql += ("'%" + txt.UpperCase() + "%'");
    }
    else
    {
        sql = "select RowID,Alive,FName,SName,TName,CID from Clients where Upper(case when CID is null then '' else CID end || case when Phone1 is null then '' else Phone1 end || case when Phone2 is null then '' else Phone2 end || case when Phone3 is null then '' else Phone3 end) like ";
        sql += ("'%" + txt.UpperCase() + "%'");
    }

    if(cbAlive->Checked ^ cbNotAlive->Checked)
    {
        if(cbAlive->Checked)
            sql += " and Alive<>0";
        if(cbNotAlive->Checked)
            sql += " and Alive=0";
    }

    sql += " order by FullName,CDate";

    SQL_exe(DBName,sql.c_str(),clients_select);

    if(SelFlag)
    {
        unsigned i;
        for(i = 0; i < Counter; i++)
            if(IDs[i] == SelRowID) break;
        if(i == Counter)
            sgClients->Row = 1;
        else
            sgClients->Row = i + 1;
    }
    else
        sgClients->Row = 1;

    sgClientsRowInfo(IDs,sgClients->Row-1);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::tbHomeClick(TObject *Sender)
{
    sgClients->Row = 1;
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::FormDestroy(TObject *Sender)
{
    PDEL(IDs);
    //PDEL(IDsSells);
    PDEL(IDsAbonements);
    PDEL(IDsAbonementsSPA);
    PDEL(IDsAbonementsBath);
    PDEL(ReserveIDs);
    PDEL(pUsers);
    PDEL(pUserIDs);

    delete [] ReserveWidths;

    delete [] NoteIDs;
    delete [] NotesWidths;

    delete [] ClientsWidths;
    delete [] AbsWidths;
    delete [] AbsSPAWidths;
    delete [] AbsBathWidths;


    delete [] ResClientsWidths;

    delete [] FitSheduleWidths;

    delete [] sgMGTimingWidths;

    delete [] sgSKTimingWidths;

    delete [] sgBathTimingWidths;

    SaveGridSize("BathBuf",sgBathBuf);
    SaveGridSize("BathResGroup",sgBathResGroup);

    SaveBoxSize("BathBuf",Panel19,sgBathBuf);
    SaveBoxSize("BathResGroup",Panel28,sgBathResGroup);

    SaveGridSize("Clients",sgClients);
    SaveGridSize("Abonements",sgAbonements);
    SaveGridSize("AbonementsSPA",sgAbonementsSPA);
    SaveGridSize("AbonementsBath",sgAbonementsBath);
    SaveGridSize("Reserve",sgReserve);

    SaveGridSize("FitShedule",sgFitShedule);
    SaveGridSize("ResClients",sgResClients);

    SaveBoxSize("FitShedule",sgFitShedule,sgResClients);

    SaveGridSize("MassageTiming",sgMGTiming);
    SaveBoxSize("Massage",Panel16,sgMGTiming);

    SaveGridSize("SaloonTiming",sgSKTiming);
    SaveBoxSize("Saloon",Panel21,sgSKTiming);

    SaveGridSize("BathTiming",sgBathTiming);
    SaveBoxSize("Bath",Panel19,sgBathTiming);

}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::tbExitClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::tbEditClick(TObject *Sender)
{
    if(sgClients->Row > 0 && Counter > 0)
    {
        if(!IDs) return;

        if(UserID != 0 && UserID != 4)
        {
            int mask = UserGrants[1] - '0';

            if((mask & 2) == 0)
                return;
        }

        ClientID = IDs[sgClients->Row-1];
        iClientsForm = new TiClientsForm(this);
        iClientsForm->ShowModal();
        if(FormResult == -1)
        {
            // �������� ������
            UpdatedRow = sgClients->Row;
            SQL_exe(DBName,("select Alive,FName,SName,TName,CID from Clients where RowID=" + (AnsiString)ClientID).c_str(),clients_rowupdate);
            sgClientsRowInfo(&ClientID,0);
        }
        delete iClientsForm;
    }
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgClientsKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key == VK_RETURN)
    {
        Key = 0;
        tbEditClick(Sender);
    }
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::edSearchStrKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
    if(Key == VK_RETURN)
    {
        sgClientsUpdate();
        sgClients->SetFocus();

        Key = 0;
    }
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::tbKassaClick(TObject *Sender)
{
    if(sgClients->Row > 0 && Counter > 0)
    {
        if(!IDs) return;

        ClientID = IDs[sgClients->Row-1];
        BillsID = 0;

        KassaForm = new TKassaForm(this);
        KassaForm->ShowModal();

        if(FormResult == -1)
        {
            //PDEL(IDsSells);
            PDEL(IDsAbonements);
            // �������� ������
            //UpdatedRow = sgClients->Row;
            //SQL_exe(DBName,("select Alive,FName,SName,TName,CID from Clients where RowID=" + (AnsiString)ClientID).c_str(),clients_rowupdate);
            sgClientsRowInfo(&ClientID,0);
        }

        delete KassaForm;
    }

    BillsID = 0;
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgAbonementsDrawCell(TObject *Sender,
      int ACol, int ARow, TRect &Rect, TGridDrawState State)
{
    sgDrawCell(Sender,ACol,ARow,Rect,State,fldAlignAbs,IDsAbonements != NULL,ilClients);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgAbonementsDblClick(TObject *Sender)
{
    if(sgClients->Row > 0 && Counter > 0 && sgAbonements->Row > 0 && CounterAbonements > 0)
    {
        if(!IDs || !IDsAbonements) return;

        ClientID = IDs[sgClients->Row-1];
        AbonementSPAID = 0;
        AbonementID = IDsAbonements[sgAbonements->Row-1];

        SQL_exefun(DBName,("select CDate from Abonements where RowID="+AnsiString(AbonementID)).c_str(),&retString);
        TDateTime dt = atof(retString.c_str());
        retString = dt;

        VisitsForm = new TVisitsForm(this);
        VisitsForm->ShowModal();

        if(VisitsForm->AbsModified)
            sgAbonementsFullUpdate(ClientID);

        delete VisitsForm;
    }
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::cbShowAbClosedClick(TObject *Sender)
{
    if(ClientID)
        sgAbonementsFullUpdate(ClientID);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::AbsFullCheck(void)
{
//(const char *dbname,const char *fName,const char *sql_from,AnsiString **pFld)
    AnsiString *pCIDs = NULL;
    AbonementsUpdCounter = 0;


    SQL_BeginTransaction();

    unsigned count = SQL_fldCollect(DBName,"RowID","from Clients where RowID in (select distinct ClientID from Abonements where Closed=0)",&pCIDs);



    for(unsigned j = 0; j < count; j++)
    {
        SQL_exe(DBName,("select Abonements.RowID,AbonementsCount,EndDate,count(Visits.RowID),FixSum from Abonements inner join Visits on AbonementID=Abonements.RowID where Closed=0 and ClientID="+(AnsiString)pCIDs[j]+" group by AbonementID").c_str(),abonements_update);
        for(unsigned i = 0; i < AbonementsUpdCounter; i++)
            SQL_exe(DBName,("update Abonements set Closed=1 where RowID=" + (AnsiString)AbonementsUpdIDs[i]).c_str());
    }

    SQL_CommitTransaction();

    AbonementsUpdIDs.Length = 0;

    PDEL(pCIDs);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::AbsSPAFullCheck(void)
{
//(const char *dbname,const char *fName,const char *sql_from,AnsiString **pFld)
    AnsiString *pCIDs = NULL;
    AbonementsSPAUpdCounter = 0;

    SQL_BeginTransaction();

    unsigned count = SQL_fldCollect(DBName,"RowID","from Clients where RowID in (select distinct ClientID from Abonements_SPA where Closed=0)",&pCIDs);

    for(unsigned j = 0; j < count; j++)
    {
        SQL_exe(DBName,("select RowID,EndDate from Abonements_SPA where Closed=0 and ClientID="+(AnsiString)pCIDs[j]).c_str(),abonements_spa_update);
        for(unsigned i = 0; i < AbonementsUpdCounter; i++)
            SQL_exe(DBName,("update Abonements_SPA set Closed=1 where RowID=" + (AnsiString)AbonementsSPAUpdIDs[i]).c_str());
    }

    SQL_CommitTransaction();

    AbonementsSPAUpdIDs.Length = 0;

    PDEL(pCIDs);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::spbVisitClick(TObject *Sender)
{
    // ���� ��������� ���������?
    if(!ClientID) return;

    AnsiString sRet, sCounter;

    SQL_exefun(DBName,("select count(*) from Abonements where Closed=0 and FixSum>=0 and EndDate>="+AnsiString((int)Now())+" and ClientID="+AnsiString(ClientID)).c_str(),&sCounter);
    unsigned abs_cnt = atoi(sCounter.c_str());

    if(!abs_cnt)
    {
        Application->MessageBox("��������!\n��� ����������� � ���������� �����������.","������������ ��������",ID_OK);
        return;
    }

    // �������� �� ������
    SQL_exefun(DBName,("select count(*) from Abonements where Closed=0 and AbonementsCount=0 and FixSum>0 and ClientID="+AnsiString(ClientID)).c_str(),&sRet);

    if(atoi(sRet.c_str()) == 0)
    {
        // ��� ������� �����, ������� �������
        SQL_exefun(DBName,("select count(*) from Reserve,FitGroup where ClientID="+AnsiString(ClientID)+" and Status=1 and FitGroupID=FitGroup.RowID and Closed=0").c_str(),&sRet);
        unsigned recs = atoi(sRet.c_str());

        if(recs)
        {
            AnsiString sql =


            "select sum(ACNT),sum(case when VCNT is null then 0 else VCNT end) from "
            "( "
                "select RowID as RID,AbonementsCount as ACNT from Abonements where Closed=0 and FixSum>=0 and ClientID=";

            sql += ClientID;
            sql +=

            ") "
            "left outer join "
            "( "
                "select AbonementID as AID,sum(case when AbonementID is null then 0 else 1 end) as VCNT from Visits "
                "group by AbonementID "
            ") "
            "on RID=AID";


            SQL_exefun2(DBName,sql.c_str(),&sCounter,&sRet);

            //SQL_exefun2(DBName,("select Count,count(*) from Abonements,Visits where Closed=0 and FixSum>=0 and EndDate>="+AnsiString(begday)+" and ClientID="+AnsiString(ClientID)+" and Abonements.RowID=AbonementID group by Abonements.RowID").c_str(),&sCounter,&sRet);
            abs_cnt = atoi(sCounter.c_str()) - atoi(sRet.c_str());

            // ������������, �� ����� ���� ����������� ������ � ������
            // �������� ���-�� ������� ������� ������� �� �������

            // ���� ������, ��������� ���� �� ������� � ����������
            if(abs_cnt < ++recs)
            {
                Application->MessageBox("��������!\n��� ��������� � ���������� ��������������� ��� ������.","������������ ��������",ID_OK);
                return;
            }
        }
    }


    //if(atof(sFixSum.c_str()) == 0.0)
    //{
        // ��������� �������� �� ����� ����������� ���������
        //SQL_exefun(DBName,("select count(*) from Abonements where Closed=0 and FixSum>=0 and EndDate>="+AnsiString((int)Now())+" and ClientID="+AnsiString(ClientID)).c_str(),&sCounter);
        //abs_cnt = atoi(sCounter.c_str());

        //if(!abs_cnt)
        //{

        //    Application->MessageBox("��������!\n������� ��������� ���������. ��� ��� ��������� ����� ���������� ��������� ���������.","������������ ��������",ID_OK);
        //    return;
        //}
    //}




    FormResult = 0;
    iVisitMode = 1;
    iVisitsForm = new TiVisitsForm(this);
    iVisitsForm->Tag = "�������";
    iVisitsForm->ShowModal();
    delete iVisitsForm;

    if(FormResult == 1)
    {
        PDEL(IDsAbonements);
        sgAbonementsFullUpdate(ClientID);
    }
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    switch(Key)
    {
case VK_INSERT: Key = 0;
                edScanSearch->SetFocus();
                edScanSearch->Text = "";
                edScanSearch->PasswordChar = '*';
                edScanSearch->SetFocus();
                break;
case VK_ESCAPE: Key = 0;
                Close();
                break;
case VK_F2:     Key = 0;
                tbKassaClick(Sender);
                break;
case VK_F12:    Key = 0;
                spbVisitClick(Sender);
    }
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgAbonementsKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
    if(Key == VK_RETURN)
    {
        Key = 0;
        sgAbonementsDblClick(Sender);
    }
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgClientsScan(void)
{
    AnsiString txt = edScanSearch->Text.Trim();

    if(txt.Length() == 0)
    {
        sgClientsFullUpdate();
        return;
    }

    AnsiString sFld = (edScanSearch->PasswordChar == '*')? "DiscountCard" : "CardNum";

    AnsiString sql = "select count(*) from Clients where "+ sFld + "='" + txt + "'";

    if(cbAlive->Checked ^ cbNotAlive->Checked)
    {
        if(cbAlive->Checked)
            sql += " and Alive<>0";
        if(cbNotAlive->Checked)
            sql += " and Alive=0";
    }

    SQL_exefun(DBName,sql.c_str(),&retString);

    __int64 SelRowID;
    bool SelFlag = false;
    if(IDs)
    {
        SelFlag = true;
        SelRowID = IDs[sgClients->Row-1];
        PDEL(IDs);
    }

    int icnt = atoi(retString.c_str());
    sgClients->RowCount = (!icnt)? 2 : icnt + 1;
    sgClients->Rows[sgClients->RowCount-1]->Clear();
    sgClients->Cells[0][1] = "";

    Counter = 0;

    if(icnt)
    {
        IDs = new __int64[icnt];
        if(!IDs) Close();
    }
    else
    {
        sgClients->Row = 1;
        sgClientsRowInfo(IDs,sgClients->Row-1);
        return;
    }

    sql = "select RowID,Alive,FName,SName,TName,CID from Clients where " + sFld + "='" + txt + "'";

    if(cbAlive->Checked ^ cbNotAlive->Checked)
    {
        if(cbAlive->Checked)
            sql += " and Alive<>0";
        if(cbNotAlive->Checked)
            sql += " and Alive=0";
    }

    sql += " order by FullName,CDate";

    SQL_exe(DBName,sql.c_str(),clients_select);

    if(SelFlag)
    {
        unsigned i;
        for(i = 0; i < Counter; i++)
            if(IDs[i] == SelRowID) break;
        if(i == Counter)
            sgClients->Row = 1;
        else
            sgClients->Row = i + 1;
    }
    else
        sgClients->Row = 1;

    sgClientsRowInfo(IDs,sgClients->Row-1);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::edScanSearchKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key == VK_RETURN)
    {
        Key = 0;
        sgClientsScan();
        sgClients->SetFocus();
    }
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::tbDoublesClick(TObject *Sender)
{
    AnsiString sql =

    "select RowID,Alive,FName,SName,TName,CID from Clients inner join "
    "( "
        "select RID from "
        "( "
            "select RowID as RID,Upper(case when FName is null then '' else FName end || case when SName is null then '' else SName end || case when TName is null then '' else TName end) as SFF from Clients "
        ") "
        "inner join "
        "( "
            "select Upper(case when FName is null then '' else FName end || case when SName is null then '' else SName end || case when TName is null then '' else TName end) as SF from Clients "
            "group by SF having count(*)>1 "
        ") on SFF=SF "
    ") on RowID=RID";

    SQL_exefun(DBName,("select count(*) from ( "+sql+" )").c_str(),&retString);

    PDEL(IDs);

    int icnt = atoi(retString.c_str());
    sgClients->RowCount = (!icnt)? 2 : icnt + 1;
    sgClients->Rows[sgClients->RowCount-1]->Clear();
    sgClients->Cells[0][1] = "";

    Counter = 0;

    if(icnt)
    {
        IDs = new __int64[icnt];
        if(!IDs) Close();
    }
    else
    {
        sgClients->Row = 1;
        sgClientsRowInfo(IDs,sgClients->Row-1);
        return;
    }

    SQL_exe(DBName,sql.c_str(),clients_select);

    sgClients->Row = 1;

    sgClientsRowInfo(IDs,sgClients->Row-1);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgAbonementsSPADrawCell(TObject *Sender,
      int ACol, int ARow, TRect &Rect, TGridDrawState State)
{
    sgDrawCell(Sender,ACol,ARow,Rect,State,fldAlignAbs,IDsAbonementsSPA != NULL,ilClients);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::cbShowAbSPAClosedClick(TObject *Sender)
{
    if(ClientID)
        sgAbonementsSPAFullUpdate(ClientID);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgAbonementsSPADblClick(TObject *Sender)
{
    if(sgClients->Row > 0 && Counter > 0 && sgAbonementsSPA->Row > 0 && CounterAbonementsSPA > 0)
    {
        if(!IDs || !IDsAbonementsSPA) return;

        ClientID = IDs[sgClients->Row-1];
        AbonementID = 0;
        AbonementSPAID = IDsAbonementsSPA[sgAbonementsSPA->Row-1];

        VisitsForm = new TVisitsForm(this);
        VisitsForm->ShowModal();
        
        if(VisitsForm->AbsModified)
            sgAbonementsSPAFullUpdate(ClientID);

        delete VisitsForm;
    }
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::meClientsExit(TObject *Sender)
{
    if(sgClients->Row > 0 && Counter > 0 && ClientID && meClients->Modified)
    {
        double dt = (double)Now();

        SQL_iniUpdate(DBName,"Clients",ClientID);
        SQL_addUpdate("#Info",meClients->Lines->Text);
        SQL_addUpdate("EDate",dt);
        SQL_exeUpdate("EUID",UserID);

        meClients->Modified = false;
    }
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::SpeedButton1Click(TObject *Sender)
{
    if(sgClients->Row > 0 && Counter > 0)
    {
        if(!IDs) return;

        ClientID = IDs[sgClients->Row-1];
        AbonementID = 0;
        AbonementSPAID = 0;

        VisitsForm = new TVisitsForm(this);
        VisitsForm->ShowModal();
        delete VisitsForm;
    }
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::laBalanseClick(TObject *Sender)
{
    // ��������� �������
    if(ClientID)
    {
        BalanseForm = new TBalanseForm(this);
        BalanseForm->ClientID = ClientID;
        BalanseForm->ShowModal();
        delete BalanseForm;
    }
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::timSearchTimer(TObject *Sender)
{
    if(edSearchStr->Modified && edSearchStr->Focused())
    {
        edSearchStr->Modified = false;
        sgClientsUpdate();
    }
    else if(edPSearchStr->Modified && edPSearchStr->Focused())
    {
        edPSearchStr->Modified = false;
        sgClientsUpdate();
    }
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::spbClosingSPAClick(TObject *Sender)
{
    // ������������� ���������� SPA

    if(sgClients->Row > 0 && Counter > 0 && sgAbonementsSPA->Row > 0 && CounterAbonementsSPA > 0)
    {
        if(!IDs || !IDsAbonementsSPA) return;

        SQL_BeginTransaction();

        AnsiString sBIID, sBID, sPrice;
        SQL_exefun3(NULL,("select RowID,BillID,Price from BillItems where AbonementID="+AnsiString(IDsAbonementsSPA[sgAbonementsSPA->Row-1])).c_str(),&sBIID,&sBID,&sPrice);
        __int64 BIID, BID;

        BIID = _atoi64(sBIID.c_str());
        BID = _atoi64(sBID.c_str());

        if(!BIID || !BID)
        {
            Application->MessageBox("��������!\n�� ������ ��� ����������, ������������� ����������.","",MB_OK);
            SQL_CancelTransaction();
            return;
        }

        SQL_exefun(NULL,("select Closed from Abonements_SPA where RowID="+AnsiString(IDsAbonementsSPA[sgAbonementsSPA->Row-1])).c_str(),&retString);
        if(atoi(retString.c_str()) != 0)
        {
            SQL_CancelTransaction();
            Application->MessageBox("��������!\n���������� ������������ �������� ���������.","",MB_OK);
            return;
        }

        SQL_exefun(NULL,("select count(*) from Visits_SPA where AbonementID="+AnsiString(IDsAbonementsSPA[sgAbonementsSPA->Row-1])).c_str(),&retString);
        if(atoi(retString.c_str()) != 0)
        {
            SQL_CancelTransaction();
            Application->MessageBox("��������!\n�� ������� ���������� ���� ��������� ������,\n������� ���������� ������������ ��� ������.","",MB_OK);
            return;
        }

        if(Application->MessageBox(("��������!\n����� ����������� ��������� SPA \""+sgAbonementsSPA->Cells[1][sgAbonementsSPA->Row]+"\" �� "+sgAbonementsSPA->Cells[2][sgAbonementsSPA->Row] +"\n����������?").c_str(),"������������� ��������",MB_OKCANCEL) == IDOK)
        {
            // ����� ��������� ���

            SQL_exefun(NULL,("select Total from Bills where RowID="+AnsiString(BID)).c_str(),&retString);

            SQL_iniUpdate(NULL,"Bills",BID);
            SQL_exeUpdate("Total",atof(retString.c_str())-atof(sPrice.c_str()));

            SQL_exe(NULL,("delete from BillItems where RowID="+AnsiString(BIID)).c_str());

            SQL_exe(DBName,("delete from Abonements_SPA where RowID="+(AnsiString)IDsAbonementsSPA[sgAbonementsSPA->Row-1]).c_str());

            SQL_CommitTransaction();

            sgAbonementsSPAFullUpdate(ClientID);
            sgClientsUpdate();
        }
        else
            SQL_CancelTransaction();
    }
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::Panel9MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if(Panel9->BevelOuter == bvRaised)
    {
        Panel9->BevelOuter = bvLowered;
        PostMessage(Panel9->Handle,WM_LBUTTONDOWN,MK_LBUTTON,0);
        return;
    }

    if(lbSPAMenu->Visible)
    {
        Panel9->BevelOuter = bvRaised;
        lbSPAMenu->Visible = false;
        return;
    }

    lbSPAMenu->Selected[0] = true;

    lbSPAMenu->Visible = true;
    lbSPAMenu->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::lbSPAMenuExit(TObject *Sender)
{
    Panel9->BevelOuter = bvRaised;
    lbSPAMenu->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::lbSPAMenuDblClick(TObject *Sender)
{
    Panel9->BevelOuter = bvRaised;
    lbSPAMenu->Visible = false;

    if(lbSPAMenu->Selected[0])
    {
        // ���� ��������� ���������?
        if(!ClientID) return;

        AnsiString sCounter;

        SQL_exefun(DBName,("select count(*) from Abonements_SPA where Closed=0 and ClientID="+AnsiString(ClientID)).c_str(),&sCounter);
        unsigned abs_cnt = atoi(sCounter.c_str());

        if(!abs_cnt)
        {
            Application->MessageBox("��������!\n��� ����������� � ���������� �����������.","������������ ��������",ID_OK);
            return;
        }

        SQL_exefun(DBName,("select first 1 Balanse from Abonements_SPA where Closed=0 and ClientID="+AnsiString(ClientID)+" order by BegDate desc").c_str(),&retString);
        double balanse = atof(retString.c_str());

        FormResult = 0;
        iVisitMode = 1;
        iVisitsForm = new TiVisitsForm(this);
        iVisitsForm->Tag = "SPA";
        iVisitsForm->SPABalanse = balanse;
        iVisitsForm->ShowModal();
        delete iVisitsForm;

        if(FormResult == 1)
        {
            PDEL(IDsAbonementsSPA);
            sgAbonementsSPAFullUpdate(ClientID);
        }
    }
    else if(lbSPAMenu->Selected[1])
    {
        // ���� ��������� ���������?
        if(!ClientID) return;

        AnsiString sCounter;

        SQL_exefun(DBName,("select count(*) from Abonements_SPA where Closed=0 and ClientID="+AnsiString(ClientID)).c_str(),&sCounter);
        unsigned abs_cnt = atoi(sCounter.c_str());

        if(!abs_cnt)
        {
            Application->MessageBox("��������!\n��� ����������� � ���������� �����������.","������������ ��������",ID_OK);
            return;
        }

        SQL_exefun(DBName,("select first 1 Balanse from Abonements_SPA where Closed=0 and ClientID="+AnsiString(ClientID)+" order by BegDate desc").c_str(),&retString);
        double balanse = atof(retString.c_str());

        FormResult = 0;
        iVisitMode = 1;
        BathForm = new TBathForm(this);
        BathForm->SPABalanse = balanse;
        BathForm->ShowModal();
        delete BathForm;

        if(FormResult == 1)
        {
            PDEL(IDsAbonementsSPA);
            sgAbonementsSPAFullUpdate(ClientID);
        }
    }
    else if(lbSPAMenu->Selected[2])
    {
        // ��������������
        if(!ClientID) return;

        AnsiString sCounter;

        SQL_exefun(DBName,("select count(*) from Abonements_SPA where Closed=0 and ClientID="+AnsiString(ClientID)).c_str(),&sCounter);
        unsigned abs_cnt = atoi(sCounter.c_str());

        if(!abs_cnt)
        {
            Application->MessageBox("��������!\n��� ����������� � ���������� �����������.","������������ ��������",ID_OK);
            return;
        }

        SQL_exefun(DBName,("select first 1 Balanse from Abonements_SPA where Closed=0 and ClientID="+AnsiString(ClientID)+" order by BegDate desc").c_str(),&retString);
        double balanse = atof(retString.c_str());

        FormResult = 0;
        iVisitMode = 1;

        BarberForm = new TBarberForm(this);
        BarberForm->SPABalanse = balanse;
        BarberForm->ShowModal();
        delete BarberForm;

        if(FormResult == 1)
        {
            PDEL(IDsAbonementsSPA);
            sgAbonementsSPAFullUpdate(ClientID);
        }
    }
    else if(lbSPAMenu->Selected[3])
    {
        // �����
        if(!ClientID) return;

        AnsiString sCounter;

        SQL_exefun(DBName,("select count(*) from Abonements_SPA where Closed=0 and ClientID="+AnsiString(ClientID)).c_str(),&sCounter);
        unsigned abs_cnt = atoi(sCounter.c_str());

        if(!abs_cnt)
        {
            Application->MessageBox("��������!\n��� ����������� � ���������� �����������.","������������ ��������",ID_OK);
            return;
        }

        SQL_exefun(DBName,("select first 1 Balanse from Abonements_SPA where Closed=0 and ClientID="+AnsiString(ClientID)+" order by BegDate desc").c_str(),&retString);
        double balanse = atof(retString.c_str());

        FormResult = 0;
        iVisitMode = 1;

        NailForm = new TNailForm(this);
        NailForm->SPABalanse = balanse;
        NailForm->ShowModal();
        delete NailForm;

        if(FormResult == 1)
        {
            PDEL(IDsAbonementsSPA);
            sgAbonementsSPAFullUpdate(ClientID);
        }
    }
    else if(lbSPAMenu->Selected[4])
    {
        // ������������
        if(!ClientID) return;

        AnsiString sCounter;

        SQL_exefun(DBName,("select count(*) from Abonements_SPA where Closed=0 and ClientID="+AnsiString(ClientID)).c_str(),&sCounter);
        unsigned abs_cnt = atoi(sCounter.c_str());

        if(!abs_cnt)
        {
            Application->MessageBox("��������!\n��� ����������� � ���������� �����������.","������������ ��������",ID_OK);
            return;
        }

        SQL_exefun(DBName,("select first 1 Balanse from Abonements_SPA where Closed=0 and ClientID="+AnsiString(ClientID)+" order by BegDate desc").c_str(),&retString);
        double balanse = atof(retString.c_str());

        FormResult = 0;
        iVisitMode = 1;

        CosmeticForm = new TCosmeticForm(this);
        CosmeticForm->SPABalanse = balanse;
        CosmeticForm->ShowModal();
        delete CosmeticForm;

        if(FormResult == 1)
        {
            PDEL(IDsAbonementsSPA);
            sgAbonementsSPAFullUpdate(ClientID);
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::lbSPAMenuKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key == VK_RETURN)
    {
        lbSPAMenuDblClick(Sender);

        Key = 0;
    }
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::Panel10MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if(Panel10->BevelOuter == bvRaised)
    {
        Panel10->BevelOuter = bvLowered;
        PostMessage(Panel10->Handle,WM_LBUTTONDOWN,MK_LBUTTON,0);
        return;
    }

    if(lbFitService->Visible)
    {
        Panel10->BevelOuter = bvRaised;
        lbFitService->Visible = false;
        return;
    }

    if(AdminMode && lbFitService->Count == 2)
    {
        lbFitService->Height = 54;
        lbFitService->Items->Add("�����. ����");
    }
    lbFitService->Selected[0] = true;

    lbFitService->Visible = true;
    lbFitService->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::lbFitServiceExit(TObject *Sender)
{
    Panel10->BevelOuter = bvRaised;
    lbFitService->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::lbFitServiceDblClick(TObject *Sender)
{
/*
    Panel10->BevelOuter = bvRaised;
    lbFitService->Visible = false;

    if(lbFitService->Selected[0])
    {
        if(sgClients->Row > 0 && Counter > 0 && sgAbonements->Row > 0 && CounterAbonements > 0)
        {
            if(!IDs || !IDsAbonements) return;

            // ������������� ���������� �������
            AnsiString sBIID, sBID, sPrice;

            SQL_BeginTransaction();

            SQL_exefun3(NULL,("select RowID,BillID,Price from BillItems where AbonementID="+AnsiString(IDsAbonements[sgAbonements->Row-1])).c_str(),&sBIID,&sBID,&sPrice);
            __int64 BIID, BID;

            BIID = _atoi64(sBIID.c_str());
            BID = _atoi64(sBID.c_str());

            if(!BIID || !BID)
            {
                Application->MessageBox("��������!\n�� ������ ��� ����������, ������������� ����������.","",MB_OK);
                SQL_CancelTransaction();
                return;
            }

            SQL_exefun(NULL,("select Closed from Abonements where RowID="+AnsiString(IDsAbonements[sgAbonements->Row-1])).c_str(),&retString);
            if(atoi(retString.c_str()) != 0)
            {
                SQL_CancelTransaction();
                Application->MessageBox("��������!\n���������� ������������ �������� ���������.","",MB_OK);
                return;
            }

            SQL_exefun(NULL,("select count(*) from Visits where AbonementID="+AnsiString(IDsAbonements[sgAbonements->Row-1])).c_str(),&retString);
            if(atoi(retString.c_str()) != 0)
            {
                SQL_CancelTransaction();
                Application->MessageBox("��������!\n�� ������� ���������� ���� ��������� ������,\n������� ���������� ������������ ��� ������.","",MB_OK);
                return;
            }

            if(Application->MessageBox(("��������!\n����� ����������� ��������� ������� \""+sgAbonements->Cells[1][sgAbonements->Row]+"\" �� "+sgAbonements->Cells[2][sgAbonements->Row] +"\n����������?").c_str(),"������������� ��������",MB_OKCANCEL) == IDOK)
            {
                // ����� ��������� ���

                SQL_exefun(NULL,("select Total from Bills where RowID="+AnsiString(BID)).c_str(),&retString);

                SQL_iniUpdate(NULL,"Bills",BID);
                SQL_exeUpdate("Total",atof(retString.c_str())-atof(sPrice.c_str()));

                SQL_exe(NULL,("delete from BillItems where RowID="+AnsiString(BIID)).c_str());

                SQL_exe(DBName,("delete from Abonements where RowID="+(AnsiString)IDsAbonements[sgAbonements->Row-1]).c_str());

                SQL_CommitTransaction();

                sgAbonementsFullUpdate(ClientID);
                sgClientsUpdate();
            }
            else
                SQL_CancelTransaction();
        }

    }
    else if(lbFitService->Selected[1])
    {
        if(sgClients->Row > 0 && Counter > 0 && sgAbonements->Row > 0 && CounterAbonements > 0)
        {
            if(!IDs || !IDsAbonements) return;

            if(Application->MessageBox(("��������!\n����� �������� ���� ���������� \""+sgAbonements->Cells[1][sgAbonements->Row]+"\" �� "+sgAbonements->Cells[2][sgAbonements->Row] +"\n����������?").c_str(),"������������� ��������",MB_OKCANCEL) == IDOK)
            {
                DTI_BegDate = sgAbonements->Cells[2][sgAbonements->Row];
                DTI_EndDate = sgAbonements->Cells[3][sgAbonements->Row];
                FormResult = 0;
                DateIntervalForm = new TDateIntervalForm(this);
                DateIntervalForm->ShowModal();
                delete DateIntervalForm;
                if(FormResult == 1)
                {
                    SQL_iniUpdate(DBName,"Abonements",IDsAbonements[sgAbonements->Row-1]);
                    SQL_addUpdate("BegDate",(int)DTI_BegDate);
                    SQL_addUpdate("EndDate",(int)DTI_EndDate);
                    SQL_exeUpdate("Closed",0);

                    sgAbonementsFullUpdate(ClientID);
                }
            }
        }
    }
    else if(lbFitService->Selected[2])
    {
        if(sgClients->Row > 0 && Counter > 0 && sgAbonements->Row > 0 && CounterAbonements > 0)
        {
            if(!IDs || !IDsAbonements) return;
            AnsiString *pV;

            int vcnt = SQL_fldCollect(DBName,"RowID",("from Visits where AbonementID="+AnsiString(IDsAbonements[sgAbonements->Row-1])+" order by CDate desc").c_str(),&pV);

            if(vcnt <= 0)
            {
                delete [] pV;
                return;
            }
            // ������ ����������
            AnsiString sql = "select first 1 RowID from Abonements where ClientID=";
            sql += ClientID;
            sql += " and EndDate<";
            sql += (double)TDateTime(sgAbonements->Cells[2][sgAbonements->Row]);
            sql += " order by EndDate desc";

            SQL_exefun(DBName,sql.c_str(),&retString);

            __int64 ID = _atoi64(retString.c_str());
            if(!ID)
            {
                delete [] pV;
                return;
            }

            SQL_exefun(DBName,("select count(*) from Visits where AbonementID="+AnsiString(ID)).c_str(),&retString);
            int visits = atoi(retString.c_str());

            SQL_exefun(DBName,("select AbonementsCount from Abonements where RowID="+AnsiString(ID)).c_str(),&retString);
            int count = atoi(retString.c_str());

            int cnt = count - visits;
            if(cnt <= 0)
            {
                delete [] pV;
                return;
            }

            if(Application->MessageBox(("��������!\n����� �������� ��������� ���������� \""+sgAbonements->Cells[1][sgAbonements->Row]+"\" �� "+sgAbonements->Cells[2][sgAbonements->Row] +"\n����������?").c_str(),"������������� ��������",MB_OKCANCEL) == IDOK)
            {
                int i = 0;
                SQL_BeginTransaction();
                while(cnt-- && vcnt--)
                {
                    SQL_exe(DBName,("update Visits set AbonementID="+AnsiString(ID)+" where RowID="+pV[i++]).c_str());
                }
                SQL_CommitTransaction();
                sgAbonementsFullUpdate(ClientID);
            }

            delete [] pV;
        }
    }
*/
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::lbFitServiceKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
    if(Key == VK_RETURN)
    {
        lbFitServiceDblClick(Sender);

        Key = 0;
    }
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgNotesDrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
    sgDrawCell(Sender,ACol,ARow,Rect,State,fldAlignNotes,false,NULL,clFuchsia,TFontStyles()<<fsBold);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::meNoteExit(TObject *Sender)
{
    if(sgClients->Row > 0 && Counter > 0 && ClientID && meNote->Modified)
    {
        double dt = (double)Now();

        SQL_iniUpdate(DBName,"Clients",ClientID);
        SQL_addUpdate("#Note",meNote->Lines->Text);
        SQL_addUpdate("EDate",dt);
        SQL_exeUpdate("EUID",UserID);

        meNote->Modified = false;

        NotesUpdate(&ClientID,0);
    }
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgReserveDrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
    sgDrawCell(Sender,ACol,ARow,Rect,State,fldAlignReserve,ReserveIDs != NULL,ilClients);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::SpeedButton4Click(TObject *Sender)
{
    if(!ClientID || !ReserveCounter || sgReserve->Cells[0][sgReserve->Row].Length() > 0) return;

    SQL_exefun(DBName,("select FitGroupID from Reserve where RowID="+AnsiString(ReserveIDs[sgReserve->Row-1])).c_str(),&retString);
    if(_atoi64(retString.c_str()) != 0)
    {
        TDateTime dt(sgReserve->Cells[1][sgReserve->Row]+" "+sgReserve->Cells[2][sgReserve->Row]);

        // �������� ��� ��������?
        unsigned short h, m, s, ms;
        dt.DecodeTime(&h,&m,&s,&ms);
        //RoundTimeParts(h,m,s,ms);

        TDateTime dtn = Now();

        if(h < 17)
        {
            // �� 21:00 ����������� ���
            if((int)dtn > (int)dt) return;

            if((int)dtn == (int)dt)
            {
                Application->MessageBox("��������!\n���������� �������� ������!","",MB_OK);
                return;
            }
        }
        else
        {
            // �� 12:00 �������� ���
            if((int)dtn > (int)dt) return;

            if((int)dtn == (int)dt)
            {
                dtn.DecodeTime(&h,&m,&s,&ms);
                if(h >= 12)
                {
                    Application->MessageBox("��������!\n���������� �������� ������!","",MB_OK);
                    return;
                }
            }
        }
    }

    // ����� ���� ������
    retString = ReserveIDs[sgReserve->Row-1];

    SQL_BeginTransaction();

    SQL_exe(NULL,("delete from Reserve where RowID="+retString+" or ParentID="+retString).c_str());
    //SQL_exe(NULL,("delete from Reserve where RowID="+AnsiString(ReserveIDs[sgReserve->Row-1])).c_str());

    SQL_CommitTransaction();

    sgReserveFullUpdate();
    sgFitSheduleFullUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sbResClick(TObject *Sender)
{
    if(!ClientID || !ReserveCounter || sgReserve->Cells[0][sgReserve->Row].Length() > 0) return;
    __int64 RID = ReserveIDs[sgReserve->Row-1];

    if(!RID) return;

    double dt = (double)TDateTime(sgReserve->Cells[1][sgReserve->Row]+" "+sgReserve->Cells[2][sgReserve->Row]);

    // �� ����� 15 �����
    if(dt + (15.0 / 1440.0) < (double)Now())
    {
        Application->MessageBox("��������!\n�������� ����������, ������� ����������� �����!","",MB_OK);
        return;
    }

    dt = Now();
    //-

    // ����� ����������


    // ������� ��� ���?

    SQL_exefun(DBName,("select Tag from Reserve,Services where ServiceID=Services.RowID and Reserve.RowID="+AnsiString(RID)).c_str(),&retString);
    //retString = (retString);

    AnsiString Tag = retString;

    /*
    if(Tag.Pos("~����~") > 0)
    {
        // �������� �� ����, �.�. ����������� ������
        // ���� ��������� ���������?

        AnsiString sFixSum, sCounter;

        SQL_exefun(DBName,("select count(*) from Abonements_Bath where Closed=0 and Balanse>0 and ClientID="+AnsiString(ClientID)).c_str(),&sCounter);
        unsigned abs_cnt = atoi(sCounter.c_str());

        if(!abs_cnt)
        {
            Application->MessageBox("��������!\n��� ����������� � ���������� �����������.","������������ ��������",ID_OK);
            return;
        }

        // ����� �����
        AnsiString *pRow, sRow[5];

        SQL_BeginTransaction();

        SQL_exefunrow(NULL,("select ServiceID,PersonID,BegDate,EndDate,QUAN from Reserve where RowID="+AnsiString(RID)).c_str(),5,sRow);

        __int64 ID, SID = _atoi64(sRow[0].c_str());
        double bt, et, price, pprice;
        unsigned cnt = atoi(sRow[4].c_str());

        if(SID && cnt)
        {
            double total = 0.0;

            SQL_exe(NULL,("delete from BillItems where BillID="+AnsiString(KassaBillID)).c_str());

            if(SID != BATH_COMPLEXID)
            {
                pRow = sRow;
                cnt = 1;
            }
            else
            {
                // ����������

                const char *pFNames[] = { "ServiceID", "PersonID", "BegDate", "EndDate", "QUAN" };


                cnt = SQL_Collect(NULL,5,pFNames,("from Reserve where ParentID="+AnsiString(RID)).c_str(),"",&pRow);
            }

            for(unsigned i = 0; i < cnt; i++)
            {
                unsigned ncnt, j = (i << 2) + i;

                SID = _atoi64(pRow[j].c_str());
                ncnt = atoi(pRow[j+4].c_str());

                bt = atof(pRow[j+2].c_str());
                et = atof(pRow[j+3].c_str());

                if(!GetSPAServicePrice(&price,&pprice,SID,ncnt,SimpleRoundTo(1440.0 * (et - bt),0)))
                {
                    price *= ncnt;
                    pprice *= ncnt;
                }

                SQL_iniInsert(DBName,"BillItems",&ID);
                SQL_addInsert("BillID",KassaBillID);
                SQL_addInsert("ServiceID",SID);
                SQL_addInsert("PersonID",_atoi64(pRow[j+1].c_str()));
                SQL_addInsert("BillItemsDate",(int)Now());
                SQL_addInsert("BegTime",bt);
                SQL_addInsert("EndTime",et);
                SQL_addInsert("Price",price);
                SQL_addInsert("PersonPrice",pprice);
                SQL_addInsert("BillItemsCount",ncnt);

                SQL_addInsert("Discount",UserDiscountSPA);

                SQL_addInsert("Total",price);

                SQL_exeInsert("Op",64);

                total += price;

                __int64 VSID;

                // Visits_SPA

                SQL_iniInsert(DBName,"Visits_SPA",&VSID);

                // �����! ���� ����� � ��������, ��� ��� ����������
                SQL_addInsert("ClientID",ClientID);
                SQL_addInsert("Visits_SPADate",(double)bt);

                SQL_addInsert("BegTime",bt);
                SQL_addInsert("EndTime",et);

                SQL_addInsert("PersonID",_atoi64(pRow[j+1].c_str()));
                SQL_addInsert("ServiceID",SID);
                SQL_addInsert("Price",price);
                SQL_addInsert("PersonPrice",pprice);
                SQL_addInsert("GroupCnt",ncnt);
                SQL_addInsert("CDate",(double)dt);
                SQL_addInsert("CUID",UserID);
                SQL_addInsert("EDate",(double)dt);
                SQL_exeInsert("EUID",UserID);

                // �������� ����������
                AnsiString *pGoods;
                const char *pF[] = { "GoodID", "Rate" };

                unsigned gcnt = SQL_Collect(DBName,2,pF,("from ServiceGoods where ServiceID="+AnsiString(SID)).c_str(),NULL,&pGoods);

                if(gcnt)
                {
                    __int64 GID;
                    AnsiString sStock[3];

                    for(unsigned j = 0; j < gcnt; j++)
                    {
                        SQL_exefunrow(DBName,("select first 1 RowID,StockCount,Part from Stock where GoodID="+pGoods[j<<1]).c_str(),3,sStock);
                        GID = _atoi64(sStock[0].c_str());

                        int rate = -atoi(pGoods[(j<<1)+1].c_str()) * ncnt;
                        int count = atoi(sStock[1].c_str());
                        int part = atoi(sStock[2].c_str());

                        SQL_iniInsert(DBName,"Outcome");
                        SQL_addInsert("Visit_SPAID",VSID);
                        SQL_addInsert("GoodID",pGoods[j<<1]);
                        SQL_addInsert("ServiceID",SID);
                        SQL_addInsert("OutcomeCount",rate / 1000);
                        SQL_exeInsert("Part",rate % 1000);

                        if(GID)
                        {
                            // ���� �������
                            rate = 1000 * count + part + rate;
                            part = rate % 1000;
                            count = rate / 1000;

                            SQL_iniUpdate(DBName,"Stock",GID);
                            SQL_addUpdate("StockCount",count);
                            SQL_exeUpdate("Part",part);
                        }
                        else
                        {
                            // ������ ���
                            part = rate % 1000;
                            count = rate / 1000;

                            SQL_iniInsert(DBName,"Stock");
                            SQL_addInsert("GoodID",_atoi64(pGoods[j<<1].c_str()));
                            SQL_addInsert("StockCount",count);
                            SQL_exeInsert("Part",part);
                        }
                    }

                    delete [] pGoods;
                }
            }

            if(pRow != sRow)
                delete [] pRow;

            SQL_iniInsert(DBName,"Bills",&ID);
            SQL_addInsert("ClientID",ClientID);
            SQL_addInsert("BegBalanse",UserBalanse);
            SQL_addInsert("FromBalanse",0);
            SQL_addInsert("ToBalanse",0);
                //if(spbPayment->Caption == "�/�")
                //    SQL_addInsert("Payment",1);
            SQL_addInsert("EndBalanse",UserBalanse);
            SQL_addInsert("GetSum",0);
            SQL_addInsert("Change",0);
            SQL_addInsert("Total",total);
            SQL_addInsert("CDate",(double)dt);
            SQL_addInsert("CUID",UserID);
            SQL_addInsert("EDate",(double)dt);

            SQL_exeInsert("EUID",UserID);

            // ������� �������
            SQL_exe(NULL,("update BillItems set BillID="+AnsiString(ID)+" where BillID="+AnsiString(KassaBillID)).c_str());

            SQL_iniUpdate(DBName,"Reserve",ReserveIDs[sgReserve->Row-1]);
            SQL_exeUpdate("Status",2);

            SQL_CommitTransaction();

            PDEL(IDsAbonements);
            sgClientsRowInfo(&ClientID,0);

        }

        return;
    }
    */



    /* ���� - ������ ����
    if(Tag.Pos("~����~") > 0)
    {
        // ���� ��������� ���������?

        AnsiString sCounter;

        SQL_exefun(DBName,("select count(*) from Abonements_Bath where Closed=0 and Balanse>0 and ClientID="+AnsiString(ClientID)).c_str(),&sCounter);
        unsigned abs_cnt = atoi(sCounter.c_str());

        if(!abs_cnt)
        {
            Application->MessageBox("��������!\n��� ����������� � ���������� �����������.","������������ ��������",ID_OK);
            return;
        }

        // ��������� �������� �� ����� ����������� ���������
        AnsiString pRow[2];
        SQL_exefunrow(DBName,("select first 1 RowID,Balanse from Abonements_Bath where Closed=0 and Balanse>0 and ClientID="+(AnsiString)ClientID+" order by RowID desc").c_str(),2,pRow);
        //SQL_exefun(DBName,("select RowID from Abonements_Bath where Closed=0 and Balanse>0 and EndDate>="+AnsiString((int)Now())+" and ClientID="+AnsiString(ClientID)).c_str(),&sCounter);
        __int64 AbID = _atoi64(pRow[0].c_str());

        if(!AbID)
        {
            Application->MessageBox("��������!\n������� ��������� ���������. ��� ��� ��������� ����� ���������� ��������� ���������.","������������ ��������",ID_OK);
            return;
        }
        //-----------------------------------------------------
        if(SQL_BeginTransaction() != SQLITE_OK) return;

        //unsigned __fastcall SQL_Collect(const char *,unsigned fld_cnt,const char **fNames,
        //const char *sql_from,const char *sql_order,AnsiString ** pFld,char *mask=NULL);

        AnsiString *pRowRes;
        const char *fNames[] = { "BegDate", "EndDate", "ServiceID", "PersonID", "ClientID", "ParentID", "Num", "Quan", "Total" };

        abs_cnt = SQL_Collect(DBName,9,fNames,
            ("from Reserve where RowID="+AnsiString(RID)+" or ParentID="+AnsiString(RID)).c_str(),
            "",
            &pRowRes
        );


        //SQL_exe
        //(DBName,("select BegDate,EndDate,ServiceID,PersonID from Reserve where RowID="+AnsiString(RID)+" or ParentID="+AnsiString(RID)).c_str(),4,pRowRes);
        TDateTime bd, ed;
        double x;
        unsigned pos;

        for(unsigned i = 0; i < abs_cnt; i++)
        {
            pos = i * 9;

            SQL_iniInsert(DBName,"Visits_Bath");
            SQL_addInsert("AbonementID",AbID);
            SQL_addInsert("ParentID",_atoi64(pRowRes[pos+5].c_str()));
            SQL_addInsert("ClientID",_atoi64(pRowRes[pos+4].c_str()));
            SQL_addInsert("PersonID",_atoi64(pRowRes[pos+3].c_str()));
            SQL_addInsert("ServiceID",_atoi64(pRowRes[pos+2].c_str()));

            bd = atof(pRowRes[pos].c_str());
            ed = atof(pRowRes[pos+1].c_str());

            SQL_addInsert("Visits_BathDate",(int)bd);
            SQL_addInsert("BegTime",modf(bd,&x));
            SQL_addInsert("EndTime",modf(ed,&x));

            SQL_addInsert("Num",atoi(pRowRes[pos+6].c_str()));

            int quan = atoi(pRowRes[pos+7].c_str());

            if(quan)
                SQL_addInsert("Price",atof(pRowRes[pos+8].c_str())/quan);
            else
                SQL_addInsert("Price",atof(pRowRes[pos+8].c_str()));

            SQL_addInsert("Total",atof(pRowRes[pos+8].c_str()));

            SQL_exeInsert("GroupCnt",quan);

        }




        SQL_iniUpdate(DBName,"Reserve",ReserveIDs[sgReserve->Row-1]);
        SQL_exeUpdate("Status",2);

        if(SQL_CommitTransaction() == SQLITE_OK)
        {
            PDEL(IDsAbonements);
            sgAbonementsFullUpdate(ClientID);
            sgReserveFullUpdate();
            sgFitSheduleFullUpdate();
        }
    }
    */

    if(Tag.Pos("~�������~") > 0)
    {


        // ���� ��� �������-������ �� ������ ���� ���������
        // ���� ��������� ���������?

        AnsiString sFixSum, sCounter;

        SQL_exefun(DBName,("select count(*) from Abonements where Closed=0 and FixSum>=0 and ClientID="+AnsiString(ClientID)).c_str(),&sCounter);
        unsigned abs_cnt = atoi(sCounter.c_str());

        if(!abs_cnt)
        {
            Application->MessageBox("��������!\n��� ����������� � ���������� �����������.","������������ ��������",ID_OK);
            return;
        }

        SQL_exefun(DBName,("select first 1 FixSum from Abonements where Closed=0 and FixSum>=0 and ClientID="+AnsiString(ClientID)+" order by BegDate,CDate").c_str(),&sFixSum);

        if(atof(sFixSum.c_str()) == 0.0)
        {
            // ��������� �������� �� ����� ����������� ���������
            SQL_exefun(DBName,("select count(*) from Abonements where Closed=0 and FixSum>=0 and EndDate>="+AnsiString((int)Now())+" and ClientID="+AnsiString(ClientID)).c_str(),&sCounter);
            abs_cnt = atoi(sCounter.c_str());

            if(!abs_cnt)
            {

                Application->MessageBox("��������!\n������� ��������� ���������. ��� ��� ��������� ����� ���������� ��������� ���������.","������������ ��������",ID_OK);
                return;
            }
        }

        //-----------------------------------------------------
        AnsiString pRowRes[4];
        SQL_exefunrow(DBName,("select BegDate,EndDate,ServiceID,PersonID from Reserve where RowID="+AnsiString(RID)).c_str(),4,pRowRes);


        // �������� ������ ���������
        if(SQL_BeginTransaction() != SQLITE_OK) return;

        AnsiString pRow[4];
        SQL_exefunrow(DBName,("select first 1 RowID,Price,AbonementsCount,FixSum from Abonements where Closed=0 and FixSum>=0 and ClientID="+(AnsiString)ClientID+" order by BegDate,CDate").c_str(),4,pRow);

        __int64 AbID = _atoi64(pRow[0].c_str());

        double price = atof(pRow[1].c_str());
        unsigned count = atoi(pRow[2].c_str());
        double fixsum = atof(pRow[3].c_str());

        SQL_iniInsert(DBName,"Visits");
        SQL_addInsert("AbonementID",AbID);

        TDateTime bd = atof(pRowRes[0].c_str());
        TDateTime ed = atof(pRowRes[1].c_str());
        double x;

        SQL_addInsert("VisitsDate",(int)bd);
        SQL_addInsert("BegTime",modf(bd,&x));

        SQL_addInsert("EndTime",modf(ed,&x));

        if(fixsum > 0.0)
            SQL_addInsert("Price",fixsum);
        else
        {
            if(count != 0.0)
                SQL_addInsert("Price",price/count);
            else
            {
                SQL_CancelTransaction();
                Application->MessageBox("��������!\n���-�� ������� ����� 0.","������ ��",MB_OK);

                return;
            }
        }

        SQL_addInsert("PersonID",pRowRes[3]);
        SQL_addInsert("ServiceID",pRowRes[2]);
        dt = Now();
        SQL_addInsert("CDate",(double)dt);
        SQL_addInsert("CUID",UserID);
        SQL_addInsert("EDate",(double)dt);

        SQL_exeInsert("EUID",UserID);

        price -= fixsum;

        if(count == 1 && fixsum != 0.0 && price > 0.0)
        {
            // ������� ������� �� �������
            SQL_exefun(DBName,"select RowID from Services where Name='�������'",&retString);
            __int64 ID = _atoi64(retString.c_str());
            if(!ID)
            {
                SQL_CancelTransaction();
                Application->MessageBox("��������!\n�� ������� ������ �������.","������ ��",MB_OK);
                //FormResult = 1;

                return;
            }

            SQL_iniInsert(DBName,"Visits");
            SQL_addInsert("AbonementID",AbID);

            SQL_addInsert("VisitsDate",(int)bd);
            SQL_addInsert("BegTime",modf(bd,&x));
            SQL_addInsert("EndTime",modf(ed,&x));
            SQL_addInsert("Price",price);
            SQL_addInsert("PersonID",0);
            SQL_addInsert("ServiceID",ID);

            SQL_addInsert("CDate",(double)dt);
            SQL_addInsert("CUID",UserID);
            SQL_addInsert("EDate",(double)dt);
            SQL_exeInsert("EUID",UserID);
        }

        SQL_iniUpdate(DBName,"Reserve",ReserveIDs[sgReserve->Row-1]);
        SQL_exeUpdate("Status",2);

        if(SQL_CommitTransaction() == SQLITE_OK)
        {
            PDEL(IDsAbonements);
            sgAbonementsFullUpdate(ClientID,AbID);
            sgReserveFullUpdate(RID);
            sgFitSheduleFullUpdate();
        }
    }
    else
    {
        SpisFromSPA(RID,Tag.Pos("~����~") > 0);

        //PDEL(IDsAbonements);
        //sgAbonementsFullUpdate(ClientID,AbID);
        //sgReserveFullUpdate(RID);
        //sgFitSheduleFullUpdate();
    }
    /*
    else
    {
        //ClientID = IDs[sgClients->Row-1];
        BillsID = 0;

        AnsiString pRowRes[5];
        SQL_exefunrow(DBName,("select BegDate,EndDate,ServiceID,PersonID,Quan from Reserve where RowID="+AnsiString(RID)).c_str(),5,pRowRes);

        KassaForm = new TKassaForm(this);
        KassaForm->ResBegDate = atof(pRowRes[0].c_str());
        KassaForm->ResEndDate = atof(pRowRes[1].c_str());
        KassaForm->ResServiceID = _atoi64(pRowRes[2].c_str());
        KassaForm->ResPersonID = _atoi64(pRowRes[3].c_str());
        KassaForm->ResQuan = atoi(pRowRes[4].c_str());

        KassaForm->ShowModal();
        if(FormResult == -1)
        {
            SQL_iniUpdate(DBName,"Reserve",ReserveIDs[sgReserve->Row-1]);
            SQL_exeUpdate("Status",2);

            PDEL(IDsAbonements);
            sgClientsRowInfo(&ClientID,0);
        }

        delete KassaForm;
    }
    */
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::SpisFromSPA(__int64 RID,bool bath,bool forcash)
{
    {
        // ���� ��� ���� � ��� ����������

        SQL_exefun(DBName,("select count(*) from Abonements_SPA where Closed=0 and Balanse>0 and ClientID="+AnsiString(ClientID)).c_str(),&retString);
        unsigned abs_cnt = atoi(retString.c_str());

        if(!abs_cnt && !forcash)
        {
            Application->MessageBox("��������!\n��� ����������� SPA � ��������� ������.","������������ ��������",ID_OK);
            return;
        }

        // ��������� �������� �� ����� ����������� ���������
        AnsiString pRow[2];
        SQL_exefunrow(DBName,("select first 1 RowID,Balanse from Abonements_SPA where Closed=0 and Balanse>0 and ClientID="+(AnsiString)ClientID+" order by RowID desc").c_str(),2,pRow);
        __int64 AbID = _atoi64(pRow[0].c_str());

        if(!AbID && !forcash)
        {
            Application->MessageBox("��������!\n������� ��������� SPA ���������. ��� ��� ��������� ����� ���������� ��������� ���������.","������������ ��������",ID_OK);
            return;
        }
        //-----------------------------------------------------


        if(SQL_BeginTransaction() != SQLITE_OK) return;

        //unsigned __fastcall SQL_Collect(const char *,unsigned fld_cnt,const char **fNames,
        //const char *sql_from,const char *sql_order,AnsiString ** pFld,char *mask=NULL);

        AnsiString *pRowRes;
        const char *fNames[] = { "BegDate", "EndDate", "ServiceID", "PersonID", "ClientID", "ParentID", "Num", "Quan", "Price" };

        SQL_exefun(NULL,("select Price from Reserve where RowID="+AnsiString(RID)).c_str(),&retString);
        double bathdisprice = ATOF(retString.c_str()), bathprice = 0;

        unsigned quan, pos;
        double pprice, x, total = 0;
        unsigned short h = 0, m, s, ms;
        double bathtime, bathprice1, bathprice2;


        if(bath)
        {
            abs_cnt = SQL_Collect(DBName,9,fNames,
            (
                "from Reserve where ParentID="+AnsiString(RID)).c_str(),
                "order by 4",
                &pRowRes
            );

            // ����� ����� ���. ������/��������� ���� ���� - 196
            //quan = ATOI(pRowRes[pos+7].c_str());
            //if(!quan) quan++;

            for(unsigned i = 0; i < abs_cnt; i++)
            {
                pos = i * 9;

                if(_atoi64(pRowRes[pos + 2].c_str()) == BATH_COMPLEXID) continue;

                if(_atoi64(pRowRes[pos + 2].c_str()) == BATH_ID)
                {
                    TDateTime(ATOF(pRowRes[pos+1].c_str()) - ATOF(pRowRes[pos].c_str())).DecodeTime(&h,&m,&s,&ms);
                    bathtime = SimpleRoundTo((double)h + (double)m / 60, -1);
                    bathprice = ATOF(pRowRes[pos+8].c_str()) * bathtime;
                }
                else
                    total += ATOF(pRowRes[pos + 8].c_str());
            }
        }
        else
        {
            abs_cnt = SQL_Collect(DBName,9,fNames,
            (
                "from Reserve where RowID="+AnsiString(RID)).c_str(),
                "order by 4",
                &pRowRes
            );

            quan = ATOI(pRowRes[7].c_str());
            if(!quan) quan++;
            // ������ ��� 1 / (24 * 60)

            TDateTime(atof(pRowRes[1].c_str()) - atof(pRowRes[0].c_str())).DecodeTime(&h,&m,&s,&ms);
            //RoundTimeParts(h,m,s,ms)

            GetSPAServicePrice(&total,&pprice,_atoi64(pRowRes[2].c_str()),quan,m,false);
        }
        // ��� �����, ������ �� �����?
        double balanse = atof(pRow[1].c_str());


        //if(UserDiscountSPA <= 0) x = 1;
        //else x = (100 - UserDiscountSPA) / 100.0;

        // ������ �� SPA ��� ������ ������ �� ����?
        // bathprice - �� ��������
        // bathdisprice - ��������, � ��� ���� ����� ����������
        bathprice1 = bathprice;
        bathprice2 = bathdisprice;

        double bprice1 = bathprice;
        double bprice2 = bathdisprice;

        //if(bath)
        // �.�. ������ ��� ����������
        //AnsiString sDis, sDisSPA;
        //SQL_exefun2(NULL,("select Discount,DiscountSPA from Clients where RowID="+AnsiString(ClientID)).c_str(),&sDis,&sDisSPA);
        double discount;

        //discount = atof(sDisSPA.c_str());
        discount = UserDiscountSPA;
        if(discount <= 0) discount = UserDiscount;
        //atof(sDis.c_str());

        int dtnow = (int)Now();
        SQL_exefun(NULL,("select count(*) from Abonements where Closed=0 and EndDate>="+AnsiString(dtnow)+" and ClientID="+AnsiString(ClientID)).c_str(),&retString);
        dtnow = ATOI(retString.c_str());

        if(dtnow > 0) dtnow = 10;

        if(discount < dtnow) discount = dtnow;

        if(discount <= 0) x = 1;
        else x = (100 - discount) / 100.0;
        //}
        //else
        //    x = 1;

        //double bathprice1, bathprice2;

        //bathprice1 = bathprice;
        //bathprice2 = bathdisprice;
        double bathdiscount;

        bathprice = (bathprice + total) * x;
        bathdisprice += total;  // ������ �� ������

        if(bathprice <= bathdisprice)
        {
            bathprice1 *= x;
            bathdiscount = (1 - x) * 100; // ������� ������

            x = bathprice;
            bprice2 = 0;


        }
        else
        {
            bathprice1 = bathprice2;    // ����������� ������, ����������
            bathdiscount = 0;

            x = bathdisprice;
            bprice1 = 0;


        }
        //x = (bathprice <= bathdisprice)? bathprice : bathdisprice;

        if(balanse < x && !forcash)
        {
            Application->MessageBox(("��������!\n�� ���������� SPA �� ���������� �������. �������� �������� ������ �� ���. ������.\n���������: "+FormatFloat(MoneyFormat,bathprice).TrimLeft() + " ���., ���. ������: "+FormatFloat(MoneyFormat,bathdisprice).TrimLeft() + " ���.").c_str(),"������������ ��������",ID_OK);
            SQL_CancelTransaction();
            return;
        }

        // ����� ������������ bathdisprice
        bathdisprice = x;

        //SQL_exe
        //(DBName,("select BegDate,EndDate,ServiceID,PersonID from Reserve where RowID="+AnsiString(RID)+" or ParentID="+AnsiString(RID)).c_str(),4,pRowRes);
        __int64 SID, CID, VisitID;
        TDateTime dt = Now();
        double bd, ed;

        __int64 BID;
        AnsiString *pGoods;
        const char *pF[] = { "GoodID", "Rate" };

        if(forcash)
            SQL_exe(NULL,("delete from BillItems where BillID="+AnsiString(KassaBillID)).c_str());

        for(unsigned i = 0; i < abs_cnt; i++)
        {
            pos = i * 9;

            CID = _atoi64(pRowRes[pos+4].c_str());
            SID = _atoi64(pRowRes[pos+2].c_str());

            quan = atoi(pRowRes[pos+7].c_str());
            if(!quan) quan++;

            SQL_iniInsert(DBName,"Visits_SPA",&VisitID);
            if(!forcash)
                SQL_addInsert("AbonementID",AbID);

            if(bath)
                SQL_addInsert("ParentID",RID);

            SQL_addInsert("ClientID",CID);
            SQL_addInsert("PersonID",_atoi64(pRowRes[pos+3].c_str()));

            SQL_addInsert("ServiceID",SID);

            bd = atof(pRowRes[pos].c_str());
            ed = atof(pRowRes[pos+1].c_str());

            SQL_addInsert("Visits_SPADate",(int)bd);
            SQL_addInsert("BegTime",modf(bd,&x));
            SQL_addInsert("EndTime",modf(ed,&x));

            SQL_addInsert("Num",ATOI(pRowRes[pos+6].c_str()));



            //if(SID == BATH_COMPLEXID)
            //    x = 0;
            if(SID == BATH_ID)
            {
                total = bathdisprice;

                //x = bathdisprice;
            }
            else if(bath)
            {
               // � ������?
                total = ATOF(pRowRes[pos+8].c_str());
                if(bprice2 == 0.0)
                    total = ((100 - discount) * total) / 100;
            }
            else
                total = bathdisprice;

            SQL_addInsert("Price",total);

            if(bath)
            {
                if(SID != BATH_ID)
                {
                    AnsiString sPrice,sGroup, sGroupLen;
                    SQL_exefun2(DBName,(AnsiString("select PersonPrice,Price from Services where RowID=")+pRowRes[pos+2]).c_str(),&retString,&sPrice);
                    SQL_exefun2(DBName,(AnsiString("select GroupPrice,IsGroup from Services where RowID=")+pRowRes[pos+2]).c_str(),&sGroup,&sGroupLen);
                    if(ATOI(sGroupLen.c_str()) > 0)
                    {
                        x = GroupAnalyze(sGroup,ATOI(pRowRes[pos+7].c_str())) - ATOF(sPrice.c_str());
                    }
                    else
                        x = ATOF(retString.c_str());
                }
                else
                    x = 0;
            }
            else
                x = pprice;

            // � ������ �� PersonPrice?
            if(bprice2 == 0.0)
                x = ((100 - discount) * x) / 100;

            pprice = x;

            SQL_addInsert("PersonPrice",pprice);

            SQL_addInsert("GroupCnt",quan);

            SQL_addInsert("CDate",(double)dt);
            SQL_addInsert("CUID",UserID);
            SQL_addInsert("EDate",(double)dt);

            if(!forcash)
            {
                SQL_exeInsert("EUID",UserID);

                // �������� ����������
                unsigned gcnt = SQL_Collect(DBName,2,pF,("from ServiceGoods where ServiceID="+pRowRes[pos+2]).c_str(),NULL,&pGoods);

                if(gcnt)
                {
                    __int64 GID;
                    AnsiString sStock[3];

                    for(unsigned j = 0; j < gcnt; j++)
                    {
                        SQL_exefunrow(DBName,("select first 1 RowID,StockCount,Part from Stock where GoodID="+pGoods[j<<1]).c_str(),3,sStock);
                        GID = _atoi64(sStock[0].c_str());

                        int rate = -atoi(pGoods[(j<<1)+1].c_str());
                        int count = atoi(sStock[1].c_str());
                        int part = atoi(sStock[2].c_str());

                        SQL_iniInsert(DBName,"Outcome");
                        SQL_addInsert("Visit_SPAID",VisitID);
                        SQL_addInsert("GoodID",pGoods[j<<1]);
                        SQL_addInsert("ServiceID",SID);
                        SQL_addInsert("OutcomeCount",rate / 1000);
                        SQL_exeInsert("Part",rate % 1000);

                        if(GID)
                        {
                            // ���� �������
                            rate = 1000 * count + part + rate;
                            part = rate % 1000;
                            count = rate / 1000;

                            SQL_iniUpdate(DBName,"Stock",GID);
                            SQL_addUpdate("StockCount",count);
                            SQL_exeUpdate("Part",part);
                        }
                        else
                        {
                            // ������ ���
                            part = rate % 1000;
                            count = rate / 1000;

                            SQL_iniInsert(DBName,"Stock");
                            SQL_addInsert("GoodID",_atoi64(pGoods[j<<1].c_str()));
                            SQL_addInsert("StockCount",count);
                            SQL_exeInsert("Part",part);
                        }
                    }

                    delete [] pGoods;
                }
            }
            else
            {

                // ���
                // SQL_addInsert("Num",ATOI(pRowRes[pos+6].c_str())); - ��� Num
                // CID - ������ ��� �������!


                //SQL_exefun(NULL,("select Balanse from Clients where RowID="+AnsiString(CID)).c_str(),&retString);
                //x = ATOF(retString.c_str());

                /* Bill */
                //SQL_iniInsert(DBName,"Bills",&BID);
                //SQL_addInsert("ClientID",CID);
                //SQL_addInsert("BegBalanse",x);
                //SQL_addInsert("FromBalanse",0);
                //SQL_addInsert("ToBalanse",0);

                //SQL_addInsert("EndBalanse",x);
                //SQL_addInsert("GetSum",0);
                //SQL_addInsert("Change",0);

                //SQL_addInsert("Total",total);

                //SQL_addInsert("CDate",(double)dt);
                //SQL_addInsert("CUID",UserID);
                //SQL_addInsert("EDate",(double)dt);
                //SQL_exeInsert("EUID",UserID);

                //----------------------------------------------------------------------
                // BillItems
                //----------------------------------------------------------------------
                //{ "BegDate", "EndDate", "ServiceID", "PersonID", "ClientID", "ParentID", "Num", "Quan", "Price" };

                SQL_iniInsert(DBName,"BillItems");
                SQL_addInsert("DiscountID",CID);
                SQL_addInsert("BillID",KassaBillID);
                SQL_addInsert("ServiceID",SID);
                SQL_addInsert("PersonID",pRowRes[pos+3]);
                SQL_addInsert("BillItemsDate",(int)dt);
                SQL_addInsert("BegTime",bd);
                SQL_addInsert("EndTime",ed);

                if(SID == BATH_ID)
                {
                    // ����� ��� ����
                    SQL_addInsert("GoodID",ATOI(pRowRes[pos+6].c_str()));

                    SQL_addInsert("Op",SELLOP_BATH);
                    // ����� ������ ���� total �� ����� ����
                    SQL_addInsert("Total",bathprice1);

                    SQL_addInsert("Discount",bathdiscount);

                    SQL_addInsert("Price",bathprice1/bathtime);
                    SQL_addInsert("BillItemsCount",bathtime);
                    SQL_addInsert("PersonPrice",pprice/bathtime);
                }
                else
                {
                /*
                    #define SELLOP_ADDBALANSE        1
                    #define SELLOP_ABONEMENT         2
                    #define SELLOP_GOOD              4
                    #define SELLOP_SERVICE           8
                    #define SELLOP_ABONEMENT_SPA    16
                    #define SELLOP_SPA_VISIT        32
                    #define SELLOP_BATH             64
                    #define SELLOP_BARBER           128
                    #define SELLOP_NAIL             256
                    #define SELLOP_COSMETIC         512
                    #define SELLOP_ABONEMENT_BATH   1024
                */

                    // ���� ������
                    int z;

                    SQL_exefun(NULL,("select Tag from Services where RowID="+pRowRes[pos+2]).c_str(),&retString);

                    if(retString.Pos("~��������������~") > 0) z = SELLOP_BARBER;
                    else if(retString.Pos("~�������� ������~") > 0) z = SELLOP_NAIL;
                    else if(retString.Pos("~������� ������������~") > 0) z = SELLOP_COSMETIC;
                    else z = SELLOP_SPA_VISIT;

                    SQL_addInsert("Op",z);
                    SQL_addInsert("Total",total);

                    SQL_addInsert("Discount",discount);
                    SQL_addInsert("Price",total/quan);
                    SQL_addInsert("BillItemsCount",quan);
                    SQL_addInsert("PersonPrice",pprice/quan);
                }







                //SQL_addInsert("Total",total);

                SQL_exeInsert("VisitID",0);


                //SQL_exeInsert("Op",SELLOP_BATH);
                //----------------------------------------
                /*
                SQL_iniInsert(DBName,"BillItems");
                SQL_addInsert("BillID",BID);
                SQL_addInsert("ServiceID",SID);
                SQL_addInsert("PersonID",pRowRes[pos+3]);
                SQL_addInsert("BillItemsDate",(int)dt);
                SQL_addInsert("BegTime",bd);
                SQL_addInsert("EndTime",ed);



                SQL_addInsert("Price",total/quan);
                SQL_addInsert("PersonPrice",pprice/quan);
                SQL_addInsert("BillItemsCount",quan);

                SQL_addInsert("Discount",discount);
                SQL_exeInsert("VisitID",VisitID);
                */
            }
        }

        if(!forcash)
        {
            // ������� � ����������!
            //
            x = ATOF(pRow[1].c_str()) - bathdisprice;
            if(x < 0) x = 0;

            SQL_iniUpdate(DBName,"Abonements_SPA",AbID);
            SQL_addUpdate("EDate",(double)dt);
            SQL_addUpdate("EUID",UserID);
            SQL_exeUpdate("Balanse",x);
        }
        else if(!LoadKassa(KassaBillID))
        {
            SQL_CancelTransaction();
            return;
        }

        SQL_iniUpdate(DBName,"Reserve",ReserveIDs[sgReserve->Row-1]);
        SQL_exeUpdate("Status",2);

        if(SQL_CommitTransaction() == SQLITE_OK)
        {
            PDEL(IDsAbonements);
            sgAbonementsSPAFullUpdate(ClientID,AbID);
            sgReserveFullUpdate(RID);
            sgFitSheduleFullUpdate();
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::dtpResDateChange(TObject *Sender)
{
    sgReserveFullUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::cbClosedReserveClick(TObject *Sender)
{
    sgReserveFullUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::CloseAllReserved(void)
{
    // ���� �� �������� �������
    //AnsiString s = ("�������");

    //SQL_exefun(DBName,("select count(Reserve.RowID) from Reserve,Services where Status=1 and BegDate



    //ServiceID=Services.RowID and Tag like '~"+s+"~%'").c_str(),&retString);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgResClientsWindowProc(Messages::TMessage& Msg)
{
    sgWindowProc(Msg,sgResClients,ResClientsWidths,sgOResClientsWindowProc);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgResClientsDrawCell(TObject *Sender,
      int ACol, int ARow, TRect &Rect, TGridDrawState State)
{
    sgDrawCell(Sender,ACol,ARow,Rect,State,fldAlignResClients,sgResClients->Rows[ARow]->Objects[0] != NULL,ilClients);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgResClientsFullUpdate(bool fTop)
{
    int pos = sgResClients->Row;
    sgResClients->RowCount = 2;
    sgResClients->Row = 1;

    sgClearRow(sgResClients);

    __int64 ID = (__int64)sgFitShedule->Rows[sgFitShedule->Row]->Objects[0];
    if(!ID) return;

    SQL_exe(DBName,("select Clients.RowID,FName,SName,TName,Status from Clients,Reserve where Clients.RowID=Reserve.ClientID and FitGroupID="+AnsiString(ID)).c_str(),clients_fill);

    if(!fTop)
        sgResClients->Row = pos;
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgFitSheduleFullUpdate(bool fTop)
{
    if(pcResTree->ActivePageIndex != 1) return;

    int pos = sgFitShedule->Row;
    sgFitShedule->RowCount = 2;
    sgFitShedule->Row = 1;

    sgClearRow(sgFitShedule);
    // ��� ����������, � ������� ��������?
    int day = (FitCurrentDay+FitCurButton).DayOfWeek() - 2;
    if(day < 0) day = 6;
    day = 1 << day;

    AnsiString sql = "select FitGroup.RowID,Services.Name,Personal.Name,BegDate,EndDate,FitGroupCount from FitGroup,Services,Personal where bin_and(WeekDays,"+AnsiString(day)+")!=0 and "
    "FitGroup.ServiceID=Services.RowID and FitGroup.PersonID=Personal.RowID and trunc(BegDate,0)="+AnsiString((int)FitCurrentDay+FitCurButton)+" order by BegDate,Services.Name";

    SQL_BeginTransaction();
    SQL_exe(DBName,sql.c_str(),fitshedule_fill);
    SQL_CancelTransaction();

    if(!fTop)
        sgFitShedule->Row = pos;        

    sgResClientsFullUpdate(fTop);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgFitSheduleWindowProc(Messages::TMessage& Msg)
{
    sgWindowProc(Msg,sgFitShedule,FitSheduleWidths,sgOFitSheduleWindowProc);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sbFitMoClick(TObject *Sender)
{
    pFitButtons[FitCurButton]->Font->Color = clBlack;
    FitCurButton = ((TSpeedButton *)Sender)->Tag - 1;
    ((TSpeedButton *)Sender)->Font->Color = clRed;
    sgFitSheduleFullUpdate(true);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgFitSheduleDrawCell(TObject *Sender,
      int ACol, int ARow, TRect &Rect, TGridDrawState State)
{
    sgDrawCell(Sender,ACol,ARow,Rect,State,fldAlignFitShedule,sgFitShedule->Rows[ARow]->Objects[0] != NULL,ilClients);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::TabSheet4Show(TObject *Sender)
{
    pFitButtons[FitCurButton]->Font->Color = clBlack;

    FitCurButton = 0;
    sbFitMo->Down = true;

    pFitButtons[FitCurButton]->Font->Color = clRed;

    sgFitSheduleFullUpdate(true);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgFitSheduleDblClick(TObject *Sender)
{
    // ����������, ������ ���� ��� ���� �����
    __int64 ID = (__int64)sgFitShedule->Rows[sgFitShedule->Row]->Objects[0];

    if(!ID || !ClientID) return;

    if(sgFitShedule->Cells[0][sgFitShedule->Row] == " ") return;

    AnsiString sRet, sCounter;

    SQL_exefun2(DBName,("select BegDate,FitGroupCount from FitGroup where RowID="+AnsiString(ID)).c_str(),&sRet,&retString);

    double dtn = Now();
    double dt = atof(sRet.c_str()) + (15.0 / 1440.0);
    int begday = dt;

    if(dtn > dt)
    {
        Application->MessageBox("��������!\n����� ������ � ������ �������!","",MB_OK);
        return;
    }

    // ����������
    SQL_exefun(DBName,("select count(*) from Reserve where FitGroupID="+AnsiString(ID)).c_str(),&sRet);

    if(atoi(sRet.c_str()) >= atoi(retString.c_str()))
    {
        Application->MessageBox("��������!\n������ ���������!","",MB_OK);
        return;
    }

    SQL_exefun(DBName,("select count(*) from Reserve where ClientID="+AnsiString(ClientID)+" and FitGroupID="+AnsiString(ID)).c_str(),&sRet);
    if(atoi(sRet.c_str()) > 0)
    {
        // ���� ������
        Application->MessageBox("��������!\n��� ������� ��� ���� ������ � ��� ������!","",MB_OK);
        return;
    }  

    // � ���� ����������� ���������?

    SQL_exefun(DBName,("select count(*) from Abonements where Closed=0 and FixSum>=0 and EndDate>="+AnsiString(begday)+" and ClientID="+AnsiString(ClientID)).c_str(),&sCounter);
    unsigned abs_cnt = atoi(sCounter.c_str());

    if(!abs_cnt)
    {
        Application->MessageBox("��������!\n��� ����������� � ���������� �����������.","������������ ��������",ID_OK);
        return;
    }

    SQL_exefun(DBName,("select count(*) from Abonements where Closed=0 and AbonementsCount=0 and FixSum>0 and ClientID="+AnsiString(ClientID)).c_str(),&sRet);

    if(atoi(sRet.c_str()) == 0)
    {
        // ��� ������� �����, ������� �������
        AnsiString sql =
        "select ACNT,case when VCNT is null then 0 else VCNT end from "
        "( "
            "select first 1 RowID as RID,AbonementsCount as ACNT from Abonements where Closed=0 and FixSum>=0 and ClientID=";

        sql += ClientID;
        sql +=

        " order by 1 desc) "
        "left outer join "
        "( "
            "select AbonementID as AID,sum(case when AbonementID is null then 0 else 1 end) as VCNT from Visits "
            "group by AbonementID "
        ") "
        "on RID=AID";

        SQL_exefun2(DBName,sql.c_str(),&sCounter,&sRet);

        //SQL_exefun2(DBName,("select sum(CNT),sum(VCNT) from (select AbonementsCount as CNT,sum(case when AbonementID is null then 0 else 1 end) as VCNT from Abonements left outer join Visits on Abonements.RowID=AbonementID where Closed=0 and FixSum>=0 and ClientID="+AnsiString(ClientID)+" group by Abonements.RowID)").c_str(),&sCounter,&sRet);

        //SQL_exefun2(DBName,("select Count,count(*) from Abonements,Visits where Closed=0 and FixSum>=0 and EndDate>="+AnsiString(begday)+" and ClientID="+AnsiString(ClientID)+" and Abonements.RowID=AbonementID group by Abonements.RowID").c_str(),&sCounter,&sRet);
        abs_cnt = atoi(sCounter.c_str()) - atoi(sRet.c_str());

        // ������������, �� ����� ���� ����������� ������ � ������
        // �������� ���-�� ������� ������� ������� �� �������

        SQL_exefun(DBName,("select count(*) from Reserve,FitGroup where ClientID="+AnsiString(ClientID)+" and Status=1 and FitGroupID=FitGroup.RowID and Closed=0").c_str(),&sRet);
        unsigned recs = atoi(sRet.c_str());

        if(recs > 0)
        {
            // ���� ������, ��������� ���� �� ������� � ����������
            if(abs_cnt < ++recs)
            {
                Application->MessageBox("��������!\n��� ��������� � ���������� ��������������� ��� ������.","������������ ��������",ID_OK);
                return;
            }
        }
    }

    SQL_BeginTransaction();
    SQL_exe(DBName,("insert into Reserve select null,"+AnsiString(ClientID)+",BegDate,EndDate,PersonID,ServiceID,1,RowID,0,null,"+AnsiString(dtn)+","+AnsiString(UserID)+",0,0,0 from FitGroup where RowID="+AnsiString(ID)).c_str());
    SQL_CommitTransaction();

    sgReserveFullUpdate();
    sgFitSheduleFullUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgResClientsClick(TObject *Sender)
{
    // ����� ������� �����, �� �� ��������� ���� � �� ��������� FitShedule
    __int64 ID = (__int64)sgResClients->Objects[0][sgResClients->Row];

    if(!ID || !IDs) return;

    unsigned i;
    for(i = 0; i < Counter; i++)
        if(ID == IDs[i]) break;

    BackFlag = true;

    if(i < Counter)
    {
        sgClients->Row = i + 1;
        sgClients->TopRow = i + 1;
    }
    else
    {
        // ��������, ��� �������
        //edSearchStr->Text = "";
        //edPSearchStr->Text = "";


        sgClientsFullUpdate();

        for(i = 0; i < Counter; i++)
            if(ID == IDs[i]) break;

        if(i < Counter)
        {
            sgClients->Row = i + 1;
            sgClients->TopRow = i + 1;
        }
    }

    BackFlag = false;
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgFitSheduleClick(TObject *Sender)
{
    sgResClientsFullUpdate(true);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::pcResTreeDrawTab(TCustomTabControl *Control,
      int TabIndex, const TRect &Rect, bool Active)
{
    Control->Canvas->Font->Style = TFontStyles() << fsBold;
    if(Active)
        Control->Canvas->Font->Color = clRed;
    else
        Control->Canvas->Font->Color = clBlack;

    int x = Rect.Width() - Control->Canvas->TextWidth(pcResTree->Pages[TabIndex]->Caption);

    if(x < 2) x = 2;
    else x >>= 1;

    Control->Canvas->TextRect(Rect,Rect.left+x,Rect.top+3,pcResTree->Pages[TabIndex]->Caption);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgNotesClick(TObject *Sender)
{
    if(!Counter || !NoteCounter) return;
    int pos = sgNotes->Row;
    __int64 ID = NoteIDs[pos-1];



    unsigned i;
    for(i = 0; i < Counter; i++)
        if(IDs[i] == ID) break;

    if(i < Counter)
    {
        sgClients->Row = i + 1;
        sgClients->TopRow = i + 1;
        //sgClientsRowInfo(IDs,i);
    }
    else
    {
        // ��������, ��� �������
        //edSearchStr->Text = "";
        //edPSearchStr->Text = "";
        sgClientsFullUpdate();

        for(i = 0; i < Counter; i++)
            if(IDs[i] == ID) break;

        if(i < Counter)
        {
            sgClients->Row = i + 1;
            sgClients->TopRow = i + 1;
        }
    }

    sgNotes->Row = pos;
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sbMGMoClick(TObject *Sender)
{
    pMGButtons[MGCurButton]->Font->Color = clBlack;
    MGCurButton = ((TSpeedButton *)Sender)->Tag - 1;
    ((TSpeedButton *)Sender)->Font->Color = clRed;
    tvMGFullUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::TabSheet5Show(TObject *Sender)
{
    pMGButtons[MGCurButton]->Font->Color = clBlack;

    MGCurButton = 0;
    sbMGMo->Down = true;

    pMGButtons[MGCurButton]->Font->Color = clRed;



    tvMGFullUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::tvMGFullUpdate(void)
{
    //if(pcResTree->ActivePageIndex != 2) return;

    // ��������� ��������, SPA ID=18, � ������ �������
    //cbMGPerson->Clear()

    __int64 *pIDs;
    AnsiString *pNames;

    //unsigned short y, m, d;
    //(MGCurrentDay + MGCurButton).DecodeDate(&y,&m,&d);

    //unsigned cnt = SQL_fldKeyCollect(DBName,"Name",("from (select Personal.RowID,Name from Personal,Calendar where Personal.RowID=PersonID and ServiceID=18 and Alive=1 and CalendarYear="+AnsiString(y)+" and CalendarMonth="+AnsiString(m)+" and bin_and(Days,"+AnsiString(1 << (d-1))+")!=0 order by Name)").c_str(),&pIDs,&pNames,true,true);

    //pNames[0] = "���";

    //for(unsigned i = 0; i < cnt; i++)
    //    cbMGPerson->Items->AddObject(pNames[i],(TObject *)pIDs[i]);

    //cbMGPerson->ItemIndex = 0;

    //delete [] pIDs;
    //delete [] pNames;

    tvMGClick(NULL);

    sgMGTimingUpdate((__int64)cbMGPerson->Items->Objects[cbMGPerson->ItemIndex],MGCurrentDay + MGCurButton);

    if(tvMG->Items->Count) return;

    // � �������� ���������� ����� ���� ���
    // SPA
    __int64 *pcIDs, *pc2IDs;
    AnsiString *pcNames, *pc2Names;
    int day = (MGCurrentDay + MGCurButton).DayOfWeek() - 2;
    if(day < 0) day = 6;
    day = 1 << day;

    unsigned cnt = SQL_fldKeyCollect(DBName,"Name",("from Services where Tag like '~SPA~' and bin_and(WeekDays,"+AnsiString(day)+")!=0 order by Name").c_str(),&pIDs,&pNames,true);
    if(!cnt) return;

    TTreeNode *pNode, *pcNode, *pc2Node;


    // ������� � ������
    for(unsigned i = 0; i < cnt; i++)
    {
        pNode = tvMG->Items->Add(NULL,pNames[i]);
        pNode->Data = (void *)pIDs[i];

        // Childrens
        unsigned ccnt = SQL_fldKeyCollect(DBName,"Name",("from Services where bin_and(WeekDays,"+AnsiString(day)+")!=0 and ParentID="+AnsiString(pIDs[i])+" order by Name").c_str(),&pcIDs,&pcNames,true);
        for(unsigned j = 0; j < ccnt; j++)
        {
            pcNode = tvMG->Items->AddChild(pNode,pcNames[j]);
            pcNode->Data = (void *)pcIDs[j];

            unsigned cc2nt = SQL_fldKeyCollect(DBName,"Name",("from Services where bin_and(WeekDays,"+AnsiString(day)+")!=0 and ParentID="+AnsiString(pcIDs[j])+" order by Name").c_str(),&pc2IDs,&pc2Names,true);

            for(unsigned k = 0; k < cc2nt; k++)
            {
                pc2Node = tvMG->Items->AddChild(pcNode,pc2Names[k]);
                pc2Node->Data = (void *)pc2IDs[k];
            }

            delete [] pc2IDs;
            delete [] pc2Names;
        }

        delete [] pcIDs;
        delete [] pcNames;
    }

    delete [] pIDs;
    delete [] pNames;
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::tvSKFullUpdate(void)
{
    //if(pcResTree->ActivePageIndex != 2) return;

    // ��������� ��������, SPA ID=18, � ������ �������
    cbSKPerson->Clear();

    __int64 *pIDs;
    AnsiString *pNames;

    unsigned short y, m, d;
    (SKCurrentDay + SKCurButton).DecodeDate(&y,&m,&d);
    // 204, 309, 374
    unsigned cnt = SQL_fldKeyCollect(DBName,"Name",("from (select Personal.RowID,Name from Personal,Calendar where Personal.RowID=PersonID and ServiceID in (204,309,374) and Alive=1 and CalendarYear="+AnsiString(y)+" and CalendarMonth="+AnsiString(m)+" and bin_and(Days,"+AnsiString(1 << (d-1))+")!=0 order by Name)").c_str(),&pIDs,&pNames,true,true);

    pNames[0] = "���";

    for(unsigned i = 0; i < cnt; i++)
        cbSKPerson->Items->AddObject(pNames[i],(TObject *)pIDs[i]);

    cbSKPerson->ItemIndex = 0;

    delete [] pIDs;
    delete [] pNames;

    sgSKTimingUpdate((__int64)cbSKPerson->Items->Objects[cbSKPerson->ItemIndex],SKCurrentDay + SKCurButton);

    if(tvSK->Items->Count) return;

    // � �������� ���������� ����� ���� ���
    // SPA


    int day = (SKCurrentDay + SKCurButton).DayOfWeek() - 2;
    if(day < 0) day = 6;
    day = 1 << day;

    TTreeNode *pNode;

    pNode = tvSK->Items->Add(NULL,"��������������");
    pNode->Data = (void *)204;

    AddTreeLevel(pNode,day);

    pNode = tvSK->Items->Add(NULL,"�������� ������");
    pNode->Data = (void *)309;

    AddTreeLevel(pNode,day);

    pNode = tvSK->Items->Add(NULL,"������� ������������");
    pNode->Data = (void *)374;

    AddTreeLevel(pNode,day);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgMGTimingDrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
    sgDrawCell(Sender,ACol,ARow,Rect,State,sgMGTimingAligns);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgMGTimingWindowProc(Messages::TMessage& Msg)
{
    sgWindowProc(Msg,sgMGTiming,sgMGTimingWidths,sgOMGTimingWindowProc);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgSKTimingWindowProc(Messages::TMessage& Msg)
{
    sgWindowProc(Msg,sgSKTiming,sgSKTimingWidths,sgOSKTimingWindowProc);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgBathTimingWindowProc(Messages::TMessage& Msg)
{
    sgWindowProc(Msg,sgBathTiming,sgBathTimingWidths,sgOBathTimingWindowProc);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgMGTimingUpdate(__int64 pid,TDateTime dt,__int64 SelID)
{
    sgMGTiming->Visible = false;
    sgMGTiming->RowCount = 2;
    sgClearRow(sgMGTiming);

    // ����������
    int row = 1;

    for(int i = 8; i < 23; i++)
    {
        if(sgMGTiming->RowCount == 2 && sgMGTiming->Cells[0][1].Length() == 0)
        {

        }
        else
        {
            sgMGTiming->RowCount++;
            sgClearRow(sgMGTiming,sgMGTiming->RowCount-1);
            row++;

        }

        if(i < 10)
            sgMGTiming->Cells[0][row] = "0" + AnsiString(i) + ":00";
        else
            sgMGTiming->Cells[0][row] = AnsiString(i) + ":00";

         sgMGTiming->RowCount++;
         sgClearRow(sgMGTiming,sgMGTiming->RowCount-1);
         row++;

    }

    if((int)dt == 0)
    {
        sgMGTiming->Visible = true;
        return;
    }

    // ����������, ������ �������� ������ �������!
    AnsiString sql = "select BegDate,EndDate,Services.Name,Personal.Name,Tag,Reserve.ClientID,Reserve.RowID from Reserve,Services,Personal where (Tag like '~SPA~%' or Tag like '~����~%') and "
    "trunc(Reserve.BegDate,0)=";
    sql += (int)dt;
    //sql += " and Reserve.ServiceID=";
    //sql += sid;
    if(pid)
    {
        // �������� ���� ������������ ������
        SQL_exefun(NULL,("select Name from Personal where RowID="+AnsiString(pid)).c_str(),&retString);

        AnsiString *pPIDs;

        int pcnt = SQL_fldCollect(NULL,"RowID",("from Personal where Name='"+retString+"'").c_str(),&pPIDs);

        sql += " and Reserve.PersonID in (0,";

        for(int ii = 0; ii < pcnt; ii++)
            sql += pPIDs[ii] + ",";

        sql[sql.Length()] = ')';
        //sql.SetLength(sql.Length()-1);


        delete [] pPIDs;
    }
    sql += " and Reserve.ServiceID=Services.RowID and Reserve.PersonID=Personal.RowID order by Reserve.BegDate";

    SQL_exe(DBName,sql.c_str(),mg_timing_fill);

    if(SelID)
    {
        for(row = 1; row < sgMGTiming->RowCount; row++)
            if((__int64)sgMGTiming->Rows[row]->Objects[1] == SelID) break;

        if(row < sgMGTiming->RowCount)
        {
            sgMGTiming->Row = row;
            sgMGTiming->TopRow = row;
        }
    }

    sgMGTiming->Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::cbMGPersonSelect(TObject *Sender)
{
    sgMGTimingUpdate((__int64)cbMGPerson->Items->Objects[cbMGPerson->ItemIndex],MGCurrentDay + MGCurButton);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgMGTimingDblClick(TObject *Sender)
{
    // ���������� �������� ����
    if(!tvMG->Selected)
    {
        Application->MessageBox("��������!\n�� ������� ������.","",MB_OK);
        return;
    }

    __int64 ServiceID = (__int64)tvMG->Selected->Data;

    if(!ServiceID) return;

    SQL_exefun(DBName,("select count(*) from Services where ParentID="+AnsiString(ServiceID)).c_str(),&retString);

    if(atoi(retString.c_str()) > 0)
    {
        Application->MessageBox("��������!\n������� ������, � �� ������.","",MB_OK);
        return;
    }

    if(cbMGPerson->ItemIndex <= 0)
    {
        Application->MessageBox("��������!\n�� ������ ����������.","",MB_OK);
        return;
    }

    // ����� ���������� ������ � ��������� ������

    //  int pos = (hour - 8) * 2 + 1;
    unsigned short y, d, h, m, s, ms;

    Now().DecodeTime(&h,&m,&s,&ms);

    int hour;
    for(hour = sgMGTiming->Row; hour > 0; hour--)
        if(sgMGTiming->Cells[0][hour].Length() > 0) break;

    if(hour) hour = atoi(sgMGTiming->Cells[0][hour].c_str());
    else hour = 8;

    // ����� ��������
    //int pid = pCurPanel->Tag / DaysCount;    // personal
    TDateTime dt = MGCurrentDay + MGCurButton;
    dt.DecodeDate(&y,&m,&d);
    //int did = d;    // day

    if(!MGCurButton && hour <= h) hour = h + 1;

    //double dt = (int)CurrentFDay + did;
    //dt += (double)hour / 24.0;

    FormResult = 0;

    RescalTimeForm = new TRescalTimeForm(this);

    RescalTimeForm->Edit1->Text = RescalTimeForm->Edit1->Text.sprintf("%02d:00",hour);
    RescalTimeForm->Edit2->Text = RescalTimeForm->Edit2->Text.sprintf("%02d:00",hour+1);
    RescalTimeForm->CheckTime = (MGCurButton == 0);
    RescalTimeForm->ShowQuan = false;

    RescalTimeForm->ShowModal();

    int ibt = RescalTimeForm->BegTime;
    int iet = RescalTimeForm->EndTime;

    if(FormResult != 1)
        return;

    delete RescalTimeForm;

    // ����� ��������, �� �������� �� ��������?
    unsigned pos;
    int itime1, itime2;

    bool err = false;

    for(int i = 1; i < sgMGTiming->RowCount; i++)
    {
        if(sgMGTiming->Cells[1][i].Length() == 0) continue;

        pos = sgMGTiming->Cells[1][i].Pos(":");
        itime1 = 60 * atoi(sgMGTiming->Cells[1][i].c_str());
        itime1 += (atoi(sgMGTiming->Cells[1][i].SubString(pos+1,sgMGTiming->Cells[1][i].Length()-pos).c_str()));

        pos = sgMGTiming->Cells[2][i].Pos(":");
        itime2 = 60 * atoi(sgMGTiming->Cells[2][i].c_str());
        itime2 += (atoi(sgMGTiming->Cells[2][i].SubString(pos+1,sgMGTiming->Cells[2][i].Length()-pos).c_str()));

        if(itime1 <= ibt)
        {
            if(itime2 > ibt)
            {
                err = true;
                break;
            }
        }
        else if(itime1 < iet)
        {
            err = true;
            break;
        }

    }

    if(err)
    {
        if(Application->MessageBox("��������!\n������ �������� ����� ��� ������������ � ������ �������.\n��� ����� ����������?","",MB_OKCANCEL) != IDOK)
            return;
    }

    __int64 ID;

    SQL_iniInsert(DBName,"Reserve",&ID);
    SQL_addInsert("ClientID",ClientID);
    SQL_addInsert("BegDate",(double)dt+ibt/1440.0);
    SQL_addInsert("EndDate",(double)dt+iet/1440.0);
    SQL_addInsert("ServiceID",ServiceID);
    SQL_addInsert("PersonID",(__int64)cbMGPerson->Items->Objects[cbMGPerson->ItemIndex]);
    SQL_addInsert("QUAN",0);
    SQL_addInsert("CDATE",(double)Now());
    SQL_addInsert("CUID",UserID);
    if(SQL_exeInsert("Status",1) == SQLITE_OK)
    {
        sgReserveFullUpdate();
        sgMGTimingUpdate((__int64)cbMGPerson->Items->Objects[cbMGPerson->ItemIndex],dt,ID);
    }
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgMGTimingClick(TObject *Sender)
{
    __int64 ID = (__int64)sgMGTiming->Rows[sgMGTiming->Row]->Objects[0];

    if(!ID || !IDs) return;

    unsigned i;
    for(i = 0; i < Counter; i++)
        if(ID == IDs[i]) break;

    if(i < Counter)
    {
        sgClients->Row = i + 1;
        sgClients->TopRow = i + 1;
    }
    else
    {
        // ��������, ��� �������
        //edSearchStr->Text = "";
        //edPSearchStr->Text = "";
        sgClientsFullUpdate();

        for(i = 0; i < Counter; i++)
            if(ID == IDs[i]) break;

        if(i < Counter)
        {
            sgClients->Row = i + 1;
            sgClients->TopRow = i + 1;
        }
    }

    // �������� � sgReserve
    ID = (__int64)sgMGTiming->Rows[sgMGTiming->Row]->Objects[1];

    for(i = 0; i < ReserveCounter; i++)
        if(ID == ReserveIDs[i]) break;

    if(i < ReserveCounter)
        sgReserve->Row = i + 1;
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::TabSheet7Show(TObject *Sender)
{
    pBathButtons[BathCurButton]->Font->Color = clBlack;

    BathCurButton = 0;
    sbBathMo->Down = true;

    pBathButtons[BathCurButton]->Font->Color = clRed;



    tvBathFullUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::tvBathFullUpdate(void)
{
    //if(pcResTree->ActivePageIndex != 2) return;

    // ��������� ��������, SPA ID=18, � ������ �������
    cbBathPerson->Clear();

    __int64 *pIDs;
    AnsiString *pNames;

    unsigned short y, m, d;
    (BathCurrentDay + BathCurButton).DecodeDate(&y,&m,&d);

    unsigned cnt = SQL_fldKeyCollect(DBName,"Name",("from (select Personal.RowID,Name from Personal,Calendar where Personal.RowID=PersonID and ServiceID=92 and Alive=1 and CalendarYear="+AnsiString(y)+" and CalendarMonth="+AnsiString(m)+" and bin_and(Days,"+AnsiString(1 << (d-1))+")!=0 order by Name)").c_str(),&pIDs,&pNames,true,true);

    pNames[0] = "���";

    for(unsigned i = 0; i < cnt; i++)
        cbBathPerson->Items->AddObject(pNames[i],(TObject *)pIDs[i]);

    cbBathPerson->ItemIndex = 0;

    delete [] pIDs;
    delete [] pNames;

    sgBathTimingUpdate((__int64)cbBathPerson->Items->Objects[cbBathPerson->ItemIndex],BathCurrentDay + BathCurButton);

    //if(tvBath->Items->Count) return;
    return;

    /*
    // � �������� ���������� ����� ���� ���
    // SPA
    __int64 *pcIDs, *pc2IDs;
    AnsiString *pcNames, *pc2Names;
    int day = (BathCurrentDay + BathCurButton).DayOfWeek() - 2;
    if(day < 0) day = 6;
    day = 1 << day;

    cnt = SQL_fldKeyCollect(DBName,"Name",("from Services where Tag like '~����~' and bin_and(WeekDays,"+AnsiString(day)+")!=0 order by Name").c_str(),&pIDs,&pNames,true);
    if(!cnt) return;

    TTreeNode *pNode, *pcNode, *pc2Node;


    // ������� � ������
    for(unsigned i = 0; i < cnt; i++)
    {
        pNode = tvBath->Items->Add(NULL,pNames[i]);
        pNode->Data = (void *)pIDs[i];

        // Childrens
        unsigned ccnt = SQL_fldKeyCollect(DBName,"Name",("from Services where bin_and(WeekDays,"+AnsiString(day)+")!=0 and ParentID="+AnsiString(pIDs[i])+" order by Name").c_str(),&pcIDs,&pcNames,true);
        for(unsigned j = 0; j < ccnt; j++)
        {
            pcNode = tvBath->Items->AddChild(pNode,pcNames[j]);
            pcNode->Data = (void *)pcIDs[j];

            unsigned cc2nt = SQL_fldKeyCollect(DBName,"Name",("from Services where bin_and(WeekDays,"+AnsiString(day)+")!=0 and ParentID="+AnsiString(pcIDs[j])+" order by Name").c_str(),&pc2IDs,&pc2Names,true);

            for(unsigned k = 0; k < cc2nt; k++)
            {
                pc2Node = tvBath->Items->AddChild(pcNode,pc2Names[k]);
                pc2Node->Data = (void *)pc2IDs[k];
            }

            delete [] pc2IDs;
            delete [] pc2Names;
        }

        delete [] pcIDs;
        delete [] pcNames;
    }

    delete [] pIDs;
    delete [] pNames;
    */
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgBathTimingUpdate(__int64 pid,TDateTime dt,__int64 SelID)
{
    sgBathTiming->Visible = false;
    sgBathTiming->RowCount = 2;
    sgClearRow(sgBathTiming);

    // ����������
    int row = 1;

    for(int i = 8; i < 23; i++)
    {
        if(sgBathTiming->RowCount == 2 && sgBathTiming->Cells[0][1].Length() == 0)
        {

        }
        else
        {
            sgBathTiming->RowCount++;
            sgClearRow(sgBathTiming,sgBathTiming->RowCount-1);
            row++;

        }

        if(i < 10)
            sgBathTiming->Cells[0][row] = "0" + AnsiString(i) + ":00";
        else
            sgBathTiming->Cells[0][row] = AnsiString(i) + ":00";

         sgBathTiming->RowCount++;
         sgClearRow(sgBathTiming,sgBathTiming->RowCount-1);
         row++;

    }

    if((int)dt == 0)
    {
        sgBathTiming->Visible = true;
        return;
    }

    // ����������, ������ �������� ������ �������!
    AnsiString sql =

    "select BegDate,EndDate,b.Name,c.Name,Tag,a.ClientID,a.RowID "
    "from Reserve a inner join Services b on a.ServiceID=b.RowID left join Personal c on a.PersonID=c.RowID "
    "where a.ParentID is not null and "

    //Reserve,Services,Personal where Reserve.ParentID is not null and "
    "trunc(a.BegDate,0)=";
    sql += (int)dt;
    sql += " and Num=";
    sql += (sbBath1->Down)? 0 : (sbBath2->Down)? 1 : 2;
  
    if(pid)
    {
        // �������� ���� ������������ ������
        SQL_exefun(NULL,("select Name from Personal where RowID="+AnsiString(pid)).c_str(),&retString);

        AnsiString *pPIDs;

        int pcnt = SQL_fldCollect(NULL,"RowID",("from Personal where Name='"+retString+"'").c_str(),&pPIDs);

        sql += " and a.PersonID in (0,";

        for(int ii = 0; ii < pcnt; ii++)
            sql += pPIDs[ii] + ",";

        sql[sql.Length()] = ')';

        delete [] pPIDs;
    }
    sql += " order by a.BegDate";

    SQL_exe(DBName,sql.c_str(),bath_timing_fill);

    if(SelID)
    {
        for(row = 1; row < sgBathTiming->RowCount; row++)
            if((__int64)sgBathTiming->Rows[row]->Objects[1] == SelID) break;

        if(row < sgBathTiming->RowCount)
        {
            sgBathTiming->Row = row;
            sgBathTiming->TopRow = row;
        }
    }

    sgBathTiming->Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sbBathMoClick(TObject *Sender)
{
    sgBathResGroup->RowCount = 2;
    sgClearRow(sgBathResGroup);

    paBathBuf->Visible = false;

    pBathButtons[BathCurButton]->Font->Color = clBlack;
    BathCurButton = ((TSpeedButton *)Sender)->Tag - 1;
    ((TSpeedButton *)Sender)->Font->Color = clRed;
    tvBathFullUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::cbBathPersonSelect(TObject *Sender)
{
    sgBathTimingUpdate((__int64)cbBathPerson->Items->Objects[cbBathPerson->ItemIndex],BathCurrentDay + BathCurButton);

}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgBathTimingClick(TObject *Sender)
{
    __int64 ID = (__int64)sgBathTiming->Rows[sgBathTiming->Row]->Objects[0];

    if(!ID || !IDs) return;

    unsigned i;
    for(i = 0; i < Counter; i++)
        if(ID == IDs[i]) break;

    if(i < Counter)
    {
        sgClients->Row = i + 1;
        sgClients->TopRow = i + 1;
    }
    else
    {
        // ��������, ��� �������
        //edSearchStr->Text = "";
        //edPSearchStr->Text = "";
        sgClientsFullUpdate();

        for(i = 0; i < Counter; i++)
            if(ID == IDs[i]) break;

        if(i < Counter)
        {
            sgClients->Row = i + 1;
            sgClients->TopRow = i + 1;
        }
    }

    // �������� � sgReserve
    ID = (__int64)sgBathTiming->Rows[sgBathTiming->Row]->Objects[1];

    for(i = 0; i < ReserveCounter; i++)
        if(ID == ReserveIDs[i]) break;

    if(i < ReserveCounter)
        sgReserve->Row = i + 1;
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgBathTimingDblClick(TObject *Sender)
{
    // ���������� �������� ����
    //if(!tvBath->Selected)
    //{
    //    Application->MessageBox("��������!\n�� ������� ������.","",MB_OK);
    //    return;
    //}

    __int64 SID = BATH_ID;
    //(__int64)tvBath->Selected->Data;

    if(!SID) return;

    //if(tvBath->Selected->HasChildren)
    //{
    //    Application->MessageBox("��������!\n������� ������, � �� ������.","",MB_OK);
    //    return;
    //}

    //if(cbBathPerson->ItemIndex <= 0)
    //{
    //    Application->MessageBox("��������!\n�� ������ ����������.","",MB_OK);
    //    return;
    //}

    // ����� ���������� ������ � ��������� ������
    unsigned short y, d, h, m, s, ms;

    Now().DecodeTime(&h,&m,&s,&ms);

    int hour;
    for(hour = sgBathTiming->Row; hour > 0; hour--)
        if(sgBathTiming->Cells[0][hour].Length() > 0) break;

    if(hour) hour = atoi(sgBathTiming->Cells[0][hour].c_str());
    else hour = 8;

    // ����� ��������
    TDateTime dt = BathCurrentDay + BathCurButton;
    dt.DecodeDate(&y,&m,&d);

    if(!BathCurButton && hour <= h) hour = h + 1;

    // � ���� Complex?
    sgBathBuf->RowCount = 2;
    sgClearRow(sgBathBuf);

    sgBathBuf->Rows[0]->Objects[0] = (TObject *)hour;

    sgBathBuf->Cells[0][1] = retString.sprintf("%02d:00",hour);
    sgBathBuf->Cells[1][1] = retString.sprintf("%02d:00",hour+1);

    //__int64 SID = (__int64)tvBath->Selected->Data;



    //************************************************************************
    //SQL_exefun(NULL,("select IsGroup from Services where RowID="+AnsiString(SID)).c_str(),&retString);

    sgBathBuf->Cells[2][1] = "��������� ����";
    //tvBath->Selected->Parent->Text + "]" + tvBath->Selected->Text;
    sgBathBuf->Cells[3][1] = "1";


    sgBathBuf->Rows[0]->Objects[1] = cbBathPerson->Items->Objects[cbBathPerson->ItemIndex];
    sgBathBuf->Rows[0]->Objects[2] = (TObject *)ClientID;
    sgBathBuf->Rows[0]->Objects[3] = (TObject *)sgClients->Row;

    sgBathBuf->Rows[1]->Objects[0] = (TObject *)SID;
    sgBathBuf->Rows[1]->Objects[1] = cbBathPerson->Items->Objects[cbBathPerson->ItemIndex];

    //sgBathBuf->Width = 450;   
    paBathBuf->Visible = true;

    sbBathBufOK->Left = 2;
    sbBathBufOK->Top = 0;
    sbBathBufOK->Width = paBathBufOK->Width - 2;
    sbBathBufOK->Height = 24;

    sbBathBufDel->Left = 2;
    sbBathBufDel->Top = 24;
    sbBathBufDel->Width = paBathBufOK->Width - 2;
    sbBathBufDel->Height = 24;

    sbBathBufCan->Left = 2;
    sbBathBufCan->Top = 48;
    sbBathBufCan->Width = paBathBufOK->Width - 2;
    sbBathBufCan->Height = 24;

    sbBathBufX->Left = 2;
    sbBathBufX->Top = 72;
    sbBathBufX->Width = paBathBufOK->Width - 2;
    sbBathBufX->Height = 24;
    sbBathBufX->Enabled = false;

    if(SID == BATH_ID)
    {
        sbBathBufX->Enabled = true;

    }
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgBathTimingDrawCell(TObject *Sender,
      int ACol, int ARow, TRect &Rect, TGridDrawState State)
{
    sgDrawCell(Sender,ACol,ARow,Rect,State,sgBathTimingAligns);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgBathBufGetEditMask(TObject *Sender,
      int ACol, int ARow, AnsiString &Value)
{
    if(ACol < 2)
        Value = "!90:00;1;_";
    else if(ACol == 3)
        Value = "0;1;_";
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgBathBufSelectCell(TObject *Sender,
      int ACol, int ARow, bool &CanSelect)
{
    if (ACol == 2)
        CanSelect = false;

    if((unsigned)sgBathBuf->Rows[ARow]->Objects[0] == BATH_ID)
        sbBathBufX->Enabled = true;
    else
        sbBathBufX->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgBathBufDrawCell(TObject *Sender,
      int ACol, int ARow, TRect &Rect, TGridDrawState State)
{
    if(ARow > 0 && sgBathBuf->Cells[3][ARow] == "0")
        sgBathBuf->Cells[3][ARow] = "1";

    sgDrawCell(Sender,ACol,ARow,Rect,State,fldAlignBathBuf);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sbBathBufOKClick(TObject *Sender)
{
    if(!sgBathBuf->Rows[1]->Objects[0])
    {
        Application->MessageBox("��������!\n�� ������� �� ����� ������.","",MB_OK);
        return;
    }

    // � ���� ��� ����?

    SetBathPrice();
    if(BathHours < 0) return;
    CalcBathPrice();
    /*
    // ��������������� ������ ������ �����
    // ������� ���� - �������, ������� - ������ ��� ������� ����
    //SQL_exefun(NULL,("select BillItemsCount from BillItems where BillID="+AnsiString(KassaBillID)+" and Op="+AnsiString(SELLOP_BATH)+" and ServiceID=196").c_str(),&retString);
    int pos;

    for(pos = 1; pos < sgBathBuf->RowCount; pos++)
        if((int)sgBathBuf->Rows[pos]->Objects[0] == BATH_ID) break;

    int cntserv = 0, cnt = 0;

    if(pos < sgBathBuf->RowCount)
    {
        cnt = atoi(sgBathBuf->Cells[3][pos].c_str());
        SetBathPrice(cnt);
    }

    for(pos = 1; pos < sgBathBuf->RowCount; pos++)
        if((int)sgBathBuf->Rows[pos]->Objects[0] >= 192 && (int)sgBathBuf->Rows[pos]->Objects[0] <= 194)
            cntserv += atoi(sgBathBuf->Cells[3][pos].c_str());

    cntserv = cnt = 0;

    for(pos = 1; pos < sgBathBuf->RowCount; pos++)
        if((int)sgBathBuf->Rows[pos]->Objects[0] == 203) break;

    if(pos < sgBathBuf->RowCount)
        cnt = atoi(sgBathBuf->Cells[3][pos].c_str());

    for(pos = 1; pos < sgBathBuf->RowCount; pos++)
        if((int)sgBathBuf->Rows[pos]->Objects[0] >= 199 && (int)sgBathBuf->Rows[pos]->Objects[0] <= 201)
            cntserv += atoi(sgBathBuf->Cells[3][pos].c_str());

    // ������� �� ��� %~������� ���� (� ������������)~% ?
    cntserv = cnt = 0;

    for(pos = 1; pos < sgBathBuf->RowCount; pos++)
    {
        SQL_exefun(NULL,("select Tag from Services where RowID="+AnsiString((__int64)sgBathBuf->Rows[pos]->Objects[0])).c_str(),&retString);
        if(retString.Pos("~������� ���� (� ������������)~") > 0)
            cnt += atoi(sgBathBuf->Cells[3][pos].c_str());

        if((int)sgBathBuf->Rows[pos]->Objects[0] == 174 || (int)sgBathBuf->Rows[pos]->Objects[0] == 176 || (int)sgBathBuf->Rows[pos]->Objects[0] == 163)
            cntserv++;
    }

    if(!cntserv && cnt == 1)
    {
        Application->MessageBox("��������!\n���������� �������� ������ � ���������� ������� ����!","��������� ������",MB_OK);
        return;
    }
    */

    // ��, ����������
    TDateTime dt;

    TDateTime pBeg = 1;
    TDateTime pEnd = 0;

    for(int pos = 1; pos < sgBathBuf->RowCount; pos++)
    {

        dt = TDateTime(sgBathBuf->Cells[0][pos],TDateTime::Time);
        if(dt < pBeg) pBeg = dt;
        dt = TDateTime(sgBathBuf->Cells[1][pos],TDateTime::Time);
        if(dt > pEnd) pEnd = dt;
    }

    pBeg += (BathCurrentDay + BathCurButton);
    pEnd += (BathCurrentDay + BathCurButton);
    dt = pBeg;

    __int64 ID;
    double rdt = Now();

    SQL_BeginTransaction();

    // ����������� ������

    SQL_iniInsert(DBName,"Reserve",&ID);
    SQL_addInsert("ClientID",ClientID);
    SQL_addInsert("BegDate",(double)pBeg);
    SQL_addInsert("EndDate",(double)pEnd);
    SQL_addInsert("ServiceID",BATH_COMPLEXID);
    SQL_addInsert("PersonID",(__int64)sgBathBuf->Rows[0]->Objects[1]);
    //(__int64)cbBathPerson->Items->Objects[cbBathPerson->ItemIndex]);
    SQL_addInsert("QUAN",sgBathBuf->RowCount - 1);  // ���-�� �������
    SQL_addInsert("CDATE",rdt);
    SQL_addInsert("CUID",UserID);
    SQL_addInsert("NUM",sbBath1->Down? 0 : sbBath2->Down? 1 : 2);
    // ���� ���� �� ������� �� ���. ������
    SQL_addInsert("PRICE",laBathSum->Caption);
    SQL_exeInsert("Status",1);

    unsigned uf;

    for(int pos = 1; pos < sgBathBuf->RowCount; pos++)
    {
        SQL_iniInsert(DBName,"Reserve");
        SQL_addInsert("ClientID",ClientID);
        SQL_addInsert("BegDate",(double)(TDateTime(sgBathBuf->Cells[0][pos],TDateTime::Time)+BathCurrentDay + BathCurButton));
        SQL_addInsert("EndDate",(double)(TDateTime(sgBathBuf->Cells[1][pos],TDateTime::Time)+BathCurrentDay + BathCurButton));
        SQL_addInsert("ServiceID",(__int64)sgBathBuf->Rows[pos]->Objects[0]);
        SQL_addInsert("PersonID",(__int64)sgBathBuf->Rows[pos]->Objects[1]);
        //cbBathPerson->Items->Objects[cbBathPerson->ItemIndex]);
        SQL_addInsert("QUAN",atoi(sgBathBuf->Cells[3][pos].c_str())); // ���-�� �������
        SQL_addInsert("ParentID",ID);
        SQL_addInsert("CDATE",rdt);
        SQL_addInsert("CUID",UserID);
        SQL_addInsert("NUM",sbBath1->Down? 0 : sbBath2->Down? 1 : 2);
        //uf = (unsigned)sgBathResGroup->Rows[pos]->Objects[3];

        // ���� ����
        //if(sgBathResGroup->Rows[1]->Objects[0])
        //{
        //    SQL_addInsert("PRICE",atof(laBathSum->Caption.c_str()) / BathHours);
        //}
        //else
            SQL_addInsert("PRICE",BathPrice);

        SQL_exeInsert("Status",1);
    }

    if(sgBathResGroup->Rows[1]->Objects[0])
    {
        for(int pos = 1; pos < sgBathResGroup->RowCount; pos++)
        {
            SQL_iniInsert(DBName,"Reserve");
            SQL_addInsert("ClientID",(__int64)sgBathResGroup->Rows[pos]->Objects[2]);
            SQL_addInsert("BegDate",(double)(TDateTime(sgBathResGroup->Cells[1][pos],TDateTime::Time)+BathCurrentDay + BathCurButton));
            SQL_addInsert("EndDate",(double)(TDateTime(sgBathResGroup->Cells[2][pos],TDateTime::Time)+BathCurrentDay + BathCurButton));
            SQL_addInsert("ServiceID",(__int64)sgBathResGroup->Rows[pos]->Objects[0]);
            SQL_addInsert("PersonID",(__int64)sgBathResGroup->Rows[pos]->Objects[1]);
            //cbBathPerson->Items->Objects[cbBathPerson->ItemIndex]);
            SQL_addInsert("QUAN",1);
            //atoi(sgBathResGroup->Cells[4][pos].c_str()));
            SQL_addInsert("ParentID",ID);
            SQL_addInsert("CDATE",rdt);
            SQL_addInsert("CUID",UserID);
            SQL_addInsert("NUM",sbBath1->Down? 0 : sbBath2->Down? 1 : 2);
            uf = (unsigned)sgBathResGroup->Rows[pos]->Objects[3];
            SQL_addInsert("PRICE",*(float *)&uf);
            SQL_exeInsert("Status",1);
        }
    }

    SQL_CommitTransaction();

    sgReserveFullUpdate();
    //tvBathFullUpdate();
    sgBathTimingUpdate((__int64)cbBathPerson->Items->Objects[cbBathPerson->ItemIndex],dt,ID);

    sgBathResGroup->RowCount = 2;
    sgClearRow(sgBathResGroup);

    paBathBuf->Visible = false;

    //sgBathTimingUpdate((__int64)cbBathPerson->Items->Objects[cbBathPerson->ItemIndex],dt,ID);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgBathBufWindowProc(Messages::TMessage& Msg)
{
    sgWindowProc(Msg,sgBathBuf,sgBathBufWidths,sgOBathBufWindowProc);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgBathResGroupWindowProc(Messages::TMessage& Msg)
{
    sgWindowProc(Msg,sgBathResGroup,sgBathResGroupWidths,sgOBathResGroupWindowProc);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sbBathBufCanClick(TObject *Sender)
{
    sgBathResGroup->RowCount = 2;
    sgClearRow(sgBathResGroup);

    paBathBuf->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sbBathBufDelClick(TObject *Sender)
{
    // ������ �������
    sgBathBuf->EditorMode = false;

    if(sgBathBuf->Row > 0 && sgBathBuf->Rows[sgBathBuf->Row]->Objects[0])
    {
        // ��������� ������
        if(sgBathBuf->RowCount == 2)
        {
            sgClearRow(sgBathBuf);
            return;
        }

        if(sgBathBuf->Row == sgBathBuf->RowCount - 1)
        {
            sgBathBuf->RowCount--;
            return;
        }

        for(int i = sgBathBuf->Row; i < sgBathBuf->RowCount - 1; i++)
            sgBathBuf->Rows[i] = sgBathBuf->Rows[i+1];

        sgBathBuf->RowCount--;

    }
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::tvBathDblClick(TObject *Sender)
{
    //
    if(!paBathBuf->Visible || !tvBath->Selected) return;

    if(tvBath->Selected->HasChildren) return;

    __int64 SID = (__int64)tvBath->Selected->Data;

    // ��������, �.�. ��� ����
    int i, j;
    for(i = 1; i < sgBathBuf->RowCount; i++)
        if(SID == (__int64)sgBathBuf->Rows[i]->Objects[0]) break;

    // ���� ������
    if(i < sgBathBuf->RowCount)
    {
        j = atoi(sgBathBuf->Cells[3][i].c_str()) + 1;
        if(j <= 12)
        {
            sgBathBuf->Cells[3][i] = j;
        }

        return;
    }

    int hour = (int)sgBathBuf->Rows[0]->Objects[0];
    int row = 1;

    if(sgBathBuf->Rows[1]->Objects[0])
    {
        sgBathBuf->RowCount++;
        row = sgBathBuf->RowCount - 1;
    }

    sgBathBuf->Cells[0][row] = retString.sprintf("%02d:00",hour);
    sgBathBuf->Cells[1][row] = retString.sprintf("%02d:00",hour+1);

    sgBathBuf->Cells[2][row] = "[" + tvBath->Selected->Parent->Text + "]" + tvBath->Selected->Text;
    sgBathBuf->Cells[3][row] = "1";

    sgBathBuf->Rows[row]->Objects[0] = (TObject *)SID;
    // � ������� ����
    sgBathBuf->Rows[row]->Objects[1] = cbBathPerson->Items->Objects[cbBathPerson->ItemIndex];

  
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::SpeedButton2Click(TObject *Sender)
{
    if(ReserveCounter)
    {
        // ����������
        //SQL_exefun(NULL,("select ServiceID from Reserve where RowID="+AnsiString(ReserveIDs[sgReserve->Row-1])).c_str(),&retString);
        //__int64 SID = _atoi64(retString.c_str());
        //if(SID != BATH_COMPLEXID) return;

        // ������, ���-��, ����
        GSListForm = new TGSListForm(this);
        GSListForm->RID = ReserveIDs[sgReserve->Row-1];
        GSListForm->ShowModal();
        delete GSListForm;
    }
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::TabSheet6Show(TObject *Sender)
{
    pSKButtons[SKCurButton]->Font->Color = clBlack;

    SKCurButton = 0;
    sbSKMo->Down = true;

    pSKButtons[SKCurButton]->Font->Color = clRed;



    tvSKFullUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::AddTreeLevel(TTreeNode *pNode,int day)
{
    if(!pNode) return;

    __int64 ID = (__int64)pNode->Data;

    if(!ID) return;

    __int64 *pIDs;
    AnsiString *pNames;

    unsigned cnt = SQL_fldKeyCollect(DBName,"Name",("from Services where ParentID="+AnsiString(ID)+" and bin_and(WeekDays,"+AnsiString(day)+")!=0 order by Name").c_str(),&pIDs,&pNames,true);
    if(!cnt) return;

    TTreeNode *pNewNode;
    TTreeView *pView = (TTreeView *)pNode->TreeView;
    // ������� � ������
    for(unsigned i = 0; i < cnt; i++)
    {
        pNewNode = pView->Items->AddChild(pNode,pNames[i]);
        pNewNode->Data = (void *)pIDs[i];

        AddTreeLevel(pNewNode,day);


    }

    delete [] pIDs;
    delete [] pNames;
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgSKTimingUpdate(__int64 pid,TDateTime dt,__int64 SelID)
{
    sgSKTiming->Visible = false;
    sgSKTiming->RowCount = 2;
    sgClearRow(sgSKTiming);

    // ����������
    int row = 1;

    for(int i = 8; i < 23; i++)
    {
        if(sgSKTiming->RowCount == 2 && sgSKTiming->Cells[0][1].Length() == 0)
        {

        }
        else
        {
            sgSKTiming->RowCount++;
            sgClearRow(sgSKTiming,sgSKTiming->RowCount-1);
            row++;

        }

        if(i < 10)
            sgSKTiming->Cells[0][row] = "0" + AnsiString(i) + ":00";
        else
            sgSKTiming->Cells[0][row] = AnsiString(i) + ":00";

         sgSKTiming->RowCount++;
         sgClearRow(sgSKTiming,sgSKTiming->RowCount-1);
         row++;

    }

    if((int)dt == 0)
    {
        sgSKTiming->Visible = true;
        return;
    }

    // ����������, ������ �������� ������ �������!
    AnsiString sql = "select BegDate,EndDate,Services.Name,Personal.Name,Tag,Reserve.ClientID,Reserve.RowID from Reserve,Services,Personal where (Tag like '~��������������~%' or Tag like '~�������� ������~%' or Tag like '~������� ������������~%') and "
    "trunc(Reserve.BegDate,0)=";
    sql += (int)dt;
    //sql += " and Reserve.ServiceID=";
    //sql += sid;
    if(pid)
    {
        sql += " and Reserve.PersonID=";
        sql += pid;
    }
    sql += " and Reserve.ServiceID=Services.RowID and Reserve.PersonID=Personal.RowID order by Reserve.BegDate";

    SQL_exe(DBName,sql.c_str(),sk_timing_fill);

    if(SelID)
    {
        for(row = 1; row < sgSKTiming->RowCount; row++)
            if((__int64)sgSKTiming->Rows[row]->Objects[1] == SelID) break;

        if(row < sgSKTiming->RowCount)
        {
            sgSKTiming->Row = row;
            sgSKTiming->TopRow = row;
        }
    }

    sgSKTiming->Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgSKTimingDrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
    sgDrawCell(Sender,ACol,ARow,Rect,State,sgSKTimingAligns);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgSKTimingClick(TObject *Sender)
{
    __int64 ID = (__int64)sgSKTiming->Rows[sgSKTiming->Row]->Objects[0];

    if(!ID || !IDs) return;

    unsigned i;
    for(i = 0; i < Counter; i++)
        if(ID == IDs[i]) break;

    if(i < Counter)
    {
        sgClients->Row = i + 1;
        sgClients->TopRow = i + 1;
    }
    else
    {
        // ��������, ��� �������
        //edSearchStr->Text = "";
        //edPSearchStr->Text = "";
        sgClientsFullUpdate();

        for(i = 0; i < Counter; i++)
            if(ID == IDs[i]) break;

        if(i < Counter)
        {
            sgClients->Row = i + 1;
            sgClients->TopRow = i + 1;
        }
    }

    // �������� � sgReserve
    ID = (__int64)sgSKTiming->Rows[sgSKTiming->Row]->Objects[1];

    for(i = 0; i < ReserveCounter; i++)
        if(ID == ReserveIDs[i]) break;

    if(i < ReserveCounter)
        sgReserve->Row = i + 1;
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgSKTimingDblClick(TObject *Sender)
{
    // ���������� �������� ����
    if(!tvSK->Selected)
    {
        Application->MessageBox("��������!\n�� ������� ������.","",MB_OK);
        return;
    }

    __int64 ServiceID = (__int64)tvSK->Selected->Data;

    if(!ServiceID) return;

    SQL_exefun(DBName,("select count(*) from Services where ParentID="+AnsiString(ServiceID)).c_str(),&retString);

    if(atoi(retString.c_str()) > 0)
    {
        Application->MessageBox("��������!\n������� ������, � �� ������.","",MB_OK);
        return;
    }

    if(cbSKPerson->ItemIndex <= 0)
    {
        Application->MessageBox("��������!\n�� ������ ����������.","",MB_OK);
        return;
    }

    // ����� ���������� ������ � ��������� ������

    //  int pos = (hour - 8) * 2 + 1;
    unsigned short y, d, h, m, s, ms;

    Now().DecodeTime(&h,&m,&s,&ms);

    int hour;
    for(hour = sgSKTiming->Row; hour > 0; hour--)
        if(sgSKTiming->Cells[0][hour].Length() > 0) break;

    if(hour) hour = atoi(sgSKTiming->Cells[0][hour].c_str());
    else hour = 8;

    // ����� ��������
    //int pid = pCurPanel->Tag / DaysCount;    // personal
    TDateTime dt = SKCurrentDay + SKCurButton;
    dt.DecodeDate(&y,&m,&d);
    //int did = d;    // day

    if(!SKCurButton && hour <= h) hour = h + 1;

    //double dt = (int)CurrentFDay + did;
    //dt += (double)hour / 24.0;

    FormResult = 0;

    RescalTimeForm = new TRescalTimeForm(this);

    RescalTimeForm->Edit1->Text = RescalTimeForm->Edit1->Text.sprintf("%02d:00",hour);
    RescalTimeForm->Edit2->Text = RescalTimeForm->Edit2->Text.sprintf("%02d:00",hour+1);
    RescalTimeForm->CheckTime = (SKCurButton == 0);
    RescalTimeForm->ShowQuan = false;

    RescalTimeForm->ShowModal();

    int ibt = RescalTimeForm->BegTime;
    int iet = RescalTimeForm->EndTime;

    if(FormResult != 1)
        return;

    delete RescalTimeForm;

    // ����� ��������, �� �������� �� ��������?
    unsigned pos;
    int itime1, itime2;

    bool err = false;

    for(int i = 1; i < sgSKTiming->RowCount; i++)
    {
        if(sgSKTiming->Cells[1][i].Length() == 0) continue;

        pos = sgSKTiming->Cells[1][i].Pos(":");
        itime1 = 60 * atoi(sgSKTiming->Cells[1][i].c_str());
        itime1 += (atoi(sgSKTiming->Cells[1][i].SubString(pos+1,sgSKTiming->Cells[1][i].Length()-pos).c_str()));

        pos = sgSKTiming->Cells[2][i].Pos(":");
        itime2 = 60 * atoi(sgSKTiming->Cells[2][i].c_str());
        itime2 += (atoi(sgSKTiming->Cells[2][i].SubString(pos+1,sgSKTiming->Cells[2][i].Length()-pos).c_str()));

        if(itime1 <= ibt)
        {
            if(itime2 > ibt)
            {
                err = true;
                break;
            }
        }
        else if(itime1 < iet)
        {
            err = true;
            break;
        }

    }

    if(err)
    {
        if(Application->MessageBox("��������!\n������ �������� ����� ��� ������������ � ������ �������.\n��� ����� ����������?","",MB_OKCANCEL) != IDOK)
            return;
    }

    __int64 ID;

    SQL_iniInsert(DBName,"Reserve",&ID);
    SQL_addInsert("ClientID",ClientID);
    SQL_addInsert("BegDate",(double)dt+ibt/1440.0);
    SQL_addInsert("EndDate",(double)dt+iet/1440.0);
    SQL_addInsert("ServiceID",ServiceID);
    SQL_addInsert("PersonID",(__int64)cbSKPerson->Items->Objects[cbSKPerson->ItemIndex]);
    SQL_addInsert("QUAN",0);
    SQL_addInsert("CDATE",(double)Now());
    SQL_addInsert("CUID",UserID);
    if(SQL_exeInsert("Status",1) == SQLITE_OK)
    {
        sgReserveFullUpdate();
        sgSKTimingUpdate((__int64)cbSKPerson->Items->Objects[cbSKPerson->ItemIndex],dt,ID);
    }
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::cbSKPersonSelect(TObject *Sender)
{
    sgSKTimingUpdate((__int64)cbSKPerson->Items->Objects[cbSKPerson->ItemIndex],SKCurrentDay + SKCurButton);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sbSKMoClick(TObject *Sender)
{
    pSKButtons[SKCurButton]->Font->Color = clBlack;
    SKCurButton = ((TSpeedButton *)Sender)->Tag - 1;
    ((TSpeedButton *)Sender)->Font->Color = clRed;
    tvSKFullUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::Splitter9Moved(TObject *Sender)
{
    if(sbBathBufOK->Visible)
    {
        sbBathBufOK->Width = paBathBufOK->Width - 2;
        sbBathBufDel->Width = paBathBufOK->Width - 2;
        sbBathBufCan->Width = paBathBufOK->Width - 2;
    }
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::tvMGClick(TObject *Sender)
{
    // ��������� cbMGPerson
    TTreeNode *pNode = tvMG->Selected;

    //if(!pNode) return;

    //if(pNode->Text != "�����������" && pNode->Text != "������") return;
    if(pNode)
        while(pNode->Parent) pNode = pNode->Parent;

    cbMGPerson->Clear();

    __int64 *pIDs;
    AnsiString *pNames;

    unsigned short y, m, d;
    (MGCurrentDay + MGCurButton).DecodeDate(&y,&m,&d);

    unsigned cnt;

    if(pNode)
    {
        if(pNode->Text == "�����������")
            cnt = SQL_fldKeyCollect(DBName,"Name",("from (select Personal.RowID,Name from Personal,Calendar where Personal.RowID=PersonID and ServiceID=18 and Alive=1 and CalendarYear="+AnsiString(y)+" and CalendarMonth="+AnsiString(m)+" and bin_and(HDays,"+AnsiString(1 << (d-1))+")!=0 order by Name)").c_str(),&pIDs,&pNames,true,true);
        else
            cnt = SQL_fldKeyCollect(DBName,"Name",("from (select Personal.RowID,Name from Personal,Calendar where Personal.RowID=PersonID and ServiceID=18 and Alive=1 and CalendarYear="+AnsiString(y)+" and CalendarMonth="+AnsiString(m)+" and bin_and(Days,"+AnsiString(1 << (d-1))+")!=0 order by Name)").c_str(),&pIDs,&pNames,true,true);
    }
    else
        cnt = SQL_fldKeyCollect(DBName,"Name",("from (select Personal.RowID,Name from Personal,Calendar where Personal.RowID=PersonID and ServiceID=18 and Alive=1 and CalendarYear="+AnsiString(y)+" and CalendarMonth="+AnsiString(m)+" and bin_and(Days,"+AnsiString(1 << (d-1))+")!=0 order by Name)").c_str(),&pIDs,&pNames,true,true);

    pNames[0] = "���";

    for(unsigned i = 0; i < cnt; i++)
        cbMGPerson->Items->AddObject(pNames[i],(TObject *)pIDs[i]);

    cbMGPerson->ItemIndex = 0;

    delete [] pIDs;
    delete [] pNames;
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::spbClosingClick(TObject *Sender)
{
    if(sgClients->Row > 0 && Counter > 0 && sgAbonements->Row > 0 && CounterAbonements > 0)
    {
        if(!IDs || !IDsAbonements) return;

        // ������������� ���������� �������
        AnsiString sBIID, sBID, sPrice;

        SQL_BeginTransaction();

        SQL_exefun3(NULL,("select RowID,BillID,Price from BillItems where AbonementID="+AnsiString(IDsAbonements[sgAbonements->Row-1])).c_str(),&sBIID,&sBID,&sPrice);
        __int64 BIID, BID;

        BIID = _atoi64(sBIID.c_str());
        BID = _atoi64(sBID.c_str());

        if(!BIID || !BID)
        {
            Application->MessageBox("��������!\n�� ������ ��� ����������, ������������� ����������.","",MB_OK);
            SQL_CancelTransaction();
            return;
        }

        // � �������?
        SQL_exefun(NULL,("select Closed from Abonements where RowID="+AnsiString(IDsAbonements[sgAbonements->Row-1])).c_str(),&retString);
        if(atoi(retString.c_str()) != 0)
        {
            SQL_CancelTransaction();
            Application->MessageBox("��������!\n���������� ������������ �������� ���������.","",MB_OK);
            return;
        }

        SQL_exefun(NULL,("select count(*) from Visits where AbonementID="+AnsiString(IDsAbonements[sgAbonements->Row-1])).c_str(),&retString);
        if(atoi(retString.c_str()) != 0)
        {
            SQL_CancelTransaction();
            Application->MessageBox("��������!\n�� ������� ���������� ���� ��������� ������,\n������� ���������� ������������ ��� ������.","",MB_OK);
            return;
        }

        if(Application->MessageBox(("��������!\n����� ����������� ��������� ������� \""+sgAbonements->Cells[1][sgAbonements->Row]+"\" �� "+sgAbonements->Cells[2][sgAbonements->Row] +"\n����������?").c_str(),"������������� ��������",MB_OKCANCEL) == IDOK)
        {
            // ����� ��������� ���

            SQL_exefun(NULL,("select Total from Bills where RowID="+AnsiString(BID)).c_str(),&retString);

            SQL_iniUpdate(NULL,"Bills",BID);
            SQL_exeUpdate("Total",atof(retString.c_str())-atof(sPrice.c_str()));

            SQL_exe(NULL,("delete from BillItems where RowID="+AnsiString(BIID)).c_str());

            SQL_exe(DBName,("delete from Abonements where RowID="+(AnsiString)IDsAbonements[sgAbonements->Row-1]).c_str());

            SQL_CommitTransaction();

            sgAbonementsFullUpdate(ClientID);
            sgClientsUpdate();
        }
        else
            SQL_CancelTransaction();
    }
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sbDelResClick(TObject *Sender)
{
    if(!ClientID || !ReserveCounter) return;

    // ����� ���� ������
    retString = ReserveIDs[sgReserve->Row-1];

    SQL_BeginTransaction();

    SQL_exe(NULL,("delete from Reserve where RowID="+retString+" or ParentID="+retString).c_str());

    SQL_CommitTransaction();

    sgReserveFullUpdate();
    //sgFitSheduleFullUpdate();

    // ����� �������� time-����
    int page = pcResTree->ActivePageIndex;

    pcResTree->ActivePageIndex = 0;
    pcResTree->ActivePageIndex = page;
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::spbFitDChangeClick(TObject *Sender)
{
    if(sgClients->Row > 0 && Counter > 0 && sgAbonements->Row > 0 && CounterAbonements > 0)
    {
        if(!IDs || !IDsAbonements) return;

        if(Application->MessageBox(("��������!\n����� �������� ���� ���������� \""+sgAbonements->Cells[1][sgAbonements->Row]+"\" �� "+sgAbonements->Cells[2][sgAbonements->Row] +"\n����������?").c_str(),"������������� ��������",MB_OKCANCEL) == IDOK)
        {
            DTI_BegDate = sgAbonements->Cells[2][sgAbonements->Row];
            DTI_EndDate = sgAbonements->Cells[3][sgAbonements->Row];
            FormResult = 0;
            DateIntervalForm = new TDateIntervalForm(this);
            DateIntervalForm->ShowModal();
            delete DateIntervalForm;
            
            if(FormResult == 1)
            {
                SQL_iniUpdate(DBName,"Abonements",IDsAbonements[sgAbonements->Row-1]);
                SQL_addUpdate("BegDate",(int)DTI_BegDate);
                SQL_addUpdate("EndDate",(int)DTI_EndDate);
                SQL_exeUpdate("Closed",0);

                sgAbonementsFullUpdate(ClientID);
            }
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::tbReservedClick(TObject *Sender)
{
//TResControlForm *ResControlForm;
    ResControlForm = new TResControlForm(this);
    ResControlForm->ShowModal();
    delete ResControlForm;
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::ToolButton6Click(TObject *Sender)
{
    AnsiString sql;

    AbonementsUpdIDs.Length = 10;
    AbonementsUpdCounter = 0;

    _PCID = 0;

    SQL_exe(NULL,"select b.RowID,a.CDate from Bills a inner join Clients b on a.ClientID=b.RowID "
                    "where a.BegBalanse!=a.EndBalanse and b.Alive=1 order by 1,2",analyze_period);

    sql = "SELECT distinct a.RowID,a.Alive,a.FName,a.SName,a.TName,a.CID FROM CLIENTS a inner join Bills b on a.RowID=b.ClientID "
    "where cast('30.12.1899' as timestamp)+b.CDate >= '01.01.2015' and "





    "a.RowID in (";

    for(unsigned i = 0; i < AbonementsUpdCounter; i++)
    {
        sql += AbonementsUpdIDs[i];
        sql += ",";
    }

    sql.SetLength(sql.Length()-1);
    sql += ")";



    //AbonementsUpdIDs.Length = 0;
    SQL_exefun(DBName,("select count(*) from ( "+sql+" )").c_str(),&retString);

    PDEL(IDs);

    int icnt = atoi(retString.c_str());
    sgClients->RowCount = (!icnt)? 2 : icnt + 1;
    sgClients->Rows[sgClients->RowCount-1]->Clear();
    sgClients->Cells[0][1] = "";

    Counter = 0;

    if(icnt)
    {
        IDs = new __int64[icnt];
        if(!IDs) Close();
    }
    else
    {
        sgClients->Row = 1;
        sgClientsRowInfo(IDs,sgClients->Row-1);
        return;
    }

    SQL_exe(DBName,sql.c_str(),clients_select);

    sgClients->Row = 1;

    sgClientsRowInfo(IDs,sgClients->Row-1);

    AbonementsUpdIDs.Length = 0;
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::edScanSearchEnter(TObject *Sender)
{
    if(edScanSearch->PasswordChar == '*')
    {
        edScanSearch->Text = "";
        edScanSearch->PasswordChar = 0;
    }
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::bVisPhoneExit(TObject *Sender)
{
    laPhone1->Visible = false;
    laPhone2->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::bVisPhoneClick(TObject *Sender)
{
    laPhone1->Visible = !laPhone1->Visible;
    laPhone2->Visible = !laPhone2->Visible;
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgAbonementsBathDrawCell(TObject *Sender,
      int ACol, int ARow, TRect &Rect, TGridDrawState State)
{
    sgDrawCell(Sender,ACol,ARow,Rect,State,fldAlignAbs,IDsAbonementsBath != NULL,ilClients);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::cbShowAbBathClosedClick(TObject *Sender)
{
   //if(ClientID)
   //     sgAbonementsBathFullUpdate(ClientID);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::spbClosingBathClick(TObject *Sender)
{
    if(sgClients->Row > 0 && Counter > 0)
    {
        if(!IDs) return;

        ClientID = IDs[sgClients->Row-1];
        //AbonementID = 0;
        //AbonementSPAID = 0;
        AbonementBathID = 0;

        VisitsBathForm = new TVisitsBathForm(this);
        VisitsBathForm->ShowModal();
        delete VisitsBathForm;
    }
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sbBath1Click(TObject *Sender)
{
    // ���������� ��. ����
    sgBathResGroup->RowCount = 2;
    sgClearRow(sgBathResGroup);

    paBathBuf->Visible = false;

    tvBathFullUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::SpeedButton7Click(TObject *Sender)
{
    if(paBathRes->Visible)
    {
        paBathRes->Visible = false;
    }
    else
    {
        // ���������� ������
        // ������ ������ ����� ������ ���-��
        //sgBathResGroup->Row = 1;
        //sgBathResGroup->Col = 1;
        // 2 - ClientID, 3 - Row

        // ������ ���� ����?
        SetBathPrice();
        if(BathHours < 0) return;

        laBathSum->Caption = FormatFloat(MoneyFormat,BathPrice * BathHours).TrimLeft();
        laAltSum->Caption = "0.00";

        int pos = (int)sgBathBuf->Rows[0]->Objects[3];

        laClient->Caption = "������: " + sgClients->Cells[1][pos] + " " + sgClients->Cells[2][pos] + ", ����� ��������� " + sgBathBuf->Cells[0][sgBathBuf->Row] + " - " + sgBathBuf->Cells[1][sgBathBuf->Row];

        if(paBathRes->Parent == Panel5)
        {
            paBathRes->Visible = true;
            sgBathResGroup->Row = 1;
            sgBathResGroup->Col = 1;
            return;
        }

        paBathRes->Parent = Panel5;
        paBathRes->Align = alClient;


        //--------------------------------------------------------------
        //cbBathResPerson->Items = cbBathPerson->Items;
        //cbBathResPerson->ItemIndex = cbBathPerson->ItemIndex;
        //cbBathResPerson->Clear();
        //for(int i = 1; i < cbBathPerson->Items->Count; i++)
        //{
        //    cbBathResPerson->Items->Add(cbBathPerson->Items->Strings[i]);
        //    cbBathResPerson->Items->Objects[i-1] = cbBathPerson->Items->Objects[i];
        //}

        //cbBathResPerson->ItemIndex = 0;

        // �������� ������ ��� � ����
        //Panel28->Width = Panel19->Width;
        //sgBathResGroup->Width = sgBathBuf->Width;



        //sgBathResGroup->Width = 450;
        //paBathResInfo->Left = sgBathResGroup->Width;


        // SPA
        __int64 *pIDs, *pcIDs, *pc2IDs, *pcxIDs;
        AnsiString *pxNames, *pNames, *pcNames, *pc2Names;
        int day = (BathCurrentDay + BathCurButton).DayOfWeek() - 2;
        if(day < 0) day = 6;
        day = 1 << day;

        unsigned cnt = SQL_fldKeyCollect(DBName,"Name",("from Services where Name!='�������' and Tag='~' and bin_and(WeekDays,"+AnsiString(day)+")!=0 order by Name").c_str(),&pcxIDs,&pxNames,true);
        if(!cnt) return;

        //(Tag like '~����~' or Tag like '~SPA~' or Tag like '~��������������~' or Tag like '~�������� ������~' or Tag like '~������� ������������~')
        TTreeNode *pcxNode, *fNode = NULL;
        TTreeNode *pNode, *pcNode, *pc2Node;

        for(unsigned ii = 0; ii < cnt; ii++)
        {
            pcxNode = tvBathRes->Items->Add(NULL,pxNames[ii]);
            pcxNode->Data = (void *)pcxIDs[ii];
            if(!ii) fNode = pcxNode;
        // ������� �
        unsigned pcnt = SQL_fldKeyCollect(DBName,"Name",("from Services where bin_and(WeekDays,"+AnsiString(day)+")!=0 and ParentID="+AnsiString(pcxIDs[ii])+" order by Name").c_str(),&pIDs,&pNames,true);
        for(unsigned i = 0; i < pcnt; i++)
        {
            pNode = tvBathRes->Items->AddChild(pcxNode,pNames[i]);
            pNode->Data = (void *)pIDs[i];

            // Childrens
            unsigned ccnt = SQL_fldKeyCollect(DBName,"Name",("from Services where bin_and(WeekDays,"+AnsiString(day)+")!=0 and ParentID="+AnsiString(pIDs[i])+" order by Name").c_str(),&pcIDs,&pcNames,true);
            for(unsigned j = 0; j < ccnt; j++)
            {
                pcNode = tvBathRes->Items->AddChild(pNode,pcNames[j]);
                pcNode->Data = (void *)pcIDs[j];

                unsigned cc2nt = SQL_fldKeyCollect(DBName,"Name",("from Services where bin_and(WeekDays,"+AnsiString(day)+")!=0 and ParentID="+AnsiString(pcIDs[j])+" order by Name").c_str(),&pc2IDs,&pc2Names,true);

                for(unsigned k = 0; k < cc2nt; k++)
                {
                    pc2Node = tvBathRes->Items->AddChild(pcNode,pc2Names[k]);
                    pc2Node->Data = (void *)pc2IDs[k];
                }

                delete [] pc2IDs;
                delete [] pc2Names;
            }

            delete [] pcIDs;
            delete [] pcNames;
        }

        delete [] pIDs;
        delete [] pNames;
        }

        delete [] pcxIDs;
        delete [] pxNames;

        //sgBathResGroup->Width = 400;
        paBathRes->Visible = true;
        //////-----------------------
        sbBathResOK->Left = 2;
        sbBathResOK->Top = 40;
        sbBathResOK->Width = paBathResInfo->Width - 2;
        sbBathResOK->Height = 24;

        sbBathResDel->Left = 2;
        sbBathResDel->Top = 64;
        sbBathResDel->Width = paBathResInfo->Width - 2;
        sbBathResDel->Height = 24;

        sbBathResCan->Left = 2;
        sbBathResCan->Top = 88;
        sbBathResCan->Width = paBathResInfo->Width - 2;
        sbBathResCan->Height = 24;

        

        sgBathResGroup->Row = 1;
        sgBathResGroup->Col = 1;

        tvBathRes->Selected = fNode;
    }
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sbBathResCanClick(TObject *Sender)
{
    if(sgClients->Row != (int)sgBathBuf->Rows[0]->Objects[3])
    {
        //BackFlag = true;
        sgClients->Row = (int)sgBathBuf->Rows[0]->Objects[3];
        //BackFlag = false;
    }

    paBathRes->Visible = false;

    sgBathResGroup->RowCount = 2;
    sgClearRow(sgBathResGroup);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgBathResGroupDrawCell(TObject *Sender,
      int ACol, int ARow, TRect &Rect, TGridDrawState State)
{
    //if(ARow > 0 && sgBathResGroup->Cells[4][ARow] == "0")
    //    sgBathResGroup->Cells[4][ARow] = "1";

    sgDrawCell(Sender,ACol,ARow,Rect,State,fldAlignBathResGroup);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgBathResGroupGetEditMask(TObject *Sender,
      int ACol, int ARow, AnsiString &Value)
{
    if(ACol == 1 || ACol == 2)
        Value = "!90:00;1;_";
    //else if(ACol == 4)
    //    Value = "0;1;_";
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgBathResGroupSelectCell(TObject *Sender,
      int ACol, int ARow, bool &CanSelect)
{
    if (ACol == 0 || ACol > 3)
        CanSelect = false;
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sbBathResDelClick(TObject *Sender)
{
    // ������ �������
    sgBathResGroup->EditorMode = false;

    if(sgBathResGroup->Row > 0 && sgBathResGroup->Rows[sgBathResGroup->Row]->Objects[0])
    {
        // ��������� ������
        if(sgBathResGroup->RowCount == 2)
            sgClearRow(sgBathResGroup);
        else if(sgBathResGroup->Row == sgBathResGroup->RowCount - 1)
            sgBathResGroup->RowCount--;
        else
        {
            for(int i = sgBathResGroup->Row; i < sgBathResGroup->RowCount - 1; i++)
                sgBathResGroup->Rows[i] = sgBathResGroup->Rows[i+1];

            sgBathResGroup->RowCount--;
        }

        // ����������� ����
        CalcBathPrice();
    }
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::tvBathResDblClick(TObject *Sender)
{
    if(tvBathRes->Selected->HasChildren) return;
    if(cbBathResPerson->ItemIndex < 0)
    {
        Application->MessageBox("��������!\n����������� ����������.","������������ ��������",MB_OK);
        return;
    }

    __int64 SID = (__int64)tvBathRes->Selected->Data;

    // ��������, �.�. ��� ����
    //int i, j;
    //for(i = 1; i < sgBathResGroup->RowCount; i++)
    //    if
    //    (
    //        SID == (__int64)sgBathResGroup->Rows[i]->Objects[0] &&
    //        cbBathResPerson->Items->Objects[cbBathResPerson->ItemIndex] == sgBathResGroup->Rows[i]->Objects[1] &&
    //        ClientID == (__int64)sgBathResGroup->Rows[i]->Objects[2]
    //    ) break;

    //if(i < sgBathResGroup->RowCount) return;

    //AnsiString sPrice;
    //SQL_exefun2(NULL, (AnsiString("select Price,PersonPrice from Services where RowID=") + SID).c_str(), &retString, &sPrice);
    //float price = atof(retString.c_str());

    double dprice, personprice;

    GetSPAServicePrice(&dprice,&personprice,SID,1,60,false);
    unsigned uf = (unsigned)sgBathResGroup->Rows[0]->Objects[0];
    float price = dprice;
    //price = SimpleRoundTo(price,-2);
    //float d = *(float *)&uf;
    unsigned short h, m, s, ms;

    TDateTime(*(float *)&uf).DecodeTime(&h, &m, &s, &ms);
    RoundTimeParts(h,m,s,ms);

    int row = 1;

    if(sgBathResGroup->Rows[1]->Objects[0])
    {
        sgBathResGroup->RowCount++;
        row = sgBathResGroup->RowCount - 1;
    }

    sgBathResGroup->Cells[0][row] = sgClients->Cells[1][sgClients->Row] + " " + sgClients->Cells[2][sgClients->Row];
    sgBathResGroup->Cells[1][row] = retString.sprintf("%02d:%02d",h,m);
    sgBathResGroup->Cells[2][row] = retString.sprintf("%02d:%02d",h+1,m);

    sgBathResGroup->Cells[3][row] = "[" + tvBathRes->Selected->Parent->Text + "]" + tvBathRes->Selected->Text;
    sgBathResGroup->Cells[4][row] = cbBathResPerson->Items->Strings[cbBathResPerson->ItemIndex];

    // ������
    sgBathResGroup->Rows[row]->Objects[0] = (TObject *)SID;
    // ����������
    sgBathResGroup->Rows[row]->Objects[1] = cbBathResPerson->Items->Objects[cbBathResPerson->ItemIndex];
    // ������
    sgBathResGroup->Rows[row]->Objects[2] = (TObject *)ClientID;
    // ���� ������
    sgBathResGroup->Rows[row]->Objects[3] = (TObject *)(*(unsigned *)&price);

    CalcBathPrice();
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sbBathResOKClick(TObject *Sender)
{
    if(sgClients->Row != (int)sgBathBuf->Rows[0]->Objects[3])
    {
        sgClients->Row = (int)sgBathBuf->Rows[0]->Objects[3];
    }

    paBathRes->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgBathBufDblClick(TObject *Sender)
{
    // ������� ���� �� ����������� ������ �������� ��
    // 373
    // 196
    if((unsigned)sgBathBuf->Rows[sgBathBuf->Row]->Objects[0] == BATH_ID)
    {
        SpeedButton7Click(NULL);
    }
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgBathResGroupClick(TObject *Sender)
{
    __int64 ID = (__int64)sgBathResGroup->Rows[sgBathResGroup->Row]->Objects[2];

    if(!ID || !IDs) return;

    unsigned i;
    for(i = 0; i < Counter; i++)
        if(ID == IDs[i]) break;

    if(i < Counter)
    {
        sgClients->Row = i + 1;
        sgClients->TopRow = i + 1;
    }
    else
    {
        // ��������, ��� �������
      
        sgClientsFullUpdate();

        for(i = 0; i < Counter; i++)
            if(ID == IDs[i]) break;

        if(i < Counter)
        {
            sgClients->Row = i + 1;
            sgClients->TopRow = i + 1;
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sbBathBufXClick(TObject *Sender)
{
    if((unsigned)sgBathBuf->Rows[sgBathBuf->Row]->Objects[0] == BATH_ID)
    {
        SpeedButton7Click(NULL);
    }
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::SetBathPrice(void)
{
    int pos;

    BathPrice = 0;
    BathHours = -1;

    for(pos = 1; pos < sgBathBuf->RowCount; pos++)
        if(sgBathBuf->Rows[pos]->Objects[0] == (TObject *)BATH_ID) break;

    if(pos >= sgBathBuf->RowCount) return;

    retString = sgBathBuf->Cells[0][pos];
    if(retString[1] == '2' && retString[2] == '4')
    {
        retString[1] = '0';
        retString[2] = '0';
    }

    TDateTime edt, bdt = TDateTime(retString,TDateTime::Time);

    retString = sgBathBuf->Cells[1][sgBathBuf->Row];
    if((retString[1] == '2' && retString[2] == '4') || (retString[1] == '0' && retString[2] == '0'))
    {
        retString[1] = '0';
        retString[2] = '0';
        edt = TDateTime(retString,TDateTime::Time) + 1;
    }
    else
        edt = TDateTime(retString,TDateTime::Time);


    if(bdt >= edt)
    {
        Application->MessageBox("��������!\n��� ������ ������� ������������ �����!","������ ������",MB_OK);
        return;
    }

    // ������� �����
    //DecodeTime(unsigned short* hour, unsigned short* min, unsigned short* sec, unsigned short* msec) const;
    unsigned short h, m, s, ms;
    (edt - bdt).DecodeTime(&h,&m,&s,&ms);

    //if(m > 0)
    //{
    //    Application->MessageBox("��������!\n��� ������ ������� ������������ �����!","������ ������",MB_OK);
    //    return;
    //}

    double x;
    float f = modf(bdt, &x);

    sgBathResGroup->Rows[0]->Objects[0] = (TObject *)*(unsigned *)&f;

    BathPrice = DisBathPrice(h);
    //BathHours = h;
    BathHours = (double)h + ((double)m / 60.0);
}
//---------------------------------------------------------------------------
double __fastcall TClientsForm::DisBathPrice(int h)
{
/*
    if(h <= 3)
        return 1000;
    else if(h <= 6)
        return 900;
    else if(h <= 9)
        return 750;
    else
        return 600;
*/
    return 950;
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::CalcBathPrice(void)
{
    float price = 0.0;
    unsigned uprice;

    for(int i = 1; i < sgBathResGroup->RowCount; i++)
    {
        uprice = (unsigned)sgBathResGroup->Rows[i]->Objects[3];
        price += *(float *)&uprice;
    }

    // ���-�� �������
    int j = ATOI(sgBathBuf->Cells[3][sgBathBuf->Row].c_str());

    if(j)
    {
        if(price / j >= 1000)
        {
            // ������
            laBathSum->Caption = FormatFloat(MoneyFormat,BathPrice * BathHours * 0.7).TrimLeft();
        }
        else
            laBathSum->Caption = FormatFloat(MoneyFormat,BathPrice * BathHours).TrimLeft();
    }
    else
        laBathSum->Caption = FormatFloat(MoneyFormat,BathPrice * BathHours).TrimLeft();

    if(price > 0)
    {
        laAltSum->Caption = FormatFloat(MoneyFormat,price).TrimLeft();
    }
    else
        laAltSum->Caption = "0.00";

    //return atof(laBathSum->Caption.c_str());
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::sgReserveSelectCell(TObject *Sender,
      int ACol, int ARow, bool &CanSelect)
{
    /*
    if(ReserveIDs && ARow > 0)
    {
        SQL_exefun(NULL,("select ServiceID from Reserve where RowID="+AnsiString(ReserveIDs[sgReserve->Row-1])).c_str(),&retString);

        if(atoi(retString.c_str()) == BATH_COMPLEXID)
        {
            sbRes4Nal->Visible = true;
        }
        else
            sbRes4Nal->Visible = false;
    }
    else
        sbRes4Nal->Visible = false;
    */
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::tvBathResChanging(TObject *Sender,
      TTreeNode *Node, bool &AllowChange)
{
    TTreeNode *pN = Node;
    while(pN->Parent != NULL)
    {
        pN = pN->Parent;
        if(tvBathRes->Selected == pN) return;
    }

    int SID = (int)pN->Data;
    __int64 *pIDs;
    AnsiString *pNames;

    unsigned short y, m, d;
    (BathCurrentDay + BathCurButton).DecodeDate(&y,&m,&d);

    unsigned cnt = SQL_fldKeyCollect
    (
        DBName,
        "Name",
        ("from (select Personal.RowID,Name from Personal,Calendar where Personal.RowID=PersonID and ServiceID="+AnsiString(SID)+" and Alive=1 and CalendarYear="+AnsiString(y)+" and CalendarMonth="+AnsiString(m)+" and bin_and(Days,"+AnsiString(1 << (d-1))+")!=0 order by Name)").c_str(),
        &pIDs,
        &pNames
    );

    cbBathResPerson->Clear();

    for(unsigned i = 0; i < cnt; i++)
    {
        cbBathResPerson->Items->Add(pNames[i]);
        cbBathResPerson->Items->Objects[i] = (TObject *)pIDs[i];
    }

    cbBathResPerson->ItemIndex = 0;
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::paBathResInfoResize(TObject *Sender)
{
    //sbBathResOK->Left = 2;
    //sbBathResOK->Top = 40;
    sbBathResOK->Width = paBathResInfo->Width - 2;
    //sbBathResOK->Height = 24;

    //sbBathResDel->Left = 2;
    //sbBathResDel->Top = 64;
    sbBathResDel->Width = paBathResInfo->Width - 2;
    //sbBathResDel->Height = 24;

    //sbBathResCan->Left = 2;
    //sbBathResCan->Top = 88;
    sbBathResCan->Width = paBathResInfo->Width - 2;
    //sbBathResCan->Height = 24;
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::paBathBufOKResize(TObject *Sender)
{
    //sbBathBufOK->Left = 2;
    //sbBathBufOK->Top = 0;
    sbBathBufOK->Width = paBathBufOK->Width - 2;
    //sbBathBufOK->Height = 24;

    //sbBathBufDel->Left = 2;
    //sbBathBufDel->Top = 24;
    sbBathBufDel->Width = paBathBufOK->Width - 2;
    //sbBathBufDel->Height = 24;

    //sbBathBufCan->Left = 2;
    //sbBathBufCan->Top = 48;
    sbBathBufCan->Width = paBathBufOK->Width - 2;
    //sbBathBufCan->Height = 24;

    //sbBathBufX->Left = 2;
    //sbBathBufX->Top = 72;
    sbBathBufX->Width = paBathBufOK->Width - 2;
    //sbBathBufX->Height = 24;
    //sbBathBufX->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::tbKKMClick(TObject *Sender)
{
    // ������ �����
    //tbKKM->CheckMenuDropdown();
    BillsForm = new TBillsForm(this);
    BillsForm->ShowModal();
    delete BillsForm;
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::pbReportZClick(TObject *Sender)
{
    // Z - �����
    int res = kkm_report_Z();

    if(res == -3828)
        Application->MessageBox("���������� �����!\nZ-����� ��� ���� ��� ��� �������� �����.", Application->Title.c_str(), MB_ICONERROR + MB_OK);
    else if(res != 0)
        Application->MessageBox("��������!\n������ ������ Z-������.", Application->Title.c_str(), MB_ICONERROR + MB_OK);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::pbReportXClick(TObject *Sender)
{
    // X - �����
    int res = kkm_report_X();

    if(res != 0)
        Application->MessageBox("��������!\n������ ������ X-������.", Application->Title.c_str(), MB_ICONERROR + MB_OK);
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::CheckKKMButtons(void)
{
    if(AdminMode)
        pbSettings->Visible = true;

    if(KKM_LINK == -1 && KKM_USE == 1)
    {
        pbOutcome->Enabled = true;
        pbIncome->Enabled = true;
        pbReportZ->Enabled = true;
        pbReportX->Enabled = true;
    }
    else
    {
        pbOutcome->Enabled = false;
        pbIncome->Enabled = false;
        pbReportZ->Enabled = false;
        pbReportX->Enabled = false;
        //pbSettings->Enabled = false;
    }
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::pbSettingsClick(TObject *Sender)
{
    kkm_properties();
}
//---------------------------------------------------------------------------
void __fastcall TClientsForm::pbOutcomeClick(TObject *Sender)
{
    // ������ ��������
    if(((TMenuItem *)Sender)->Tag == 0)
    {
        double d = kkm_getsum();

        if(d > 0)
        {
            KKMOutForm = new TKKMOutForm(this,false);
            KKMOutForm->ShowModal();
            delete KKMOutForm;
        }
        else
            Application->MessageBox("��������!\n���������� ��������� �������� ������.", Application->Title.c_str(), MB_ICONERROR + MB_OK);
    }
    else
    {
        KKMOutForm = new TKKMOutForm(this,true);
        KKMOutForm->ShowModal();
        delete KKMOutForm;
    }
}
//---------------------------------------------------------------------------
bool __fastcall TClientsForm::LoadKassa(__int64 BillID)
{

    //double total, getsum, terminal;

    //TList* pBill =
    //    BuildBillNOT(BillID, &total, &getsum, &terminal);

    __int64 BID;
    AnsiString servName;
    double price, total;
    double group_cnt;

    //const char *,unsigned fld_cnt,const char **fNames,const char *sql_from,const char *sql_order,
    //AnsiString ** pFld,char *mask=NULL);
    AnsiString *pRet;
    const char *fNames[] =
    { "a.RowID", "b.Tag||b.Name", "c.Name", "a.Price", "a.BillItemsCount", "a.Op", "a.Total", "a.Discount", "a.BegTime", "a.EndTime", "a.GoodID" };

    AnsiString sql_from =
        "from BillItems a "
        "left join Services b on a.ServiceID=b.RowID "
        "left join ServNames c on a.ServiceID=c.ServiceID "
        "where a.BillID=";

    sql_from += BillID;

    int h, cnt = SQL_Collect(NULL,11,fNames,sql_from.c_str(),NULL,&pRet);

    KassaForm = new TKassaForm(this);
    KassaForm->InTransaction = true;
    unsigned pos;

    for(int i = 0; i < cnt; i++)
    {
        pos = i * 11;

        BID = ATOI64(pRet[pos].c_str());
        servName = (pRet[pos+2].Length() > 0)? pRet[pos+2] : pRet[pos+1];
        price = ATOF(pRet[pos+3].c_str());
        group_cnt = ATOF(pRet[pos+4].c_str());
        total = ATOF(pRet[pos+6].c_str());


        KassaForm->KassaOps |= ATOI(pRet[pos+5].c_str());

        if((int)KassaForm->Counter >= KassaForm->IDs.Length)
            KassaForm->IDs.Length = KassaForm->IDs.Length + 10;
        KassaForm->IDs[KassaForm->Counter++] = BID;

        if(KassaForm->Counter > 1)
            KassaForm->sgKassa->RowCount++;

        KassaForm->sgKassa->Row = KassaForm->sgKassa->RowCount - 1;

        if(KassaForm->KassaOps & SELLOP_SPA_VISIT)
            KassaForm->sgKassa->Cells[0][KassaForm->sgKassa->Row] = "������ SPA";
        double discount = ATOF(pRet[pos+7].c_str());
        if(KassaForm->KassaOps & SELLOP_BATH)
        {
            KassaForm->sgKassa->Cells[0][KassaForm->sgKassa->Row] = "������ ������";
            // ��������� ��� servName
            h = ATOI(pRet[pos+10].c_str());
            if(h == 0)
                servName = "[����]������";
            else if(h == 1)
                servName = "[����]��������� �������";
            else if(h == 2)
                servName = "[����]������";
            else
                servName = "[����]";
        }
            //discount = 0;

            // ��������� ����������
            //group_cnt = 24.0 * (ATOF(pRet[pos+9].c_str()) - ATOF(pRet[pos+8].c_str()));
            //group_cnt = ATOF();




        double x;
        if(modf(discount,&x) != 0.0)
            KassaForm->sgKassa->Cells[4][KassaForm->sgKassa->Row] = FormatFloat(MoneyFormat,discount).TrimLeft()+"%";
        else
            KassaForm->sgKassa->Cells[4][KassaForm->sgKassa->Row] = (AnsiString)(int)discount+"%";


        //if(discount > 0)
        //{
          
        //    price /= (1.0 - (discount / 100.0));
        //    total = price * group_cnt;
        //}

        KassaForm->sgKassa->Cells[1][KassaForm->sgKassa->Row] = servName;
        KassaForm->sgKassa->Cells[2][KassaForm->sgKassa->Row] = FormatFloat(MoneyFormat,price).TrimLeft();
        KassaForm->sgKassa->Cells[3][KassaForm->sgKassa->Row] = group_cnt;

        KassaForm->sgKassa->Cells[5][KassaForm->sgKassa->Row] = FormatFloat(MoneyFormat,total).TrimLeft();

        KassaForm->Total += total;

        KassaForm->KassaUpdateInfo();
    }

    PDEL(pRet);

    BillsID = 0;

    KassaForm->ShowModal();

    if(FormResult == -1)
    {
        PDEL(IDsAbonements);
        sgClientsRowInfo(&ClientID,0);
    }

    delete KassaForm;
    BillsID = 0;

    return FormResult == -1;
}
//---------------------------------------------------------------------------

