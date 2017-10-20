//---------------------------------------------------------------------------

#ifndef fitgroupH
#define fitgroupH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------
class TFitGroupForm : public TForm
{
__published:	// IDE-managed Components
    TToolBar *tbClients;
    TToolButton *tbExit;
    TImageList *ilBtnVisits;
    TImageList *ilBtnHotVisits;
    TStatusBar *StatusBar1;
    TStringGrid *sgShedule;
    TPanel *Panel1;
    TSpeedButton *sbMo;
    TSpeedButton *sbTu;
    TSpeedButton *sbWe;
    TSpeedButton *sbTh;
    TSpeedButton *sbFr;
    TSpeedButton *sbSa;
    TSpeedButton *sbSu;
    TToolButton *ToolButton1;
    TToolButton *ToolButton2;
    TSpeedButton *SpeedButton1;
    TSpeedButton *SpeedButton2;
    TSpeedButton *SpeedButton3;
    TLabel *laDate;
    TToolButton *ToolButton3;
    void __fastcall tbExitClick(TObject *Sender);
    void __fastcall sgSheduleDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall ToolButton1Click(TObject *Sender);
    void __fastcall sbMoClick(TObject *Sender);
    void __fastcall sgSheduleDblClick(TObject *Sender);
    void __fastcall ToolButton2Click(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall SpeedButton1Click(TObject *Sender);
    void __fastcall SpeedButton2Click(TObject *Sender);
    void __fastcall SpeedButton3Click(TObject *Sender);
    void __fastcall ToolButton3Click(TObject *Sender);
private:	// User declarations
    TDateTime CurrentDay;
    int CurrentWDay;
    int CurButton;
    int FirstButton;
    char *fldAlignShedule;

    int *SheduleWidths;

    TWndMethod sgOSheduleWindowProc;

    void __fastcall sgSheduleWindowProc(Messages::TMessage& Msg);
    void __fastcall sgSheduleFullUpdate(void);

public:		// User declarations
    __fastcall TFitGroupForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFitGroupForm *FitGroupForm;
//---------------------------------------------------------------------------
#endif
