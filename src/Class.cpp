// Class.cpp
#include "Class.h"

// Hàm khởi tạo mặc định
Lop::Lop() : MALOP(""), TENLOP("") {}

// Hàm khởi tạo có tham số
Lop::Lop(const std::string &malop, const std::string &tenlop) : MALOP(malop), TENLOP(tenlop) {}

// Hàm lấy mã lớp
std::string Lop::getCode()
{
    return MALOP;
}

// Phương thức để nhập thông tin lớp
void Lop::nhapThongTin()
{
    std::cout << "Nhập mã lớp: ";
    std::cin >> MALOP;
    isValidCode(MALOP); // Kiểm tra tính hợp lệ của mã lớp
    std::cout << "Nhập tên lớp: ";
    std::cin.ignore();              // Xóa bỏ ký tự newline còn lại trong bộ đệm
    std::getline(std::cin, TENLOP); // Đọc toàn bộ dòng văn bản, bao gồm cả khoảng trắng
}

// Phương thức để thêm sinh viên vào danh sách
void Lop::addStudent(const SinhVien &student)
{
    danhSachSinhVien.push_back(student);
}

// Phương thức để in thông tin lớp
void Lop::printClassInfo() const
{
    std::cout << "Mã lớp: " << MALOP << ", Tên lớp: " << TENLOP << std::endl;
    std::cout << "Danh sách sinh viên: " << std::endl;
    for (const auto &student : danhSachSinhVien)
    {
        student.inThongTin(); // Giả sử lớp SinhVien có phương thức inThongTin()
    }
}

// Getter cho MALOP và TENLOP
std::string Lop::getClassID() const
{
    return MALOP;
}

std::string Lop::getClassName() const
{
    return TENLOP;
}

// Getter cho danh sách sinh viên (nếu cần, nhưng không khuyến khích truy cập trực tiếp)
const std::vector<SinhVien> &Lop::getStudents() const
{
    return danhSachSinhVien;
}

// Phương thức xóa sinh viên theo mã sinh viên
bool Lop::removeStudent(const std::string &maSV)
{
    for (auto it = danhSachSinhVien.begin(); it != danhSachSinhVien.end(); ++it)
    {
        if (it->getMaSV() == maSV) // Tìm sinh viên theo mã
        {
            danhSachSinhVien.erase(it); // Xóa sinh viên khỏi danh sách
            return true;
        }
    }
    return false; // Không tìm thấy sinh viên
}

// Phương thức tìm sinh viên theo mã sinh viên
SinhVien *Lop::findStudent(const std::string &maSV)
{
    for (auto &student : danhSachSinhVien)
    {
        if (student.getMaSV() == maSV)
        {
            return &student; // Trả về con trỏ đến sinh viên
        }
    }
    return nullptr; // Không tìm thấy sinh viên
}
