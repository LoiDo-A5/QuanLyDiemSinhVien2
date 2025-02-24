#ifndef CREDIT_CLASS_H
#define CREDIT_CLASS_H

#include <string>
#include "Student.h"

class DangKyNode
{
public:
    string MASV;
    float DIEM;
    bool huyDangKy;
    DangKyNode *next;

    DangKyNode(string masv, float diem, bool huy)
        : MASV(masv), DIEM(diem), huyDangKy(huy), next(nullptr) {}
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
    CreditClass(const std::string &MAMH,
                const std::string &nienKhoa, int hocKy, int nhom,
                int soSvMin, int soSvMax);

    // Nếu bạn cần constructor mặc định
    CreditClass();

    // Getter và Setter
    void addStudent(const DangKyNode &student); // Thêm sinh viên vào danh sách đăng ký
    void capNhatDSSV(DangKyNode *dssv);         // Cập nhật danh sách sinh viên
    void inDSSV() const;                        // In danh sách sinh viên đăng ký

    // Getter các thông tin khác
    int getMALOPTC() const;
    std::string getMAMH() const;
    std::string getNienKhoa() const;
    int getHocKy() const;
    int getNhom() const;
    int getSoSvMin() const;
    int getSoSvMax() const;
    bool isHuyLop() const;

    // Setters cho các trường
    void setMAMH(const std::string &maMH);
    void setNienKhoa(const std::string &nienKhoa);
    void setHocKy(int hocKy);
    void setNhom(int nhom);
    void setSoSvMin(int soSvMin);
    void setSoSvMax(int soSvMax);
    void setHuyLop(bool huy);

    // Getter cho danh sách sinh viên đăng ký
    DangKyNode *getDSSVDK() const; // Trả về con trỏ đến danh sách sinh viên
    int getSoLuongSinhVien() const;
    bool hasStudent(const std::string &msv) const;
    bool removeStudent(const std::string &maSV);
    DangKyNode *findStudent(const std::string &maSV);

    ~CreditClass();
};

#endif // CREDIT_CLASS_H
