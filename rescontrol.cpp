//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "rescontrol.h"
#include "lib.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TResControlForm *ResControlForm;

static AnsiString retString;
//---------------------------------------------------------------------------

//***************************************************************************
//******************************* CALLBACKS *********************************
//***************************************************************************

//---------------------------------------------------------------------------
static int rescontrol_select(void *NotUsed, int argc, char **argv, char **azColName)
{
    // Date,UserName,ClientName,ServiceName,PersonalName

    TDateTime dt;
    if(argv[0])
        dt = atof(argv[0]);
    else
        dt = 0;

    if(ResControlForm->sgResControl->Cells[0][1].Length() > 0)
        ResControlForm->sgResControl->RowCount++;

    int pos = ResControlForm->sgResControl->RowCount - 1;

    __int64 SID = (argv[5])? _atoi64(argv[5]) : 0;

    ResControlForm->sgResControl->Cells[0][pos] = dt;
    ResControlForm->sgResControl->Cells[1][pos] = argv[1];
    ResControlForm->sgResControl->Cells[2][pos] = argv[2];
    if(SID)
    {
        SQL_exefun(NULL,("select Name from Services where RowID="+AnsiString(SID)).c_str(),&retString);
        ResControlForm->sgResControl->Cells[3][pos] = "[" + retString + "]" + argv[3];
    }
    else
        ResControlForm->sgResControl->Cells[3][pos] = argv[3];

    ResControlForm->sgResControl->Cells[4][pos] = argv[4];


    return 0;
}
//---------------------------------------------------------------------------
__fastcall TResControlForm::TResControlForm(TComponent* Owner)
    : TForm(Owner)
{
    fldAlignResControl = "LRrrr";
}
//---------------------------------------------------------------------------
void __fastcall TResControlForm::sgResControlWindowProc(Messages::TMessage& Msg)
{
    sgWindowProc(Msg,sgResControl,ResControlWidths,sgOResControlWindowProc);
}
//---------------------------------------------------------------------------
void __fastcall TResControlForm::FormShow(TObject *Sender)
{
    dtpBegDate->DateTime = Now();
    dtpEndDate->DateTime = dtpBegDate->DateTime + 1;

    sgSetHeaders(sgResControl,"Дата","Администратор","Клиент","Услуга","Специалист");
    sgSetWidths(sgResControl,&ResControlWidths,160,120,240,150);

    sgOResControlWindowProc = sgResControl->WindowProc;
    sgResControl->WindowProc = sgResControlWindowProc;

    sgResControlFullUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TResControlForm::FormDestroy(TObject *Sender)
{
    delete [] ResControlWidths;
}
//---------------------------------------------------------------------------
void __fastcall TResControlForm::sgResControlFullUpdate(void)
{
AnsiString sql = "select CD,UN,CN,SN,PN,PaID from ("


"select CD,StarsUser as UN,FNAME||' '||SNAME||' '||TNAME as CN,Services.Name as SN,Personal.Name as PN,Services.ParentID as PaID from "
"( "
    "select BegDate as CD,CUID as CUI,ClientID as CLID,ServiceID as SID,PersonID as PID from Reserve "
") left outer join Stars on CUI=Stars.RowID "
"left outer join Clients on CLID=Clients.RowID "
"left outer join Services on SID=Services.RowID "
"left outer join Personal on PID=Personal.RowID) where CD>=";

    sql += (int)dtpBegDate->Date;
    sql += " and CD<";
    sql += (int)dtpEndDate->Date;

    if(edFilter->Text.Length() > 0)
    {
        sql += " and (Upper(CN) like '%" + edFilter->Text.UpperCase() + "%' or ";
        sql += "Upper(UN) like '%" + edFilter->Text.UpperCase() + "%' or ";
        sql += "Upper(SN) like '%" + edFilter->Text.UpperCase() + "%' or ";
        sql += "Upper(PN) like '%" + edFilter->Text.UpperCase() + "%')";




    }

    sql += " order by 1 desc";

    sgResControl->RowCount = 2;

    sgClearRow(sgResControl);

    SQL_BeginTransaction();
    SQL_exe(NULL,sql.c_str(),rescontrol_select);
    SQL_CancelTransaction();
}
//---------------------------------------------------------------------------
void __fastcall TResControlForm::sgResControlDrawCell(TObject *Sender,
      int ACol, int ARow, TRect &Rect, TGridDrawState State)
{
   sgDrawCell(Sender,ACol,ARow,Rect,State,fldAlignResControl);
}
//---------------------------------------------------------------------------
void __fastcall TResControlForm::tbExitClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TResControlForm::dtpBegDateCloseUp(TObject *Sender)
{
    if(dtpBegDate->DateTime >= dtpEndDate->DateTime)
        dtpEndDate->DateTime = dtpBegDate->DateTime + 1;

    sgResControlFullUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TResControlForm::dtpEndDateCloseUp(TObject *Sender)
{
    if(dtpBegDate->DateTime >= dtpEndDate->DateTime)
        dtpBegDate->DateTime = dtpEndDate->DateTime - 1;

    sgResControlFullUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TResControlForm::edFilterKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
    if(Key == VK_RETURN && edFilter->Modified)
    {
        sgResControlFullUpdate();
        Key = 0;
    }
}
//---------------------------------------------------------------------------

