//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "barber.h"
#include "lib.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TBarberForm *BarberForm;

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

const char *pColors[] = {
    "Wella",
    "Schwarzcopf",
    "Schwarzcopf Blond me",
    "Schwarzcopf Igora Vario Blond",
    "Schwarzcopf Natural",
    "L'Oreal Efassor"
};

const char *pGr = "гр.";
const char *pMl = "мл.";
//---------------------------------------------------------------------------
__fastcall TBarberForm::TBarberForm(TComponent* Owner)
    : TForm(Owner)
{
    CloseFlag = false;

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

    pAddOps = new addop_type[6];

    pAddOps[0].count = 2;
    pAddOps[0].label = pGr;
    pAddOps[0].lines[0] = pColors[0];
    pAddOps[0].lines[1] = pColors[1];
    pAddOps[0].price[0] = 18.0;
    pAddOps[0].price[1] = 13.0;

    pAddOps[1].count = 2;
    pAddOps[1].label = pGr;
    pAddOps[1].lines[0] = pColors[2];
    pAddOps[1].lines[1] = pColors[3];
    pAddOps[1].price[0] = 13.0;
    pAddOps[1].price[1] = 13.0;

    pAddOps[2].count = 4;
    pAddOps[2].label = pGr;
    pAddOps[2].lines[0] = pColors[0];
    pAddOps[2].lines[1] = pColors[1];
    pAddOps[2].lines[2] = pColors[2];
    pAddOps[2].lines[3] = pColors[3];
    pAddOps[2].price[0] = 18.0;
    pAddOps[2].price[1] = 13.0;
    pAddOps[2].price[2] = 13.0;
    pAddOps[2].price[3] = 13.0;

    pAddOps[3].count = 1;
    pAddOps[3].label = pGr;
    pAddOps[3].lines[0] = pColors[5];
    pAddOps[3].price[0] = 13.0;

    pAddOps[4].count = 1;
    pAddOps[4].label = pMl;
    pAddOps[4].lines[0] = pColors[4];
    pAddOps[4].price[0] = 13.0;

    pAddOps[5].count = 1;
    pAddOps[5].label = pMl;
    pAddOps[5].lines[0] = pColors[4];
    pAddOps[5].price[0] = 13.0;

    ResServiceID = 0;
    ResPersonID = 0;
    ResBegDate = 0;
    ResEndDate = 0;

    VisitID = 0;
}
//---------------------------------------------------------------------------
void __fastcall TBarberForm::FormDestroy(TObject *Sender)
{
    delete [] pLevel2IDs;
    delete [] pLevel2;

    delete [] pServicesIDs;
    delete [] pServices;

    delete [] pServices2IDs;
    delete [] pServices2;

    delete [] pPersonalIDs;
    delete [] pPersonal;

    delete [] pAddOps;

    SaveBoxSize("Barber",lbLevel01,lbLevel02,lbLevel03);
}
//---------------------------------------------------------------------------
void __fastcall TBarberForm::FormShow(TObject *Sender)
{
    SQL_exefun(DBName,"select RowID from Services where Name='Парикмахерская'",&retString);
    __int64 ID = _atoi64(retString.c_str());
    if(!ID)
    {
        CloseFlag = true;
        return;
    }

    Level2Counter = SQL_fldKeyCollect(DBName,"Name",("from Services where bin_and(WeekDays,"+AnsiString(CurDayOfWeek)+")!=0 and ParentID="+AnsiString(ID)+" order by Name").c_str(),&pLevel2IDs,&pLevel2,true);
    if(!Level2Counter)
    {
        CloseFlag = true;
        return;
    }

    LoadBoxSize("Barber",lbLevel01,lbLevel02,lbLevel03);

    for(unsigned i = 0; i < Level2Counter; i++)
    {
        //lbLevel2->Items->Add(pLevel2[i]);
        lbLevel01->Items->Add(pLevel2[i]);
    }
    lbLevel01->ItemIndex = 0;
    //lbLevel2->ItemIndex = 0;

    PersonalCounter = SQL_fldKeyCollect(DBName,"Name",("from Personal where Alive!=0 and ServiceID="+AnsiString(ID)+" order by Name").c_str(),&pPersonalIDs,&pPersonal,true,true);
    if(PersonalCounter <= 1)
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
    //dtpTime->DateTime = CurPeriod = dtpEndTime->DateTime - dtpBegTime->DateTime + (int)dtpBegTime->DateTime;

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
}
//---------------------------------------------------------------------------
void __fastcall TBarberForm::lbServicesUpdate(void)
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
void __fastcall TBarberForm::lbServices2Update(void)
{
    delete [] pServices2IDs;
    delete [] pServices2;
    pServices2IDs = NULL;
    pServices2 = NULL;
    Services2Counter = 0;

    lbLevel03->Clear();

    if(lbLevel02->ItemIndex < 0) return;

    Services2Counter = SQL_fldKeyCollect(DBName,"Name",("from Services where bin_and(WeekDays,"+AnsiString(CurDayOfWeek)+")!=0 and ParentID="+AnsiString(pServicesIDs[lbLevel02->ItemIndex])+" order by Name").c_str(),&pServices2IDs,&pServices2,true);
    for(unsigned i = 0; i < Services2Counter; i++)
    {
        lbLevel03->Items->Add(pServices2[i]);
    }

    lbLevel03->ItemIndex = 0;

    AnsiString sAddOp;

    AddType = 0;

    if(lbLevel03->ItemIndex >= 0)
    {
        SQL_exefun2(DBName,("select Timed,AddOp from Services where RowID="+AnsiString(pServices2IDs[lbLevel03->ItemIndex])).c_str(),&retString,&sAddOp);
        Timed = atoi(retString.c_str());
        AddOp = atoi(sAddOp.c_str());
    }
    else
    if(lbLevel02->ItemIndex >= 0)
    {
        SQL_exefun2(DBName,("select Timed,AddOp from Services where RowID="+AnsiString(pServicesIDs[lbLevel02->ItemIndex])).c_str(),&retString,&sAddOp);
        Timed = atoi(retString.c_str());
        AddOp = atoi(sAddOp.c_str());
    }
    else
    {
        Timed = 0;
        AddOp = 0;
    }

    //int itime = Timed? Timed : 30;
    if((int)ResEndDate && (int)ResBegDate)
        dtpBegTime->DateTime = ResBegDate;
    int itime = Timed? Timed : ((int)ResEndDate && (int)ResBegDate)? SimpleRoundTo((double)(ResEndDate - ResBegDate) * 1440.0,0) : 30;

    Edit1->Text = Edit1->Text.sprintf("%02d:%02d",itime/60,itime%60);

    double d = itime;
    d /= 1440.0;

    dtpEndTime->DateTime = dtpBegTime->DateTime + d;

    seGroupCnt->Value = 1;
    laPriceUpdate();
    lbPersonalUpdate();

    if(AddOp)
    {
        lbColor->Clear();

        AnsiString s;

        for(int i = 0; i < pAddOps[AddOp-1].count; i++)
        {
            s = pAddOps[AddOp-1].lines[i];
            lbColor->Items->Add(s);
        }

        lbColor->ItemIndex = 0;
        laKind->Caption = pAddOps[AddOp-1].label;

        TRect rect = lbLevel03->ItemRect(lbLevel03->ItemIndex);

        Panel2->Left = lbLevel03->Left + rect.Left + 3;
        Panel2->Top = lbLevel03->Top + rect.Bottom + 3;

        Panel2->Visible = true;
        Panel2->SetFocus();
    }
}
//---------------------------------------------------------------------------
void __fastcall TBarberForm::lbPersonalUpdate(void)
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
void __fastcall TBarberForm::laPriceUpdate(void)
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

    //if(lbServices->ItemIndex >= 0)
    {
        // Цена?
        //double pprice, price;
        //AnsiString sPersonPrice, sTimed;
        //AnsiString sIsGroup, sGroupPrice;
        double zprice;

        //SQL_exefun3(DBName,("select Price,PersonPrice,Timed from Services where RowID="+AnsiString(pIDs[pCombo->ItemIndex])).c_str(),&retString,&sPersonPrice,&sTimed);


        //SQL_exefun2(DBName,("select IsGroup,GroupPrice from Services where RowID="+AnsiString(pIDs[pCombo->ItemIndex])).c_str(),&sIsGroup,&sGroupPrice);

        AnsiString sql = "select Price,PersonPrice,Timed,IsGroup,GroupPrice,SUMP from Services left outer join "
                         "(select ServiceID as SID,sum(Price) as SUMP from ServiceGoods group by ServiceID) on Services.RowID=SID where Services.RowID=";
        sql += pIDs[pCombo->ItemIndex];

        AnsiString sRet[6];
        SQL_exefunrow(DBName,sql.c_str(),6,sRet);

        int timed = atoi(sRet[2].c_str());

        double pprice;

        if(atoi(sRet[3].c_str()) > 0)
        {
            seGroupCnt->Enabled = true;
            //seGroupCnt->Value = 1;
            zprice = GroupAnalyze(sRet[4],seGroupCnt->Value);

            // pprice = zprice - (sum(goodsprice) * seGroupCnt->Value
            //SQL_exefun(DBName,("select sum(Price) from ServiceGoods where ServiceID="+AnsiString(pIDs[pCombo->ItemIndex])).c_str(),&sPersonPrice);
            pprice = zprice - (atof(sRet[5].c_str()) * seGroupCnt->Value);
        }
        else
        {
            seGroupCnt->Enabled = false;
            //seGroupCnt->Value = 1;
            zprice = atof(sRet[0].c_str());
            pprice = atof(sRet[1].c_str());
        }

        if(timed)
        {
            unsigned pos = Edit1->Text.Pos(":");
            int itime = 60 * atoi(Edit1->Text.c_str());
            itime += atoi(Edit1->Text.SubString(pos+1,Edit1->Text.Length()-pos).c_str());

            Price = itime;
            Price /= timed;

            PersonPrice = Price;
            Price = ((((AddOp)? AddPrice : 0.0) + Price * zprice) * (100.0 - UserDiscountSPA)) / 100.0;

            //if(seGroupCnt->Enabled)
            //    PersonPrice = Price;
            //else
            PersonPrice = ((((AddOp)? AddPrice : 0.0) + PersonPrice * pprice) * (100.0 - UserDiscountSPA)) / 100.0;
        }
        else
        {
            Price = ((((AddOp)? AddPrice : 0.0) + zprice) * (100.0 - UserDiscountSPA)) / 100.0;
            //if(seGroupCnt->Enabled)
            //    PersonPrice = Price;
            //else
            PersonPrice = ((((AddOp)? AddPrice : 0.0) + pprice) * (100.0 - UserDiscountSPA)) / 100.0;
        }

        laPrice->Caption = "Цена: " + FormatFloat(MoneyFormat,Price)+" руб.";
    }
    //else
    //    laPrice->Caption = "Цена:";
}
//---------------------------------------------------------------------------
double __fastcall TBarberForm::GroupAnalyze(AnsiString group,int cnt)
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

    // Цепочка собрана, поехали

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
                    // расчет
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
void __fastcall TBarberForm::lbLevel01Click(TObject *Sender)
{
    lbServicesUpdate();    
}
//---------------------------------------------------------------------------
void __fastcall TBarberForm::lbLevel02Click(TObject *Sender)
{
    lbServices2Update();
}
//---------------------------------------------------------------------------
void __fastcall TBarberForm::lbLevel03Click(TObject *Sender)
{
    Panel2->Visible = false;

    AddType = 0;
    AddCount = 0;
    AddPrice = 0.0;

    if(lbLevel03->ItemIndex >= 0)
    {
        AnsiString sAddOp;
        SQL_exefun2(DBName,("select Timed,AddOp from Services where RowID="+AnsiString(pServices2IDs[lbLevel03->ItemIndex])).c_str(),&retString,&sAddOp);
        Timed = atoi(retString.c_str());
        AddOp = atoi(sAddOp.c_str());
    }
    else
    {
        Timed = 0;
        AddOp = 0;
    }

    //int itime = Timed? Timed : 30;
    if((int)ResEndDate && (int)ResBegDate)
        dtpBegTime->DateTime = ResBegDate;
    int itime = Timed? Timed : ((int)ResEndDate && (int)ResBegDate)? SimpleRoundTo((double)(ResEndDate - ResBegDate) * 1440.0,0) : 30;

    Edit1->Text = Edit1->Text.sprintf("%02d:%02d",itime/60,itime%60);

    double d = itime;
    d /= 1440.0;

    dtpEndTime->DateTime = dtpBegTime->DateTime + d;
    seGroupCnt->Value = 1;
    laPriceUpdate();
    lbPersonalUpdate();
   
    if(AddOp)
    {
        lbColor->Clear();

        AnsiString s;

        for(int i = 0; i < pAddOps[AddOp-1].count; i++)
        {
            s = pAddOps[AddOp-1].lines[i];
            lbColor->Items->Add(s);
        }
        lbColor->ItemIndex = 0;
        laKind->Caption = pAddOps[AddOp-1].label;


        TRect rect = lbLevel03->ItemRect(lbLevel03->ItemIndex);

        //BarbColorForm = new TBarbColorForm(this);



        //TPoint pt(lbLevel03->Left,lbLevel03->Top);

        Panel2->Left = lbLevel03->Left + rect.Left + 3;
        Panel2->Top = lbLevel03->Top + rect.Bottom + 3;

        //int hgt = Panel2->Height;
        //Panel2->Height = 0;
        Panel2->Visible = true;
        Panel2->SetFocus();

        //for(int i = 1; i <= hgt; i++)
        //{
        //    Panel2->Height = i;
        //    Sleep(2);

        //    Panel2->Repaint();
        //}


        //pt = paBath->ClientToScreen(pt);

        //BarbColorForm->Left = pt.x + rect.Left + 3;
        //BarbColorForm->Top = pt.y + rect.Bottom + 4;
        //BarbColorForm->ShowModal();
        //delete BarbColorForm;

        //laPriceUpdate();
    }
}
//---------------------------------------------------------------------------
void __fastcall TBarberForm::bOKClick(TObject *Sender)
{
    if(AddOp && (!AddCount || !AddType))
    {
        Application->MessageBox("Внимание!\nДля данной услуги необходимо задать расходный материал.","",MB_OK);

        return;
    }

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

    if(AddOp)
    {
        SQL_iniInsert(DBName,"AddOp");
        SQL_addInsert("Visits_SPAID",VisitID);
        SQL_addInsert("Type",AddType);
        //if(AddType == 1)
        //    SQL_addInsert("!Name","Wella");
        //else
        //    SQL_addInsert("!Name","Schwarzkopf");
        SQL_addInsert("!Name",pAddOps[AddOp-1].lines[AddType-1]);
        SQL_addInsert("Price",AddPrice);
        SQL_exeInsert("AddOpCount",AddCount);
        //SQL_addInsert("Part",0);
    }

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
void __fastcall TBarberForm::bCancelClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TBarberForm::Button1Click(TObject *Sender)
{
    AddCount = atoi(edColor->Text.c_str());

    if(!AddCount)
    {
        Application->MessageBox("Внимание!\nКоличество не может быть 0.","",MB_OK);
        return;
    }

    AddType = lbColor->ItemIndex + 1;
    AddPrice = pAddOps[AddOp-1].price[AddType-1] * AddCount;

    laPriceUpdate();

    Panel2->Visible = false;

}
//---------------------------------------------------------------------------
void __fastcall TBarberForm::lbLevel01Enter(TObject *Sender)
{
    Panel2->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TBarberForm::lbLevel02Enter(TObject *Sender)
{
    Panel2->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TBarberForm::Button2Click(TObject *Sender)
{
    Panel2->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TBarberForm::edColorKeyPress(TObject *Sender, char &Key)
{
    ui_keyfilter(Key);
}
//---------------------------------------------------------------------------
void __fastcall TBarberForm::seGroupCntChange(TObject *Sender)
{
    laPriceUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TBarberForm::Panel2Exit(TObject *Sender)
{
    Panel2->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TBarberForm::FormPaint(TObject *Sender)
{
    if(CloseFlag)
        Close();
}
//---------------------------------------------------------------------------

