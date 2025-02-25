#include "../include/Student.h"
#include <IsValid.h>

SinhVien::SinhVien() : MASV(""), HO(""), TEN(""), GIOITINH(""), SODT("") {}

SinhVien::SinhVien(const string &masv, const string &ho, const string &ten,
                   const string &gioitinh, const string &sodt)
    : MASV(masv), HO(ho), TEN(ten), GIOITINH(gioitinh), SODT(sodt) {}

string SinhVien::getMASV() const { return MASV; }
string SinhVien::getHO() const { return HO; }
string SinhVien::getTEN() const { return TEN; }
string SinhVien::getGIOITINH() const { return GIOITINH; }
string SinhVien::getSODT() const { return SODT; }

void SinhVien::setMASV(const string &masv) { MASV = masv; }
void SinhVien::setHO(const string &ho) { HO = ho; }
void SinhVien::setTEN(const string &ten) { TEN = ten; }
void SinhVien::setGIOITINH(const string &gioitinh) { GIOITINH = gioitinh; }
void SinhVien::setSODT(const string &sodt) { SODT = sodt; }

void SinhVien::inThongTin() const
{
    cout << "Mã SV: " << MASV << ", Họ: " << HO << ", Tên: " << TEN
         << ", Giới tính: " << GIOITINH << ", Số điện thoại: " << SODT << endl;
}

// SinhVien::~SinhVien()
// {
//     while (dsdangky)
//     {
//         DangKy *temp = dsdangky;
//         dsdangky = dsdangky->next;
//         delete temp;
//     }
// }

string SinhVien::toString() const
{
    stringstream ss;
    ss << MASV << " " << HO << " " << TEN << " " << GIOITINH << " " << SODT;
    return ss.str();
}

void SinhVien::fromString(const string &str)
{
    istringstream ss(str);
    ss >> MASV >> HO >> TEN >> GIOITINH >> SODT;
}

void SinhVien::nhapThongTin()
{
    cout << "Nhập mã sinh viên: ";
    cin >> MASV;
    isValidCode(MASV);

    cin.ignore(); // Để xóa ký tự xuống dòng từ mục nhập trước đó

    cout << "Nhập họ: ";
    isValidString(HO);

    cout << "Nhập tên: ";
    isValidString(TEN);

    cout << "Nhập giới tính: ";
    isValidString(GIOITINH);

    cout << "Nhập SDT: ";
    cin >> SODT;
    isValidSDT(SODT);
}