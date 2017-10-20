//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "reserve.h"
#include "lib.h"
#include "rescal.h"
#include "fitshedule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

extern const char *DBName;
//extern const char *_days[];

TReserveForm *ReserveForm;
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
__fastcall TReserveForm::TReserveForm(TComponent* Owner)
    : TForm(Owner)
{
    //__int64 *pServiceIDs;
    //AnsiString *pServices;
    //unsigned i, cnt = SQL_fldKeyCollect(DBName,"Name","from Services where WeekDays&127 and Tag='~'",&pServiceIDs,&pServices,true);

    //tcReserve->Tabs->Add("");
    //tcReserve->Tabs->Objects[0] = NULL;

    //for(i = 0; i < cnt; i++)
    //{
    //    tcReserve->Tabs->Add(pServices[i]);
    //    tcReserve->Tabs->Objects[i+1] = (TObject *)pServiceIDs[i];
    //}

    //delete [] pServiceIDs;
    //delete [] pServices;


    //pLevelTab[0] = tcReserve;



    //DaysCount = 7;
    //PersonCount = 0;

    //pDays = NULL;
    //pHeaders = NULL;
    //pPersons = NULL;
    //pPersonIDs = NULL;
    //pPersonNames = NULL;

    //CurrentFDay = Now();
    //FitFlag = false;

}
//---------------------------------------------------------------------------
void __fastcall TReserveForm::tbExitClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TReserveForm::AllLabelClick(TObject *Sender)
{
    TLabel *pCurLabel = (TLabel *)Sender;

    if(pCurLabel->Caption.Length() > 0 && pCurLabel->Caption[1] == '+')
    {
        if(CurCheckedLabel)
        {
            CurCheckedLabel->Color = clBackground;
            CurCheckedLabel->Font->Style = TFontStyles();
            CurCheckedLabel = NULL;
        }
        // могут быть открытые
        // свернуть если открыта другая ветка
        TLabel *pL;

        for(int i = 0; i < sbMain->ControlCount; i++)
        {
            pL = (TLabel *)((TPanel *)sbMain->Controls[i])->Controls[0];
            if(pL->Caption[1] == '-')
            {
                // открытая ветка
                if(pCurLabel->Parent->Tag != (int)pL)
                {
                    pL->Caption = StringReplace(pL->Caption,"-","+",TReplaceFlags());

                    int j = 0;
                    int *pObj = new int[sbMain->ControlCount];

                    for(int i = 0; i < sbMain->ControlCount; i++)
                    {
                        if(sbMain->Controls[i]->Tag == (int)pL)
                        {
                            for(int k = 0; k < sbMain->ControlCount; k++)
                                if(sbMain->Controls[k]->Tag == (int)((TPanel *)sbMain->Controls[i])->Controls[0])
                                    pObj[j++] = (int)sbMain->Controls[k];

                            pObj[j++] = (int)sbMain->Controls[i];
                        }
                    }

                    for(int i = 0; i < j; i++)
                        delete (TPanel *)pObj[i];

                    delete [] pObj;

                }

            }
        }

        pCurLabel->Caption = StringReplace(pCurLabel->Caption,"+","-",TReplaceFlags());

        // развернуть

        __int64 *pIDs;
        AnsiString sRet, *pNames;

        unsigned cnt = SQL_fldKeyCollect(DBName,"Name",("from Services where WeekDays&127 and ParentID="+AnsiString(pCurLabel->Tag)+" order by Name").c_str(),&pIDs,&pNames,true);

        TPanel *pBox;
        TLabel *pLabel;

        int top = pCurLabel->Parent->Top + pCurLabel->Parent->Height;

        //sbMain->Visible = false;
        for(unsigned i = 0; i < cnt; i++)
        {
            pBox = new TPanel(sbMain);
            pBox->Color = clBackground;
            pBox->BevelOuter = bvNone;
            pBox->Parent = sbMain;

            pBox->Height = 30;
            pBox->Top = top;
            pBox->Align = alTop;
            pBox->Tag = (int)pCurLabel;

            top = pBox->Top + pBox->Height;

            pLabel = new TLabel(pBox);
            pLabel->Parent = pBox;

            pLabel->Top = 5;
            pLabel->Left = pCurLabel->Left + 16;
            pLabel->Font->Color = clWhite;
            pLabel->Font->Size = 11;

            SQL_exefun(DBName,("select count(*) from Services where ParentID="+AnsiString(pIDs[i])).c_str(),&sRet);
            int res = atoi(sRet.c_str());



            if(res > 0)
                pLabel->Caption = "+ " + pNames[i];
            else
                pLabel->Caption = pNames[i];

            pLabel->OnClick = AllLabelClick;
            pLabel->Tag = pIDs[i];

            if(cnt == 1 && res == 0)
            {
                CurCheckedLabel = pLabel;
                CurCheckedLabel->Color = clBlue;

                //pLabel = new TLabel(pBox);
                //pLabel->Parent = pBox;

                //pLabel->Top = 5;
                //pLabel->Left = pCurLabel->Left + 400;
                //pLabel->Font->Color = clWhite;
                //pLabel->Font->Size = 11;
                CurCheckedLabel->Font->Style = TFontStyles() << fsUnderline;
                //pLabel->Caption = "запись";
            }
        }
        //sbMain->Visible = true;

        delete [] pNames;
        delete [] pIDs;
    }
    else if(pCurLabel->Caption.Length() > 0 && pCurLabel->Caption[1] == '-')
    {
        // свернуть
        if(CurCheckedLabel)
        {
            CurCheckedLabel->Color = clBackground;
            CurCheckedLabel->Font->Style = TFontStyles();
            CurCheckedLabel = NULL;
        }
        pCurLabel->Caption = StringReplace(pCurLabel->Caption,"-","+",TReplaceFlags());

        int j = 0;
        int *pObj = new int[sbMain->ControlCount];

        for(int i = 0; i < sbMain->ControlCount; i++)
        {
            if(sbMain->Controls[i]->Tag == (int)pCurLabel)
            {
                for(int k = 0; k < sbMain->ControlCount; k++)
                    if(sbMain->Controls[k]->Tag == (int)((TPanel *)sbMain->Controls[i])->Controls[0])
                        pObj[j++] = (int)sbMain->Controls[k];

                pObj[j++] = (int)sbMain->Controls[i];
            }
        }

        //sbMain->Visible = false;
        for(int i = 0; i < j; i++)
            delete (TPanel *)pObj[i];
        //sbMain->Visible = true;

        delete [] pObj;
    }
    else
    {
        // check or uncheck
        if(CurCheckedLabel && CurCheckedLabel != pCurLabel)
        {
            CurCheckedLabel->Color = clBackground;
            CurCheckedLabel->Font->Style = TFontStyles();
        }
        CurCheckedLabel = pCurLabel;

        if(pCurLabel->Color == clBackground)
        {
            pCurLabel->Color = clBlue;
            CurCheckedLabel->Font->Style = TFontStyles() << fsUnderline;
        }
        else
        {
            RescalForm = new TRescalForm(this);
            RescalForm->ServiceID = CurCheckedLabel->Tag;
            RescalForm->ShowModal();
            delete RescalForm;
        }

    }
}
//---------------------------------------------------------------------------
void __fastcall TReserveForm::AllImageClick(TObject *Sender,const char *Tag)
{
    __int64 *pIDs;
    AnsiString sRet, *pNames;
    unsigned cnt;

    sRet = Label6->Caption;
    cnt = sRet.Pos("/");
    sRet.SetLength(cnt);


    if(!Tag)
    {
        cnt = SQL_fldKeyCollect(DBName,"Name",("from Services where (Tag='~"+AnsiToUtf8("Парикмахерская")+"~' or Tag='~"+AnsiToUtf8("Ногтевой сервис")+"~') and WeekDays&127 order by Name").c_str(),&pIDs,&pNames,true);
        Label6->Caption = sRet + " " + "Салон красоты";
    }
    else
    {
        cnt = SQL_fldKeyCollect(DBName,"Name",("from Services where Tag='~"+AnsiToUtf8(Tag)+"~' and WeekDays&127 order by Name").c_str(),&pIDs,&pNames,true);
        Label6->Caption = sRet + " " + Tag;
    }
    TPanel *pBox;
    TLabel *pLabel;

    int top = Panel1->Top + Panel1->Height;
    //sbMain->Visible = false;
    for(unsigned i = 0; i < cnt; i++)
    {
        pBox = new TPanel(sbMain);
        pBox->Color = clBackground;
        pBox->BevelOuter = bvNone;
        pBox->Parent = sbMain;

        pBox->Height = 30;
        pBox->Top = top;
        pBox->Align = alTop;
        pBox->Tag = 0;

        top = pBox->Top + pBox->Height;

        pLabel = new TLabel(pBox);
        pLabel->Parent = pBox;

        pLabel->Top = 5;
        pLabel->Left = 138;
        pLabel->Font->Color = clWhite;
        pLabel->Font->Size = 11;

        SQL_exefun(DBName,("select count(*) from Services where ParentID="+AnsiString(pIDs[i])).c_str(),&sRet);
        if(atoi(sRet.c_str()) > 0)
            pLabel->Caption = "+ " + pNames[i];
        else
            pLabel->Caption = pNames[i];

        pLabel->OnClick = AllLabelClick;
        pLabel->Tag = pIDs[i];
    }
    //sbMain->Visible = true;

    delete [] pNames;
    delete [] pIDs;
}
//---------------------------------------------------------------------------
void __fastcall TReserveForm::ClearAllPans(void)
{
    CurCheckedLabel = NULL;
    delete sbMain;
    sbMain = new TScrollBox(this);
    sbMain->Parent = this;
    sbMain->Top = Panel1->Top + Panel1->Height;
    sbMain->BorderStyle = bsNone;
    sbMain->Align = alClient;
}
//---------------------------------------------------------------------------
void __fastcall TReserveForm::Image2Click(TObject *Sender)
{
    // Фитнесс
    ClearAllPans();
    //FitFlag = true;
    //AllImageClick(Sender,"Фитнесс");

    FitSheduleForm = new TFitSheduleForm(this);
    //FitSheduleForm->ServiceID = CurCheckedLabel->Tag;
    FitSheduleForm->ShowModal();
    delete FitSheduleForm;
}
//---------------------------------------------------------------------------
void __fastcall TReserveForm::Image1Click(TObject *Sender)
{
    ClearAllPans();
    //FitFlag = false;
    AllImageClick(Sender,"SPA");
}
//---------------------------------------------------------------------------
void __fastcall TReserveForm::Image5Click(TObject *Sender)
{
    ClearAllPans();
    //FitFlag = false;
    AllImageClick(Sender,"Баня");
}
//---------------------------------------------------------------------------
void __fastcall TReserveForm::Image3Click(TObject *Sender)
{
    ClearAllPans();
    //FitFlag = false;
    AllImageClick(Sender,NULL);
}
//---------------------------------------------------------------------------


