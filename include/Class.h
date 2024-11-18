#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <string>
#include <vector>
#include "Student.h" // Bao gồm tệp định nghĩa lớp SinhVien nếu cần

class Lop
{
private:
    std::string MALOP;                      // Mã lớp
    std::string TENLOP;                     // Tên lớp
    std::vector<SinhVien> danhSachSinhVien; // Danh sách sinh viên trong lớp

public:
    // Hàm khởi tạo mặc định
    Lop() : MALOP(""), TENLOP("") {}

    // Hàm khởi tạo có tham số
    Lop(const std::string &malop, const std::string &tenlop) : MALOP(malop), TENLOP(tenlop) {}

    // Phương thức để nhập thông tin lớp
    void nhapThongTin()
    {
        std::cout << "Nhập mã lớp: ";
        std::cin >> MALOP;
        std::cout << "Nhập tên lớp: ";
        std::cin.ignore();
        std::getline(std::cin, TENLOP);
    }

    // Phương thức để thêm sinh viên vào danh sách
    void addStudent(const SinhVien &student)
    {
        danhSachSinhVien.push_back(student);
    }

    // Phương thức để in thông tin lớp
    void printClassInfo() const
    {
        std::cout << "Mã lớp: " << MALOP << ", Tên lớp: " << TENLOP << std::endl;
        std::cout << "Danh sách sinh viên: " << std::endl;
        for (const auto &student : danhSachSinhVien)
        {
            student.inThongTin(); // Giả sử lớp SinhVien có phương thức inThongTin()
        }
    }

    // Getter cho MALOP và TENLOP
    std::string getClassID() const
    {
        return MALOP;
    }

    std::string getClassName() const
    {
        return TENLOP;
    }

    // Getter cho danh sách sinh viên (nếu cần, nhưng không khuyến khích truy cập trực tiếp)
    const std::vector<SinhVien> &getStudents() const
    {
        return danhSachSinhVien;
    }

    bool removeStudent(const std::string &maSV)
    {
        for (auto it = danhSachSinhVien.begin(); it != danhSachSinhVien.end(); ++it)
        {
            if (it->getMaSV() == maSV)
            {                               // Tìm sinh viên theo mã
                danhSachSinhVien.erase(it); // Xóa sinh viên khỏi danh sách
                return true;
            }
        }
        return false; // Không tìm thấy sinh viên
    }
};

#endif // CLASS_H
