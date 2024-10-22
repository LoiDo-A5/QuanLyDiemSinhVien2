#ifndef CLASS_H
#define CLASS_H

#include "Node.h"  // Sử dụng Node cho danh sách sinh viên
#include <string>

using namespace std;

class Lop {
public:
    string MALOP;   // Mã lớp
    string TENLOP;  // Tên lớp
    Node* danhSachSinhVien;  // Danh sách sinh viên trong lớp (dùng Node*)

    // Constructor
    Lop(const string& malop, const string& tenlop) : MALOP(malop), TENLOP(tenlop), danhSachSinhVien(nullptr) {}
};

#endif
