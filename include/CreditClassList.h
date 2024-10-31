// CreditClassList.h
#ifndef CREDIT_CLASS_LIST_H
#define CREDIT_CLASS_LIST_H

#include "CreditClass.h"
#include <vector>

class CreditClassList {
private:
    std::vector<CreditClass*> creditClasses;

public:
    CreditClassList();
    
    void addCreditClass(CreditClass* creditClass);
    void displayCreditClasses();
    void removeCreditClass(int malopTC);
    CreditClass* findCreditClassByMAMH(const std::string& maMH); // Đảm bảo khai báo hàm
    void cancelCreditClass(int malopTC);
};

#endif // CREDIT_CLASS_LIST_H
