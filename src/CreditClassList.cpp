// CreditClassList.cpp

#include "CreditClassList.h"
#include "CreditClass.h"
#include <iostream>

CreditClassList::CreditClassList() {}

void CreditClassList::addCreditClass(CreditClass *creditClass)
{
    creditClasses.push_back(creditClass);
}

void CreditClassList::displayCreditClasses()
{
    if (creditClasses.empty())
    {
        std::cout << "Danh sách lớp tín chỉ rỗng." << std::endl;
        return;
    }
    for (const auto &creditClass : creditClasses)
    {
        std::cout << "Mã lớp tín chỉ: " << creditClass->getMALOPTC()
                  << ", Mã môn học: " << creditClass->getMAMH()
                  << ", Tên lớp: " << creditClass->getTenLop()
                  << ", Niên khóa: " << creditClass->getNienKhoa()
                  << ", Học kỳ: " << creditClass->getHocKy()
                  << ", Nhóm: " << creditClass->getNhom()
                  << ", Số sinh viên tối thiểu: " << creditClass->getSoSvMin()
                  << ", Số sinh viên tối đa: " << creditClass->getSoSvMax()
                  << ", Trạng thái hủy lớp: " << (creditClass->isHuyLop() ? "Có" : "Không")
                  << std::endl;
    }
}

void CreditClassList::removeCreditClass(int malopTC)
{
    for (auto it = creditClasses.begin(); it != creditClasses.end(); ++it)
    {
        if ((*it)->getMALOPTC() == malopTC)
        {
            delete *it; // Free memory
            creditClasses.erase(it);
            std::cout << "Lớp tín chỉ với mã " << malopTC << " đã được xóa." << std::endl;
            return;
        }
    }
    std::cerr << "Không tìm thấy lớp tín chỉ với mã: " << malopTC << std::endl;
}

CreditClass *CreditClassList::findCreditClassByMALOPTC(int malopTC)
{
    for (const auto &creditClass : creditClasses)
    {
        if (creditClass->getMALOPTC() == malopTC)
        {
            return creditClass;
        }
    }
    return nullptr; // Return nullptr if not found
}

void CreditClassList::cancelCreditClass(int malopTC)
{
    for (auto &creditClass : creditClasses)
    {
        if (creditClass->getMALOPTC() == malopTC)
        {
            creditClass->setHuyLop(true); // Set cancellation status
            std::cout << "Lớp tín chỉ với mã " << malopTC << " đã được hủy." << std::endl;
            return;
        }
    }
    std::cerr << "Không tìm thấy lớp tín chỉ với mã: " << malopTC << std::endl;
}

std::vector<CreditClass *> CreditClassList::findClassesByParams(const std::string &nienKhoa,
                                                               int hocKy,
                                                               int nhom,
                                                               const std::string &maMH)
{
    std::vector<CreditClass *> result;
    for (auto &creditClass : creditClasses)
    {
        if ((nienKhoa.empty() || creditClass->getNienKhoa() == nienKhoa) &&
            (hocKy == 0 || creditClass->getHocKy() == hocKy) &&
            (nhom == 0 || creditClass->getNhom() == nhom) &&
            (maMH.empty() || creditClass->getMAMH() == maMH))
        {
            result.push_back(creditClass);
        }
    }
    return result;
}
