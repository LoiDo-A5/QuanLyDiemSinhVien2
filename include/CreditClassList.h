#ifndef CREDIT_CLASS_LIST_H
#define CREDIT_CLASS_LIST_H

#include "CreditClass.h"
#include "Student.h"
#include <string>

class CreditClassList
{
private:
    CreditClass creditClasses[10000]; // Mảng lớp tín chỉ với kích thước cố định
    int count;                        // Số lượng lớp tín chỉ hiện có

public:
    // Constructor
    CreditClassList();

    // Thêm lớp tín chỉ
    void addCreditClass(const CreditClass &creditClass);

    // Xóa lớp tín chỉ theo mã
    void removeCreditClass(int malopTC);

    // Tìm lớp tín chỉ theo mã lớp tín chỉ
    CreditClass *findCreditClassByMALOPTC(int malopTC);

    // Hiển thị danh sách lớp tín chỉ
    void displayCreditClasses() const;

    // Xóa các lớp tín chỉ không đủ sinh viên
    void cancelCreditClasses();

    // Tìm lớp tín chỉ theo niên khóa và học kỳ
    CreditClass *findClassesByParams(const std::string &nienKhoa, int hocKy);

    // Tìm lớp tín chỉ theo mã môn học, học kỳ, nhóm, niên khóa
    CreditClass *findClass(const std::string &nienKhoa, int hocKy, int nhom, const std::string &maMH);

    // Đăng ký sinh viên vào lớp tín chỉ
    bool registerStudent(const std::string &maMH, const SinhVien &sinhVien);

    // Lưu danh sách lớp tín chỉ vào file
    void saveToFile(const std::string &filename) const;

    // Đọc danh sách lớp tín chỉ từ file
    void readFromFile(const std::string &filename);

    // Tìm lớp theo mã sinh viên
    CreditClass *findClassesByMsv(const std::string &msv);

    // Lấy số lượng lớp tín chỉ
    int getCount() const;

    bool displayStudentsInClass(const std::string &nienKhoa, int hocKy, int nhom, const std::string &maMH) const;
};

#endif // CREDIT_CLASS_LIST_H
