//---------------------------------------------------------------------------

#ifndef i_abtypesH
#define i_abtypesH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------
class TiAbTypesForm : public TForm
{
__published:	// IDE-managed Components
    TBevel *Bevel1;
    TCheckBox *cbAlive;
    TLabel *Label8;
    TLabel *Label2;
    TEdit *edName;
    TEdit *edCount;
    TLabel *Label1;
    TEdit *edPrice;
    TLabel *Label3;
    TEdit *edDays;
    TComboBox *lbPerson;
    TLabel *Label4;
    TLabel *Label5;
    TComboBox *lbService;
    TToolBar *tbDiscounts;
    TToolButton *tbSave;
    TToolButton *tbExit;
    TToolButton *ToolButton3;
    TImageList *iliAbTypes;
    TStatusBar *sbiAbTypes;
    TGroupBox *GroupBox1;
    TCheckBox *cbAutoFlow;
    TEdit *edFixSum;
    TLabel *Label6;
    void __fastcall tbExitClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall tbSaveClick(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall edPriceKeyPress(TObject *Sender, char &Key);
    void __fastcall edCountKeyPress(TObject *Sender, char &Key);
    void __fastcall edDaysKeyPress(TObject *Sender, char &Key);
    void __fastcall edFixSumKeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
    __fastcall TiAbTypesForm(TComponent* Owner);
    void __fastcall AbTypeSave(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TiAbTypesForm *iAbTypesForm;
//---------------------------------------------------------------------------
#endif