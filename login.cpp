//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include "login.h"
#include "accounts.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TLoginForm *LoginForm;
extern bool AppExit;
extern bool NoUserDay;
extern bool AdminMode;
extern const char *DBName;
extern __int64 UserID;
extern AnsiString UserAcc;
extern unsigned char UserGrants[FORMS_COUNT];
extern const char *pDefUserText;

static bool AccAccept = false;
//---------------------------------------------------------------------------
__fastcall TLoginForm::TLoginForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
static int login_select(void *NotUsed, int argc, char **argv, char **azColName)
{
    AccAccept = true;

    UserID = (argv[0])? _atoi64(argv[0]) : 0;

    memset(UserGrants,'0',FORMS_COUNT);
    //UserGrants[FORMS_COUNT] = 0;

    if(argv[1] != NULL)
    {
        unsigned len = strlen(argv[1]);
        if(len > FORMS_COUNT) len = FORMS_COUNT;

        memcpy(UserGrants,argv[1],len);
    }

    return 0;
}
//---------------------------------------------------------------------------
void __fastcall TLoginForm::btnCancelClick(TObject *Sender)
{
    AppExit = true;
}
//---------------------------------------------------------------------------
void __fastcall TLoginForm::btnOkClick(TObject *Sender)
{
    char md5pass[33];
    md5::md5(edPassword->Text.c_str(),md5pass);

    if(edLogin->Text == "admin" && !strcmp(md5pass,"528e5e5ba5a5ce3cd36e68a1842c4274"))
    //1 - "c4ca4238a0b923820dcc509a6f75849b"))
    //matuM-ba!27 - "817de2478651c02b4d78b1a483558d96"
    {
        AdminMode = true;
        UserAcc = "Администратор";
        Close();
        return;
    }
    else if(edPassword->Text.Trim().Length() > 0 && edLogin->Text.Trim().LowerCase() != pDefUserText)
    {
        md5::md5(edPassword->Text.c_str(),md5pass);
        AnsiString sql = "select RowID,Grants from Stars where StarsUser='"+(edLogin->Text)+"' and Passwd='"+md5pass+"' and StarsLock=0";

        SQL_exe(DBName,sql.c_str(),login_select);

        if(AccAccept)
        {
            // А по календарю??
            if(UserID != 4)
            {

                AnsiString sRet;
                unsigned short year, month, day;

                Now().DecodeDate(&year,&month,&day);

                sql = "select Days from Calendar where CalendarYear=";
                sql += year;
                sql += " and CalendarMonth=";
                sql += month;
                sql += " and PersonID=-";
                sql += UserID;

                SQL_exefun(NULL,sql.c_str(),&sRet);

                unsigned days = atoi(sRet.c_str());

                if(!(days & (1 << (day - 1))))
                {
                    AppExit = true;
                    NoUserDay = true;
                }
            }

            UserAcc = edLogin->Text;
            Close();
            return;
        }
    }

    int lft = LoginForm->Left;
    int top = LoginForm->Top;

    for(unsigned i = 0; i < 100; i++)
    {
        if(!(i & 1))
        {
            LoginForm->Left = lft - 2;
            LoginForm->Top  = top - 2;
        }
        else
        {
            LoginForm->Left = lft + 2;
            LoginForm->Top  = top + 2;
        }
        LoginForm->Repaint();
    }
    LoginForm->Left = lft;
    LoginForm->Top  = top;

    edLogin->SetFocus();
}
//---------------------------------------------------------------------------

