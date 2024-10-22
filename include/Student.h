#ifndef STUDENT_H
#define STUDENT_H

#include <string>

using namespace std;

class SinhVien {
private:
    string MASV;      // Mã sinh viên
    string HO;        // Họ sinh viên
    string TEN;       // Tên sinh viên
    string GIOITINH;  // Giới tính
    string CMND;      // Số chứng minh nhân dân
    float DIEM;       // Điểm của sinh viên

public:
    // Constructor mặc định
    SinhVien();

    // Constructor có tham số
    SinhVien(const string& masv, const string& ho, const string& ten, const string& gioiTinh, const string& cmnd, float diem);

    // Hàm nhập thông tin sinh viên
    void nhapThongTin();

    // Hàm in thông tin sinh viên
    void inThongTin() const;

    // Hàm lấy mã sinh viên
    string getMaSV() const;

    // Hàm cập nhật điểm sinh viên
    void capNhatDiem(float diemMoi);
};

#endif
