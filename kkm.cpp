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
#include <comobj.hpp>
#include "kkm.h"
#include "lib.h"
#pragma hdrstop
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
Variant ECR = 0;
//bool TestKKM = true;
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
// ���������� ���������� - ������� �� ����� � ���� �� ���������� ���
// ������ ���� ������ ����
int kkm_status(bool *session, int *mode, bool *bill)
{
    int res;

    *session = false;
    *mode = -1;
    *bill = false;

    //if((res = kkm_opendevice()) == 0)
    {
        if((res = ECR.OleFunction("GetStatus")) == 0)
        {
            if((bool)ECR.OlePropertyGet("SessionOpened"))
                *session = true;

            *mode = ECR.OlePropertyGet("Mode");

            if(ECR.OlePropertyGet("CheckState") != 0)
                *bill = true;
        }

        //kkm_closedevice();
    }

    return res;
}
//---------------------------------------------------------------------------
int kkm_init()
{
    int res = kkm_destroy();

    if(res != 0) return res;

    if(ECR.Type() != 9)
    {
        // ������� ������ ������ �������� ���
        // ���� ������ ������� �� ������� ������������ ����������, �� �������� ����������� ������ ����������
        try
        {
            ECR = CreateOleObject("AddIn.FprnM45");
            ECR.OlePropertySet("ApplicationHandle", int(Application->Handle)); // ���������� ��� ����������� ����������� ���� �������� � ��������� ����������

            //ECR.OlePropertySet("DeviceEnabled", true);
            //if((res = ECR.OlePropertyGet("ResultCode")) != 0)
            //{
                //Application->MessageBox("������ ������������� ���!", Application->Title.c_str(), MB_ICONERROR + MB_OK);
            //    ECR = 0;
            //    res = -1;
            //}


        }
        catch (Exception &exception)
        {
            //Application->MessageBox("������ �������� ���!", Application->Title.c_str(), MB_ICONERROR + MB_OK);
            ECR = 0;
            res = -1;
        }
    }

    return res;
}
//---------------------------------------------------------------------------
int kkm_opendevice()
{
    //if((bool)ECR.OlePropertyGet("DeviceEnabled") == true) return 0;

    ECR.OlePropertySet("DeviceEnabled", true);
    return ECR.OlePropertyGet("ResultCode");
}
//---------------------------------------------------------------------------
int kkm_closedevice()
{
    //if((bool)ECR.OlePropertyGet("DeviceEnabled") == false) return 0;

    ECR.OlePropertySet("DeviceEnabled", false);
    return ECR.OlePropertyGet("ResultCode");
}
//---------------------------------------------------------------------------
// ��������� ���� � ������������� ����� 1
// ��������� ���� � ������ ������
int kkm_open()
{
    int res;

    if((res = kkm_opendevice()) == 0)
    {
        // ������������� ������ �������
        ECR.OlePropertySet("Password", "1");
        // ������ � ����� �����������
        ECR.OlePropertySet("Mode", 1);
        res = ECR.OleFunction("SetMode");

        if(res == -3822)
        {
            if(Application->MessageBox("Z ����� ��� �������� 24 ����!\n������������ ����� �������������?", Application->Title.c_str(), MB_ICONERROR + MB_YESNO) == IDYES)
            {
                if((res = kkm_report_Z()) == 0)
                {
                    if((res = kkm_opendevice()) == 0)
                    {
                        // ������������� ������ �������
                        ECR.OlePropertySet("Password", "1");
                        // ������ � ����� �����������
                        ECR.OlePropertySet("Mode", 1);
                        res = ECR.OleFunction("SetMode");
                    }
                }
            }
        }

        if(res != 0) kkm_closedevice();
    }

    return res;
}
//---------------------------------------------------------------------------
int kkm_bill_cancel()
{
    return ECR.OleFunction("CancelCheck");
}
//---------------------------------------------------------------------------
int kkm_bill_open(bool annulate)
{
    // ����� ������� ����
    int res;

    if((res = kkm_open()) == 0)
    {
        bool session, bill;
        int mode;

        if((res = kkm_status(&session, &mode, &bill)) == 0)
        {
            if(bill)
                if((res = kkm_bill_cancel()) != 0)
                    goto _end;

            if(!annulate)
                ECR.OlePropertySet("CheckType", 1);
            else
                ECR.OlePropertySet("CheckType", 2);

            res = ECR.OleFunction("OpenCheck");
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
    ECR.OlePropertySet("Name", name);
    ECR.OlePropertySet("Price", price);
    ECR.OlePropertySet("Quantity", quan);
    ECR.OlePropertySet("Department", department);

    return ECR.OleFunction("Registration");
}
//---------------------------------------------------------------------------
// ���� ������ ���� ������
int kkm_bill_sub(char *name, double price, double quan, int department = 0)
{
    ECR.OlePropertySet("Name", name);
    ECR.OlePropertySet("Price", price);
    ECR.OlePropertySet("Quantity", quan);
    ECR.OlePropertySet("Department", department);

    return ECR.OleFunction("Return");
}
//---------------------------------------------------------------------------
// ���� ������ ���� ������
int kkm_bill_payment(double paysum, int type = 0)
{
    // type = 0 - �������� ������
    // type = 1 - ��� ������ 1

    ECR.OlePropertySet("Summ", paysum);
    ECR.OlePropertySet("TypeClose", type);

    return ECR.OleFunction("Payment");
}
//---------------------------------------------------------------------------
// ���� ������ ���� ������
// ����� �������� ���� �����������
int kkm_bill_close()
{
    int res;

    res = ECR.OleFunction("CloseCheck");
    kkm_closedevice();

    return res;
}
//---------------------------------------------------------------------------
int kkm_destroy()
{
    int res = 0;

    if(ECR.Type() == 9)
        res = kkm_closedevice();
    ECR = 0;

    return res;
}
//---------------------------------------------------------------------------
int kkm_outcome(double cash)
{
    // ������� ����������
    int res;

    if((res = kkm_open()) == 0)
    {
        bool session, bill;
        int mode;

        if((res = kkm_status(&session, &mode, &bill)) == 0)
        {
            if(bill)
                if((res = ECR.OleFunction("CancelCheck")) != 0)
                    goto _end;

            ECR.OlePropertySet("Summ", cash);
            res = ECR.OleFunction("CashOutcome");
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
        bool session, bill;
        int mode;

        if((res = kkm_status(&session, &mode, &bill)) == 0)
        {
            if(bill)
                if((res = ECR.OleFunction("CancelCheck")) != 0)
                    goto _end;

            ECR.OlePropertySet("Summ", cash);
            res = ECR.OleFunction("CashIncome");
        }
    }

_end:
    kkm_closedevice();

    return res;
}
//---------------------------------------------------------------------------
int kkm_report_X()
{
    int res;

    if((res = kkm_open()) == 0)
    {
        // X - �����
        // ������������� ������ �������������� ���
        ECR.OlePropertySet("Password", "29");
        // ������ � ����� ������� ��� �������
        ECR.OlePropertySet("Mode", 2);
        if((res = ECR.OleFunction("SetMode")) == 0)
        {
            // ������� �����
            ECR.OlePropertySet("ReportType", 2);
            res = ECR.OleFunction("Report");
        }
    }

    kkm_closedevice();

    return res;
}
//---------------------------------------------------------------------------
int kkm_report_Z()
{
    int res;

    if((bool)ECR.OlePropertyGet("DeviceEnabled"))
        res = 0;
    else
        res = kkm_open();

    if(res == 0)
    {
        // Z - �����
        // ������������� ������ ���������� �������������� ���
        ECR.OlePropertySet("Password", "30");
        // ������ � ����� ������� � ��������
        ECR.OlePropertySet("Mode", 3);
        if((res = ECR.OleFunction("SetMode")) == 0)
        {
            // ������� �����
            ECR.OlePropertySet("ReportType", 1);
            res = ECR.OleFunction("Report");
        }
    }

    kkm_closedevice();

    return res;
}
//---------------------------------------------------------------------------
void kkm_properties()
{
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
}
//---------------------------------------------------------------------------
double kkm_getsum()
{
    double res = -1;

    if(kkm_open() == 0)
        if(ECR.OleFunction("GetSumm") == 0)
            res = (double)ECR.OlePropertyGet("Summ");

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

                    res = kkm_bill_add(pPos->name.c_str(),pPos->price, pPos->quan, department);
                    if(res != 0) goto _kkmerr;
                }

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

                res = kkm_bill_close();
            }

            if(res != 0)
            {
_kkmerr:        // �������� � ���
                Application->MessageBox("������ ������ ���� ���!\n��������� ������.", Application->Title.c_str(), MB_ICONERROR + MB_OK);
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
                    res = kkm_bill_sub(pPos->name.c_str(),pPos->price, pPos->quan, department);
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
                Application->MessageBox("������ ������������� ���� ���!\n��������� ������.", Application->Title.c_str(), MB_ICONERROR + MB_OK);
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

