//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "goodsincome.h"
#include <math.h>
#include "lib.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TGoodsIncomeForm *GoodsIncomeForm;

extern const char *DBName;
extern __int64 UserID;

extern const char *MoneyFormat;
extern const char *CountFormat;
//---------------------------------------------------------------------------

//***************************************************************************
//******************************* CALLBACKS *********************************
//***************************************************************************

//---------------------------------------------------------------------------
static int docsfill_fun(void *NotUsed, int argc, char **argv, char **azColName)
{
    // select RowID,Closed,Date,Type from Docs

    if(!argv[0]) return 0;
    __int64 ID = _atoi64(argv[0]);

    if(!ID) return 0;

   GoodsIncomeForm->IDsDocs[GoodsIncomeForm->DocsCount++] = ID;

   if(argv[1])
        GoodsIncomeForm->sgDocs->Cells[0][GoodsIncomeForm->DocsCount] = (atoi(argv[1]))? " " : "";
    else
        GoodsIncomeForm->sgDocs->Cells[0][GoodsIncomeForm->DocsCount] = " ";

    //GoodsIncomeForm->sgDocs->Cells[3][GoodsIncomeForm->DocsCount] = (argv[1]);

    if(argv[2])
        GoodsIncomeForm->sgDocs->Cells[1][GoodsIncomeForm->DocsCount] = TDateTime(atof(argv[2])).DateTimeString();
    else
        GoodsIncomeForm->sgDocs->Cells[1][GoodsIncomeForm->DocsCount] = "";

    int type = atoi(argv[3]);
    switch(type)
    {
case 0:
        GoodsIncomeForm->sgDocs->Cells[2][GoodsIncomeForm->DocsCount] = "приход ";
        break;
case 1: GoodsIncomeForm->sgDocs->Cells[2][GoodsIncomeForm->DocsCount] = "закупка ";
        break;
default:
        GoodsIncomeForm->sgDocs->Cells[2][GoodsIncomeForm->DocsCount] = "неизвестный тип ";
    }

    return 0;
}
//---------------------------------------------------------------------------
static int fill_fun(void *NotUsed, int argc, char **argv, char **azColName)
{
    // select Goods.RowID,Name,Price,Count,Part from Goods

    GoodsIncomeForm->pGIDs[GoodsIncomeForm->GoodsCount++] = (argv[0])? _atoi64(argv[0]) : 0;

    GoodsIncomeForm->sgGoods->Cells[0][GoodsIncomeForm->GoodsCount] = (argv[1]);

    GoodsIncomeForm->sgGoods->Cells[1][GoodsIncomeForm->GoodsCount] = (argv[2])? FormatFloat(MoneyFormat,strtof(argv[2],2)) : AnsiString("0.00");

    double count = (argv[3])? atof(argv[3]) : 0.0;
    count += ((argv[4])? atof(argv[4]) / 1000.0 : 0.0);



    GoodsIncomeForm->sgGoods->Cells[2][GoodsIncomeForm->GoodsCount] = FormatFloat(CountFormat,count);

    GoodsIncomeForm->sgGoods->Cells[3][GoodsIncomeForm->GoodsCount] = atoi(argv[5])? "да" : "нет";

    return 0;
}
//---------------------------------------------------------------------------
static int fill_ifun(void *NotUsed, int argc, char **argv, char **azColName)
{
    // select Income.RowID,GoodID,Name,Count,Part from Income

    GoodsIncomeForm->pIDs[GoodsIncomeForm->GoodsIncomeCount] = (argv[0])? _atoi64(argv[0]) : 0;
    GoodsIncomeForm->ppGIDs[GoodsIncomeForm->GoodsIncomeCount++] = (argv[1])? _atoi64(argv[1]) : 0;

    GoodsIncomeForm->sgGoodsIncome->Cells[0][GoodsIncomeForm->GoodsIncomeCount] = (argv[2]);

    double x = (argv[4])? atof(argv[4]) : 0.0;
    x /= 1000.0;
    x += ((argv[3])? atof(argv[3]) : 0.0);

    GoodsIncomeForm->sgGoodsIncome->Cells[1][GoodsIncomeForm->GoodsIncomeCount] = FormatFloat(CountFormat,x);

    return 0;
}
//---------------------------------------------------------------------------

//***************************************************************************
//*************************** END CALLBACKS *********************************
//***************************************************************************

