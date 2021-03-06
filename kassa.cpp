//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <math.h>
#include "kassa.h"
#include "accounts.h"
#include "servicesprice.h"
#include "abtypes.h"
#include "abparam.h"
#include "i_visits.h"
#include "goods.h"
#include "bath.h"
#include "barber.h"
#include "nail.h"
#include "cosmetic.h"

#include "discard.h"

#include "kkm.h"

#define DYN_LENGTH      20


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TKassaForm *KassaForm;

extern const char *DBName;
extern __int64 ClientID;
extern __int64 BillsID;
extern __int64 UserID;
extern unsigned char UserGrants[FORMS_COUNT];
extern int FormResult;

extern int ServicesPriceFormMode;
extern __int64 ServicesPriceFormRetID;
extern AnsiString ServicesPriceFormRetStr;

extern int AbTypesFormMode;
extern __int64 AbTypesFormRetID;
extern AnsiString AbTypesFormRet1;
extern AnsiString AbTypesFormRet2;
extern AnsiString AbTypesFormRet3;
extern AnsiString AbTypesFormRet4;

extern __int64 LastAbID;
extern int LastAbAutoFlow;
extern int LastAbVisits;
extern TDateTime LastAbEndDate;

extern double UserBalanse;
extern double UserDiscount;
extern double UserDiscountSPA;

extern bool NegBalanseFlag;

extern bool WriteACheck;

static TWndMethod sgOWindowProc;

static TDateTime CDate, EDate;
static __int64 CUID, EUID;

static AnsiString retString;

static AnsiString *pUsers = NULL;
static __int64 *pUserIDs = NULL;
static unsigned UsersCounter = 0;




static double BegBalanse = 0.0;
static double FromBalanse = 0.0;
static double ToBalanse = 0.0;
static double EndBalanse = 0.0;
static double GetSum = 0.0;
static double Terminal = 0.0;
static double Change = 0.0;


static int blaW1, blaW, blaC;

static int edInputCol;

extern const char *MoneyFormat;
extern int iVisitMode;
extern __int64 VisitID;
extern __int64 VisitServiceID;
extern AnsiString VisitServiceName;
extern __int64 VisitPersonID;
extern double VisitBegTime;
extern double VisitEndTime;
extern double VisitPrice;

extern __int64 KassaBillID;

extern int KKM_LINK;
extern int KKM_USE;
//---------------------------------------------------------------------------

//***************************************************************************
//******************************* CALLBACKS *********************************
//***************************************************************************

//---------------------------------------------------------------------------
static int users_select(void *NotUsed, int argc, char **argv, char **azColName)
{
    pUserIDs[UsersCounter] = (argv[0])? _atoi64(argv[0]) : -1;
    if(argv[1])
        pUsers[UsersCounter++] = (argv[1]);
    else
        pUsers[UsersCounter++] = "unknown";

    return 0;
}
//---------------------------------------------------------------------------
static int abonements_create(void *NotUsed, int argc, char **argv, char **azColName)
{
    if(!argv[0]) return 0;

    KassaForm->pAbFields[0] = argv[0];
    KassaForm->pAbFields[1] = argv[1];
    KassaForm->pAbFields[2] = argv[2];
    KassaForm->pAbFields[3] = argv[3];
    KassaForm->pAbFields[4] = argv[4];
    KassaForm->pAbFields[5] = argv[5];
    KassaForm->pAbFields[6] = argv[6];
    KassaForm->pAbFields[7] = argv[7];
    KassaForm->pAbFields[8] = argv[8];
    //KassaForm->pAbFieldsCounter++;
    
    return 0;
}
//---------------------------------------------------------------------------
static int billitems_reload(void *NotUsed,int argc,char **argv,char **azColName)
{
    //
    // argv[0] - Op
    // argv[1] - Price
    // argv[2] - Count
    if(!argv[0]) return 0;

    int Op = atoi(argv[0]);
    double price = (argv[1])? strtof(argv[1]) : 0.0;

    if(Op == SELLOP_ADDBALANSE)
        ToBalanse += price;

    int count = (argv[2])? atoi(argv[2]) : 0;

    KassaForm->Total += (price * count);

    return 0;
}
//---------------------------------------------------------------------------
static int billitems_select(void *NotUsed,int argc,char **argv,char **azColName)
{
    if(!argv[0]) return 0;
    if((int)KassaForm->Counter >= KassaForm->IDs.Length)
        KassaForm->IDs.Length = KassaForm->IDs.Length + 10;
    KassaForm->IDs[KassaForm->Counter] = atoi(argv[0]);

    if(!argv[1]) return 0;
    int op = atoi(argv[1]);

    double price;
    if(!argv[5]) price = 0.0;
    else price = atof(argv[5]);

    double discount;
    if(!argv[6]) discount = 0.0;
    else discount = atof(argv[6]);

    int count;
    if(!argv[7]) count = 0;
    else count = atoi(argv[7]);

    double total;
    if(!argv[8]) total = 0.0;
    else total = atof(argv[8]);

    if(KassaForm->Counter++) KassaForm->sgKassa->RowCount++;

    switch(op)
    {
case SELLOP_ADDBALANSE: KassaForm->sgKassa->Cells[0][KassaForm->Counter] = "���������� �������";
                        retString = "";
                        //BalanseChange += total;
                        break;
case SELLOP_ABONEMENT:  if(argv[2])
                        {
                            SQL_exefun(DBName,("select Name from AbTypes where RowID="+(AnsiString)argv[2]).c_str(),&retString);
                            KassaForm->sgKassa->Cells[0][KassaForm->Counter] = "���������";
                        }
                        else
                            retString = "��� ������";
                        break;
case SELLOP_ABONEMENT_SPA:
                        KassaForm->sgKassa->Cells[0][KassaForm->Counter] = "��������� SPA";
                        retString = ("������ "+AnsiString(discount)+"%");
                        break;
case SELLOP_GOOD:       if(argv[3])
                        {
                            SQL_exefun(DBName,("select Name from Goods where RowID="+(AnsiString)argv[3]).c_str(),&retString);
                            KassaForm->sgKassa->Cells[0][KassaForm->Counter] = "�����";
                        }
                        else
                            retString = "��� ������";
                        break;
case SELLOP_SERVICE:    if(argv[4])
                        {
                            SQL_exefun(DBName,("select Name from Services where RowID="+(AnsiString)argv[4]).c_str(),&retString);
                            KassaForm->sgKassa->Cells[0][KassaForm->Counter] = "������";
                        }
                        else
                            retString = "��� ������";
                        break;
default: return 0;
    }

    KassaForm->sgKassa->Cells[1][KassaForm->Counter] = retString;
    KassaForm->sgKassa->Cells[2][KassaForm->Counter] = FormatFloat(MoneyFormat,price).TrimLeft();
    KassaForm->sgKassa->Cells[3][KassaForm->Counter] = count;
    KassaForm->sgKassa->Cells[4][KassaForm->Counter] = FormatFloat(MoneyFormat,discount).TrimLeft();
    KassaForm->sgKassa->Cells[5][KassaForm->Counter] = FormatFloat(MoneyFormat,total).TrimLeft();

    //Total += total;

    return 0;
}
//---------------------------------------------------------------------------
/*
static int bills_select(void *NotUsed,int argc,char **argv,char **azColName)
{
    AnsiString status = "ID: " + (AnsiString)BillsID;

    if(argv[0])
        CDate = atof(argv[0]);
    else
        CDate = 0;

    CUID = (argv[1])? _atoi64(argv[1]) : -1;

    if(argv[2])
        EDate = atof(argv[2]);
    else
        EDate = 0;

    EUID = (argv[3])? _atoi64(argv[3]) : -1;

    BegBalanse  = (argv[4]) ? atof(argv[4])  : 0.0;
    FromBalanse = (argv[5]) ? atof(argv[5])  : 0.0;
    ToBalanse   = (argv[6]) ? atof(argv[6])  : 0.0;
    EndBalanse  = (argv[7]) ? atof(argv[7])  : 0.0;
    GetSum      = (argv[8]) ? atof(argv[8])  : 0.0;
    Change      = (argv[9]) ? atof(argv[9])  : 0.0;
    Total       = (argv[10])? atof(argv[10]) : 0.0;

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

    KassaForm->sbKassa->SimpleText = status;

    SQL_exe(DBName,("select RowID,Op,AbTypeID,GoodID,ServiceID,Price,Discount,BillItemsCount,Total from BillItems where BillID="+(AnsiString)BillsID+" order by RowID").c_str(),billitems_select);

    return 0;
}*/
//---------------------------------------------------------------------------

//***************************************************************************
//*************************** END CALLBACKS *********************************
//***************************************************************************

