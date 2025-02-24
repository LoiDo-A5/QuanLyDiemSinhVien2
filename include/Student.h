#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

class SinhVien
{
private:
    string MASV;
    string HO;
    string TEN;
    string GIOITINH;
    string SODT;

public:
    SinhVien();
    SinhVien(const string &masv, const string &ho, const string &ten,
             const string &gioitinh, const string &sodt);

    // Getter methods
    string getMASV() const;
    string getHO() const;
    string getTEN() const;
    string getGIOITINH() const;
    string getSODT() const;

    void setMASV(const string &masv);
    void setHO(const string &ho);
    void setTEN(const string &ten);
    void setGIOITINH(const string &gioitinh);
    void setSODT(const string &sodt);

    // In thông tin sinh viên
    void inThongTin() const;

    // Thêm đăng ký môn học
    void themDangKy(float diem, bool huy);

    // In danh sách đăng ký môn học
    void inDanhSachDangKy() const;

    // Destructor để giải phóng bộ nhớ
    ~SinhVien();

    string toString() const;
    void fromString(const string &str);
};

#endif // STUDENT_H
