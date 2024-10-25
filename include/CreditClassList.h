#ifndef CREDITCLASSLIST_H
#define CREDITCLASSLIST_H

#include <vector>
#include <string>

// Forward declaration
class CreditClass; // Khai báo trước lớp CreditClass

class CreditClassList {
private:
    std::vector<CreditClass> creditClasses; // Danh sách các lớp tín chỉ

public:
    CreditClassList(); // Constructor
    ~CreditClassList(); // Destructor

    void addCreditClass(const CreditClass& creditClass); // Thêm lớp tín chỉ
    void removeCreditClass(const std::string& classID); // Xóa lớp tín chỉ theo ID
    CreditClass* findCreditClass(const std::string& classID); // Tìm lớp tín chỉ theo ID
    void displayCreditClasses(); // Hiển thị danh sách lớp tín chỉ
};

#endif // CREDITCLASSLIST_H
