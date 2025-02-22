#ifndef CREDIT_CLASS_H
#define CREDIT_CLASS_H

#include <string>
#include "Student.h"  // Đảm bảo rằng bạn đã bao gồm file Student.h

// Định nghĩa SinhVienNode (dùng cho danh sách liên kết đơn)
struct SinhVienNode
{
    SinhVien student;        // Thông tin sinh viên
    SinhVienNode* next;      // Con trỏ đến phần tử tiếp theo trong danh sách

    // Constructor cho node
    SinhVienNode(const SinhVien &sv) : student(sv), next(nullptr) {}
};

class CreditClass
{
private:
    int MALOPTC;                   // Mã lớp tín chỉ
    std::string MAMH;              // Mã môn học
    std::string tenLop;            // Tên lớp
    std::string nienKhoa;          // Niên khóa
    int hocKy;                     // Học kỳ
    int nhom;                      // Nhóm
    int soSvMin;                   // Số sinh viên tối thiểu
    int soSvMax;                   // Số sinh viên tối đa
    bool huyLop;                   // Trạng thái hủy lớp
    SinhVienNode *dssvdk;          // Danh sách sinh viên đăng ký lớp tín chỉ (danh sách liên kết đơn)
    
public:
    // Constructor
    CreditClass(int malopTC, const std::string &maMH, const std::string &tenLop,
                const std::string &nienKhoa, int hocKy, int nhom, int soSvMin, int soSvMax);

    // Getter và Setter
    void addStudent(const SinhVien &student);  // Thêm sinh viên vào danh sách đăng ký
    void capNhatDSSV(SinhVienNode *dssv);      // Cập nhật danh sách sinh viên
    void inDSSV() const;                       // In danh sách sinh viên đăng ký
};

#endif // CREDIT_CLASS_H
