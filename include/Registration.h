#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <string>  // Thư viện cần thiết để sử dụng string

using namespace std;

struct SinhVienDK {
    string MASV;          // Mã sinh viên
    float DIEM;           // Điểm của sinh viên
    bool huyDK;           // Trạng thái hủy đăng ký
    SinhVienDK* next;     // Con trỏ tới sinh viên đăng ký tiếp theo trong danh sách liên kết đơn

    // Phương thức cập nhật điểm
    void updateScore(float newScore) {
        DIEM = newScore;  // Cập nhật điểm của sinh viên
    }
};

#endif
