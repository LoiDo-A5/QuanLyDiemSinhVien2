#include "Student.h"
#include <iostream>

using namespace std;

// Constructor không tham số
SinhVien::SinhVien() : MASV(""), HO(""), TEN(""), GIOITINH(""), CMND(""), DIEM(0) {}

// Constructor có tham số
SinhVien::SinhVien(const string& masv, const string& ho, const string& ten, const string& gioiTinh, const string& cmnd, float diem)
    : MASV(masv), HO(ho), TEN(ten), GIOITINH(gioiTinh), CMND(cmnd), DIEM(diem) {}

// Hàm nhập thông tin sinh viên
void SinhVien::nhapThongTin() {
    cout << "Nhập mã sinh viên: ";
    cin >> MASV;
    cout << "Nhập họ sinh viên: ";
    cin.ignore();
    getline(cin, HO);
    cout << "Nhập tên sinh viên: ";
    getline(cin, TEN);
    cout << "Nhập giới tính: ";
    getline(cin, GIOITINH);
    cout << "Nhập số CMND: ";
    getline(cin, CMND);
    cout << "Nhập điểm: ";
    cin >> DIEM;
}

// Hàm in thông tin sinh viên
void SinhVien::inThongTin() const {
    cout << "Mã SV: " << MASV << ", Họ tên: " << HO << " " << TEN
         << ", Giới tính: " << GIOITINH << ", CMND: " << CMND
         << ", Điểm: " << DIEM << endl;
}

// Hàm lấy mã sinh viên
string SinhVien::getMaSV() const {
    return MASV;
}

// Hàm cập nhật điểm sinh viên
void SinhVien::capNhatDiem(float diemMoi) {
    DIEM = diemMoi;
}

