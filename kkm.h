//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
extern int KKM_LINK;
extern int KKM_USE;

int kkm_init();
int kkm_open();
int kkm_destroy();

int kkm_opendevice();
int kkm_closedevice();

int kkm_bill_open(bool annulate = false);
int kkm_bill_add(char *, double, double, int);
int kkm_bill_sub(char *, double, double, int);
int kkm_bill_payment(double, int);
int kkm_bill_close();
int kkm_bill_cancel();

int kkm_report_Z();
int kkm_report_X();

int kkm_outcome(double);
int kkm_income(double);

void kkm_properties();

double kkm_getsum();
int kkm_bill_print(__int64);
int kkm_bill_retprint(__int64);

