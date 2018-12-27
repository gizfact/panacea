/*
**************************** !!! �������� !!! *****************************
  ��� ���������� ������ � ��������� � ������ ������� ���������� � �����
���������� ��������� ��������� �� �������������� ���������.
  ��� ����� ��������� � ���� "Tools\Debugger Options", ��������
"Language Exceptions". ���� "Stop On Delphi Exceptions" ���������� �����.
***************************************************************************
*/
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "lib.h"
#include "kkm.h"
//---------------------------------------------------------------------------
typedef const char * (*KKM_GET_VERSION_STRING)();
KKM_GET_VERSION_STRING _kkm_get_version_string;

typedef int (*KKM_CREATE)(libfptr_handle *handle);
KKM_CREATE _kkm_create;

typedef int (*KKM_DESTROY)(libfptr_handle *handle);
KKM_DESTROY _kkm_destroy;

typedef int (*KKM_OPEN)(libfptr_handle handle);
KKM_OPEN _kkm_open;

typedef int (*KKM_OPERATOR_LOGIN)(libfptr_handle handle);
KKM_OPERATOR_LOGIN _kkm_operator_login;

typedef int (*KKM_CLOSE)(libfptr_handle handle);
KKM_CLOSE _kkm_close;

typedef int (*KKM_IS_OPENED)(libfptr_handle handle);
KKM_IS_OPENED _kkm_is_opened;

typedef void (*KKM_SET_PARAM_INT)(libfptr_handle handle, int, uint);
KKM_SET_PARAM_INT _kkm_set_param_int;

typedef void (*KKM_SET_PARAM_DOUBLE)(libfptr_handle handle, int, double);
KKM_SET_PARAM_DOUBLE _kkm_set_param_double;

typedef void (*KKM_SET_PARAM_STR)(libfptr_handle handle, int, wchar_t *);
KKM_SET_PARAM_STR _kkm_set_param_str;

typedef void (*KKM_QUERY_DATA)(libfptr_handle handle);
KKM_QUERY_DATA _kkm_query_data;

typedef uint (*KKM_GET_PARAM_INT)(libfptr_handle handle, int);
KKM_GET_PARAM_INT _kkm_get_param_int;

typedef int (*KKM_GET_PARAM_BOOL)(libfptr_handle handle, int);
KKM_GET_PARAM_BOOL _kkm_get_param_bool;

typedef double (*KKM_GET_PARAM_DOUBLE)(libfptr_handle handle, int);
KKM_GET_PARAM_DOUBLE _kkm_get_param_double;

// �������� ����
typedef int (*KKM_OPEN_RECEIPT)(libfptr_handle handle);
KKM_OPEN_RECEIPT _kkm_open_receipt;

// �������� ����
typedef int (*KKM_CLOSE_RECEIPT)(libfptr_handle handle);
KKM_CLOSE_RECEIPT _kkm_close_receipt;

// ������ ����
typedef int (*KKM_CANCEL_RECEIPT)(libfptr_handle handle);
KKM_CANCEL_RECEIPT _kkm_cancel_receipt;

typedef int (*KKM_REGISTRATION)(libfptr_handle handle);
KKM_REGISTRATION _kkm_registration;

typedef int (*KKM_PAYMENT)(libfptr_handle handle);
KKM_PAYMENT _kkm_payment;

typedef int (*KKM_RECEIPT_TOTAL)(libfptr_handle handle);
KKM_RECEIPT_TOTAL _kkm_receipt_total;

typedef int (*KKM_CONTINUE_PRINT)(libfptr_handle handle);
KKM_CONTINUE_PRINT _kkm_continue_print;

typedef int (*KKM_REPORT)(libfptr_handle handle);
KKM_REPORT _kkm_report;

typedef int (*KKM_CASH_INCOME)(libfptr_handle handle);
KKM_CASH_INCOME _kkm_cash_income;

typedef int (*KKM_CASH_OUTCOME)(libfptr_handle handle);
KKM_CASH_OUTCOME _kkm_cash_outcome;

typedef int (*KKM_SHOW_PROPERTIES)(libfptr_handle handle, int, void *);
KKM_SHOW_PROPERTIES _kkm_show_properties;

typedef int (*KKM_ERROR_CODE)(libfptr_handle handle);
KKM_ERROR_CODE _kkm_error_code;

