#include "CreditClass.h"
#include <iostream>

CreditClass::CreditClass(const std::string &MAMH, const std::string &nienKhoa,
                         int hocKy, int nhom, int soSvMin, int soSvMax)
    : MAMH(MAMH), nienKhoa(nienKhoa),
      hocKy(hocKy), nhom(nhom), soSvMin(soSvMin), soSvMax(soSvMax), huyLop(false), dssvdk(nullptr) {}

// Constructor mặc định
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

// Getter các thông tin khác
int CreditClass::getMALOPTC() const { return MALOPTC; }
std::string CreditClass::getMAMH() const { return MAMH; }
std::string CreditClass::getNienKhoa() const { return nienKhoa; }
int CreditClass::getHocKy() const { return hocKy; }
int CreditClass::getNhom() const { return nhom; }
int CreditClass::getSoSvMin() const { return soSvMin; }
int CreditClass::getSoSvMax() const { return soSvMax; }
bool CreditClass::isHuyLop() const { return huyLop; }

// Setters
void CreditClass::setMAMH(const std::string &maMH) { MAMH = maMH; }
void CreditClass::setNienKhoa(const std::string &nienKhoa) { this->nienKhoa = nienKhoa; }
void CreditClass::setHocKy(int hocKy) { this->hocKy = hocKy; }
void CreditClass::setNhom(int nhom) { this->nhom = nhom; }
void CreditClass::setSoSvMin(int soSvMin) { this->soSvMin = soSvMin; }
void CreditClass::setSoSvMax(int soSvMax) { this->soSvMax = soSvMax; }
void CreditClass::setHuyLop(bool huy) { huyLop = huy; }

// Thêm sinh viên vào danh sách đăng ký lớp tín chỉ
void CreditClass::addStudent(const DangKyNode &student)
{
    DangKyNode *newNode = new DangKyNode(student.MASV, student.DIEM, student.huyDangKy);

    if (dssvdk == nullptr)
    {
        dssvdk = newNode;
    }
    else
    {
        DangKyNode *current = dssvdk;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }
    std::cout << "Sinh viên " << student.MASV << " đã đăng ký lớp tín chỉ thành công.\n";
}

// Cập nhật danh sách sinh viên đăng ký
void CreditClass::capNhatDSSV(DangKyNode *dssv)
{
    dssvdk = dssv;
}

// In danh sách sinh viên đăng ký lớp tín chỉ
void CreditClass::inDSSV() const
{
    DangKyNode *current = dssvdk;
    if (!current)
    {
        std::cout << "Lớp tín chỉ này chưa có sinh viên đăng ký.\n";
        return;
    }

    std::cout << "Danh sách sinh viên đã đăng ký:\n";
    while (current != nullptr)
    {
        std::cout << "Mã SV: " << current->MASV << ", Điểm: " << current->DIEM
                  << ", Hủy ĐK: " << (current->huyDangKy ? "Có" : "Không") << std::endl;
        current = current->next;
    }
}

// Getter cho danh sách sinh viên đăng ký
DangKyNode *CreditClass::getDSSVDK() const
{
    return dssvdk;
}

// Lấy số lượng sinh viên đã đăng ký
int CreditClass::getSoLuongSinhVien() const
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

// Kiểm tra sinh viên có đăng ký lớp hay không
bool CreditClass::hasStudent(const std::string &msv) const
{
    DangKyNode *current = dssvdk;
    while (current != nullptr)
    {
        if (current->MASV == msv)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Tìm sinh viên theo mã số
DangKyNode *CreditClass::findStudent(const std::string &maSV)
{
    DangKyNode *current = dssvdk;
    while (current != nullptr)
    {
        if (current->MASV == maSV)
        {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

// Xóa sinh viên khỏi danh sách đăng ký
bool CreditClass::removeStudent(const std::string &maSV)
{
    if (dssvdk == nullptr)
        return false;

    DangKyNode *current = dssvdk;
    DangKyNode *previous = nullptr;

    while (current != nullptr)
    {
        if (current->MASV == maSV)
        {
            if (previous == nullptr)
            {
                dssvdk = current->next;
            }
            else
            {
                previous->next = current->next;
            }
            delete current;
            return true;
        }
        previous = current;
        current = current->next;
    }
    return false;
}
