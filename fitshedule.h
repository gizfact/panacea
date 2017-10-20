//---------------------------------------------------------------------------

#ifndef fitsheduleH
#define fitsheduleH
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
class TFitSheduleForm : public TForm
{
__published:	// IDE-managed Components
    TToolBar *tbClients;
    TToolButton *tbExit;
    TToolButton *ToolButton1;
    TToolButton *ToolButton2;
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
    TImageList *ilBtnVisits;
    TImageList *ilBtnHotVisits;
    TSplitter *Splitter1;
    TStringGrid *sgClients;
    TImageList *ilClients;
    void __fastcall tbExitClick(TObject *Sender);
    void __fastcall sbMoClick(TObject *Sender);
    void __fastcall sgSheduleDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall ToolButton1Click(TObject *Sender);
    void __fastcall sgClientsDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
    void __fastcall sgSheduleClick(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
private:	// User declarations
    char *fldAlignShedule;
    int *SheduleWidths;
    TWndMethod sgOSheduleWindowProc;

    char *fldAlignClients;
    int *ClientsWidths;
    TWndMethod sgOClientsWindowProc;

    TDateTime CurrentDay;
    unsigned CurrentWDay;
    //unsigned CurrentFDay;
    TSpeedButton *pButtons[7];
    int CurButton;

    void __fastcall sgSheduleFullUpdate(void);
    void __fastcall sgSheduleWindowProc(Messages::TMessage& Msg);

    void __fastcall sgClientsFullUpdate(void);
    void __fastcall sgClientsWindowProc(Messages::TMessage& Msg);

public:		// User declarations
    //__int64 ServiceID;

    __fastcall TFitSheduleForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFitSheduleForm *FitSheduleForm;
//---------------------------------------------------------------------------
#endif
