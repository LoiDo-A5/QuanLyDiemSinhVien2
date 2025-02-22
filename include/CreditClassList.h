#ifndef CREDIT_CLASS_LIST_H
#define CREDIT_CLASS_LIST_H

#include "CreditClass.h"
#include <vector>
#include <string>

class CreditClassList
{
private:
    CreditClass creditClasses[10000]; // Mảng các lớp tín chỉ
    int count;

public:
    CreditClassList();

    // Thêm lớp tín chỉ
    void addCreditClass(CreditClass *creditClass);

    // Xóa lớp tín chỉ
    void removeCreditClass(int malopTC);

    // Tìm lớp tín chỉ theo mã
    CreditClass *findCreditClassByMALOPTC(int malopTC);
};

#endif // CREDIT_CLASS_LIST_H
