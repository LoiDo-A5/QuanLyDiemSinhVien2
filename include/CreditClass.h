#ifndef CREDIT_CLASS_H
#define CREDIT_CLASS_H

#include <string>
#include <vector>
#include "Student.h"

class CreditClass
{
private:
    int MALOPTC;                  // Mã lớp tín chỉ
    std::string MAMH;             // Mã môn học
    std::string tenLop;           // Tên lớp
    std::string nienKhoa;         // Niên khóa
    int hocKy;                    // Học kỳ
    int nhom;                     // Nhóm
    int soSvMin;                  // Số sinh viên tối thiểu
    int soSvMax;                  // Số sinh viên tối đa
    bool huyLop;                  // Trạng thái hủy lớp
    std::vector<SinhVien> DSSVDK; // Danh sách sinh viên đăng ký lớp tín chỉ

public:
    // Constructor
    CreditClass(int malopTC, const std::string &maMH, const std::string &tenLop,
                const std::string &nienKhoa, int hocKy, int nhom, int soSvMin, int soSvMax);

    int getMALOPTC() const;
    std::string getMAMH() const;
    std::string getTenLop() const;
    std::string getNienKhoa() const;
    int getHocKy() const;
    int getNhom() const;
    int getSoSvMin() const;
    int getSoSvMax() const;
    bool isHuyLop() const;
    std::vector<SinhVien> &getDSSVDK();
    void capNhatDSSV(vector<SinhVien> dssv);
    void setMAMH(const std::string &maMH);
    void setTenLop(const std::string &tenLop);
    void setNienKhoa(const std::string &nienKhoa);
    void setHocKy(int hocKy);
    void setNhom(int nhom);
    void setSoSvMin(int soSvMin);
    void setSoSvMax(int soSvMax);
    void setHuyLop(bool huy);

    void addStudent(const SinhVien &student, bool docFile);
};

#endif // CREDIT_CLASS_H
