//---------------------------------------------------------------------------
#ifndef clientsH
#define clientsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ToolWin.hpp>
#include <ImgList.hpp>
#include <Grids.hpp>
#include <jpeg.hpp>
#include <Graphics.hpp>
#include <Buttons.hpp>
#include <Dialogs.hpp>
#include <Menus.hpp>
#include <Tabs.hpp>
#include <Mask.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TClientsForm : public TForm
{
__published:	// IDE-managed Components
    TStatusBar *sbClients;
    TToolBar *tbClients;
    TPanel *Panel1;
    TToolButton *tbAdd;
    TImageList *ilClientsButtons;
    TPanel *Panel2;
    TToolButton *tbReload;
    TToolButton *tbEdit;
    TImageList *ilClients;
    TStringGrid *sgClients;
    TSplitter *Splitter1;
    TEdit *edSearchStr;
    TLabel *Label1;
    TCheckBox *cbFName;
    TLabel *Label2;
    TCheckBox *cbSName;
    TLabel *Label3;
    TCheckBox *cbTName;
    TLabel *Label4;
    TTimer *timPhoto;
    TPanel *Panel5;
    TPanel *Panel4;
    TPanel *paPhoto;
    TImage *imClients;
    TButton *Button1;
    TButton *Button2;
    TLabel *laPhone2;
    TLabel *Label5;
    TLabel *Label6;
    TLabel *laCardNum;
    TLabel *Label8;
    TLabel *laCardDate;
    TLabel *Label10;
    TLabel *Label11;
    TLabel *Label12;
    TMemo *meClients;
    TLabel *laPhone1;
    TLabel *laRegDate;
    TCheckBox *cbCID;
    TLabel *Label7;
    TCheckBox *cbAlive;
    TCheckBox *cbNotAlive;
    TImage *imGreen;
    TImage *imRed;
    TToolButton *tbExit;
    TToolButton *ToolButton1;
    TToolButton *ToolButton2;
    TToolButton *tbHome;
    TToolButton *tbDoubles;
    TToolButton *ToolButton5;
    TToolButton *tbKassa;
    TPanel *Panel6;
    TSplitter *Splitter2;
    TLabel *Label9;
    TLabel *laDiscount;
    TCheckBox *cbShowAbClosed;
    TEdit *edPSearchStr;
    TLabel *Label14;
    TLabel *laDiscountSPA;
    TLabel *laDiscountAll;
    TBevel *Bevel1;
    TLabel *Label15;
    TLabel *Label16;
    TBevel *Bevel2;
    TBevel *Bevel3;
    TLabel *Label17;
    TSpeedButton *spbVisit;
    TLabel *Label18;
    TEdit *edScanSearch;
    TSplitter *Splitter3;
    TImageList *ImageList1;
    TToolButton *ToolButton3;
    TToolButton *ToolButton4;
    TSpeedButton *laBalanse;
    TTimer *timSearch;
    TPanel *Panel10;
    TListBox *lbFitService;
    TPanel *Panel11;
    TSplitter *Splitter5;
    TStringGrid *sgNotes;
    TPanel *Panel12;
    TMemo *meNote;
    TLabel *Label20;
    TPanel *Panel13;
    TPageControl *pcResTree;
    TTabSheet *TabSheet3;
    TTabSheet *TabSheet4;
    TSplitter *Splitter8;
    TPanel *Panel14;
    TSpeedButton *sbFitMo;
    TSpeedButton *sbFitTu;
    TSpeedButton *sbFitWe;
    TSpeedButton *sbFitTh;
    TSpeedButton *sbFitFr;
    TSpeedButton *sbFitSa;
    TSpeedButton *sbFitSu;
    TStringGrid *sgFitShedule;
    TStringGrid *sgResClients;
    TTabSheet *TabSheet5;
    TTabSheet *TabSheet6;
    TTabSheet *TabSheet7;
    TPanel *Panel8;
    TSpeedButton *SpeedButton2;
    TSpeedButton *sbRes;
    TSpeedButton *SpeedButton4;
    TCheckBox *cbClosedReserve;
    TStringGrid *sgReserve;
    TSplitter *Splitter6;
    TPanel *Panel15;
    TSpeedButton *sbMGMo;
    TSpeedButton *sbMGTu;
    TSpeedButton *sbMGWe;
    TSpeedButton *sbMGTh;
    TSpeedButton *sbMGFr;
    TSpeedButton *sbMGSa;
    TSpeedButton *sbMGSu;
    TStringGrid *sgMGTiming;
    TPanel *Panel16;
    TTreeView *tvMG;
    TSplitter *Splitter7;
    TPanel *Panel17;
    TComboBox *cbMGPerson;
    TPanel *Panel18;
    TSpeedButton *sbBathMo;
    TSpeedButton *sbBathTu;
    TSpeedButton *sbBathWe;
    TSpeedButton *sbBathTh;
    TSpeedButton *sbBathFr;
    TSpeedButton *sbBathSa;
    TSpeedButton *sbBathSu;
    TPanel *Panel19;
    TTreeView *tvBath;
    TPanel *Panel20;
    TComboBox *cbBathPerson;
    TSplitter *Splitter9;
    TStringGrid *sgBathTiming;
    TPanel *paBathBuf;
    TStringGrid *sgBathBuf;
    TPanel *paBathBufOK;
    TSpeedButton *sbBathBufOK;
    TSpeedButton *sbBathBufCan;
    TSpeedButton *sbBathBufDel;
    TPanel *Panel21;
    TTreeView *tvSK;
    TPanel *Panel22;
    TComboBox *cbSKPerson;
    TStringGrid *sgSKTiming;
    TPanel *Panel23;
    TSpeedButton *sbSKMo;
    TSpeedButton *sbSKTu;
    TSpeedButton *sbSKWe;
    TSpeedButton *sbSKTh;
    TSpeedButton *sbSKFr;
    TSpeedButton *sbSKSa;
    TSpeedButton *sbSKSu;
    TSplitter *Splitter10;
    TSpeedButton *sbFitAlt;
    TSpeedButton *sbMGAlt;
    TSpeedButton *sbSKAlt;
    TSpeedButton *sbBathAlt;
    TSpeedButton *spbClosing;
    TSpeedButton *sbDelRes;
    TSpeedButton *spbFitDChange;
    TToolButton *tbReserved;
    TToolButton *ToolButton6;
    TButton *bVisPhone;
    TStringGrid *sgAbonements;
    TPanel *Panel25;
    TStringGrid *sgAbonementsBath;
    TPanel *Panel7;
    TStringGrid *sgAbonementsSPA;
    TListBox *lbSPAMenu;
    TPanel *Panel9;
    TSpeedButton *SpeedButton1;
    TSpeedButton *spbClosingSPA;
    TPanel *Panel24;
    TCheckBox *cbShowAbSPAClosed;
    TSplitter *Splitter11;
    TSplitter *Splitter4;
    TPanel *Panel26;
    TSpeedButton *SpeedButton5;
    TSpeedButton *spbClosingBath;
    TCheckBox *cbShowAbBathClosed;
    TSpeedButton *sbBath1;
    TSpeedButton *sbBath2;
    TSpeedButton *sbBath3;
    TPanel *paBathRes;
    TSpeedButton *SpeedButton7;
    TPanel *Panel28;
    TTreeView *tvBathRes;
    TPanel *Panel29;
    TComboBox *cbBathResPerson;
    TPanel *Panel3;
    TStringGrid *sgBathResGroup;
    TPanel *paBathResInfo;
    TSpeedButton *sbBathResOK;
    TSpeedButton *sbBathResCan;
    TSpeedButton *sbBathResDel;
    TLabel *laAltSuml;
    TLabel *laBathSuml;
    TPanel *Panel27;
    TLabel *laClient;
    TLabel *laBathSum;
    TLabel *laAltSum;
    TSpeedButton *sbBathBufX;
    TSplitter *Splitter12;
    TSplitter *Splitter13;
    TSplitter *Splitter14;
    TPopupMenu *PopupMenu1;
    TMenuItem *pbReportZ;
    TMenuItem *pbReportX;
    TToolButton *tbKKM;
    TMenuItem *N1;
    TMenuItem *pbOutcome;
    TMenuItem *N3;
    TMenuItem *pbSettings;
    TMenuItem *pbBills;
    TMenuItem *pbIncome;
    TSpeedButton *sbBathVisit;
    void __fastcall tbAddClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall sgClientsDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
    void __fastcall sgClientsSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
    void __fastcall tbReloadClick(TObject *Sender);
    void __fastcall timPhotoTimer(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall cbFNameClick(TObject *Sender);
    void __fastcall cbSNameClick(TObject *Sender);
    void __fastcall cbTNameClick(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall cbCIDClick(TObject *Sender);
    void __fastcall cbAliveClick(TObject *Sender);
    void __fastcall cbNotAliveClick(TObject *Sender);
    void __fastcall tbHomeClick(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall tbExitClick(TObject *Sender);
    void __fastcall tbEditClick(TObject *Sender);
    void __fastcall sgClientsKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall edSearchStrKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall tbKassaClick(TObject *Sender);
    void __fastcall sgAbonementsDrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State);
    void __fastcall sgAbonementsDblClick(TObject *Sender);
    void __fastcall cbShowAbClosedClick(TObject *Sender);
    void __fastcall spbVisitClick(TObject *Sender);
    void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall sgAbonementsKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall edScanSearchKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall tbDoublesClick(TObject *Sender);
    void __fastcall sgAbonementsSPADrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State);
    void __fastcall cbShowAbSPAClosedClick(TObject *Sender);
    void __fastcall sgAbonementsSPADblClick(TObject *Sender);
    void __fastcall meClientsExit(TObject *Sender);
    void __fastcall SpeedButton1Click(TObject *Sender);
    void __fastcall laBalanseClick(TObject *Sender);
    void __fastcall timSearchTimer(TObject *Sender);
    void __fastcall spbClosingSPAClick(TObject *Sender);
    void __fastcall Panel9MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall lbSPAMenuExit(TObject *Sender);
    void __fastcall lbSPAMenuDblClick(TObject *Sender);
    void __fastcall lbSPAMenuKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall Panel10MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall lbFitServiceExit(TObject *Sender);
    void __fastcall sgNotesDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
    void __fastcall meNoteExit(TObject *Sender);
    void __fastcall sgReserveDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
    void __fastcall SpeedButton4Click(TObject *Sender);
    void __fastcall sbResClick(TObject *Sender);
    void __fastcall dtpResDateChange(TObject *Sender);
    void __fastcall cbClosedReserveClick(TObject *Sender);

    void __fastcall sgResClientsDrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State);
    void __fastcall sbFitMoClick(TObject *Sender);
    void __fastcall sgFitSheduleDrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State);
    void __fastcall TabSheet4Show(TObject *Sender);
    void __fastcall sgFitSheduleDblClick(TObject *Sender);
    void __fastcall sgResClientsClick(TObject *Sender);
    void __fastcall sgFitSheduleClick(TObject *Sender);
    void __fastcall pcResTreeDrawTab(TCustomTabControl *Control,
          int TabIndex, const TRect &Rect, bool Active);
    void __fastcall sgNotesClick(TObject *Sender);
    void __fastcall sbMGMoClick(TObject *Sender);
    void __fastcall TabSheet5Show(TObject *Sender);
    void __fastcall sgMGTimingDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
    void __fastcall cbMGPersonSelect(TObject *Sender);
    void __fastcall sgMGTimingDblClick(TObject *Sender);
    void __fastcall sgMGTimingClick(TObject *Sender);
    void __fastcall TabSheet7Show(TObject *Sender);
    void __fastcall sbBathMoClick(TObject *Sender);
    void __fastcall cbBathPersonSelect(TObject *Sender);
    void __fastcall sgBathTimingClick(TObject *Sender);
    void __fastcall sgBathTimingDblClick(TObject *Sender);
    void __fastcall sgBathTimingDrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State);
    void __fastcall sgBathBufGetEditMask(TObject *Sender, int ACol,
          int ARow, AnsiString &Value);
    void __fastcall sgBathBufSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
    void __fastcall sgBathBufDrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State);
    void __fastcall sbBathBufOKClick(TObject *Sender);
    void __fastcall sbBathBufCanClick(TObject *Sender);
    void __fastcall sbBathBufDelClick(TObject *Sender);
    void __fastcall tvBathDblClick(TObject *Sender);
    void __fastcall SpeedButton2Click(TObject *Sender);
    void __fastcall TabSheet6Show(TObject *Sender);
    void __fastcall sgSKTimingDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
    void __fastcall sgSKTimingClick(TObject *Sender);
    void __fastcall sgSKTimingDblClick(TObject *Sender);
    void __fastcall cbSKPersonSelect(TObject *Sender);
    void __fastcall sbSKMoClick(TObject *Sender);
    void __fastcall Splitter9Moved(TObject *Sender);
    void __fastcall tvMGClick(TObject *Sender);
    void __fastcall spbClosingClick(TObject *Sender);
    void __fastcall sbDelResClick(TObject *Sender);
    void __fastcall spbFitDChangeClick(TObject *Sender);
    void __fastcall tbReservedClick(TObject *Sender);
    void __fastcall ToolButton6Click(TObject *Sender);
    void __fastcall edScanSearchEnter(TObject *Sender);
    void __fastcall bVisPhoneExit(TObject *Sender);
    void __fastcall bVisPhoneClick(TObject *Sender);
    void __fastcall sgAbonementsBathDrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State);
    void __fastcall cbShowAbBathClosedClick(TObject *Sender);
    void __fastcall spbClosingBathClick(TObject *Sender);
    void __fastcall sbBath1Click(TObject *Sender);
    void __fastcall SpeedButton7Click(TObject *Sender);
    void __fastcall sbBathResCanClick(TObject *Sender);
    void __fastcall sgBathResGroupDrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State);
    void __fastcall sgBathResGroupGetEditMask(TObject *Sender, int ACol,
          int ARow, AnsiString &Value);
    void __fastcall sgBathResGroupSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
    void __fastcall sbBathResDelClick(TObject *Sender);
    void __fastcall tvBathResDblClick(TObject *Sender);
    void __fastcall sbBathResOKClick(TObject *Sender);
    void __fastcall sgBathBufDblClick(TObject *Sender);
    void __fastcall sgBathResGroupClick(TObject *Sender);
    void __fastcall sbBathBufXClick(TObject *Sender);
    void __fastcall sgReserveSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
    void __fastcall tvBathResChanging(TObject *Sender, TTreeNode *Node,
          bool &AllowChange);
    void __fastcall paBathResInfoResize(TObject *Sender);
    void __fastcall paBathBufOKResize(TObject *Sender);
    void __fastcall tbKKMClick(TObject *Sender);
    void __fastcall pbReportZClick(TObject *Sender);
    void __fastcall pbReportXClick(TObject *Sender);
    void __fastcall pbSettingsClick(TObject *Sender);
    void __fastcall pbOutcomeClick(TObject *Sender);
    void __fastcall sgAbonementsBathDblClick(TObject *Sender);
    void __fastcall sbBathVisitClick(TObject *Sender);
    void __fastcall SpeedButton5Click(TObject *Sender);

