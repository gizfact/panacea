//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "i_clients.h"
#include "accounts.h"
//#include "lib.h"
#include <math.h>
#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TiClientsForm *iClientsForm;

extern const char *DBName;
extern __int64 ClientID;
extern __int64 UserID;
extern unsigned char UserGrants[FORMS_COUNT];

extern int FormResult;

extern AnsiString ImgPath;

static AnsiString CID;
static AnsiString PhotoPath = "";
static AnsiString NewPhotoPath = "";

extern const char *MoneyFormat;

extern void upper_ru(sqlite3_context *, int, sqlite3_value **);

extern TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TiClientsForm::TiClientsForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TiClientsForm::tbSaveClick(TObject *Sender)
{
    edFName->Text = edFName->Text.Trim();
    edSName->Text = edSName->Text.Trim();
    edTName->Text = edTName->Text.Trim();

    if(edFName->Text.Length() == 0 && edSName->Text.Length() == 0 && edTName->Text.Length() == 0)
    {
        Application->MessageBox("Внимание!\nНеобходимо заполнить хотя бы одно поле: Фамилия, Имя, Отчество.","Ошибка ввода",MB_OK);
        return;
    }

    if(edFName->Text != FName || edSName->Text != SName || edTName->Text != TName)
    {
        AnsiString retString, sql = "select count(*) from Clients where sqlfun(FName,0)='";
        sql += (edFName->Text.UpperCase());
        sql += "' and sqlfun(SName,0)='";
        sql += (edSName->Text.UpperCase());
        sql += "' and sqlfun(TName,0)='";
        sql += (edTName->Text.UpperCase());
        sql += "'";

        //SQL_exefunalt(DBName,sql.c_str(),upper_ru,&retString);

        if(atoi(retString.c_str()) > 0)
        {
            if(Application->MessageBox("Внимание!\nКлиент с такими Имя,Фамилия,Отчество уже существует.\nСохранение приведет к созданию тезки. Продолжить?","Предупреждение",MB_OKCANCEL) == IDCANCEL)
                return;
        }
    }

    edDiscount->Text = edDiscount->Text.Trim();

    if(edCard->Text.Length() > 0)
        edCardNum->Text = edCardNum->Text.Trim();
    else
    {
        edCardNum->Text = "0";
        edWebPass->Text = "";
    }

    double discount = atof(edDiscount->Text.c_str());

    edCID->Text = edCID->Text.Trim();

    edTName->Text = edTName->Text.Trim();

    edPhone1->Text = edPhone1->Text.Trim();
    edPhone2->Text = edPhone2->Text.Trim();
    //edPhone3->Text = edPhone3->Text.Trim();

    TDateTime dt = Now();
    //dt = dt.CurrentDateTime();

    SQL_BeginTransaction();

    if(!ClientID)
    {
        __int64 ID;

        SQL_iniInsert(DBName,"Clients",&ID);

        SQL_addInsert("#CID",edCID->Text);
        SQL_addInsert("#FName",edFName->Text);
        SQL_addInsert("#SName",edSName->Text);
        SQL_addInsert("#TName",edTName->Text);
        SQL_addInsert("#FullName",edFName->Text+" "+edSName->Text+" "+edTName->Text);

        SQL_addInsert("!DiscountCard",edCard->Text);
        SQL_addInsert("!CardNum",edCardNum->Text);
        if((int)CardDate == 0 && edCard->Text.Length() > 0)
            SQL_addInsert("!CardDate",(double)Now());
        SQL_addInsert("!WebPass",edWebPass->Text);

        SQL_addInsert("Discount",discount);
        SQL_addInsert("DiscountSPA",discount);

        if((double)dtpBirthDate->DateTime != 0)
            SQL_addInsert("BirthDate",(double)(dtpBirthDate->DateTime));
        SQL_addInsert("#Phone1",edPhone1->Text);
        SQL_addInsert("#Phone2",edPhone2->Text);
        //SQL_addInsert("#Phone3",edPhone3->Text);
        SQL_addInsert("Alive",(int)(cbAlive->Checked));

        if(NewPhotoPath != PhotoPath)
        {
            if(NewPhotoPath.Length() == 0)
            {
                DeleteFile((ImgPath + PhotoPath).c_str());
                SQL_addInsert("!Photo","");
            }
            else
            {
                char *p = strrchr(NewPhotoPath.c_str(),'.');
                if(p)
                {
                    unsigned len = p - NewPhotoPath.c_str();
                    PhotoPath = (AnsiString)ClientID + "." + NewPhotoPath.SubString(len+2,NewPhotoPath.Length()-len-1);
                    if(CopyFile(NewPhotoPath.c_str(),(ImgPath + PhotoPath).c_str(),false))
                        SQL_addInsert("!Photo",PhotoPath);
                }
            }
        }

        SQL_addInsert("#Info",mInfo->Lines->Text);

        //if(edCard->Text.Length() == 0)


        //SQL_addInsert("#Note",mNote->Lines->Text);
        SQL_addInsert("CDate",(double)dt);
        SQL_addInsert("EDate",(double)dt);
        SQL_addInsert("CUID",UserID);
        SQL_exeInsert("EUID",UserID);
        ClientID = ID;
        FormResult = 1;
    }
    else
    {
        SQL_iniUpdate(DBName,"Clients",ClientID);

        SQL_addUpdate("#CID",edCID->Text);
        SQL_addUpdate("#FName",edFName->Text);
        SQL_addUpdate("#SName",edSName->Text);
        SQL_addUpdate("#TName",edTName->Text);
        SQL_addUpdate("#FullName",edFName->Text+" "+edSName->Text+" "+edTName->Text);
        SQL_addUpdate("!DiscountCard",edCard->Text);
        SQL_addUpdate("!CardNum",edCardNum->Text);
        if((int)CardDate == 0 && edCard->Text.Length() > 0)
            SQL_addUpdate("!CardDate",(double)Now());
        SQL_addUpdate("!WebPass",edWebPass->Text);
        SQL_addUpdate("Discount",discount);
        SQL_addUpdate("DiscountSPA",discount);
        if((double)dtpBirthDate->DateTime != 0)
            SQL_addUpdate("BirthDate",(double)(dtpBirthDate->DateTime));
        SQL_addUpdate("!Phone1",edPhone1->Text);
        SQL_addUpdate("!Phone2",edPhone2->Text);
        //SQL_addUpdate("!Phone3",edPhone3->Text);
        SQL_addUpdate("Alive",(int)(cbAlive->Checked));

        if(NewPhotoPath != PhotoPath)
        {
            if(NewPhotoPath.Length() == 0)
            {
                DeleteFile((ImgPath + PhotoPath).c_str());
                SQL_addUpdate("!Photo","");
            }
            else
            {
                char *p = strrchr(NewPhotoPath.c_str(),'.');
                if(p)
                {
                    unsigned len = p - NewPhotoPath.c_str();
                    PhotoPath = (AnsiString)ClientID + "." + NewPhotoPath.SubString(len+2,NewPhotoPath.Length()-len-1);
                    if(CopyFile(NewPhotoPath.c_str(),(ImgPath + PhotoPath).c_str(),false))
                        SQL_addUpdate("!Photo",PhotoPath);
                }
            }
        }

        SQL_addUpdate("#Info",mInfo->Lines->Text);

        SQL_addUpdate("EDate",(double)dt);
        SQL_exeUpdate("EUID",UserID);

        FormResult = -1;
    }

    SQL_CommitTransaction();

    SQL_exefun(NULL,"select count(*) from Clients where Alive>0",&retString);
    MainForm->sbMain->Panels->Items[1]->Text = AnsiString("Активных клиентов: ") + atoi(retString.c_str());

    Close();
}
//---------------------------------------------------------------------------
static int iclients_select(void *NotUsed,int argc,char **argv,char **azColName)
{
    CID = (argv[0]);
    iClientsForm->edCID->Text = CID;
    iClientsForm->edFName->Text = (argv[1]);
    iClientsForm->edSName->Text = (argv[2]);
    iClientsForm->edTName->Text = (argv[3]);

    iClientsForm->FName = iClientsForm->edFName->Text;
    iClientsForm->SName = iClientsForm->edSName->Text;
    iClientsForm->TName = iClientsForm->edTName->Text;

    if(argv[4])
        iClientsForm->dtpBirthDate->DateTime = atof(argv[4]);
    else
        iClientsForm->dtpBirthDate->Date = TDate(1900,1,1);

    iClientsForm->edPhone1->Text = (argv[5])? argv[5] : "";
    iClientsForm->edPhone2->Text = (argv[6])? argv[6] : "";
    iClientsForm->mInfo->Lines->Text = (argv[8]);

    if(argv[9])
        iClientsForm->edBalanse->Text = FormatFloat(MoneyFormat,strtof(argv[9])).TrimLeft();
    else
        iClientsForm->edBalanse->Text = "0.00";

    iClientsForm->cbAlive->Checked = (argv[10])? (atoi(argv[10]) != 0) : false;

    if(argv[11] > 0)
        PhotoPath = argv[11];
    else
        PhotoPath = "";
    try
    {
        if(PhotoPath.Length() > 0)
        {
            iClientsForm->Panel2->Caption = "";
            iClientsForm->imPhoto->Picture->LoadFromFile(ImgPath + PhotoPath);
        }
    }
    catch(...)
    {
        iClientsForm->Panel2->Caption = "НЕТ ФОТО";
    }

    NewPhotoPath = PhotoPath;

    iClientsForm->edCard->Text = (argv[12])? argv[12] : "";
    iClientsForm->edCardNum->Text = (argv[15])? argv[15] : "";
    iClientsForm->CardDate = (argv[16])? atof(argv[16]) : 0.0;

    iClientsForm->edWebPass->Text = (argv[14])? argv[14] : "";

    double x, discount = (argv[13])? atof(argv[13]) : 0.0;
    if(modf(discount,&x) != 0.0)
        iClientsForm->edDiscount->Text = (AnsiString)discount;
    else
        iClientsForm->edDiscount->Text = (AnsiString)(int)discount;

    return 0;
}
//---------------------------------------------------------------------------
void __fastcall TiClientsForm::FormShow(TObject *Sender)
{
    if(UserID == 0)
    {
        edCardNum->ReadOnly = false;
        edCardNum->PasswordChar = 0;
        edCard->ReadOnly = false;
        edCard->PasswordChar = 0;
    }

    if(UserID == 0 || UserGrants[12] != '0')
    {
        edDiscount->Enabled = true;
        cbAlive->Enabled = true;
    }

    int mask = UserGrants[1] - '0';

    if(ClientID != 0)
    {
        if(UserID != 0 && UserID != 4)
        {
            if((mask & 2) == 0)
                tbSave->Visible = false;
            else
            {
                edCID->ReadOnly = true;
                edFName->ReadOnly = true;
                edSName->ReadOnly = true;
                edTName->ReadOnly = true;
                edDiscount->ReadOnly = true;
                edPhone1->ReadOnly = true;
                edPhone2->ReadOnly = true;
                mInfo->ReadOnly = true;
            }
        }

        SQL_exe(DBName,("select CID,FName,SName,TName,BirthDate,Phone1,Phone2,Phone3,Info,Balanse,Alive,Photo,DiscountCard,Discount,WebPass,CardNum,CardDate from Clients where RowID=" + (AnsiString)ClientID).c_str(),iclients_select);
        if(edWebPass->Text.Length() > 0 && UserID != 0 && UserID != 4)
            edWebPass->PasswordChar = '*';
    }
    else
    {
        CID = "";
        dtpBirthDate->DateTime = 0;
        CardDate = 0;
    }

    if(edCard->Text.Length() > 0)
    {
        Button1->Visible = false;
        //edCardNum->ReadOnly = true;
    }

    if(UserID == 0 || UserID == 4)
        edCardNum->ReadOnly = false;

    FormResult = 0;
}
//---------------------------------------------------------------------------
void __fastcall TiClientsForm::btSetPhotoClick(TObject *Sender)
{
    if(opdPhoto->Execute())
    {
        NewPhotoPath = opdPhoto->FileName;
        try
        {
            Panel2->Caption = "";
            imPhoto->Picture->LoadFromFile(NewPhotoPath);
        }
        catch(...)
        {
            Panel2->Caption = "НЕТ ФОТО";
        }
        tbSave->Enabled = true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TiClientsForm::btClearPhotoClick(TObject *Sender)
{
    NewPhotoPath = "";
    imPhoto->Picture = NULL;
    Panel2->Caption = "НЕТ ФОТО";
    tbSave->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TiClientsForm::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key == VK_ESCAPE)
    {
        Key = 0;
        Close();
    }
    else if(Key == VK_INSERT && edCard->Text.Length() == 0 && edWebPass->Text.Length() > 0)
    {
        //edCardNum->ReadOnly = false;
        edCard->ReadOnly = false;
        edCard->SetFocus();
    }
    else if(Key == VK_RETURN)
    {
        if(edCard->Focused() && edCard->ReadOnly == false && edCard->Text.Length() > 0)
        {
            // Проверим карту
            SQL_exefun(NULL,("select count(*) from Clients where DiscountCard='" + edCard->Text + "'").c_str(),&retString);

            if(atoi(retString.c_str()))
            {
                edCard->Text = "";
                Application->MessageBox("Внимание!\nКарта с таким номером уже заведена. Повторный ввод невозможен.","Ошибка ввода",MB_OK);
            }
            
            edCard->ReadOnly = true;
            edCardNum->ReadOnly = false;
            edCardNum->SetFocus();
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TiClientsForm::Button1Click(TObject *Sender)
{
    // Генерация пароля, ввод карты

    AnsiString pass;

    randomize();

    pass = char('0' + random(10));
    pass += char('0' + random(10));
    pass += char('0' + random(10));
    pass += char('0' + random(10));
    pass += char('0' + random(10));
    pass += char('0' + random(10));

    if(pass[1] == '0') pass[1] = '1';

    edWebPass->Text = pass;
}
//---------------------------------------------------------------------------
void __fastcall TiClientsForm::edCardNumKeyPress(TObject *Sender,
      char &Key)
{
    ui_keyfilter(Key);
}
//---------------------------------------------------------------------------

