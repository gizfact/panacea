//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "i_visits.h"
#include "lib.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TiVisitsForm *iVisitsForm;

extern const char *DBName;
extern __int64 UserID;

extern __int64 ClientID;

__int64 VisitServiceID;
__int64 VisitPersonID;
AnsiString VisitServiceName;
double VisitPrice;
double VisitBegTime;
double VisitEndTime;

int iVisitMode = 0;

extern int FormResult;

extern double UserDiscountSPA;

extern const char *MoneyFormat;
extern int CurDayOfWeek;
//---------------------------------------------------------------------------
__fastcall TiVisitsForm::TiVisitsForm(TComponent* Owner)
    : TForm(Owner)
{
    PersonPrice = 0.0;

    ResServiceID = 0;
    ResPersonID = 0;
    ResBegDate = 0;
    ResEndDate = 0;

    VisitID = 0;

    CloseFlag = false;
}
//---------------------------------------------------------------------------
void __fastcall TiVisitsForm::FormShow(TObject *Sender)
{
    TDateTime dt = Now();

    laDate->Caption = "����: " + dt.DateString();

    dtpBegTime->DateTime = dt;
    dtpEndTime->DateTime = dt + (1.0/1440.0);

    //UsersCounter = UserInit(DBName,&pUserIDs,&pUsers);
    LoadBoxSize("Visits",lbLevel1,lbLevel2,lbLevel3);

    AnsiString sPID, sSID;
    __int64 ID;

    SQL_exefun(DBName,("select RowID from Services where Name='"+Tag+"'").c_str(),&retString);
    PersonalCounter = SQL_fldKeyCollect(DBName,"Name",("from Personal where Alive!=0 and ServiceID="+AnsiString(atoi(retString.c_str()))+" order by Name").c_str(),&pPersonalIDs,&pPersonal,true,true);

    if(PersonalCounter <= 1)
    {
        Application->MessageBox("��������!\n��� ������ �� ��������� �����������.","������",MB_OK);
        CloseFlag = true;
        return;
    }

    pPersonalIDs[0] = 0;
    if(Tag == "SPA")
        pPersonal[0] = "��� �����������";
    else
        pPersonal[0] = "��� �������";


    SQL_exefun(DBName,("select Personify from Services where RowID="+retString).c_str(),&retString);
    Personify = atoi(retString.c_str());
    if(Personify > 1) Personify = 1;

    if(Personify >= 0)
        for(unsigned i = Personify; i < PersonalCounter; i++)
            lbPersonal->Items->Add(pPersonal[i]);
    else
        lbPersonal->Items->Add(pPersonal[0]);

    lbPersonal->ItemIndex = 0;

    if(lbPersonal->ItemIndex < 0)
    {
        Personify = -1;
        lbPersonal->Items->Add(pPersonal[0]);
        lbPersonal->ItemIndex = 0;
    }

    ID = _atoi64(sPID.c_str());

    for(unsigned i = 0; i < PersonalCounter; i++)
    {
        //lbPersonal->Items->Add(pPersonal[i]);
        if(pPersonalIDs[i] == ID)
            lbPersonal->ItemIndex = i;
    }
    if(lbPersonal->ItemIndex < 0) lbPersonal->ItemIndex = 0;

    //PersonalUpdate();

    if(Tag == "�������")
    {
        paSPA->Visible = false;
        laPrice->Visible = false;
        laMins->Caption = "�������:";
        edMins->Visible = false;
        laProc->Visible = false;
        iVisitsForm->Width = 423;
        iVisitsForm->Height = 226;
        Bevel2->Top = 144;

        bOK->Top = 162;
        bCancel->Top = 162;

        SQL_exefun2(DBName,("select first 1 PersonID,ServiceID from Abonements where Closed=0 and FixSum>=0 and ClientID="+(AnsiString)ClientID+" order by BegDate,CDate").c_str(),&sPID,&sSID);

        AnsiString sql =
"from Services where bin_and(WeekDays,"+AnsiString(CurDayOfWeek)+")!=0 and RowID not in (select distinct ParentID from Services) and "
"Tag like '~"+(Tag)+
"~%' order by Name";

        ServicesCounter = SQL_fldKeyCollect(DBName,"Name",sql.c_str(),&pServicesIDs,&pServices,true,true);

        pServicesIDs[0] = 0;
        pServices[0] = "�����������";

        ID = _atoi64(sSID.c_str());
        for(unsigned i = 0; i < ServicesCounter; i++)
        {
            lbServices->Items->Add(pServices[i]);
            if(pServicesIDs[i] == ID)
                lbServices->ItemIndex = i;
        }
        if(lbServices->ItemIndex < 0) lbServices->ItemIndex = 0;
    }
    else if(Tag == "SPA")
    {
        AnsiString *pLevel;
        //, sDiscount;

        lbServices->Visible = false;
        laBeg->Caption = "������ ���������:";
        //laEnd->Caption = "����������:";
        laPerson->Caption = "����������:";

        Discount = UserDiscountSPA;

        //ID = _atoi64(sSID.c_str());
        //__int64 ID1 = 0, ID2 = 0;
        //SQL_exefun(DBName,("select ParentID from Services where RowID="+AnsiString(ID)).c_str(),&retString);
        //ID2 = _atoi64(retString.c_str());
        //SQL_exefun(DBName,("select ParentID from Services where RowID="+AnsiString(ID2)).c_str(),&retString);
        //ID1 = _atoi64(retString.c_str());

        unsigned cnt = SQL_fldCollect(DBName,"Name",("from Services where bin_and(WeekDays,"+AnsiString(CurDayOfWeek)+")!=0 and Tag='~SPA~' order by Name").c_str(),&pLevel,true);

        for(unsigned i = 0; i < cnt; i++)
        {
            lbLevel1->Items->Add(pLevel[i]);
            //if(pServicesIDs[i] == ID1)
            //    lbLevel1->ItemIndex = i;
        }
        lbLevel1->ItemIndex = 0;
        delete [] pLevel;
        lbLevel1Click(Sender);
    }

    if(!ResServiceID || !ResPersonID || (double)ResBegDate == 0.0 || (double)ResEndDate == 0.0) return;

    // ����������
    unsigned i;

    for(i = 0; i < PersonalCounter; i++)
        if(pPersonalIDs[i] == ResPersonID) break;

    if(i < PersonalCounter) lbPersonal->ItemIndex = i;

    // �����
    dtpBegTime->DateTime = ResBegDate;
    dtpEndTime->DateTime = ResEndDate;

    //Edit1->Text = (ResEndDate - ResBegDate).FormatString("hh:nn");
    edMins->Text = SimpleRoundTo((double)(ResEndDate - ResBegDate) * 1440.0,0);

    // ����� �������
    AnsiString sN1, sN2;
    __int64 SID1, SID2, SID3 = ResServiceID;

    SQL_exefun(DBName,("select ParentID,Name from Services where RowID="+AnsiString(SID3)).c_str(),&retString);
    SID2 = _atoi64(retString.c_str());
    SQL_exefun2(DBName,("select ParentID,Name from Services where RowID="+AnsiString(SID2)).c_str(),&retString,&sN2);
    SID1 = _atoi64(retString.c_str());


    if(!SID1 || !SID2) return;

    SQL_exefun(DBName,("select Name from Services where RowID="+AnsiString(SID1)).c_str(),&sN1);

    //sN1 = (sN1);
    //sN2 = (sN2);

    for(i = 0; i < lbLevel1->Count; i++)
        if(lbLevel1->Items->Strings[i] == sN1) break;

    if(i < lbLevel1->Count)
    {
        lbLevel1->ItemIndex = i;
        lbLevel1Click(Sender);
    }
    else return;

    for(i = 0; i < lbLevel2->Count; i++)
        if(lbLevel2->Items->Strings[i] == sN2) break;

    if(i < lbLevel2->Count)
    {
        lbLevel2->ItemIndex = i;
        lbLevel2Click(Sender);
    }
    else return;

    for(i = 0; i < ServicesCounter; i++)
        if(pServicesIDs[i] == SID3) break;

    if(i < ServicesCounter)
    {
        lbLevel3->ItemIndex = i;
        lbLevel3Click(this);
    }
    else return;
}
//---------------------------------------------------------------------------
void __fastcall TiVisitsForm::FormDestroy(TObject *Sender)
{
    //PDEL(pUsers);
    //PDEL(pUserIDs);
    PDEL(pPersonalIDs);
    PDEL(pPersonal);
    PDEL(pServicesIDs);
    PDEL(pServices);
    //PDEL(pServicesPrice);
    SaveBoxSize("Visits",lbLevel1,lbLevel2,lbLevel3);
}
//---------------------------------------------------------------------------
void __fastcall TiVisitsForm::bCancelClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TiVisitsForm::bOKClick(TObject *Sender)
{
    //if(Tag == "SPA")
    //    lbLevel3Click(Sender);
    
    TDateTime dt = Now();

    if(dtpEndTime->Time < dtpBegTime->Time)
    {
        Application->MessageBox("��������!\n����� ���������� ������� ������ ���� ������ ������� ������ �������.","������ �����",MB_OK);
        return;
    }

    if(!iVisitMode)
    {
        if(Tag == "SPA")
        {
            VisitServiceID = pServicesIDs[lbLevel3->ItemIndex];
            VisitServiceName =
            "["+lbLevel2->Items->Strings[lbLevel2->ItemIndex]+"]"+
            lbLevel3->Items->Strings[lbLevel3->ItemIndex];
            VisitPrice = atof(laPrice->Caption.SubString(7,laPrice->Caption.Length()-7).c_str());

            SQL_exefun(DBName,("select PersonPrice from Services where RowID="+AnsiString(VisitServiceID)).c_str(),&retString);
            PersonPrice = atof(retString.c_str());
            PersonPrice = (PersonPrice * (100.0 - Discount)) / 100.0;
        }
        else
        {
            VisitServiceID = pServicesIDs[lbServices->ItemIndex];
            VisitServiceName = lbServices->Items->Strings[lbServices->ItemIndex];
        }

        if(Personify < 0)
            VisitPersonID = 0;
        else
            VisitPersonID = pPersonalIDs[lbPersonal->ItemIndex+Personify];
        VisitBegTime = dtpBegTime->Time;
        VisitEndTime = dtpEndTime->Time;
    }
    else if(Tag == "�������")
    {
        // �������� ������ ���������
        if(SQL_BeginTransaction() != SQLITE_OK) return;

        AnsiString pRow[5];
        SQL_exefunrow(DBName,("select first 1 RowID,Price,AbonementsCount,FixSum,Name from Abonements where Closed=0 and FixSum>=0 and ClientID="+(AnsiString)ClientID+" order by BegDate,CDate").c_str(),5,pRow);

        __int64 AbID = _atoi64(pRow[0].c_str());

        double price = atof(pRow[1].c_str());
        unsigned count = atoi(pRow[2].c_str());
        double fixsum = atof(pRow[3].c_str());

        //__int64 VID, PID = 0;

        SQL_iniInsert(DBName,"Visits",&VisitID);
        SQL_addInsert("AbonementID",AbID);

        SQL_addInsert("VisitsDate",(double)dt);
        SQL_addInsert("BegTime",(double)dtpBegTime->Time);
        SQL_addInsert("EndTime",(double)dtpEndTime->Time);

        if(fixsum > 0.0)
            SQL_addInsert("Price",fixsum);
        else
        {
            if(count != 0.0)
                SQL_addInsert("Price",price/count);
            // ����� ���� ������� �����
            else if(pRow[4].Pos("������� �����") > 0)
                SQL_addInsert("Price",0);
            else
            {
                SQL_CancelTransaction();
                Application->MessageBox("��������!\n���-�� ������� ����� 0.","������ ��",MB_OK);
                Close();
                return;
            }
        }

        if(Personify < 0)
            SQL_addInsert("PersonID",0);
        else
            SQL_addInsert("PersonID",pPersonalIDs[lbPersonal->ItemIndex+Personify]);
        SQL_addInsert("ServiceID",pServicesIDs[lbServices->ItemIndex]);

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
                Close();
                return;
            }

            SQL_iniInsert(DBName,"Visits");
            SQL_addInsert("AbonementID",AbID);

            SQL_addInsert("VisitsDate",(double)dt);
            SQL_addInsert("BegTime",(double)dtpBegTime->Time);
            SQL_addInsert("EndTime",(double)dtpEndTime->Time);
            SQL_addInsert("Price",price);
            SQL_addInsert("PersonID",0);
            SQL_addInsert("ServiceID",ID);

            SQL_addInsert("CDate",(double)dt);
            SQL_addInsert("CUID",UserID);
            SQL_addInsert("EDate",(double)dt);
            SQL_addInsert("ParentID",VisitID);
            SQL_exeInsert("EUID",UserID);
        }

        SQL_CommitTransaction();
    }
    else if(Tag == "SPA")
    {
        // ���� ������, ������
        double price = atof(laPrice->Caption.SubString(7,laPrice->Caption.Length()-7).c_str());

        if(SPABalanse < price)
        {
            Application->MessageBox("��������!\n���� ������ ��������� ��������� ������ SPA-����������.\n���������� ������ ����������.","",MB_OK);
            return;

        }

        if(SQL_BeginTransaction() != SQLITE_OK) return;

        __int64 ID = pServicesIDs[lbLevel3->ItemIndex];

        //SQL_exefun(DBName,("select Price from Services where RowID="+AnsiString(ID)).c_str(),&retString);

        VisitPrice = price;
        AnsiString sBalanse;

        SQL_exefun2(DBName,("select first 1 RowID,Balanse from Abonements_SPA where Closed=0 and ClientID="+AnsiString(ClientID)+" order by BegDate,CDate").c_str(),&retString,&sBalanse);
        __int64 AbSPAID = _atoi64(retString.c_str());
        double balanse = atof(sBalanse.c_str());

        balanse -= price;
        if(balanse < 0.0) balanse = 0.0;

        SQL_iniInsert(DBName,"Visits_SPA",&VisitID);
        SQL_addInsert("AbonementID",AbSPAID);

        SQL_addInsert("Visits_SPADate",(double)dt);
        SQL_addInsert("BegTime",(double)dtpBegTime->Time);
        SQL_addInsert("EndTime",(double)dtpEndTime->Time);
        SQL_addInsert("Price",price);

        SQL_exefun(DBName,("select PersonPrice from Services where RowID="+AnsiString(ID)).c_str(),&retString);
        price = atof(retString.c_str());
        price = (price * (100.0 - Discount)) / 100.0;

        SQL_addInsert("PersonPrice",price);
        if(Personify < 0)
            SQL_addInsert("PersonID",0);
        else
            SQL_addInsert("PersonID",pPersonalIDs[lbPersonal->ItemIndex+Personify]);
        SQL_addInsert("ServiceID",ID);

        SQL_addInsert("CDate",(double)dt);
        SQL_addInsert("CUID",UserID);
        SQL_addInsert("EDate",(double)dt);
        SQL_exeInsert("EUID",UserID);

        SQL_iniUpdate(DBName,"Abonements_SPA",AbSPAID);
        SQL_addUpdate("EDate",(double)dt);
        SQL_addUpdate("EUID",UserID);
        SQL_exeUpdate("Balanse",balanse);

        // �������� ����������
        AnsiString *pGoods;
        const char *pF[] = { "GoodID", "Rate" };

        unsigned gcnt = SQL_Collect(DBName,2,pF,("from ServiceGoods where ServiceID="+AnsiString(ID)).c_str(),NULL,&pGoods);

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
                SQL_addInsert("ServiceID",ID);
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

        //if(sOutcomeData.Length() > 0) sOutcomeData.SetLength(sOutcomeData.Length()-1);
        //if(sStockData.Length() > 0) sOutcomeData.SetLength(sOutcomeData.Length()-1);

        SQL_CommitTransaction();
    }
    else
    {
        FormResult = 0;
        Close();
        return;
    }

    FormResult = 1;
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TiVisitsForm::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key == VK_ESCAPE)
    {
        Key = 0;
        Close();
    }
    if(Key == VK_RETURN)
    {
        Key = 0;
        bOKClick(Sender);
    }
}
//---------------------------------------------------------------------------
void __fastcall TiVisitsForm::lbLevel1Click(TObject *Sender)
{
    if(lbLevel1->ItemIndex < 0) return;

    AnsiString *pLevel;
    unsigned cnt = SQL_fldCollect(DBName,"Name",("from Services where bin_and(WeekDays,"+AnsiString(CurDayOfWeek)+")!=0 and Tag='~SPA~"+(lbLevel1->Items->Strings[lbLevel1->ItemIndex])+"~' order by Name").c_str(),&pLevel,true);
    lbLevel2->Clear();

    for(unsigned i = 0; i < cnt; i++)
        lbLevel2->Items->Add(pLevel[i]);

    lbLevel2->ItemIndex = 0;

    lbLevel2Click(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TiVisitsForm::lbLevel2Click(TObject *Sender)
{
    AnsiString *pLevel;
    AnsiString sTag = "~SPA~"+ lbLevel1->Items->Strings[lbLevel1->ItemIndex] + "~" + lbLevel2->Items->Strings[lbLevel2->ItemIndex] + "~";

    delete [] pServicesIDs;

    unsigned cnt = SQL_fldKeyCollect(DBName,"Name",("from Services where bin_and(WeekDays,"+AnsiString(CurDayOfWeek)+")!=0 and Tag='"+(sTag)+"' order by Name").c_str(),&pServicesIDs,&pLevel,true);

    lbLevel3->Clear();

    for(unsigned i = 0; i < cnt; i++)
        lbLevel3->Items->Add(pLevel[i]);

    delete [] pLevel;
    lbLevel3->ItemIndex = 0;

    lbLevel3Click(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TiVisitsForm::lbLevel3Click(TObject *Sender)
{
    double price;
    AnsiString sTimed;

    SQL_exefun2(DBName,("select Price,Timed from Services where RowID="+AnsiString(pServicesIDs[lbLevel3->ItemIndex])).c_str(),&retString,&sTimed);
    int timed = atoi(sTimed.c_str());

    if(timed)
    {
        //int part = strtof(AnsiString((1440.0*((double)dtpEndTime->DateTime - (double)dtpBegTime->DateTime))/timed).c_str(),0);
        price = atof(edMins->Text.c_str());
        price = (price * atof(retString.c_str()) * (100.0 - Discount)) / 100.0;
    }
    else
        price = (atof(retString.c_str()) * (100.0 - Discount)) / 100.0;

    laPrice->Caption = "����: " + FormatFloat(MoneyFormat,price)+" ���.";

    PersonalUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TiVisitsForm::PersonalUpdate(void)
{
    int oldi = lbPersonal->ItemIndex;
    int cnt = lbPersonal->Items->Count;

    lbPersonal->Clear();



    TListBox *pCombo;
    __int64 *pIDs;

    //if(lbLevel3->ItemIndex >= 0)
    //{
        pCombo = lbLevel3;
        pIDs = pServicesIDs;
    //}
    //else
    //if(lbServices->ItemIndex >= 0)
    //{
    //    pCombo = lbLevel2;
    //    pIDs = pServicesIDs;
    //}


    if(pCombo->ItemIndex >= 0)
    {
        SQL_exefun(DBName,("select Personify from Services where RowID="+AnsiString(pIDs[pCombo->ItemIndex])).c_str(),&retString);
        Personify = atoi(retString.c_str());
        if(Personify > 1) Personify = 1;

        if(Personify >= 0)
            for(unsigned i = Personify; i < PersonalCounter; i++)
                lbPersonal->Items->Add(pPersonal[i]);
        else
            lbPersonal->Items->Add(pPersonal[0]);

        //lbPersonal->ItemIndex = 0;
    }

    if(cnt < lbPersonal->Items->Count)
        lbPersonal->ItemIndex = oldi + 1;
    else if(cnt == lbPersonal->Items->Count)
        lbPersonal->ItemIndex = oldi;
    else
        lbPersonal->ItemIndex = oldi - 1;

    if(lbPersonal->ItemIndex < 0)
    {
        Personify = -1;
        lbPersonal->Items->Add(pPersonal[0]);
        lbPersonal->ItemIndex = 0;
    }
}
//---------------------------------------------------------------------------
void __fastcall TiVisitsForm::dtpEndTimeChange(TObject *Sender)
{
    if(dtpEndTime->DateTime <= dtpBegTime->DateTime)
        dtpBegTime->DateTime = (double)dtpEndTime->DateTime - 1.0/1440.0;

    edMins->Text = strtof(AnsiString(((double)dtpEndTime->DateTime - (double)dtpBegTime->DateTime) * 1440.0).c_str(),0);

    lbLevel3Click(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TiVisitsForm::dtpBegTimeChange(TObject *Sender)
{
    if(dtpBegTime->DateTime >= dtpEndTime->DateTime)
        dtpEndTime->DateTime = (double)dtpBegTime->DateTime + 1.0/1440.0;

    edMins->Text = strtof(AnsiString(((double)dtpEndTime->DateTime - (double)dtpBegTime->DateTime) * 1440.0).c_str(),0);

    lbLevel3Click(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TiVisitsForm::edMinsExit(TObject *Sender)
{
    dtpEndTime->DateTime = dtpBegTime->DateTime + (atof(edMins->Text.c_str()) / 1440.0);
}
//---------------------------------------------------------------------------
void __fastcall TiVisitsForm::edMinsKeyPress(TObject *Sender, char &Key)
{
    ui_keyfilter(Key);
}
//---------------------------------------------------------------------------


void __fastcall TiVisitsForm::FormPaint(TObject *Sender)
{
    if(CloseFlag)
        Close();    
}
//---------------------------------------------------------------------------

