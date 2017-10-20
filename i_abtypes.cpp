//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "i_abtypes.h"
#include "lib.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TiAbTypesForm *iAbTypesForm;

extern const char *DBName;
extern __int64 AbTypeID;
extern __int64 UserID;
extern int FormResult;
extern const char *MoneyFormat;

static AnsiString AbTypeName;

static AnsiString *pUsers = NULL;
static __int64 *pUserIDs = NULL;
static unsigned UsersCounter = 0;

static AnsiString *pPersonal = NULL;
static __int64 *pPersonalIDs = NULL;
static unsigned PersonalCounter = 0;

static AnsiString *pServices = NULL;
static __int64 *pServicesIDs = NULL;
static unsigned ServicesCounter = 0;



static AnsiString retString;
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
static int personal_select(void *NotUsed, int argc, char **argv, char **azColName)
{
    pPersonalIDs[PersonalCounter] = (argv[0])? _atoi64(argv[0]) : -1;
    if(argv[1])
        pPersonal[PersonalCounter] = (argv[1]);
    else
        pPersonal[PersonalCounter] = "unknown";

    iAbTypesForm->lbPerson->Items->Add(pPersonal[PersonalCounter++]);

    return 0;
}
//---------------------------------------------------------------------------
static int services_select(void *NotUsed, int argc, char **argv, char **azColName)
{
    pServicesIDs[ServicesCounter] = (argv[0])? _atoi64(argv[0]) : -1;
    if(argv[1])
        pServices[ServicesCounter] = (argv[1]);
    else
        pServices[ServicesCounter] = "unknown";

    iAbTypesForm->lbService->Items->Add(pServices[ServicesCounter++]);

    return 0;
}
//---------------------------------------------------------------------------
static int abtypes_select(void *NotUsed,int argc,char **argv,char **azColName)
{
    // Alive - 0
    iAbTypesForm->cbAlive->Checked = (argv[0])? (atoi(argv[0]) != 0) : false;

    // Name - 1
    AbTypeName = (argv[1]);
    iAbTypesForm->edName->Text = AbTypeName;

    // Price - 2
    if(argv[2])
        iAbTypesForm->edPrice->Text = FormatFloat(MoneyFormat,strtof(argv[2])).TrimLeft();

    // Days - 3
    if(argv[3])
        iAbTypesForm->edDays->Text = atoi(argv[3]);

    // Count - 4
    if(argv[4])
        iAbTypesForm->edCount->Text = atoi(argv[4]);

    // PersonID - 5
    unsigned i;
    __int64 ID = (argv[5])? _atoi64(argv[5]) : 0;
    for(i = 0; i < PersonalCounter; i++)
        if(pPersonalIDs[i] == ID) break;
    if(i < PersonalCounter) iAbTypesForm->lbPerson->ItemIndex = i;
    else iAbTypesForm->lbPerson->ItemIndex = 0;

    // ServiceID - 6
    ID = (argv[6])? _atoi64(argv[6]) : 0;
    for(i = 0; i < ServicesCounter; i++)
        if(pServicesIDs[i] == ID) break;
    if(i < ServicesCounter) iAbTypesForm->lbService->ItemIndex = i;
    else iAbTypesForm->lbService->ItemIndex = 0;

    // AutoFlow - 7
    iAbTypesForm->cbAutoFlow->Checked = (argv[7])? (atoi(argv[7]) != 0) : false;

    AnsiString status;

    // CUID - 9
    if(argv[9])
    {
        __int64 CUID = (argv[9])? _atoi64(argv[9]) : -1;
        unsigned i;

        for(i = 0; i < UsersCounter; i++)
            if(pUserIDs[i] == CUID) break;

        if(i == UsersCounter)
            status += "   C:[unknown]";
        else
            status += ("   C:[" + pUsers[i] + " - ");
    }

    // CDate - 8
    TDateTime CDate;
    if(argv[8])
        CDate = atof(argv[8]);
    else
        CDate = 0;

    if((double)CDate == 0)
        status += "?]";
    else
        status += (CDate.DateTimeString() + "]");

    // EUID - 11
    if(argv[11])
    {
        __int64 EUID = (argv[11])? _atoi64(argv[11]) : -1;
        unsigned i;

        for(i = 0; i < UsersCounter; i++)
            if(pUserIDs[i] == EUID) break;

        if(i == UsersCounter)
            status += "   E:[unknown]";
        else
            status += ("   E:[" + pUsers[i] + " - ");
    }

    // EDate - 10
    TDateTime EDate;
    if(argv[10])
        EDate = atof(argv[10]);
    else
        EDate = 0;

    if((double)EDate == 0)
        status += "?]";
    else
        status += (EDate.DateTimeString() + "]");

    iAbTypesForm->sbiAbTypes->SimpleText = status;

    // FixSum - 12
    if(argv[12])
        iAbTypesForm->edFixSum->Text = FormatFloat(MoneyFormat,strtof(argv[12])).TrimLeft();

    return 0;
}
//---------------------------------------------------------------------------

