#include "CreditClass.h"
#include <iostream>

// Constructor with automatic class ID
CreditClass::CreditClass(int maLopTC, const std::string& maMH, const std::string& tenLop, 
                         const std::string& nienKhoa, int hocKy, int nhom, int minSv, int maxSv)
    : MALOPTC(maLopTC), MAMH(maMH), tenLop(tenLop), nienKhoa(nienKhoa), 
      hocKy(hocKy), nhom(nhom), soSvMin(minSv), soSvMax(maxSv), huyLop(false) {
    // Initialize array of pointers to registered students to nullptr
}

// Getters
int CreditClass::getMALOPTC() const {
    return MALOPTC;
}

std::string CreditClass::getMAMH() const {
    return MAMH;
}

std::string CreditClass::getTenLop() const {
    return tenLop;
}

std::string CreditClass::getNienKhoa() const {
    return nienKhoa;
}

int CreditClass::getHocKy() const {
    return hocKy;
}

int CreditClass::getNhom() const {
    return nhom;
}

int CreditClass::getSoSvMin() const {
    return soSvMin;
}

int CreditClass::getSoSvMax() const {
    return soSvMax;
}

bool CreditClass::isHuyLop() const {
    return huyLop;
}

void CreditClass::setHuyLop(bool huy) {
    huyLop = huy;
}
