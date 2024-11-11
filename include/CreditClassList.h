// CreditClassList.h
#ifndef CREDIT_CLASS_LIST_H
#define CREDIT_CLASS_LIST_H

#include "CreditClass.h"
#include <vector>
#include <string>

class CreditClassList {
private:
    std::vector<CreditClass*> creditClasses; // Danh sách các lớp tín chỉ

public:
    CreditClassList();  // Hàm khởi tạo
    
    // Thêm một lớp tín chỉ vào danh sách
    void addCreditClass(CreditClass* creditClass);

    // Hiển thị tất cả các lớp tín chỉ trong danh sách
    void displayCreditClasses();

    // Xóa một lớp tín chỉ theo mã lớp tín chỉ (malopTC)
    void removeCreditClass(int malopTC);

    // Tìm và trả về lớp tín chỉ theo mã lớp tín chỉ (malopTC)
    CreditClass* findCreditClassByMALOPTC(int malopTC);

    // Hủy một lớp tín chỉ theo mã lớp tín chỉ (malopTC)
    void cancelCreditClass(int malopTC);
};

#endif // CREDIT_CLASS_LIST_H
