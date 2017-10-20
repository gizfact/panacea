//---------------------------------------------------------------------------

#ifndef i_clientsH
#define i_clientsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ToolWin.hpp>
#include <ImgList.hpp>
#include <Mask.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
//---------------------------------------------------------------------------
class TiClientsForm : public TForm
{
__published:	// IDE-managed Components
    TStatusBar *sbiClients;
    TToolBar *ToolBar1;
    TPanel *Panel1;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TLabel *Label5;
    TLabel *Label6;
    TLabel *Label7;
    TToolButton *tbSave;
    TImageList *ImageList1;
    TLabel *Label8;
    TLabel *Label9;
    TEdit *edCID;
    TEdit *edFName;
    TEdit *edSName;
    TEdit *edTName;
    TEdit *edPhone1;
    TEdit *edPhone2;
    TEdit *edWebPass;
    TDateTimePicker *dtpBirthDate;
    TMemo *mInfo;
    TEdit *edBalanse;
    TLabel *Label10;
    TCheckBox *cbAlive;
    TPanel *Panel2;
    TImage *imPhoto;
    TButton *btSetPhoto;
    TOpenPictureDialog *opdPhoto;
    TButton *btClearPhoto;
    TLabel *Label11;
    TEdit *edDiscount;
    TEdit *edCardNum;
    TLabel *Label12;
    TImageList *ImageList2;
    TButton *Button1;
    TEdit *edCard;
    void __fastcall tbSaveClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall btSetPhotoClick(TObject *Sender);
    void __fastcall btClearPhotoClick(TObject *Sender);
    void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall edCardNumKeyPress(TObject *Sender, char &Key);
private:	// User declarations
    AnsiString retString;
public:		// User declarations
    TDateTime CardDate;
    __fastcall TiClientsForm(TComponent* Owner);

    AnsiString FName, SName, TName;
};
//---------------------------------------------------------------------------
extern PACKAGE TiClientsForm *iClientsForm;
//---------------------------------------------------------------------------
#endif
