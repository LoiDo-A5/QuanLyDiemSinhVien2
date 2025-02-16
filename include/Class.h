// Class.h
#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <string>
#include <vector>
#include "Student.h"
#include "IsValid.h"

class Lop
{
private:
    std::string MALOP;                      // Mã lớp
    std::string TENLOP;                     // Tên lớp
    std::vector<SinhVien> danhSachSinhVien; // Danh sách sinh viên trong lớp

public:
    // Hàm khởi tạo mặc định
    Lop();

    // Hàm khởi tạo có tham số
    Lop(const std::string &malop, const std::string &tenlop);

    std::string getCode();

    // Phương thức để nhập thông tin lớp
    void nhapThongTin();

    // Phương thức để thêm sinh viên vào danh sách
    void addStudent(const SinhVien &student);

    // Phương thức để in thông tin lớp
    void printClassInfo() const;

    // Getter cho MALOP và TENLOP
    std::string getClassID() const;
    std::string getClassName() const;

    // Getter cho danh sách sinh viên (nếu cần, nhưng không khuyến khích truy cập trực tiếp)
    const std::vector<SinhVien> &getStudents() const;

    // Phương thức xóa sinh viên theo mã sinh viên
    bool removeStudent(const std::string &maSV);

    // Phương thức tìm sinh viên theo mã sinh viên
    SinhVien *findStudent(const std::string &maSV);
};

#endif // CLASS_H
