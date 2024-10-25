#include "CreditClassList.h"
#include "CreditClass.h" // Bao gồm định nghĩa lớp CreditClass
#include <iostream>

CreditClassList::CreditClassList() {}

CreditClassList::~CreditClassList() {}

void CreditClassList::addCreditClass(const CreditClass& creditClass) {
    creditClasses.push_back(creditClass); // Thêm lớp tín chỉ vào danh sách
}

void CreditClassList::removeCreditClass(const std::string& classID) {
    // Logic để xóa lớp tín chỉ theo ID
}

CreditClass* CreditClassList::findCreditClass(const std::string& classID) {
    // Logic để tìm lớp tín chỉ
    return nullptr; // Thay thế bằng logic tìm kiếm thật sự
}

void CreditClassList::displayCreditClasses() {
    for (const auto& creditClass : creditClasses) {
        std::cout << "Class ID: " << creditClass.getClassID() 
                  << ", Class Name: " << creditClass.getClassName() 
                  << ", Credits: " << creditClass.getCredits() << std::endl;
    }
}
