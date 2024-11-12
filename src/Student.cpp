#include "Student.h"

// Constructor mặc định
SinhVien::SinhVien() : MASV(""), HO(""), TEN(""), GIOITINH(""), CMND(""), DIEM(0.0) {}

// Constructor có tham số
SinhVien::SinhVien(const string& masv, const string& ho, const string& ten, const string& gioiTinh, const string& cmnd, float diem)
    : MASV(masv), HO(ho), TEN(ten), GIOITINH(gioiTinh), CMND(cmnd), DIEM(diem) {}

// Hàm nhập thông tin sinh viên
void SinhVien::nhapThongTin() {
    cout << "Nhập mã sinh viên: ";
    cin >> MASV;
    cout << "Nhập họ: ";
    cin.ignore(); // To clear the newline character from previous input
    getline(cin, HO);  // Using getline to capture multi-word names
    cout << "Nhập tên: ";
    getline(cin, TEN); // Using getline for full names
    cout << "Nhập giới tính: ";
    cin >> GIOITINH;
    cout << "Nhập số CMND: ";
    cin >> CMND;
    cout << "Nhập điểm: ";
    cin >> DIEM;
}

// Hàm in thông tin sinh viên
void SinhVien::inThongTin() const {
    cout << "Mã sinh viên: " << MASV << ", Họ: " << HO << ", Tên: " << TEN
         << ", Giới tính: " << GIOITINH << ", CMND: " << CMND << ", Điểm: " << DIEM << endl;
}

// Hàm lấy mã sinh viên
string SinhVien::getMaSV() const {
    return MASV;
}

// Hàm lấy tên sinh viên (họ và tên)
string SinhVien::getName() const {
    return HO + " " + TEN; // Trả về họ và tên
}

// Hàm lấy họ
string SinhVien::getHo() const {
    return HO;
}

// Hàm lấy tên
string SinhVien::getTen() const {
    return TEN;
}

// Hàm cập nhật điểm sinh viên
void SinhVien::capNhatDiem(float diemMoi) {
    DIEM = diemMoi;
}
