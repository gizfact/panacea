//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fitgroup.h"
#include "lib.h"
#include "i_fitgroup.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

extern int FormResult;
extern __int64 ClientID;
extern const char *DBName;

extern __int64 UserID;

TFitGroupForm *FitGroupForm;
//---------------------------------------------------------------------------
static int shedule_fill(void *NotUsed,int argc,char **argv,char **azColName)
{
    __int64 ID = atoi(argv[0]);
    if(!ID) return 0;

    if(FitGroupForm->sgShedule->Cells[0][1].Length())
        FitGroupForm->sgShedule->RowCount++;

    int pos = FitGroupForm->sgShedule->RowCount - 1;

    FitGroupForm->sgShedule->Rows[pos]->Objects[0] = (TObject *)ID;
    FitGroupForm->sgShedule->Cells[0][pos] = (argv[1]);
    FitGroupForm->sgShedule->Cells[1][pos] = (argv[2]);
    FitGroupForm->sgShedule->Cells[2][pos] = TDateTime(atof(argv[3])).FormatString("hh:nn");
    FitGroupForm->sgShedule->Cells[3][pos] = TDateTime(atof(argv[4])).FormatString("hh:nn");
    FitGroupForm->sgShedule->Cells[4][pos] = atoi(argv[5]);

    return 0;
}
//---------------------------------------------------------------------------
__fastcall TFitGroupForm::TFitGroupForm(TComponent* Owner)
    : TForm(Owner)
{
    fldAlignShedule = "Lrrrr";

    CurrentDay = (int)Now();
    CurrentWDay = CurrentDay.DayOfWeek() - 1;
    if(!CurrentWDay) CurrentWDay = 7;

    switch(CurrentWDay)
    {
case 1: sbMo->Down = true; CurButton = 0; break;
case 2: sbTu->Down = true; CurButton = 1; break;
case 3: sbWe->Down = true; CurButton = 2; break;
case 4: sbTh->Down = true; CurButton = 3; break;
case 5: sbFr->Down = true; CurButton = 4; break;
case 6: sbSa->Down = true; CurButton = 5; break;
case 7: sbSu->Down = true; CurButton = 6;
    }

    FirstButton = CurButton;
}
//---------------------------------------------------------------------------
void __fastcall TFitGroupForm::tbExitClick(TObject *Sender)
{
    Close();    
}
//---------------------------------------------------------------------------
void __fastcall TFitGroupForm::sgSheduleDrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
    sgDrawCell(Sender,ACol,ARow,Rect,State,fldAlignShedule);
}
//---------------------------------------------------------------------------
void __fastcall TFitGroupForm::FormShow(TObject *Sender)
{
    sgSetHeaders(sgShedule,"������","����������","������","�����","���-��");
    sgSetWidths(sgShedule,&SheduleWidths,180,120,80,80);

    sgOSheduleWindowProc = sgShedule->WindowProc;
    sgShedule->WindowProc = sgSheduleWindowProc;

    laDate->Caption = (CurrentDay + CurButton - FirstButton).DateString();

    sgSheduleFullUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TFitGroupForm::sgSheduleWindowProc(Messages::TMessage& Msg)
{
    sgWindowProc(Msg,sgShedule,SheduleWidths,sgOSheduleWindowProc);
}
//---------------------------------------------------------------------------
void __fastcall TFitGroupForm::ToolButton1Click(TObject *Sender)
{
    if((int)CurrentDay < (int)Now()) return;

    FormResult = 0;

    iFitGroupForm = new TiFitGroupForm(this);

    iFitGroupForm->CurrentID = 0;
    iFitGroupForm->CurrentDay = CurrentDay + CurButton - FirstButton;
    iFitGroupForm->CurrentWDay = iFitGroupForm->CurrentDay.DayOfWeek() - 1;
    if(!iFitGroupForm->CurrentWDay) iFitGroupForm->CurrentWDay = 7;

    iFitGroupForm->ShowModal();
    delete iFitGroupForm;

    if(FormResult == 1)
        sgSheduleFullUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TFitGroupForm::sgSheduleFullUpdate(void)
{
    sgShedule->RowCount = 2;
    sgShedule->Row = 1;

    sgClearRow(sgShedule);



    SQL_exe(DBName,("select FitGroup.RowID,Services.Name,Personal.Name,BegDate,EndDate,FitGroupCount from FitGroup,Services,Personal where "
    "FitGroup.ServiceID=Services.RowID and FitGroup.PersonID=Personal.RowID and trunc(BegDate,0)="+AnsiString((int)CurrentDay+CurButton-FirstButton)+" order by BegDate,Services.Name").c_str(),shedule_fill);

}
//---------------------------------------------------------------------------
void __fastcall TFitGroupForm::sbMoClick(TObject *Sender)
{
    CurButton = ((TSpeedButton *)Sender)->Tag - 1;
    laDate->Caption = (CurrentDay + CurButton - FirstButton).DateString();
    sgSheduleFullUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TFitGroupForm::sgSheduleDblClick(TObject *Sender)
{
    __int64 ID = (__int64)sgShedule->Rows[sgShedule->Row]->Objects[0];

    if(!ID) return;

    FormResult = 0;

    iFitGroupForm = new TiFitGroupForm(this);

    iFitGroupForm->CurrentID = ID;
    iFitGroupForm->CurrentDay = CurrentDay + CurButton - FirstButton;
    iFitGroupForm->CurrentWDay = iFitGroupForm->CurrentDay.DayOfWeek() - 1;
    if(!iFitGroupForm->CurrentWDay) iFitGroupForm->CurrentWDay = 7;

    iFitGroupForm->ShowModal();
    delete iFitGroupForm;

    if(FormResult == 1)
        sgSheduleFullUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TFitGroupForm::ToolButton2Click(TObject *Sender)
{
    //if((int)CurrentDay < (int)Now()) return;

    __int64 ID = (__int64)sgShedule->Rows[sgShedule->Row]->Objects[0];

    if(!ID) return;

    // ��������, ���� �� ����������
    AnsiString sRet;
    SQL_exefun(DBName,("select count(*) from Reserve where Status=2 and FitGroupID="+AnsiString(ID)).c_str(),&sRet);
    if(atoi(sRet.c_str()) != 0)
    {
        Application->MessageBox("��������!\n�� ������ ���� ������������� ������. �������� ����������.","",MB_OK);
        return;
    }

    SQL_exefun(DBName,("select count(*) from Reserve where Status!=2 and FitGroupID="+AnsiString(ID)).c_str(),&sRet);
    if(atoi(sRet.c_str()) != 0)
    {
        if(Application->MessageBox("��������!\n�� ������ ���� ������. ������� ������ � ��������� ������?","",MB_OKCANCEL) == IDCANCEL)
            return;
        //const char *pMsg = "TFitGroupForm::ToolButton2Click";
        SQL_BeginTransaction();

        SQL_exe(NULL,("insert into Reserve_Del select Reserve.*,null,null from Reserve where RowID="+AnsiString(ID)+" or FitGroupID="+AnsiString(ID)).c_str());
        SQL_exe(NULL,(AnsiString("update Reserve_Del set EDATE=")+(double)Now()+",EUID="+AnsiString(UserID)+" where EDATE is null and EUID is null").c_str());

        SQL_exe(DBName,("delete from Reserve where RowID="+AnsiString(ID)+" or FitGroupID="+AnsiString(ID)).c_str());
        //SQL_exe(DBName,("delete from FitGroup where RowID="+AnsiString(ID)).c_str());
        SQL_CommitTransaction();

        sgSheduleFullUpdate();
        return;
    }

    SQL_BeginTransaction();
    SQL_exe(DBName,("delete from FitGroup where RowID="+AnsiString(ID)).c_str());
    SQL_CommitTransaction();

    sgSheduleFullUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TFitGroupForm::FormDestroy(TObject *Sender)
{
    delete [] SheduleWidths;
}
//---------------------------------------------------------------------------
void __fastcall TFitGroupForm::SpeedButton1Click(TObject *Sender)
{
    CurrentDay = (int)Now();
    laDate->Caption = (CurrentDay + CurButton - FirstButton).DateString();
    sgSheduleFullUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TFitGroupForm::SpeedButton2Click(TObject *Sender)
{
    CurrentDay -= 7;
    laDate->Caption = (CurrentDay + CurButton - FirstButton).DateString();
    sgSheduleFullUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TFitGroupForm::SpeedButton3Click(TObject *Sender)
{
    //if((int)CurrentDay == (int)Now()) return;
    CurrentDay += 7;
    laDate->Caption = (CurrentDay + CurButton - FirstButton).DateString();
    sgSheduleFullUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TFitGroupForm::ToolButton3Click(TObject *Sender)
{
    // ����������� ����������� ����������
    
    int pd = (int)CurrentDay - FirstButton - 7;
    SQL_BeginTransaction();
    SQL_exe(DBName,("insert into FitGroup select null,FitGroupDay,a.ServiceID,a.PersonID,BegDate+7,EndDate+7,FitGroupCount,0 from FitGroup a,Personal,Services where BegDate>="+AnsiString(pd)+" and EndDate<"+AnsiString(pd+7)+" and PersonID=Personal.RowID and Personal.ServiceID=Services.RowID and Alive=1 and bin_and(WeekDays,127)!=0").c_str());
    SQL_CommitTransaction();

    sgSheduleFullUpdate();
}
//---------------------------------------------------------------------------

