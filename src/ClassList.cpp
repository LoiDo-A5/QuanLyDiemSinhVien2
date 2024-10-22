#include "ClassList.h"
#include "Node.h"
#include <iostream>
using namespace std;

ClassList::ClassList() : classCount(0) {}

void ClassList::addClass(const Lop& newClass) {
    if (classCount < 1000) {
        classes[classCount++] = new Lop(newClass); // Giả sử Lop có constructor
    } else {
        cout << "Danh sách lớp đã đầy!" << endl;
    }
}

void ClassList::printClasses() {
    for (int i = 0; i < classCount; i++) {
        cout << "Mã lớp: " << classes[i]->MALOP << ", Tên lớp: " << classes[i]->TENLOP << endl;
    }
}

void ClassList::updateClass(const string& malop, const Lop& updatedClass) {
    for (int i = 0; i < classCount; i++) {
        if (classes[i]->MALOP == malop) {
            *classes[i] = updatedClass; // Cập nhật thông tin lớp
            cout << "Cập nhật lớp " << malop << " thành công!" << endl;
            return;
        }
    }
    cout << "Không tìm thấy lớp với mã: " << malop << endl;
}

// Thêm chức năng nhập sinh viên vào lớp
void ClassList::addStudentToClass(const string& malop, const SinhVien& newStudent) {
    for (int i = 0; i < classCount; i++) {
        if (classes[i]->MALOP == malop) {
            Node* newNode = new Node(newStudent);  // Tạo một nút mới chứa sinh viên

            newNode->next = classes[i]->danhSachSinhVien; // Thêm sinh viên vào đầu danh sách
            classes[i]->danhSachSinhVien = newNode; // Cập nhật danh sách sinh viên
            
            // Sử dụng getter để lấy MASV
            cout << "Thêm sinh viên " << newStudent.getMaSV() << " vào lớp " << malop << " thành công!" << endl;
            return;
        }
    }
    cout << "Không tìm thấy lớp với mã: " << malop << endl;
}
