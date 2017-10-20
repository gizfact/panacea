//---------------------------------------------------------------------------

#ifndef reserveH
#define reserveH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>


//---------------------------------------------------------------------------
class TReserveForm : public TForm
{
__published:	// IDE-managed Components
    TImageList *ilBtnVisits;
    TImageList *ilBtnHotVisits;
    TToolBar *tbClients;
    TToolButton *tbExit;
    TStatusBar *StatusBar1;
    TImage *Image1;
    TLabel *Label1;
    TImage *Image2;
    TLabel *Label2;
    TImage *Image3;
    TLabel *Label3;
    TImage *Image4;
    TLabel *Label4;
    TImage *Image5;
    TLabel *Label5;
    TLabel *Label9;
    TLabel *Label10;
    TLabel *Label11;
    TLabel *Label12;
    TLabel *Label13;
    TLabel *Label14;
    TLabel *Label15;
    TLabel *Label16;
    TLabel *Label17;
    TLabel *Label18;
    TPanel *Panel1;
    TLabel *Label6;
    TBevel *Bevel1;
    TScrollBox *sbMain;
    void __fastcall tbExitClick(TObject *Sender);
    void __fastcall Image2Click(TObject *Sender);
    void __fastcall Image1Click(TObject *Sender);
    void __fastcall Image5Click(TObject *Sender);
    void __fastcall Image3Click(TObject *Sender);
private:	// User declarations
    //bool FitFlag;

   

    //void __fastcall FullUpdate(void);
    //void __fastcall ClearCalendar(void);
    //void __fastcall PanClick(TObject *Sender,
    //  TMouseButton Button, TShiftState Shift, int X, int Y);

public:		// User declarations
    //int **pDays;
    //unsigned DaysCount;
    //int **pPersons;
    //__int64 *pPersonIDs;
    //AnsiString *pPersonNames;
    //unsigned PersonCount;
    //int **pHeaders;
    //TDateTime CurrentFDay;

    TLabel *CurCheckedLabel;

    __fastcall TReserveForm(TComponent* Owner);
    void __fastcall AllLabelClick(TObject *Sender);
    void __fastcall AllImageClick(TObject *Sender,const char *Tag);
    void __fastcall ClearAllPans(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TReserveForm *ReserveForm;
//---------------------------------------------------------------------------
#endif
