//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "sync.h"
#include "dm_main.h"

#pragma package(smart_init)
//bool SyncErrStatus = false;
#define LOGPATH "c:\panacea\sync.log"

extern __int64 UserID;

extern volatile bool ReserveFlag;
extern AnsiString ConString;

extern bool SyncLog;
extern bool SendEMAIL;

static char *pTables[] = {  "Personal",
                            "Services",
                            "AbTypes",
                            "FitGroup",

                            "Clients",
                            "Reserve",
                            "Abonements",
                            "Visits",
                            "Visits_SPA",
                            "Abonements_SPA",
                            "Bills"

};

static char *pPersonal[]   = { "RowID", "#Name", "Alive", "#Job", "ServiceID", NULL };
static char *pServices[]   = { "RowID", "#Name", "ParentID", "IsGroup", "#Tag", "Price", "PersonPrice", "Timed", "Personify", "WeekDays", "#GroupPrice", "AddOp", NULL };
static char *pClients[]    = { "RowID", "#CID", "#FName", "#SName", "#TName", "Alive", "BirthDate", "#DiscountCard", "#Phone1", "#Phone2", "#Phone3", "Balanse", "Discount", "DiscountSPA", "#WebPass", NULL };
static char *pFitGroup[]   = { "RowID", "FitGroupDay", "ServiceID", "PersonID", "BegDate", "EndDate", "FitGroupCount", "Closed", NULL };
static char *pReserve[]    = { "RowID", "ClientID", "BegDate", "EndDate", "PersonID", "ServiceID", "Status", "FitGroupID", "Quan", "ParentID", NULL };
static char *pAbTypes[]    = { "RowID", "#Name", "Price", "Alive", "Days", "AbTypesCount", "PersonID", "ServiceID", "AutoFlow", "FixSum", NULL };
static char *pAbonements[] = { "RowID", "ClientID", "AbTypeID", "PersonID", "ServiceID", "#Name", "Price", "AbonementsCount", "Discount", "AutoFlow", "BegDate", "EndDate", "Closed", "FixSum", NULL };
static char *pVisits[]     = { "RowID", "AbonementID", "PersonID", "ServiceID", "VisitsDate", "BegTime", "EndTime", "Price", "ParentID", NULL };

static char *pVisits_SPA[] = { "RowID", "AbonementID", "PersonID", "ServiceID", "Visits_SPADate", "BegTime", "EndTime", "Price", "ClientID", "GroupCnt", NULL };
static char *pAbonements_SPA[]
                           = { "RowID", "ClientID", "BegDate", "EndDate", "Closed", "Balanse", "Discount", "#Name", "Price", NULL };
static char *pBills[]      = { "RowID", "ClientID", "BegBalanse", "FromBalanse", "ToBalanse", "EndBalanse", "Total", "Payment", "CDate", NULL };

static char **pFields[]    = { pPersonal, pServices, pAbTypes, pFitGroup, pClients, pReserve, pAbonements, pVisits, pVisits_SPA, pAbonements_SPA, pBills };

