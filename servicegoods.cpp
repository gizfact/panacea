//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "servicegoods.h"
#include "lib.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TServiceGoodsForm *ServiceGoodsForm;

extern const char *DBName;
//extern __int64 UserID;

extern const char *MoneyFormat;
//---------------------------------------------------------------------------

//***************************************************************************
//******************************* CALLBACKS *********************************
//***************************************************************************

//---------------------------------------------------------------------------
static int servicesfill_fun(void *NotUsed, int argc, char **argv, char **azColName)
{
    // select RowID,Name,PersonPrice,Price,Timed from Services

    if(!argv[0]) return 0;
    __int64 ID = _atoi64(argv[0]);

    if(!ID) return 0;

    ServiceGoodsForm->IDsServices[ServiceGoodsForm->ServicesCount++] = ID;

    ServiceGoodsForm->sgServices->Cells[0][ServiceGoodsForm->ServicesCount] = (argv[1]);

    double pprice = ATOF(argv[2]);

    ServiceGoodsForm->sgServices->Cells[1][ServiceGoodsForm->ServicesCount] = FormatFloat(MoneyFormat,pprice);

    double gprice = ATOF(argv[3]) - pprice;

    ServiceGoodsForm->sgServices->Cells[2][ServiceGoodsForm->ServicesCount] = FormatFloat(MoneyFormat,gprice);
    ServiceGoodsForm->sgServices->Cells[3][ServiceGoodsForm->ServicesCount] = FormatFloat(MoneyFormat,pprice+gprice);
    ServiceGoodsForm->sgServices->Cells[4][ServiceGoodsForm->ServicesCount] = ATOI(argv[4]);

    return 0;
}
//---------------------------------------------------------------------------
static int servicegoodsfill_fun(void *NotUsed, int argc, char **argv, char **azColName)
{
    //  select ServiceGoods.RowID,Name,ServiceGoods.Price,Rate from ServiceGoods

    if(!argv[0]) return 0;
    __int64 ID = _atoi64(argv[0]);

    if(!ID) return 0;

    ServiceGoodsForm->IDsServiceGoods[ServiceGoodsForm->ServiceGoodsCount++] = ID;

    ServiceGoodsForm->sgServiceGoods->Cells[0][ServiceGoodsForm->ServiceGoodsCount] = (argv[1]);

    ServiceGoodsForm->sgServiceGoods->Cells[1][ServiceGoodsForm->ServiceGoodsCount] = FormatFloat(MoneyFormat,ATOF(argv[2]));

    ServiceGoodsForm->sgServiceGoods->Cells[2][ServiceGoodsForm->ServiceGoodsCount] = FormatFloat(MoneyFormat,ATOF(argv[3]));


    return 0;
}
//---------------------------------------------------------------------------
static int goodsfill_fun(void *NotUsed, int argc, char **argv, char **azColName)
{
    // select RowID,Name,Price,ForSale from Goods

    if(!argv[0]) return 0;
    __int64 ID = _atoi64(argv[0]);

    if(!ID) return 0;

    ServiceGoodsForm->IDsGoods[ServiceGoodsForm->GoodsCount++] = ID;

    ServiceGoodsForm->sgGoods->Cells[0][ServiceGoodsForm->GoodsCount] = (argv[1]);

    ServiceGoodsForm->sgGoods->Cells[1][ServiceGoodsForm->GoodsCount] = FormatFloat(MoneyFormat,ATOF(argv[2]));

    ServiceGoodsForm->sgGoods->Cells[2][ServiceGoodsForm->GoodsCount] = ATOI(argv[3]);


    return 0;
}
//---------------------------------------------------------------------------

//***************************************************************************
//*************************** END CALLBACKS *********************************
//***************************************************************************

