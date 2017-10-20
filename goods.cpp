//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "goods.h"
#include "lib.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TGoodsForm *GoodsForm;

extern const char *DBName;
extern const char *MoneyFormat;
extern const char *CountFormat;
extern int FormResult;

//***************************************************************************
//******************************* CALLBACKS *********************************
//***************************************************************************
static int fill_fun(void *NotUsed, int argc, char **argv, char **azColName)
{
    __int64 ID = _atoi64(argv[0]);

    if(!ID) return 0;

    double price = strtof(argv[2],2);
    int count = (argv[3])? atoi(argv[3]) : 0;

    if(GoodsForm->KassaMode)
    {

        if(count <= 0 || price <= 0.0)
        {
            if(GoodsForm->sgGoods->RowCount > 2)
                GoodsForm->sgGoods->RowCount--;
            return 0;
        }

        SQL_exefun(DBName,("select sum(BillItemsCount) from BillItems where BillID=0 and GoodID="+AnsiString(ID)).c_str(),&GoodsForm->SelSection);
        count -= atoi(GoodsForm->SelSection.c_str());

        if(count <= 0)
        {
            if(GoodsForm->sgGoods->RowCount > 2)
                GoodsForm->sgGoods->RowCount--;
            return 0;
        }
    }

    GoodsForm->pIDs[GoodsForm->GoodsCount++] = ID;

    GoodsForm->sgGoods->Cells[0][GoodsForm->GoodsCount] = (argv[1]);
    GoodsForm->sgGoods->Cells[1][GoodsForm->GoodsCount] = FormatFloat(MoneyFormat,price);

    int part = (argv[4])? atoi(argv[4]) : 0;
    double stock = part;
    stock = (stock / 1000.0) + count;

    GoodsForm->sgGoods->Cells[2][GoodsForm->GoodsCount] = FormatFloat(CountFormat,stock);

    return 0;
}
//---------------------------------------------------------------------------

//***************************************************************************
//*************************** END CALLBACKS *********************************
//***************************************************************************

