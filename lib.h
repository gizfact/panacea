//---------------------------------------------------------------------------
#include <time.h>
#include <DateUtils.hpp>
#include "sqlite3.h"
#include <new.h>
#include <Grids.hpp>
#include <IniFiles.hpp>
//---------------------------------------------------------------------------
#define HEADER_COLOR    clNavy
//#define SEL_COLOR       TColor(0xD0FDFF)
extern TColor SelColor;
//clSkyBlue
//TColor(0xCD00CD)
//0xCC6699     TColor
#define PDEL(p) delete [] (p); (p) = NULL

#define ATOI(Z)    ((Z)? atoi(Z) : 0)
#define ATOI64(Z)  ((Z)? _atoi64(Z) : 0)
#define ATOF(Z)    ((Z)? atof(Z) : 0.0)

#define MONDAY      1
#define TUESDAY     2
#define WEDNESDAY   4
#define THURSDAY    8
#define FRIDAY      16
#define SATURDAY    32
#define SUNDAY      64

#define FULLWEEK    127
#define WORKWEEK    31
#define WEEKEND     96
#define WEEKEND_EX  112

#define BATH_ID 196
#define BATH_COMPLEXID 373

// ���
// ����
// ���-��
// �����
// ��� ������
typedef struct
{
    AnsiString name;
    double price;
    double quan;
    __int64 id;
    int op;
} BillPosition;

#define SELLOP_ADDBALANSE        1
#define SELLOP_ABONEMENT         2
#define SELLOP_GOOD              4
#define SELLOP_SERVICE           8
#define SELLOP_ABONEMENT_SPA    16
#define SELLOP_SPA_VISIT        32
#define SELLOP_BATH             64
#define SELLOP_BARBER           128
#define SELLOP_NAIL             256
#define SELLOP_COSMETIC         512
#define SELLOP_ABONEMENT_BATH   1024
//---------------------------------------------------------------------------
//void LoadBoxSize(const char *sName,TListBox *pBox1,TListBox *pBox2,TListBox *pBox3 = NULL);
//void SaveBoxSize(const char *sName,TListBox *pBox1,TListBox *pBox2,TListBox *pBox3 = NULL);

void __fastcall RoundTimeParts(unsigned short& h,unsigned short& m,unsigned short& s,unsigned short& ms);

void LoadBoxSize(const char *sName,TControl *pBox1,TControl *pBox2 = NULL,TControl *pBox3 = NULL);
void SaveBoxSize(const char *sName,TControl *pBox1,TControl *pBox2 = NULL,TControl *pBox3 = NULL);

void LoadGridSize(const char *sName,TStringGrid *pGrid);
void SaveGridSize(const char *sName,TStringGrid *pGrid);

double TimeStr2Double(char *);

void sgSetHeaders(TStringGrid *pGrid,...);
void sgSetWidths(TStringGrid *pGrid,int **pWidths,...);

void __fastcall sgWindowProc(Messages::TMessage& Msg,TStringGrid *pGrid,int *pWidths,TWndMethod sgOWindowProc);
void __fastcall sgDrawCell(TObject *Sender,
      int ACol, int ARow, TRect &Rect, TGridDrawState State,const char *fldAlign,bool Light = false,TImageList *pImageList = NULL,TColor fCol=clBlack,TFontStyles fType=TFontStyles());

unsigned __fastcall UserInit(const char *,__int64 **,AnsiString **);
int __fastcall sgGetLastWidth(TStringGrid *);
void __fastcall sgClearRow(TStringGrid *pGrid,int ARow=1);

void __fastcall sgAlignTextDraw(TStringGrid *,int,int,TRect &,const char *alignment=NULL);

//unsigned __fastcall _SQL_arrSelect(const char *dbname,const __int64 *pIDs,unsigned cnt,char *sql_before,char *sql_after,AnsiString *pFlds,unsigned cnt_flds,char *mask=NULL);

unsigned __fastcall SQL_Collect(const char *,unsigned fld_cnt,const char **fNames,const char *sql_from,const char *sql_order,AnsiString ** pFld,char *mask=NULL);

int __fastcall SQL_exefunrow(const char *,const char *sql,unsigned count,AnsiString *pRet);
unsigned __fastcall SQL_fldCollect(const char *,const char *fName,const char *sql_from,AnsiString **pFld,bool ToAnsi = false,bool FirstZero = false,bool Distinct = false);
unsigned __fastcall SQL_fldKeyCollect(const char *,const char *fName,const char *sql_from,__int64 **pIDs,AnsiString **pFld,bool ToAnsi = false,bool FirstZero = false,bool Distinct = false);

int __fastcall monthdays(int,int);
TDateTime __fastcall addmonths(TDateTime cdt,int add);

double __fastcall RoundDouble(double d, unsigned precision);
double __fastcall strtof(char *,unsigned precision = 2);

void __fastcall ui_keyfilter(char &Key);
void __fastcall ud_keyfilter(char &Key);
void __fastcall d_keyfilter(char &Key);

//int __fastcall SQL_arrSelect(const char *dbname,const __int64 *pIDs,unsigned cnt,const AnsiString *sql,int (*callback)(void*,int,char**,char**) = NULL);

int __fastcall SQL_exe(const char *,const char *,int (*callback)(void*,int,char**,char**) = NULL);
int __fastcall SQL_exefun(const char *,const char *,AnsiString *pRet = NULL);
int __fastcall SQL_exefun2(const char *,const char *,AnsiString *,AnsiString *);
int __fastcall SQL_exefun3(const char *,const char *,AnsiString *,AnsiString *,AnsiString *);
//int __fastcall SQL_exefunalt(const char *,const char *,void (*sqlfun)(sqlite3_context *,int,sqlite3_value **),
//    AnsiString *);

void __fastcall SQL_iniInsert(const char *,const char *,__int64 *pID = NULL);
void __fastcall SQL_addInsert(const char *,AnsiString);
int __fastcall SQL_exeInsert(const char *,AnsiString);

void __fastcall SQL_iniUpdate(const char *,const char *,const __int64);
void __fastcall SQL_addUpdate(const char *,AnsiString);
int __fastcall SQL_exeUpdate(const char *,AnsiString);

//int __fastcall SQL_Update2(const char *,const char *,const char *,AnsiString,const __int64);
//int __fastcall SQL_Update2(const char *,const char *,const char *,AnsiString,const char *,AnsiString,const __int64);
//---------------------------------------------------------------------------
int __fastcall SQL_BeginTransaction(const char *dbname = NULL);
int __fastcall SQL_CommitTransaction(void);
int __fastcall SQL_CancelTransaction(void);

bool GetFileVersion(LPTSTR szFN, LPTSTR szVersion, DWORD nSize);

TList* BuildBill(__int64 ID, double* total, double* getsum, double* terminal, double* frombal = NULL, double* change = NULL);

//TList* BuildBillNOT(__int64 ID, double* total, double* getsum, double* terminal, double* frombal = NULL, double* change = NULL);

