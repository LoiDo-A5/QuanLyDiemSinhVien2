#ifndef CLASSLIST_H
#define CLASSLIST_H

#include "Class.h"
#include "Student.h" // Thêm thư viện Student.h nếu cần sử dụng SinhVien
#include "CreditClass.h" // Add this line to include CreditClass

class ClassList {
private:
    Lop* classes[1000];  // Mảng lớp tối đa 1000 lớp
    int classCount;

    CreditClass* creditClasses[1000]; // Declare array for credit classes
    int creditClassCount; // Declare the count for credit classes

public:
    ClassList();
    void addClass(const Lop& newClass); // Thêm lớp
    void printClasses(); // In danh sách lớp
    void addStudentToClass(const std::string& malop, const SinhVien& newStudent); // Thêm sinh viên vào lớp
    void updateClass(const std::string& malop, const Lop& updatedClass); // Cập nhật lớp

    void addCreditClass(const CreditClass& newCreditClass); // Thêm lớp tín chỉ
    void removeCreditClass(const std::string& classCode); // Xóa lớp tín chỉ
    void editCreditClass(const std::string& classCode, const CreditClass& updatedClass); // Hiệu chỉnh lớp tín chỉ
    void printCreditClasses(); // In danh sách lớp tín chỉ
};

#endif // CLASSLIST_H