//---------------------------------------------------------------------------
void __fastcall TGoodsForm::sgGoodsWindowProc(Messages::TMessage& Msg)
{
    bool done = Msg.Msg == WM_SIZE;

    if(Msg.Msg == WM_NCHITTEST || done)
    {
        int i;

        if(!done)
        {
            for(i = 0; i < sgGoods->ColCount; i++)
                if(sgGoods->ColWidths[i] != GoodsWidths[i]) break;
            done = i < sgGoods->ColCount;
        }

        if(done)
        {
            int sum_width = 0;

            for(i = 0; i < sgGoods->ColCount; i++)
            {
                if(sgGoods->ColWidths[i] < 16) sgGoods->ColWidths[i] = 16;
                sum_width += sgGoods->ColWidths[i];
            }

            int width = sgGoods->ClientWidth - sgGoods->ColCount;

            if(sum_width < width) sgGoods->ColWidths[sgGoods->ColCount-1] += (width - sum_width);
            else if(sum_width > width)
            {
                // Вылез за границы
                int w;

                for(i = sgGoods->ColCount - 1; i >= 0 && sum_width > width; i--)
                {
                    w = sgGoods->ColWidths[i];

                    sgGoods->ColWidths[i] -= (sum_width - width);
                    if(sgGoods->ColWidths[i] < 16)
                    {
                        sgGoods->ColWidths[i] = 16;
                        sum_width -= (w - 16);
                    }
                    else
                        break;
                }
            }

            for(i = 0; i < sgGoods->ColCount; i++)
                GoodsWidths[i] = sgGoods->ColWidths[i];
        }
    }

    if(Msg.Msg != WM_SIZE)
        sgOGoodsWindowProc(Msg);
}
//---------------------------------------------------------------------------
__fastcall TGoodsForm::TGoodsForm(TComponent* Owner)
    : TForm(Owner)
{
    pIDs = NULL;

    KassaMode = true;
    fldAlignGoods = "lrR";
}
//---------------------------------------------------------------------------
void __fastcall TGoodsForm::tbExitClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TGoodsForm::FormShow(TObject *Sender)
{
    cbSection->Items->Add("Бар");
    cbSection->Items->Add("Косметика");
    cbSection->Items->Add("Сопутствующие товары");

    cbSection->ItemIndex = 0;

    GoodsWidths = new int[sgGoods->ColCount];

    sgGoods->Cells[0][0] = "Товар";
    sgGoods->Cells[1][0] = "Цена";
    sgGoods->Cells[2][0] = "Остаток";

    sgGoods->ColWidths[0] = 240;
    sgGoods->ColWidths[1] = 100;

    sgGoods->ColWidths[2] = sgGoods->ClientWidth - sgGoods->ColWidths[0] - sgGoods->ColWidths[1] - sgGoods->ColCount;

    AnsiString sCount;

    SQL_BeginTransaction();

    if(KassaMode)
        SQL_exefun(DBName,"select count(*) from Stock inner join Goods on GoodID=Goods.RowID where ForSale=1 and Section=0",&sCount);
    else
        SQL_exefun(DBName,"select count(*) from Goods where Section=0",&sCount);


    GoodsCount = atoi(sCount.c_str());
    if(GoodsCount)
    {
        if(GoodsCount > 1)
            sgGoods->RowCount = GoodsCount + 1;

        pIDs = new __int64[GoodsCount];
        GoodsCount = 0;

        if(KassaMode)
            SQL_exe(DBName,"select Goods.RowID,Name,Price,StockCount,Part from Stock inner join Goods on GoodID=Goods.RowID where ForSale=1 and Section=0 order by Name",fill_fun);
        else
            SQL_exe(DBName,"select Goods.RowID,Name,Price,StockCount,Part from Goods left outer join Stock on GoodID=Goods.RowID where Section=0 order by Name",fill_fun);
    }

    SQL_CancelTransaction();

    sgOGoodsWindowProc = sgGoods->WindowProc;
    sgGoods->WindowProc = sgGoodsWindowProc;
}
//---------------------------------------------------------------------------
void __fastcall TGoodsForm::FormDestroy(TObject *Sender)
{
    delete [] pIDs;
}
//---------------------------------------------------------------------------
void __fastcall TGoodsForm::sgGoodsDrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
    if(State.Contains(gdFixed))
    {
        sgGoods->Canvas->Font->Style = TFontStyles() << fsBold;
        sgGoods->Canvas->Font->Color = HEADER_COLOR;

        sgGoods->Canvas->Brush->Color = clBtnFace;
        sgGoods->Canvas->FillRect(Rect);

        int lft = Rect.Width() - sgGoods->Canvas->TextWidth(sgGoods->Cells[ACol][0]);
        if(lft < 2) lft = 2;
        else lft >>= 1;
        sgGoods->Canvas->TextRect(Rect,Rect.left+lft,Rect.top+1,sgGoods->Cells[ACol][0]);
    }
    else
    {
        sgGoods->Canvas->Font->Style = TFontStyles();

        if(State.Contains(gdSelected))
        {
            sgGoods->Canvas->Brush->Color = SelColor;
            sgGoods->Canvas->FillRect(Rect);
        }
        else
        {
            sgGoods->Canvas->Brush->Color = clWhite;
            sgGoods->Canvas->FillRect(Rect);
        }

        sgGoods->Canvas->Font->Color = clBlack;
        sgAlignTextDraw(sgGoods,ACol,ARow,Rect,fldAlignGoods);
    }
}
//---------------------------------------------------------------------------
void __fastcall TGoodsForm::cbSectionSelect(TObject *Sender)
{
    AnsiString sCount;

    PDEL(pIDs);

    sgGoods->RowCount = 2;

    sgGoods->Cells[0][1] = "";
    sgGoods->Cells[1][1] = "";
    sgGoods->Cells[2][1] = "";

    SQL_BeginTransaction();

    if(KassaMode)
        SQL_exefun(DBName,("select count(*) from Stock inner join Goods on GoodID=Goods.RowID where ForSale=1 and Section="+AnsiString(cbSection->ItemIndex)).c_str(),&sCount);
    else
        SQL_exefun(DBName,("select count(*) from Goods where Section="+AnsiString(cbSection->ItemIndex)).c_str(),&sCount);
    GoodsCount = atoi(sCount.c_str());

    if(GoodsCount)
    {
        if(GoodsCount > 1)
            sgGoods->RowCount = GoodsCount + 1;

        pIDs = new __int64[GoodsCount];
        GoodsCount = 0;
        if(KassaMode)
            SQL_exe(DBName,("select Goods.RowID,Name,Price,StockCount,Part from Stock inner join Goods on GoodID=Goods.RowID where ForSale=1 and Section="+AnsiString(cbSection->ItemIndex)+" order by Name").c_str(),fill_fun);
        else
            SQL_exe(DBName,("select Goods.RowID,Name,Price,StockCount,Part from Goods left outer join Stock on GoodID=Goods.RowID where Section="+AnsiString(cbSection->ItemIndex)+" order by Name").c_str(),fill_fun);
    }

    SQL_CancelTransaction();
}
//---------------------------------------------------------------------------
void __fastcall TGoodsForm::sgGoodsDblClick(TObject *Sender)
{
    // Выбор товара
    if(KassaMode && sgGoods->Row > 0 && GoodsCount > 0)
    {
        // Вернуть ID товара, цену и остаток?
        SelID = pIDs[sgGoods->Row-1];
        SelName = sgGoods->Cells[0][sgGoods->Row];
        SelPrice = atof(sgGoods->Cells[1][sgGoods->Row].c_str());
        SelCount = atoi(sgGoods->Cells[2][sgGoods->Row].c_str());
        SelSection = cbSection->Items->Strings[cbSection->ItemIndex];

        FormResult = 1;
        Close();
    }
}
//---------------------------------------------------------------------------