typedef int (*KKM_ERROR_DESCRIPTION)(libfptr_handle handle, wchar_t *, int);
KKM_ERROR_DESCRIPTION _kkm_error_description;

typedef int (*KKM_CHECK_DOCUMENT_CLOSED)(libfptr_handle handle);
KKM_CHECK_DOCUMENT_CLOSED _kkm_check_document_closed;
//---------------------------------------------------------------------------
//Variant ECR = 0;
//bool TestKKM = true;
extern AnsiString UserAcc;
libfptr_handle fptr = NULL;
HINSTANCE dllhandle = NULL;

char *flog = "kkm.log";
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// SetMode �����:
/* ������������ ����
0. ��������� ������ �� ��� (GetStatus)
1. �������� ����.
2. ����������� ������ �������.
3. ���������� ������ �� ������ �������.
4. ����������� ������ �������.
[��������� ��������]
62
5. ���������� �������� �� ���� ���
6. ����� ������.
7. �������� ����.
*/

// CashIncome - ��������
// CashOutcome - �������
// OpenSession - �������� �����
// Report - ������ �������
//---------------------------------------------------------------------------
void kkm_writelog(AnsiString& s)
{
    if(flog)
    {
        int h;
        if(FileExists(flog))
        {
            h = FileOpen(flog, fmOpenReadWrite);
            FileSeek(h, 0, 2);
        }
        else
            h = FileCreate(flog);

        FileWrite(h, s.c_str(), s.Length());
        FileClose(h);
    }
}
//---------------------------------------------------------------------------
// ������������� DLL
int kkm_load()
{
    dllhandle = LoadLibrary("fptr10.dll");
    if(dllhandle)
    {
        _kkm_get_version_string  =
        (KKM_GET_VERSION_STRING)GetProcAddress(dllhandle, "libfptr_get_version_string");

        _kkm_create =
        (KKM_CREATE)GetProcAddress(dllhandle, "libfptr_create");

        _kkm_destroy =
        (KKM_DESTROY)GetProcAddress(dllhandle, "libfptr_destroy");

        _kkm_open =
        (KKM_OPEN)GetProcAddress(dllhandle, "libfptr_open");

        _kkm_close =
        (KKM_CLOSE)GetProcAddress(dllhandle, "libfptr_close");

        _kkm_operator_login =
        (KKM_OPERATOR_LOGIN)GetProcAddress(dllhandle, "libfptr_operator_login");

        _kkm_is_opened =
        (KKM_IS_OPENED)GetProcAddress(dllhandle, "libfptr_is_opened");

        _kkm_set_param_int =
        (KKM_SET_PARAM_INT)GetProcAddress(dllhandle, "libfptr_set_param_int");

        _kkm_set_param_double =
        (KKM_SET_PARAM_DOUBLE)GetProcAddress(dllhandle, "libfptr_set_param_double");

        _kkm_set_param_str =
        (KKM_SET_PARAM_STR)GetProcAddress(dllhandle, "libfptr_set_param_str");

        _kkm_query_data =
        (KKM_QUERY_DATA)GetProcAddress(dllhandle, "libfptr_query_data");

        _kkm_get_param_int =
        (KKM_GET_PARAM_INT)GetProcAddress(dllhandle, "libfptr_get_param_int");

        _kkm_get_param_bool =
        (KKM_GET_PARAM_BOOL)GetProcAddress(dllhandle, "libfptr_get_param_bool");

        _kkm_get_param_double =
        (KKM_GET_PARAM_DOUBLE)GetProcAddress(dllhandle, "libfptr_get_param_double");

        _kkm_open_receipt =
        (KKM_OPEN_RECEIPT)GetProcAddress(dllhandle, "libfptr_open_receipt");

        _kkm_close_receipt =
        (KKM_CLOSE_RECEIPT)GetProcAddress(dllhandle, "libfptr_close_receipt");

        _kkm_cancel_receipt =
        (KKM_CANCEL_RECEIPT)GetProcAddress(dllhandle, "libfptr_cancel_receipt");

        _kkm_continue_print =
        (KKM_CONTINUE_PRINT)GetProcAddress(dllhandle, "libfptr_continue_print");

        _kkm_registration =
        (KKM_REGISTRATION)GetProcAddress(dllhandle, "libfptr_registration");

        _kkm_payment =
        (KKM_PAYMENT)GetProcAddress(dllhandle, "libfptr_payment");

        _kkm_receipt_total =
        (KKM_RECEIPT_TOTAL)GetProcAddress(dllhandle, "libfptr_receipt_total");

        _kkm_report =
        (KKM_REPORT)GetProcAddress(dllhandle, "libfptr_report");

        _kkm_cash_income =
        (KKM_CASH_INCOME)GetProcAddress(dllhandle, "libfptr_cash_income");

        _kkm_cash_outcome =
        (KKM_CASH_OUTCOME)GetProcAddress(dllhandle, "libfptr_cash_outcome");

        _kkm_show_properties =
        (KKM_SHOW_PROPERTIES)GetProcAddress(dllhandle, "libfptr_show_properties");

        _kkm_error_code =
        (KKM_ERROR_CODE)GetProcAddress(dllhandle, "libfptr_error_code");

        _kkm_error_description =
        (KKM_ERROR_DESCRIPTION)GetProcAddress(dllhandle, "libfptr_error_description");

        _kkm_check_document_closed =
        (KKM_CHECK_DOCUMENT_CLOSED)GetProcAddress(dllhandle, "libfptr_check_document_closed");

        return 0;
    }

    return -1;
}
//---------------------------------------------------------------------------
AnsiString kkm_error_description()
{
    wchar_t errorDescription[128];
    int size = _kkm_error_description(fptr, errorDescription, 127);

    if(size > 127)
    {
        wchar_t *p = new wchar_t[size + 1];
        _kkm_error_description(fptr, p, size);

        AnsiString s = WideCharToString(p);
        delete [] p;
        return s;
    }

    return WideCharToString(errorDescription);
}
//---------------------------------------------------------------------------
int kkm_init()
{
    int res = kkm_load();
    if(res != 0) return res;

    res = _kkm_create(&fptr);

    return res;
}
//---------------------------------------------------------------------------
// ���������� ���������� - ������� �� ����� � ���� �� ���������� ���
// ������ ���� ������ ����
int kkm_status(int *session, int *mode, bool *bill)
{
    //int res;

    *session = false;
    *mode = -1;
    *bill = false;

    _kkm_set_param_int(fptr, LIBFPTR_PARAM_DATA_TYPE, LIBFPTR_DT_STATUS);
    _kkm_query_data(fptr);

    //if(res == 0)
    {
        //LIBFPTR_SS_CLOSED
        //LIBFPTR_SS_OPENED
        //LIBFPTR_SS_EXPIRED
        uint shiftState = _kkm_get_param_int(fptr, LIBFPTR_PARAM_SHIFT_STATE);
        if(shiftState == LIBFPTR_SS_OPENED)
            *session = 1;
        else if(shiftState == LIBFPTR_SS_CLOSED)
            *session = 0;
        else if(shiftState == LIBFPTR_SS_EXPIRED)
            *session = -1;
        else
            *session = -2;

        uint receiptType = _kkm_get_param_int(fptr, LIBFPTR_PARAM_RECEIPT_TYPE);
        if(receiptType != LIBFPTR_RT_CLOSED) *bill = true;

        *mode = _kkm_get_param_int(fptr, LIBFPTR_PARAM_MODE);
    }

    return 0;
}
//---------------------------------------------------------------------------
int kkm_opendevice()
{
    return _kkm_open(fptr);
}
//---------------------------------------------------------------------------
int kkm_closedevice()
{
    return _kkm_close(fptr);
}
//---------------------------------------------------------------------------
int kkm_operator_login()
{
    _kkm_set_param_str(fptr, 1021, L"������: �������������");

    //if(UserAcc == NULL || UserAcc.Length() == 0)
    //    _kkm_set_param_str(fptr, 1021, L"������: �������������");
    //else
    //{
    //    wchar_t buf[128];
    //    StringToWideChar("������: " + UpperCase(UserAcc[1]) + UserAcc.SubString(2, UserAcc.Length() - 1), buf, 127);
    //    _kkm_set_param_str(fptr, 1021, buf);
    //}

    //char * p = (char *)L"������: ����";
    //char * q = (char *)buf;

    _kkm_set_param_str(fptr, 1203, L"123456789047");

    return _kkm_operator_login(fptr);
}
//---------------------------------------------------------------------------
// ��������� ���� � ������������� ����� 1
// ��������� ���� � ������ ������
int kkm_open()
{
    int res;

    if((res = kkm_opendevice()) == 0)
    {
        // ����������� �������


        //_kkm_open_shift(fptr); - ��� �������������

        //_kkm_check_document_closed();
        int session, mode;
        bool bill;

        kkm_status(&session, &mode, &bill);

        if(session == -1)
        {
            // Z-����� �������������
            res = kkm_report_Z();
        }

        if(bill)
        {
            // �������� ���??
            res = _kkm_cancel_receipt(fptr);
            //_kkm_continue_print(fptr);
        }

        if(res != 0)
            kkm_closedevice();
            
        //res = kkm_opendevice();
    }

    return res;
}
//---------------------------------------------------------------------------
int kkm_bill_cancel()
{
    //return ECR.OleFunction("CancelCheck");
    return _kkm_cancel_receipt(fptr);
}
//---------------------------------------------------------------------------
int kkm_bill_open(bool annulate)
{
    // ����� ������� ����
    int res;

    if((res = kkm_open()) == 0)
    {
        bool bill;
        int session, mode;

        if((res = kkm_status(&session, &mode, &bill)) == 0)
        {
            if(bill)
                if((res = kkm_bill_cancel()) != 0)
                    goto _end;

            //Application->MessageBox("LOGIN", "", MB_OK);
            kkm_operator_login();
            //Application->MessageBox("LOGIN OK", "", MB_OK);
            //_kkm_set_param_int(fptr, LIBFPTR_PARAM_RECEIPT_TYPE, LIBFPTR_RT_SELL);


            if(annulate)
                _kkm_set_param_int(fptr, LIBFPTR_PARAM_RECEIPT_TYPE, LIBFPTR_RT_SELL_RETURN);
            else
                _kkm_set_param_int(fptr, LIBFPTR_PARAM_RECEIPT_TYPE, LIBFPTR_RT_SELL);

            res = _kkm_open_receipt(fptr);
        }
    }

    if(res != 0)
_end:   kkm_closedevice();

    return res;
}
//---------------------------------------------------------------------------
// ���� ������ ���� ������
int kkm_bill_add(char *name, double price, double quan, int department = 0)
{
    wchar_t buf[512];
    StringToWideChar(name, buf, 511);

    _kkm_set_param_str(fptr, LIBFPTR_PARAM_COMMODITY_NAME, buf);
    _kkm_set_param_double(fptr, LIBFPTR_PARAM_PRICE, price);
    _kkm_set_param_double(fptr, LIBFPTR_PARAM_QUANTITY, quan);
    //_kkm_set_param_int(fptr, LIBFPTR_PARAM_TAX_TYPE, LIBFPTR_TAX_VAT0);
    // LIBFPTR_TT_USN_INCOME
    //_kkm_set_param_int(fptr, 1055, LIBFPTR_TT_USN_INCOME);
    _kkm_set_param_int(fptr, LIBFPTR_PARAM_TAX_TYPE, LIBFPTR_TAX_NO);
    //_kkm_set_param_int(fptr, LIBFPTR_PARAM_USE_ONLY_TAX_TYPE, true);

    _kkm_set_param_int(fptr, LIBFPTR_PARAM_DEPARTMENT, department);


    //return ECR.OleFunction("Registration");
    return _kkm_registration(fptr);
}
//---------------------------------------------------------------------------
// ���� ������ ���� ������
/*
int kkm_bill_sub(char *name, double price, double quan, int department = 0)
{
    ECR.OlePropertySet("Name", name);
    ECR.OlePropertySet("Price", price);
    ECR.OlePropertySet("Quantity", quan);
    ECR.OlePropertySet("Department", department);

    return ECR.OleFunction("Return");
}
*/
//---------------------------------------------------------------------------
// ���� ������ ���� ������
int kkm_bill_payment(double paysum, int type = 0)
{
    // type = 0 - �������� ������
    // type = 1 - ��� ������ 1
    if(!type)
        _kkm_set_param_int(fptr, LIBFPTR_PARAM_PAYMENT_TYPE, LIBFPTR_PT_CASH);
    else
        _kkm_set_param_int(fptr, LIBFPTR_PARAM_PAYMENT_TYPE, LIBFPTR_PT_ELECTRONICALLY);


    _kkm_set_param_double(fptr, LIBFPTR_PARAM_PAYMENT_SUM, paysum);
    return _kkm_payment(fptr);
    //ECR.OlePropertySet("Summ", paysum);
    //ECR.OlePropertySet("TypeClose", type);

    //return ECR.OleFunction("Payment");
}
//---------------------------------------------------------------------------
// ���� ������ ���� ������
// ����� �������� ���� �����������
int kkm_bill_close()
{
    //_kkm_set_param_double(fptr, LIBFPTR_PARAM_SUM, total);
    //_kkm_receipt_total(fptr);

    int res = _kkm_close_receipt(fptr);

    while(_kkm_check_document_closed(fptr) < 0)
    {

        // �� ������� ��������� ��������� ���������. ������� ������������ ����� ������, ��������� ��������� ��������� � ��������� ������
        if(Application->MessageBox(("������ �������� �������� ���� -\n" + kkm_error_description() + "���������?\n").c_str(),"",MB_YESNO) == IDNO)
        {
            _kkm_cancel_receipt(fptr);
            return -1;
        }
        //std::wcout << getErrorDescription(fptr) << std::endl;
        //continue;
    }

    if(_kkm_get_param_bool(fptr, LIBFPTR_PARAM_DOCUMENT_CLOSED) == 0)
    {
        // �������� �� ��������. ��������� ��� �������� (���� ��� ���) � ������������ ������
        if(Application->MessageBox(("������ �������� ���� -\n" + kkm_error_description() + "���������?\n").c_str(),"",MB_YESNO) == IDNO)
        {
            _kkm_cancel_receipt(fptr);
            return -1;
        }
    }

    if(_kkm_get_param_bool(fptr, LIBFPTR_PARAM_DOCUMENT_PRINTED) == 0)
    {
        // ����� ����� ������� ����� ������������� ���������, �� ���������� � �������, ���� ��� ����������
        while(_kkm_continue_print(fptr) < 0)
        {
            // ���� �� ������� ���������� �������� - �������� ������������ ������ � ����������� ��� ���.
            //std::wcout << L"�� ������� ���������� �������� (������ \""<< getErrorDescription(fptr) << L"\"). ��������� ��������� � ���������.";
            if(Application->MessageBox(("������ ������ ���� -\n" + kkm_error_description() + "���������?\n").c_str(),"",MB_YESNO) == IDNO)
            {
                _kkm_cancel_receipt(fptr);
                return -1;
            }
        }
    }

    return res;
}
//---------------------------------------------------------------------------
int kkm_destroy()
{
    int res = 0;

    //if(ECR.Type() == 9)
    if(fptr)
        res = kkm_closedevice();

    _kkm_destroy(&fptr);
    //ECR = 0;
    fptr = NULL;

    return res;
}
//---------------------------------------------------------------------------
int kkm_outcome(double cash)
{
    // ������� ����������
    int res;

    if((res = kkm_open()) == 0)
    {
        bool bill;
        int session, mode;

        if((res = kkm_status(&session, &mode, &bill)) == 0)
        {
            if(bill)
                if((res = _kkm_cancel_receipt(fptr)) != 0)
                    goto _end;

            _kkm_set_param_double(fptr, LIBFPTR_PARAM_SUM, cash);
            res = _kkm_cash_outcome(fptr);
        }
    }

_end:
    kkm_closedevice();

    return res;
}
//---------------------------------------------------------------------------
int kkm_income(double cash)
{
    int res;

    if((res = kkm_open()) == 0)
    {
        bool bill;
        int session, mode;

        if((res = kkm_status(&session, &mode, &bill)) == 0)
        {
            if(bill)
                //if((res = ECR.OleFunction("CancelCheck")) != 0)
                if((res = _kkm_cancel_receipt(fptr)) != 0)
                    goto _end;

            //ECR.OlePropertySet("Summ", cash);
            //res = ECR.OleFunction("CashIncome");
            _kkm_set_param_double(fptr, LIBFPTR_PARAM_SUM, cash);
            res = _kkm_cash_income(fptr);
        }
    }

_end:
    kkm_closedevice();

    return res;
}
//---------------------------------------------------------------------------
int kkm_report_X()
{
    //Application->MessageBox("X-REPORT", "", MB_OK);
    int res;

    if((res = kkm_open()) == 0)
    {
        //kkm_writelog("KKM OPEN\r\n");
        //Application->MessageBox("OPEN", "", MB_OK);
        kkm_operator_login();




        //Application->MessageBox("LOGIN", "", MB_OK);
        //kkm_writelog("KKM OPERATOR LOGIN\r\n");

        _kkm_set_param_int(fptr, LIBFPTR_PARAM_REPORT_TYPE, LIBFPTR_RT_X);
        //Application->MessageBox("PARAM", "", MB_OK);
        res = _kkm_report(fptr);
        //kkm_writelog(AnsiString("RES: ") + AnsiString(res) + "\r\n");
        //Application->MessageBox("REPORT", "", MB_OK);
    }
    //else
    //Application->MessageBox("NOT OPEN", "", MB_OK);

    kkm_closedevice();

    return res;
}
//---------------------------------------------------------------------------
int kkm_report_Z()
{
    int res;

    if((res = kkm_open()) == 0)
    {
        kkm_operator_login();

        _kkm_set_param_int(fptr, LIBFPTR_PARAM_REPORT_TYPE, LIBFPTR_RT_CLOSE_SHIFT);
        res = _kkm_report(fptr);
    }

    kkm_closedevice();

    return res;
}
//---------------------------------------------------------------------------
void kkm_properties(void *handle)
{
/*
    if(ECR.Type() != 9)
    {
        // ������� ������ ������ �������� ���
        // ���� ������ ������� �� ������� ������������ ����������, �� �������� ����������� ������ ����������
        try
        {
            ECR = CreateOleObject("AddIn.FprnM45");
            ECR.OlePropertySet("ApplicationHandle", int(Application->Handle)); // ���������� ��� ����������� ����������� ���� �������� � ��������� ����������
            ECR.OleFunction("ShowProperties");
            ECR = 0;
        }
        catch(Exception &exception)
        {
            ECR = 0;
        }
    }
    else
    {
        ECR.OleFunction("ShowProperties");
        ECR = 0;
    }
    */
    if(fptr != NULL)
        _kkm_show_properties(fptr, LIBFPTR_GUI_PARENT_NATIVE, handle);
}
//---------------------------------------------------------------------------
double kkm_getsum()
{
    double res = -1;

    if(kkm_open() == 0)
    {
        _kkm_set_param_int(fptr, LIBFPTR_PARAM_DATA_TYPE, LIBFPTR_DT_CASH_SUM);
        _kkm_query_data(fptr);

        res = _kkm_get_param_double(fptr, LIBFPTR_PARAM_SUM);
    }

    kkm_closedevice();

    return res;
}
//---------------------------------------------------------------------------
int kkm_bill_print(__int64 ID)
{
    // �������������� � ���
    //__int64 ID = (__int64)sgBills->Objects[0][sgBills->Row];

    if(!ID) return -1;
    int res = -1;

    if(KKM_LINK == -1 && KKM_USE == 1)
    {
        // ���������� ���
        /*
        #define SELLOP_ADDBALANSE        1 - �� ������� Bills
        #define SELLOP_ABONEMENT         2 - ��������� �������
        #define SELLOP_GOOD              4 - �����
        #define SELLOP_SERVICE           8 - �� ������������
        #define SELLOP_ABONEMENT_SPA    16 - ��������� SPA ����������
        #define SELLOP_SPA_VISIT        32 - SPA ������ �� ServNames
        #define SELLOP_BATH             64 - ������ ������ �� ServNames
        #define SELLOP_BARBER           128 - �������������� �� ServNames
        #define SELLOP_NAIL             256 - ����� �� ServNames
        #define SELLOP_COSMETIC         512 - ��������� �� ServNames
        #define SELLOP_ABONEMENT_BATH   1024
        */

        //int department;
        //, payment;
        TList *pBill;
        double total, getsum, terminal, frombal;
        pBill = BuildBill(ID, &total, &getsum, &terminal, &frombal);

        int department = (getsum > 0)? 1 : 2;

        if(pBill)
        {
            BillPosition *pPos;

            if((res = kkm_bill_open()) == 0)
            {
                // ����� �������� ���, ID - BillID

                for(int i = 0; i < pBill->Count; i++)
                {
                    pPos = (BillPosition *)(pBill->Items[i]);

                    //Application->MessageBox("��������� �������", "", MB_OK);
                    res = kkm_bill_add(pPos->name.c_str(),pPos->price, pPos->quan, department);
                    if(res != 0) goto _kkmerr;
                    //Application->MessageBox("��������� �������", "", MB_OK);
                }

                if(getsum > 0)
                {
                    //Application->MessageBox("��������� ������ ���", "", MB_OK);
                    res = kkm_bill_payment(getsum, 0);
                    if(res != 0) goto _kkmerr;
                    //Application->MessageBox("�������� ������", "", MB_OK);
                }
                if(terminal > 0)
                {
                    //Application->MessageBox("��������� ������ ������", "", MB_OK);
                    res = kkm_bill_payment(terminal,1);
                    if(res != 0) goto _kkmerr;
                    //Application->MessageBox("�������� ������", "", MB_OK);
                }
                if(frombal > 0)
                {
                    //Application->MessageBox("��������� ������ ������ � �������", "", MB_OK);
                    res = kkm_bill_payment(frombal,1);
                    if(res != 0) goto _kkmerr;
                    //Application->MessageBox("�������� ������", "", MB_OK);
                }

                //Application->MessageBox("��������� ���", "", MB_OK);
                res = kkm_bill_close();
                //Application->MessageBox((AnsiString("��� ������ � ����� ") + res).c_str(), "", MB_OK);
            }

            if(res != 0)
            {
_kkmerr:        // �������� � ���
                Application->MessageBox(("������ ������ ���� ���!\n" + kkm_error_description() + "\n��������� ������.").c_str(), Application->Title.c_str(), MB_ICONERROR + MB_OK);
                res = -1;
            }

            for(int i = 0; i < pBill->Count; i++)
                delete (BillPosition *)(pBill->Items[i]);

            pBill->Clear();
            delete pBill;
        }
    }

    return res;
}
//---------------------------------------------------------------------------
int kkm_bill_retprint(__int64 ID)
{
    if(!ID) return -1;

    int res = -1;

    if(KKM_LINK == -1 && KKM_USE == 1)
    {
        // ���������� ���
        /*
        #define SELLOP_ADDBALANSE        1 - �� ������� Bills
        #define SELLOP_ABONEMENT         2 - ��������� �������
        #define SELLOP_GOOD              4 - �����
        #define SELLOP_SERVICE           8 - �� ������������
        #define SELLOP_ABONEMENT_SPA    16 - ��������� SPA ����������
        #define SELLOP_SPA_VISIT        32 - SPA ������ �� ServNames
        #define SELLOP_BATH             64 - ������ ������ �� ServNames
        #define SELLOP_BARBER           128 - �������������� �� ServNames
        #define SELLOP_NAIL             256 - ����� �� ServNames
        #define SELLOP_COSMETIC         512 - ��������� �� ServNames
        #define SELLOP_ABONEMENT_BATH   1024
        */

        //int department;
        //, payment;
        TList *pBill;
        double total, getsum, terminal, frombal;
        pBill = BuildBill(ID, &total, &getsum, &terminal, &frombal);

        int department = (getsum > 0)? 1 : 2;

        if(pBill)
        {
            BillPosition *pPos;

            if((res = kkm_bill_open(true)) == 0)
            {
                // ����� �������� ���, ID - BillID
                //res = kkm_bill_open();
                //if(res != 0) goto _kkmerr;

                for(int i = 0; i < pBill->Count; i++)
                {
                    pPos = (BillPosition *)(pBill->Items[i]);
                    res = kkm_bill_add(pPos->name.c_str(),pPos->price, pPos->quan, department);
                    if(res != 0) goto _kkmerr;
                }

                /*
                if(getsum > 0)
                {
                    res = kkm_bill_payment(getsum, 0);
                    if(res != 0) goto _kkmerr;
                }
                if(terminal > 0)
                {
                    res = kkm_bill_payment(terminal,1);
                    if(res != 0) goto _kkmerr;
                }
                if(frombal > 0)
                {
                    res = kkm_bill_payment(frombal,1);
                    if(res != 0) goto _kkmerr;
                }
                */

                res = kkm_bill_close();
            }

            if(res != 0)
            {
_kkmerr:        // �������� � ���
                Application->MessageBox("������ �������� ���� ���!\n��������� ������.", Application->Title.c_str(), MB_ICONERROR + MB_OK);
            }

            for(int i = 0; i < pBill->Count; i++)
                delete (BillPosition *)(pBill->Items[i]);

            pBill->Clear();
            delete pBill;
        }
    }

    return res;
}
//---------------------------------------------------------------------------

