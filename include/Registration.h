#ifndef REGISTRATION_H
#define REGISTRATION_H

#include "Student.h" // Thêm thư viện Student.h để sử dụng lớp SinhVien

class SinhVienDK {
private:
    SinhVien sinhVien; // Đối tượng sinh viên

public:
    // Phương thức cập nhật điểm
    void updateScore(float newScore);
    
    // Có thể thêm các phương thức khác nếu cần
};

#endif // REGISTRATION_H
