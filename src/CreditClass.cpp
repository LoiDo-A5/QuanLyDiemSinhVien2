#include "CreditClass.h"
#include <iostream>

CreditClass::CreditClass(const std::string &maMH,
                         const std::string &nk, int hk, int n,
                         int min, int max)
    : MALOPTC(0), MAMH(maMH), nienKhoa(nk),
      hocKy(hk), nhom(n), soSvMin(min), soSvMax(max), huyLop(false), dssvdk(nullptr) {}

// Constructor
CreditClass::CreditClass()
    : MALOPTC(0), MAMH(""), nienKhoa(""),
      hocKy(0), nhom(0), soSvMin(0), soSvMax(0), huyLop(false), dssvdk(nullptr) {}

CreditClass::~CreditClass()
{
    DangKyNode *current = dssvdk;
    while (current != nullptr)
    {
        DangKyNode *temp = current;
        current = current->next;
        delete temp;
    }
}

// Getter và Setter cho các trường thông tin khác
int CreditClass::getMALOPTC() const { return MALOPTC; }
std::string CreditClass::getMAMH() const { return MAMH; }
std::string CreditClass::getNienKhoa() const { return nienKhoa; }
int CreditClass::getHocKy() const { return hocKy; }
int CreditClass::getNhom() const { return nhom; }
int CreditClass::getSoSvMin() const { return soSvMin; }
int CreditClass::getSoSvMax() const { return soSvMax; }
bool CreditClass::isHuyLop() const { return huyLop; }

// Setters
void CreditClass::setMaLopTC(int maLopTC) { MALOPTC = maLopTC; }
void CreditClass::setMAMH(const std::string &maMH) { MAMH = maMH; }
void CreditClass::setNienKhoa(const std::string &nienKhoa) { this->nienKhoa = nienKhoa; }
void CreditClass::setHocKy(int hocKy) { this->hocKy = hocKy; }
void CreditClass::setNhom(int nhom) { this->nhom = nhom; }
void CreditClass::setSoSvMin(int soSvMin) { this->soSvMin = soSvMin; }
void CreditClass::setSoSvMax(int soSvMax) { this->soSvMax = soSvMax; }
void CreditClass::setHuyLop(bool huy) { huyLop = huy; }

// Thêm sinh viên vào lớp tín chỉ
void CreditClass::addStudent(const std::string maSV)
{
    // Kiểm tra nếu lớp chưa đầy
    if (dssvdk == nullptr)
    {
        dssvdk = new DangKyNode(maSV); // Khởi tạo danh sách sinh viên đầu tiên
    }
    else
    {
        DangKyNode *current = dssvdk;
        // Duyệt đến phần tử cuối cùng trong danh sách
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = new DangKyNode(maSV); // Thêm sinh viên vào cuối danh sách
    }
    std::cout << "Sinh viên " << maSV << " đã được thêm vào lớp tín chỉ." << std::endl;
}

// Lấy danh sách sinh viên đăng ký
DangKyNode *CreditClass::getDSSVDK() const
{
    return dssvdk;
}

// Cập nhật danh sách sinh viên đăng ký
void CreditClass::capNhatDSSV(DangKyNode *dssv)
{
    // Nếu danh sách dssvdk chưa có (nullptr), khởi tạo danh sách
    if (dssvdk == nullptr)
    {
        dssvdk = dssv;
    }
    else
    {
        // Nếu đã có danh sách, cần cập nhật thêm sinh viên vào danh sách
        DangKyNode *current = dssvdk;
        while (current->next != nullptr)
        {
            current = current->next; // Duyệt đến sinh viên cuối cùng trong danh sách
        }
        current->next = dssv; // Thêm sinh viên vào cuối danh sách
    }
}

DangKyNode *CreditClass::findStudent(const std::string &maSV)
{
    DangKyNode *current = dssvdk;
    while (current != nullptr)
    {
        if (current->MASV == maSV)
        {
            return current; // Trả về con trỏ đến sinh viên nếu tìm thấy
        }
        current = current->next;
    }
    return nullptr; // Không tìm thấy sinh viên
}

int CreditClass::countRegisteredStudents() const
{
    int count = 0;
    DangKyNode *current = dssvdk;
    while (current != nullptr)
    {
        count++;
        current = current->next;
    }
    return count;
}

void CreditClass::setDSSVDK(DangKyNode *newNode)
{
    dssvdk = newNode;
}

// // Phương thức cập nhật danh sách sinh viên
// void CreditClass::capNhatDSSV(SinhVienNode *dssv)
// {
//     dssvdk = dssv; // Cập nhật danh sách sinh viên
// }

// // In danh sách sinh viên
// void CreditClass::inDSSV() const
// {
//     SinhVienNode *current = dssvdk;
//     while (current != nullptr)
//     {
//         std::cout << current->student.getHO() << " " << current->student.getTEN() << std::endl;
//         current = current->next;
//     }
// }

// // Getter cho danh sách sinh viên đăng ký
// SinhVienNode *CreditClass::getDSSVDK() const
// {
//     return dssvdk; // Trả về con trỏ đến danh sách sinh viên
// }

// int CreditClass::getSoLuongSinhVien() const
// {
//     int count = 0;
//     SinhVienNode *current = dssvdk; // Bắt đầu từ đầu danh sách liên kết
//     while (current != nullptr)
//     {
//         count++;
//         current = current->next;
//     }
//     return count;
// }

// bool CreditClass::hasStudent(const std::string &msv) const
// {
//     SinhVienNode *current = dssvdk; // Bắt đầu từ đầu danh sách liên kết
//     while (current != nullptr)
//     {
//         if (current->student.getMASV() == msv)
//         {
//             return true; // Tìm thấy sinh viên
//         }
//         current = current->next; // Di chuyển đến node tiếp theo
//     }
//     return false; // Không tìm thấy sinh viên
// }

// SinhVien *CreditClass::findStudent(const std::string &maSV)
// {
//     SinhVienNode *current = dssvdk;
//     while (current != nullptr)
//     {
//         if (current->student.getMASV() == maSV)
//         {
//             return &current->student; // Trả về con trỏ đến sinh viên tìm thấy
//         }
//         current = current->next;
//     }
//     return nullptr; // Không tìm thấy
// }

// // Hàm xóa sinh viên theo mã số
// bool CreditClass::removeStudent(const std::string &maSV)
// {
//     if (dssvdk == nullptr)
//         return false; // Danh sách rỗng

//     SinhVienNode *current = dssvdk;
//     SinhVienNode *previous = nullptr;

//     // Tìm sinh viên trong danh sách liên kết
//     while (current != nullptr)
//     {
//         if (current->student.getMASV() == maSV)
//         {
//             if (previous == nullptr)
//             {
//                 // Nếu sinh viên cần xóa là node đầu tiên
//                 dssvdk = current->next;
//             }
//             else
//             {
//                 // Nếu sinh viên cần xóa ở giữa hoặc cuối danh sách
//                 previous->next = current->next;
//             }
//             delete current; // Giải phóng bộ nhớ
//             return true;    // Xóa thành công
//         }
//         previous = current;
//         current = current->next;
//     }
//     return false; // Không tìm thấy sinh viên
// }