AnsiString sCatch;
//---------------------------------------------------------------------------
//
//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TSync::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//
//---------------------------------------------------------------------------
__fastcall TSync::TSync(bool CreateSuspended)
    : TThread(CreateSuspended)
{
}
//---------------------------------------------------------------------------
void __fastcall TSync::Execute()
{
    //---- Place thread code here ----
    CoInitialize(NULL);

    while(true)
    {
        while(ReserveFlag)
            ::Sleep(3000);

        //Application->MessageBox("Start Sync","",MB_OK);

        // Синхронизация
        if(SyncLog)
        {
            int fHandle = FileOpen(LOGPATH,fmOpenReadWrite);
            if(fHandle == -1)
                fHandle = FileCreate(LOGPATH);


            if(fHandle > 0)
            {
                FileSeek(fHandle,0,2);
                sVal = "\r\nStart Sync at " + Now().DateTimeString() + "\r\n";
                FileWrite(fHandle,sVal.c_str(),sVal.Length());
                FileClose(fHandle);
            }
        }

        AnsiString sql, sUpd;

        struct _R
        {
            __int64 RID;
            __int64 CID;
            int RStatus;
        } *pR;

        TIBQuery *pQue = NULL;
        TIBTransaction *pTrans = NULL;
        TDataSource *pDS = NULL;

        try
        {
            pR = NULL;

            dmMain->ADOConn->Connected = true;

            if(SyncLog)
            {
                int fHandle = FileOpen(LOGPATH,fmOpenReadWrite);
                if(fHandle > 0)
                {
                    FileSeek(fHandle,0,2);
                    sVal = "Connecting to remote server - ";
                    sVal += ((dmMain->ADOConn->Connected)? "true\r\n" : "false\r\n");
                    FileWrite(fHandle,sVal.c_str(),sVal.Length());
                    FileClose(fHandle);
                }
            }

            if(dmMain->ADOConn->Connected)
            {
                // Есть коннект

                dmMain->ADOQue->SQL->Text = "SET AUTOCOMMIT=0";
                dmMain->ADOQue->ExecSQL();

                dmMain->ADOConn->BeginTrans();

                dmMain->DBAlt->DatabaseName = ConString;
                dmMain->DBAlt->Open();

                if(SyncLog)
                {
                    int fHandle = FileOpen(LOGPATH,fmOpenReadWrite);
                    if(fHandle > 0)
                    {
                        FileSeek(fHandle,0,2);
                        sVal = "Connecting to local server - ";
                        sVal += ((dmMain->DBAlt->Connected)? "true\r\n" : "false\r\n");
                        FileWrite(fHandle,sVal.c_str(),sVal.Length());
                        FileClose(fHandle);
                    }
                }

                pTrans = new TIBTransaction(NULL);
                pTrans->DefaultDatabase = dmMain->DBAlt;
                pTrans->Params->Clear();
                pTrans->Params->Add("read_committed");
                pTrans->Params->Add("rec_version");
                pTrans->Params->Add("nowait");

                //read_committed
                //rec_version
                //nowait

                pQue = new TIBQuery(NULL);
                pQue->Database = dmMain->DBAlt;
                pQue->Transaction = pTrans;

                pDS = new TDataSource(NULL);
                pDS->DataSet = pQue;

                pTrans->Active = true;

                int RecCnt = 0;


                for(int i = 0; i < sizeof(pTables) / sizeof(char *); i++)
                {
                    sUpd = "0,";

                    pQue->SQL->Text = AnsiString("select first 1000 * from ") + pTables[i] + " where Sync=0";
                    //if(i == 7)
                    //    Application->MessageBox(pQue->SQL->Text.c_str(),"",MB_OK);
                    pQue->Prepare();
                    pQue->Open();
                    //pQue->FetchAll();

                    pQue->First();

                    while(!pQue->Eof)
                    {
                        // Сборка запроса
                        sql = AnsiString("replace into ") + pTables[i] + " set ";

                        for(int j = 0; pFields[i][j]; j++)
                        {
                            bool fnull = true;
                            bool fstr = false;
                            int pos = 0;

                            if(pFields[i][j][pos] == '!')
                            {
                                pos++;
                                fnull = false;
                            }

                            if(pFields[i][j][pos] == '#')
                            {
                                pos++;
                                fstr = true;
                            }

                            if(fnull && pQue->FieldByName(pFields[i][j]+pos)->IsNull)
                                sql += AnsiString(pFields[i][j]+pos) + "=null,";
                            else
                            {
                                if(fstr)
                                    sql += AnsiString(pFields[i][j]+pos) + "='" + pQue->FieldByName(pFields[i][j]+pos)->AsString + "',";
                                else
                                    sql += AnsiString(pFields[i][j]+pos) + "=" + pQue->FieldByName(pFields[i][j]+pos)->AsString + ",";
                            }

                            //if(i == 7)
                            //    Application->MessageBox((AnsiString("Set ")+sql).c_str(),"",MB_OK);

                        }

                        sql.SetLength(sql.Length()-1);

                        sql = StringReplace(sql,"WebPass=null","WebPass='0'",TReplaceFlags());

                        dmMain->ADOQue->SQL->Text = sql;

                        //if(i == 7)
                        //    Application->MessageBox((AnsiString("Set ")+sql+" is OK").c_str(),"",MB_OK);

                        dmMain->ADOQue->ExecSQL();

                        sUpd += pQue->FieldByName("RowID")->AsInteger;
                        sUpd += ",";

                        pQue->Next();

                        RecCnt++;


                    }


                    pQue->Close();

                    sUpd.SetLength(sUpd.Length()-1);
                    pQue->SQL->Text = AnsiString("update ") + pTables[i] + " set Sync=1 where RowID in (" + sUpd + ")";

                    pQue->ExecSQL();

                    //Application->MessageBox((AnsiString("Set ")+pTables[i]+" is OK").c_str(),"",MB_OK);
                }

                // Может что-то удалить?
                sUpd = "'0',";

                pQue->SQL->Text = "select ID,Name from SyncDel";
                pQue->Prepare();
                pQue->Open();

                pQue->First();

                while(!pQue->Eof)
                {
                    if(pQue->FieldByName("NAME")->AsString.UpperCase() != "RESERVE")
                    {
                        dmMain->ADOQue->SQL->Text = "delete from " + pQue->FieldByName("NAME")->AsString + " where RowID=" + pQue->FieldByName("ID")->AsString;
                        dmMain->ADOQue->ExecSQL();
                    }
                    else
                    {
                        __int64 CID = 0, FID = 0;

                        dmMain->ADOQue->SQL->Text = "select ClientID,FitGroupID from Reserve where RowID=" + pQue->FieldByName("ID")->AsString;
                        dmMain->ADOQue->Open();

                        if(!dmMain->ADOQue->Fields->Fields[0]->IsNull && !dmMain->ADOQue->Fields->Fields[1]->IsNull)
                        {
                            CID = _atoi64(dmMain->ADOQue->Fields->Fields[0]->AsString.c_str());
                            FID = _atoi64(dmMain->ADOQue->Fields->Fields[1]->AsString.c_str());
                        }

                        dmMain->ADOQue->Close();

                        dmMain->ADOQue->SQL->Text = "delete from " + pQue->FieldByName("NAME")->AsString + " where RowID=" + pQue->FieldByName("ID")->AsString;
                        dmMain->ADOQue->ExecSQL();

                        if(CID && FID)
                        {
                            dmMain->ADOQue->SQL->Text = "update Reserve_Synchron set Status_Synchron=2 where ClientID=" + AnsiString(CID) + " and FitGroupID=" + AnsiString(FID);
                            dmMain->ADOQue->ExecSQL();
                        }
                    }

                    sUpd += "'";
                    sUpd += pQue->FieldByName("ID")->AsInteger;
                    sUpd += pQue->FieldByName("Name")->AsString;
                    sUpd += "',";

                    pQue->Next();

                    RecCnt++;
                }

                pQue->Close();

                sUpd.SetLength(sUpd.Length()-1);

                pQue->SQL->Text = "delete from SyncDel where cast(ID as varchar(16)) || Name in (" + sUpd + ")";
                pQue->ExecSQL();

                //--------------------------------------------------------------
                // Есть ли записи на сайте?
                __int64 ID, ClientID;

                dmMain->ADOQue->SQL->Text = "select * from Reserve_Synchron where Status_Synchron=0";
                dmMain->ADOQue->Open();

                int RIDCnt = 0;

                pR = new _R[dmMain->ADOQue->RecordCount];

                while(!dmMain->ADOQue->Eof)
                {
                    // Попытка записи

                    ClientID = dmMain->ADOQue->FieldByName("ClientID")->AsInteger;
                    ID = dmMain->ADOQue->FieldByName("FitGroupID")->AsInteger;
                    pR[RIDCnt].CID = ClientID;
                    //--------------------------------------------------------------------------------------------
                        // Записаться, только если еще есть время

                    if(!ID || !ClientID)
                    {
                        pR[RIDCnt].RID = dmMain->ADOQue->FieldByName("RowID")->AsInteger;
                        pR[RIDCnt++].RStatus = 1;

                        dmMain->ADOQue->Next();
                        continue;
                    }

                    AnsiString sRet, retString, sCounter;

                    pQue->SQL->Text = "select BegDate,FitGroupCount from FitGroup where RowID=" + AnsiString(ID);
                    pQue->Prepare();
                    pQue->Open();

                    sRet = pQue->FieldByName("BegDate")->AsString;
                    retString = pQue->FieldByName("FitGroupCount")->AsString;
                    //SQL_exefun2(DBName,("select BegDate,FitGroupCount from FitGroup where RowID="+AnsiString(ID)).c_str(),&sRet,&retString);

                    pQue->Close();

                    double dtn = Now();
                    double dt = atof(sRet.c_str()) + (15.0 / 1440.0);
                    int begday = dt;

                    if(dtn > dt)
                    {
                        //Application->MessageBox("Внимание!\nВремя записи в группу истекло!","",MB_OK);
                        // Непринято - ставим 2

                        pR[RIDCnt].RID = dmMain->ADOQue->FieldByName("RowID")->AsInteger;
                        pR[RIDCnt++].RStatus = 2;

                        dmMain->ADOQue->Next();
                        continue;
                    }

                    // Количество
                    pQue->SQL->Text = "select count(*) from Reserve where FitGroupID=" + AnsiString(ID);
                    pQue->Prepare();
                    pQue->Open();

                    sRet = pQue->Fields->Fields[0]->AsInteger;

                    pQue->Close();

                    //SQL_exefun(DBName,("select count(*) from Reserve where FitGroupID="+AnsiString(ID)).c_str(),&sRet);

                    if(atoi(sRet.c_str()) >= atoi(retString.c_str()))
                    {
                        //Application->MessageBox("Внимание!\nГруппа заполнена!","",MB_OK);
                        // Непринято - ставим 2

                        pR[RIDCnt].RID = dmMain->ADOQue->FieldByName("RowID")->AsInteger;
                        pR[RIDCnt++].RStatus = 2;

                        dmMain->ADOQue->Next();
                        continue;
                    }

                    pQue->SQL->Text = "select count(*) from Reserve where ClientID=" + AnsiString(ClientID) + " and FitGroupID=" + AnsiString(ID);
                    pQue->Prepare();
                    pQue->Open();

                    sRet = pQue->Fields->Fields[0]->AsInteger;

                    pQue->Close();

                    //SQL_exefun(DBName,("select count(*) from Reserve where ClientID="+AnsiString(ClientID)+" and FitGroupID="+AnsiString(ID)).c_str(),&sRet);

                    if(atoi(sRet.c_str()) > 0)
                    {
                        // Есть запись
                        //Application->MessageBox("Внимание!\nДля клиента уже есть запись в эту группу!","",MB_OK);
                        //return;
                        // Непринято - ставим 2

                        pR[RIDCnt].RID = dmMain->ADOQue->FieldByName("RowID")->AsInteger;
                        pR[RIDCnt++].RStatus = 2;

                        dmMain->ADOQue->Next();
                        continue;
                    }

                    // А есть действующий абонемент?
                    pQue->SQL->Text = "select count(*) from Abonements where Closed=0 and FixSum>=0 and EndDate>=" + AnsiString(begday) + " and ClientID=" + AnsiString(ClientID);
                    pQue->Prepare();
                    pQue->Open();

                    sCounter = pQue->Fields->Fields[0]->AsInteger;

                    pQue->Close();

                    //SQL_exefun(DBName,("select count(*) from Abonements where Closed=0 and FixSum>=0 and EndDate>="+AnsiString(begday)+" and ClientID="+AnsiString(ClientID)).c_str(),&sCounter);
                    unsigned abs_cnt = atoi(sCounter.c_str());

                    if(!abs_cnt)
                    {
                        //Application->MessageBox("Внимание!\nНет абонементов с доступными посещениями.","Недопустимая операция",ID_OK);
                        //return;
                        // Непринято - ставим 2

                        pR[RIDCnt].RID = dmMain->ADOQue->FieldByName("RowID")->AsInteger;
                        pR[RIDCnt++].RStatus = 2;

                        dmMain->ADOQue->Next();
                        continue;
                    }

                    pQue->SQL->Text = "select count(*) from Abonements where Closed=0 and AbonementsCount=0 and FixSum>0 and ClientID=" + AnsiString(ClientID);
                    pQue->Prepare();
                    pQue->Open();

                    sRet = pQue->Fields->Fields[0]->AsInteger;

                    pQue->Close();

                    //SQL_exefun(DBName,("select count(*) from Abonements where Closed=0 and AbonementsCount=0 and FixSum>0 and ClientID="+AnsiString(ClientID)).c_str(),&sRet);

                    if(atoi(sRet.c_str()) == 0)
                    {
                        // Нет клубной карты, считаем занятия
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

                        pQue->SQL->Text = sql;
                        //"select count(*) from Abonements where Closed=0 and AbonementsCount=0 and FixSum>0 and ClientID=" + AnsiString(ClientID);
                        pQue->Prepare();
                        pQue->Open();

                        sCounter = pQue->Fields->Fields[0]->AsInteger;
                        sRet     = pQue->Fields->Fields[1]->AsInteger;

                        pQue->Close();

                        //SQL_exefun2(DBName,sql.c_str(),&sCounter,&sRet);

                        //SQL_exefun2(DBName,("select sum(CNT),sum(VCNT) from (select AbonementsCount as CNT,sum(case when AbonementID is null then 0 else 1 end) as VCNT from Abonements left outer join Visits on Abonements.RowID=AbonementID where Closed=0 and FixSum>=0 and ClientID="+AnsiString(ClientID)+" group by Abonements.RowID)").c_str(),&sCounter,&sRet);

                        //SQL_exefun2(DBName,("select Count,count(*) from Abonements,Visits where Closed=0 and FixSum>=0 and EndDate>="+AnsiString(begday)+" and ClientID="+AnsiString(ClientID)+" and Abonements.RowID=AbonementID group by Abonements.RowID").c_str(),&sCounter,&sRet);
                        abs_cnt = atoi(sCounter.c_str()) - atoi(sRet.c_str());

                        // Замечательно, но могут быть блокирующие записи в группу
                        // Получаем кол-во текущих записей клиента на Фитнесс

                        pQue->SQL->Text = "select count(*) from Reserve,FitGroup where ClientID=" + AnsiString(ClientID) + " and Status=1 and FitGroupID=FitGroup.RowID and Closed=0";
                        pQue->Prepare();
                        pQue->Open();

                        sRet = pQue->Fields->Fields[0]->AsInteger;

                        pQue->Close();

                        //SQL_exefun(DBName,("select count(*) from Reserve,FitGroup where ClientID="+AnsiString(ClientID)+" and Status=1 and FitGroupID=FitGroup.RowID and Closed=0").c_str(),&sRet);
                        unsigned recs = atoi(sRet.c_str());

                        if(recs > 0)
                        {
                            // Есть записи, проверить есть ли занятия в абонементе
                            if(abs_cnt < ++recs)
                            {
                                //Application->MessageBox("Внимание!\nВсе посещения в абонементе зарезервированы под запись.","Недопустимая операция",ID_OK);
                                //return;
                                // Непринято - ставим 2

                                pR[RIDCnt].RID = dmMain->ADOQue->FieldByName("RowID")->AsInteger;
                                pR[RIDCnt++].RStatus = 2;

                                dmMain->ADOQue->Next();
                                continue;
                            }
                        }
                    }

                    //double dt = Now();

                    //SQL_BeginTransaction();
                    pQue->SQL->Text = "insert into Reserve select null," + AnsiString(ClientID) + ",BegDate,EndDate,PersonID,ServiceID,1,RowID,0,null," + AnsiString(dtn) + ",0,0,0,0 from FitGroup where RowID=" + AnsiString(ID);
                    pQue->Prepare();
                    pQue->ExecSQL();

                    pR[RIDCnt].RID = dmMain->ADOQue->FieldByName("RowID")->AsInteger;
                    pR[RIDCnt++].RStatus = 1;

                    RecCnt++;

                    //--------------------------------------------------------------------------------------------
                    dmMain->ADOQue->Next();
                }

                dmMain->ADOQue->Close();
                //--------------------------------------------------------------

                for(int i = 0; i < RIDCnt; i++)
                {
                    dmMain->ADOQue->SQL->Text = "update Reserve_Synchron set Status_Synchron=" + AnsiString(pR[i].RStatus) + " where RowID=" + AnsiString(pR[i].RID);
                    dmMain->ADOQue->ExecSQL();
                }


                if(RecCnt)
                {
                    dmMain->ADOConn->CommitTrans();
                    pTrans->Commit();
                }
                else if(RIDCnt)
                    dmMain->ADOConn->CommitTrans();

                //Application->MessageBox("After Commit","",MB_OK);
                
                // Есть Commit, разослать почту
                // Теоретически можно отслеживать, ушло письмо или нет
                if(SendEMAIL)
                {
                    for(int i = 0; i < RIDCnt; i++)
                    {
                        if(pR[i].RStatus == 1)
                        {
                            dmMain->ADOQue->SQL->Text = "select Email from Clients where RowID=" + AnsiString(pR[i].CID);
                            dmMain->ADOQue->Open();
                            if(!dmMain->ADOQue->FieldByName("EMAIL")->IsNull)
                                if(dmMain->ADOQue->FieldByName("EMAIL")->AsString.Length() > 0)
                                    dmMain->SendMail(dmMain->ADOQue->FieldByName("EMAIL")->AsString.c_str(),"Запись на Фитнесс","Вы записались на Фитнесс!");

                            dmMain->ADOQue->Close();

                        }
                    }
                }

                if(pTrans)
                {
                    pTrans->Active = false;
                    delete pTrans;
                }

                if(pDS)
                    delete pDS;
                if(pQue)
                    delete pQue;

                dmMain->DBAlt->Close();


            }
        }
        catch(...)
        {
            //Application->MessageBox("Catch here","",MB_OK);

            if(pQue)
                pQue->Close();

            if(pTrans)
            {
                pTrans->Active = false;
                delete pTrans;
            }

            if(pDS)
                delete pDS;
            if(pQue)
                delete pQue;

            dmMain->DBAlt->Close();

            dmMain->ADOConn->Connected = false;

            if(pR) delete [] pR;

            //SyncErrStatus = true;
            if(SyncLog)
            {
                int fHandle = FileOpen(LOGPATH,fmOpenReadWrite);
                if(fHandle > 0)
                {
                    FileSeek(fHandle,0,2);
                    sVal = "Catching some errors, finished at " + Now().DateTimeString() + "\r\n";

                    FileWrite(fHandle,sVal.c_str(),sVal.Length());
                    FileClose(fHandle);
                }
            }

            Suspend();

            continue;
        }

        // Завершение

        dmMain->ADOConn->Connected = false;

        if(pR) delete [] pR;

        if(SyncLog)
        {
            int fHandle = FileOpen(LOGPATH,fmOpenReadWrite);
            if(fHandle > 0)
            {
                FileSeek(fHandle,0,2);
                sVal = "Sync OK, finished at " + Now().DateTimeString() + "\r\n";

                FileWrite(fHandle,sVal.c_str(),sVal.Length());
                FileClose(fHandle);
            }
        }

        Suspend();
    }

}
//---------------------------------------------------------------------------
