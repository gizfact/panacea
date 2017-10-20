//---------------------------------------------------------------------------

#ifndef syncH
#define syncH
//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------
class TSync : public TThread
{            
private:
protected:
    void __fastcall Execute();

public:
    AnsiString sVal;
    __fastcall TSync(bool CreateSuspended);

};
//---------------------------------------------------------------------------
#endif