private:	// User declarations


    double BathPrice;
    double BathHours;

    char *fldAlignFitShedule;
    int *FitSheduleWidths;
    TWndMethod sgOFitSheduleWindowProc;

    char *fldAlignResClients;
    int *ResClientsWidths;
    TWndMethod sgOResClientsWindowProc;

    TDateTime CurrentDay;
    //unsigned CurrentWDay;



    TDateTime FitCurrentDay;
    TSpeedButton *pFitButtons[8];
    int FitCurButton;

    TDateTime MGCurrentDay;
    TSpeedButton *pMGButtons[8];
    int MGCurButton;

    TDateTime SKCurrentDay;
    TSpeedButton *pSKButtons[8];
    int SKCurButton;

    TDateTime BathCurrentDay;
    TSpeedButton *pBathButtons[8];
    int BathCurButton;

    const char *fldAlignAbs;
    const char *fldAlignCli;
    const char *fldAlignNotes;
    const char *fldAlignReserve;


    int *ClientsWidths;
    int *AbsWidths;
    int *AbsSPAWidths;
    int *AbsBathWidths;
    int *NotesWidths;
    int *ReserveWidths;

    int *sgMGTimingWidths;
    int *sgSKTimingWidths;
    int *sgBathTimingWidths;
    int *sgBathBufWidths;
    int *sgBathResGroupWidths;

    const char *sgMGTimingAligns;
    const char *sgSKTimingAligns;
    const char *sgBathTimingAligns;
    const char *fldAlignBathBuf;
    const char *fldAlignBathResGroup;

    TWndMethod sgOCliWindowProc;
    TWndMethod sgOAbonementsWindowProc;
    TWndMethod sgOAbonementsSPAWindowProc;
    TWndMethod sgOAbonementsBathWindowProc;
    TWndMethod sgONotesWindowProc;
    TWndMethod sgOReserveWindowProc;
    TWndMethod sgOMGTimingWindowProc;
    TWndMethod sgOSKTimingWindowProc;
    TWndMethod sgOBathTimingWindowProc;
    TWndMethod sgOBathBufWindowProc;
    TWndMethod sgOBathResGroupWindowProc;

    void __fastcall sgSheduleWindowProc(Messages::TMessage& Msg);
    void __fastcall sgResClientsWindowProc(Messages::TMessage& Msg);
    void __fastcall sgFitSheduleWindowProc(Messages::TMessage& Msg);


    void __fastcall sgResClientsFullUpdate(bool fTop = false);
    void __fastcall sgFitSheduleFullUpdate(bool fTop = false);

    void __fastcall tvMGFullUpdate(void);

    void __fastcall tvSKFullUpdate(void);

    void __fastcall sgMGTimingWindowProc(Messages::TMessage& Msg);
    void __fastcall sgMGTimingUpdate(__int64 pid,TDateTime dt,__int64 SelID = 0);

    void __fastcall sgSKTimingWindowProc(Messages::TMessage& Msg);
    void __fastcall sgSKTimingUpdate(__int64 pid,TDateTime dt,__int64 SelID = 0);

    void __fastcall tvBathFullUpdate(void);
    void __fastcall sgBathTimingWindowProc(Messages::TMessage& Msg);
    void __fastcall sgBathBufWindowProc(Messages::TMessage& Msg);
    void __fastcall sgBathTimingUpdate(__int64 pid,TDateTime dt,__int64 SelID = 0);

    void __fastcall AddTreeLevel(TTreeNode *pNode,int day);
    void __fastcall SetBathPrice(void);
    void __fastcall CalcBathPrice(void);
    double __fastcall DisBathPrice(int h);
    void __fastcall CheckKKMButtons(void);

    bool __fastcall LoadKassa(__int64);

    void __fastcall MirrorClubCard(__int64);

