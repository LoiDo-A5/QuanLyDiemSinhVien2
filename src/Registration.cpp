#include "Registration.h"
#include <iostream>
using namespace std;

// Hàm thêm sinh viên vào danh sách đăng ký
void addStudent(SinhVienDK*& head, const string& masv, float diem) {
    SinhVienDK* newStudent = new SinhVienDK;
    newStudent->MASV = masv;
    newStudent->DIEM = diem;
    newStudent->huyDK = false; // Mới thêm sẽ chưa hủy đăng ký
    newStudent->next = head;   // Thêm vào đầu danh sách
    head = newStudent;
}

// Hàm in danh sách sinh viên đăng ký
void printRegisteredStudents(SinhVienDK* head) {
    if (head == nullptr) {
        cout << "Chưa có sinh viên nào đăng ký!" << endl;
        return;
    }

    cout << "Danh sách sinh viên đã đăng ký:" << endl;
    SinhVienDK* current = head;
    while (current != nullptr) {
        cout << "Mã SV: " << current->MASV << ", Điểm: " << current->DIEM << endl;
        current = current->next;
    }
}

// Hàm hủy đăng ký sinh viên
void cancelRegistration(SinhVienDK*& head, const string& masv) {
    SinhVienDK* current = head;
    SinhVienDK* previous = nullptr;

    while (current != nullptr && current->MASV != masv) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Không tìm thấy sinh viên với mã: " << masv << endl;
        return;
    }

    if (previous == nullptr) {
        // Nếu sinh viên cần hủy ở đầu danh sách
        head = current->next;
    } else {
        previous->next = current->next; // Bỏ qua sinh viên
    }

    delete current; // Giải phóng bộ nhớ
    cout << "Hủy đăng ký thành công cho sinh viên: " << masv << endl;
}

// Hàm cập nhật điểm cho sinh viên
void updateStudentScore(SinhVienDK* head, const string& masv, float newScore) {
    SinhVienDK* current = head;

    while (current != nullptr) {
        if (current->MASV == masv) {
            current->updateScore(newScore);
            cout << "Cập nhật điểm cho sinh viên " << masv << " thành công!" << endl;
            return;
        }
        current = current->next;
    }

    cout << "Không tìm thấy sinh viên với mã: " << masv << endl;
}
