//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "lib.h"

#include "dm_main.h"

#include <math.h>
//---------------------------------------------------------------------------
static const char *pZ = "0";
//---------------------------------------------------------------------------
//static AnsiString _DBName;
//static sqlite3 *_pTempDB = NULL;
//static AnsiString _TName;
extern AnsiString _AppPath;

static AnsiString _ID;
static AnsiString _SQL;
static AnsiString _SQL_alt;
static unsigned _Args;
static char *_Mask = NULL;
static __int64 *_pID;

static AnsiString _exefun_Ret;
static AnsiString _exefun_Ret2;
static AnsiString _exefun_Ret3;

static AnsiString *_pCollector;
static __int64 *_pCollectorIDs;

static int _monthdays[] = {31,28,31,30,31,30,31,31,30,31,30,31};

const char *_DayNames[] = { "Пн", "Вт", "Ср", "Чт", "Пт", "Сб", "Вс" };

const char *_MonthNames[] =
    { "январь", "февраль", "март", "апрель", "май", "июнь", "июль", "август", "сентябрь", "октябрь", "ноябрь", "декабрь" };

TColor SelColor = clMoneyGreen;
bool SQL_ShowErrors = false;
bool SQL_InTransaction = false;
int  SQL_RepeatCount = 4;
int  SQL_ExecDelay  = 1000;

static const char *pSQL_ErrOpen = "Отсутствует связь с БД";
static const char *pSQL_ErrBegin = ": Невозможно начать транзакцию!";
static const char *pSQL_ErrCommit = ": Невозможно завершить транзакцию!";
static const char *pSQL_ErrErr = "Ошибка БД";

#define SQL_ErrOpen()       if(SQL_ShowErrors) Application->MessageBox(pSQL_ErrOpen,pSQL_ErrErr,MB_OK)
#define SQL_ErrExec()       if(SQL_ShowErrors) Application->MessageBox(zErrMsg,pSQL_ErrErr,MB_OK)
#define SQL_ErrBegin()      if(SQL_ShowErrors) Application->MessageBox((AnsiString(sMethod)+pSQL_ErrBegin).c_str(),pSQL_ErrErr,MB_OK)
#define SQL_ErrCommit()     if(SQL_ShowErrors) Application->MessageBox((AnsiString(sMethod)+pSQL_ErrCommit).c_str(),pSQL_ErrErr,MB_OK)

