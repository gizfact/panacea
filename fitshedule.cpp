//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include "fitshedule.h"
#include "lib.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TFitSheduleForm *FitSheduleForm;

extern int FormResult;
extern const char *DBName;
extern __int64 ClientID;

static const char *_pDays[] = { "Пн", "Вт", "Ср", "Чт", "Пт", "Сб", "Вс" };

//---------------------------------------------------------------------------
static int shedule_fill(void *NotUsed,int argc,char **argv,char **azColName)
{
    __int64 ID = atoi(argv[0]);
    if(!ID) return 0;

    AnsiString sCnt;


    if(FitSheduleForm->sgShedule->Rows[1]->Objects[0])
        FitSheduleForm->sgShedule->RowCount++;

    int pos = FitSheduleForm->sgShedule->RowCount - 1;

    FitSheduleForm->sgShedule->Rows[pos]->Objects[0] = (TObject *)ID;
    SQL_exefun(DBName,("select count(*) from Reserve where ClientID="+AnsiString(ClientID)+" and FitGroupID="+AnsiString(ID)).c_str(),&sCnt);
    FitSheduleForm->sgShedule->Cells[0][pos] = atoi(sCnt.c_str())? " " : "";
    FitSheduleForm->sgShedule->Cells[1][pos] = (argv[1]);
    FitSheduleForm->sgShedule->Cells[2][pos] = (argv[2]);
    FitSheduleForm->sgShedule->Cells[3][pos] = TDateTime(atof(argv[3])).FormatString("hh:nn");
    FitSheduleForm->sgShedule->Cells[4][pos] = TDateTime(atof(argv[4])).FormatString("hh:nn");
    SQL_exefun(DBName,("select count(*) from Reserve where FitGroupID="+AnsiString(ID)).c_str(),&sCnt);
    FitSheduleForm->sgShedule->Cells[5][pos] = sCnt + " / " + atoi(argv[5]);

    return 0;
}
//---------------------------------------------------------------------------
static int clients_fill(void *NotUsed,int argc,char **argv,char **azColName)
{
    __int64 ID = atoi(argv[0]);
    if(!ID) return 0;

    //AnsiString sCnt;


    if(FitSheduleForm->sgClients->Rows[1]->Objects[0])
        FitSheduleForm->sgClients->RowCount++;

    int pos = FitSheduleForm->sgClients->RowCount - 1;

    FitSheduleForm->sgClients->Rows[pos]->Objects[0] = (TObject *)ID;
    FitSheduleForm->sgClients->Cells[0][pos] = (argv[1]);
    FitSheduleForm->sgClients->Cells[1][pos] = (argv[2]);
    FitSheduleForm->sgClients->Cells[2][pos] = (argv[3]);


    return 0;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
__fastcall TFitSheduleForm::TFitSheduleForm(TComponent* Owner)
    : TForm(Owner)
{
    pButtons[0] = sbMo;
    
    pButtons[1] = sbTu;
    pButtons[2] = sbWe;
    pButtons[3] = sbTh;
    pButtons[4] = sbFr;
    pButtons[5] = sbSa;
    pButtons[6] = sbSu;

    CurButton = 0;

    //fldAlignShedule = "Lrrrr";
    fldAlignClients = "rrr";
    fldAlignShedule = "Lrrrr";

    CurrentDay = (int)Now();
    CurrentWDay = CurrentDay.DayOfWeek() - 1;
    if(!CurrentWDay) CurrentWDay = 7;
    //CurrentFDay = CurrentWDay;

    int day = CurrentWDay - 1;
    for(int i = 0; i < 7; i++)
    {
        if(day > 4) pButtons[i]->Font->Color = clRed;
        pButtons[i]->Caption = _pDays[day++];
        if(day > 6) day = 0;
    }

    //pButtons[CurrentWDay-1]->Down = true;
}
//---------------------------------------------------------------------------
void __fastcall TFitSheduleForm::tbExitClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TFitSheduleForm::sbMoClick(TObject *Sender)
{
    CurButton = ((TSpeedButton *)Sender)->Tag - 1;
    //CurrentWDay = CurrentFDay + CurButton;
    //if(CurrentWDay > 7) CurrentWDay -= 7;
    sgSheduleFullUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TFitSheduleForm::sgClientsFullUpdate(void)
{
    sgClients->RowCount = 2;
    sgClients->Row = 1;

    sgClearRow(sgClients);

    __int64 ID = (__int64)sgShedule->Rows[sgShedule->Row]->Objects[0];
    if(!ID) return;

    SQL_exe(DBName,("select Clients.RowID,FName,SName,TName from Clients,Reserve where Clients.RowID=Reserve.ClientID and FitGroupID="+AnsiString(ID)).c_str(),clients_fill);

}
//---------------------------------------------------------------------------
void __fastcall TFitSheduleForm::sgSheduleFullUpdate(void)
{
    sgShedule->RowCount = 2;
    sgShedule->Row = 1;

    sgClearRow(sgShedule);
    // Это расписание, а сколько записано?

    SQL_BeginTransaction();
    SQL_exe(DBName,("select FitGroup.RowID,Services.Name,Personal.Name,BegDate,EndDate,FitGroupCount from FitGroup,Services,Personal where "
    "FitGroup.ServiceID=Services.RowID and FitGroup.PersonID=Personal.RowID and trunc(BegDate,0)="+AnsiString((int)CurrentDay+CurButton)+" order by BegDate,Services.Name").c_str(),shedule_fill);
    SQL_CancelTransaction();
    
    sgClientsFullUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TFitSheduleForm::sgSheduleDrawCell(TObject *Sender,
      int ACol, int ARow, TRect &Rect, TGridDrawState State)
{
    sgDrawCell(Sender,ACol,ARow,Rect,State,fldAlignShedule,sgShedule->Rows[ARow]->Objects[0] != NULL,ilClients);
}
//---------------------------------------------------------------------------
void __fastcall TFitSheduleForm::FormShow(TObject *Sender)
{
    sgSetHeaders(sgShedule,"","Услуга","Специалист","Начало","Конец","Кол-во");
    sgSetWidths(sgShedule,&SheduleWidths,16,180,120,80,80);

    sgOSheduleWindowProc = sgShedule->WindowProc;
    sgShedule->WindowProc = sgSheduleWindowProc;

    sgSetHeaders(sgClients,"Фамилия","Имя","Отчество");
    sgSetWidths(sgClients,&ClientsWidths,120,120);

    sgOClientsWindowProc = sgClients->WindowProc;
    sgClients->WindowProc = sgClientsWindowProc;

    sgSheduleFullUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TFitSheduleForm::sgSheduleWindowProc(Messages::TMessage& Msg)
{
    sgWindowProc(Msg,sgShedule,SheduleWidths,sgOSheduleWindowProc);
}
//---------------------------------------------------------------------------
void __fastcall TFitSheduleForm::sgClientsWindowProc(Messages::TMessage& Msg)
{
    sgWindowProc(Msg,sgClients,ClientsWidths,sgOClientsWindowProc);
}
//---------------------------------------------------------------------------
void __fastcall TFitSheduleForm::ToolButton1Click(TObject *Sender)
{
    // Записаться, только если еще есть время
    __int64 ID = (__int64)sgShedule->Rows[sgShedule->Row]->Objects[0];

    if(!ID || !ClientID) return;

    AnsiString sRet;
    SQL_exefun(DBName,("select count(*) from Reserve where ClientID="+AnsiString(ClientID)+" and FitGroupID="+AnsiString(ID)).c_str(),&sRet);
    if(atoi(sRet.c_str()) > 0)
    {
        // Есть запись
        Application->MessageBox("Внимание!\nДля клиента уже есть запись в эту группу!","",MB_OK);
        return;
    }

    // А есть действующий абонемент?

    AnsiString sFixSum, sCounter;

    SQL_exefun(DBName,("select count(*) from Abonements where Closed=0 and FixSum>=0 and ClientID="+AnsiString(ClientID)).c_str(),&sCounter);
    unsigned abs_cnt = atoi(sCounter.c_str());

    if(!abs_cnt)
    {
        Application->MessageBox("Внимание!\nНет абонементов с доступными посещениями.","Недопустимая операция",ID_OK);
        return;
    }

    SQL_exefun(DBName,("select first 1 FixSum from Abonements where Closed=0 and FixSum>=0 and ClientID="+AnsiString(ClientID)+" order by BegDate,CDate").c_str(),&sFixSum);

    if(atof(sFixSum.c_str()) == 0.0)
    {
        // Требуется проверка на любой действующий абонемент
        SQL_exefun(DBName,("select count(*) from Abonements where Closed=0 and FixSum>=0 and EndDate>="+AnsiString((int)Now())+" and ClientID="+AnsiString(ClientID)).c_str(),&sCounter);
        abs_cnt = atoi(sCounter.c_str());

        if(!abs_cnt)
        {

            Application->MessageBox("Внимание!\nТекущий абонемент просрочен. Для его продления нужно приобрести следующий абонемент.","Недопустимая операция",ID_OK);
            return;
        }
    }


    sRet = sgShedule->Cells[5][sgShedule->Row];

    int recs = atoi(sRet.c_str());

    int pos = sRet.Pos("/");

    if(pos <= 0) return;

    int cnt = atoi(sRet.SubString(pos+1,sRet.Length()-pos).c_str());

    if(recs >= cnt) return;
    
    SQL_BeginTransaction();
    SQL_exe(DBName,("insert into Reserve select null,"+AnsiString(ClientID)+",BegDate,EndDate,PersonID,ServiceID,1,RowID,0 from FitGroup where RowID="+AnsiString(ID)).c_str());
    SQL_CommitTransaction();

    sgSheduleFullUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TFitSheduleForm::sgClientsDrawCell(TObject *Sender,
      int ACol, int ARow, TRect &Rect, TGridDrawState State)
{
    sgDrawCell(Sender,ACol,ARow,Rect,State,fldAlignClients);
}
//---------------------------------------------------------------------------
void __fastcall TFitSheduleForm::sgSheduleClick(TObject *Sender)
{
    sgClientsFullUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TFitSheduleForm::FormDestroy(TObject *Sender)
{
    delete [] SheduleWidths;
    delete [] ClientsWidths;
}
//---------------------------------------------------------------------------

