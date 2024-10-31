// CreditClass.h
#ifndef CREDIT_CLASS_H
#define CREDIT_CLASS_H

#include <string>

class CreditClass {
private:
    int MALOPTC;     // Mã lớp tín chỉ
    std::string MAMH; // Mã môn học
    std::string tenLop; // Tên lớp
    std::string nienKhoa; // Niên khóa
    int hocKy;       // Học kỳ
    int nhom;        // Nhóm
    int soSvMin;     // Số sinh viên tối thiểu
    int soSvMax;     // Số sinh viên tối đa
    bool huyLop;     // Trạng thái hủy lớp

public:
    // Constructor
    CreditClass(int malopTC, const std::string& maMH, const std::string& tenLop, 
                const std::string& nienKhoa, int hocKy, int nhom, int soSvMin, int soSvMax);
    
    // Getter methods
    int getMALOPTC() const;
    std::string getMAMH() const;
    std::string getTenLop() const;
    std::string getNienKhoa() const;
    int getHocKy() const;
    int getNhom() const;
    int getSoSvMin() const;
    int getSoSvMax() const;
    bool isHuyLop() const;

    // Setter methods
    void setHuyLop(bool huy);
};

#endif // CREDIT_CLASS_H
