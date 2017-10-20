//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "sells.h"
#include "lib.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

extern const char *DBName;
extern const char *MoneyFormat;

TSellsForm *SellsForm;
//---------------------------------------------------------------------------
static int fill_fun(void *NotUsed, int argc, char **argv, char **azColName)
{
    //sgCounter++;

    TDateTime dt = atof(argv[0]);

    SellsForm->sgSells->Cells[0][++SellsForm->sgCounter] = dt.DateString();
    SellsForm->sgSells->Cells[1][SellsForm->sgCounter] = dt.TimeString();

    //AnsiString sRet;
    //SQL_exefun(DBName,(AnsiString("select Name from Goods where RowID=")+argv[1]).c_str(),&sRet);

    SellsForm->sgSells->Cells[2][SellsForm->sgCounter] = (argv[1]);

    int count = atoi(argv[2]);
    SellsForm->sgSells->Cells[3][SellsForm->sgCounter] = count;
    SellsForm->TotalCount += count;

    double sum = atof(argv[3]);
    SellsForm->sgSells->Cells[4][SellsForm->sgCounter] = FormatFloat(MoneyFormat,sum);
    SellsForm->TotalSum += sum;

    //SQL_exefun(DBName,(AnsiString("select User from Stars where RowID=")+argv[4]).c_str(),&sRet);
    SellsForm->sgSells->Cells[5][SellsForm->sgCounter] = (argv[4]);

    //SQL_exefun(DBName,(AnsiString("select FName from Clients where RowID=")+argv[5]).c_str(),&sRet);

    SellsForm->sgSells->Cells[6][SellsForm->sgCounter] = AnsiString(argv[5]) + " " + (argv[6]) + " " + (argv[7]);

    return 0;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TSellsForm::sgSellsWindowProc(Messages::TMessage& Msg)
{
    bool done = Msg.Msg == WM_SIZE;

    if(Msg.Msg == WM_NCHITTEST || done)
    {
        int i;

        if(!done)
        {
            for(i = 0; i < sgSells->ColCount; i++)
                if(sgSells->ColWidths[i] != SellsWidths[i]) break;
            done = i < sgSells->ColCount;
        }

        if(done)
        {
            int sum_width = 0;

            for(i = 0; i < sgSells->ColCount; i++)
            {
                if(sgSells->ColWidths[i] < 16) sgSells->ColWidths[i] = 16;
                sum_width += sgSells->ColWidths[i];
            }

            int width = sgSells->ClientWidth - sgSells->ColCount;

            if(sum_width < width) sgSells->ColWidths[sgSells->ColCount-1] += (width - sum_width);
            else if(sum_width > width)
            {
                // Вылез за границы
                int w;

                for(i = sgSells->ColCount - 1; i >= 0 && sum_width > width; i--)
                {
                    w = sgSells->ColWidths[i];

                    sgSells->ColWidths[i] -= (sum_width - width);
                    if(sgSells->ColWidths[i] < 16)
                    {
                        sgSells->ColWidths[i] = 16;
                        sum_width -= (w - 16);
                    }
                    else
                        break;
                }
            }

            for(i = 0; i < sgSells->ColCount; i++)
                SellsWidths[i] = sgSells->ColWidths[i];
        }
    }

    if(Msg.Msg != WM_SIZE)
        sgOSellsWindowProc(Msg);
}
//---------------------------------------------------------------------------
__fastcall TSellsForm::TSellsForm(TComponent* Owner)
    : TForm(Owner)
{
    fldAlignSells = "lrRrrrr";
}
//---------------------------------------------------------------------------
void __fastcall TSellsForm::FormShow(TObject *Sender)
{
    dtpBegDate->DateTime = Now();
    dtpEndDate->DateTime = dtpBegDate->DateTime + 1;
    SellsWidths = new int[sgSells->ColCount];

    sgSells->Cells[0][0] = "Дата";
    sgSells->Cells[1][0] = "Время";
    sgSells->Cells[2][0] = "Товар";
    sgSells->Cells[3][0] = "Кол-во";
    sgSells->Cells[4][0] = "Сумма";
    sgSells->Cells[5][0] = "Продавец";
    sgSells->Cells[6][0] = "Покупатель";

    sgSells->ColWidths[0] = SellsWidths[0] = 80;
    sgSells->ColWidths[1] = SellsWidths[1] = 80;
    sgSells->ColWidths[2] = SellsWidths[2] = 150;
    sgSells->ColWidths[3] = SellsWidths[3] = 80;
    sgSells->ColWidths[4] = SellsWidths[4] = 80;
    sgSells->ColWidths[5] = SellsWidths[5] = 120;

    sgSells->ColWidths[6] = SellsWidths[6] = sgSells->ClientWidth - sgSells->ColWidths[0] - sgSells->ColWidths[1] - sgSells->ColWidths[2] - sgSells->ColWidths[3] - sgSells->ColWidths[4] - sgSells->ColWidths[5] - sgSells->ColCount;



    //SQL_exefun(DBName,"select count(*) from Stars",&retString);

    sgOSellsWindowProc = sgSells->WindowProc;
    sgSells->WindowProc = sgSellsWindowProc;

    sgSellsFullUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TSellsForm::FormDestroy(TObject *Sender)
{
    delete [] SellsWidths;    
}
//---------------------------------------------------------------------------
void __fastcall TSellsForm::sgSellsDrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
    if(State.Contains(gdFixed))
    {
        sgSells->Canvas->Font->Style = TFontStyles() << fsBold;
        sgSells->Canvas->Font->Color = HEADER_COLOR;

        int lft = Rect.Width() - sgSells->Canvas->TextWidth(sgSells->Cells[ACol][0]);
        if(lft < 2) lft = 2;
        else lft >>= 1;
        sgSells->Canvas->TextRect(Rect,Rect.left+lft,Rect.top+1,sgSells->Cells[ACol][0]);
    }
    else
    {
        if(State.Contains(gdSelected))
        {
            sgSells->Canvas->Brush->Color = SelColor;
            //SEL_COLOR;
            sgSells->Canvas->FillRect(Rect);
        }
        else
        {
            sgSells->Canvas->Brush->Color = clWhite;
            sgSells->Canvas->FillRect(Rect);
        }

        sgSells->Canvas->Font->Color = clBlack;
        sgAlignTextDraw(sgSells,ACol,ARow,Rect,fldAlignSells);
    }
}
//---------------------------------------------------------------------------
void __fastcall TSellsForm::sgSellsFullUpdate(void)
{
    TotalCount = 0;
    TotalSum = 0.0;

    // Чеки
    sgSells->RowCount = 2;
    sgSells->Row = 1;
    sgCounter = 0;
    for(int i = 0; i < sgSells->ColCount; i++)
        sgSells->Cells[i][1] = "";

    AnsiString sql =
        "select count(*) from BillItems,Bills,Goods,Stars,Clients "
        "where BillItems.BillID=Bills.RowID and BillItems.GoodID=Goods.RowID and Bills.CUID=Stars.RowID and Bills.ClientID=Clients.RowID "
        "and Op=4 and Bills.CDate>=";
    sql += (int)dtpBegDate->DateTime;
    sql += " and Bills.CDate<";
    sql += (int)dtpEndDate->DateTime;

    if(cbChoice->ItemIndex > 0)
    {
        sql += " and Goods.Section=";
        sql += (cbChoice->ItemIndex - 1);
    }

    if(edFilter->Text.Length() > 0)
        sql += " and Upper(Goods.Name) like '%" + (edFilter->Text.UpperCase()) + "%'";

    AnsiString sRet;
    SQL_exefun(DBName,sql.c_str(),&sRet);

    int cnt = atoi(sRet.c_str());

    if(cnt > 1)
        sgSells->RowCount = cnt + 1;

    sql = StringReplace(sql,"count(*)","Bills.CDate,Goods.Name,BillItems.BillItemsCount,BillItems.Total,Stars.StarsUser,FName,SName,TName",TReplaceFlags());
    SQL_exe(DBName,sql.c_str(),fill_fun);

    sgSells->Row = 1;

    sbSells->SimpleText = "  ИТОГО: " + AnsiString(TotalCount) + " шт., " + FormatFloat(MoneyFormat,TotalSum) + "руб.";
    sgSells->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TSellsForm::tbExitClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TSellsForm::dtpBegDateCloseUp(TObject *Sender)
{
    if(dtpBegDate->DateTime >= dtpEndDate->DateTime)
        dtpEndDate->DateTime = dtpBegDate->DateTime + 1;

    sgSellsFullUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TSellsForm::edFilterKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key == VK_RETURN && edFilter->Modified)
    {
        sgSellsFullUpdate();
        Key = 0;
    }
}
//---------------------------------------------------------------------------
void __fastcall TSellsForm::dtpEndDateCloseUp(TObject *Sender)
{
    if(dtpBegDate->DateTime >= dtpEndDate->DateTime)
        dtpBegDate->DateTime = dtpEndDate->DateTime - 1;

    sgSellsFullUpdate();
}
//---------------------------------------------------------------------------