//---------------------------------------------------------------------------
__fastcall TServiceGoodsForm::TServiceGoodsForm(TComponent* Owner)
    : TForm(Owner)
{
    IDsServices = NULL;
    IDsServiceGoods = NULL;
    IDsGoods = NULL;

    ServicesCount = 0;
    ServiceGoodsCount = 0;
    GoodsCount = 0;

    fldAlignServices = "lrrRr";
    fldAlignServiceGoods = "lrr";
    fldAlignGoods = "lrr";

    //ServiceID = 0;
}
//---------------------------------------------------------------------------
void __fastcall TServiceGoodsForm::FormShow(TObject *Sender)
{
    //cbService->Items->Add("Гидромассаж");
    //cbService->Items->Add("Массаж");
    //cbService->Items->Add("Русская баня (с пармейстером)");
    //cbService->Items->Add("Русская баня (с массажистом)");
    //cbService->Items->Add("Хаммам (с пармейстером)");
    //cbService->Items->Add("Хаммам (с массажистом)");
    //cbService->Items->Add("Детский зал");
    //cbService->Items->Add("Мужской зал");
    //cbService->Items->Add("Женский зал");
    //cbService->Items->Add("Руки");
    //cbService->Items->Add("Ноги");
    //cbService->Items->Add("Общий уход");




    cbSection->Items->Add("Бар");
    cbSection->Items->Add("Косметика");
    cbSection->Items->Add("Сопутствующие товары");

    cbSection->ItemIndex = 0;

    sgSetHeaders(sgServices,"Услуга","Цена раб.","Цена мат.","Цена общая","Время");
    sgSetWidths(sgServices,&ServicesWidths,200,80,80,80);

    sgSetHeaders(sgServiceGoods,"Материал","Стоимость","Расход");
    sgSetWidths(sgServiceGoods,&ServiceGoodsWidths,100,100);

    sgSetHeaders(sgGoods,"Материал","Цена","В продаже");
    sgSetWidths(sgGoods,&GoodsWidths,100,100);

    sgOServicesWindowProc = sgServices->WindowProc;
    sgServices->WindowProc = sgServicesWindowProc;

    sgOServiceGoodsWindowProc = sgServiceGoods->WindowProc;
    sgServiceGoods->WindowProc = sgServiceGoodsWindowProc;

    sgOGoodsWindowProc = sgGoods->WindowProc;
    sgGoods->WindowProc = sgGoodsWindowProc;

    Service0Update();
}
//---------------------------------------------------------------------------
void __fastcall TServiceGoodsForm::Service0Update(void)
{
    AnsiString *pFld;
    unsigned cnt = SQL_fldCollect(DBName,"Name","from Services where Tag='~' order by Name",&pFld);
    if(cnt)
    {
        for(unsigned i = 0; i < cnt; i++)
            cbService0->Items->Add(pFld[i]);
        delete [] pFld;

        cbService0->ItemIndex = 0;
    }
    else
        cbService0->ItemIndex = -1;

    Service1Update();
}

void __fastcall TServiceGoodsForm::Service1Update(void)
{
    if(cbService0->ItemIndex < 0)
    {
        cbService1->ItemIndex = -1;
    }
    else
    {
        cbService1->Clear();
        AnsiString *pFld;
        unsigned cnt = SQL_fldCollect(DBName,"Name",("from Services where Tag='~" + (cbService0->Items->Strings[cbService0->ItemIndex]) + "~' order by Name").c_str(),&pFld);
        if(cnt)
        {
            for(unsigned i = 0; i < cnt; i++)
                cbService1->Items->Add(pFld[i]);
            delete [] pFld;

            cbService1->ItemIndex = 0;
        }
        else
            cbService1->ItemIndex = -1;
    }

    if(cbService1->ItemIndex >= 0)
        cbService1->Visible = true;
    else
        cbService1->Visible = false;

    Service2Update();
}

