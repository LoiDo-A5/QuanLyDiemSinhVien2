#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

using namespace std;

class SinhVien
{
private:
    string MASV;     // Mã sinh viên
    string HO;       // Họ sinh viên
    string TEN;      // Tên sinh viên
    string GIOITINH; // Giới tính
    string CMND;     // Số chứng minh nhân dân
    float DIEM;      // Điểm của sinh viên

public:
    // Constructor mặc định
    SinhVien();

    // Constructor có tham số
    SinhVien(const string &masv, const string &ho, const string &ten, const string &gioiTinh, const string &cmnd);

    // Hàm nhập thông tin sinh viên
    void nhapThongTin();

    // Hàm in thông tin sinh viên
    void inThongTin() const;

    // Hàm lấy mã sinh viên
    string getMaSV() const;

    // Hàm lấy tên sinh viên (họ và tên)
    string getName() const;

    // Hàm lấy họ
    string getHo() const;

    // Hàm lấy tên
    string getTen() const;

    // Hàm lấy điểm của sinh viên
    float getDiem() const;

    // Hàm cập nhật điểm sinh viên
    void capNhatDiem(float diemMoi);

    // Hàm lấy giới tính
    string getGioiTinh() const;

    // Hàm lấy CMND
    string getCMND() const;

    // Hàm chuyển thông tin sinh viên thành chuỗi
    string toString() const;

    void fromString(const string &data);
};

#endif // STUDENT_H
