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
    string CMND;
    string SODT;
    map<string, float> DIEM;

    struct DangKy
    {
        string MASV;
        float DIEM;
        bool huyDangKy;
        DangKy *next;

        DangKy(string masv, float diem, bool huy)
            : MASV(masv), DIEM(diem), huyDangKy(huy), next(nullptr) {}
    };
    DangKy *dsdangky;

public:
    SinhVien();
    SinhVien(const string &masv, const string &ho, const string &ten,
             const string &gioitinh, const string &cmnd, const string &sodt);

    // Getter methods
    string getMASV() const;
    string getHO() const;
    string getTEN() const;
    string getGIOITINH() const;
    string getCMND() const;
    string getSODT() const;

    void setMASV(const string &masv);
    void setHO(const string &ho);
    void setTEN(const string &ten);
    void setGIOITINH(const string &gioitinh);
    void setCMND(const string &cmnd);
    void setSODT(const string &sodt);

    // Cập nhật điểm
    void capNhatDiem(const string &maMH, float diemMoi);

    // Lấy điểm của môn học
    float getDiem(const string &maMH) const;

    // In thông tin sinh viên
    void inThongTin() const;

    // In điểm các môn học
    void inDiem() const;

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
