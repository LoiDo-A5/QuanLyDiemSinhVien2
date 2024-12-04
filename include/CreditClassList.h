// CreditClassList.h
#ifndef CREDIT_CLASS_LIST_H
#define CREDIT_CLASS_LIST_H

#include "CreditClass.h"
#include <vector>
#include <string>

class CreditClassList
{
private:
    std::vector<CreditClass *> creditClasses; // List of credit classes

public:
    CreditClassList(); // Constructor

    // Add a credit class to the list
    void addCreditClass(CreditClass *creditClass);

    // Display all credit classes in the list
    void displayCreditClasses();

    // Remove a credit class by its code (malopTC)
    void removeCreditClass(int malopTC);

    // Find and return a credit class by its code (malopTC)
    CreditClass *findCreditClassByMALOPTC(int malopTC);

    // Cancel a credit class by its code (malopTC)
    void cancelCreditClass(int malopTC);

    // Find credit classes based on various parameters (nienKhoa, hocKy, nhom, maMH)
    std::vector<CreditClass *> findClassesByParams(const std::string &nienKhoa,
                                                   int hocKy);

    bool registerStudent(const std::string &maMH, const SinhVien &sinhVien);
};

#endif // CREDIT_CLASS_LIST_H
