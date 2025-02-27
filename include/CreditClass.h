#ifndef CREDIT_CLASS_H
#define CREDIT_CLASS_H

#include <string>
#include "Student.h"

class DangKyNode
{
public:
    std::string MASV;
    float DIEM;
    bool huyDangKy;
    DangKyNode *next;

    DangKyNode(std::string masv)
        : MASV(masv), DIEM(0), huyDangKy(false), next(nullptr) {}
};

class CreditClass
{
private:
    int MALOPTC;          // Mã lớp tín chỉ (số nguyên tự động tăng)
    std::string MAMH;     // Mã môn học
    std::string nienKhoa; // Niên khóa
    int hocKy;            // Học kỳ
    int nhom;             // Nhóm
    int soSvMin;          // Số sinh viên tối thiểu
    int soSvMax;          // Số sinh viên tối đa
    bool huyLop;          // Trạng thái hủy lớp
    DangKyNode *dssvdk;   // Danh sách sinh viên đăng ký lớp tín chỉ (danh sách liên kết đơn)

public:
    // Constructor
    CreditClass();
    CreditClass(const std::string &MAMH,
                const std::string &nienKhoa, int hocKy, int nhom,
                int soSvMin, int soSvMax);

    ~CreditClass(); // Destructor để giải phóng bộ nhớ

    // Getter và Setter
    int getMALOPTC() const;
    std::string getMAMH() const;
    std::string getNienKhoa() const;
    int getHocKy() const;
    int getNhom() const;
    int getSoSvMin() const;
    int getSoSvMax() const;
    bool isHuyLop() const;

    void setMaLopTC(int maLopTC);
    void setMAMH(const std::string &maMH);
    void setNienKhoa(const std::string &nienKhoa);
    void setHocKy(int hocKy);
    void setNhom(int nhom);
    void setSoSvMin(int soSvMin);
    void setSoSvMax(int soSvMax);
    void setHuyLop(bool huy);

    // Quản lý sinh viên trong lớp tín chỉ
    void addStudent(const std::string maSV);
    DangKyNode *getDSSVDK() const;      // Lấy danh sách sinh viên đăng ký
    void capNhatDSSV(DangKyNode *dssv); // Cập nhật danh sách sinh viên đăng ký
    bool removeStudent(const std::string &maSV);

    DangKyNode *findStudent(const std::string &maSV);
    int countRegisteredStudents() const;
    void setDSSVDK(DangKyNode *newNode);
};

#endif // CREDIT_CLASS_H