//---------------------------------------------------------------------------
void __fastcall RoundTimeParts(unsigned short& h,unsigned short& m,unsigned short& s,unsigned short& ms)
{
    if(ms >= 500)
    {
        s++;
    }

    ms = 0;

    if(s >= 60)
    {
        m++;
        s -= 60;
    }
    if(m >= 60)
    {
        h++;
        m -= 60;
    }
    if(h >= 24) h -= 24;
}
//---------------------------------------------------------------------------
//void LoadBoxSize(const char *sName,TListBox *pBox1,TListBox *pBox2,TListBox *pBox3)
void LoadBoxSize(const char *sName,TControl *pBox1,TControl *pBox2,TControl *pBox3)
{
    TIniFile *pIni = new TIniFile(_AppPath+"panacea.ini");



    if(pIni->SectionExists("Box"))
    {
        AnsiString sSizes = pIni->ReadString("Box",sName,"0");
        int size = atoi(sSizes.c_str());

        if(size > 0)
        {
            char *p;

            pBox1->Width = size;
            if(pBox2)
            {
                strtok(sSizes.c_str(),",");
                size = atoi(strtok(NULL,","));
                if(size > 0)
                {
                    pBox2->Width = size;
                    if(pBox3)
                    {
                        p = strtok(NULL,",");
                        size = 0;
                        if(p)
                            size = atoi(p);
                        if(size > 0)
                            pBox3->Width = size;
                    }
                }
            }
        }
    }

    delete pIni;
}
//---------------------------------------------------------------------------
//void SaveBoxSize(const char *sName,TListBox *pBox1,TListBox *pBox2,TListBox *pBox3)
void SaveBoxSize(const char *sName,TControl *pBox1,TControl *pBox2,TControl *pBox3)
{
    TIniFile *pIni = new TIniFile(_AppPath+"panacea.ini");

    AnsiString sSizes = pBox1->Width;
    if(pBox2)
    {
        sSizes += ",";
        sSizes += pBox2->Width;
        if(pBox3)
        {
            sSizes += ",";
            sSizes += pBox3->Width;
        }
    }

    pIni->WriteString("Box",sName,sSizes);

    delete pIni;
}
//---------------------------------------------------------------------------
void LoadGridSize(const char *sName,TStringGrid *pGrid)
{
    TIniFile *pIni = new TIniFile(_AppPath+"panacea.ini");

    if(pIni->SectionExists("Grid"))
    {
        AnsiString sSizes = pIni->ReadString("Grid",sName,"0");
        int size = atoi(sSizes.c_str());

        if(size > 0)
        {
            char *p;

            pGrid->ColWidths[0] = size;
            p = strtok(sSizes.c_str(),",");
            size = atoi(strtok(NULL,","));

            for(int i = 1; i < pGrid->ColCount && size > 0; i++)
            {
                pGrid->ColWidths[i] = size;
                p = strtok(NULL,",");
                size = 0;
                if(p)
                    size = atoi(p);
            }
        }
    }

    delete pIni;
}
//---------------------------------------------------------------------------
void SaveGridSize(const char *sName,TStringGrid *pGrid)
{
    TIniFile *pIni = new TIniFile(_AppPath+"panacea.ini");

    AnsiString sSizes; // = pGrid->ColWidths[0];

    for(int i = 0; i < pGrid->ColCount; i++)
    {
        sSizes += pGrid->ColWidths[i];
        sSizes += ",";
    }

    sSizes.SetLength(sSizes.Length()-1);

    pIni->WriteString("Grid",sName,sSizes);

    delete pIni;
}
//---------------------------------------------------------------------------
double TimeStr2Double(char *stim)
{
    // Преобразовать из xx:xx
    int mins = 0, hour = atoi(stim);

    if(hour < 0) hour = 0;
    else if(hour > 24) hour %= 24;

    char *p = strchr(stim,':');
    if(p)
    {
        mins = atoi(p + 1);
        if(mins < 0) mins = 0;                
        else mins %= 60;
    }

    double tim = (hour * 60) + mins;
    tim /= 1440;
    return tim;
}
//---------------------------------------------------------------------------
void sgSetHeaders(TStringGrid *pGrid,...)
{
    va_list ap;

    va_start(ap,pGrid);

    for(int i = 0; i < pGrid->ColCount; i++)
        pGrid->Cells[i][0] = va_arg(ap,char *);

   va_end(ap);
}
//---------------------------------------------------------------------------
void sgSetWidths(TStringGrid *pGrid,int **pWidths,...)
{
    va_list ap;

    va_start(ap,pWidths);

    *pWidths = new int[pGrid->ColCount];

    for(int i = 0; i < pGrid->ColCount - 1; i++)
        pGrid->ColWidths[i] = (*pWidths)[i] = va_arg(ap,int);

    pGrid->ColWidths[pGrid->ColCount-1] = (*pWidths)[pGrid->ColCount-1] = sgGetLastWidth(pGrid);

   va_end(ap);
}
//---------------------------------------------------------------------------
void __fastcall sgDrawCell(TObject *Sender,
      int ACol, int ARow, TRect &Rect, TGridDrawState State,const char *fldAlign,bool Light,TImageList *pImageList,TColor fCol,TFontStyles fType)
{
    TStringGrid *pGrid = (TStringGrid *)Sender;

    if(State.Contains(gdFixed))
    {
        pGrid->Canvas->Font->Style = TFontStyles() << fsBold;
        pGrid->Canvas->Font->Color = HEADER_COLOR;

        pGrid->Canvas->Brush->Color = clBtnFace;
        pGrid->Canvas->FillRect(Rect);

        int lft = Rect.Width() - pGrid->Canvas->TextWidth(pGrid->Cells[ACol][0]);
        if(lft < 2) lft = 2;
        else lft >>= 1;
        pGrid->Canvas->TextRect(Rect,Rect.left+lft,Rect.top+1,pGrid->Cells[ACol][0]);
    }
    else
    {

        pGrid->Canvas->Font->Style = fType;

        if(State.Contains(gdSelected))
        {
            pGrid->Canvas->Brush->Color = SelColor;
            pGrid->Canvas->FillRect(Rect);
        }
        else
        {

            pGrid->Canvas->Brush->Color = clWhite;
            pGrid->Canvas->FillRect(Rect);
        }

        if(Light && ACol == 0 && pImageList)
        {
            if((pGrid->Cells[ACol][ARow]).Length() == 0)
                pImageList->Draw(pGrid->Canvas,Rect.left,Rect.top,0);
            else if(pGrid->Cells[ACol][ARow] == "\t")
                pImageList->Draw(pGrid->Canvas,Rect.left,Rect.top,2);
            else
                pImageList->Draw(pGrid->Canvas,Rect.left,Rect.top,1);
        }
        else
        {
            //pGrid->Canvas->Font->Style = TFontStyles() << fType;
            pGrid->Canvas->Font->Color = fCol;
            sgAlignTextDraw(pGrid,ACol,ARow,Rect,fldAlign);
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall sgWindowProc(Messages::TMessage& Msg,TStringGrid *pGrid,int *pWidths,TWndMethod sgOWindowProc)
{
    bool done = Msg.Msg == WM_SIZE;

    if(Msg.Msg == WM_NCHITTEST || done)
    {
        int i;

        if(!done)
        {
            for(i = 0; i < pGrid->ColCount; i++)
                if(pGrid->ColWidths[i] != pWidths[i]) break;
            done = i < pGrid->ColCount;
        }

        if(done)
        {
            int sum_width = 0;

            for(i = 0; i < pGrid->ColCount; i++)
            {
                if(pGrid->ColWidths[i] < 16) pGrid->ColWidths[i] = 16;
                sum_width += pGrid->ColWidths[i];
            }

            int width = pGrid->ClientWidth - pGrid->ColCount;

            if(sum_width < width) pGrid->ColWidths[pGrid->ColCount-1] += (width - sum_width);
            else if(sum_width > width)
            {
                // Вылез за границы
                int w;

                for(i = pGrid->ColCount - 1; i >= 0 && sum_width > width; i--)
                {
                    w = pGrid->ColWidths[i];

                    pGrid->ColWidths[i] -= (sum_width - width);
                    if(pGrid->ColWidths[i] < 16)
                    {
                        pGrid->ColWidths[i] = 16;
                        sum_width -= (w - 16);
                    }
                    else
                        break;
                }
            }

            for(i = 0; i < pGrid->ColCount; i++)
                pWidths[i] = pGrid->ColWidths[i];
        }
    }

    if(Msg.Msg != WM_SIZE)
        sgOWindowProc(Msg);
}
//---------------------------------------------------------------------------
void __fastcall sgClearRow(TStringGrid *pGrid,int ARow)
{
    for(int i = 0; i < pGrid->ColCount; i++)
    {
        pGrid->Cells[i][ARow] = "";
        pGrid->Rows[ARow]->Objects[i] = NULL;
    }
}
//---------------------------------------------------------------------------
int __fastcall sgGetLastWidth(TStringGrid *pGrid)
{
    int width = pGrid->ClientWidth;

    for(int i = 0; i < pGrid->ColCount - 1; i++)
        width -= pGrid->ColWidths[i];

    return(width - pGrid->ColCount);
}
//---------------------------------------------------------------------------
unsigned __fastcall UserInit(const char *DBName,__int64 **pUserIDs,AnsiString **pUsers)
{
    unsigned cnt = SQL_fldKeyCollect(DBName,"StarsUser","from Stars",pUserIDs,pUsers,true,true);

    (*pUsers)[0] = "admin";
    (*pUserIDs)[0] = 0;

    return cnt;
}
//---------------------------------------------------------------------------
void __fastcall sgAlignTextDraw(TStringGrid *pGrid,int ACol,int ARow,TRect &Rect,const char *alignment)
{
    if(!alignment || ACol >= (int)strlen(alignment))
    {
        pGrid->Canvas->TextRect(Rect,Rect.left+2,Rect.top+1,pGrid->Cells[ACol][ARow]);
        return;
    }

    char align = alignment[ACol];
    int x;

    switch(align)
    {
case 'R':   pGrid->Canvas->Font->Style = TFontStyles() << fsBold;
case 'r':

            x = Rect.Right - pGrid->Canvas->TextWidth(pGrid->Cells[ACol][ARow]);
                //int Y = Rect.Top + ((Rect.Bottom - Rect.Top - sgAbTypes->Canvas->TextHeight(sgAbTypes->Cells[ACol][ARow])) >> 1);
                //Rect.Right -= 2;

            pGrid->Canvas->TextRect(Rect,x-2,Rect.top+1,pGrid->Cells[ACol][ARow]);
            break;

case 'C':   pGrid->Canvas->Font->Style = TFontStyles() << fsBold;
case 'c':
            x = Rect.Width() - pGrid->Canvas->TextWidth(pGrid->Cells[ACol][ARow]);
            if(x < 2) x = 2;
            else x >>= 1;
            pGrid->Canvas->TextRect(Rect,Rect.left+x,Rect.top+1,pGrid->Cells[ACol][ARow]);
            break;

case 'L':   pGrid->Canvas->Font->Style = TFontStyles() << fsBold;
case 'l':

default:    pGrid->Canvas->TextRect(Rect,Rect.left+2,Rect.top+1,pGrid->Cells[ACol][ARow]);

    }
}
//---------------------------------------------------------------------------
int __fastcall monthdays(int year,int month)
{
    if(month == 2)
    {
        if(!(year % 4))
        {
            if(!(year % 400)) return 29;
            if(year % 100) return 29;
            return 28;
        }
        else return 28;
    }
    else
        return _monthdays[month-1];
}
//---------------------------------------------------------------------------
TDateTime __fastcall addmonths(TDateTime cdt,int add)
{
    unsigned short y,m,d;

    cdt.DecodeDate(&y,&m,&d);

    int iy = y, im = m, id = d;

    im += add;
    if(im > 12)
    {
        iy += ((im-1) / 12);
        im = ((im-1) % 12) + 1;
    }
    else if(im <= 0)
    {
        iy -= ((-im / 12) + 1);
        im = 12 - (-im % 12);
    }

    // Смотрим день
    int days = monthdays(iy,im);
    if(id > days)
    {

        if(im == 2)
        {
            // Попали в февраль
            if(id >= 29)
                id = days;
            //else
            //{
                //id = id - 29;
                //id = days;
                //im++;
            //}
        }
        else if(im == 3 && add == 1)
        {
            // Добавим n дня

            id += (30 - monthdays(iy,2));


        }
        else
            id = days;
    }

    return TDateTime(iy,im,id);
}
//---------------------------------------------------------------------------
void __fastcall ui_keyfilter(char &Key)
{
    if(Key >= '0' && Key <= '9') return;
    if(Key >= ' ') Key = 0;
}
//---------------------------------------------------------------------------
void __fastcall ud_keyfilter(char &Key)
{
    if(Key >= '0' && Key <= '9') return;
    if(Key == '.' || Key == ',') return;
    if(Key >= ' ') Key = 0;
}
//---------------------------------------------------------------------------
void __fastcall d_keyfilter(char &Key)
{
    if(Key >= '0' && Key <= '9') return;
    if(Key == '.' || Key == ',' || Key == '-') return;
    if(Key >= ' ') Key = 0;
}
//---------------------------------------------------------------------------
static int _exefun(void *NotUsed,int argc,char **argv,char **azColName)
{
    if(argc > 0) _exefun_Ret = (argv[0])? argv[0] : "";

    return 0;
}
//---------------------------------------------------------------------------
static int _exefun2(void *NotUsed,int argc,char **argv,char **azColName)
{
    if(argc > 1)
    {
        _exefun_Ret  = (argv[0])? argv[0] : "";
        _exefun_Ret2 = (argv[1])? argv[1] : "";
    }
    return 0;
}
//---------------------------------------------------------------------------
static int _exefun3(void *NotUsed,int argc,char **argv,char **azColName)
{
    if(argc > 2)
    {
        _exefun_Ret  = (argv[0])? argv[0] : "";
        _exefun_Ret2 = (argv[1])? argv[1] : "";
        _exefun_Ret3 = (argv[2])? argv[2] : "";
    }
    return 0;
}
//---------------------------------------------------------------------------
double __fastcall RoundDouble(double d,unsigned precision)
{ 
    int buf = 1;

    for(unsigned j = 0; j < precision; j++) buf *= 10;

    __int64 i = (int)(d * buf * 10);
    if(i % 10 >= 5) i = i / 10 + 1;
    else i /= 10;

    double dnew = i;

    return dnew / buf;
}
//---------------------------------------------------------------------------
double __fastcall strtof(char *src,unsigned precision)
{
    double val;
    char *p, *pp;

    if((p = strchr(src,',')) != NULL)
        *p = '.';

    if((pp = strchr(src,'.')) == NULL)
        val = atoi(src);
    else
    {
        char roubles[128];
        char copecs[128];

        strncpy(roubles,src,pp - src);
        roubles[pp - src] = '\0';

        memset(copecs,'0',precision + 1);

        unsigned count = strlen(++pp);
        if(count > precision + 1) count = precision + 1;

        for(unsigned i = 0; i < count; i++)
            copecs[i] = pp[i];

        copecs[precision+1] = '\0';

        val = (atoi(copecs) + 5) / 10;
        int r = atoi(roubles);

        if(r < 0)
            val = -val;

        unsigned x = 1;
        for(unsigned i = 0; i < precision; i++) x *= 10;
        val = (val / x) + r;
    }

    if(p) *p = ',';

    return val;
}
//---------------------------------------------------------------------------
static bool _fToAnsi;
static int _collectfun(void *NotUsed,int argc,char **argv,char **azColName)
{
    if(argc > 0)
    {
        if(_fToAnsi)
            *_pCollector = argv[0];
        else
            *_pCollector = argv[0];
    }
    else
        *_pCollector = "";

    _pCollector++;

    return 0;
}

// Сбор какого-то поля
unsigned __fastcall SQL_fldCollect(const char *dbname,const char *fName,const char *sql_from,AnsiString **pFld,bool ToAnsi,bool FirstZero,bool Distinct)
{
    // sql - select Field from ....
    AnsiString s;

    if(Distinct)
        s = AnsiString("select count(distinct ") + fName + ") from (select " + fName + " " + sql_from + ")";
    else
        s = AnsiString("select count(*) from (select ") + fName + " " + sql_from + ")";

    SQL_exefun(dbname,s.c_str(),&_exefun_Ret);

    unsigned cnt = atoi(_exefun_Ret.c_str());

    if(FirstZero) cnt++;
    if(!cnt)
    {
        *pFld = NULL;
        return 0;
    }

    _pCollector = new AnsiString[cnt];
    if(!_pCollector) return 0;

    *pFld = _pCollector;

    if(Distinct)
        s = AnsiString("select distinct ") + fName + " from (select ";
    else
        s = AnsiString("select ") + fName + " from (select ";

    _fToAnsi = ToAnsi;
    SQL_exe(dbname,(s + fName + " " + sql_from + ")").c_str(),_collectfun);

    return cnt;
}

static int _keycollectfun(void *NotUsed,int argc,char **argv,char **azColName)
{
    if(argc > 1)
    {
        __int64 ID = (argv[0])? _atoi64(argv[0]) : 0;
        *_pCollectorIDs++ = ID;

        if(argv[1])
        {
            if(_fToAnsi)
                *_pCollector = argv[1];
            else
                *_pCollector = argv[1];
        }
        else
            *_pCollector = "";

        _pCollector++;
    }

    return 0;
}

unsigned __fastcall SQL_fldKeyCollect(const char *dbname,const char *fName,const char *sql_from,__int64 **pIDs,AnsiString **pFld,bool ToAnsi,bool FirstZero,bool Distinct)
{
    // sql - select Field from ....
    AnsiString s;

    //if(Distinct)
    //    s = (AnsiString)"select count(distinct RowID) " + sql_from;
    //else
    //    s = (AnsiString)"select count(*) " + sql_from;

    if(Distinct)
        s = (AnsiString)"select count(distinct RowID) from (select RowID," + fName + " " + sql_from + ")";
    else
        s = (AnsiString)"select count(*) from (select RowID," + fName + " " + sql_from + ")";

    SQL_exefun(dbname,s.c_str(),&_exefun_Ret);

    unsigned cnt = atoi(_exefun_Ret.c_str());
    if(FirstZero) cnt++;
    if(!cnt)
    {
        *pIDs = NULL;
        *pFld = NULL;
        return 0;
    }
    _pCollectorIDs = new __int64[cnt];
    if(!_pCollectorIDs) return 0;

    _pCollector = new AnsiString[cnt];
    if(!_pCollector)
    {
        delete [] _pCollectorIDs;
        return 0;
    }

    *pIDs = _pCollectorIDs;
    *pFld = _pCollector;

    if(FirstZero)
    {
        _pCollectorIDs[0] = 0;
        _pCollectorIDs++;
        _pCollector++;
    }

    //if(Distinct)
    //    s = "select distinct RowID,";
    //else
    //    s = "select RowID,";

    if(Distinct)
        s = AnsiString("select distinct RowID,") + fName + " from (select RowID," + fName + " " + sql_from + ")";
    else
        s = AnsiString("select RowID,") + fName + " from (select RowID," + fName + " " + sql_from + ")";
        //s = AnsiString("select RowID,") + fName + " from (select RowID," + fName + " ";

    _fToAnsi = ToAnsi;
    SQL_exe(dbname,s.c_str(),_keycollectfun);

    return cnt;
}

static int _fullcollectfun(void *NotUsed,int argc,char **argv,char **azColName)
{
    if(argc >= (int)_Args)
        for(unsigned i = 0; i < _Args; i++)
        {
            if(argv[i])
                if(_Mask && _Mask[i] == '#')
                    *_pCollector++ = argv[i];
                else
                    *_pCollector++ = argv[i];
            else
                *_pCollector++ = "";
        }

    return 0;
}

unsigned __fastcall SQL_Collect(const char *dbname,unsigned fld_cnt,const char **fNames,const char *sql_from,const char *sql_order,AnsiString ** pFld,char *mask)
{
    *pFld = NULL;
    SQL_exefun(dbname,((AnsiString)"select count(*) "+sql_from).c_str(),&_exefun_Ret);
    unsigned cnt = atoi(_exefun_Ret.c_str());

    if(!cnt) return 0;

    _pCollector = new AnsiString[cnt*fld_cnt];

    if(!_pCollector) return 0;

    *pFld = _pCollector;

    AnsiString sql = "select ";
    for(unsigned i = 0; i < fld_cnt; i++)
    {
        if(i) sql += ",";
        sql += fNames[i];
    }

    sql += (AnsiString(" ")+sql_from);
    if(sql_order)
        sql += (AnsiString(" ")+sql_order);

    _Args = fld_cnt;
    _Mask = mask;
    SQL_exe(dbname,sql.c_str(),_fullcollectfun);

    return cnt;
}
//---------------------------------------------------------------------------
static int _exefunrow(void *NotUsed,int argc,char **argv,char **azColName)
{
    if(argc >= (int)_Args)
        for(unsigned i = 0; i < _Args; i++)
            _pCollector[i] = (argv[i])? argv[i] : "";

    return 0;
}

int __fastcall SQL_exefunrow(const char *dbname,const char *sql,unsigned count,AnsiString *pRet)
{
    if(dmMain->TransactionMain->Active && !SQL_InTransaction)
    {
        // Открытая транзакция - но флаг сброшен, что делать??

        return -1;
    }
    if(!dmMain->TransactionMain->Active && SQL_InTransaction)
    {
        // Закрытая транзакция но активен флаг - сбой?
        return -1;
    }

    int rc = 0;

    TIBQuery *pQue;
    TDataSource *pDS = NULL;

    if(dmMain->TransactionMain->Active)
    {
        // Можеть быть открытый Query
        pQue = new TIBQuery(NULL);
        pQue->Database = dmMain->DBMain;
        pQue->Transaction = dmMain->TransactionMain;
        pDS = new TDataSource(NULL);
        pDS->DataSet = pQue;
    }
    else
    {
        pQue = dmMain->QueMain;
        //dmMain->TransactionMain->Active = true;
    }

    pQue->Close();
    pQue->SQL->Clear();
    pQue->SQL->Add(sql);

    try
    {
        pQue->Prepare();
        pQue->Open();
    }
    catch(...)
    {
        pQue->Close();

        if(pDS)
        {
            delete pDS;
            delete pQue;
        }
        //dmMain->TransactionMain->Active = false;
        return -1;
    }

    if(pRet && !pQue->Eof)
        for(unsigned i = 0; i < count; i++)
            pRet[i] = pQue->Fields->Fields[i]->AsString;

    pQue->Close();
    if(!SQL_InTransaction)
        dmMain->TransactionMain->Active = false;

    if(pDS)
    {
        delete pDS;
        delete pQue;
    }
    
    return rc;
}
//---------------------------------------------------------------------------
int __fastcall SQL_exefun(const char *dbname,const char *sql,AnsiString *pRet)
{
    if(pRet) *pRet = "";

    if(dmMain->TransactionMain->Active && !SQL_InTransaction)
    {
        // Открытая транзакция - но флаг сброшен
        return -1;
    }
    if(!dmMain->TransactionMain->Active && SQL_InTransaction)
    {
        // Закрытая транзакция но активен флаг - сбой?
        return -1;
    }

    int rc = 0;
    TIBQuery *pQue;
    TDataSource *pDS = NULL;

    if(dmMain->TransactionMain->Active)
    {
        // Можеть быть открытый Query
        pQue = new TIBQuery(NULL);
        pQue->Database = dmMain->DBMain;
        pQue->Transaction = dmMain->TransactionMain;
        pDS = new TDataSource(NULL);
        pDS->DataSet = pQue;
     }
    else
    {
        pQue = dmMain->QueMain;
        //dmMain->TransactionMain->Active = true;
    }

    pQue->Close();
    pQue->SQL->Clear();
    pQue->SQL->Add(sql);

    try
    {
        pQue->Prepare();
        pQue->Open();
    }
    catch(...)
    {
        pQue->Close();

        if(pDS)
        {
            delete pDS;
            delete pQue;
        }

        // Что делать с транзакцией?
        //dmMain->TransactionMain->Active = false;
        return -1;
    }

    if(pRet && !pQue->Eof)
        *pRet = pQue->Fields->Fields[0]->AsString;

    pQue->Close();
    if(!SQL_InTransaction)
        dmMain->TransactionMain->Active = false;

    if(pDS)
    {
        delete pDS;
        delete pQue;
    }

    return rc;
}
//---------------------------------------------------------------------------
int __fastcall SQL_exefun2(const char *dbname,const char *sql,AnsiString *pRet1,AnsiString *pRet2)
{
    if(pRet1) *pRet1 = "";
    if(pRet2) *pRet2 = "";

    if(dmMain->TransactionMain->Active && !SQL_InTransaction)
    {
        // Открытая транзакция - но флаг сброшен
        return -1;
    }
    if(!dmMain->TransactionMain->Active && SQL_InTransaction)
    {
        // Закрытая транзакция но активен флаг - сбой?
        return -1;
    }

    int rc = 0;
    TIBQuery *pQue;
    TDataSource *pDS = NULL;

    if(dmMain->TransactionMain->Active)
    {
        // Можеть быть открытый Query
        pQue = new TIBQuery(NULL);
        pQue->Database = dmMain->DBMain;
        pQue->Transaction = dmMain->TransactionMain;
        pDS = new TDataSource(NULL);
        pDS->DataSet = pQue;
     }
     else
        pQue = dmMain->QueMain;

    pQue->Close();
    pQue->SQL->Clear();
    pQue->SQL->Add(sql);

    try
    {
        pQue->Prepare();
        pQue->Open();
    }
    catch(...)
    {
        pQue->Close();

        if(pDS)
        {
            delete pDS;
            delete pQue;
        }

        // Что делать с транзакцией?
        //dmMain->TransactionMain->Active = false;
        return -1;
    }

    if(!pQue->Eof)
    {
        if(pRet1)
            *pRet1 = pQue->Fields->Fields[0]->AsString;
        if(pRet2)
            *pRet2 = pQue->Fields->Fields[1]->AsString;
    }

    pQue->Close();
    if(!SQL_InTransaction)
        dmMain->TransactionMain->Active = false;

    if(pDS)
    {
        delete pDS;
        delete pQue;
    }

    return rc;
}
//---------------------------------------------------------------------------
int __fastcall SQL_exefun3(const char *dbname,const char *sql,AnsiString *pRet1,AnsiString *pRet2,AnsiString *pRet3)
{
    if(pRet1) *pRet1 = "";
    if(pRet2) *pRet2 = "";
    if(pRet3) *pRet3 = "";

    if(dmMain->TransactionMain->Active && !SQL_InTransaction)
    {
        // Открытая транзакция - но флаг сброшен
        return -1;
    }
    if(!dmMain->TransactionMain->Active && SQL_InTransaction)
    {
        // Закрытая транзакция но активен флаг - сбой?
        return -1;
    }

    int rc = 0;

    TIBQuery *pQue;
    TDataSource *pDS = NULL;

    if(dmMain->TransactionMain->Active)
    {
        // Можеть быть открытый Query
        pQue = new TIBQuery(NULL);
        pQue->Database = dmMain->DBMain;
        pQue->Transaction = dmMain->TransactionMain;
        pDS = new TDataSource(NULL);
        pDS->DataSet = pQue;
     }
     else
        pQue = dmMain->QueMain;

    pQue->Close();
    pQue->SQL->Clear();
    pQue->SQL->Add(sql);

    try
    {
        pQue->Prepare();
        pQue->Open();
    }
    catch(...)
    {
        pQue->Close();

        if(pDS)
        {
            delete pDS;
            delete pQue;
        }

        // Что делать с транзакцией?
        //dmMain->TransactionMain->Active = false;
        return -1;
    }

    if(!pQue->Eof)
    {
        if(pRet1)
            *pRet1 = pQue->Fields->Fields[0]->AsString;
        if(pRet2)
            *pRet2 = pQue->Fields->Fields[1]->AsString;
        if(pRet3)
            *pRet3 = pQue->Fields->Fields[2]->AsString;
    }

    pQue->Close();
    if(!SQL_InTransaction)
        dmMain->TransactionMain->Active = false;

    if(pDS)
    {
        delete pDS;
        delete pQue;
    }

    return rc;
}
//---------------------------------------------------------------------------
int __fastcall SQL_exe(const char *dbname,const char *sql,int (*callback)(void*,int,char**,char**))
{
    if(dmMain->TransactionMain->Active && !SQL_InTransaction)
    {
        // Открытая транзакция - но флаг сброшен
        return -1;
    }
    if(!dmMain->TransactionMain->Active && SQL_InTransaction)
    {
        // Закрытая транзакция но активен флаг - сбой?
        return -1;
    }

    int rc = 0;
    TIBQuery *pQue;
    TDataSource *pDS = NULL;

    if(dmMain->QueMain->Active)
    {
        pQue = new TIBQuery(NULL);
        pQue->Database = dmMain->DBMain;
        pQue->Transaction = dmMain->TransactionMain;
        pDS = new TDataSource(NULL);
        pDS->DataSet = pQue;
     }
     else
        pQue = dmMain->QueMain;

    //dmMain->QueMain->Close();
    //dmMain->QueMain->SQL->Clear();
    //dmMain->QueMain->SQL->Add(sql);
    pQue->Close();
    pQue->SQL->Clear();
    pQue->SQL->Add(sql);

    try
    {
        //dmMain->QueMain->Prepare();
        //dmMain->QueMain->Open();
        pQue->Prepare();
        pQue->Open();
    }
    catch(...)
    {
        pQue->Close();

        if(pDS)
        {
            delete pDS;
            delete pQue;
        }
        //dmMain->QueMain->Close();
        //dmMain->TransactionMain->Active = false;
        return -1;
    }

    int cnt = pQue->FieldCount;

    if(callback && !pQue->Eof && cnt)
    {
        char **pArgs = (char **)malloc(cnt * sizeof(char *));
        AnsiString *sBuf = new AnsiString[cnt];

        while(!pQue->Eof)
        {
            // n-аргументов
            for(int i = 0; i < cnt; i++)
            {
                sBuf[i] = pQue->Fields->Fields[i]->AsString;
                pArgs[i] = sBuf[i].c_str();
            }

            callback(NULL,cnt,pArgs,NULL);

            pQue->Next();
        }

        delete [] sBuf;
        free(pArgs);
    }

    pQue->Close();
    if(!SQL_InTransaction)
        dmMain->TransactionMain->Active = false;

    if(pDS)
    {
        delete pDS;
        delete pQue;
    }

    return rc;
}
//---------------------------------------------------------------------------
int __fastcall SQL_CancelTransaction(void)
{
    //static const char *_sql = "rollback transaction";
    SQL_InTransaction = false;
    //if(!_pTempDB) return SQLITE_ERROR;
    dmMain->TransactionMain->Active = false;
    //sqlite3_close(_pTempDB);
    //_pTempDB = NULL;

    return 0;
}
//---------------------------------------------------------------------------
int __fastcall SQL_CommitTransaction(void)
{
    //static const char *_sql = "commit transaction";
    if(!SQL_InTransaction) return -1;

    SQL_InTransaction = false;
    dmMain->TransactionMain->Commit();
    dmMain->TransactionMain->Active = false;

    return 0;
}
//---------------------------------------------------------------------------
int __fastcall SQL_BeginTransaction(const char *dbname)
{
    //static const char *_sql = "begin transaction";
    if(SQL_InTransaction) return -1;

    SQL_InTransaction = true;
    dmMain->TransactionMain->Active = true;

    return 0;
}
//---------------------------------------------------------------------------
void __fastcall SQL_iniInsert(const char *dbname,const char *tname,__int64 *pID)
{
    //_DBName = dbname;
    //_TName = tname;
    //_ID = (AnsiString)ID;
    _Args = 0;
    _pID = pID;
    if(_pID) *_pID = 0;
    _SQL = (AnsiString)"insert into " + tname + " (";
    _SQL_alt = " values (";
}
//---------------------------------------------------------------------------
void __fastcall SQL_addInsert(const char *fname,AnsiString val)
{
    if(_Args++ > 0)
    {
        _SQL += ",";
        _SQL_alt += ",";
    }
    if(fname[0] == '!')
    {
        _SQL += (AnsiString)&fname[1];
        _SQL_alt += ("'" + StringReplace(val,"'","''",TReplaceFlags() << rfReplaceAll) + "'");
    }
    else if(fname[0] == '#')
    {
        _SQL += (AnsiString)&fname[1];
        _SQL_alt += ("'" + StringReplace(val,"'","''",TReplaceFlags() << rfReplaceAll) + "'");
    }
    else
    {
        _SQL += (AnsiString)fname;
        unsigned pos = val.Pos(",");
        if(pos > 0) val[pos] = '.';
        _SQL_alt += val;
    }
}
//---------------------------------------------------------------------------
int __fastcall SQL_exeInsert(const char *fname,AnsiString val)
{
    // Может быть в транзакции

    if(_Args++ > 0)
    {
        _SQL += ",";
        _SQL_alt += ",";
    }
    if(fname[0] == '!')
    {
        _SQL += (AnsiString)&fname[1];
        _SQL_alt += ("'" + val + "'");
    }
    else if(fname[0] == '#')
    {
        _SQL += (AnsiString)&fname[1];
        _SQL_alt += ("'" + val + "'");
    }
    else
    {
        _SQL += (AnsiString)fname;
        unsigned pos = val.Pos(",");
        if(pos > 0) val[pos] = '.';
        _SQL_alt += val;
    }
    _SQL += ")" + _SQL_alt + ")";

    if(dmMain->TransactionMain->Active && !SQL_InTransaction)
    {
        // Открытая транзакция - но флаг сброшен
        return -1;
    }
    if(!dmMain->TransactionMain->Active && SQL_InTransaction)
    {
        // Закрытая транзакция но активен флаг - сбой?
        return -1;
    }

    int rc = 0;

    if(_pID) _SQL += " returning RowID";

    dmMain->SQLMain->Close();
    dmMain->SQLMain->SQL->Clear();
    dmMain->SQLMain->SQL->Add(_SQL);

    try
    {
        dmMain->TransactionMain->Active = true;
        dmMain->SQLMain->Prepare();
        dmMain->SQLMain->ExecQuery();
    }
    catch(...)
    {
        dmMain->SQLMain->Close();
        dmMain->TransactionMain->Active = false;
        return -1;
    }

    if(_pID)
    // && !dmMain->SQLMain->Eof)
        *_pID = _atoi64(dmMain->SQLMain->Fields[0]->AsString.c_str());

    dmMain->SQLMain->Close();
    if(!SQL_InTransaction)
    {
        dmMain->TransactionMain->Commit();
        dmMain->TransactionMain->Active = false;
    }

    return rc;
}
//---------------------------------------------------------------------------
void __fastcall SQL_iniUpdate(const char *dbname,const char *tname,const __int64 ID)
{
    //_DBName = dbname;
    //_TName = tname;
    _ID = (AnsiString)ID;
    _Args = 0;
    _SQL = (AnsiString)"update " + tname + " set ";
}
//---------------------------------------------------------------------------
void __fastcall SQL_addUpdate(const char *fname,AnsiString val)
{
    if(_Args++ > 0)
        _SQL += ",";
    if(fname[0] == '!')
        _SQL += ((AnsiString)&fname[1] + "='" + StringReplace(val,"'","''",TReplaceFlags() << rfReplaceAll) + "'");
    else if(fname[0] == '#')
        _SQL += ((AnsiString)&fname[1] + "='" + StringReplace(val,"'","''",TReplaceFlags() << rfReplaceAll) + "'");
    else
    {
        unsigned pos = val.Pos(",");
        if(pos > 0) val[pos] = '.';
        _SQL += ((AnsiString)fname + "=" + val);
    }
}
//---------------------------------------------------------------------------
int __fastcall SQL_exeUpdate(const char *fname,AnsiString val)
{
    if(_Args++ > 0)
        _SQL += ",";
    if(fname[0] == '!')
        _SQL += ((AnsiString)&fname[1] + "='" + val + "'");
    else if(fname[0] == '#')
        _SQL += ((AnsiString)&fname[1] + "='" + (val) + "'");
    else
    {
        unsigned pos = val.Pos(",");
        if(pos > 0) val[pos] = '.';
        _SQL += ((AnsiString)fname + "=" + val);
    }
    _SQL += (" where RowID="+_ID);

    if(dmMain->TransactionMain->Active && !SQL_InTransaction)
    {
        // Открытая транзакция - но флаг сброшен
        return -1;
    }
    if(!dmMain->TransactionMain->Active && SQL_InTransaction)
    {
        // Закрытая транзакция но активен флаг - сбой?
        return -1;
    }

    int rc = 0;

    dmMain->SQLMain->Close();
    dmMain->SQLMain->SQL->Clear();
    dmMain->SQLMain->SQL->Add(_SQL);

    try
    {
        dmMain->TransactionMain->Active = true;
        dmMain->SQLMain->Prepare();
        dmMain->SQLMain->ExecQuery();
    }
    catch(...)
    {
        dmMain->SQLMain->Close();
        dmMain->TransactionMain->Active = false;
        return -1;
    }

    dmMain->SQLMain->Close();
    if(!SQL_InTransaction)
    {
        dmMain->TransactionMain->Commit();
        dmMain->TransactionMain->Active = false;
    }

    return rc;
}
//---------------------------------------------------------------------------
// SQL_arrSelect,_SQL_arrSelect - Пока не используются и без транзакций
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
bool GetFileVersion(LPTSTR szFN, LPTSTR szVersion, DWORD nSize)
{
    DWORD   dwCount,
            dwHandle,
            dwValueLen;
    BOOL    bRet;
    TCHAR   *pcValue,
            *pc,
            *pBuffer,
            szQuery[100];

    if (nSize == 0)
        return false;

    if ((dwCount = GetFileVersionInfoSize(szFN, &dwHandle)) != 0)
    {
        pBuffer = new TCHAR[dwCount];
        if (!pBuffer)
            return false;

        if (GetFileVersionInfo(szFN, dwHandle, dwCount, pBuffer) != 0)
        {
            BOOL bVer = VerQueryValue(pBuffer, "\\VarFileInfo\\Translation", //INTERNAL USE ONLY
                (void **) &pcValue, (UINT *) &dwValueLen);

            if (bVer && dwValueLen != 0)
            {

                wsprintf(szQuery, "\\StringFileInfo\\%04X%04X\\FileVersion", //INTERNAL USE ONLY
                    *(WORD *)pcValue, *(WORD *)(pcValue+2));    // Localization OK

                bRet = VerQueryValue(pBuffer, szQuery, (void **) &pcValue,
                    (UINT *) &dwValueLen);

                if (bRet)
                {
                    while ((pc = _tcschr(pcValue, '(')) != NULL)
                        *pc = '{';
                    while ((pc = _tcschr(pcValue, ')')) != NULL)
                        *pc = '}';

                    _tcsncpy(szVersion, pcValue, nSize);
                    szVersion[nSize - 1] = '\0';

                    delete [] pBuffer;
                    return true;
                }
            }
        }

        delete [] pBuffer;
    }

    return false;
}
//---------------------------------------------------------------------------
TList* BuildBill(__int64 ID, double* total, double* getsum, double* terminal, double* frombal, double* change)
{
    //

    TList* pList = NULL;

    // Интересуют Payment и KKM (должен быть 0)
    AnsiString *pRet, sql =

        "from BILLS a "

        "left join BILLITEMS b on a.ROWID=b.BILLID "

        "left join GOODS c on b.GOODID=c.ROWID "
        "left join ABTYPES d on b.ABTYPEID=d.ROWID "
        "left join SERVICES e on b.SERVICEID=e.ROWID "
        "left join SERVNAMES f on e.ROWID=f.SERVICEID "

        "where a.ROWID=" + AnsiString(ID);

    //SQL_BeginTransaction();

    //unsigned SQL_Collect(const char *,unsigned fld_cnt,const char **fNames,const char *sql_from,const char *sql_order,AnsiString ** pFld,char *mask=NULL);
    const char* pFld[] =
    {
       "a.GETSUM","a.FROMBALANSE","a.TOBALANSE","a.PAYMENT","a.KKM",
       "c.NAME","d.NAME","e.TAG||e.NAME","f.NAME",
       "b.OP","b.PRICE","b.BILLITEMSCOUNT","b.TOTAL",
       "a.CHANGE","a.TOTAL","b.DISCOUNT","a.TERMINAL","b.ROWID"
    };

    int op, pos, cnt = SQL_Collect(NULL,18,pFld,sql.c_str(),NULL,&pRet);
    double d1, d2;

    for(int pcnt = 0, i = 0; i < cnt; pcnt++, i++)
    {
        pos = i * 18;
    /*
    typedef struct
    {
        AnsiString name;
        double price;
        double quan;
    } BillPosition;
    */


        if(!i)
        {
            pList = new TList();

            //if(ATOI(pRet[pos + 3].c_str()) == 1)
            //{
            //    *department = 1;
            //    *payment = 1;
            //}

            d1 = ATOF(pRet[pos + 1].c_str());
            d2 = ATOF(pRet[pos + 2].c_str());

            if(d2 - d1 > 0)
            {
                pList->Add(new BillPosition);
                ((BillPosition *)pList->Items[pcnt])->name = "пополнение баланса";
                ((BillPosition *)pList->Items[pcnt])->price = d2 - d1;
                ((BillPosition *)pList->Items[pcnt])->quan = 1;
                ((BillPosition *)pList->Items[pcnt])->id = 0;
                ((BillPosition *)pList->Items[pcnt++])->op = SELLOP_ADDBALANSE;
            }

            if(total) *total = ATOF(pRet[pos + 14].c_str());
            if(getsum) *getsum = ATOF(pRet[pos].c_str());
            if(terminal) *terminal = ATOF(pRet[pos+16].c_str());
            if(change) *change = ATOF(pRet[pos + 13].c_str());
            if(frombal) *frombal = ATOF(pRet[pos + 1].c_str());
        }

        //discount = ATOF(pRet[pos + 15].c_str());
        //if(discount < 1.0) discount = 1.0;
        //else
        //    discount = (100.0 - discount) / 100.0;

        // Может не быть данных
        op = ATOI(pRet[pos + 9].c_str());

        if(op == SELLOP_ABONEMENT)
        {
            // Абонемент Фитнесс
             pList->Add(new BillPosition);
             ((BillPosition *)pList->Items[pcnt])->name = "абонемент " + pRet[pos + 6];
             //d1 = ATOF(pRet[pos + 15].c_str());
             //d1 = (100.0 - ATOF(pRet[pos + 15].c_str())) / 100.0;
             //if(d1 > 0)
             //   ((BillPosition *)pList->Items[pcnt])->price = (100.0 - d1) * ATOF(pRet[pos + 10].c_str()) / 100.0;
             //else
             ((BillPosition *)pList->Items[pcnt])->price = ATOF(pRet[pos + 10].c_str());
             ((BillPosition *)pList->Items[pcnt])->quan = ATOF(pRet[pos + 11].c_str());
        }
        else if(op == SELLOP_GOOD)
        {
            // Товар
             pList->Add(new BillPosition);
             ((BillPosition *)pList->Items[pcnt])->name = pRet[pos + 5];
             ((BillPosition *)pList->Items[pcnt])->price = ATOF(pRet[pos + 10].c_str());
             ((BillPosition *)pList->Items[pcnt])->quan = ATOF(pRet[pos + 11].c_str());
        }
        else if(op == SELLOP_ABONEMENT_SPA)
        {
            // Абонемент SPA
            pList->Add(new BillPosition);
            ((BillPosition *)pList->Items[pcnt])->name = "пополнение абонемента SPA";
            ((BillPosition *)pList->Items[pcnt])->price = ATOF(pRet[pos + 10].c_str());
            ((BillPosition *)pList->Items[pcnt])->quan = ATOF(pRet[pos + 11].c_str());
        }
        else if(op == SELLOP_SPA_VISIT || op == SELLOP_BATH || op == SELLOP_BARBER || op == SELLOP_NAIL || op == SELLOP_COSMETIC)
        {
            // Имя из ServNames
            pList->Add(new BillPosition);
            ((BillPosition *)pList->Items[pcnt])->name = (pRet[pos + 8].Length() > 0)? pRet[pos + 8] : pRet[pos + 7];
            ((BillPosition *)pList->Items[pcnt])->price = ATOF(pRet[pos + 10].c_str());
            ((BillPosition *)pList->Items[pcnt])->quan = ATOF(pRet[pos + 11].c_str());
        }

        if(pcnt < cnt)
        {
            ((BillPosition *)pList->Items[pcnt])->id = ATOI64(pRet[pos + 17].c_str());
            ((BillPosition *)pList->Items[pcnt])->op = op;
        }
    }

    //SQL_CancelTransaction();

    return pList;
}
//---------------------------------------------------------------------------

