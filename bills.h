//---------------------------------------------------------------------------

#ifndef billsH
#define billsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TBillsForm : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TPanel *Panel2;
    TStringGrid *sgBills;
    TSplitter *Splitter1;
    TPanel *Panel3;
    TPanel *Panel4;
    TStringGrid *sgBillItems;
    TImageList *ilBills;
    TDateTimePicker *dtpBegDate;
    TDateTimePicker *dtpEndDate;
    TLabel *Label1;
    TButton *bCheck;
    TButton *bCancel;
    TGroupBox *GroupBox1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TLabel *Label5;
    TLabel *Label6;
    TLabel *laPay;
    TLabel *laDep;
    TLabel *laSell;
    TLabel *laFrom;
    TLabel *laChange;
    TCheckBox *cbOutcome;
    TLabel *Label7;
    TLabel *laTerminal;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall sgBillsSelectCell(TObject *Sender, int ACol, int ARow,
          bool &CanSelect);
    void __fastcall sgBillsDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
    void __fastcall sgBillItemsDrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State);
    void __fastcall dtpBegDateCloseUp(TObject *Sender);
    void __fastcall bCheckClick(TObject *Sender);
    void __fastcall bCancelClick(TObject *Sender);
private:	// User declarations
    char *sgBillsAligns;
    int *sgBillsWidths;
    TWndMethod sgOBillsWindowProc;

    char *sgBillItemsAligns;
    int *sgBillItemsWidths;
    TWndMethod sgOBillItemsWindowProc;

    void __fastcall sgBillsWindowProc(Messages::TMessage& Msg);
    void __fastcall sgBillItemsWindowProc(Messages::TMessage& Msg);
    void __fastcall sgBillsFullUpdate();
    void __fastcall sgBillItemsFullUpdate(int);
public:		// User declarations
    //AnsiString retString;
    AnsiString retS;

    __fastcall TBillsForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TBillsForm *BillsForm;
//---------------------------------------------------------------------------
#endif
