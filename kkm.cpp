/*
**************************** !!! ВНИМАНИЕ !!! *****************************
  Для корректной работы с драйвером в режиме отладки необходимо в среде
разработки отключить остановку на исключительных ситуациях.
  Эта опция находится в меню "Tools\Debugger Options", закладка
"Language Exceptions". Флаг "Stop On Delphi Exceptions" необходимо снять.
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
// SetMode перед:
/* формирование чека
0. Проверить закрыт ли чек (GetStatus)
1. Открытие чека.
2. Регистрация первой позиции.
3. Начисление скидки на первую позицию.
4. Регистрация второй позиции.
[Интерфейс драйвера]
62
5. Начисление надбавки на весь чек
6. Прием оплаты.
7. Закрытие чека.
*/

// CashIncome - внесение
// CashOutcome - выплата
// OpenSession - открытие смены
// Report - снятие отчетов

//---------------------------------------------------------------------------
// Возвращает информацию - открыта ли смена и есть ли незакрытый чек
// Должен быть открыт порт
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
        // создаем объект общего драйвера ККМ
        // если объект создать не удается генерируется исключение, по которому завершается работа приложения
        try
        {
            ECR = CreateOleObject("AddIn.FprnM45");
            ECR.OlePropertySet("ApplicationHandle", int(Application->Handle)); // необходимо для корректного отображения окон драйвера в контексте приложения

            //ECR.OlePropertySet("DeviceEnabled", true);
            //if((res = ECR.OlePropertyGet("ResultCode")) != 0)
            //{
                //Application->MessageBox("Ошибка инициализации ККМ!", Application->Title.c_str(), MB_ICONERROR + MB_OK);
            //    ECR = 0;
            //    res = -1;
            //}


        }
        catch (Exception &exception)
        {
            //Application->MessageBox("Ошибка драйвера ККМ!", Application->Title.c_str(), MB_ICONERROR + MB_OK);
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
// Открывает порт и устанавливает режим 1
// Закрывает порт в случае ошибки
int kkm_open()
{
    int res;

    if((res = kkm_opendevice()) == 0)
    {
        // устанавливаем пароль кассира
        ECR.OlePropertySet("Password", "1");
        // входим в режим регистрации
        ECR.OlePropertySet("Mode", 1);
        res = ECR.OleFunction("SetMode");

        if(res == -3822)
        {
            if(Application->MessageBox("Z Отчет ККМ превысил 24 часа!\nСформировать отчет автоматически?", Application->Title.c_str(), MB_ICONERROR + MB_YESNO) == IDYES)
            {
                if((res = kkm_report_Z()) == 0)
                {
                    if((res = kkm_opendevice()) == 0)
                    {
                        // устанавливаем пароль кассира
                        ECR.OlePropertySet("Password", "1");
                        // входим в режим регистрации
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
    // Нужно открыть порт
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
// Порт должен быть открыт
int kkm_bill_add(char *name, double price, double quan, int department = 0)
{
    ECR.OlePropertySet("Name", name);
    ECR.OlePropertySet("Price", price);
    ECR.OlePropertySet("Quantity", quan);
    ECR.OlePropertySet("Department", department);

    return ECR.OleFunction("Registration");
}
//---------------------------------------------------------------------------
// Порт должен быть открыт
int kkm_bill_sub(char *name, double price, double quan, int department = 0)
{
    ECR.OlePropertySet("Name", name);
    ECR.OlePropertySet("Price", price);
    ECR.OlePropertySet("Quantity", quan);
    ECR.OlePropertySet("Department", department);

    return ECR.OleFunction("Return");
}
//---------------------------------------------------------------------------
// Порт должен быть открыт
int kkm_bill_payment(double paysum, int type = 0)
{
    // type = 0 - наличная оплата
    // type = 1 - тип оплаты 1

    ECR.OlePropertySet("Summ", paysum);
    ECR.OlePropertySet("TypeClose", type);

    return ECR.OleFunction("Payment");
}
//---------------------------------------------------------------------------
// Порт должен быть открыт
// После операции порт закрывается
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
    // выплата наличности
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
        // X - отчет
        // устанавливаем пароль администратора ККМ
        ECR.OlePropertySet("Password", "29");
        // входим в режим отчетов без гашения
        ECR.OlePropertySet("Mode", 2);
        if((res = ECR.OleFunction("SetMode")) == 0)
        {
            // снимаем отчет
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
        // Z - отчет
        // устанавливаем пароль системного администратора ККМ
        ECR.OlePropertySet("Password", "30");
        // входим в режим отчетов с гашением
        ECR.OlePropertySet("Mode", 3);
        if((res = ECR.OleFunction("SetMode")) == 0)
        {
            // снимаем отчет
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
        // создаем объект общего драйвера ККМ
        // если объект создать не удается генерируется исключение, по которому завершается работа приложения
        try
        {
            ECR = CreateOleObject("AddIn.FprnM45");
            ECR.OlePropertySet("ApplicationHandle", int(Application->Handle)); // необходимо для корректного отображения окон драйвера в контексте приложения
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
    // Взаимодействие с ККМ
    //__int64 ID = (__int64)sgBills->Objects[0][sgBills->Row];

    if(!ID) return -1;
    int res = -1;

    if(KKM_LINK == -1 && KKM_USE == 1)
    {
        // Подготовим чек
        /*
        #define SELLOP_ADDBALANSE        1 - Из таблицы Bills
        #define SELLOP_ABONEMENT         2 - Абонемент Фитнесс
        #define SELLOP_GOOD              4 - Товар
        #define SELLOP_SERVICE           8 - не используется
        #define SELLOP_ABONEMENT_SPA    16 - Абонемент SPA пополнение
        #define SELLOP_SPA_VISIT        32 - SPA услуга из ServNames
        #define SELLOP_BATH             64 - Банная услуга из ServNames
        #define SELLOP_BARBER           128 - Парикмахерская из ServNames
        #define SELLOP_NAIL             256 - Ногти из ServNames
        #define SELLOP_COSMETIC         512 - Косметика из ServNames
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
                // можно печатать чек, ID - BillID

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
_kkmerr:        // Проблемы с ККМ
                Application->MessageBox("Ошибка печати чека ККМ!\nУстраните ошибку.", Application->Title.c_str(), MB_ICONERROR + MB_OK);
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
        // Подготовим чек
        /*
        #define SELLOP_ADDBALANSE        1 - Из таблицы Bills
        #define SELLOP_ABONEMENT         2 - Абонемент Фитнесс
        #define SELLOP_GOOD              4 - Товар
        #define SELLOP_SERVICE           8 - не используется
        #define SELLOP_ABONEMENT_SPA    16 - Абонемент SPA пополнение
        #define SELLOP_SPA_VISIT        32 - SPA услуга из ServNames
        #define SELLOP_BATH             64 - Банная услуга из ServNames
        #define SELLOP_BARBER           128 - Парикмахерская из ServNames
        #define SELLOP_NAIL             256 - Ногти из ServNames
        #define SELLOP_COSMETIC         512 - Косметика из ServNames
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
                // можно печатать чек, ID - BillID
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
_kkmerr:        // Проблемы с ККМ
                Application->MessageBox("Ошибка аннулирования чека ККМ!\nУстраните ошибку.", Application->Title.c_str(), MB_ICONERROR + MB_OK);
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

