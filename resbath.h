//---------------------------------------------------------------------------

#ifndef resbathH
#define resbathH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TResBathForm : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TPanel *Panel2;
    TPageControl *pcResBath;
    TTabSheet *TabSheet1;
    TTabSheet *TabSheet2;
    TStringGrid *sgM3;
    TStringGrid *sgM2;
    TStringGrid *sgM1;
    TPanel *Panel3;
    TPanel *Panel14;
    TSpeedButton *sbFitMo;
    TSpeedButton *sbFitTu;
    TSpeedButton *sbFitWe;
    TSpeedButton *sbFitTh;
    TSpeedButton *sbFitFr;
    TSpeedButton *sbFitSa;
    TSpeedButton *sbFitSu;
    TSpeedButton *sbFitAlt;
    TStringGrid *sgF3;
    TStringGrid *sgF2;
    TStringGrid *sgF1;
    TMaskEdit *edInput;
    TButton *Button1;
    TButton *Button2;
    TButton *Button3;
    TButton *Button4;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall sgM1DrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
    void __fastcall sgM1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall sbFitMoClick(TObject *Sender);
    void __fastcall TabSheet1Show(TObject *Sender);
    void __fastcall TabSheet2Show(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall sgM1DblClick(TObject *Sender);
    void __fastcall edInputExit(TObject *Sender);
    void __fastcall sgM1SelectCell(TObject *Sender, int ACol, int ARow,
          bool &CanSelect);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Button3Click(TObject *Sender);
    void __fastcall Button4Click(TObject *Sender);
private:	// User declarations
    TStringGrid *sgCur;
    TDateTime ResTime;
    TStringGrid *sgCli;
    int CliCol, CliRow;

    TWndMethod sgOM1WindowProc;
    const char *fldAlignM1;
    int *M1Widths;

    TWndMethod sgOM2WindowProc;
    //const char *fldAlignM2;
    int *M2Widths;

    TWndMethod sgOM3WindowProc;
    //const char *fldAlignM3;
    int *M3Widths;

    TWndMethod sgOF1WindowProc;
    int *F1Widths;

    TWndMethod sgOF2WindowProc;
    int *F2Widths;

    TWndMethod sgOF3WindowProc;
    int *F3Widths;

    //TDateTime CurrentDay;

    TDateTime FitCurrentDay;
    TSpeedButton *pFitButtons[8];
    int FitCurButton;

    int CurAb;

    //bool NewFlag;
    //int EditCol;
    bool EditMode;
    TDateTime Date1;
    TDateTime Date2;

    void __fastcall sgM1WindowProc(Messages::TMessage&);
    void __fastcall sgM2WindowProc(Messages::TMessage&);
    void __fastcall sgM3WindowProc(Messages::TMessage&);
    void __fastcall sgF1WindowProc(Messages::TMessage&);
    void __fastcall sgF2WindowProc(Messages::TMessage&);
    void __fastcall sgF3WindowProc(Messages::TMessage&);
    void __fastcall lvAlignTextDraw(TListView *,TListItem *,TRect &,const char *alignment=NULL);
    void __fastcall sgResBathSheduleFullUpdate(void);
    void __fastcall sgEdit(void);

    void __fastcall ReserveSave(void);


public:		// User declarations
    __fastcall TResBathForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TResBathForm *ResBathForm;
//---------------------------------------------------------------------------
#endif
