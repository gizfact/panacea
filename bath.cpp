//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "bath.h"
#include <math.h>
#include "lib.h"                   
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TBathForm *BathForm;

extern const char *MoneyFormat;
extern const char *DBName;

extern int FormResult;
extern double UserDiscountSPA;

extern __int64 VisitServiceID;
extern __int64 VisitPersonID;
extern AnsiString VisitServiceName;
extern double VisitPrice;
extern double VisitBegTime;
extern double VisitEndTime;
extern int iVisitMode;

extern __int64 ClientID;
extern __int64 UserID;

extern int CurDayOfWeek;

bool __fastcall GetSPAServicePrice(double *pPrice,double *pPersonPrice,__int64 SID,unsigned cnt,unsigned minutes,bool fdiscount=true);
//---------------------------------------------------------------------------
__fastcall TBathForm::TBathForm(TComponent* Owner)
    : TForm(Owner)
{
    pServicesIDs = NULL;
    pServices = NULL;
    ServicesCounter = 0;

    pPersonalIDs = NULL;
    pPersonal = NULL;
    PersonalCounter = 0;

    pLevel2IDs = NULL;
    pLevel2 = NULL;
    Level2Counter = 0;

    Price = 0.0;
    PersonPrice = 0.0;

    Timed = 0;

    ResBegDate = 0;
    ResEndDate = 0;

    ResServiceID = 0;
    ResPersonID = 0;

    ResQuan = 1;

    VisitID = 0;

    CloseFlag = false;
}
//---------------------------------------------------------------------------
void __fastcall TBathForm::bCancelClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TBathForm::edMinsKeyPress(TObject *Sender, char &Key)
{
    ud_keyfilter(Key);
}
//---------------------------------------------------------------------------
void __fastcall TBathForm::dtpBegTimeChange(TObject *Sender)
{
    unsigned pos = Edit1->Text.Pos(":");
    int itime = 60 * atoi(Edit1->Text.c_str());
    itime += atoi(Edit1->Text.SubString(pos+1,Edit1->Text.Length()-pos).c_str());

    double d = itime;
    d /= 1440.0;

    dtpEndTime->DateTime = dtpBegTime->DateTime + d;

    laPriceUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TBathForm::FormShow(TObject *Sender)
{
    SQL_exefun(DBName,"select RowID from Services where Name='Баня'",&retString);
    __int64 ID = _atoi64(retString.c_str());
    
    if(!ID)
    {
        Close();
        return;
    }

    Level2Counter = SQL_fldKeyCollect(DBName,"Name",("from Services where bin_and(WeekDays,"+AnsiString(CurDayOfWeek)+")!=0 and ParentID="+AnsiString(ID)+" order by Name").c_str(),&pLevel2IDs,&pLevel2,true);
    if(!Level2Counter)
    {
        Close();
        return;
    }

    LoadBoxSize("Bath",lbLevel01,lbLevel02,lbLevel03);

    for(unsigned i = 0; i < Level2Counter; i++)
        lbLevel01->Items->Add(pLevel2[i]);

    lbLevel01->ItemIndex = 0;

    PersonalCounter = SQL_fldKeyCollect(DBName,"Name",("from Personal where Alive!=0 and ServiceID="+AnsiString(ID)+" order by Name").c_str(),&pPersonalIDs,&pPersonal,true,true);
    //PersonalCounter = SQL_fldKeyCollect(DBName,"Name",("from Personal where Alive!=0 and ServiceID="+AnsiString(ID)+" order by Name").c_str(),&pPersonalIDs,&pPersonal);
    if(PersonalCounter == 0)
    {
        Application->MessageBox("Внимание!\nДля отдела не назначены специалисты.","Ошибка",MB_OK);
        CloseFlag = true;
        return;
    }
    pPersonalIDs[0] = 0;
    pPersonal[0] = "без специалиста";

    TDateTime dt = Now();

    laDate->Caption = "Дата: " + dt.DateString();

    dtpBegTime->DateTime = dt;
    dtpEndTime->DateTime = dt + (1.0/24.0);

    lbServicesUpdate();

    if(!ResServiceID || !ResPersonID || (double)ResBegDate == 0.0 || (double)ResEndDate == 0.0) return;

    // Специалист
    unsigned i;

    for(i = 0; i < PersonalCounter; i++)
        if(pPersonalIDs[i] == ResPersonID) break;

    if(i < PersonalCounter) lbPersonal->ItemIndex = i - Personify;

    // Время
    dtpBegTime->DateTime = ResBegDate;
    dtpEndTime->DateTime = ResEndDate;

    seGroupCnt->Value = ResQuan;

    Edit1->Text = (ResEndDate - ResBegDate).FormatString("hh:nn");

    // Найти цепочку
    __int64 SID1, SID2, SID3 = ResServiceID;

    SQL_exefun(DBName,("select ParentID from Services where RowID="+AnsiString(SID3)).c_str(),&retString);
    SID2 = _atoi64(retString.c_str());
    SQL_exefun(DBName,("select ParentID from Services where RowID="+AnsiString(SID2)).c_str(),&retString);
    SID1 = _atoi64(retString.c_str());

    if(!SID1 || !SID2) return;

    for(i = 0; i < Level2Counter; i++)
        if(pLevel2IDs[i] == SID1) break;

    if(i < Level2Counter)
    {
        lbLevel01->ItemIndex = i;
        lbServicesUpdate();
    }
    else return;

    for(i = 0; i < ServicesCounter; i++)
        if(pServicesIDs[i] == SID2) break;

    if(i < ServicesCounter)
    {
        lbLevel02->ItemIndex = i;
        lbServices2Update();
    }
    else return;

    for(i = 0; i < Services2Counter; i++)
        if(pServices2IDs[i] == SID3) break;

    if(i < Services2Counter)
    {
        lbLevel03->ItemIndex = i;
        lbLevel03Click(this);
    }
    else return;

}
//---------------------------------------------------------------------------
void __fastcall TBathForm::FormDestroy(TObject *Sender)
{
    delete [] pLevel2IDs;
    delete [] pLevel2;

    delete [] pServicesIDs;
    delete [] pServices;

    delete [] pServices2IDs;
    delete [] pServices2;

    delete [] pPersonalIDs;
    delete [] pPersonal;

    SaveBoxSize("Bath",lbLevel01,lbLevel02,lbLevel03);
}
//---------------------------------------------------------------------------
void __fastcall TBathForm::lbServicesUpdate(void)
{
    delete [] pServicesIDs;
    delete [] pServices;
    pServicesIDs = NULL;
    pServices = NULL;
    ServicesCounter = 0;

    //lbServices->Clear();
    lbLevel02->Clear();

    //if(lbLevel2->ItemIndex < 0) return;
    if(lbLevel01->ItemIndex < 0) return;

    ServicesCounter = SQL_fldKeyCollect(DBName,"Name",("from Services where bin_and(WeekDays,"+AnsiString(CurDayOfWeek)+")!=0 and ParentID="+AnsiString(pLevel2IDs[lbLevel01->ItemIndex])+" order by Name").c_str(),&pServicesIDs,&pServices,true);
    for(unsigned i = 0; i < ServicesCounter; i++)
    {
        //lbServices->Items->Add(pServices[i]);
        lbLevel02->Items->Add(pServices[i]);
    }
    //lbServices->ItemIndex = 0;
    lbLevel02->ItemIndex = 0;

    lbServices2Update();
}
//---------------------------------------------------------------------------
void __fastcall TBathForm::lbServices2Update(void)
{
    delete [] pServices2IDs;
    delete [] pServices2;
    pServices2IDs = NULL;
    pServices2 = NULL;
    Services2Counter = 0;

    //lbServices2->Clear();
    lbLevel03->Clear();

    //if(lbServices->ItemIndex < 0) return;
    if(lbLevel02->ItemIndex < 0) return;

    Services2Counter = SQL_fldKeyCollect(DBName,"Name",("from Services where bin_and(WeekDays,"+AnsiString(CurDayOfWeek)+")!=0 and ParentID="+AnsiString(pServicesIDs[lbLevel02->ItemIndex])+" order by Name").c_str(),&pServices2IDs,&pServices2,true);
    for(unsigned i = 0; i < Services2Counter; i++)
    {
        //lbServices2->Items->Add(pServices2[i]);
        lbLevel03->Items->Add(pServices2[i]);
    }
    //lbServices2->ItemIndex = 0;
    lbLevel03->ItemIndex = 0;

    if(lbLevel03->ItemIndex >= 0)
    {
        SQL_exefun(DBName,("select Timed from Services where RowID="+AnsiString(pServices2IDs[lbLevel03->ItemIndex])).c_str(),&retString);
        Timed = atoi(retString.c_str());
    }
    else
    if(lbLevel02->ItemIndex >= 0)
    {
        SQL_exefun(DBName,("select Timed from Services where RowID="+AnsiString(pServicesIDs[lbLevel02->ItemIndex])).c_str(),&retString);
        Timed = atoi(retString.c_str());
    }
    else
    Timed = 0;

    if((int)ResEndDate && (int)ResBegDate)
        dtpBegTime->DateTime = ResBegDate;
    int itime = Timed? Timed : ((int)ResEndDate && (int)ResBegDate)? SimpleRoundTo((double)(ResEndDate - ResBegDate) * 1440.0,0) : 30;

    //if((int)ResEndDate && (int)ResBegDate)
    //{
    //    dtpBegTime->DateTime = ResBegDate;
    //      dtpEndTime->DateTime = ResEndDate;
    //    Edit1->Text = (ResEndDate - ResBegDate).FormatString("hh:nn");

        //itime = SimpleRoundTo((double)(ResEndDate - ResBegDate) * 1440.0,0);
    //}
    //else
    Edit1->Text = Edit1->Text.sprintf("%02d:%02d",itime/60,itime%60);

    double d = itime;
    d /= 1440.0;

    dtpEndTime->DateTime = dtpBegTime->DateTime + d;

    seGroupCnt->Value = ResQuan;

    laPriceUpdate();
    lbPersonalUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TBathForm::lbPersonalUpdate(void)
{
    lbPersonal->Clear();

    TListBox *pCombo;
    __int64 *pIDs;

    if(lbLevel03->ItemIndex >= 0)
    {
        pCombo = lbLevel03;
        pIDs = pServices2IDs;
    }
    else
    //if(lbServices->ItemIndex >= 0)
    {
        pCombo = lbLevel02;
        pIDs = pServicesIDs;
    }


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

        lbPersonal->ItemIndex = 0;
    }
    if(lbPersonal->ItemIndex < 0)
    {
        Personify = -1;
        lbPersonal->Items->Add(pPersonal[0]);
        lbPersonal->ItemIndex = 0;
    }
}
//---------------------------------------------------------------------------
void __fastcall TBathForm::laPriceUpdate(void)
{
    TListBox *pCombo;
    __int64 *pIDs;

    if(lbLevel03->ItemIndex >= 0)
    {
        pCombo = lbLevel03;
        pIDs = pServices2IDs;
    }
    else
    if(lbLevel02->ItemIndex >= 0)
    {
        pCombo = lbLevel02;
        pIDs = pServicesIDs;
    }
    else
    {
        Price = 0.0;
        PersonPrice = 0.0;
        laPrice->Caption = "Цена:";
        return;
    }

    unsigned pos = Edit1->Text.Pos(":");
    int itime = 60 * atoi(Edit1->Text.c_str());
    itime += atoi(Edit1->Text.SubString(pos+1,Edit1->Text.Length()-pos).c_str());

    if(GetSPAServicePrice(&Price,&PersonPrice,pIDs[pCombo->ItemIndex],seGroupCnt->Value,itime))
        seGroupCnt->Enabled = true;
    else
    {
        seGroupCnt->Enabled = false;
        seGroupCnt->Value = 1;
    }

    laPrice->Caption = "Цена: " + FormatFloat(MoneyFormat,Price)+" руб.";
}
//---------------------------------------------------------------------------
void __fastcall TBathForm::bOKClick(TObject *Sender)
{
    if(!iVisitMode)
    {
        if(lbLevel03->ItemIndex >= 0)
        {
            VisitServiceID = pServices2IDs[lbLevel03->ItemIndex];
            VisitServiceName = "["+pServices[lbLevel02->ItemIndex]+"]"+pServices2[lbLevel03->ItemIndex];
        }
        else
        {
            VisitServiceID = pServicesIDs[lbLevel02->ItemIndex];
            VisitServiceName = pServices[lbLevel02->ItemIndex];
        }
        VisitPrice = Price;
        //atof(laPrice->Caption.SubString(7,laPrice->Caption.Length()-7).c_str());

        if(Personify >= 0)
            VisitPersonID = pPersonalIDs[lbPersonal->ItemIndex+Personify];
        else
            VisitPersonID = 0;
        VisitBegTime = dtpBegTime->Time;
        VisitEndTime = dtpEndTime->Time;

        FormResult = 1;
        Close();
        return;
    }

    TDateTime dt = Now();

    if(dtpEndTime->Time < dtpBegTime->Time)
    {
        Application->MessageBox("Внимание!\nВремя завершения занятия должно быть больше времени начала занятия.","Ошибка ввода",MB_OK);
        return;
    }

    if(SPABalanse < Price)
    {
        Application->MessageBox("Внимание!\nЦена услуги превышает доступный баланс SPA-Абонемента.\nПроведение услуги невозможно.","",MB_OK);
        return;
    }

    if(SQL_BeginTransaction() != SQLITE_OK) return;

    __int64 ID;
    if(lbLevel03->ItemIndex >= 0)
        ID = pServices2IDs[lbLevel03->ItemIndex];
    else
        ID = pServicesIDs[lbLevel02->ItemIndex];

    //double price = atof(laPrice->Caption.SubString(7,laPrice->Caption.Length()-7).c_str());
    VisitPrice = Price;
    AnsiString sBalanse;

    SQL_exefun2(DBName,("select first 1 RowID,Balanse from Abonements_SPA where Closed=0 and ClientID="+AnsiString(ClientID)+" order by BegDate,CDate").c_str(),&retString,&sBalanse);
    __int64 AbSPAID = _atoi64(retString.c_str());
    double balanse = atof(sBalanse.c_str());

    balanse -= Price;
    if(balanse < 0.0) balanse = 0.0;

    SQL_iniInsert(DBName,"Visits_SPA",&VisitID);
    SQL_addInsert("AbonementID",AbSPAID);
    SQL_addInsert("ClientID",ClientID);

    SQL_addInsert("Visits_SPADate",(double)dt);
    SQL_addInsert("BegTime",(double)dtpBegTime->Time);
    SQL_addInsert("EndTime",(double)dtpEndTime->Time);
    SQL_addInsert("Price",Price);

    //SQL_exefun(DBName,("select PersonPrice from Services where RowID="+AnsiString(ID)).c_str(),&retString);
    //price = atof(retString.c_str());
    //price = (price * (100.0 - UserDiscountSPA)) / 100.0;

    SQL_addInsert("PersonPrice",PersonPrice);
    SQL_addInsert("GroupCnt",seGroupCnt->Value);
    if(Personify >= 0)
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

    // Списание материалов
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

            int rate = -atoi(pGoods[(j<<1)+1].c_str()) * seGroupCnt->Value;
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
                // Есть остатки
                rate = 1000 * count + part + rate;
                part = rate % 1000;
                count = rate / 1000;

                SQL_iniUpdate(DBName,"Stock",GID);
                SQL_addUpdate("StockCount",count);
                SQL_exeUpdate("Part",part);
            }
            else
            {
                // Ничего нет
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

    if(SQL_CommitTransaction() == SQLITE_OK)
        FormResult = 1;

    Close();
}
//---------------------------------------------------------------------------
void __fastcall TBathForm::CSpinButton1DownClick(TObject *Sender)
{
    // Вниз
    int period = Timed? Timed : 30;

    unsigned pos = Edit1->Text.Pos(":");
    int itime = 60 * atoi(Edit1->Text.c_str());
    itime += (atoi(Edit1->Text.SubString(pos+1,Edit1->Text.Length()-pos).c_str()) - period);

    if(itime < 0)
        itime += 1440;

    double d = itime;
    d /= 1440.0;

    Edit1->Text = Edit1->Text.sprintf("%02d:%02d",itime/60,itime%60);

    dtpEndTime->DateTime = dtpBegTime->DateTime + d;
    laPriceUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TBathForm::CSpinButton1UpClick(TObject *Sender)
{
    // Вверх
    int period = Timed? Timed : 30;

    unsigned pos = Edit1->Text.Pos(":");
    int itime = 60 * atoi(Edit1->Text.c_str());
    itime += (atoi(Edit1->Text.SubString(pos+1,Edit1->Text.Length()-pos).c_str()) + period);

    if(itime >= 1440)
        itime -= 1440;

    double d = itime;
    d /= 1440.0;

    Edit1->Text = Edit1->Text.sprintf("%02d:%02d",itime/60,itime%60);

    dtpEndTime->DateTime = dtpBegTime->DateTime + d;
    laPriceUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TBathForm::seGroupCntChange(TObject *Sender)
{
    laPriceUpdate();
    //lbPersonalUpdate();    
}
//---------------------------------------------------------------------------
void __fastcall TBathForm::lbLevel01Click(TObject *Sender)
{
    lbServicesUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TBathForm::lbLevel02Click(TObject *Sender)
{
    lbServices2Update();
}
//---------------------------------------------------------------------------
void __fastcall TBathForm::lbLevel03Click(TObject *Sender)
{
    if(lbLevel03->ItemIndex >= 0)
    {
        SQL_exefun(DBName,("select Timed from Services where RowID="+AnsiString(pServices2IDs[lbLevel03->ItemIndex])).c_str(),&retString);
        Timed = atoi(retString.c_str());
    }
    else
        Timed = 0;

    //int itime = Timed? Timed : 30;
    if((int)ResEndDate && (int)ResBegDate)
        dtpBegTime->DateTime = ResBegDate;
    int itime = Timed? Timed : ((int)ResEndDate && (int)ResBegDate)? SimpleRoundTo((double)(ResEndDate - ResBegDate) * 1440.0,0) : 30;


    Edit1->Text = Edit1->Text.sprintf("%02d:%02d",itime/60,itime%60);

    double d = itime;
    d /= 1440.0;

    dtpEndTime->DateTime = dtpBegTime->DateTime + d;
    seGroupCnt->Value = ResQuan;

    laPriceUpdate();
    lbPersonalUpdate();
}
//---------------------------------------------------------------------------

void __fastcall TBathForm::FormPaint(TObject *Sender)
{
    if(CloseFlag)
        Close();    
}
//---------------------------------------------------------------------------

