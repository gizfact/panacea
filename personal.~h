//---------------------------------------------------------------------------

#ifndef personalH
#define personalH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TPersonalForm : public TForm
{
__published:	// IDE-managed Components
    TStatusBar *sbPersonal;
    TToolBar *ToolBar1;
    TToolButton *ToolButton1;
    TToolButton *tbEdit;
    TToolButton *tbSave;
    TToolButton *ToolButton2;
    TToolButton *tbExit;
    TToolButton *ToolButton4;
    TPanel *Panel1;
    TStringGrid *sgPersonal;
    TImageList *ilBtnPersonal;
    TToolButton *tbNew;
    TImageList *ilPersonal;
    TToolButton *tbAlive;
    TEdit *edInput;
    TPopupMenu *pmServices;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall sgPersonalDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall tbExitClick(TObject *Sender);
    void __fastcall tbNewClick(TObject *Sender);
    void __fastcall sgPersonalDblClick(TObject *Sender);
    void __fastcall edInputExit(TObject *Sender);
    void __fastcall edInputKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall tbSaveClick(TObject *Sender);
    void __fastcall sgPersonalSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
    void __fastcall tbEditClick(TObject *Sender);
    void __fastcall tbAliveClick(TObject *Sender);
    void __fastcall sgPersonalKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall sgPersonalMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
private:	// User declarations

public:		// User declarations
    DynamicArray<__int64> IDs;
    unsigned Counter;

    TDateTime CDate, EDate;
    __int64 CUID, EUID, PersonID;
    AnsiString retString;
    TWndMethod sgOWindowProc;

    bool NewFlag;
    bool EditMode;

    AnsiString *pUsers;
    __int64 *pUserIDs;
    unsigned UsersCounter;

    int EditCol;
    AnsiString PersonName;
    AnsiString PersonJob;

    unsigned UpdatedRow;

    AnsiString *pServices;
    __int64 *pServicesIDs;

    __fastcall TPersonalForm(TComponent* Owner);
    void __fastcall sgWindowProc(Messages::TMessage& Msg);
    void __fastcall sgPersonalFullUpdate(void);
    void __fastcall sgPersonalRowInfo(DynamicArray<__int64> pID, unsigned cnt);
    void __fastcall sgPersonalEdit(void);
    void __fastcall PersonalSave(void);
    void __fastcall sgPersonalNew(void);

    void __fastcall pmServicesClick(TObject *);
};
//---------------------------------------------------------------------------
extern PACKAGE TPersonalForm *PersonalForm;
//---------------------------------------------------------------------------
#endif