public:		// User declarations
    bool BackFlag;
    __int64 *IDs;
    unsigned Counter;

    __int64 *ReserveIDs;
    unsigned ReserveCounter;

    __int64 *NoteIDs;
    unsigned NoteCounter;

    DynamicArray<__int64> AbonementsUpdIDs;
    unsigned AbonementsUpdCounter;

    DynamicArray<__int64> AbonementsSPAUpdIDs;
    unsigned AbonementsSPAUpdCounter;

    __fastcall TClientsForm(TComponent* Owner);
    void __fastcall sgClientsFullUpdate(void);
    void __fastcall sgClientsUpdate(void);
    void __fastcall sgClientsRowInfo(__int64 *, unsigned);

    void __fastcall NotesUpdate(__int64 *, unsigned);

    void __fastcall sgClientsRowUpdate(__int64 *, unsigned);
    void __fastcall sgCliWindowProc(Messages::TMessage& Msg);
    //void __fastcall sgSellsRowInfo(__int64 *pID, unsigned cnt);
    //void __fastcall sgSellsFullUpdate(__int64);
    void __fastcall sgAbonementsFullUpdate(__int64,__int64 LastAbID=0);
    void __fastcall sgAbonementsBathFullUpdate(__int64,__int64 LastAbID=0);
    void __fastcall AbsSPAFullCheck(void);
    void __fastcall sgAbonementsSPAFullUpdate(__int64,__int64 LastAbID=0);
    void __fastcall sgReserveFullUpdate(__int64 LastRecID=0);
    //void __fastcall sgSellsWindowProc(Messages::TMessage& Msg);
    void __fastcall sgAbonementsWindowProc(Messages::TMessage& Msg);
    void __fastcall sgReserveWindowProc(Messages::TMessage& Msg);
    void __fastcall sgAbonementsSPAWindowProc(Messages::TMessage& Msg);
    void __fastcall sgAbonementsBathWindowProc(Messages::TMessage& Msg);
    void __fastcall sgNotesWindowProc(Messages::TMessage& Msg);
    void __fastcall sgBathResGroupWindowProc(Messages::TMessage& Msg);
    void __fastcall sgOldClientsUpdate(void);
    void __fastcall AbsFullCheck(void);
    double __fastcall SPADiscount(__int64);

    void __fastcall CloseAllReserved(void);

    void __fastcall sgClientsScan(void);
    void __fastcall SpisFromSPA(__int64,bool,bool ForCash = false);


};


//---------------------------------------------------------------------------
extern PACKAGE TClientsForm *ClientsForm;
//---------------------------------------------------------------------------
#endif
