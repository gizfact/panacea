//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "balanse.h"
#include "lib.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBalanseForm *BalanseForm;

extern const char *DBName;
extern const char *MoneyFormat;
//---------------------------------------------------------------------------
static int balanse_ui(void *NotUsed,int argc,char **argv,char **azColName)
{
    if(argv[0])
        BalanseForm->CDate = atof(argv[0]);
    else
        BalanseForm->CDate = 0;

    BalanseForm->CUID = (argv[1])? _atoi64(argv[1]) : -1;

    if(argv[2])
        BalanseForm->EDate = atof(argv[2]);
    else
        BalanseForm->EDate = 0;

    BalanseForm->EUID = (argv[3])? _atoi64(argv[3]) : -1;

    return 0;
}
//---------------------------------------------------------------------------
static int fill_fun(void *NotUsed, int argc, char **argv, char **azColName)
{
//  "select CDate,BegBalanse,FromBalanse,ToBalanse,EndBalanse,RowID from Bills where ClientID=";
    if(!argv[5]) return 0;
    __int64 ID = _atoi64(argv[5]);
    if(!ID) return 0;

    if(BalanseForm->IDs.Length <= (int)BalanseForm->BalanseCounter)
        BalanseForm->IDs.Length += 4;

    BalanseForm->IDs[BalanseForm->BalanseCounter++] = ID;

    if(BalanseForm->BalanseCounter > 1)
        BalanseForm->sgBalanse->RowCount++;

    if(argv[0])
        BalanseForm->sgBalanse->Cells[0][BalanseForm->BalanseCounter] = TDateTime(atof(argv[0]));

    if(argv[1])
        BalanseForm->sgBalanse->Cells[1][BalanseForm->BalanseCounter] = FormatFloat(MoneyFormat,strtof(argv[1],2));
    if(argv[2])
        BalanseForm->sgBalanse->Cells[2][BalanseForm->BalanseCounter] = FormatFloat(MoneyFormat,strtof(argv[2],2));
    if(argv[3])
        BalanseForm->sgBalanse->Cells[3][BalanseForm->BalanseCounter] = FormatFloat(MoneyFormat,strtof(argv[3],2));
    if(argv[4])
        BalanseForm->sgBalanse->Cells[4][BalanseForm->BalanseCounter] = FormatFloat(MoneyFormat,strtof(argv[4],2));

    return 0;
}
//---------------------------------------------------------------------------
void __fastcall TBalanseForm::sgBalanseWindowProc(Messages::TMessage& Msg)
{
    bool done = Msg.Msg == WM_SIZE;

    if(Msg.Msg == WM_NCHITTEST || done)
    {
        int i;

        if(!done)
        {
            for(i = 0; i < sgBalanse->ColCount; i++)
                if(sgBalanse->ColWidths[i] != BalanseWidths[i]) break;
            done = i < sgBalanse->ColCount;
        }

        if(done)
        {
            int sum_width = 0;

            for(i = 0; i < sgBalanse->ColCount; i++)
            {
                if(sgBalanse->ColWidths[i] < 16) sgBalanse->ColWidths[i] = 16;
                sum_width += sgBalanse->ColWidths[i];
            }

            int width = sgBalanse->ClientWidth - sgBalanse->ColCount;

            if(sum_width < width) sgBalanse->ColWidths[sgBalanse->ColCount-1] += (width - sum_width);
            else if(sum_width > width)
            {
                // Вылез за границы
                int w;

                for(i = sgBalanse->ColCount - 1; i >= 0 && sum_width > width; i--)
                {
                    w = sgBalanse->ColWidths[i];

                    sgBalanse->ColWidths[i] -= (sum_width - width);
                    if(sgBalanse->ColWidths[i] < 16)
                    {
                        sgBalanse->ColWidths[i] = 16;
                        sum_width -= (w - 16);
                    }
                    else
                        break;
                }
            }

            for(i = 0; i < sgBalanse->ColCount; i++)
                BalanseWidths[i] = sgBalanse->ColWidths[i];
        }
    }

    if(Msg.Msg != WM_SIZE)
        sgOBalanseWindowProc(Msg);
}
//---------------------------------------------------------------------------
__fastcall TBalanseForm::TBalanseForm(TComponent* Owner)
    : TForm(Owner)
{
    fldAlign = "lrrrr";
}
//---------------------------------------------------------------------------
void __fastcall TBalanseForm::FormShow(TObject *Sender)
{
    BalanseWidths = new int[sgBalanse->ColCount];

    sgBalanse->Cells[0][0] = "Дата";
    sgBalanse->Cells[1][0] = "На начало";
    sgBalanse->Cells[2][0] = "На баланс";
    sgBalanse->Cells[3][0] = "С баланса";
    sgBalanse->Cells[4][0] = "На конец";

    sgBalanse->ColWidths[0] = BalanseWidths[0] = 180;
    sgBalanse->ColWidths[1] = BalanseWidths[1] = 120;
    sgBalanse->ColWidths[2] = BalanseWidths[2] = 120;
    sgBalanse->ColWidths[3] = BalanseWidths[3] = 120;
    sgBalanse->ColWidths[4] = BalanseWidths[4] = sgBalanse->ClientWidth - sgBalanse->ColWidths[0] - sgBalanse->ColWidths[1] - sgBalanse->ColWidths[2] - sgBalanse->ColWidths[3] - sgBalanse->ColCount;

    UsersCounter = UserInit(DBName,&pUserIDs,&pUsers);

    dtpBalanse->DateTime = (int)Now() - 60;

    sgOBalanseWindowProc = sgBalanse->WindowProc;
    sgBalanse->WindowProc = sgBalanseWindowProc;

    sgBalanseFullUpdate();

    sgBalanseUI(0);
}
//---------------------------------------------------------------------------
void __fastcall TBalanseForm::sgBalanseUI(int cnt)
{
    if(IDs.Length >= (int)BalanseCounter && BalanseCounter > 0 && cnt >= 0)
    {
        AnsiString status = "ID: " + (AnsiString)IDs[cnt];

        CDate = 0;
        CUID = -1;
        EDate = 0;
        EUID = -1;

        SQL_exe(DBName,("select CDate,CUID,EDate,EUID from Bills where RowID="+(AnsiString)IDs[cnt]).c_str(),balanse_ui);

        unsigned i;
        for(i = 0; i < UsersCounter; i++)
            if(pUserIDs[i] == CUID) break;

        if(i == UsersCounter)
            status += "   C:[unknown - ";
        else
            status += ("   C:[" + pUsers[i] + " - ");

        if((double)CDate == 0)
            status += "?]";
        else
            status += (CDate.DateTimeString() + "]");

        for(i = 0; i < UsersCounter; i++)
            if(pUserIDs[i] == EUID) break;

        if(i == UsersCounter)
            status += "   E:[unknown - ";
        else
            status += ("   E:[" + pUsers[i] + " - ");

        if((double)EDate == 0)
            status += "?]";
        else
            status += (EDate.DateTimeString() + "]");

        sbBalanse->SimpleText = status;
    }
    else
        sbBalanse->SimpleText = "ID: ";
}
//---------------------------------------------------------------------------
void __fastcall TBalanseForm::sgBalanseFullUpdate(void)
{
    // Изменения баланса
    int dt = (int)Now();
    int Start = (int)dtpBalanse->DateTime;
    int Finish = dt + 1;

    AnsiString sql = "select CDate,BegBalanse,ToBalanse,FromBalanse,EndBalanse,RowID from Bills where ClientID=";
    sql += ClientID;
    sql += " and BegBalanse!=EndBalanse and CDate>=";
    sql += Start;
    sql += " and EDate<";
    sql += Finish;
    sql += " order by CDate desc,RowID desc";

    sgBalanse->RowCount = 2;
    sgBalanse->Cells[0][1] = "";
    sgBalanse->Cells[1][1] = "";
    sgBalanse->Cells[2][1] = "";
    sgBalanse->Cells[3][1] = "";
    sgBalanse->Cells[4][1] = "";

    BalanseCounter = 0;
    SQL_exe(DBName,sql.c_str(),fill_fun);
}
//---------------------------------------------------------------------------
void __fastcall TBalanseForm::FormDestroy(TObject *Sender)
{
    delete [] BalanseWidths;

    delete [] pUserIDs;
    delete [] pUsers;

    IDs.Length = 0;
}
//---------------------------------------------------------------------------
void __fastcall TBalanseForm::sgBalanseDrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
    if(State.Contains(gdFixed))
    {
        sgBalanse->Canvas->Font->Style = TFontStyles() << fsBold;
        sgBalanse->Canvas->Font->Color = HEADER_COLOR;

        int lft = Rect.Width() - sgBalanse->Canvas->TextWidth(sgBalanse->Cells[ACol][0]);
        if(lft < 2) lft = 2;
        else lft >>= 1;
        sgBalanse->Canvas->TextRect(Rect,Rect.left+lft,Rect.top+1,sgBalanse->Cells[ACol][0]);
    }
    else
    {
        if(State.Contains(gdSelected))
        {
            sgBalanse->Canvas->Brush->Color = SelColor;
            //SEL_COLOR;
            sgBalanse->Canvas->FillRect(Rect);
        }
        else
        {
            sgBalanse->Canvas->Brush->Color = clWhite;
            sgBalanse->Canvas->FillRect(Rect);
        }

        sgBalanse->Canvas->Font->Color = clBlack;
        sgAlignTextDraw(sgBalanse,ACol,ARow,Rect,fldAlign);
    }
}
//---------------------------------------------------------------------------
void __fastcall TBalanseForm::dtpBalanseChange(TObject *Sender)
{
    sgBalanseFullUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TBalanseForm::tbExitClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TBalanseForm::sgBalanseSelectCell(TObject *Sender,
      int ACol, int ARow, bool &CanSelect)
{
    sgBalanseUI(ARow-1);
}
//---------------------------------------------------------------------------

