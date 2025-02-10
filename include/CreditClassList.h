// CreditClassList.h
#ifndef CREDIT_CLASS_LIST_H
#define CREDIT_CLASS_LIST_H

#include "CreditClass.h"
#include <vector>
#include <string>

class CreditClassList
{
private:
    std::vector<CreditClass *> creditClasses; // danh sanh cua credit classes

public:
    CreditClassList(); // Constructor

    // Thêm một lớp tín chỉ vào danh sách
    void addCreditClass(CreditClass *creditClass);

    // Hiển thị tất cả các lớp tín chỉ trong danh sách
    void displayCreditClasses();

    // Xóa một lớp tín chỉ theo mã của nó (malopTC)
    void removeCreditClass(int malopTC, bool isAuto);

    // Tìm và trả về một lớp tín dụng theo mã của nó (malopTC)
    CreditClass *findCreditClassByMALOPTC(int malopTC);

    // Hủy các lớp tín chỉ không đủ sinh viên đăng ký
    void cancelCreditClasses();

    // Tìm lớp tín chỉ dựa trên các tham số khác nhau (nienKhoa, hocKy)
    std::vector<CreditClass *> findClassesByParams(const std::string &nienKhoa,
                                                   int hocKy);

    bool registerStudent(const std::string &maMH, const SinhVien &sinhVien);

    void saveToFile(const std::string &filename);
    void readFromFile(const std::string &filename);
    // Tìm lớp tín chỉ dựa trên các tham số khác nhau (nienKhoa, hocKy, nhom, maMH)
    CreditClass *findClass(const std::string &nienKhoa,
                           int hocKy, int nhom, const std::string &maM);
};

#endif // CREDIT_CLASS_LIST_H
