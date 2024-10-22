#include "CreditClass.h"
#include <iostream>
using namespace std;

void LopTinChi::printRegisteredStudents() {
    SinhVienDK* current = dsSinhVienDK; // Bắt đầu từ đầu danh sách sinh viên đăng ký
    if (current == nullptr) {
        cout << "Chưa có sinh viên nào đăng ký lớp tín chỉ này!" << endl;
        return;
    }

    cout << "Danh sách sinh viên đã đăng ký:" << endl;
    while (current != nullptr) {
        cout << "Mã SV: " << current->MASV << ", Điểm: " << current->DIEM << endl;
        current = current->next;
    }
}

void LopTinChi::checkAndCancelClass() {
    int studentCount = 0;
    SinhVienDK* current = dsSinhVienDK;

    // Đếm số sinh viên đã đăng ký
    while (current != nullptr) {
        studentCount++;
        current = current->next;
    }

    if (studentCount < soSVMin) {
        huyLop = true; // Hủy lớp nếu số lượng sinh viên ít hơn số tối thiểu
        cout << "Lớp tín chỉ " << MALOPTC << " đã bị hủy do số sinh viên đăng ký không đủ!" << endl;
    } else {
        cout << "Lớp tín chỉ " << MALOPTC << " vẫn tiếp tục hoạt động!" << endl;
    }
}