//---------------------------------------------------------------------------
void __fastcall TKassaForm::KassaUpdateInfo(void)
{
    if(!tbSave->Visible) return;

    //if(spbTerminal->Down)
    //{
    //    GetSum = Total;
    //}

    EndBalanse = BegBalanse - FromBalanse + ToBalanse;

    edFromBalanse->Text = FormatFloat(MoneyFormat,FromBalanse).TrimLeft();
    edToBalanse->Text = FormatFloat(MoneyFormat,ToBalanse).TrimLeft();
    laEndBalanse->Caption = FormatFloat(MoneyFormat,EndBalanse).TrimLeft();
    edGetSum->Text = FormatFloat(MoneyFormat,GetSum).TrimLeft();
    //double terminal = ATOF(edTerminal->Text.c_str());
    edTerminal->Text = FormatFloat(MoneyFormat,Terminal).TrimLeft();
    Change = Terminal + GetSum - Total - ToBalanse + FromBalanse;
    if(Change < 0) Change = 0;
    else if(Change > GetSum) Change = GetSum;
    laChange->Caption = FormatFloat(MoneyFormat,Change).TrimLeft();

    laTotal->Caption = "�����: " + FormatFloat(MoneyFormat,Total).TrimLeft();
}
//---------------------------------------------------------------------------
void __fastcall TKassaForm::sgWindowProc(Messages::TMessage& Msg)
{
    bool done = Msg.Msg == WM_SIZE;

    if(Msg.Msg == WM_NCHITTEST || done)
    {
        int i;

        if(!done)
        {
            for(i = 0; i < sgKassa->ColCount; i++)
                if(sgKassa->ColWidths[i] != KassaWidths[i]) break;
            done = i < sgKassa->ColCount;
        }

        if(done)
        {
            int sum_width = 0;

            for(i = 0; i < sgKassa->ColCount; i++)
            {
                if(sgKassa->ColWidths[i] < 16) sgKassa->ColWidths[i] = 16;
                sum_width += sgKassa->ColWidths[i];
            }

            int width = sgKassa->ClientWidth - sgKassa->ColCount;

            if(sum_width < width) sgKassa->ColWidths[sgKassa->ColCount-1] += (width - sum_width);
            else if(sum_width > width)
            {
                // ����� �� �������
                int w;

                for(i = sgKassa->ColCount - 1; i >= 0 && sum_width > width; i--)
                {
                    w = sgKassa->ColWidths[i];

                    sgKassa->ColWidths[i] -= (sum_width - width);
                    if(sgKassa->ColWidths[i] < 16)
                    {
                        sgKassa->ColWidths[i] = 16;
                        sum_width -= (w - 16);
                    }
                    else
                        break;
                }
            }

            for(i = 0; i < sgKassa->ColCount; i++)
                KassaWidths[i] = sgKassa->ColWidths[i];
        }
    }

    if(Msg.Msg != WM_SIZE)
        sgOWindowProc(Msg);
}
//---------------------------------------------------------------------------
__fastcall TKassaForm::TKassaForm(TComponent* Owner)
    : TForm(Owner)
{
    KassaOps = 0;
    GoodsCount = 0;
    fldAlign = "llrrrr";

    ResBegDate = 0;
    ResEndDate = 0;

    ResServiceID = 0;
    ResPersonID = 0;

    Counter = 0;
    Total = 0;

    InTransaction = false;
}
//---------------------------------------------------------------------------
void __fastcall TKassaForm::FormDestroy(TObject *Sender)
{
    IDs.Length = 0;

    PDEL(pUsers);
    PDEL(pUserIDs);

    delete [] KassaWidths;
}
//---------------------------------------------------------------------------
void __fastcall TKassaForm::tbExit0Click(TObject *Sender)
{
    SQL_BeginTransaction();
    SQL_exefun(DBName,("delete from BillItems where BillID="+AnsiString(KassaBillID)).c_str());
    SQL_CommitTransaction();
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TKassaForm::tbSave0Click(TObject *Sender)
{
    __int64 ID;

    if((ID = Billing()) != 0)
    {
        if(((TButton *)Sender)->Tag == 1)
        {
            if(kkm_bill_print(ID) == 0)
            {
                // ������ ������ ����
                SQL_iniUpdate(NULL,"Bills",ID);
                SQL_exeUpdate("KKM",1);
            }
        }

        Close();
    }
}
//---------------------------------------------------------------------------
void __fastcall TKassaForm::FormShow(TObject *Sender)
{
    if(!ClientID) Close();

    if(!InTransaction)
    {
        SQL_BeginTransaction();
        SQL_exe(DBName,("delete from BillItems where BillID="+AnsiString(KassaBillID)).c_str());
        SQL_CommitTransaction();
    }
    // ���������������� SessionBillID, -1, -2 ...?


    KassaWidths = new int[sgKassa->ColCount];

    sgKassa->ColWidths[0] = KassaWidths[0] = 140;
    sgKassa->ColWidths[1] = KassaWidths[1] = 220;
    sgKassa->ColWidths[2] = KassaWidths[2] = 100;
    sgKassa->ColWidths[3] = KassaWidths[3] = 60;
    sgKassa->ColWidths[4] = KassaWidths[4] = 100;

    sgKassa->ColWidths[5] = KassaWidths[5] = sgKassa->ClientWidth - sgKassa->ColWidths[0] - sgKassa->ColWidths[1] - sgKassa->ColWidths[2] - sgKassa->ColWidths[3] - sgKassa->ColWidths[4] - sgKassa->ColCount;

    sgKassa->Cells[0][0] = "��������";
    sgKassa->Cells[1][0] = "�������";
    sgKassa->Cells[2][0] = "����";
    sgKassa->Cells[3][0] = "���-��";

    sgKassa->Cells[4][0] = "������";
    sgKassa->Cells[5][0] = "����";

    sgOWindowProc = sgKassa->WindowProc;
    sgKassa->WindowProc = sgWindowProc;

    if(UserGrants[12] != '0')
    {
        //spbTerminal->Visible = false;
        spbPayment->Visible = true;

    }

    if(KKM_LINK != -1 || KKM_USE != 1)
        tbBilling->Enabled = false;
    //UserDiscount = (argv[12])? atof(argv[12]) : 0.0;
    //UserDiscountSPA = (argv[13])? atof(argv[13]) : 0.0;
    double x;

    if(UserDiscount > 0.0)
    {
        if(UserDiscountSPA > 0.0)
        {
            // ����� ������

            if(modf(UserDiscount,&x) != 0.0)
                laDiscount->Caption = "����� ������ " + FormatFloat(MoneyFormat,UserDiscount) + "%";
            else
                laDiscount->Caption = "����� ������ " + (AnsiString)((unsigned)UserDiscount) + "%";
        }
        else
        {
            if(modf(UserDiscount,&x) != 0.0)
                laDiscount->Caption = "������ ������� " + FormatFloat(MoneyFormat,UserDiscount) + "%";
            else
                laDiscount->Caption = "������ ������� " + (AnsiString)((unsigned)UserDiscount) + "%";
        }
    }
    else if(UserDiscountSPA > 0.0)
    {
        if(modf(UserDiscountSPA,&x) != 0.0)
            laDiscount->Caption = "������ ��� " + FormatFloat(MoneyFormat,UserDiscountSPA) + "%";
        else
            laDiscount->Caption = "������ ��� " + (AnsiString)((unsigned)UserDiscountSPA) + "%";
    }
    else
    {
        laDiscount->Caption = "��� ������";
    }

    SQL_exefun(DBName,"select count(*) from Stars",&retString);

    pUsers = new AnsiString[atoi(retString.c_str()) + 1];
    if(!pUsers) Close();
    pUserIDs = new __int64[atoi(retString.c_str()) + 1];
    if(!pUserIDs) Close();
    UsersCounter = 1;
    pUsers[0] = "admin";
    pUserIDs[0] = 0;
    SQL_exe(DBName,"select RowID,StarsUser from Stars",users_select);

    if(!Counter)
        IDs.Length = DYN_LENGTH;
    //Counter = 0;



    /*
    if(BillsID != 0)
    {
        tbSave->Visible = false;
        //tbBAdd->Visible = false;
        tbAbAdd->Visible = false;
        //tbGAdd->Visible = false;
        //tbSAdd->Visible = false;
        //tbDel->Visible = false;
        //tbEdit->Visible = false;
        //tbCancel->Visible = false;
        tbD1->Visible = false;
        tbD2->Visible = false;
        //tbD3->Visible = false;

        sbBalanseUp->Visible = false;
        sbGetSumUp->Visible = false;

        edGetSum->Enabled = false;
        edTerminal->Enabled = false;
        edToBalanse->Enabled = false;
        edFromBalanse->Enabled = false;

        ToolBar1->Visible = false;
        SQL_BeginTransaction();
        SQL_exe(DBName,("select CDate,CUID,EDate,EUID,BegBalanse,FromBalanse,ToBalanse,EndBalanse,GetSum,Change,Total from Bills where RowID="+(AnsiString)BillsID).c_str(),bills_select);
        SQL_CancelTransaction();
        edFromBalanse->Text = FormatFloat(MoneyFormat,FromBalanse).TrimLeft();
        edToBalanse->Text = FormatFloat(MoneyFormat,ToBalanse).TrimLeft();
        laEndBalanse->Caption = FormatFloat(MoneyFormat,EndBalanse).TrimLeft();
        edGetSum->Text = FormatFloat(MoneyFormat,GetSum).TrimLeft();
        laChange->Caption = FormatFloat(MoneyFormat,Change).TrimLeft();

        laTotal->Caption = "�����: " + FormatFloat(MoneyFormat,Total).TrimLeft();
    }
    else*/
    {
        BegBalanse = UserBalanse;
        FromBalanse = 0.0;
        ToBalanse = 0.0;
        EndBalanse = BegBalanse;
        GetSum = 0.0;
        Terminal = 0.0;
        Change = 0.0;
        if(!Counter)
            Total = 0.0;

        KassaUpdateInfo();
    }

    laBegBalanse->Caption = "������: " + FormatFloat(MoneyFormat,BegBalanse).TrimLeft();

    FormResult = 0;
    //sgKassa->SetFocus();

    if(!ResServiceID || !ResPersonID || (double)ResBegDate == 0.0 || (double)ResEndDate == 0.0) return;
    else
    {
        // ����������...

        // ����� ������, ����� ������ ����
        SQL_exefun(DBName,("select Tag from Services where RowID="+AnsiString(ResServiceID)).c_str(),&retString);

        retString = (retString);
        char *ps = retString.c_str() + 1;
        if(!*ps) return;
        char *pe = strchr(ps,'~');
        if(!pe) return;

        retString = retString.SubString(2,pe-ps);

        if(retString == "����")
        {
            // ���, ����
            Button2->Click();
        }
        else if(retString == "��������������")
        {
            Button3->Click();
        }
        else if(retString == "�������� ������")
        {
            Button4->Click();
        }
        else if(retString == "SPA")
        {
            tbSPAVisit->Click();

        }

    }


}
//---------------------------------------------------------------------------
void __fastcall TKassaForm::edInputSave(void)
{
    double price;
    //ToBalanse = strtof(laToBalanse->Caption.c_str());

    if(edInputCol == 2)
    {
        price = strtof(edInput->Text.c_str());
        if(price < 0) return;
        if(sgKassa->Cells[0][sgKassa->Row] == "���������� �������")
            ToBalanse += price;
        //laToBalanse->Caption = FormatFloat(MoneyFormat,ToBalanse).TrimLeft();
    }
    else
        price = strtof(sgKassa->Cells[2][sgKassa->Row].c_str());

    int count;
    if(edInputCol == 3)
    {
        // ���-��
        count = atoi(edInput->Text.c_str());

        SQL_exefun(DBName,("select GoodID from BillItems where RowID="+AnsiString(IDs[sgKassa->Row-1])).c_str(),&retString);

        __int64 ID = _atoi64(retString.c_str());
        int i;

        for(i = 0; i < GoodsCount; i++)
            if(arMaxCount[i].GoodID == ID) break;

        if(i < GoodsCount)
        {
            if(count > arMaxCount[i].MaxCount)
                count = arMaxCount[i].MaxCount;
        }

        if(count < 0) return;
        Total -= price * atoi(sgKassa->Cells[3][sgKassa->Row].c_str());
    }
    else
        count = atoi(sgKassa->Cells[3][sgKassa->Row].c_str());

    double total = price * count;

    Total += total;

    SQL_iniUpdate(DBName,"BillItems",IDs[sgKassa->Row-1]);
    if(edInputCol == 2)
        SQL_addUpdate("Price",price);
    if(edInputCol == 3)
        SQL_addUpdate("BillItemsCount",count);
    SQL_exeUpdate("Total",total);

    sgKassa->Cells[2][sgKassa->Row] = FormatFloat(MoneyFormat,price).TrimLeft();
    sgKassa->Cells[3][sgKassa->Row] = count;
    sgKassa->Cells[5][sgKassa->Row] = FormatFloat(MoneyFormat,total).TrimLeft();

    KassaUpdateInfo();
}
//---------------------------------------------------------------------------
void __fastcall TKassaForm::tbBAddClick(TObject *Sender)
{
    // ���������� �������
    edInput->Visible = false;

    __int64 ID;

    SQL_iniInsert(DBName,"BillItems",&ID);
    SQL_exeInsert("Op",SELLOP_ADDBALANSE);
    KassaOps |= SELLOP_ADDBALANSE;

    if((int)Counter >= IDs.Length)
        IDs.Length = IDs.Length + 10;
    IDs[Counter++] = ID;

    if(Counter > 1)
        sgKassa->RowCount++;

    sgKassa->Row = sgKassa->RowCount - 1;

    sgKassa->Cells[0][sgKassa->Row] = "���������� �������";
    sgKassa->Cells[1][sgKassa->Row] = "";
    sgKassa->Cells[2][sgKassa->Row] = "0.00";
    sgKassa->Cells[3][sgKassa->Row] = "1";
    sgKassa->Cells[4][sgKassa->Row] = "0.00";
    sgKassa->Cells[5][sgKassa->Row] = "0.00";

    //double getsum = strtof(edGetSum->Text.c_str());

    TRect rect = sgKassa->CellRect(2,sgKassa->Row);
    edInput->Left = rect.Left + 2;
    edInput->Top = rect.Top + Panel2->Top + 2;
    edInput->Width = rect.Width() + 1;
    edInput->Height = rect.Height();
    edInput->Text = sgKassa->Cells[2][sgKassa->Row];

    edInput->Visible = true;
    //edInput->Enabled = true;
    edInputCol = 2;
    edInput->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TKassaForm::sgKassaDrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
    if(State.Contains(gdFixed))
    {
        sgKassa->Canvas->Font->Style = TFontStyles() << fsBold;
        sgKassa->Canvas->Font->Color = HEADER_COLOR;

        int lft = Rect.Width() - sgKassa->Canvas->TextWidth(sgKassa->Cells[ACol][0]);
        if(lft < 2) lft = 2;
        else lft >>= 1;
        sgKassa->Canvas->TextRect(Rect,Rect.left+lft,Rect.top+1,sgKassa->Cells[ACol][0]);
    }
    else
    {
        if(State.Contains(gdSelected))
        {
            sgKassa->Canvas->Brush->Color = SelColor;
            //SEL_COLOR;
            sgKassa->Canvas->FillRect(Rect);
        }
        else
        {
            sgKassa->Canvas->Brush->Color = clWhite;
            sgKassa->Canvas->FillRect(Rect);
        }

        sgKassa->Canvas->Font->Color = clBlack;
        sgAlignTextDraw(sgKassa,ACol,ARow,Rect,fldAlign);
    }
}
//---------------------------------------------------------------------------
void __fastcall TKassaForm::tbSAddClick(TObject *Sender)
{
    // ������
    edInput->Visible = false;

    //ServicesPriceFormMode = 1;
    //ServicesPriceForm = new TServicesPriceForm(this);
    //ServicesPriceForm->ShowModal();
    //delete ServicesPriceForm;
    //ServicesPriceFormMode = 0;

    //if(!ServicesPriceFormRetID) return;
    FormResult = 0;
    iVisitMode = 0;
    iVisitsForm = new TiVisitsForm(this);
    iVisitsForm->ShowModal();
    delete iVisitsForm;

    if(FormResult != 1) return;

    __int64 ID;

    SQL_iniInsert(DBName,"BillItems",&ID);
    SQL_addInsert("ServiceID",VisitServiceID);
    SQL_addInsert("PersonID",VisitPersonID);
    SQL_addInsert("BillItemsDate",(int)Now());
    SQL_addInsert("BegTime",VisitBegTime);
    SQL_addInsert("EndTime",VisitEndTime);

    SQL_exeInsert("Op",SELLOP_SERVICE);
    KassaOps |= SELLOP_SERVICE;

    if((int)Counter >= IDs.Length)
        IDs.Length = IDs.Length + 10;
    IDs[Counter++] = ID;

    if(Counter > 1)
        sgKassa->RowCount++;

    sgKassa->Row = sgKassa->RowCount - 1;

    sgKassa->Cells[0][sgKassa->Row] = "������";
    sgKassa->Cells[1][sgKassa->Row] = VisitServiceName;
    sgKassa->Cells[2][sgKassa->Row] = "0.00";
    sgKassa->Cells[3][sgKassa->Row] = "1";
    sgKassa->Cells[4][sgKassa->Row] = "0.00";
    sgKassa->Cells[5][sgKassa->Row] = "0.00";

    //Total += price;

    KassaUpdateInfo();

    TRect rect = sgKassa->CellRect(2,sgKassa->Row);
    edInput->Left = rect.Left + 2;
    edInput->Top = rect.Top + Panel2->Top + 2;
    edInput->Width = rect.Width() + 1;
    edInput->Height = rect.Height();
    edInput->Text = sgKassa->Cells[2][sgKassa->Row];

    edInput->Visible = true;
    //edInput->Enabled = true;
    edInputCol = 2;
    edInput->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TKassaForm::edInputExit(TObject *Sender)
{
    edInput->Visible = false;
    //edInput->Enabled = false;

    if(edInputCol > 0)
        edInputSave();
}
//---------------------------------------------------------------------------
void __fastcall TKassaForm::edInputKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key == VK_ESCAPE)
    {
        edInputCol = 0;
        sgKassa->SetFocus();
    }
    else if(Key == VK_RETURN)
        sgKassa->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TKassaForm::edGetSumKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key == VK_RETURN)
    {
        GetSum = ATOF(edGetSum->Text.c_str());

        KassaUpdateInfo();
    }
}
//---------------------------------------------------------------------------
void __fastcall TKassaForm::edGetSumKeyPress(TObject *Sender, char &Key)
{
    ud_keyfilter(Key);
}
//---------------------------------------------------------------------------
void __fastcall TKassaForm::tbCancel0Click(TObject *Sender)
{
    edInput->Visible = false;

    SQL_BeginTransaction();
    SQL_exe(DBName,("delete from BillItems where BillID="+AnsiString(KassaBillID)).c_str());
    SQL_CommitTransaction();

    sgKassa->RowCount = 2;
    sgKassa->Cells[0][1] = "";
    sgKassa->Cells[1][1] = "";
    sgKassa->Cells[2][1] = "";
    sgKassa->Cells[3][1] = "";
    sgKassa->Cells[4][1] = "";
    sgKassa->Cells[5][1] = "";
    sgKassa->Row = 1;

    Counter = 0;
    Total = 0.0;
    BegBalanse = UserBalanse;
    //BalanseChange = 0.0;
    edGetSum->Text = "0.00";
    edTerminal->Text = "0.00";

    laTotal->Caption = "�����: " + FormatFloat(MoneyFormat,Total).TrimLeft();
    laBegBalanse->Caption = "������: " + FormatFloat(MoneyFormat,BegBalanse).TrimLeft();
    laChange->Caption = "�����: 0.00";
    sgKassa->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TKassaForm::edInputKeyPress(TObject *Sender, char &Key)
{
    ui_keyfilter(Key);
}
//---------------------------------------------------------------------------
void __fastcall TKassaForm::edGetSumExit(TObject *Sender)
{
    GetSum = ATOF(edGetSum->Text.c_str());

    KassaUpdateInfo();
}
//---------------------------------------------------------------------------
void __fastcall TKassaForm::edFromBalanseExit(TObject *Sender)
{
    FromBalanse = strtof(edFromBalanse->Text.c_str());

    KassaUpdateInfo();
}
//---------------------------------------------------------------------------
void __fastcall TKassaForm::edFromBalanseKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
    if(Key == VK_RETURN)
    {
        FromBalanse = strtof(edFromBalanse->Text.c_str());
    
        KassaUpdateInfo();
    }
}
//---------------------------------------------------------------------------
void __fastcall TKassaForm::sbBalanseUpClick(TObject *Sender)
{
    // ������� � �������
    edInput->Visible = false;

    GetSum = ATOF(edGetSum->Text.c_str());
    Terminal = ATOF(edTerminal->Text.c_str());
    //ToBalanse = ATOF(edToBalanse->Text.c_str());

    FromBalanse = Total - GetSum - Terminal;

    if(FromBalanse < 0) FromBalanse = 0;
    else if(FromBalanse > UserBalanse)
        FromBalanse = UserBalanse;

    KassaUpdateInfo();
}
//---------------------------------------------------------------------------
void __fastcall TKassaForm::sbGetSumUpClick(TObject *Sender)
{
    // ������� � ��������
    edInput->Visible = false;

    FromBalanse = ATOF(edFromBalanse->Text.c_str());
    ToBalanse = ATOF(edToBalanse->Text.c_str());
    GetSum = ATOF(edGetSum->Text.c_str());
    Terminal = ATOF(edTerminal->Text.c_str());

    GetSum = Total - Terminal - FromBalanse + ToBalanse;
    if(GetSum < 0) GetSum = 0;

    KassaUpdateInfo();
}
//---------------------------------------------------------------------------
void __fastcall TKassaForm::tbDelClick(TObject *Sender)
{
    // ������� ������� �� ����
    if(sgKassa->Row > 0 && Counter > 0)
    {
        //__int64 ID = IDs[sgKassa->Row-1];
        edInput->Visible = false;

        SQL_BeginTransaction();
        SQL_exefun(DBName,("delete from BillItems where RowID=" + (AnsiString)IDs[sgKassa->Row-1]).c_str());
        SQL_CommitTransaction();

        for(unsigned i = sgKassa->Row; i < Counter; i++)
        {
            IDs[i-1] = IDs[i];
            sgKassa->Rows[i] = sgKassa->Rows[i+1];
        }


        if(Counter > 1)
            sgKassa->RowCount--;
        else
        {
            sgKassa->Cells[0][1] = "";
            sgKassa->Cells[1][1] = "";
            sgKassa->Cells[2][1] = "";
            sgKassa->Cells[3][1] = "";
            sgKassa->Cells[4][1] = "";
            sgKassa->Cells[5][1] = "";
        }
        Counter--;

        //BegBalanse = UserBalanse;
        //FromBalanse = 0.0;
        ToBalanse = 0.0;
        //EndBalanse = BegBalanse;
        //GetSum = 0.0;
        //Change = 0.0;
        Total = 0.0;

        SQL_exe(DBName,("select Op,Price,BillItemsCount from BillItems where BillID="+AnsiString(KassaBillID)).c_str(),billitems_reload);

        KassaUpdateInfo();
    }
}
//---------------------------------------------------------------------------
void __fastcall TKassaForm::tbEditClick(TObject *Sender)
{
    //return;
    // ������������� ���-�� ��� ������
    if(sgKassa->Row > 0 && Counter > 0)
    {
        SQL_exefun(DBName,("select GoodID from BillItems where RowID="+AnsiString(IDs[sgKassa->Row-1])).c_str(),&retString);
        if(_atoi64(retString.c_str()) == 0) return;

        edInput->Visible = false;

        //SQL_exefun(DBName,("select Op from BillItems where RowID=" + (AnsiString)IDs[sgKassa->Row-1]).c_str(),&retString);
        //int op = atoi(retString.c_str());
        //if(op == SELLOP_ABONEMENT || op == SELLOP_ABONEMENT_SPA) return;
        //edInputCol = (op == SELLOP_ADDBALANSE || op == SELLOP_SERVICE)? 2 : 3;
        edInputCol = 3;

        TRect rect = sgKassa->CellRect(edInputCol,sgKassa->Row);
        edInput->Left = rect.Left + 2;
        edInput->Top = rect.Top + Panel2->Top + 2;
        edInput->Width = rect.Width() + 1;
        edInput->Height = rect.Height();
        edInput->Text = sgKassa->Cells[edInputCol][sgKassa->Row];

        edInput->Visible = true;

        edInput->SetFocus();
    }
}
//---------------------------------------------------------------------------
void __fastcall TKassaForm::edToBalanseExit(TObject *Sender)
{
    ToBalanse = strtof(edToBalanse->Text.c_str());

    KassaUpdateInfo();
}
//---------------------------------------------------------------------------
void __fastcall TKassaForm::edToBalanseKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key == VK_RETURN)
    {
        ToBalanse = strtof(edToBalanse->Text.c_str());

        KassaUpdateInfo();
    }
}
//---------------------------------------------------------------------------
void __fastcall TKassaForm::edToBalanseKeyPress(TObject *Sender, char &Key)
{
    if(NegBalanseFlag)
        d_keyfilter(Key);
    else
        ud_keyfilter(Key);
}
//---------------------------------------------------------------------------
void __fastcall TKassaForm::edFromBalanseKeyPress(TObject *Sender,
      char &Key)
{
    if(NegBalanseFlag)
        d_keyfilter(Key);
    else
        ud_keyfilter(Key);
}
//---------------------------------------------------------------------------
void __fastcall TKassaForm::spbPaymentClick(TObject *Sender)
{
    if(spbPayment->Caption == "���.")
        spbPayment->Caption = "�/�";
    else
        spbPayment->Caption = "���.";
}
//---------------------------------------------------------------------------
void __fastcall TKassaForm::tbAbSPAAddClick(TObject *Sender)
{
    // �������� ��������� SPA
    // ���� ��������� ��� ���� - �������� ������� �� ������?
    edInput->Visible = false;

    SQL_exefun(DBName,("select count(*) from BillItems where BillID="+AnsiString(KassaBillID)+" and AbTypeID="+AnsiString(SELLOP_ABONEMENT_SPA)).c_str(),&retString);
    unsigned abcnt = atoi(retString.c_str());

    if(abcnt > 0)
    {
        Application->MessageBox("��������!\n����� ������� ������ ���� ��������� �� SPA.","������������ ��������",MB_OK);
        return;
    }

    double price;
    //__int64 PID;
    //__int64 SID;

    AbParamForm = new TAbParamForm(this);
    AbParamForm->Tag = "SPA";
    //AbParamForm->edBalanse->Visible = true;
    //AbParamForm->laBalanse->Visible = true;
    AbParamForm->ShowModal();

    if(FormResult == 1)
    {
        //PID = AbParamForm->AbParamPID;
        //SID = AbParamForm->AbParamSID;
        price = AbParamForm->Balanse;
    }

    delete AbParamForm;

    if(FormResult != 1)
    {
        FormResult = 0;
        return;
    }

    FormResult = 0;

    __int64 ID;
    double total = price;

    SQL_iniInsert(DBName,"BillItems",&ID);
    SQL_addInsert("BillID",KassaBillID);
    //SQL_addInsert("AbTypeID",AbTypesFormRetID);
    //SQL_addInsert("PersonID",PID);
    //SQL_addInsert("ServiceID",SID);
    SQL_addInsert("Price",price);
    SQL_addInsert("BillItemsCount",1);

    double discount = 0.0;
    if(price >= 4000.0 && price < 5501.0)
        discount = 7.0;
    else if(price >= 5501.0 && price < 7000)
        discount = 10.0;
    else if(price >= 7000.0) discount = 13.0;

    //SQL_addInsert("#Name","������ "+AnsiString(discount)+"%");
    SQL_addInsert("Discount",discount);
    SQL_addInsert("Total",total);

    SQL_exeInsert("Op",SELLOP_ABONEMENT_SPA);
    KassaOps |= SELLOP_ABONEMENT_SPA;

    if((int)Counter >= IDs.Length)
        IDs.Length = IDs.Length + 10;
    IDs[Counter++] = ID;

    if(Counter > 1)
        sgKassa->RowCount++;

    sgKassa->Row = sgKassa->RowCount - 1;

    sgKassa->Cells[0][sgKassa->Row] = "��������� �� SPA";
    sgKassa->Cells[1][sgKassa->Row] = "������ "+AnsiString(discount)+"%";
    sgKassa->Cells[2][sgKassa->Row] = FormatFloat(MoneyFormat,price).TrimLeft();
    sgKassa->Cells[3][sgKassa->Row] = "1";
    sgKassa->Cells[4][sgKassa->Row] = "";
    sgKassa->Cells[5][sgKassa->Row] = FormatFloat(MoneyFormat,total).TrimLeft();

    Total += total;

    KassaUpdateInfo();
}
//---------------------------------------------------------------------------
void __fastcall TKassaForm::tbSPAVisitClick(TObject *Sender)
{
    // ��������� ���

    // ������
    edInput->Visible = false;

    FormResult = 0;
    iVisitMode = 0;

    iVisitsForm = new TiVisitsForm(this);
    iVisitsForm->Tag = "SPA";

    iVisitsForm->ResBegDate = ResBegDate;
    iVisitsForm->ResEndDate = ResEndDate;

    iVisitsForm->ResServiceID = ResServiceID;
    iVisitsForm->ResPersonID = ResPersonID;

    iVisitsForm->ShowModal();
    double pprice = iVisitsForm->PersonPrice;
    __int64 VID = iVisitsForm->VisitID;
    delete iVisitsForm;

    if(FormResult != 1) return;

    __int64 ID;

    //SQL_exefun(DBName,("select Price from Services where RowID="+AnsiString(VisitServiceID)).c_str(),&retString);
    //double price = atof(retString.c_str());
    double price = VisitPrice;
    // ���� ������?
    //SQL_exefun(DBName,("select Discount from Abonements_SPA where Closed=0 and ClientID="+AnsiString(ClientID)).c_str(),&retString);
    double total, discount;
    // = atof(retString.c_str());
    //if(UserDiscountSPA > discount)
    discount = UserDiscountSPA;
    total = price;
    //total = (price * (100.0 - discount)) / 100.0;

    SQL_iniInsert(DBName,"BillItems",&ID);
    SQL_addInsert("BillID",KassaBillID);
    SQL_addInsert("ServiceID",VisitServiceID);
    SQL_addInsert("PersonID",VisitPersonID);
    SQL_addInsert("BillItemsDate",(int)Now());
    SQL_addInsert("BegTime",VisitBegTime);
    SQL_addInsert("EndTime",VisitEndTime);

    SQL_addInsert("Price",price);
    SQL_addInsert("PersonPrice",pprice);
    SQL_addInsert("BillItemsCount",1);

    SQL_addInsert("Discount",discount);
    SQL_addInsert("Total",total);

    SQL_addInsert("VisitID",VID);

    SQL_exeInsert("Op",SELLOP_SPA_VISIT);
    KassaOps |= SELLOP_SPA_VISIT;

    if((int)Counter >= IDs.Length)
        IDs.Length = IDs.Length + 10;
    IDs[Counter++] = ID;

    if(Counter > 1)
        sgKassa->RowCount++;

    sgKassa->Row = sgKassa->RowCount - 1;

    sgKassa->Cells[0][sgKassa->Row] = "������ SPA";
    sgKassa->Cells[1][sgKassa->Row] = VisitServiceName;
    sgKassa->Cells[2][sgKassa->Row] = FormatFloat(MoneyFormat,price).TrimLeft();
    sgKassa->Cells[3][sgKassa->Row] = "1";

    double x;
    if(modf(discount,&x) != 0.0)
        sgKassa->Cells[4][sgKassa->Row] = FormatFloat(MoneyFormat,discount).TrimLeft()+"%";
    else
        sgKassa->Cells[4][sgKassa->Row] = (AnsiString)(int)discount+"%";

    sgKassa->Cells[5][sgKassa->Row] = FormatFloat(MoneyFormat,total).TrimLeft();

    Total += total;

    KassaUpdateInfo();
}
//---------------------------------------------------------------------------
void __fastcall TKassaForm::Button1Click(TObject *Sender)
{
    // �����

    edInput->Visible = false;

    FormResult = 0;

    GoodsForm = new TGoodsForm(this);
    GoodsForm->ShowModal();

    if(FormResult == 1)
    {


        __int64 ID, GoodID = GoodsForm->SelID;
        double total, price = GoodsForm->SelPrice;
        //MaxCount = GoodsForm->SelCount;
        AnsiString Name = GoodsForm->SelName;
        AnsiString Section = GoodsForm->SelSection;
        AnsiString sCount;
        int count = 1;

        SQL_exefun2(DBName,("select RowID,BillItemsCount from BillItems where BillID="+AnsiString(KassaBillID)+" and GoodID="+AnsiString(GoodID)).c_str(),&retString,&sCount);
        ID = _atoi64(retString.c_str());

        if(ID)
        {
            count += atoi(sCount.c_str());
            total = price;

            SQL_iniUpdate(DBName,"BillItems",ID);
            SQL_addUpdate("Total",total);
            SQL_exeUpdate("BillItemsCount",count);

            unsigned i;

            for(i = 0; i < Counter; i++)
                if(ID == IDs[i]) break;

            sgKassa->Row = i + 1;

            sgKassa->Cells[3][sgKassa->Row] = count;
            sgKassa->Cells[5][sgKassa->Row] = FormatFloat(MoneyFormat,total).TrimLeft();
        }
        else
        {
            if(arMaxCount.Length <= GoodsCount)
                arMaxCount.Length += 4;

            arMaxCount[GoodsCount].GoodID = GoodID;
            arMaxCount[GoodsCount++].MaxCount = GoodsForm->SelCount;

            total = price;

            SQL_iniInsert(DBName,"BillItems",&ID);
            SQL_addInsert("BillID",KassaBillID);
            SQL_addInsert("BillItemsDate",(int)Now());
            SQL_addInsert("GoodID",GoodID);
            SQL_addInsert("Price",price);
            SQL_addInsert("BillItemsCount",1);
            SQL_addInsert("Total",price);
            SQL_exeInsert("Op",SELLOP_GOOD);
            KassaOps |= SELLOP_GOOD;

            if((int)Counter >= IDs.Length)
                IDs.Length = IDs.Length + 10;
            IDs[Counter++] = ID;

            if(Counter > 1)
                sgKassa->RowCount++;

            sgKassa->Row = sgKassa->RowCount - 1;

            sgKassa->Cells[0][sgKassa->Row] = Section;
            sgKassa->Cells[1][sgKassa->Row] = Name;
            sgKassa->Cells[2][sgKassa->Row] = FormatFloat(MoneyFormat,price).TrimLeft();
            sgKassa->Cells[3][sgKassa->Row] = "1";
            sgKassa->Cells[4][sgKassa->Row] = "";
            sgKassa->Cells[5][sgKassa->Row] = FormatFloat(MoneyFormat,price).TrimLeft();
        }

        Total += total;

        KassaUpdateInfo();

        TRect rect = sgKassa->CellRect(3,sgKassa->Row);
        edInput->Left = rect.Left + 2;
        edInput->Top = rect.Top + Panel2->Top + 2;
        edInput->Width = rect.Width() + 1;
        edInput->Height = rect.Height();
        edInput->Text = sgKassa->Cells[3][sgKassa->Row];

        edInput->Visible = true;

        edInputCol = 3;
        edInput->SetFocus();
    }

    delete GoodsForm;
}
//---------------------------------------------------------------------------
void __fastcall TKassaForm::Button2Click(TObject *Sender)
{
    // ����
    edInput->Visible = false;

    //if(sgKassa->Cells[0][1].Length() > 0 && sgKassa->Cells[0][1] != "������ ������")
    //{
    //    Application->MessageBox("��������!\n������ ������� ��������� ������ ��������� �������.","",MB_OK);
    //    return;
    //}

    FormResult = 0;
    iVisitMode = 0;
    BathForm = new TBathForm(this);

    BathForm->ResBegDate = ResBegDate;
    BathForm->ResEndDate = ResEndDate;

    BathForm->ResServiceID = ResServiceID;
    BathForm->ResPersonID = ResPersonID;

    BathForm->ResQuan = ResQuan;

    BathForm->ShowModal();

    //double pprice = BathForm->PersonPrice;
    int group_cnt = BathForm->seGroupCnt->Value;
    double pprice = BathForm->PersonPrice;
    __int64 VID = BathForm->VisitID;
    delete BathForm;

    if(FormResult != 1) return;

    __int64 ID;

    double price = VisitPrice;
    double total;
    
    total = price;

    SQL_iniInsert(DBName,"BillItems",&ID);
    SQL_addInsert("BillID",KassaBillID);
    SQL_addInsert("ServiceID",VisitServiceID);
    SQL_addInsert("PersonID",VisitPersonID);
    SQL_addInsert("BillItemsDate",(int)Now());
    SQL_addInsert("BegTime",VisitBegTime);
    SQL_addInsert("EndTime",VisitEndTime);

    SQL_addInsert("Price",price);
    SQL_addInsert("PersonPrice",pprice);
    SQL_addInsert("BillItemsCount",group_cnt);

    SQL_addInsert("Discount",UserDiscountSPA);
    SQL_addInsert("Total",total);

    SQL_addInsert("VisitID",VID);

    SQL_exeInsert("Op",SELLOP_BATH);
    KassaOps |= SELLOP_BATH;

    if((int)Counter >= IDs.Length)
        IDs.Length = IDs.Length + 10;
    IDs[Counter++] = ID;

    if(Counter > 1)
        sgKassa->RowCount++;

    sgKassa->Row = sgKassa->RowCount - 1;

    sgKassa->Cells[0][sgKassa->Row] = "������ ������";
    sgKassa->Cells[1][sgKassa->Row] = VisitServiceName;
    sgKassa->Cells[2][sgKassa->Row] = FormatFloat(MoneyFormat,price).TrimLeft();
    sgKassa->Cells[3][sgKassa->Row] = group_cnt;

    double x;
    if(modf(UserDiscountSPA,&x) != 0.0)
        sgKassa->Cells[4][sgKassa->Row] = FormatFloat(MoneyFormat,UserDiscountSPA).TrimLeft()+"%";
    else
        sgKassa->Cells[4][sgKassa->Row] = (AnsiString)(int)UserDiscountSPA+"%";

    sgKassa->Cells[5][sgKassa->Row] = FormatFloat(MoneyFormat,total).TrimLeft();

    Total += total;

    KassaUpdateInfo();
}
//---------------------------------------------------------------------------
void __fastcall TKassaForm::edToBalanseChange(TObject *Sender)
{
    KassaOps |= SELLOP_ADDBALANSE;
}
//---------------------------------------------------------------------------
void __fastcall TKassaForm::edFromBalanseChange(TObject *Sender)
{
    KassaOps |= SELLOP_ADDBALANSE;
}
//---------------------------------------------------------------------------
void __fastcall TKassaForm::tbAbAddClick(TObject *Sender)
{
    // �������� ���������
    edInput->Visible = false;

    SQL_exefun(DBName,("select count(*) from BillItems where BillID="+AnsiString(KassaBillID)+" and AbTypeID="+AnsiString(SELLOP_ABONEMENT)).c_str(),&retString);
    unsigned abcnt = atoi(retString.c_str());

    if(abcnt > 0)
    {
        Application->MessageBox("��������!\n����� ������� ������ ���� ��������� �� �������.","������������ ��������",MB_OK);
        return;
    }

    AbTypesFormMode = 1;
    AbTypesForm = new TAbTypesForm(this);
    AbTypesForm->ShowModal();
    delete AbTypesForm;

    AbTypesFormMode = 0;

    if(FormResult != 1 || !AbTypesFormRetID)
    {
        FormResult = 0;
        return;
    }

    FormResult = 0;

    __int64 ID;

    // AbTypesFormRet1 - Name
    // AbTypesFormRet2 - Price
    double price = ATOF(AbTypesFormRet2.c_str());
    //double fixsum = atof(AbTypesFormRet3.c_str());
    //double total;

    if(UserDiscount != 0)
        price = (price * (100.0 - UserDiscount))/ 100.0;

    //else
    //    total = price;

    double total = price;

    if(AbTypesFormRetID != 25 && AbTypesFormRetID != 50 && AbTypesFormRetID != 26)
    {

        SQL_exefun(NULL,("select count(*) from Abonements where Closed=0 and AbTypeID in (25,50) and ClientID="+AnsiString(ClientID)).c_str(),&retString);
        if(ATOI(retString.c_str()) > 0)
        {
            if(Application->MessageBox("��������!\n������������ ������� ���������� ���������� ��������� �� �������.\n����������?","",MB_OKCANCEL) == 2)
                return;
        }
    }
    
    SQL_iniInsert(DBName,"BillItems",&ID);
    SQL_addInsert("BillID",KassaBillID);
    SQL_addInsert("AbTypeID",AbTypesFormRetID);
    SQL_addInsert("PersonID",AbTypesFormRet3);
    SQL_addInsert("ServiceID",AbTypesFormRet4);
    SQL_addInsert("Price",price);
    //SQL_addInsert("FixSum",fixsum);
    SQL_addInsert("BillItemsCount",1);
    SQL_addInsert("Discount",UserDiscount);
    SQL_addInsert("Total",total);

    SQL_exeInsert("Op",SELLOP_ABONEMENT);
    KassaOps |= SELLOP_ABONEMENT;

    if((int)Counter >= IDs.Length)
        IDs.Length = IDs.Length + 10;
    IDs[Counter++] = ID;

    if(Counter > 1)
        sgKassa->RowCount++;

    sgKassa->Row = sgKassa->RowCount - 1;

    sgKassa->Cells[0][sgKassa->Row] = "��������� �� �������";
    sgKassa->Cells[1][sgKassa->Row] = AbTypesFormRet1;
    sgKassa->Cells[2][sgKassa->Row] = FormatFloat(MoneyFormat,price).TrimLeft();
    sgKassa->Cells[3][sgKassa->Row] = "1";

    double x;
    if(modf(UserDiscount,&x) != 0.0)
        sgKassa->Cells[4][sgKassa->Row] = FormatFloat(MoneyFormat,UserDiscount).TrimLeft()+"%";
    else
        sgKassa->Cells[4][sgKassa->Row] = (AnsiString)(int)UserDiscount+"%";

    //sgKassa->Cells[4][sgKassa->Row] = FormatFloat(MoneyFormat,UserDiscount).TrimLeft();
    sgKassa->Cells[5][sgKassa->Row] = FormatFloat(MoneyFormat,total).TrimLeft();

    Total += total;

    KassaUpdateInfo();
}
//---------------------------------------------------------------------------
void __fastcall TKassaForm::Button3Click(TObject *Sender)
{
    // ��������������

    edInput->Visible = false;

    FormResult = 0;
    iVisitMode = 0;
    BarberForm = new TBarberForm(this);
    BarberForm->ResBegDate = ResBegDate;
    BarberForm->ResEndDate = ResEndDate;

    BarberForm->ResServiceID = ResServiceID;
    BarberForm->ResPersonID = ResPersonID;
    BarberForm->ShowModal();

    //double pprice = BathForm->PersonPrice;
    int group_cnt = BarberForm->seGroupCnt->Value;
    double pprice = BarberForm->PersonPrice;

    int addop = BarberForm->AddOp;
    int addcnt = BarberForm->AddCount;
    double addprice = BarberForm->AddPrice;
    int addtype = BarberForm->AddType;
    AnsiString sColor;
    if(addop && FormResult == 1)
        sColor = BarberForm->pAddOps[addop-1].lines[addtype-1];
    __int64 VID = BarberForm->VisitID;

    delete BarberForm;

    if(FormResult != 1) return;

    __int64 ID;

    double price = VisitPrice;
    double total = price;

    SQL_iniInsert(DBName,"BillItems",&ID);
    SQL_addInsert("BillID",KassaBillID);
    SQL_addInsert("ServiceID",VisitServiceID);
    SQL_addInsert("PersonID",VisitPersonID);
    SQL_addInsert("BillItemsDate",(int)Now());
    SQL_addInsert("BegTime",VisitBegTime);
    SQL_addInsert("EndTime",VisitEndTime);

    SQL_addInsert("Price",price);
    SQL_addInsert("PersonPrice",pprice);
    SQL_addInsert("BillItemsCount",group_cnt);

    SQL_addInsert("Discount",UserDiscountSPA);
    SQL_addInsert("Total",total);

    SQL_addInsert("VisitID",VID);

    if(addop)
    {
        SQL_BeginTransaction();
        SQL_exeInsert("Op",SELLOP_BARBER);
        SQL_iniInsert(DBName,"AddOp");
        SQL_addInsert("BillItemsID",ID);
        SQL_addInsert("Type",addtype);
        SQL_addInsert("!Name",sColor);
        SQL_addInsert("Price",addprice);
        SQL_exeInsert("AddOpCount",addcnt);
        SQL_CommitTransaction();
    }
    else
        SQL_exeInsert("Op",SELLOP_BARBER);

    KassaOps |= SELLOP_BARBER;

    if((int)Counter >= IDs.Length)
        IDs.Length = IDs.Length + 10;
    IDs[Counter++] = ID;

    if(Counter > 1)
        sgKassa->RowCount++;

    sgKassa->Row = sgKassa->RowCount - 1;

    sgKassa->Cells[0][sgKassa->Row] = "��������������";
    sgKassa->Cells[1][sgKassa->Row] = VisitServiceName;
    sgKassa->Cells[2][sgKassa->Row] = FormatFloat(MoneyFormat,price).TrimLeft();
    sgKassa->Cells[3][sgKassa->Row] = group_cnt;

    double x;
    if(modf(UserDiscountSPA,&x) != 0.0)
        sgKassa->Cells[4][sgKassa->Row] = FormatFloat(MoneyFormat,UserDiscountSPA).TrimLeft()+"%";
    else
        sgKassa->Cells[4][sgKassa->Row] = (AnsiString)(int)UserDiscountSPA+"%";

    sgKassa->Cells[5][sgKassa->Row] = FormatFloat(MoneyFormat,total).TrimLeft();

    Total += total;

    KassaUpdateInfo();
}
//---------------------------------------------------------------------------
void __fastcall TKassaForm::Button4Click(TObject *Sender)
{
    // �����

    edInput->Visible = false;

    FormResult = 0;
    iVisitMode = 0;
    NailForm = new TNailForm(this);

    NailForm->ShowModal();

    //double pprice = BathForm->PersonPrice;
    int group_cnt = NailForm->seGroupCnt->Value;
    double pprice = NailForm->PersonPrice;

    int addop = NailForm->AddOp;
    int addcnt = NailForm->AddCount;
    double addprice = NailForm->AddPrice;
    int addtype = NailForm->AddType;
    __int64 VID = NailForm->VisitID;
    delete NailForm;

    if(FormResult != 1) return;

    __int64 ID;

    double price = VisitPrice;
    double total;
    
    total = price;

    SQL_iniInsert(DBName,"BillItems",&ID);
    SQL_addInsert("BillID",KassaBillID);
    SQL_addInsert("ServiceID",VisitServiceID);
    SQL_addInsert("PersonID",VisitPersonID);
    SQL_addInsert("BillItemsDate",(int)Now());
    SQL_addInsert("BegTime",VisitBegTime);
    SQL_addInsert("EndTime",VisitEndTime);

    SQL_addInsert("Price",price);
    SQL_addInsert("PersonPrice",pprice);
    SQL_addInsert("BillItemsCount",group_cnt);

    SQL_addInsert("Discount",UserDiscountSPA);
    SQL_addInsert("Total",total);

    SQL_addInsert("VisitID",VID);

    if(addop == 1)
    {
        SQL_BeginTransaction();
        SQL_exeInsert("Op",SELLOP_NAIL);
        SQL_iniInsert(DBName,"AddOp");
        SQL_addInsert("BillItemsID",ID);
        SQL_addInsert("Type",addtype);
        if(addtype == 1)
            SQL_addInsert("!Name","Wella");
        else
            SQL_addInsert("!Name","Schwarzkopf");
        SQL_addInsert("Price",addprice);
        SQL_exeInsert("AddOpCount",addcnt);
        SQL_CommitTransaction();
    }
    else
        SQL_exeInsert("Op",SELLOP_NAIL);

    KassaOps |= SELLOP_NAIL;

    if((int)Counter >= IDs.Length)
        IDs.Length = IDs.Length + 10;
    IDs[Counter++] = ID;

    if(Counter > 1)
        sgKassa->RowCount++;

    sgKassa->Row = sgKassa->RowCount - 1;

    sgKassa->Cells[0][sgKassa->Row] = "�������� ������";
    sgKassa->Cells[1][sgKassa->Row] = VisitServiceName;
    sgKassa->Cells[2][sgKassa->Row] = FormatFloat(MoneyFormat,price).TrimLeft();
    sgKassa->Cells[3][sgKassa->Row] = group_cnt;

    double x;
    if(modf(UserDiscountSPA,&x) != 0.0)
        sgKassa->Cells[4][sgKassa->Row] = FormatFloat(MoneyFormat,UserDiscountSPA).TrimLeft()+"%";
    else
        sgKassa->Cells[4][sgKassa->Row] = (AnsiString)(int)UserDiscountSPA+"%";

    sgKassa->Cells[5][sgKassa->Row] = FormatFloat(MoneyFormat,total).TrimLeft();

    Total += total;

    KassaUpdateInfo();
}
//---------------------------------------------------------------------------
void __fastcall TKassaForm::Button5Click(TObject *Sender)
{
    // ������������

    edInput->Visible = false;

    FormResult = 0;
    iVisitMode = 0;
    CosmeticForm = new TCosmeticForm(this);

    CosmeticForm->ShowModal();

    int group_cnt = CosmeticForm->seGroupCnt->Value;
    double pprice = CosmeticForm->PersonPrice;

    int addop = CosmeticForm->AddOp;
    int addcnt = CosmeticForm->AddCount;
    double addprice = CosmeticForm->AddPrice;
    int addtype = CosmeticForm->AddType;
    __int64 VID = CosmeticForm->VisitID;
    delete CosmeticForm;

    if(FormResult != 1) return;

    __int64 ID;

    double price = VisitPrice;
    double total;
    
    total = price;

    SQL_iniInsert(DBName,"BillItems",&ID);
    SQL_addInsert("BillID",KassaBillID);
    SQL_addInsert("ServiceID",VisitServiceID);
    SQL_addInsert("PersonID",VisitPersonID);
    SQL_addInsert("BillItemsDate",(int)Now());
    SQL_addInsert("BegTime",VisitBegTime);
    SQL_addInsert("EndTime",VisitEndTime);

    SQL_addInsert("Price",price);
    SQL_addInsert("PersonPrice",pprice);
    SQL_addInsert("BillItemsCount",group_cnt);

    SQL_addInsert("Discount",UserDiscountSPA);
    SQL_addInsert("Total",total);

    SQL_addInsert("VisitID",VID);

    if(addop == 1)
    {
        SQL_BeginTransaction();
        SQL_exeInsert("Op",SELLOP_COSMETIC);
        SQL_iniInsert(DBName,"AddOp");
        SQL_addInsert("BillItemsID",ID);
        SQL_addInsert("Type",addtype);
        if(addtype == 1)
            SQL_addInsert("!Name","Wella");
        else
            SQL_addInsert("!Name","Schwarzkopf");
        SQL_addInsert("Price",addprice);
        SQL_exeInsert("AddOpCount",addcnt);
        SQL_CommitTransaction();
    }
    else
        SQL_exeInsert("Op",SELLOP_COSMETIC);

    KassaOps |= SELLOP_COSMETIC;

    if((int)Counter >= IDs.Length)
        IDs.Length = IDs.Length + 10;
    IDs[Counter++] = ID;

    if(Counter > 1)
        sgKassa->RowCount++;

    sgKassa->Row = sgKassa->RowCount - 1;

    sgKassa->Cells[0][sgKassa->Row] = "������������";
    sgKassa->Cells[1][sgKassa->Row] = VisitServiceName;
    sgKassa->Cells[2][sgKassa->Row] = FormatFloat(MoneyFormat,price).TrimLeft();
    sgKassa->Cells[3][sgKassa->Row] = group_cnt;

    double x;
    if(modf(UserDiscountSPA,&x) != 0.0)
        sgKassa->Cells[4][sgKassa->Row] = FormatFloat(MoneyFormat,UserDiscountSPA).TrimLeft()+"%";
    else
        sgKassa->Cells[4][sgKassa->Row] = (AnsiString)(int)UserDiscountSPA+"%";

    sgKassa->Cells[5][sgKassa->Row] = FormatFloat(MoneyFormat,total).TrimLeft();

    Total += total;

    KassaUpdateInfo();
}
//---------------------------------------------------------------------------
void __fastcall TKassaForm::Button6Click(TObject *Sender)
{
    // ��������� ����
    // �������� ���������
    edInput->Visible = false;

    SQL_exefun(DBName,("select count(*) from BillItems where BillID="+AnsiString(KassaBillID)+" and AbTypeID="+AnsiString(SELLOP_ABONEMENT_BATH)).c_str(),&retString);
    unsigned abcnt = atoi(retString.c_str());

    if(abcnt > 0)
    {
        Application->MessageBox("��������!\n����� ������� ������ ���� ��������� �� ����.","������������ ��������",MB_OK);
        return;
    }

    AbTypesFormMode = 2; // ������
    AbTypesForm = new TAbTypesForm(this);
    AbTypesForm->ShowModal();
    delete AbTypesForm;

    AbTypesFormMode = 0;

    if(FormResult != 1 || !AbTypesFormRetID)
    {
        FormResult = 0;
        return;
    }

    FormResult = 0;

    __int64 ID;

    // AbTypesFormRet1 - Name
    // AbTypesFormRet2 - Price
    double price = ATOF(AbTypesFormRet2.c_str());

    if(UserDiscount != 0)
        price = (price * (100.0 - UserDiscount))/ 100.0;

    double total = price;

    SQL_iniInsert(DBName,"BillItems",&ID);
    SQL_addInsert("BillID",KassaBillID);
    SQL_addInsert("AbTypeID",AbTypesFormRetID);
    SQL_addInsert("PersonID",AbTypesFormRet3);
    SQL_addInsert("ServiceID",AbTypesFormRet4);
    SQL_addInsert("Price",price);
    //SQL_addInsert("FixSum",fixsum);
    SQL_addInsert("BillItemsCount",1);
    SQL_addInsert("Discount",UserDiscount);
    SQL_addInsert("Total",total);

    SQL_exeInsert("Op",SELLOP_ABONEMENT_BATH);
    KassaOps |= SELLOP_ABONEMENT_BATH;

    if((int)Counter >= IDs.Length)
        IDs.Length = IDs.Length + 10;
    IDs[Counter++] = ID;

    if(Counter > 1)
        sgKassa->RowCount++;

    sgKassa->Row = sgKassa->RowCount - 1;

    sgKassa->Cells[0][sgKassa->Row] = "��������� � ����";
    sgKassa->Cells[1][sgKassa->Row] = AbTypesFormRet1;
    sgKassa->Cells[2][sgKassa->Row] = FormatFloat(MoneyFormat,price).TrimLeft();
    sgKassa->Cells[3][sgKassa->Row] = "1";

    double x;
    if(modf(UserDiscount,&x) != 0.0)
        sgKassa->Cells[4][sgKassa->Row] = FormatFloat(MoneyFormat,UserDiscount).TrimLeft()+"%";
    else
        sgKassa->Cells[4][sgKassa->Row] = (AnsiString)(int)UserDiscount+"%";

    //sgKassa->Cells[4][sgKassa->Row] = FormatFloat(MoneyFormat,UserDiscount).TrimLeft();
    sgKassa->Cells[5][sgKassa->Row] = FormatFloat(MoneyFormat,total).TrimLeft();

    Total += total;

    KassaUpdateInfo();
}
//---------------------------------------------------------------------------
__int64 __fastcall TKassaForm::Billing(void)
{
    // �������
    edInput->Visible = false;
     __int64 ID = 0;

    FromBalanse = ATOF(edFromBalanse->Text.c_str());
    ToBalanse = ATOF(edToBalanse->Text.c_str());
    GetSum = ATOF(edGetSum->Text.c_str());
    Terminal = ATOF(edTerminal->Text.c_str());

    KassaUpdateInfo();


    // �������� ����
    // ������ �/� - ��� ����

    if(spbPayment->Caption == "���.")
    {
        if(Terminal + GetSum + FromBalanse - ToBalanse - Total < 0)
        {
            //
            if(Application->MessageBox("��������!\n�������� ����� ������ ����� ������! ����������?","",MB_YESNO) == IDNO)
                return ID;
        }

        else if(Change != Terminal + GetSum + FromBalanse - ToBalanse - Total)
        {
            if(Application->MessageBox("��������!\n����� �� ������������� ���������� ��������! ����������?","",MB_YESNO) == IDNO)
                return ID;
        }

        if(Change > 0)
        {
            // ���� �����
            if(Terminal > 0 && Change > GetSum)
            {
                if(Application->MessageBox("��������!\n����� ��������� ������ ��������� �������! ����������?","",MB_YESNO) == IDNO)
                return ID;
            }
        }
    }

    if(UserBalanse - FromBalanse + ToBalanse < 0 && FromBalanse > ToBalanse && !NegBalanseFlag)
    {
        Application->MessageBox("��������!\n� ��� ��� ���� ��� ����� �������������� �������.","",MB_OK);
        return ID;
    }

    // ���� ��������� ������� � ���� ����� - ��������� �������������
    if(FromBalanse != 0 && UserID != 0 && UserID != 4)
    {
        SQL_exefun(NULL,("select DiscountCard from Clients where RowID=" + AnsiString(ClientID)).c_str(),&retString);

        if(retString.Length() > 0)
        {
            DisCardForm = new TDisCardForm(this);
            DisCardForm->UserCard = retString;
            FormResult = 0;
            DisCardForm->ShowModal();

            delete DisCardForm;

            if(!FormResult)
            {
                Application->MessageBox("��������!\n�������� � ������� �� ������������.","",MB_OK);
                return ID;
            }
        }
        else
        {
            Application->MessageBox("��������!\n�������� � ������� ���������� - ��� �����.","",MB_OK);
            return ID;
        }
    }



    if(KassaOps)
    {

        //const char *pMethod = "kassa.tbSave0Click";

        TDateTime dt = Now();

        /*
        if(KassaOps & SELLOP_BATH)
        {


            // ��������������� ������ ������ �����
            // ������� ���� - �������, ������� - ������ ��� ������� ����

            // ������� ����, ������ � �����������
            // �������� �����
            SQL_exefun(NULL,("select BillItemsCount from BillItems where BillID="+AnsiString(KassaBillID)+" and Op="+AnsiString(SELLOP_BATH)+" and (ServiceID=196 or ServiceID=203)").c_str(),&retString);

            int cntserv, cnt = atoi(retString.c_str());
            // cnt - ���-�� ������� � ������, ��������� ������ ���� �� ������
            SQL_exefun(NULL,(
                "select sum(a.BillItemsCount) from BillItems a "
                "left join Services b on a.ServiceID=b.RowID "
                "where a.BillID=" + AnsiString(KassaBillID) +
                " and a.ServiceID!=196 and a.ServiceID!=203 "
                "and (b.Tag like '~SPA~%' or b.Tag like '~������� ������������~%')"
            ).c_str(),&retString);

            cntserv = atoi(retString.c_str());

            if(cntserv < cnt)
            {
                Application->MessageBox(("��������!\n���������� �������� ������� " + AnsiString(cnt-cntserv) + " ������ � ��������� ����!").c_str(),"������ ������",MB_OK);
                return ID;
            }

            AnsiString *pSIDs;
            int s_cnt;
            if((s_cnt = SQL_fldCollect(DBName,"ServiceID",("from BillItems left outer join Services on ServiceID=Services.RowID where BillID="+AnsiString(KassaBillID)+" and Op="+AnsiString(SELLOP_BATH)+" and Tag like '%~"+("������� ���� (� ������������)~%'")).c_str(),&pSIDs)) > 0)
            {
                int xx;
                for(xx = 0; xx < s_cnt; xx++)
                    if(pSIDs[xx] == "174" || pSIDs[xx] == "176" || pSIDs[xx] == "163") break;

                delete [] pSIDs;

                if(xx >= s_cnt && s_cnt < 2)
                {
                    Application->MessageBox("��������!\n���������� �������� ������ � ���������� ������� ����!","��������� ������",MB_OK);
                    return ID;
                }
            }
        }
        */

        SQL_iniInsert(NULL,"Bills",&ID);
        SQL_addInsert("ClientID",ClientID);
        SQL_addInsert("BegBalanse",BegBalanse);
        SQL_addInsert("FromBalanse",FromBalanse);
        SQL_addInsert("ToBalanse",ToBalanse);
        if(spbPayment->Caption == "�/�")// || spbTerminal->Down)
            SQL_addInsert("Payment",1);

        SQL_addInsert("EndBalanse",EndBalanse);
        SQL_addInsert("GetSum",GetSum);
        SQL_addInsert("Terminal",Terminal);
        SQL_addInsert("Change",Change);
        SQL_addInsert("Total",Total);
        SQL_addInsert("CDate",(double)dt);
        SQL_addInsert("CUID",UserID);
        SQL_addInsert("EDate",(double)dt);

        if(!InTransaction)
        {
            if(SQL_BeginTransaction() != SQLITE_OK)
                return ID;
        }

        SQL_exeInsert("EUID",UserID);

        if(BegBalanse != EndBalanse)
        {
            SQL_iniUpdate(DBName,"Clients",ClientID);
            SQL_exeUpdate("Balanse",EndBalanse);
        }

        // ������� �������

        for(unsigned i = 0; i < Counter; i++)
        {
            SQL_iniUpdate(DBName,"BillItems",IDs[i]);
            SQL_exeUpdate("BillID",ID);
        }

        unsigned cnt;
        AnsiString s1, s2, s3;

        //-----------------------------------------------------------------------------------------------------
        // �����
        //-----------------------------------------------------------------------------------------------------
        if(KassaOps & SELLOP_GOOD)
        {
            cnt = SQL_fldCollect(DBName,"RowID",("from BillItems where BillID="+AnsiString(ID)+" and Op="+AnsiString(SELLOP_GOOD)).c_str(),&pAbFields);

            for(unsigned i = 0; i < cnt; i++)
            {
                SQL_exefun2(DBName,("select GoodID,BillItemsCount from BillItems where RowID="+AnsiString(_atoi64(pAbFields[i].c_str()))).c_str(),&s1,&retString);
                SQL_exe(DBName,("update Stock set StockCount=StockCount-"+AnsiString(atoi(retString.c_str()))+" where GoodID="+AnsiString(_atoi64(s1.c_str()))).c_str());

            }
            SQL_exe(DBName,"delete from Stock where StockCount=0 and Part=0");

            delete [] pAbFields;
        }


        //-----------------------------------------------------------------------------------------------------
        // ������ ����, ����� ��������� ��������� ������
        // ���� ������� ������ � ��� ���� - ��������
        //-----------------------------------------------------------------------------------------------------
        if(KassaOps & SELLOP_BATH)
        {
            cnt = SQL_fldCollect(DBName,"RowID",("from BillItems where BillID="+AnsiString(ID)+" and Op="+AnsiString(SELLOP_BATH)+" order by RowID").c_str(),&pAbFields);
            __int64 SID, VSID;

            for(unsigned i = 0; i < cnt; i++)
            {
                AnsiString sPPrice;

                // ��� ����
                SQL_exefun(NULL,("select GoodID from BillItems where RowID="+pAbFields[i]).c_str(),&s1);
                SQL_iniInsert(NULL,"Visits_SPA",&VSID);
                SQL_addInsert("Num",s1);

                // �����! ���� ����� � ��������, ��� ��� ����������
                SQL_addInsert("ClientID",ClientID);
                SQL_addInsert("Visits_SPADate",(double)dt);
                SQL_exefun3(DBName,("select BegTime,EndTime,PersonPrice from BillItems where RowID="+pAbFields[i]).c_str(),&s1,&s2,&sPPrice);
                SQL_addInsert("BegTime",s1);
                SQL_addInsert("EndTime",s2);

                SQL_exefun3(DBName,("select PersonID,ServiceID,Total from BillItems where RowID="+pAbFields[i]).c_str(),&s1,&s2,&s3);

                SQL_addInsert("PersonID",_atoi64(s1.c_str()));
                SID = _atoi64(s2.c_str());
                SQL_addInsert("ServiceID",SID);
                SQL_addInsert("Price",atof(s3.c_str()));
                SQL_addInsert("PersonPrice",atof(sPPrice.c_str()));

                SQL_exefun(DBName,("select BillItemsCount from BillItems where RowID="+pAbFields[i]).c_str(),&s3);
                int out_cnt = atoi(s3.c_str());
                //if(out_cnt > 0)
                SQL_addInsert("GroupCnt",out_cnt);

                //SQL_exefun(DBName,("select PersonPrice from Services where RowID="+AnsiString(SID)).c_str(),&s3);
                //double price = atof(s3.c_str()) * out_cnt;
                //price = (price * (100.0 - UserDiscountSPA)) / 100.0;

                //SQL_addInsert("PersonPrice",price);

                SQL_addInsert("CDate",(double)dt);
                SQL_addInsert("CUID",UserID);
                SQL_addInsert("EDate",(double)dt);
                SQL_exeInsert("EUID",UserID);

                SQL_iniUpdate(NULL,"BillItems",_atoi64(pAbFields[i].c_str()));
                SQL_exeUpdate("VisitID",VSID);

                // �������� ���������� - ���
                //AnsiString *pGoods;
                //const char *pF[] = { "GoodID", "Rate" };

                //unsigned gcnt = SQL_Collect(DBName,2,pF,("from ServiceGoods where ServiceID="+AnsiString(_atoi64(s2.c_str()))).c_str(),NULL,&pGoods);
                /*
                if(gcnt)
                {
                    __int64 GID;
                    AnsiString sStock[3];

                    for(unsigned j = 0; j < gcnt; j++)
                    {
                        SQL_exefunrow(DBName,("select first 1 RowID,StockCount,Part from Stock where GoodID="+pGoods[j<<1]).c_str(),3,sStock);
                        GID = _atoi64(sStock[0].c_str());

                        int rate = -atoi(pGoods[(j<<1)+1].c_str()) * out_cnt;
                        int count = atoi(sStock[1].c_str());
                        int part = atoi(sStock[2].c_str());

                        SQL_iniInsert(DBName,"Outcome");
                        SQL_addInsert("Visit_SPAID",VSID);
                        SQL_addInsert("GoodID",pGoods[j<<1]);
                        SQL_addInsert("ServiceID",_atoi64(s2.c_str()));
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
                */
            }

            delete [] pAbFields;
        }

        //-----------------------------------------------------------------------------------------------------
        // ��������������
        //-----------------------------------------------------------------------------------------------------

        if(KassaOps & SELLOP_BARBER)
        {
            cnt = SQL_fldCollect(DBName,"RowID",("from BillItems where BillID="+AnsiString(ID)+" and Op="+AnsiString(SELLOP_BARBER)+" order by RowID").c_str(),&pAbFields);
            __int64 SID, VSID;

            for(unsigned i = 0; i < cnt; i++)
            {
                AnsiString sPPrice;

                SQL_exefun(NULL,("select DiscountID from BillItems where RowID="+pAbFields[i]).c_str(),&s1);
                SQL_iniInsert(NULL,"Visits_SPA",&VSID);
                SID = ATOI64(s1.c_str());
                SQL_addInsert("ClientID",SID? SID : ClientID);

                SQL_addInsert("Visits_SPADate",(double)dt);
                SQL_exefun3(DBName,("select BegTime,EndTime,PersonPrice from BillItems where RowID="+pAbFields[i]).c_str(),&s1,&s2,&sPPrice);
                SQL_addInsert("BegTime",s1);
                SQL_addInsert("EndTime",s2);

                SQL_exefun3(DBName,("select PersonID,ServiceID,Total from BillItems where RowID="+pAbFields[i]).c_str(),&s1,&s2,&s3);

                SQL_addInsert("PersonID",_atoi64(s1.c_str()));
                SID = _atoi64(s2.c_str());
                SQL_addInsert("ServiceID",SID);
                SQL_addInsert("Price",atof(s3.c_str()));
                SQL_addInsert("PersonPrice",atof(sPPrice.c_str()));

                SQL_exefun(DBName,("select BillItemsCount from BillItems where RowID="+pAbFields[i]).c_str(),&s3);
                int out_cnt = atoi(s3.c_str());
                //if(out_cnt > 0)
                SQL_addInsert("GroupCnt",out_cnt);

                //SQL_exefun(DBName,("select PersonPrice from Services where RowID="+AnsiString(SID)).c_str(),&s3);
                //double price = atof(s3.c_str()) * out_cnt;
                //price = (price * (100.0 - UserDiscountSPA)) / 100.0;

                //SQL_addInsert("PersonPrice",price);

                SQL_addInsert("CDate",(double)dt);
                SQL_addInsert("CUID",UserID);
                SQL_addInsert("EDate",(double)dt);
                SQL_exeInsert("EUID",UserID);

                // �.�. ���. ������
                SQL_exe(DBName,("update AddOp set Visits_SPAID="+AnsiString(VSID)+" where BillItemsID="+AnsiString(pAbFields[i])).c_str());

                SQL_iniUpdate(NULL,"BillItems",_atoi64(pAbFields[i].c_str()));
                SQL_exeUpdate("VisitID",VSID);
                // �������� ����������
                AnsiString *pGoods;
                const char *pF[] = { "GoodID", "Rate" };

                unsigned gcnt = SQL_Collect(DBName,2,pF,("from ServiceGoods where ServiceID="+AnsiString(_atoi64(s2.c_str()))).c_str(),NULL,&pGoods);

                if(gcnt)
                {
                    __int64 GID;
                    AnsiString sStock[3];

                    for(unsigned j = 0; j < gcnt; j++)
                    {
                        SQL_exefunrow(DBName,("select first 1 RowID,StockCount,Part from Stock where GoodID="+pGoods[j<<1]).c_str(),3,sStock);
                        GID = _atoi64(sStock[0].c_str());

                        int rate = -atoi(pGoods[(j<<1)+1].c_str()) * out_cnt;
                        int count = atoi(sStock[1].c_str());
                        int part = atoi(sStock[2].c_str());

                        SQL_iniInsert(DBName,"Outcome");
                        SQL_addInsert("Visit_SPAID",VSID);
                        SQL_addInsert("GoodID",pGoods[j<<1]);
                        SQL_addInsert("ServiceID",_atoi64(s2.c_str()));
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
            delete [] pAbFields;
        }

        //-----------------------------------------------------------------------------------------------------
        // �����
        //-----------------------------------------------------------------------------------------------------

        if(KassaOps & SELLOP_NAIL)
        {
            cnt = SQL_fldCollect(DBName,"RowID",("from BillItems where BillID="+AnsiString(ID)+" and Op="+AnsiString(SELLOP_NAIL)+" order by RowID").c_str(),&pAbFields);
            __int64 SID, VSID;

            for(unsigned i = 0; i < cnt; i++)
            {
                AnsiString sPPrice;

                SQL_exefun(NULL,("select DiscountID from BillItems where RowID="+pAbFields[i]).c_str(),&s1);
                SQL_iniInsert(NULL,"Visits_SPA",&VSID);
                SID = ATOI64(s1.c_str());
                SQL_addInsert("ClientID",SID? SID : ClientID);

                SQL_addInsert("Visits_SPADate",(double)dt);
                SQL_exefun3(DBName,("select BegTime,EndTime,PersonPrice from BillItems where RowID="+pAbFields[i]).c_str(),&s1,&s2,&sPPrice);
                SQL_addInsert("BegTime",s1);
                SQL_addInsert("EndTime",s2);

                SQL_exefun3(DBName,("select PersonID,ServiceID,Total from BillItems where RowID="+pAbFields[i]).c_str(),&s1,&s2,&s3);

                SQL_addInsert("PersonID",_atoi64(s1.c_str()));
                SID = _atoi64(s2.c_str());
                SQL_addInsert("ServiceID",SID);
                SQL_addInsert("Price",atof(s3.c_str()));
                SQL_addInsert("PersonPrice",atof(sPPrice.c_str()));

                SQL_exefun(DBName,("select BillItemsCount from BillItems where RowID="+pAbFields[i]).c_str(),&s3);
                int out_cnt = atoi(s3.c_str());
                //if(out_cnt > 0)
                SQL_addInsert("GroupCnt",out_cnt);

                //SQL_exefun(DBName,("select PersonPrice from Services where RowID="+AnsiString(SID)).c_str(),&s3);
                //double price = atof(s3.c_str()) * out_cnt;
                //price = (price * (100.0 - UserDiscountSPA)) / 100.0;

                //SQL_addInsert("PersonPrice",price);

                SQL_addInsert("CDate",(double)dt);
                SQL_addInsert("CUID",UserID);
                SQL_addInsert("EDate",(double)dt);
                SQL_exeInsert("EUID",UserID);

                // �.�. ���. ������
                SQL_exe(DBName,("update AddOp set Visits_SPAID="+AnsiString(VSID)+" where BillItemsID="+AnsiString(pAbFields[i])).c_str());

                SQL_iniUpdate(NULL,"BillItems",_atoi64(pAbFields[i].c_str()));
                SQL_exeUpdate("VisitID",VSID);
                // �������� ����������
                AnsiString *pGoods;
                const char *pF[] = { "GoodID", "Rate" };

                unsigned gcnt = SQL_Collect(DBName,2,pF,("from ServiceGoods where ServiceID="+AnsiString(_atoi64(s2.c_str()))).c_str(),NULL,&pGoods);

                if(gcnt)
                {
                    __int64 GID;
                    AnsiString sStock[3];

                    for(unsigned j = 0; j < gcnt; j++)
                    {
                        SQL_exefunrow(DBName,("select first 1 RowID,StockCount,Part from Stock where GoodID="+pGoods[j<<1]).c_str(),3,sStock);
                        GID = _atoi64(sStock[0].c_str());

                        int rate = -atoi(pGoods[(j<<1)+1].c_str()) * out_cnt;
                        int count = atoi(sStock[1].c_str());
                        int part = atoi(sStock[2].c_str());

                        SQL_iniInsert(DBName,"Outcome");
                        SQL_addInsert("Visit_SPAID",VSID);
                        SQL_addInsert("GoodID",pGoods[j<<1]);
                        SQL_addInsert("ServiceID",_atoi64(s2.c_str()));
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
            delete [] pAbFields;
        }

        //-----------------------------------------------------------------------------------------------------
        // ���������
        //-----------------------------------------------------------------------------------------------------

        if(KassaOps & SELLOP_COSMETIC)
        {
            cnt = SQL_fldCollect(DBName,"RowID",("from BillItems where BillID="+AnsiString(ID)+" and Op="+AnsiString(SELLOP_COSMETIC)+" order by RowID").c_str(),&pAbFields);
            __int64 SID, VSID;

            for(unsigned i = 0; i < cnt; i++)
            {
                AnsiString sPPrice;

                SQL_exefun(NULL,("select DiscountID from BillItems where RowID="+pAbFields[i]).c_str(),&s1);
                SQL_iniInsert(NULL,"Visits_SPA",&VSID);
                SID = ATOI64(s1.c_str());
                SQL_addInsert("ClientID",SID? SID : ClientID);

                SQL_addInsert("Visits_SPADate",(double)dt);
                SQL_exefun3(DBName,("select BegTime,EndTime,PersonPrice from BillItems where RowID="+pAbFields[i]).c_str(),&s1,&s2,&sPPrice);
                SQL_addInsert("BegTime",s1);
                SQL_addInsert("EndTime",s2);

                SQL_exefun3(DBName,("select PersonID,ServiceID,Total from BillItems where RowID="+pAbFields[i]).c_str(),&s1,&s2,&s3);

                SQL_addInsert("PersonID",_atoi64(s1.c_str()));
                SID = _atoi64(s2.c_str());
                SQL_addInsert("ServiceID",SID);
                SQL_addInsert("Price",atof(s3.c_str()));
                SQL_addInsert("PersonPrice",atof(sPPrice.c_str()));

                SQL_exefun(DBName,("select BillItemsCount from BillItems where RowID="+pAbFields[i]).c_str(),&s3);
                int out_cnt = atoi(s3.c_str());
                //if(out_cnt > 0)
                SQL_addInsert("GroupCnt",out_cnt);

                //SQL_exefun(DBName,("select PersonPrice from Services where RowID="+AnsiString(SID)).c_str(),&s3);
                //double price = atof(s3.c_str()) * out_cnt;
                //price = (price * (100.0 - UserDiscountSPA)) / 100.0;

                //SQL_addInsert("PersonPrice",price);

                SQL_addInsert("CDate",(double)dt);
                SQL_addInsert("CUID",UserID);
                SQL_addInsert("EDate",(double)dt);
                SQL_exeInsert("EUID",UserID);

                // �.�. ���. ������
                SQL_exe(DBName,("update AddOp set Visits_SPAID="+AnsiString(VSID)+" where BillItemsID="+AnsiString(pAbFields[i])).c_str());

                SQL_iniUpdate(NULL,"BillItems",_atoi64(pAbFields[i].c_str()));
                SQL_exeUpdate("VisitID",VSID);
                // �������� ����������
                AnsiString *pGoods;
                const char *pF[] = { "GoodID", "Rate" };

                unsigned gcnt = SQL_Collect(DBName,2,pF,("from ServiceGoods where ServiceID="+AnsiString(_atoi64(s2.c_str()))).c_str(),NULL,&pGoods);

                if(gcnt)
                {
                    __int64 GID;
                    AnsiString sStock[3];

                    for(unsigned j = 0; j < gcnt; j++)
                    {
                        SQL_exefunrow(DBName,("select first 1 RowID,StockCount,Part from Stock where GoodID="+pGoods[j<<1]).c_str(),3,sStock);
                        GID = _atoi64(sStock[0].c_str());

                        int rate = -atoi(pGoods[(j<<1)+1].c_str()) * out_cnt;
                        int count = atoi(sStock[1].c_str());
                        int part = atoi(sStock[2].c_str());

                        SQL_iniInsert(DBName,"Outcome");
                        SQL_addInsert("Visit_SPAID",VSID);
                        SQL_addInsert("GoodID",pGoods[j<<1]);
                        SQL_addInsert("ServiceID",_atoi64(s2.c_str()));
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
            delete [] pAbFields;
        }

        //-----------------------------------------------------------------------------------------------------
        // ������ SPA
        //-----------------------------------------------------------------------------------------------------
        if(KassaOps & SELLOP_SPA_VISIT)
        {
            __int64 SID, VSID;
            cnt = SQL_fldCollect(DBName,"RowID",("from BillItems where BillID="+AnsiString(ID)+" and Op="+AnsiString(SELLOP_SPA_VISIT)+" order by RowID").c_str(),&pAbFields);

            for(unsigned i = 0; i < cnt; i++)
            {
                AnsiString sPPrice;

                SQL_exefun(NULL,("select DiscountID from BillItems where RowID="+pAbFields[i]).c_str(),&s1);
                SQL_iniInsert(NULL,"Visits_SPA",&VSID);
                SID = ATOI64(s1.c_str());
                SQL_addInsert("ClientID",SID? SID : ClientID);

                SQL_addInsert("Visits_SPADate",(double)dt);
                SQL_exefun3(DBName,("select BegTime,EndTime,PersonPrice from BillItems where RowID="+pAbFields[i]).c_str(),&s1,&s2,&sPPrice);
                SQL_addInsert("BegTime",s1);
                SQL_addInsert("EndTime",s2);

                SQL_exefun3(DBName,("select PersonID,ServiceID,Total from BillItems where RowID="+pAbFields[i]).c_str(),&s1,&s2,&s3);

                SQL_addInsert("PersonID",_atoi64(s1.c_str()));
                SQL_addInsert("ServiceID",_atoi64(s2.c_str()));
                SQL_addInsert("Price",atof(s3.c_str()));

                //SQL_exefun(DBName,("select PersonPrice from Services where RowID="+AnsiString(_atoi64(s2.c_str()))).c_str(),&s3);
                //double price = atof(s3.c_str());
                //price = (price * (100.0 - UserDiscountSPA)) / 100.0;

                SQL_addInsert("PersonPrice",atof(sPPrice.c_str()));

                SQL_addInsert("CDate",(double)dt);
                SQL_addInsert("CUID",UserID);
                SQL_addInsert("EDate",(double)dt);
                SQL_exeInsert("EUID",UserID);

                SQL_iniUpdate(NULL,"BillItems",_atoi64(pAbFields[i].c_str()));
                SQL_exeUpdate("VisitID",VSID);
                // �������� ����������
                AnsiString *pGoods;
                const char *pF[] = { "GoodID", "Rate" };

                unsigned gcnt = SQL_Collect(DBName,2,pF,("from ServiceGoods where ServiceID="+AnsiString(_atoi64(s2.c_str()))).c_str(),NULL,&pGoods);

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
                        SQL_addInsert("Visit_SPAID",VSID);
                        SQL_addInsert("GoodID",pGoods[j<<1]);
                        SQL_addInsert("ServiceID",_atoi64(s2.c_str()));
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

            delete [] pAbFields;
        }

        //-----------------------------------------------------------------------------------------------------
        // ��������� �� SPA
        //-----------------------------------------------------------------------------------------------------
        if(KassaOps & SELLOP_ABONEMENT_SPA)
        {
            SQL_exefun(DBName,("select count(*) from BillItems where BillID="+(AnsiString)ID+" and Op="+AnsiString(SELLOP_ABONEMENT_SPA)).c_str(),&retString);
            cnt = atoi(retString.c_str());

            if(cnt == 1)
            {
                // ���� SPA
                AnsiString sBIID;
                __int64 AID;
                pAbFields = new AnsiString[4];

                SQL_exefun3(DBName,("select Price,PersonID,RowID from BillItems where BillID="+(AnsiString)ID+" and Op="+AnsiString(SELLOP_ABONEMENT_SPA)).c_str(),&pAbFields[0],&pAbFields[1],&sBIID);
                SQL_exefun2(DBName,("select ServiceID,Discount from BillItems where BillID="+(AnsiString)ID+" and Op="+AnsiString(SELLOP_ABONEMENT_SPA)).c_str(),&pAbFields[2],&pAbFields[3]);
                double price = atof(pAbFields[0].c_str());
                TDateTime edt = addmonths(dt,1);

                SQL_iniInsert(DBName,"Abonements_SPA",&AID);

                SQL_addInsert("ClientID",ClientID);
                SQL_addInsert("Balanse",price);
                SQL_addInsert("Price",price);

                //SQL_addInsert("PersonID",pAbFields[1]);
                //SQL_addInsert("ServiceID",pAbFields[2]);
                //SQL_addInsert("FixSum",fixsum);
                SQL_addInsert("#Name","������ "+pAbFields[3]+"%");
                //SQL_addInsert("Count",count);
                SQL_addInsert("Discount",pAbFields[3]);
                SQL_addInsert("BegDate",(double)dt);
                SQL_addInsert("EndDate",(double)edt);
                //SQL_addInsert("AutoFlow",autoflow);
                SQL_addInsert("CDate",(double)dt);
                SQL_addInsert("CUID",UserID);
                SQL_addInsert("EDate",(double)dt);

                SQL_exeInsert("EUID",UserID);

                SQL_iniUpdate(NULL,"BillItems",_atoi64(sBIID.c_str()));
                SQL_exeUpdate("AbonementID",AID);

                if(WriteACheck)
                {
                    SQL_iniInsert(DBName,"ACheck");
                    SQL_addInsert("F0",ClientID);
                    SQL_addInsert("F1",ID);
                    SQL_addInsert("F2",_atoi64(sBIID.c_str()));
                    SQL_addInsert("F3",AID);
                    SQL_addInsert("F4",1);
                    SQL_addInsert("F5",UserID);
                    SQL_exeInsert("F6",(double)dt);
                }

                PDEL(pAbFields);
            }
        }

        //-----------------------------------------------------------------------------------------------------
        // ��������� � ����
        //-----------------------------------------------------------------------------------------------------
        if(KassaOps & SELLOP_ABONEMENT_BATH)
        {
            SQL_exefun(DBName,("select count(*) from AbTypes where RowID in (select AbTypeID from BillItems where BillID="+(AnsiString)ID+" and AbTypeID!=0)").c_str(),&retString);
            cnt = atoi(retString.c_str());

            if(cnt == 1)
            {
                AnsiString sBIID;
                __int64 AID;
                pAbFields = new AnsiString[9];

                retString = "select RowID,Name,Price,AbTypesCount,Days,AutoFlow,PersonID,ServiceID,FixSum from AbTypes where RowID in (select AbTypeID from BillItems where BillID=";
                retString += ((AnsiString)ID + " and AbTypeID!=0)");
                SQL_exe(DBName,retString.c_str(),abonements_create);

                SQL_exefun3(DBName,("select PersonID,ServiceID,RowID from BillItems where BillID="+(AnsiString)ID+" and AbTypeID!=0").c_str(),&pAbFields[6],&pAbFields[7],&sBIID);

                double fixsum = atof(pAbFields[8].c_str());
                int count = atoi(pAbFields[3].c_str());
                int autoflow = atoi(pAbFields[5].c_str());
                if(autoflow) autoflow = 60;

                double price = atof(pAbFields[2].c_str());
                if(UserDiscount != 0.0)
                {
                    if(price != 0.0)
                        price = (price * (100.0 - UserDiscount)) / 100.0;
                    if(fixsum != 0.0)
                        fixsum = (fixsum * (100.0 - UserDiscount)) / 100.0;
                }

                SQL_iniInsert(DBName,"Abonements_Bath",&AID);

                SQL_addInsert("AbonementID",0);
                SQL_addInsert("ClientID",ClientID);
                SQL_addInsert("AbTypeID",pAbFields[0]);
                SQL_addInsert("PersonID",pAbFields[6]);
                SQL_addInsert("ServiceID",pAbFields[7]);
                SQL_addInsert("FixSum",fixsum);
                SQL_addInsert("!Name",pAbFields[1]);
                SQL_addInsert("Price",price);
                SQL_addInsert("AbonementsCount",count);
                SQL_addInsert("Discount",UserDiscount);
                SQL_addInsert("BegDate",(double)dt);

                unsigned days = atoi(pAbFields[4].c_str());

                TDateTime edt;

                if(days == 1)
                    edt = dt;
                else
                {
                    if(days == 90)
                        edt = addmonths(dt,3);
                    else if(days == 180)
                        edt = addmonths(dt,6);
                    else if(days == 360)
                        edt = addmonths(dt,12);
                    else
                        edt = addmonths(dt,1);
                }

                SQL_addInsert("EndDate",(double)edt);
                SQL_addInsert("AutoFlow",autoflow);
                SQL_addInsert("CDate",(double)dt);
                SQL_addInsert("CUID",UserID);
                SQL_addInsert("EDate",(double)dt);

                SQL_exeInsert("EUID",UserID);

                SQL_iniUpdate(NULL,"BillItems",_atoi64(sBIID.c_str()));
                SQL_exeUpdate("AbonementID",AID);

                if(WriteACheck)
                {
                    SQL_iniInsert(DBName,"ACheck");
                    SQL_addInsert("F0",ClientID);
                    SQL_addInsert("F1",ID);
                    SQL_addInsert("F2",_atoi64(sBIID.c_str()));
                    SQL_addInsert("F3",AID);
                    SQL_addInsert("F4",0);
                    SQL_addInsert("F5",UserID);
                    SQL_exeInsert("F6",(double)dt);
                }

                if(pAbFields[0] == BATH_TICKET)
                {
                    SQL_iniInsert(DBName,"Visits_Bath");
                    SQL_addInsert("AbonementID",AID);

                    SQL_addInsert("VisitsDate",(double)dt);
                    SQL_addInsert("BegTime",(double)dt);
                    SQL_addInsert("EndTime",(double)edt);

                    SQL_addInsert("Price",price);

                    SQL_addInsert("PersonID",pAbFields[6]);
                    SQL_addInsert("ServiceID",pAbFields[7]);

                    SQL_addInsert("CDate",(double)dt);
                    SQL_addInsert("CUID",UserID);
                    SQL_addInsert("EDate",(double)dt);

                    SQL_exeInsert("EUID",UserID);

                    //price -= fixsum;

                    // ������� �� ������ ����?
                }

                PDEL(pAbFields);
            }
        }
        //-----------------------------------------------------------------------------------------------------
        // ��������� �� �������
        //-----------------------------------------------------------------------------------------------------
        if(KassaOps & SELLOP_ABONEMENT)
        {
            SQL_exefun(DBName,("select count(*) from AbTypes where RowID in (select AbTypeID from BillItems where BillID="+(AnsiString)ID+" and AbTypeID!=0)").c_str(),&retString);
            cnt = atoi(retString.c_str());

            if(cnt == 1)
            {
                // ������ �� ������������ ��������� �� ������� � ��� �������� ���� ����� �� �������

                AnsiString sBIID;
                __int64 AID;
                pAbFields = new AnsiString[9];

                retString = "select RowID,Name,Price,AbTypesCount,Days,AutoFlow,PersonID,ServiceID,FixSum from AbTypes where RowID in (select AbTypeID from BillItems where BillID=";
                retString += ((AnsiString)ID + " and AbTypeID!=0)");
                SQL_exe(DBName,retString.c_str(),abonements_create);

                SQL_exefun3(DBName,("select PersonID,ServiceID,RowID from BillItems where BillID="+(AnsiString)ID+" and AbTypeID!=0").c_str(),&pAbFields[6],&pAbFields[7],&sBIID);

                double fixsum = atof(pAbFields[8].c_str());
                int count = atoi(pAbFields[3].c_str());
                int autoflow = atoi(pAbFields[5].c_str());
                if(autoflow) autoflow = 60;

                double price = atof(pAbFields[2].c_str());
                if(UserDiscount != 0.0)
                {
                    if(price != 0.0)
                        price = (price * (100.0 - UserDiscount)) / 100.0;
                    if(fixsum != 0.0)
                        fixsum = (fixsum * (100.0 - UserDiscount)) / 100.0;
                }

                SQL_iniInsert(DBName,"Abonements",&AID);

                SQL_addInsert("ClientID",ClientID);
                SQL_addInsert("AbTypeID",pAbFields[0]);
                SQL_addInsert("PersonID",pAbFields[6]);
                SQL_addInsert("ServiceID",pAbFields[7]);
                SQL_addInsert("FixSum",fixsum);
                SQL_addInsert("!Name",pAbFields[1]);
                SQL_addInsert("Price",price);
                SQL_addInsert("AbonementsCount",count);
                SQL_addInsert("Discount",UserDiscount);
                SQL_addInsert("BegDate",(double)dt);

                unsigned days = atoi(pAbFields[4].c_str());

                TDateTime edt;

                if(days == 1)
                    edt = dt;
                else
                {
                    if(days == 90)
                        edt = addmonths(dt,3);
                    else if(days == 180)
                        edt = addmonths(dt,6);
                    else if(days == 360)
                        edt = addmonths(dt,12);
                    else
                        edt = addmonths(dt,1);
                }

                SQL_addInsert("EndDate",(double)edt);
                SQL_addInsert("AutoFlow",autoflow);
                SQL_addInsert("CDate",(double)dt);
                SQL_addInsert("CUID",UserID);
                SQL_addInsert("EDate",(double)dt);

                SQL_exeInsert("EUID",UserID);

                SQL_iniUpdate(NULL,"BillItems",_atoi64(sBIID.c_str()));
                SQL_exeUpdate("AbonementID",AID);

                if(WriteACheck)
                {
                    SQL_iniInsert(DBName,"ACheck");
                    SQL_addInsert("F0",ClientID);
                    SQL_addInsert("F1",ID);
                    SQL_addInsert("F2",_atoi64(sBIID.c_str()));
                    SQL_addInsert("F3",AID);
                    SQL_addInsert("F4",0);
                    SQL_addInsert("F5",UserID);
                    SQL_exeInsert("F6",(double)dt);
                }

                if(pAbFields[0] == "24") // �������
                {
                    SQL_iniInsert(DBName,"Visits");
                    SQL_addInsert("AbonementID",AID);

                    SQL_addInsert("VisitsDate",(double)dt);
                    SQL_addInsert("BegTime",(double)dt);
                    SQL_addInsert("EndTime",(double)edt);

                    SQL_addInsert("Price",fixsum);

                    SQL_addInsert("PersonID",pAbFields[6]);
                    SQL_addInsert("ServiceID",pAbFields[7]);

                    SQL_addInsert("CDate",(double)dt);
                    SQL_addInsert("CUID",UserID);
                    SQL_addInsert("EDate",(double)dt);

                    SQL_exeInsert("EUID",UserID);

                    price -= fixsum;

                    // ������� ������� �� �������
                    SQL_exefun(DBName,"select RowID from Services where Name='�������'",&retString);
                    __int64 BassID = _atoi64(retString.c_str());
                    if(BassID)
                    {
                        SQL_iniInsert(DBName,"Visits");
                        SQL_addInsert("AbonementID",AID);

                        SQL_addInsert("VisitsDate",(double)dt);
                        SQL_addInsert("BegTime",(double)dt);
                        SQL_addInsert("EndTime",(double)edt);
                        SQL_addInsert("Price",price);
                        SQL_addInsert("PersonID",0);
                        SQL_addInsert("ServiceID",BassID);

                        SQL_addInsert("CDate",(double)dt);
                        SQL_addInsert("CUID",UserID);
                        SQL_addInsert("EDate",(double)dt);
                        SQL_exeInsert("EUID",UserID);
                    }
                }
                else if(pAbFields[0] != "25" && pAbFields[0] != "26" && pAbFields[0] != "50")
                {
                    SQL_exefun(NULL,("update Abonements set Closed=1 where ClientID="+AnsiString(ClientID)+" and AbTypeID in (25,50)").c_str());

                }

                PDEL(pAbFields);
            }
        }

        if(!InTransaction)
        {
            if(SQL_CommitTransaction() == SQLITE_OK)
                FormResult = -1;
        }
        else
            FormResult = -1;
    }

    return ID;
}
//-----------------------------------------------------------------------------------------------------
void __fastcall TKassaForm::sbChangeUpClick(TObject *Sender)
{
    // ����� �� ������
    edInput->Visible = false;
   
    FromBalanse = ATOF(edFromBalanse->Text.c_str());
    ToBalanse = ATOF(edToBalanse->Text.c_str());
    GetSum = ATOF(edGetSum->Text.c_str());
    Terminal = ATOF(edTerminal->Text.c_str());

    Change = Terminal + GetSum - Total - ToBalanse + FromBalanse;
    if(Change < 0) Change = 0;
    else if(Change > GetSum) Change = GetSum;

    ToBalanse += Change;
    Change = 0;

    KassaUpdateInfo();
}
//---------------------------------------------------------------------------
void __fastcall TKassaForm::spbTerminalClick(TObject *Sender)
{
/*
    static int i = 0;
    if(i++ & 1)
    {
        spbTerminal->Font->Color = clBlack;
        if(spbTerminal->Down) spbTerminal2->Down = true;
        edToBalanse->Enabled = true;
        edFromBalanse->Enabled = true;
        edGetSum->Enabled = true;

        sbBalanseUp->Enabled = true;
        sbChangeUp->Enabled = true;
        sbGetSumUp->Enabled = true;
    }
    else
    {
        spbTerminal->Font->Color = clFuchsia;

        ToBalanse = 0;
        FromBalanse = 0;
        GetSum = 0;
        KassaUpdateInfo();

        edToBalanse->Enabled = false;
        edFromBalanse->Enabled = false;
        edGetSum->Enabled = false;

        sbBalanseUp->Enabled = false;
        sbChangeUp->Enabled = false;
        sbGetSumUp->Enabled = false;
    }
    */
}
//---------------------------------------------------------------------------
void __fastcall TKassaForm::edTerminalKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key == VK_RETURN)
    {
        Terminal = ATOF(edGetSum->Text.c_str());

        KassaUpdateInfo();
    }
}
//---------------------------------------------------------------------------
void __fastcall TKassaForm::edTerminalExit(TObject *Sender)
{
    Terminal = ATOF(edTerminal->Text.c_str());

    KassaUpdateInfo();
}
//---------------------------------------------------------------------------
void __fastcall TKassaForm::SpeedButton1Click(TObject *Sender)
{
    // ������� � ���������
    edInput->Visible = false;

    FromBalanse = ATOF(edFromBalanse->Text.c_str());
    ToBalanse = ATOF(edToBalanse->Text.c_str());
    GetSum = ATOF(edGetSum->Text.c_str());
    Terminal = ATOF(edTerminal->Text.c_str());

    Terminal = Total - GetSum - FromBalanse + ToBalanse;
    if(Terminal < 0) Terminal = 0;

    KassaUpdateInfo();

}
//---------------------------------------------------------------------------







