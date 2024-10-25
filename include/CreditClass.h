#ifndef CREDITCLASS_H
#define CREDITCLASS_H

#include <string>

class CreditClass {
private:
    std::string classID;
    std::string className;
    int credits; // Số tín chỉ

public:
    CreditClass(const std::string& id, const std::string& name, int credits); // Constructor
    std::string getClassID() const; // Phương thức lấy ID lớp
    std::string getClassName() const; // Phương thức lấy tên lớp
    int getCredits() const; // Phương thức lấy số tín chỉ
};

#endif // CREDITCLASS_H
