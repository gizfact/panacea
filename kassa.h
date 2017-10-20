//---------------------------------------------------------------------------

#ifndef kassaH
#define kassaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>
#include <Menus.hpp>


//---------------------------------------------------------------------------

typedef struct
{
    __int64 GoodID;
    int MaxCount;
} BillGood;

class TKassaForm : public TForm
{
__published:	// IDE-managed Components
    TStatusBar *sbKassa;
    TLabel *Label1;
    TToolBar *ToolBar1;
    TImageList *ilKassa;
    TPanel *Panel1;
    TToolButton *tbD2;
    TToolButton *tbD1;
    TLabel *laBegBalanse;
    TPanel *Panel2;
    TStringGrid *sgKassa;
    TLabel *laTotal;
    TEdit *edInput;
    TEdit *edGetSum;
    TLabel *Label2;
    TLabel *laChange;
    TLabel *laEndBalanse;
    TEdit *edFromBalanse;
    TLabel *Label3;
    TLabel *Label4;
    TLabel *Label5;
    TBevel *Bevel1;
    TLabel *Label6;
    TSpeedButton *sbBalanseUp;
    TSpeedButton *sbGetSumUp;
    TEdit *edToBalanse;
    TButton *tbBilling;
    TButton *tbAbAdd;
    TLabel *laDiscount;
    TSpeedButton *spbPayment;
    TButton *tbSPAVisit;
    TButton *tbAbSPAAdd;
    TButton *Button1;
    TButton *Button2;
    TButton *Button3;
    TButton *Button4;
    TButton *Button5;
    TToolButton *ToolButton3;
    TButton *Button6;
    TButton *tbSave;
    TSpeedButton *sbChangeUp;
    TLabel *Label7;
    TLabel *Label8;
    TLabel *Label9;
    TLabel *Label10;
    TEdit *edTerminal;
    TSpeedButton *SpeedButton1;
    TLabel *Label11;
    void __fastcall tbExit0Click(TObject *Sender);
    void __fastcall tbSave0Click(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall tbBAddClick(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall sgKassaDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
    void __fastcall tbSAddClick(TObject *Sender);
    void __fastcall edInputExit(TObject *Sender);
    void __fastcall edInputKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall edGetSumKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall edGetSumKeyPress(TObject *Sender, char &Key);
    void __fastcall tbCancel0Click(TObject *Sender);
    void __fastcall edInputKeyPress(TObject *Sender, char &Key);
    void __fastcall edGetSumExit(TObject *Sender);
    void __fastcall edFromBalanseExit(TObject *Sender);
    void __fastcall edFromBalanseKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall sbBalanseUpClick(TObject *Sender);
    void __fastcall sbGetSumUpClick(TObject *Sender);
    void __fastcall tbDelClick(TObject *Sender);
    void __fastcall tbEditClick(TObject *Sender);
    void __fastcall edToBalanseExit(TObject *Sender);
    void __fastcall edToBalanseKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall edToBalanseKeyPress(TObject *Sender, char &Key);
    void __fastcall edFromBalanseKeyPress(TObject *Sender, char &Key);
    void __fastcall spbPaymentClick(TObject *Sender);
    void __fastcall tbAbSPAAddClick(TObject *Sender);
    void __fastcall tbSPAVisitClick(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall edToBalanseChange(TObject *Sender);
    void __fastcall edFromBalanseChange(TObject *Sender);
    void __fastcall tbAbAddClick(TObject *Sender);
    void __fastcall Button3Click(TObject *Sender);
    void __fastcall Button4Click(TObject *Sender);
    void __fastcall Button5Click(TObject *Sender);
    void __fastcall Button6Click(TObject *Sender);
    void __fastcall sbChangeUpClick(TObject *Sender);
    void __fastcall spbTerminalClick(TObject *Sender);
    void __fastcall edTerminalKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall edTerminalExit(TObject *Sender);
    void __fastcall SpeedButton1Click(TObject *Sender);
private:	// User declarations


    int *KassaWidths;

    DynamicArray<BillGood> arMaxCount;
    int GoodsCount;

    __int64 SessionBillID;
    __int64 __fastcall Billing(void);

public:		// User declarations
    bool InTransaction;

    int KassaOps;
    unsigned Counter;
    DynamicArray<__int64> IDs;
    double Total;

    TDateTime ResBegDate;
    TDateTime ResEndDate;

    __int64 ResServiceID;
    __int64 ResPersonID;
    int ResQuan;

    char *fldAlign;
    AnsiString *pAbFields;
    //unsigned pAbFieldsCounter;

    __fastcall TKassaForm(TComponent* Owner);
    void __fastcall sgWindowProc(Messages::TMessage& Msg);
    void __fastcall edInputSave(void);
    void __fastcall KassaUpdateInfo(void);

    //TList* __fastcall BuildBill(__int64, int *, int *);
};
//---------------------------------------------------------------------------
extern PACKAGE TKassaForm *KassaForm;
//---------------------------------------------------------------------------
#endif
