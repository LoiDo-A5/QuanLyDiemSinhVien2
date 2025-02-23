#include "CreditClass.h"
#include <iostream>

CreditClass::CreditClass(int MALOPTC, const std::string &MAMH, const std::string &tenLop,
                         const std::string &nienKhoa, int hocKy, int nhom,
                         int soSvMin, int soSvMax)
    : MALOPTC(MALOPTC), MAMH(MAMH), tenLop(tenLop), nienKhoa(nienKhoa),
      hocKy(hocKy), nhom(nhom), soSvMin(soSvMin), soSvMax(soSvMax), huyLop(false), dssvdk(nullptr) {}

// Constructor
CreditClass::CreditClass()
    : MALOPTC(0), MAMH(""), tenLop(""), nienKhoa(""),
      hocKy(0), nhom(0), soSvMin(0), soSvMax(0), huyLop(false), dssvdk(nullptr) {}

CreditClass::~CreditClass()
{
    SinhVienNode *current = dssvdk;
    while (current != nullptr)
    {
        SinhVienNode *temp = current;
        current = current->next;
        delete temp;
    }
}

// Getter và Setter cho các trường thông tin khác
int CreditClass::getMALOPTC() const { return MALOPTC; }
std::string CreditClass::getMAMH() const { return MAMH; }
std::string CreditClass::getTenLop() const { return tenLop; }
std::string CreditClass::getNienKhoa() const { return nienKhoa; }
int CreditClass::getHocKy() const { return hocKy; }
int CreditClass::getNhom() const { return nhom; }
int CreditClass::getSoSvMin() const { return soSvMin; }
int CreditClass::getSoSvMax() const { return soSvMax; }
bool CreditClass::isHuyLop() const { return huyLop; }

// Setters
void CreditClass::setMAMH(const std::string &maMH) { MAMH = maMH; }
void CreditClass::setTenLop(const std::string &tenLop) { this->tenLop = tenLop; }
void CreditClass::setNienKhoa(const std::string &nienKhoa) { this->nienKhoa = nienKhoa; }
void CreditClass::setHocKy(int hocKy) { this->hocKy = hocKy; }
void CreditClass::setNhom(int nhom) { this->nhom = nhom; }
void CreditClass::setSoSvMin(int soSvMin) { this->soSvMin = soSvMin; }
void CreditClass::setSoSvMax(int soSvMax) { this->soSvMax = soSvMax; }
void CreditClass::setHuyLop(bool huy) { huyLop = huy; }

// Thêm sinh viên vào lớp tín chỉ
void CreditClass::addStudent(const SinhVien &student)
{
    // Kiểm tra nếu lớp chưa đầy
    if (dssvdk == nullptr)
    {
        dssvdk = new SinhVienNode(student); // Khởi tạo danh sách sinh viên đầu tiên
    }
    else
    {
        SinhVienNode *current = dssvdk;
        // Duyệt đến phần tử cuối cùng trong danh sách
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = new SinhVienNode(student); // Thêm sinh viên vào cuối danh sách
    }
    std::cout << "Sinh viên " << student.getHO() << " " << student.getTEN() << " đã được thêm vào lớp tín chỉ." << std::endl;
}

// Phương thức cập nhật danh sách sinh viên
void CreditClass::capNhatDSSV(SinhVienNode *dssv)
{
    dssvdk = dssv; // Cập nhật danh sách sinh viên
}

// In danh sách sinh viên
void CreditClass::inDSSV() const
{
    SinhVienNode *current = dssvdk;
    while (current != nullptr)
    {
        std::cout << current->student.getHO() << " " << current->student.getTEN() << std::endl;
        current = current->next;
    }
}

// Getter cho danh sách sinh viên đăng ký
SinhVienNode *CreditClass::getDSSVDK() const
{
    return dssvdk; // Trả về con trỏ đến danh sách sinh viên
}

int CreditClass::getSoLuongSinhVien() const
{
    int count = 0;
    SinhVienNode *current = dssvdk; // Bắt đầu từ đầu danh sách liên kết
    while (current != nullptr)
    {
        count++;
        current = current->next;
    }
    return count;
}

bool CreditClass::hasStudent(const std::string &msv) const
{
    SinhVienNode *current = dssvdk; // Bắt đầu từ đầu danh sách liên kết
    while (current != nullptr)
    {
        if (current->student.getMASV() == msv)
        {
            return true; // Tìm thấy sinh viên
        }
        current = current->next; // Di chuyển đến node tiếp theo
    }
    return false; // Không tìm thấy sinh viên
}