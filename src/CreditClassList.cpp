// CreditClassList.cpp
#include "CreditClassList.h"
#include "CreditClass.h"
#include <iostream>
#include <vector>

// Constructor
CreditClassList::CreditClassList() {}

// Thêm lớp tín chỉ vào danh sách
void CreditClassList::addCreditClass(CreditClass* creditClass) {
    creditClasses.push_back(creditClass);
}

// Hiển thị danh sách lớp tín chỉ
void CreditClassList::displayCreditClasses() {
    for (const auto& creditClass : creditClasses) {
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

// Xóa lớp tín chỉ theo mã lớp tín chỉ
void CreditClassList::removeCreditClass(int malopTC) {
    for (auto it = creditClasses.begin(); it != creditClasses.end(); ++it) {
        if ((*it)->getMALOPTC() == malopTC) {
            delete *it; // Giải phóng bộ nhớ
            creditClasses.erase(it);
            std::cout << "Lớp tín chỉ với mã " << malopTC << " đã được xóa." << std::endl;
            return;
        }
    }
    std::cerr << "Không tìm thấy lớp tín chỉ với mã: " << malopTC << std::endl;
}

// Tìm kiếm lớp tín chỉ theo mã môn học
CreditClass* CreditClassList::findCreditClassByMAMH(const std::string& maMH) {
    for (const auto& creditClass : creditClasses) {
        if (creditClass->getMAMH() == maMH) {
            return creditClass;
        }
    }
    return nullptr; // Trả về nullptr nếu không tìm thấy
}

// Phương thức hủy lớp
void CreditClassList::cancelCreditClass(int malopTC) {
    for (const auto& creditClass : creditClasses) {
        if (creditClass->getMALOPTC() == malopTC) {
            creditClass->setHuyLop(true); // Cập nhật trạng thái hủy lớp
            std::cout << "Lớp tín chỉ với mã " << malopTC << " đã được hủy." << std::endl;
            return;
        }
    }
    std::cerr << "Không tìm thấy lớp tín chỉ với mã: " << malopTC << std::endl;
}
