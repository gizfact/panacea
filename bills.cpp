//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "bills.h"
#include "lib.h"
#include "kkm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TBillsForm *BillsForm;

extern __int64 ClientID;
extern const char *MoneyFormat;
extern int KKM_LINK;
//---------------------------------------------------------------------------

//***************************************************************************
//******************************* CALLBACKS *********************************
//***************************************************************************

//---------------------------------------------------------------------------
static int bills_select(void *NotUsed, int argc, char **argv, char **azColName)
{
    //  RowID,CDate,BegBalanse,FromBalanse,ToBalanse,EndBalanse,Total,FullName,UserName,Payment,KKM
    //  "","Дата","Кассир","Клиент","Сумма чека"

    __int64 ID = _atoi64(argv[0]);
    if(!ID) return 0;

    if(BillsForm->sgBills->RowCount == 2)
    {
        if(BillsForm->sgBills->Cells[1][1].Length() > 0)
            BillsForm->sgBills->RowCount++;
    }
    else
        BillsForm->sgBills->RowCount++;

    int pos = BillsForm->sgBills->RowCount - 1;

    BillsForm->sgBills->Objects[0][pos] = (TObject *)ID;

    int status = ATOI(argv[10]);

    BillsForm->sgBills->Cells[0][pos] = (status == 1)? " " : (status == 0)? "" : "\t";
    BillsForm->sgBills->Cells[1][pos] = TDateTime(atof(argv[1])).DateTimeString();

    BillsForm->sgBills->Cells[2][pos] = argv[8]? argv[8] : "";
    BillsForm->sgBills->Cells[3][pos] = argv[7]? argv[7] : "";
    BillsForm->sgBills->Cells[4][pos] = FormatFloat(MoneyFormat,ATOF(argv[6])).TrimLeft();

    return 0;
}
//---------------------------------------------------------------------------
static int bills_select2(void *NotUsed, int argc, char **argv, char **azColName)
{
    //  "",a.OpDate,a.Summ,b.StarsUser

    if(BillsForm->sgBills->RowCount == 2)
    {
        if(BillsForm->sgBills->Cells[1][1].Length() > 0)
            BillsForm->sgBills->RowCount++;
    }
    else
        BillsForm->sgBills->RowCount++;

    int pos = BillsForm->sgBills->RowCount - 1;



    BillsForm->sgBills->Cells[0][pos] = "";
    BillsForm->sgBills->Cells[1][pos] = TDateTime(atof(argv[0])).DateTimeString();
    BillsForm->sgBills->Cells[2][pos] = argv[2];
    double d = ATOF(BillsForm->retS.c_str());
    if(pos == 1)
        BillsForm->sgBills->Cells[3][pos] = "ИТОГО: " + FormatFloat(MoneyFormat,d).TrimLeft();
    else if(d < 0)
        BillsForm->sgBills->Cells[3][pos] = "СНЯТИЕ НАЛИЧНЫХ";
    else
        BillsForm->sgBills->Cells[3][pos] = "ВНЕСЕНИЕ НАЛИЧНЫХ";
    BillsForm->sgBills->Cells[4][pos] = FormatFloat(MoneyFormat,ATOF(argv[1])).TrimLeft();

    return 0;
}
//---------------------------------------------------------------------------
__fastcall TBillsForm::TBillsForm(TComponent* Owner)
    : TForm(Owner)
{
    dtpBegDate->DateTime = dtpBegDate->DateTime.CurrentDateTime();
    dtpEndDate->DateTime = dtpBegDate->DateTime;
}
//---------------------------------------------------------------------------
void __fastcall TBillsForm::sgBillsWindowProc(Messages::TMessage& Msg)
{
    sgWindowProc(Msg,sgBills,sgBillsWidths,sgOBillsWindowProc);
}
//---------------------------------------------------------------------------
void __fastcall TBillsForm::sgBillItemsWindowProc(Messages::TMessage& Msg)
{
    sgWindowProc(Msg,sgBillItems,sgBillItemsWidths,sgOBillItemsWindowProc);
}
//---------------------------------------------------------------------------
void __fastcall TBillsForm::FormShow(TObject *Sender)
{
    sgSetHeaders(sgBills,"","Дата","Кассир","Клиент","Сумма чека");
    sgSetWidths(sgBills,&sgBillsWidths,16,160,80,250);
    sgBillsAligns = "cLrrr";

    sgSetHeaders(sgBillItems,"Операция","Цена","Кол-во","Сумма");
    sgSetWidths(sgBillItems,&sgBillItemsWidths,400,100,80);
    sgBillItemsAligns = "Lrrr";

    sgOBillsWindowProc = sgBills->WindowProc;
    sgBills->WindowProc = sgBillsWindowProc;

    sgOBillItemsWindowProc = sgBillItems->WindowProc;
    sgBillItems->WindowProc = sgBillItemsWindowProc;

    sgBillsFullUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TBillsForm::sgBillsFullUpdate()
{
    //

    sgBills->OnSelectCell = NULL;

    sgBills->RowCount = 2;
    sgBills->Objects[0][1] = NULL;
    sgBills->Rows[1]->Clear();

    if(!cbOutcome->Checked)
    {
        SQL_exe(NULL,
        (
            "select a.RowID,a.CDate,a.BegBalanse,a.FromBalanse,a.ToBalanse,a.EndBalanse,a.Total,c.FullName,b.StarsUser,a.Payment,a.KKM "
            "from Bills a "
            "left join Stars b on a.CUID=b.RowID "
            "left join Clients c on a.ClientID=c.RowID "
            "where a.CDate>=" + AnsiString((int)(dtpBegDate->Date)) +
            "and a.CDate<" + AnsiString((int)(dtpEndDate->Date + 1)) +
            "order by CDate desc"

        ).c_str(),bills_select);


    }
    else
    {
        SQL_exefun(NULL,
        (
            "select sum(a.Summ) "
            "from KKM a "
            "where a.OpDate>=" + AnsiString((int)(dtpBegDate->Date)) +
            "and a.OpDate<" + AnsiString((int)(dtpEndDate->Date + 1))

        ).c_str(),&retS);

        SQL_exe(NULL,
        (
            "select a.OpDate,a.Summ,b.StarsUser "
            "from KKM a "
            "left join Stars b on a.StarID=b.RowID "

            "where a.OpDate>=" + AnsiString((int)(dtpBegDate->Date)) +
            "and a.OpDate<" + AnsiString((int)(dtpEndDate->Date + 1)) +
            "order by a.OpDate desc"

        ).c_str(),bills_select2);
    }

    sgBillItemsFullUpdate(1);

    sgBills->OnSelectCell = sgBillsSelectCell;
}
//---------------------------------------------------------------------------
void __fastcall TBillsForm::sgBillItemsFullUpdate(int row)
{
    sgBillItems->RowCount = 2;
    sgBillItems->Rows[1]->Clear();

    laPay->Caption = "";
    laDep->Caption = "";
    laSell->Caption = "";
    laTerminal->Caption = "";
    laFrom->Caption = "";
    laChange->Caption = "";

    //int dep, pay;
    double total = 0, getsum = 0, terminal = 0, change = 0, frombal = 0;

    //SQL_BeginTransaction();
    TList* pBill = BuildBill((__int64)(sgBills->Objects[0][row]),&total,&getsum,&terminal,&frombal,&change);

    //SQL_CancelTransaction();

    if(KKM_LINK != -1 || KKM_USE != 1 || !pBill) goto _notlink;
    if(sgBills->Cells[0][row] == "")
    {
        bCheck->Enabled = true;
        bCancel->Enabled = false;
    }
    else if(sgBills->Cells[0][row] == " ")
    {
        bCheck->Enabled = false;
        bCancel->Enabled = true;
    }
    else
    {
    _notlink:
        bCheck->Enabled = false;
        bCancel->Enabled = false;
    }

    if(pBill)
    {
        if(getsum > 0)
        {
            if(terminal > 0 || frombal > 0)
            {
                laPay->Caption = "нал.+б/н";
                laDep->Caption = "1+2";
            }
            else
            {
                laPay->Caption = "нал.";
                laDep->Caption = "1";
            }
        }
        else if(terminal > 0 || frombal > 0)
        {
            laPay->Caption = "б/н";
            laDep->Caption = "2";
        }
      
        else
        {
            laPay->Caption = "со счета";
            laDep->Caption = "0";
        }

        laSell->Caption = FormatFloat(MoneyFormat,getsum).TrimLeft();
        laTerminal->Caption = FormatFloat(MoneyFormat,terminal).TrimLeft();
        laFrom->Caption = FormatFloat(MoneyFormat,frombal).TrimLeft();
        laChange->Caption = FormatFloat(MoneyFormat,change).TrimLeft();


        int pos;
        double d1, d2;
        // Операция Цена Кол-во Сумма
        for(int i = 0; i < pBill->Count; i++)
        {
            if(sgBillItems->RowCount == 2)
            {
                if(sgBillItems->Cells[0][1].Length() > 0)
                    sgBillItems->RowCount++;
            }
            else
                sgBillItems->RowCount++;

            pos = sgBillItems->RowCount - 1;

            sgBillItems->Cells[0][pos] = ((BillPosition *)pBill->Items[i])->name;
            d1 = ((BillPosition *)pBill->Items[i])->price;
            d2 = ((BillPosition *)pBill->Items[i])->quan;
            sgBillItems->Cells[1][pos] = FormatFloat(MoneyFormat,d1).TrimLeft();
            sgBillItems->Cells[2][pos] = d2;
            sgBillItems->Cells[3][pos] = FormatFloat(MoneyFormat,d1 * d2).TrimLeft();
        }

        for(int i = 0; i < pBill->Count; i++)
            delete (BillPosition *)(pBill->Items[i]);

        pBill->Clear();
        delete pBill;
    }
}
//---------------------------------------------------------------------------
void __fastcall TBillsForm::sgBillsSelectCell(TObject *Sender, int ACol,
      int ARow, bool &CanSelect)
{
    static int _arow = -1;

    if(ARow == _arow) return;

    _arow = ARow;

    if(!cbOutcome->Checked)
        sgBillItemsFullUpdate(_arow);
}
//---------------------------------------------------------------------------
void __fastcall TBillsForm::sgBillsDrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
    sgDrawCell(Sender,ACol,ARow,Rect,State,sgBillsAligns,sgBills->Objects[0][ARow] != NULL,ilBills);
}
//---------------------------------------------------------------------------
void __fastcall TBillsForm::sgBillItemsDrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
    sgDrawCell(Sender,ACol,ARow,Rect,State,sgBillItemsAligns);
}
//---------------------------------------------------------------------------
void __fastcall TBillsForm::dtpBegDateCloseUp(TObject *Sender)
{
    if(dtpEndDate->Date < dtpBegDate->Date)
    {
        sgBills->RowCount = 2;
        sgBills->Objects[0][1] = NULL;
        sgBills->Rows[1]->Clear();

        sgBillItems->RowCount = 2;
        sgBillItems->Rows[1]->Clear();

        laPay->Caption = "";
        laDep->Caption = "";
        laSell->Caption = "";
        laTerminal->Caption = "";
        laFrom->Caption = "";
        laChange->Caption = "";

        if(cbOutcome->Checked)
        {
            bCheck->Enabled = false;
            bCancel->Enabled = false;
        }
    }
    else
    {
        sgBillsFullUpdate();
        sgBills->SetFocus();
    }
}
//---------------------------------------------------------------------------
void __fastcall TBillsForm::bCheckClick(TObject *Sender)
{
    // Взаимодействие с ККМ
    __int64 ID = (__int64)sgBills->Objects[0][sgBills->Row];

    if(kkm_bill_print(ID) == 0)
    {
        // Меняем статус чека
        SQL_iniUpdate(NULL,"Bills",ID);
        SQL_exeUpdate("KKM",1);

        sgBills->Cells[0][sgBills->Row] = ' ';
        // Пробито
        bCheck->Enabled = false;
        bCancel->Enabled = true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TBillsForm::bCancelClick(TObject *Sender)
{
    // Взаимодействие с ККМ
    __int64 ID = (__int64)sgBills->Objects[0][sgBills->Row];

    if(kkm_bill_retprint(ID) == 0)
    {
        // Меняем статус чека
        SQL_iniUpdate(NULL,"Bills",ID);
        SQL_exeUpdate("KKM",2);

        //sgBillsFullUpdate();
        sgBills->Cells[0][sgBills->Row] = '\t';
        // Возврат
        bCancel->Enabled = false;
    }
}
//---------------------------------------------------------------------------