//***************************************************************************
//*************************** END CALLBACKS *********************************
//***************************************************************************

//---------------------------------------------------------------------------
__fastcall TiAbTypesForm::TiAbTypesForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TiAbTypesForm::tbExitClick(TObject *Sender)
{
    Close();    
}
//---------------------------------------------------------------------------
void __fastcall TiAbTypesForm::FormShow(TObject *Sender)
{
    SQL_exefun(DBName,"select count(*) from Stars",&retString);

    pUsers = new AnsiString[atoi(retString.c_str()) + 1];
    if(!pUsers) Close();
    pUserIDs = new __int64[atoi(retString.c_str()) + 1];
    if(!pUserIDs) Close();
    UsersCounter = 1;
    pUsers[0] = "admin";
    pUserIDs[0] = 0;
    SQL_exe(DBName,"select RowID,StarsUser from Stars",users_select);

    SQL_exefun(DBName,"select count(*) from Personal",&retString);
    pPersonal = new AnsiString[atoi(retString.c_str()) + 1];
    if(!pPersonal) Close();
    pPersonalIDs = new __int64[atoi(retString.c_str()) + 1];
    if(!pPersonalIDs) Close();
    PersonalCounter = 1;
    pPersonal[0] = "без тренера";
    pPersonalIDs[0] = 0;
    lbPerson->Items->Add(pPersonal[0]);
    SQL_exe(DBName,"select RowID,Name from Personal order by Name,EDate",personal_select);

    SQL_exefun(DBName,"select count(*) from Services where RowID not in (select ParentID from Services)",&retString);
    pServices = new AnsiString[atoi(retString.c_str()) + 1];
    if(!pServices) Close();
    pServicesIDs = new __int64[atoi(retString.c_str()) + 1];
    if(!pServicesIDs) Close();
    ServicesCounter = 1;
    pServices[0] = "отсутствует";
    pServicesIDs[0] = 0;
    lbService->Items->Add(pServices[0]);
    SQL_exe(DBName,"select RowID,Name from Services where RowID not in (select ParentID from Services) order by Name,EDate",services_select);

    if(AbTypeID != 0)
        SQL_exe(DBName,("select Alive,Name,Price,Days,AbTypesCount,PersonID,ServiceID,AutoFlow,CDate,CUID,EDate,EUID,FixSum from AbTypes where RowID=" + (AnsiString)AbTypeID).c_str(),abtypes_select);
    else
    {
        lbPerson->ItemIndex = 0;
        lbService->ItemIndex = 0;
    }

    FormResult = 0;
}
//---------------------------------------------------------------------------
void __fastcall TiAbTypesForm::AbTypeSave(void)
{
    edName->Text = edName->Text.Trim();

    //if(edName->Text.Length() > 0 && edName->Text != AbTypeName)
    //{
    //    AnsiString sql = "select count(*) from AbTypes where Name='";
    //    sql += (edName->Text.Trim());
    //    sql += "'";

    //    SQL_exefun(DBName,sql.c_str(),&retString);

    //    if(atoi(retString.c_str()) > 0)
    //    {
    //        Application->MessageBox(("Абонемент с наименованием "+edName->Text.Trim()+" уже существует.").c_str(),"");
    //        return;
    //    }
    //}

    double Price = strtof(edPrice->Text.c_str());
    double FixSum = strtof(edFixSum->Text.c_str());
    int Count = atoi(edCount->Text.c_str());
    int Days = atoi(edDays->Text.c_str());

    TDateTime dt = Now();

    if(!AbTypeID)
    {
        __int64 ID;

        SQL_iniInsert(DBName,"AbTypes",&ID);

        SQL_addInsert("#Name",edName->Text);
        SQL_addInsert("Price",Price);
        SQL_addInsert("FixSum",FixSum);
        SQL_addInsert("AbTypesCount",Count);
        SQL_addInsert("Days",Days);
        SQL_addInsert("PersonID",pPersonalIDs[lbPerson->ItemIndex]);
        SQL_addInsert("ServiceID",pServicesIDs[lbService->ItemIndex]);
        SQL_addInsert("Alive",(int)(cbAlive->Checked));
        SQL_addInsert("AutoFlow",(int)(cbAutoFlow->Checked));
        SQL_addInsert("CDate",(double)dt);
        SQL_addInsert("EDate",(double)dt);
        SQL_addInsert("CUID",UserID);

        SQL_exeInsert("EUID",UserID);
        AbTypeID = ID;

        FormResult = 1;
    }
    else
    {
        SQL_iniUpdate(DBName,"AbTypes",AbTypeID);

        SQL_addUpdate("#Name",edName->Text);
        SQL_addUpdate("Price",Price);
        SQL_addUpdate("FixSum",FixSum);
        SQL_addUpdate("AbTypesCount",Count);
        SQL_addUpdate("Days",Days);
        SQL_addUpdate("PersonID",pPersonalIDs[lbPerson->ItemIndex]);
        SQL_addUpdate("ServiceID",pServicesIDs[lbService->ItemIndex]);
        SQL_addUpdate("Alive",(int)(cbAlive->Checked));
        SQL_addUpdate("AutoFlow",(int)(cbAutoFlow->Checked));
        SQL_addUpdate("EDate",(double)dt);

        SQL_exeUpdate("EUID",UserID);

        FormResult = -1;
    }

    Close();
}
//---------------------------------------------------------------------------
void __fastcall TiAbTypesForm::tbSaveClick(TObject *Sender)
{
    AbTypeSave();
}
//---------------------------------------------------------------------------
void __fastcall TiAbTypesForm::FormDestroy(TObject *Sender)
{
    PDEL(pUsers);
    PDEL(pUserIDs);

    PDEL(pPersonal);
    PDEL(pPersonalIDs);
}
//---------------------------------------------------------------------------
void __fastcall TiAbTypesForm::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key == VK_ESCAPE) Close();
    if(Key == VK_RETURN) AbTypeSave();
}
//---------------------------------------------------------------------------
void __fastcall TiAbTypesForm::edPriceKeyPress(TObject *Sender, char &Key)
{
    ud_keyfilter(Key);
}
//---------------------------------------------------------------------------
void __fastcall TiAbTypesForm::edCountKeyPress(TObject *Sender, char &Key)
{
    ui_keyfilter(Key);
}
//---------------------------------------------------------------------------
void __fastcall TiAbTypesForm::edDaysKeyPress(TObject *Sender, char &Key)
{
    ui_keyfilter(Key);
}
//---------------------------------------------------------------------------
void __fastcall TiAbTypesForm::edFixSumKeyPress(TObject *Sender, char &Key)
{
    d_keyfilter(Key);
}
//---------------------------------------------------------------------------

