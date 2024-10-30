#include "ClassList.h"
#include "CreditClass.h"
#include "Node.h"
#include <iostream>
using namespace std;

ClassList::ClassList() : classCount(0), creditClassCount(0) {}

void ClassList::addClass(const Lop& newClass) {
    if (classCount < 1000) {
        classes[classCount++] = new Lop(newClass); // Giả sử Lop có constructor
    } else {
        cout << "Danh sách lớp đã đầy!" << endl;
    }
}

void ClassList::printClasses() {
    for (int i = 0; i < classCount; i++) {
        classes[i]->printClassInfo(); // In thông tin lớp
    }
}

void ClassList::updateClass(const string& malop, const Lop& updatedClass) {
    for (int i = 0; i < classCount; i++) {
        if (classes[i]->getClassID() == malop) {
            *classes[i] = updatedClass;
            cout << "Cập nhật lớp " << malop << " thành công!" << endl;
            return;
        }
    }
    cout << "Không tìm thấy lớp " << malop << "." << endl;
}

void ClassList::addStudentToClass(const string& malop, const SinhVien& newStudent) {
    for (int i = 0; i < classCount; i++) {
        if (classes[i]->getClassID() == malop) {
            classes[i]->addStudent(newStudent);
            cout << "Thêm sinh viên " << newStudent.getMaSV() << " vào lớp " << malop << " thành công!" << endl;
            return;
        }
    }
    cout << "Không tìm thấy lớp " << malop << "." << endl;
}

// Implement the new methods for credit classes

void ClassList::addCreditClass(const CreditClass& newCreditClass) {
    if (creditClassCount < 1000) {
        creditClasses[creditClassCount++] = new CreditClass(newCreditClass); // Giả sử CreditClass có constructor
    } else {
        cout << "Danh sách lớp tín chỉ đã đầy!" << endl;
    }
}

void ClassList::removeCreditClass(const std::string& classCode) {
    for (int i = 0; i < creditClassCount; i++) {
        if (creditClasses[i]->getClassID() == classCode) {
            delete creditClasses[i]; // Giải phóng bộ nhớ
            creditClasses[i] = creditClasses[creditClassCount - 1]; // Di chuyển lớp cuối cùng lên
            creditClassCount--; // Giảm đếm
            cout << "Xóa lớp tín chỉ " << classCode << " thành công!" << endl;
            return;
        }
    }
    cout << "Không tìm thấy lớp tín chỉ " << classCode << "." << endl;
}

void ClassList::editCreditClass(const std::string& classCode, const CreditClass& updatedClass) {
    for (int i = 0; i < creditClassCount; i++) {
        if (creditClasses[i]->getClassID() == classCode) {
            *creditClasses[i] = updatedClass; // Cập nhật thông tin lớp tín chỉ
            cout << "Cập nhật lớp tín chỉ " << classCode << " thành công!" << endl;
            return;
        }
    }
    cout << "Không tìm thấy lớp tín chỉ " << classCode << "." << endl;
}

void ClassList::printCreditClasses() {
    for (int i = 0; i < creditClassCount; i++) {
        cout << creditClasses[i]->getClassID() << " - " << creditClasses[i]->getClassName() << " - " << creditClasses[i]->getCredits() << " tín chỉ" << endl;
    }
}
