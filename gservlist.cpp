//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "gservlist.h"

#include "lib.h"
#include "clients.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TGSListForm *GSListForm;

extern double UserDiscount;
extern double UserDiscountSPA;
extern const char *MoneyFormat;
extern __int64 ClientID;
bool __fastcall GetSPAServicePrice(double *pPrice,double *pPersonPrice,__int64 SID,unsigned cnt,unsigned minutes,bool fdiscount=true);
//---------------------------------------------------------------------------
__fastcall TGSListForm::TGSListForm(TComponent* Owner)
    : TForm(Owner)
{
    RID = 0;
}
//---------------------------------------------------------------------------
void __fastcall TGSListForm::FormShow(TObject *Sender)
{
    if(!RID)
    {
        Close();
        return;
    }


    //ClientsForm->sgReserve->Row-1

    AnsiString  sRet = ClientsForm->sgReserve->Cells[0][ClientsForm->sgReserve->Row],
                //sPrice,
                *pRow;

    if(sRet.Length() > 0) btSpis->Enabled = false;

    const char *fNames[] = { "b.NAME", "a.QUAN", "b.PARENTID", "c.NAME", "a.NUM", "a.PRICE", "a.SERVICEID", "d.FNAME||' '||d.SNAME", "a.ENDDATE-a.BEGDATE" };

    unsigned pos;
    double quan;

    unsigned cnt;

    SQL_exefun(NULL,("select ServiceID,Price from Reserve where RowID="+AnsiString(RID)).c_str(),&sRet);
    int SID = atoi(sRet.c_str());

    if(SID == BATH_COMPLEXID)
    {
        cnt = SQL_Collect(NULL,9,fNames,("from Reserve a inner join Services b on a.ServiceID=b.RowID inner join Clients d on a.ClientID=d.RowID left join Personal c on a.PersonID=c.RowID where a.ParentID="+AnsiString(RID)).c_str(),"",&pRow);
    }
    else
        cnt = SQL_Collect(NULL,9,fNames,("from Reserve a inner join Services b on a.ServiceID=b.RowID inner join Clients d on a.ClientID=d.RowID left join Personal c on a.PersonID=c.RowID where a.RowID="+AnsiString(RID)).c_str(),"",&pRow);

    TListItem  *ListItem;

    // RID - Complex root ID
    SQL_exefun(NULL,("select Price from Reserve where RowID="+AnsiString(RID)).c_str(),&sRet);
    double pprice, total = 0, atotal = 0, bathprice = atof(sRet.c_str()), price;
    //price = (100 - UserDiscountSPA) * price / 100;

    for(unsigned i = 0; i < cnt; i++)
    {
        pos = i * 9;

        ListItem = lvGSList->Items->Add();
        ListItem->Caption = pRow[pos+7];
        if(atoi(pRow[pos+6].c_str()) == BATH_ID)
        {
            int num = atoi(pRow[4].c_str());
            if(num == 0)
                sRet = "������";
            else if(num == 1)
                sRet = "��������� �������";
            else if(num == 2)
                sRet = "������";
            else
                sRet = "����";

            ListItem->SubItems->Add("[����]" + sRet);
        }
        else
        {
            SQL_exefun(NULL,("select Name from Services where RowID="+AnsiString(_atoi64(pRow[pos+2].c_str()))).c_str(),&sRet);
            ListItem->SubItems->Add("[" + sRet + "]" + pRow[pos]);
        }

        // ����������
        ListItem->SubItems->Add(pRow[pos+3]);
        // ����
        //ListItem->SubItems->Add(pRow[pos+4]);

        quan = atoi(pRow[pos+1].c_str());

        if(!quan) quan++;

        if(atoi(pRow[pos+6].c_str()) == BATH_ID)
        {
            unsigned short h, m, s, ms;
            TDateTime(atof(pRow[pos+8].c_str())).DecodeTime(&h,&m,&s,&ms);
            quan = (double)m / 60 + h;

            price = bathprice;
        }
        else
        {
            // ����
            price = atof(pRow[pos+5].c_str()) * quan;
            if(price == 0)
            {
            // ���� �� ����������
                GetSPAServicePrice(&price,&pprice,SID,quan,0,false);

            
            }
        }
        ListItem->SubItems->Add(quan);
        ListItem->SubItems->Add(FormatFloat(MoneyFormat,price).TrimLeft());

        total += price;

        // �.�. ������ ��� ����������
        //AnsiString sDis, sDisSPA;
        //SQL_exefun2(NULL,("select Discount,DiscountSPA from Clients where RowID="+AnsiString(ClientID)).c_str(),&sDis,&sDisSPA);
        double discount;



        discount = UserDiscountSPA;
        //atof(sDisSPA.c_str());
        if(discount <= 0) discount = UserDiscount;
        //ATOF(sDis.c_str());

        int dt = (int)Now();
        SQL_exefun(NULL,("select count(*) from Abonements where Closed=0 and EndDate>="+AnsiString(dt)+" and ClientID="+AnsiString(ClientID)).c_str(),&sRet);
        dt = ATOI(sRet.c_str());

        if(dt > 0) dt = 10;

        if(discount < dt) discount = dt;

        if(ATOI(pRow[pos+6].c_str()) == BATH_ID)
            price = ATOF(pRow[pos+5].c_str()) * quan;

        price *= (100 - discount) / 100;

        ListItem->SubItems->Add(FormatFloat(MoneyFormat,price).TrimLeft());

        atotal += price;
    }

    // �����:
    ListItem = lvGSList->Items->Add();
    ListItem = lvGSList->Items->Add();
    ListItem->Caption = "�����:";

    ListItem->SubItems->Add("");
    ListItem->SubItems->Add("");
    ListItem->SubItems->Add("");

    ListItem->SubItems->Add(FormatFloat(MoneyFormat,total).TrimLeft());
    ListItem->SubItems->Add(FormatFloat(MoneyFormat,atotal).TrimLeft());

    delete [] pRow;
}
//---------------------------------------------------------------------------
void __fastcall TGSListForm::btSpisClick(TObject *Sender)
{
    // ������� ����, � ����� � �� ������... �� ���. ������
    AnsiString retString;

    __int64 VSID, BID, RID = ClientsForm->ReserveIDs[ClientsForm->sgReserve->Row - 1];
    if(!RID) return;

    SQL_exefun(NULL,("select Tag from Reserve,Services where ServiceID=Services.RowID and Reserve.RowID="+AnsiString(RID)).c_str(),&retString);
    if(retString.Pos("~�������~") > 0) return;

    ClientsForm->SpisFromSPA(RID,retString.Pos("~����~") > 0,true);

    Close();
}
//---------------------------------------------------------------------------

