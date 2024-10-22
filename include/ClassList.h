#ifndef CLASSLIST_H
#define CLASSLIST_H

#include "Class.h"
#include "Student.h" // Thêm thư viện Student.h nếu cần sử dụng SinhVien

class ClassList {
private:
    Lop* classes[1000];  // Mảng lớp tối đa 1000 lớp
    int classCount;

public:
    ClassList();
    void addClass(const Lop& newClass); // Thêm lớp
    void printClasses(); // In danh sách lớp
    void addStudentToClass(const string& malop, const SinhVien& newStudent); // Thêm sinh viên vào lớp
    void updateClass(const string& malop, const Lop& updatedClass); // Cập nhật lớp
};

#endif
