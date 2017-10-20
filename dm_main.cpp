//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "dm_main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TdmMain *dmMain;
//---------------------------------------------------------------------------
__fastcall TdmMain::TdmMain(TComponent* Owner)
    : TDataModule(Owner)
{

}
//---------------------------------------------------------------------------
bool __fastcall TdmMain::DBConnect(AnsiString &ConString)
{
    try
    {
        QueMain->Close();
        TransactionMain->Active = false;
        DBMain->Close();
        DBMain->DatabaseName = ConString;

        DBMain->Open();
    }
    catch(...)
    {
        QueMain->Close();
        TransactionMain->Active = false;
        DBMain->Close();
    }

    return DBMain->Connected;
}
//---------------------------------------------------------------------------
bool __fastcall TdmMain::SendMail(const char *toAddr, const char *Subject, const char *Body)
{
    objMsg->Body->Text = AnsiToUtf8(Body);
    //objMsg->From->Text = "it@aptekar76.ru";
    objMsg->Subject  = AnsiToUtf8(Subject);
    objMsg->Recipients->EMailAddresses = toAddr;

//objMsg->ContentType = "text/plain; charset=windows-1251";
    //objMsg->ContentType = "text/plain; format=flowed; charset=\"UTF-8\"";
    //objMsg->CharSet = "utf8";
    //objMsg->ContentTransferEncoding = "8bit";
//  objMsg->Priority = TIdMessagePriority(mpHighest);
//  objMsg->CCList->EMailAddresses = "it@aptekar76.ru";

    //objSMTP->Host = "mail.hostland.ru";
    //objSMTP->UserId = "it@aptekar76.ru";
    //objSMTP->Password = "Jut3JwR3";
    //objSMTP->Port = 2525;
    //objSMTP->AuthenticationType = atLogin;

    try
    {
        objSMTP->Connect();
        objSMTP->Send(objMsg);
    }
    catch(...)
    {
        if(objSMTP->Connected())
            objSMTP->Disconnect();

        return false;
    }

    if(objSMTP->Connected())
        objSMTP->Disconnect();

    return true;
}
//---------------------------------------------------------------------------



