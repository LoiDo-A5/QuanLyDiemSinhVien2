#include "Registration.h"
#include <iostream>

// Phương thức cập nhật điểm cho sinh viên
void SinhVienDK::updateScore(float newScore) {
    sinhVien.capNhatDiem(newScore); // Gọi phương thức cập nhật điểm từ lớp SinhVien
}
