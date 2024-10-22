#include <iostream>
#include "../include/Course.h"
#include "../include/Class.h"
#include "../include/Student.h"
#include "../include/CreditClass.h"
#include "../include/CourseList.h"
#include "../include/ClassList.h"

using namespace std;

int main() {
    // Tạo danh sách môn học
    CourseList courseList;  
    MonHoc newCourse;
    
    // Nhập môn học
    cout << "Nhập mã môn học: ";
    cin >> newCourse.MAMH;
    cout << "Nhập tên môn học: ";
    cin.ignore(); // Để loại bỏ newline
    getline(cin, newCourse.TENMH);
    cout << "Nhập số tín chỉ lý thuyết: ";
    cin >> newCourse.STCLT;
    cout << "Nhập số tín chỉ thực hành: ";
    cin >> newCourse.STCTH;

    courseList.insert(newCourse); // Thêm môn học vào danh sách

    // In danh sách môn học
    cout << "Danh sách môn học:" << endl;
    courseList.printInOrder(courseList.getRoot());

    // Tạo danh sách lớp
    ClassList classList;  
    Lop newClass;
    
    // Nhập thông tin lớp
    cout << "Nhập mã lớp: ";
    cin >> newClass.MALOP;
    cout << "Nhập tên lớp: ";
    cin.ignore(); // Để loại bỏ newline
    getline(cin, newClass.TENLOP);

    classList.addClass(newClass); // Thêm lớp vào danh sách

    // In danh sách lớp
    cout << "Danh sách lớp:" << endl;
    classList.printClasses();

    return 0;
}