void __fastcall TServiceGoodsForm::Service2Update(void)
{
    if(cbService1->ItemIndex < 0)
    {
        cbService2->ItemIndex = -1;
    }
    else
    {
        cbService2->Clear();
        AnsiString *pFld;
        unsigned cnt = SQL_fldCollect(DBName,"Name",("from Services where Tag='~" + (cbService0->Items->Strings[cbService0->ItemIndex]+"~"+cbService1->Items->Strings[cbService1->ItemIndex]) + "~' order by Name").c_str(),&pFld);
        if(cnt)
        {
            for(unsigned i = 0; i < cnt; i++)
                cbService2->Items->Add(pFld[i]);
            delete [] pFld;

            cbService2->ItemIndex = 0;
        }
        else
            cbService2->ItemIndex = -1;
    }

    if(cbService2->ItemIndex >= 0)
        cbService2->Visible = true;
    else
        cbService2->Visible = false;

    FullUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TServiceGoodsForm::FormDestroy(TObject *Sender)
{
    delete [] IDsServices;
    delete [] IDsServiceGoods;
    delete [] IDsGoods;

    delete [] ServicesWidths;
    delete [] ServiceGoodsWidths;
    delete [] GoodsWidths;
}
//---------------------------------------------------------------------------
void __fastcall TServiceGoodsForm::sgServicesWindowProc(Messages::TMessage& Msg)
{
    sgWindowProc(Msg,sgServices,ServicesWidths,sgOServicesWindowProc);
}
//---------------------------------------------------------------------------
void __fastcall TServiceGoodsForm::sgServiceGoodsWindowProc(Messages::TMessage& Msg)
{
    sgWindowProc(Msg,sgServiceGoods,ServiceGoodsWidths,sgOServiceGoodsWindowProc);
}
//---------------------------------------------------------------------------
void __fastcall TServiceGoodsForm::sgGoodsWindowProc(Messages::TMessage& Msg)
{
    sgWindowProc(Msg,sgGoods,GoodsWidths,sgOGoodsWindowProc);
}
//---------------------------------------------------------------------------
void __fastcall TServiceGoodsForm::sgServicesDrawCell(TObject *Sender,
      int ACol, int ARow, TRect &Rect, TGridDrawState State)
{
    sgDrawCell(Sender,ACol,ARow,Rect,State,fldAlignServices);
}
//---------------------------------------------------------------------------
void __fastcall TServiceGoodsForm::sgServiceGoodsDrawCell(TObject *Sender,
      int ACol, int ARow, TRect &Rect, TGridDrawState State)
{
    sgDrawCell(Sender,ACol,ARow,Rect,State,fldAlignServiceGoods);
}
//---------------------------------------------------------------------------
void __fastcall TServiceGoodsForm::sgGoodsDrawCell(TObject *Sender,
      int ACol, int ARow, TRect &Rect, TGridDrawState State)
{
    sgDrawCell(Sender,ACol,ARow,Rect,State,fldAlignGoods);
}
//---------------------------------------------------------------------------
void __fastcall TServiceGoodsForm::FullUpdate(__int64 SID,__int64 SGID)
{
    AnsiString sRet;
    TComboBox *pCombo;

    PDEL(IDsServices);
    ServicesCount = 0;
    //ServiceID = 0;

    sgServices->RowCount = 2;
    sgClearRow(sgServices);

    AnsiString filter = "~";

    if(cbService0->Visible)
        filter += cbService0->Items->Strings[cbService0->ItemIndex] + "~";

    if(cbService1->Visible)
        filter += cbService1->Items->Strings[cbService1->ItemIndex] + "~";

    if(cbService2->Visible)
        filter += cbService2->Items->Strings[cbService2->ItemIndex] + "~";
    //if(cbService2->Visible)
    //    pCombo = cbService2;
    //else
    //    pCombo = cbService1;

    SQL_exefun(DBName,("select count(*) from Services where Tag='"+filter+"'").c_str(),&sRet);

    unsigned cnt = atoi(sRet.c_str());

    if(cnt)
    {
        if(cnt > 1)
            sgServices->RowCount = cnt + 1;

        IDsServices = new __int64[cnt];

        SQL_exe(DBName,("select RowID,Name,PersonPrice,Price,Timed from Services where Tag='"+filter+"' order by Name").c_str(),servicesfill_fun);

        if(SID)
        {
            for(cnt = 0; cnt < ServicesCount; cnt++)
                if(SID == IDsServices[cnt]) break;

            if(cnt < ServicesCount)
                sgServices->Row = cnt + 1;

        }
    }

    UpdateServiceGoods(SGID);
    UpdateGoods();


    //UpdateStatus();
}
//---------------------------------------------------------------------------
void __fastcall TServiceGoodsForm::ToolButton7Click(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TServiceGoodsForm::UpdateServiceGoods(__int64 SGID)
{
    AnsiString sCount;

    PDEL(IDsServiceGoods);
    ServiceGoodsCount = 0;

    sgServiceGoods->RowCount = 2;
    sgClearRow(sgServiceGoods);

    if(!ServicesCount) return;

    SQL_exefun(DBName,("select count(*) from ServiceGoods where ServiceID="+AnsiString(IDsServices[sgServices->Row-1])).c_str(),&sCount);
    ServiceGoodsCount = atoi(sCount.c_str());

    if(ServiceGoodsCount)
    {
        IDsServiceGoods = new __int64[ServiceGoodsCount];
        if(ServiceGoodsCount > 1)
            sgServiceGoods->RowCount = ServiceGoodsCount + 1;

        ServiceGoodsCount = 0;

        SQL_exe(DBName,("select ServiceGoods.RowID,Name,ServiceGoods.Price,Rate from ServiceGoods left outer join Goods on GoodID=Goods.RowID where ServiceID="+AnsiString(IDsServices[sgServices->Row-1])+" order by Name").c_str(),servicegoodsfill_fun);

        if(SGID)
        {
            unsigned cnt;
            for(cnt = 0; cnt < ServiceGoodsCount; cnt++)
                if(SGID == IDsServiceGoods[cnt]) break;

            if(cnt < ServiceGoodsCount)
                sgServiceGoods->Row = cnt + 1;

        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TServiceGoodsForm::UpdateGoods(void)
{
    AnsiString sCount;

    PDEL(IDsGoods);
    GoodsCount = 0;

    sgGoods->RowCount = 2;
    sgClearRow(sgGoods);

    SQL_exefun(DBName,("select count(*) from Goods where Section="+AnsiString(cbSection->ItemIndex)).c_str(),&sCount);
    GoodsCount = atoi(sCount.c_str());

    if(GoodsCount)
    {
        IDsGoods = new __int64[GoodsCount];
        if(GoodsCount > 1)
            sgGoods->RowCount = GoodsCount + 1;

        GoodsCount = 0;

        SQL_exe(DBName,("select RowID,Name,Price,ForSale from Goods where Section="+AnsiString(cbSection->ItemIndex)+" order by Name").c_str(),goodsfill_fun);

    }
}
//---------------------------------------------------------------------------
void __fastcall TServiceGoodsForm::cbSectionSelect(TObject *Sender)
{
    UpdateGoods();
}
//---------------------------------------------------------------------------
void __fastcall TServiceGoodsForm::sgGoodsMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
//    if(Button == mbRight && GoodsCount > 0)
//    {
//        TPoint p(X,Y);

//        p = sgGoods->ClientToScreen(p);
//        pmGoods->Popup(p.x,p.y);
//    }
}
//---------------------------------------------------------------------------
void __fastcall TServiceGoodsForm::ToolButton2Click(TObject *Sender)
{
    if(!GoodsCount) return;

    int forsale = !atoi(sgGoods->Cells[2][sgGoods->Row].c_str());
    SQL_BeginTransaction();
    SQL_exe(DBName,("update Goods set ForSale="+AnsiString(forsale)+" where RowID="+AnsiString(IDsGoods[sgGoods->Row-1])).c_str());
    SQL_CommitTransaction();
    sgGoods->Cells[2][sgGoods->Row] = forsale;
}
//---------------------------------------------------------------------------
void __fastcall TServiceGoodsForm::ToolButton5Click(TObject *Sender)
{
    // Привязать материал к услуге
    if(!ServicesCount || !GoodsCount) return;

    __int64 GID = IDsGoods[sgGoods->Row-1];

    if(ServiceGoodsCount)
    {
        unsigned i;
        for(i = 0; i < ServiceGoodsCount; i++)
            if(GID == IDsServiceGoods[i]) break;

        if(i < ServiceGoodsCount) return;
    }

    __int64 ID, SID = IDsServices[sgServices->Row-1];
    double price = atof(sgGoods->Cells[1][sgGoods->Row].c_str());

    SQL_BeginTransaction();

    SQL_iniInsert(DBName,"ServiceGoods",&ID);
    SQL_addInsert("ServiceID",SID);
    SQL_addInsert("GoodID",GID);
    SQL_addInsert("Price",price);
    SQL_exeInsert("Rate",100);

    SQL_exe(DBName,("update Services set Price=Price+"+AnsiString(price)+" where RowID="+AnsiString(SID)).c_str());

    SQL_CommitTransaction();

    FullUpdate(SID,ID);
}
//---------------------------------------------------------------------------
void __fastcall TServiceGoodsForm::sgServicesSelectCell(TObject *Sender,
      int ACol, int ARow, bool &CanSelect)
{
    static bool run = false;

    if(run) return;
    run = true;

    if(ARow != sgServices->Row && ServicesCount)
    {
        sgServices->Row = ARow;
        UpdateServiceGoods();
    }

    run = false;
}
//---------------------------------------------------------------------------
void __fastcall TServiceGoodsForm::edInputExit(TObject *Sender)
{
    edInput->Visible = false;

    if(edInputCol > 0 && edInput->Modified)
    {
        if(SQL_BeginTransaction() != SQLITE_OK) return;

        AnsiString sSum;
        double d = atof(edInput->Text.Trim().c_str());

        if(edInputMode == 2)
        {
            SQL_iniUpdate(DBName,"ServiceGoods",IDsServiceGoods[sgServiceGoods->Row-1]);
            if(edInputCol == 1)
            {
                SQL_exeUpdate("Price",d);

                SQL_exefun(DBName,("select sum(Price) from ServiceGoods where ServiceID="+AnsiString(IDsServices[sgServices->Row-1])).c_str(),&sSum);
                double gsum = atof(sSum.c_str());
                double psum = atof(sgServices->Cells[1][sgServices->Row].c_str());

                SQL_exe(DBName,("update Services set Price="+AnsiString(gsum+psum)+" where RowID="+AnsiString(IDsServices[sgServices->Row-1])).c_str());
                sgServices->Cells[2][sgServices->Row] = FormatFloat(MoneyFormat,gsum);
                sgServices->Cells[3][sgServices->Row] = FormatFloat(MoneyFormat,gsum+psum);
            }
            else
                SQL_exeUpdate("Rate",d);

            sgServiceGoods->Cells[edInputCol][sgServiceGoods->Row] = FormatFloat(MoneyFormat,d);
        }
        else if(edInputMode == 1)
        {
            SQL_iniUpdate(DBName,"Services",IDsServices[sgServices->Row-1]);
            if(edInputCol == 1)
            {
                SQL_exefun(DBName,("select sum(Price) from ServiceGoods where ServiceID="+AnsiString(IDsServices[sgServices->Row-1])).c_str(),&sSum);

                SQL_addUpdate("PersonPrice",d);
                sgServices->Cells[1][sgServices->Row] = FormatFloat(MoneyFormat,d);
                d += atof(sSum.c_str());
                SQL_exeUpdate("Price",d);
                sgServices->Cells[3][sgServices->Row] = FormatFloat(MoneyFormat,d);
            }
            else
            {
                SQL_exeUpdate("Timed",(int)d);
                sgServices->Cells[4][sgServices->Row] = (int)d;
            }
        }

        SQL_CommitTransaction();
        edInput->Modified = false;
    }
}
//---------------------------------------------------------------------------
void __fastcall TServiceGoodsForm::edInputKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
    if(Key == VK_ESCAPE)
    {
        edInputCol = -1;
        edInputMode = 0;

        if(edInputMode == 2)
            sgServiceGoods->SetFocus();
        else
            sgServices->SetFocus();
    }
    else if(Key == VK_RETURN)
    {
        if(edInputMode == 2)
        {
            sgServiceGoods->SetFocus();
            if(edInputCol == 1)
                edInputCol++;
            else if(sgServiceGoods->Row < (int)ServiceGoodsCount)
            {
                edInputCol = 1;
                sgServiceGoods->Row++;
            }
            else return;

            TRect rect = sgServiceGoods->CellRect(edInputCol,sgServiceGoods->Row);

            edInput->Left = sgServiceGoods->Left + rect.Left + 2;
            edInput->Top = rect.Top + sgServiceGoods->Top + 2;
            edInput->Width = rect.Width() + 1;
            edInput->Height = rect.Height();
            edInput->Text = sgServiceGoods->Cells[edInputCol][sgServiceGoods->Row];

            edInput->Visible = true;
            edInput->SetFocus();
        }
        else if(edInputMode == 1)
        {
            sgServices->SetFocus();
            if(edInputCol == 1)
                edInputCol = 4;
            else if(sgServices->Row < (int)ServicesCount)
            {
                edInputCol = 1;
                sgServices->Row++;
            }
            else return;

            TRect rect = sgServices->CellRect(edInputCol,sgServices->Row);

            edInput->Left = sgServices->Left + rect.Left + 2;
            edInput->Top = rect.Top + sgServices->Top + 2;
            edInput->Width = rect.Width() + 1;
            edInput->Height = rect.Height();
            edInput->Text = sgServices->Cells[edInputCol][sgServices->Row];

            edInput->Visible = true;
            edInput->SetFocus();
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TServiceGoodsForm::sgServiceGoodsDblClick(TObject *Sender)
{
    edInput->Visible = false;

    TPoint p;
    GetCursorPos(&p);

    TRect rect = sgServiceGoods->CellRect(2,sgServiceGoods->Row);

    p = ScreenToClient(p);

    if(p.x >= sgServiceGoods->Left + rect.Left)
        edInputCol = 2;
    else
    {
        edInputCol = 1;
        rect = sgServiceGoods->CellRect(1,sgServiceGoods->Row);
    }

    edInputMode = 2;

    edInput->Left = sgServiceGoods->Left + rect.Left + 2;
    edInput->Top = rect.Top + sgServiceGoods->Top + 2;
    edInput->Width = rect.Width() + 1;
    edInput->Height = rect.Height();
    edInput->Text = sgServiceGoods->Cells[edInputCol][sgServiceGoods->Row];

    edInput->Visible = true;

    edInput->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TServiceGoodsForm::edInputKeyPress(TObject *Sender,
      char &Key)
{
    ud_keyfilter(Key);
}
//---------------------------------------------------------------------------
void __fastcall TServiceGoodsForm::sgServicesDblClick(TObject *Sender)
{
    edInput->Visible = false;

    TPoint p;
    GetCursorPos(&p);

    TRect rect = sgServices->CellRect(4,sgServices->Row);

    p = ScreenToClient(p);

    if(p.x >= sgServices->Left + rect.Left)
        edInputCol = 4;
    else
    {
        edInputCol = 1;
        rect = sgServices->CellRect(1,sgServices->Row);
    }

    //TRect rect = sgServices->CellRect(1,sgServices->Row);

    //edInputCol = 1;
    edInputMode = 1;

    edInput->Left = sgServices->Left + rect.Left + 2;
    edInput->Top = rect.Top + sgServices->Top + 2;
    edInput->Width = rect.Width() + 1;
    edInput->Height = rect.Height();
    edInput->Text = sgServices->Cells[edInputCol][sgServices->Row];

    edInput->Visible = true;

    edInput->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TServiceGoodsForm::ToolButton1Click(TObject *Sender)
{
    // Удалить материал из услуги
    if(!ServiceGoodsCount) return;

    __int64 GID = IDsServiceGoods[sgServiceGoods->Row-1];


    __int64 SID = IDsServices[sgServices->Row-1];
    SQL_BeginTransaction();
    SQL_exe(DBName,("delete from ServiceGoods where RowID="+AnsiString(GID)).c_str());

    // А цена?
    AnsiString sPrice;
    SQL_exefun(DBName,("select sum(Price) from ServiceGoods where ServiceID="+AnsiString(SID)).c_str(),&sPrice);
    double price = atof(sPrice.c_str());
    //double price = atof(sgGoods->Cells[1][sgGoods->Row].c_str());

    //SQL_iniInsert(DBName,"ServiceGoods",&ID);
    //SQL_addInsert("ServiceID",SID);
    //SQL_addInsert("GoodID",GID);
    //SQL_addInsert("Price",price);
    //SQL_exeInsert("Rate",1);

    SQL_exe(DBName,("update Services set Price=PersonPrice+"+AnsiString(price)+" where RowID="+AnsiString(SID)).c_str());

    SQL_CommitTransaction();

    FullUpdate(SID,0);
}
//---------------------------------------------------------------------------
void __fastcall TServiceGoodsForm::cbService0Select(TObject *Sender)
{
    Service1Update();
}
//---------------------------------------------------------------------------
void __fastcall TServiceGoodsForm::cbService1Select(TObject *Sender)
{
    Service2Update();
}
//---------------------------------------------------------------------------
void __fastcall TServiceGoodsForm::cbService2Select(TObject *Sender)
{
    FullUpdate();
}
//---------------------------------------------------------------------------

