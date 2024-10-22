#ifndef CREDITCLASS_H
#define CREDITCLASS_H

#include <string>
#include "Registration.h"  // Bao gồm Registration.h để sử dụng SinhVienDK

using namespace std;

struct LopTinChi {
    int MALOPTC;            // Mã lớp tín chỉ (tự động tăng)
    string MAMH;            // Mã môn học
    string nienKhoa;        // Niên khóa
    int hocKy;              // Học kỳ
    int nhom;               // Nhóm
    int soSVMin;            // Số sinh viên tối thiểu
    int soSVMax;            // Số sinh viên tối đa
    bool huyLop;            // Trạng thái hủy lớp
    SinhVienDK* dsSinhVienDK;  // Con trỏ đến danh sách sinh viên đăng ký (danh sách liên kết đơn)

    // Thêm phương thức để in danh sách sinh viên đã đăng ký
    void printRegisteredStudents();

    // Thêm phương thức để kiểm tra và hủy lớp
    void checkAndCancelClass();

    // Các phương thức khác như thêm sinh viên, cập nhật điểm, v.v. có thể thêm ở đây
};

#endif
    