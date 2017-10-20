//---------------------------------------------------------------------------

#ifndef dm_mainH
#define dm_mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <IBDatabase.hpp>
#include <IBCustomDataSet.hpp>
#include <IBQuery.hpp>
#include <IBSQL.hpp>
#include <Dialogs.hpp>
#include <ADODB.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdMessageClient.hpp>
#include <IdSMTP.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <IdMessage.hpp>
//---------------------------------------------------------------------------
class TdmMain : public TDataModule
{
__published:	// IDE-managed Components
    TDataSource *DSMain;
    TIBQuery *QueMain;
    TIBTransaction *TransactionMain;
    TIBDatabase *DBMain;
    TIBSQL *SQLMain;
    TSaveDialog *dlgSave;
    TADOQuery *ADOQue;
    TDataSource *dsADO;
    TADOConnection *ADOConn;
    TIBDatabase *DBAlt;
    TIdSMTP *objSMTP;
    TIdMessage *objMsg;
private:	// User declarations
public:		// User declarations


    __fastcall TdmMain(TComponent* Owner);

    bool __fastcall SendMail(const char *,const char *,const char *);

    bool __fastcall DBConnect(AnsiString &);

};
//---------------------------------------------------------------------------
extern PACKAGE TdmMain *dmMain;
//---------------------------------------------------------------------------
#endif
