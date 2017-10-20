//---------------------------------------------------------------------------

#ifndef i_discountsH
#define i_discountsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TiDiscountsForm : public TForm
{
__published:	// IDE-managed Components
    TToolBar *tbDiscounts;
    TToolButton *tbSave;
    TToolButton *ToolButton2;
    TToolButton *ToolButton3;
    TImageList *iliDiscounts;
    TPageControl *pcDiscount;
    TPanel *Panel1;
    TLabel *Label4;
    TLabel *Label8;
    TLabel *Label1;
    TLabel *Label2;
    TEdit *edName;
    TDateTimePicker *dtpBegDate;
    TCheckBox *cbAlive;
    TGroupBox *GroupBox1;
    TCheckBox *cbMon;
    TCheckBox *cbTue;
    TCheckBox *cbWed;
    TCheckBox *cbThu;
    TCheckBox *cbFri;
    TCheckBox *cbSat;
    TCheckBox *cbSun;
    TDateTimePicker *dtpEndDate;
    TEdit *edPercent;
    TStatusBar *StatusBar1;
    TTabSheet *tsMain;
    TTabSheet *tsAbTypes;
    TTabSheet *tsGoods;
    TTabSheet *tsServices;
    TBevel *Bevel1;
    TStringGrid *sgAbTypes;
    TStringGrid *sgGoods;
    TStringGrid *sgServices;
    void __fastcall tbSaveClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormKeyPress(TObject *Sender, char &Key);
    void __fastcall ToolButton2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TiDiscountsForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TiDiscountsForm *iDiscountsForm;
//---------------------------------------------------------------------------
#endif