//---------------------------------------------------------------------------
void __fastcall TGoodsIncomeForm::sgDocsWindowProc(Messages::TMessage& Msg)
{
    bool done = Msg.Msg == WM_SIZE;

    if(Msg.Msg == WM_NCHITTEST || done)
    {
        int i;

        if(!done)
        {
            for(i = 0; i < sgDocs->ColCount; i++)
                if(sgDocs->ColWidths[i] != DocsWidths[i]) break;
            done = i < sgDocs->ColCount;
        }

        if(done)
        {
            int sum_width = 0;

            for(i = 0; i < sgDocs->ColCount; i++)
            {
                if(sgDocs->ColWidths[i] < 16) sgDocs->ColWidths[i] = 16;
                sum_width += sgDocs->ColWidths[i];
            }

            int width = sgDocs->ClientWidth - sgDocs->ColCount;

            if(sum_width < width) sgDocs->ColWidths[sgDocs->ColCount-1] += (width - sum_width);
            else if(sum_width > width)
            {
                // Вылез за границы
                int w;

                for(i = sgDocs->ColCount - 1; i >= 0 && sum_width > width; i--)
                {
                    w = sgDocs->ColWidths[i];

                    sgDocs->ColWidths[i] -= (sum_width - width);
                    if(sgDocs->ColWidths[i] < 16)
                    {
                        sgDocs->ColWidths[i] = 16;
                        sum_width -= (w - 16);
                    }
                    else
                        break;
                }
            }

            for(i = 0; i < sgDocs->ColCount; i++)
                DocsWidths[i] = sgDocs->ColWidths[i];
        }
    }

    if(Msg.Msg != WM_SIZE)
        sgODocsWindowProc(Msg);
}
//---------------------------------------------------------------------------
void __fastcall TGoodsIncomeForm::sgGoodsIncomeWindowProc(Messages::TMessage& Msg)
{
    bool done = Msg.Msg == WM_SIZE;

    if(Msg.Msg == WM_NCHITTEST || done)
    {
        int i;

        if(!done)
        {
            for(i = 0; i < sgGoodsIncome->ColCount; i++)
                if(sgGoodsIncome->ColWidths[i] != GoodsIncomeWidths[i]) break;
            done = i < sgGoodsIncome->ColCount;
        }

        if(done)
        {
            int sum_width = 0;

            for(i = 0; i < sgGoodsIncome->ColCount; i++)
            {
                if(sgGoodsIncome->ColWidths[i] < 16) sgGoodsIncome->ColWidths[i] = 16;
                sum_width += sgGoodsIncome->ColWidths[i];
            }

            int width = sgGoodsIncome->ClientWidth - sgGoodsIncome->ColCount;

            if(sum_width < width) sgGoodsIncome->ColWidths[sgGoodsIncome->ColCount-1] += (width - sum_width);
            else if(sum_width > width)
            {
                // Вылез за границы
                int w;

                for(i = sgGoodsIncome->ColCount - 1; i >= 0 && sum_width > width; i--)
                {
                    w = sgGoodsIncome->ColWidths[i];

                    sgGoodsIncome->ColWidths[i] -= (sum_width - width);
                    if(sgGoodsIncome->ColWidths[i] < 16)
                    {
                        sgGoodsIncome->ColWidths[i] = 16;
                        sum_width -= (w - 16);
                    }
                    else
                        break;
                }
            }

            for(i = 0; i < sgGoodsIncome->ColCount; i++)
                GoodsIncomeWidths[i] = sgGoodsIncome->ColWidths[i];
        }
    }

    if(Msg.Msg != WM_SIZE)
        sgOGoodsIncomeWindowProc(Msg);
}
//---------------------------------------------------------------------------
void __fastcall TGoodsIncomeForm::sgGoodsWindowProc(Messages::TMessage& Msg)
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
__fastcall TGoodsIncomeForm::TGoodsIncomeForm(TComponent* Owner)
    : TForm(Owner)
{
    IDsDocs = NULL;
    pIDs = NULL;
    ppGIDs = NULL;
    pGIDs = NULL;

    fldAlignDocs = "ccr";
    fldAlignGoodsIncome = "lR";
    fldAlignGoods = "lrRR";

    GoodsIncomeFocus = false;
    GoodsFocus = false;

    GoodsIncomeSave = true;

    DocID = 0;
}
//---------------------------------------------------------------------------
void __fastcall TGoodsIncomeForm::tbExitClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TGoodsIncomeForm::FormShow(TObject *Sender)
{
    UsersCounter = UserInit(DBName,&pUserIDs,&pUsers);
    //sbGoods->SimpleText = "ID: ";

    cbSection->Items->Add("Бар");
    cbSection->Items->Add("Косметика");
    cbSection->Items->Add("Сопутствующие товары");

    cbSection->ItemIndex = 0;

    DocsWidths = new int[sgDocs->ColCount];

    sgDocs->Cells[1][0] = "Дата";
    sgDocs->Cells[2][0] = "Тип";    // Приход, Закупка


    sgDocs->ColWidths[0] = DocsWidths[0] = 16;
    sgDocs->ColWidths[1] = DocsWidths[1] = 160;
    sgDocs->ColWidths[2] = DocsWidths[2] =
    sgDocs->ClientWidth - sgDocs->ColWidths[0] - sgDocs->ColWidths[1] - sgDocs->ColCount;

    GoodsWidths = new int[sgGoods->ColCount];

    sgGoods->Cells[0][0] = "Товар";
    sgGoods->Cells[1][0] = "Цена";
    sgGoods->Cells[2][0] = "В наличии";
    sgGoods->Cells[3][0] = "В продаже";

    sgGoods->ColWidths[0] = GoodsWidths[0] = 240;
    sgGoods->ColWidths[1] = GoodsWidths[1] = 120;
    sgGoods->ColWidths[2] = GoodsWidths[2] = 120;

    sgGoods->ColWidths[3] = GoodsWidths[3] =

    sgGoods->ClientWidth - sgGoods->ColWidths[0] - sgGoods->ColWidths[1] - sgGoods->ColWidths[2] - sgGoods->ColCount;

    GoodsIncomeWidths = new int[sgGoodsIncome->ColCount];

    sgGoodsIncome->Cells[0][0] = "Товар";
    sgGoodsIncome->Cells[1][0] = "Кол-во";

    sgGoodsIncome->ColWidths[0] = GoodsIncomeWidths[0] = 240;
    sgGoodsIncome->ColWidths[1] = GoodsIncomeWidths[1] = sgGoodsIncome->ClientWidth - sgGoodsIncome->ColWidths[0] - sgGoodsIncome->ColCount;

//    AnsiString sRet;
//    SQL_exefun(DBName,"select count(*) from Docs where Section=0",&sRet);
//    unsigned cnt = atoi(sRet.c_str());

//    if(cnt)
//    {
//        if(cnt > 1)
//            sgDocs->RowCount = cnt + 1;

//        IDsDocs = new __int64[cnt];

//        SQL_exe(DBName,"select RowID,Closed,Date,Type from Docs where Section=0 order by Date desc",docsfill_fun);
//        DocID = IDsDocs[0];
//    }

//    UpdateGoods();
//    UpdateGoodsIncome(DocID);

    sgODocsWindowProc = sgDocs->WindowProc;
    sgDocs->WindowProc = sgDocsWindowProc;

    sgOGoodsWindowProc = sgGoods->WindowProc;
    sgGoods->WindowProc = sgGoodsWindowProc;

    sgOGoodsIncomeWindowProc = sgGoodsIncome->WindowProc;
    sgGoodsIncome->WindowProc = sgGoodsIncomeWindowProc;

    FullUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TGoodsIncomeForm::UpdateGoods(void)
{
    AnsiString sCount;

    PDEL(pGIDs);

    GoodsCount = 0;


    sgGoods->Cells[0][1] = "";
    sgGoods->Cells[1][1] = "";
    sgGoods->Cells[2][1] = "";
    sgGoods->Cells[3][1] = "";
    GCurCol = 0;
    GCurRow = 1;
    GCurCell = "";
    sgGoods->RowCount = 2;
    char *s = "";
    if(cbForSale->Checked)
        s = " and ForSale=1 ";

    SQL_exefun(DBName,("select count(*) from Goods where Section="+AnsiString(cbSection->ItemIndex)+s).c_str(),&sCount);
    GoodsCount = atoi(sCount.c_str());

    GCurCol = 0;
    GCurRow = 1;
    GCurCell = sgGoods->Cells[GCurCol][GCurRow];

    sgGoods->Col = GCurCol;
    sgGoods->Row = GCurRow;

    if(GoodsCount)
    {
        pGIDs = new __int64[GoodsCount];
        if(GoodsCount > 1)
            sgGoods->RowCount = GoodsCount + 1;

        GoodsCount = 0;

        SQL_exe(DBName,("select Goods.RowID,Name,Price,StockCount,Part,ForSale from Goods left outer join Stock on Goods.RowID=GoodID where Section="+AnsiString(cbSection->ItemIndex)+s+"order by Name").c_str(),fill_fun);
        GCurCell = sgGoods->Cells[GCurCol][GCurRow];
    }
}
//---------------------------------------------------------------------------
void __fastcall TGoodsIncomeForm::UpdateGoodsIncome(__int64 ID)
{
    PDEL(pIDs);
    PDEL(ppGIDs);
    GoodsIncomeCount = 0;

    sgGoodsIncome->Cells[0][1] = "";
    sgGoodsIncome->Cells[1][1] = "";
    CurCol = 0;
    CurRow = 1;
    CurCell = "";
    sgGoodsIncome->RowCount = 2;


    //PDEL(pGIDs);
    //GoodsCount = 0;

    //sgGoods->RowCount = 2;
    //sgGoods->Cells[0][1] = "";
    //sgGoods->Cells[1][1] = "";
    //sgGoods->Cells[2][1] = "";
    //sgGoods->Cells[3][1] = "";
    //sgGoods->Cells[4][1] = "";

    if(!ID) return;

    AnsiString sCount;

    //SQL_exefun(DBName,"select count(*) from Goods",&sCount);
    //GoodsCount = atoi(sCount.c_str());

    //GCurCol = 0;
    //GCurRow = 1;
    //GCurCell = sgGoods->Cells[GCurCol][GCurRow];
    //sgGoods->Col = GCurCol;
    //sgGoods->Row = GCurRow;

    //if(GoodsCount)
    //{
    //    pGIDs = new __int64[GoodsCount];
    //    sgGoods->RowCount = GoodsCount + 1;
    //    GoodsCount = 0;


    //    SQL_exe(DBName,"select Goods.RowID,Name,Price,TradePrice,Divider,Count from Goods left outer join Stock on Goods.RowID=GoodID order by Name",fill_fun);

        //sgGoods->RowCount--;
    //}

    //SQL_exefun(DBName,"select max(Date) from Income",&sCount);
    //int date = atoi(sCount.c_str());

    //dtpIncome->DateTime = date;

    SQL_exefun(DBName,("select count(*) from Income where DocID="+AnsiString(DocID)).c_str(),&sCount);
    GoodsIncomeCount = atoi(sCount.c_str());

    CurCol = 0;
    CurRow = 1;
    CurCell = sgGoodsIncome->Cells[CurCol][CurRow];
    sgGoodsIncome->Col = CurCol;
    sgGoodsIncome->Row = CurRow;

    if(GoodsIncomeCount)
    {
        pIDs = new __int64[GoodsIncomeCount];
        ppGIDs = new __int64[GoodsIncomeCount];

        if(GoodsIncomeCount > 1)
            sgGoodsIncome->RowCount = GoodsIncomeCount + 1;

        GoodsIncomeCount = 0;
        SQL_exe(DBName,("select Income.RowID,GoodID,Name,IncomeCount,Part from Income left outer join Goods on GoodID=Goods.RowID where DocID="+AnsiString(DocID)+" order by Name").c_str(),fill_ifun);
        CurCell = sgGoodsIncome->Cells[CurCol][CurRow];

        if(ppGIDs && pGIDs)
        {
            unsigned i;
            for(i = 0; i < GoodsCount; i++)
                if(ppGIDs[CurRow-1] == pGIDs[i]) break;

            if(i < GoodsCount)
            {
                GCurCol = 0;
                GCurRow = i + 1;
                GCurCell = sgGoods->Cells[GCurCol][GCurRow];
                sgGoods->Col = GCurCol;
                sgGoods->Row = GCurRow;
            }
        }
    }

}
//---------------------------------------------------------------------------
void __fastcall TGoodsIncomeForm::FormDestroy(TObject *Sender)
{
    delete [] IDsDocs;
    delete [] pIDs;
    delete [] ppGIDs;
    delete [] pGIDs;

    delete [] DocsWidths;
    delete [] GoodsIncomeWidths;
    delete [] GoodsWidths;

    delete [] pUserIDs;
    delete [] pUsers;
}
//---------------------------------------------------------------------------
void __fastcall TGoodsIncomeForm::sgGoodsIncomeSelectCell(TObject *Sender,
      int ACol, int ARow, bool &CanSelect)
{
    static bool running = false;

    if(running) return;

    running = true;

    if(sgGoodsIncome->Col != ACol)
        sgGoodsIncome->Col = ACol;

    if(sgGoodsIncome->Row != ARow)
        sgGoodsIncome->Row = ARow;

    if(GoodsIncomeFocus && ACol == 1 && sgDocs->Cells[0][sgDocs->Row] == "")
    {
        sgGoodsIncome->Options = sgGoodsIncome->Options >> goRowSelect;
        sgGoodsIncome->Options = sgGoodsIncome->Options << goEditing;
        sgGoodsIncome->Options = sgGoodsIncome->Options << goAlwaysShowEditor;

        if(sgGoodsIncome->Focused())
            sgGoodsIncome->EditorMode = true;
    }
    else
    {
        sgGoodsIncome->Options = sgGoodsIncome->Options >> goAlwaysShowEditor;
        sgGoodsIncome->Options = sgGoodsIncome->Options >> goEditing;
        sgGoodsIncome->Options = sgGoodsIncome->Options << goRowSelect;
    }

    if(sgGoodsIncome->Cells[CurCol][CurRow] != CurCell && pIDs && GoodsIncomeSave)
    {
        double count = strtof(sgGoodsIncome->Cells[1][CurRow].c_str(),3);
        sgGoodsIncome->Cells[1][CurRow] = FormatFloat(CountFormat,count);

        //double dt = (double)Now();

        int part = strtof(AnsiString(1000.0 * modf(count,&count)).c_str(),0);



        SQL_iniUpdate(DBName,"Income",pIDs[CurRow-1]);
        double d = atof(sgGoods->Cells[1][sgGoods->Row].c_str());
        SQL_addUpdate("Price",d);
        SQL_addUpdate("Total",d * ((int)count + (part / 1000)));
        SQL_addUpdate("IncomeCount",(int)count);
        SQL_exeUpdate("Part",part);
    }

    CurCol = ACol;
    CurRow = ARow;
    CurCell = sgGoodsIncome->Cells[CurCol][CurRow];

    if(GoodsIncomeFocus && ppGIDs && pGIDs)
    {
        unsigned i;
        for(i = 0; i < GoodsCount; i++)
            if(ppGIDs[CurRow-1] == pGIDs[i]) break;

        if(i < GoodsCount)
        {
            GCurCol = 0;
            GCurRow = i + 1;

            GCurCell = sgGoods->Cells[GCurCol][GCurRow];
            sgGoods->Col = GCurCol;
            sgGoods->Row = GCurRow;


            sgGoods->Repaint();
        }
    }

    sgGoodsIncome->Repaint();

    running = false;
}
//---------------------------------------------------------------------------
void __fastcall TGoodsIncomeForm::ToolButton1Click(TObject *Sender)
{
    sgDocs->SetFocus();
    //sgGoodsIncome->SetFocus();

    // Перенесем справа позицию, если нет
    if(GoodsCount && DocID && sgDocs->Cells[0][sgDocs->Row] == "")
    {
        __int64 ID = pGIDs[sgGoods->Row-1];
        unsigned i;

        for(i = 0; i < GoodsIncomeCount; i++)
            if(ID == ppGIDs[i]) break;

        if(i < GoodsIncomeCount) return;

        __int64 *pNewIDs = new __int64[++GoodsIncomeCount];

        memcpy(pNewIDs,ppGIDs,sizeof(__int64)*(GoodsIncomeCount-1));
        pNewIDs[GoodsIncomeCount-1] = ID;
        delete [] ppGIDs;

        ppGIDs = pNewIDs;

        pNewIDs = new __int64[GoodsIncomeCount];

        memcpy(pNewIDs,pIDs,sizeof(__int64)*(GoodsIncomeCount-1));

        delete [] pIDs;

        pIDs = pNewIDs;

        //double dt = (double)Now();

        SQL_iniInsert(DBName,"Income",&pIDs[GoodsIncomeCount-1]);
        SQL_addInsert("GoodID",ID);
        SQL_addInsert("DocID",DocID);
        double d = atof(sgGoods->Cells[1][sgGoods->Row].c_str());
        SQL_addInsert("Price",d);
        SQL_addInsert("Total",d);
        SQL_exeInsert("IncomeCount",1);

        CurCol = 0;
        CurRow = 1;
        CurCell = sgGoodsIncome->Cells[0][1];

        if(GoodsIncomeCount > 1)
        {
            sgGoodsIncome->RowCount++;
            CurRow = sgGoodsIncome->RowCount - 1;
        }
        else
            CurRow = 1;

        sgGoodsIncome->Cells[0][CurRow] = sgGoods->Cells[0][sgGoods->Row];
        sgGoodsIncome->Cells[1][CurRow] = "1";

        CurCell = sgGoodsIncome->Cells[1][CurRow];

        sgGoodsIncome->Row = CurRow;
        sgGoodsIncome->Col = 1;

    }
}
//---------------------------------------------------------------------------
void __fastcall TGoodsIncomeForm::sgGoodsSelectCell(TObject *Sender,
      int ACol, int ARow, bool &CanSelect)
{
    static bool running = false;


    if(running) return;

    running = true;

    if(sgGoods->Col != ACol)
        sgGoods->Col = ACol;

    if(sgGoods->Row != ARow)
        sgGoods->Row = ARow;


    
    if(GoodsFocus && ACol < 2)
    {
        sgGoods->Options = sgGoods->Options >> goRowSelect;
        sgGoods->Options = sgGoods->Options << goEditing;
        sgGoods->Options = sgGoods->Options << goAlwaysShowEditor;
    }
    else
    {
        sgGoods->Options = sgGoods->Options >> goAlwaysShowEditor;
        sgGoods->Options = sgGoods->Options >> goEditing;
        sgGoods->Options = sgGoods->Options << goRowSelect;
    }

    if(sgGoods->Cells[GCurCol][GCurRow] != GCurCell)
    {
        if(!GoodsCount )
        {
            // 1-ая запись
            sgGoods->Cells[1][1] = FormatFloat(MoneyFormat,strtof(sgGoods->Cells[1][1].c_str(),2));
            //sgGoods->Cells[2][1] = atoi(sgGoods->Cells[2][1].c_str());

            //double dt = (double)Now();

            SQL_iniInsert(DBName,"Goods");
            SQL_addInsert("#Name",sgGoods->Cells[0][1]);
            SQL_addInsert("Price",sgGoods->Cells[1][1]);
            SQL_exeInsert("Section",cbSection->ItemIndex);



        }
        else
        {
            sgGoods->Cells[1][GCurRow] = FormatFloat(MoneyFormat,strtof(sgGoods->Cells[1][GCurRow].c_str(),2));

            //sgGoods->Cells[3][GCurRow] = atoi(sgGoods->Cells[3][GCurRow].c_str());

            //double dt = (double)Now();
             __int64 ID = pGIDs[GCurRow-1];

            SQL_iniUpdate(DBName,"Goods",ID);
            SQL_addUpdate("#Name",sgGoods->Cells[0][GCurRow]);
            SQL_exeUpdate("Price",sgGoods->Cells[1][GCurRow]);

            unsigned i;

            for(i = 0; i < GoodsIncomeCount; i++)
                if(ID == ppGIDs[i]) break;

            if(i < GoodsIncomeCount)
                sgGoodsIncome->Cells[0][i+1] = sgGoods->Cells[0][GCurRow];

        }
    }

    GCurCol = ACol;
    GCurRow = ARow;
    GCurCell = sgGoods->Cells[GCurCol][GCurRow];

    // Где фокус?
    if(GoodsFocus && ppGIDs && pGIDs)
    {
        unsigned i;
        for(i = 0; i < GoodsIncomeCount; i++)
            if(ppGIDs[i] == pGIDs[GCurRow-1]) break;

        if(i < GoodsIncomeCount)
        {
            CurCol = 0;
            CurRow = i + 1;

            CurCell = sgGoods->Cells[CurCol][CurRow];
            sgGoodsIncome->Col = CurCol;
            sgGoodsIncome->Row = CurRow;


            sgGoodsIncome->Repaint();
        }


    }

    sgGoods->Repaint();

    running = false;
}
//---------------------------------------------------------------------------
void __fastcall TGoodsIncomeForm::sgGoodsEnter(TObject *Sender)
{
    GoodsFocus = true;

    //sgGoods->Options = sgGoods->Options >> goRowSelect;
    //sgGoods->Options = sgGoods->Options << goEditing;
    //sgGoods->Options = sgGoods->Options << goAlwaysShowEditor;



    //sgGoods->Repaint();


    //mouse_event
    //TPoint pos;
    //GetCursorPos(&pos);
    //pos=ClientToScreen(pos);
    //pos=ScreenToClient(Form1->Handle, &pos);
    //Edit1->Text=IntToStr(pos.x) + " / " + IntToStr(pos.y);

    //BitBtn1->Left=pos.x;
    //BitBtn1->Top=pos.y;
    //mouse_event(MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_LEFTDOWN, pos.x, pos.y, 0, 0); // нажали
    //mouse_event(MOUSEEVENTF_ABSOLUTE|MOUSEEVENTF_LEFTUP, pos.x, pos.y, 0, 0); //отпустили
    //PostMessage(sgGoods->Handle,WM_LBUTTONDOWN,MK_LBUTTON,0);
}
//---------------------------------------------------------------------------
void __fastcall TGoodsIncomeForm::sgGoodsExit(TObject *Sender)
{
    if(sgGoods->Cells[GCurCol][GCurRow] != GCurCell)
    {
        if(!GoodsCount)
        {
            // 1-ая запись
            sgGoods->Cells[1][1] = FormatFloat(MoneyFormat,strtof(sgGoods->Cells[1][1].c_str(),2));

            SQL_iniInsert(DBName,"Goods");
            SQL_addInsert("#Name",sgGoods->Cells[0][1]);
            SQL_addInsert("Price",sgGoods->Cells[1][1]);
            SQL_exeInsert("Section",cbSection->ItemIndex);
        }
        else
        {
            sgGoods->Cells[1][GCurRow] = FormatFloat(MoneyFormat,strtof(sgGoods->Cells[1][GCurRow].c_str(),2));

             __int64 ID = pGIDs[GCurRow-1];

            SQL_iniUpdate(DBName,"Goods",ID);
            SQL_addUpdate("#Name",sgGoods->Cells[0][GCurRow]);
            SQL_exeUpdate("Price",sgGoods->Cells[1][GCurRow]);

            unsigned i;

            for(i = 0; i < GoodsIncomeCount; i++)
                if(ID == ppGIDs[i]) break;

            if(i < GoodsIncomeCount)
                sgGoodsIncome->Cells[0][i+1] = sgGoods->Cells[0][GCurRow];

        }
    }

    GoodsFocus = false;

    sgGoods->Options = sgGoods->Options >> goAlwaysShowEditor;
    sgGoods->Options = sgGoods->Options >> goEditing;
    sgGoods->Options = sgGoods->Options << goRowSelect;

    sgGoods->Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TGoodsIncomeForm::sgGoodsDrawCell(TObject *Sender,
      int ACol, int ARow, TRect &Rect, TGridDrawState State)
{
    sgGoods->Canvas->Font->Name = "Verdana";
    sgGoods->Canvas->Font->Size = 10;

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

        if(State.Contains(gdSelected) || ARow == sgGoods->Row)
        {
            sgGoods->Canvas->Brush->Color = SelColor;
            //SEL_COLOR;
            Rect.right++;
            sgGoods->Canvas->FillRect(Rect);
            Rect.right--;
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
void __fastcall TGoodsIncomeForm::sgGoodsGetEditText(TObject *Sender,
      int ACol, int ARow, AnsiString &Value)
{
    sgGoods->Row = ARow;
    sgGoods->Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TGoodsIncomeForm::sgGoodsIncomeDrawCell(TObject *Sender,
      int ACol, int ARow, TRect &Rect, TGridDrawState State)
{
    sgGoodsIncome->Canvas->Font->Name = "Verdana";
    sgGoodsIncome->Canvas->Font->Size = 10;

    if(State.Contains(gdFixed))
    {
        sgGoodsIncome->Canvas->Font->Style = TFontStyles() << fsBold;
        sgGoodsIncome->Canvas->Font->Color = HEADER_COLOR;

         sgGoodsIncome->Canvas->Brush->Color = clBtnFace;
         sgGoodsIncome->Canvas->FillRect(Rect);

        int lft = Rect.Width() - sgGoodsIncome->Canvas->TextWidth(sgGoodsIncome->Cells[ACol][0]);
        if(lft < 2) lft = 2;
        else lft >>= 1;
        sgGoodsIncome->Canvas->TextRect(Rect,Rect.left+lft,Rect.top+1,sgGoodsIncome->Cells[ACol][0]);
    }
    else
    {
        sgGoodsIncome->Canvas->Font->Style = TFontStyles();

        if(State.Contains(gdSelected) || ARow == sgGoodsIncome->Row)
        {
            sgGoodsIncome->Canvas->Brush->Color = SelColor;
            //SEL_COLOR;
            Rect.right++;
            sgGoodsIncome->Canvas->FillRect(Rect);
            Rect.right--;
        }
        else
        {

            sgGoodsIncome->Canvas->Brush->Color = clWhite;
            sgGoodsIncome->Canvas->FillRect(Rect);
        }

        sgGoodsIncome->Canvas->Font->Color = clBlack;
        sgAlignTextDraw(sgGoodsIncome,ACol,ARow,Rect,fldAlignGoodsIncome);
    }
}
//---------------------------------------------------------------------------
void __fastcall TGoodsIncomeForm::sgGoodsIncomeEnter(TObject *Sender)
{
    GoodsIncomeFocus = true;

    //sgGoodsIncome->Options = sgGoodsIncome->Options >> goRowSelect;
    //sgGoodsIncome->Options = sgGoodsIncome->Options << goEditing;
    //sgGoodsIncome->Options = sgGoodsIncome->Options << goAlwaysShowEditor;

    //sgGoodsIncome->Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TGoodsIncomeForm::sgGoodsIncomeGetEditText(TObject *Sender,
      int ACol, int ARow, AnsiString &Value)
{
    sgGoodsIncome->Row = ARow;
    sgGoodsIncome->Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TGoodsIncomeForm::ToolButton3Click(TObject *Sender)
{
    // Новый товар

    sgDocs->SetFocus();
    //sgGoods->SetFocus();

    GCurCol = 0;
    GCurRow = 1;
    GCurCell = sgGoods->Cells[0][1];

    if(GoodsCount)
    {
        sgGoods->RowCount++;
        GCurRow = sgGoods->RowCount - 1;
    }

    GCurCell = "новый товар";

    sgGoods->Cells[0][GCurRow] = GCurCell;
    sgGoods->Cells[1][GCurRow] = "0.00";
    //FormatFloat(MoneyFormat,strtof(sgGoods->Cells[1][GCurRow].c_str(),2));
    //sgGoods->Cells[2][GCurRow] = atoi(sgGoods->Cells[2][GCurRow].c_str());
    sgGoods->Cells[2][GCurRow] = "0";

    __int64 ID;
    //double dt = (double)Now();

    SQL_iniInsert(DBName,"Goods",&ID);
    SQL_addInsert("#Name",sgGoods->Cells[0][GCurRow]);
    SQL_addInsert("Price",sgGoods->Cells[1][GCurRow]);
    //SQL_addInsert("TradePrice",sgGoods->Cells[2][GCurRow]);
    //SQL_addInsert("Divider",sgGoods->Cells[3][GCurRow]);
    //SQL_addInsert("CDate",dt);
    //SQL_addInsert("CUID",UserID);
    SQL_addInsert("ForSale",1);
    if(SQL_exeInsert("Section",cbSection->ItemIndex) == SQLITE_OK)
    //if(SQL_exeInsert("EUID",UserID) == SQLITE_OK)
    {
        __int64 *pNewIDs = new __int64[++GoodsCount];

        memcpy(pNewIDs,pGIDs,sizeof(__int64)*(GoodsCount-1));
        pNewIDs[GoodsCount-1] = ID;
        delete [] pGIDs;

        pGIDs = pNewIDs;

    }

    sgGoods->Col = GCurCol;
    sgGoods->Row = GCurRow;

    sgGoods->Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TGoodsIncomeForm::sgGoodsIncomeExit(TObject *Sender)
{
   if(sgGoodsIncome->Cells[CurCol][CurRow] != CurCell && pIDs && GoodsIncomeSave)
    {
        double count = strtof(sgGoodsIncome->Cells[1][CurRow].c_str(),3);

        sgGoodsIncome->Cells[1][CurRow] = FormatFloat(CountFormat,count);
        int part = strtof(AnsiString(1000.0 * modf(count,&count)).c_str(),0);
        //int ipart = part;

        SQL_iniUpdate(DBName,"Income",pIDs[CurRow-1]);
        double d = atof(sgGoods->Cells[1][sgGoods->Row].c_str());
        SQL_addUpdate("Price",d);
        SQL_addUpdate("Total",d * ((int)count + (part / 1000)));
        SQL_addUpdate("IncomeCount",(int)count);
        SQL_exeUpdate("Part",part);
    }

    GoodsIncomeFocus = false;

    sgGoodsIncome->Options = sgGoodsIncome->Options >> goAlwaysShowEditor;
    sgGoodsIncome->Options = sgGoodsIncome->Options >> goEditing;
    sgGoodsIncome->Options = sgGoodsIncome->Options << goRowSelect;

    sgGoodsIncome->Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TGoodsIncomeForm::ToolButton5Click(TObject *Sender)
{
    sgDocs->SetFocus();

    // Удалить позицию слева
    if(GoodsIncomeCount && sgGoodsIncome->Row > 0 && pIDs && ppGIDs && sgDocs->Cells[0][sgDocs->Row] == "")
    {
        // Сдвиг вверх
        SQL_BeginTransaction();
        SQL_exe(DBName,("delete from Income where RowID="+AnsiString(pIDs[sgGoodsIncome->Row-1])).c_str());
        SQL_CommitTransaction();

        int cnt = sgGoodsIncome->RowCount - sgGoodsIncome->Row - 1;

        for(int i = 0; i < cnt; i++)
        {
            pIDs[sgGoodsIncome->Row-1+i] = pIDs[sgGoodsIncome->Row+i];
            pGIDs[sgGoodsIncome->Row-1+i] = pGIDs[sgGoodsIncome->Row+i];
            
            sgGoodsIncome->Rows[sgGoodsIncome->Row+i] = sgGoodsIncome->Rows[sgGoodsIncome->Row+i+1];
        }

        if(cnt <= 0 && GoodsIncomeCount == 1)
        {
            PDEL(pIDs);
            PDEL(ppGIDs);

            for(int j = 0; j < sgGoodsIncome->ColCount; j++)
                sgGoodsIncome->Cells[j][1] = "";

        }

        GoodsIncomeCount--;
        GoodsIncomeSave = false;

        if(GoodsIncomeCount > 0)
            sgGoodsIncome->RowCount--;

        GoodsIncomeSave = true;
    }

    //sgGoodsIncome->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TGoodsIncomeForm::sgDocsDrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
    if(State.Contains(gdFixed))
    {
        sgDocs->Canvas->Font->Style = TFontStyles() << fsBold;
        sgDocs->Canvas->Font->Color = HEADER_COLOR;

        int lft = Rect.Width() - sgDocs->Canvas->TextWidth(sgDocs->Cells[ACol][0]);
        if(lft < 2) lft = 2;
        else lft >>= 1;
        sgDocs->Canvas->TextRect(Rect,Rect.left+lft,Rect.top+1,sgDocs->Cells[ACol][0]);
    }
    else
    {
        if(State.Contains(gdSelected))
        {
            sgDocs->Canvas->Brush->Color = SelColor;
            //SEL_COLOR;
            sgDocs->Canvas->FillRect(Rect);
        }
        else
        {
            sgDocs->Canvas->Brush->Color = clWhite;
            sgDocs->Canvas->FillRect(Rect);
        }

        if(ACol == 0)
        {
            if(IDsDocs)
            {

                if((sgDocs->Cells[ACol][ARow]).Length() == 0)
                    ilDocs->Draw(sgDocs->Canvas,Rect.left,Rect.top,0);
                else if(sgDocs->Cells[ACol][ARow] == "\t")
                    ilDocs->Draw(sgDocs->Canvas,Rect.left,Rect.top,2);
                else
                    ilDocs->Draw(sgDocs->Canvas,Rect.left,Rect.top,1);
            }
        }
        else
        {
            sgDocs->Canvas->Font->Color = clBlack;
            sgAlignTextDraw(sgDocs,ACol,ARow,Rect,fldAlignDocs);
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TGoodsIncomeForm::ToolButton9Click(TObject *Sender)
{
    // Новый документ прихода
    sgDocs->SetFocus();

    double dt = (double)Now();

    SQL_iniInsert(DBName,"Docs",&DocID);
    SQL_addInsert("Section",cbSection->ItemIndex);
    SQL_addInsert("DocsDate",dt);
    SQL_addInsert("CDate",dt);
    SQL_addInsert("EDate",dt);
    SQL_addInsert("CUID",UserID);
    SQL_exeInsert("EUID",UserID);

    // Обновить данные
    if(!DocsCount)
    {
        IDsDocs = new __int64[1];
        IDsDocs[0] = DocID;
        sgDocs->Cells[1][1] = TDateTime(dt).DateTimeString();
        sgDocs->Cells[2][1] = "приход ";

        DocsCount++;
    }
    else
    {
        __int64 *newIDsDocs = new __int64[DocsCount+1];

        memcpy(&newIDsDocs[1],IDsDocs,sizeof(__int64)*DocsCount);
        newIDsDocs[0] = DocID;
        delete [] IDsDocs;
        IDsDocs = newIDsDocs;

        sgDocs->RowCount++;

        for(unsigned i = 0; i < DocsCount; i++)
            sgDocs->Rows[DocsCount-i+1] = sgDocs->Rows[DocsCount-i];

        sgDocs->Cells[0][1] = "";
        sgDocs->Cells[1][1] = TDateTime(dt).DateTimeString();
        sgDocs->Cells[2][1] = "приход ";

        DocsCount++;
    }

    sgDocs->Repaint();

    UpdateGoodsIncome(DocID);
    UpdateStatus();
}
//---------------------------------------------------------------------------
void __fastcall TGoodsIncomeForm::sgDocsSelectCell(TObject *Sender,
      int ACol, int ARow, bool &CanSelect)
{
    if(ARow != sgDocs->Row && IDsDocs && ARow > 0)
    {
        DocID = IDsDocs[ARow-1];
        UpdateGoodsIncome(DocID);
        UpdateStatus();
    }
}
//---------------------------------------------------------------------------
void __fastcall TGoodsIncomeForm::tbCloseClick(TObject *Sender)
{
    // Нельзя закрыть
    sgDocs->SetFocus();

    if(DocID && sgDocs->Cells[0][sgDocs->Row] == "")
    {
        if(SQL_BeginTransaction() != SQLITE_OK)
            return;

        SQL_iniUpdate(DBName,"Docs",DocID);
        SQL_addUpdate("EDate",(double)Now());
        SQL_addUpdate("EUID",UserID);
        SQL_exeUpdate("Closed",1);

        sgDocs->Cells[0][sgDocs->Row] = " ";

        sgDocs->Repaint();

        // И пересчет остатков
        AnsiString sCount, sPart;
        int count, part;
        int count2, part2;

        SQL_exe(DBName,"delete from Stock where (StockCount=0 and Part=0) or GoodID=0");

        for(unsigned i = 0; i < GoodsIncomeCount; i++)
        {
            SQL_exefun2(DBName,("select IncomeCount,Part from Income where RowID="+AnsiString(pIDs[i])).c_str(),&sCount,&sPart);
            count = atoi(sCount.c_str());
            part = atoi(sPart.c_str());

            if(count || part)
            {
                SQL_exefun2(DBName,("select StockCount,Part from Stock where GoodID="+AnsiString(ppGIDs[i])).c_str(),&sCount,&sPart);
                count2 = atoi(sCount.c_str());
                part2 = atoi(sPart.c_str());

                if(count2 || part2)
                {
                    count2 = ((count2 + count) * 1000) + part + part2;
                    part2 = count2 % 1000;
                    count2 = count2 / 1000;
                    SQL_exe(DBName,("update Stock set StockCount="+AnsiString(count2)+",Part="+AnsiString(part2)+" where GoodID="+AnsiString(ppGIDs[i])).c_str());
                }
                else
                {
                    SQL_iniInsert(DBName,"Stock");
                    SQL_addInsert("GoodID",ppGIDs[i]);
                    SQL_addInsert("StockCount",count);
                    SQL_exeInsert("Part",part);
                }
            }
        }

        SQL_CommitTransaction();

        PDEL(pGIDs);
        UpdateGoods();
    }
}
//---------------------------------------------------------------------------
void __fastcall TGoodsIncomeForm::tbReloadClick(TObject *Sender)
{
    sgDocs->SetFocus();

    if(DocID && sgDocs->Cells[0][sgDocs->Row] == "")
    {
        UpdateGoods();
        UpdateGoodsIncome(DocID);
    }
    else
        UpdateGoods();
}
//---------------------------------------------------------------------------
void __fastcall TGoodsIncomeForm::cbSectionSelect(TObject *Sender)
{
    FullUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TGoodsIncomeForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    sgDocs->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TGoodsIncomeForm::ToolButton4Click(TObject *Sender)
{
    // Удалить незакрытый приход
    sgDocs->SetFocus();

    if(DocID && sgDocs->Cells[0][sgDocs->Row] == "")
    {
        SQL_BeginTransaction();
        SQL_exe(DBName,("delete from Income where DocID="+AnsiString(DocID)).c_str());
        SQL_exe(DBName,("delete from Docs where RowID="+AnsiString(DocID)).c_str());
        SQL_CommitTransaction();

        FullUpdate();
    }
}
//---------------------------------------------------------------------------
void __fastcall TGoodsIncomeForm::ToolButton8Click(TObject *Sender)
{
    // Удалить товар
    sgDocs->SetFocus();

    if(GoodsCount)
    {
        AnsiString sItems;
        SQL_exefun(DBName,("select count(*) from BillItems where GoodID="+AnsiString(pGIDs[sgGoods->Row-1])).c_str(),&sItems);
        if(atoi(sItems.c_str()) != 0)
        {
            Application->MessageBox(("Внимание!\nНевозможно удалить товар \""+sgGoods->Cells[0][sgGoods->Row]+"\" так как по нему проводились продажи.").c_str(),"",MB_OK);
            return;
        }

        SQL_BeginTransaction();
        SQL_exe(DBName,("delete from Stock where GoodID="+AnsiString(pGIDs[sgGoods->Row-1])).c_str());
        SQL_exe(DBName,("delete from Income where GoodID="+AnsiString(pGIDs[sgGoods->Row-1])).c_str());
        SQL_exe(DBName,("delete from Goods where RowID="+AnsiString(pGIDs[sgGoods->Row-1])).c_str());
        SQL_CommitTransaction();

        FullUpdate();
    }
}
//---------------------------------------------------------------------------
void __fastcall TGoodsIncomeForm::FullUpdate(void)
{
    AnsiString sRet;

    PDEL(IDsDocs);
    DocsCount = 0;
    DocID = 0;

    sgDocs->RowCount = 2;
    sgDocs->Cells[0][1] = "";
    sgDocs->Cells[1][1] = "";
    sgDocs->Cells[2][1] = "";

    SQL_exefun(DBName,("select count(*) from Docs where Section="+AnsiString(cbSection->ItemIndex)).c_str(),&sRet);
    unsigned cnt = atoi(sRet.c_str());

    if(cnt)
    {
        if(cnt > 1)
            sgDocs->RowCount = cnt + 1;

        IDsDocs = new __int64[cnt];

        SQL_exe(DBName,("select RowID,Closed,DocsDate,Type from Docs where Section="+AnsiString(cbSection->ItemIndex)+" order by DocsDate desc").c_str(),docsfill_fun);
        DocID = IDsDocs[0];
    }

    UpdateGoods();
    UpdateGoodsIncome(DocID);

    UpdateStatus();
}
//---------------------------------------------------------------------------
void __fastcall TGoodsIncomeForm::UpdateStatus(void)
{
    if(DocID)
    {
        AnsiString s1, s2;
        TDateTime CDate, EDate;
        __int64 CUID, EUID;

        SQL_exefun2(DBName,("select CDate,EDate from Docs where RowID="+AnsiString(DocID)).c_str(),&s1,&s2);
        CDate = atof(s1.c_str());
        EDate = atof(s2.c_str());

        SQL_exefun2(DBName,("select CUID,EUID from Docs where RowID="+AnsiString(DocID)).c_str(),&s1,&s2);
        CUID = _atoi64(s1.c_str());
        EUID = _atoi64(s2.c_str());

        AnsiString status = "ID: " + (AnsiString)DocID;

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

        sbGoods->SimpleText = status;
    }
    else
        sbGoods->SimpleText = "ID: ";
}
//---------------------------------------------------------------------------
void __fastcall TGoodsIncomeForm::ToolButton10Click(TObject *Sender)
{
    sgDocs->SetFocus();

    // Изменить статус товара

    if(GoodsCount)
    {
        __int64 ID = pGIDs[sgGoods->Row-1];

        SQL_iniUpdate(DBName,"Goods",ID);

        int status = (sgGoods->Cells[3][sgGoods->Row] == "да")? 0 : 1;
        sgGoods->Cells[3][sgGoods->Row] = (status)? "да" : "нет";

        SQL_exeUpdate("ForSale",status);
    }
}
//---------------------------------------------------------------------------
void __fastcall TGoodsIncomeForm::cbForSaleClick(TObject *Sender)
{
    UpdateGoods();
}
//---------------------------------------------------------------------------

