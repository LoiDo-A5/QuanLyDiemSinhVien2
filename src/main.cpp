#include <iostream>
#include "ClassList.h"
#include "CourseList.h"
#include "Student.h"
#include "CreditClass.h"
#include "Class.h"

using namespace std;

int main() {
    ClassList classList; // Danh sách lớp
    CourseList courseList; // Danh sách môn học

    int choice;
    do {
        cout << "==== MENU ====" << endl;
        cout << "1. Thêm lớp" << endl;
        cout << "2. In danh sách lớp" << endl;
        cout << "3. Thêm sinh viên vào lớp" << endl;
        cout << "4. Thêm môn học" << endl;
        cout << "5. In danh sách môn học" << endl;
        cout << "6. Cập nhật thông tin lớp" << endl;
        cout << "7. Cập nhật thông tin môn học" << endl;
        cout << "8. Mở lớp tín chỉ" << endl; // Thêm tùy chọn mở lớp tín chỉ
        cout << "0. Thoát" << endl;
        cout << "Chọn chức năng: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string malop, tenlop;
                cout << "Nhập mã lớp: ";
                cin >> malop;
                cout << "Nhập tên lớp: ";
                cin.ignore();
                getline(cin, tenlop);
                Lop newClass(malop, tenlop);
                classList.addClass(newClass);
                break;
            }
            case 2: {
                classList.printClasses();
                break;
            }
            case 3: {
                string malop;
                cout << "Nhập mã lớp: ";
                cin >> malop;
                SinhVien newStudent;
                cout << "Nhập thông tin sinh viên:" << endl;
                newStudent.nhapThongTin();
                classList.addStudentToClass(malop, newStudent);
                break;
            }
            case 4: {
                MonHoc newCourse;
                cout << "Nhập mã môn học: ";
                cin >> newCourse.MAMH;
                cout << "Nhập tên môn học: ";
                cin.ignore();
                getline(cin, newCourse.TENMH);
                cout << "Nhập số tín chỉ lý thuyết: ";
                cin >> newCourse.STCLT;
                cout << "Nhập số tín chỉ thực hành: ";
                cin >> newCourse.STCTH;
                courseList.insert(newCourse);
                break;
            }
            case 5: {
                courseList.printInOrder(courseList.getRoot());
                break;
            }
            case 6: {
                string malop;
                Lop updatedClass;
                cout << "Nhập mã lớp cần cập nhật: ";
                cin >> malop;
                cout << "Nhập thông tin lớp mới:" << endl;
                updatedClass.nhapThongTin(); // Gọi hàm nhập thông tin
                classList.updateClass(malop, updatedClass);
                break;
            }
            case 7: {
                string mamh;
                MonHoc updatedCourse;
                cout << "Nhập mã môn học cần cập nhật: ";
                cin >> mamh;
                cout << "Nhập thông tin môn học mới:" << endl;
                courseList.updateCourse(mamh, updatedCourse);
                break;
            }
            case 8: { // Mở lớp tín chỉ
                int subChoice;
                do {
                    cout << "==== MENU LỚP TÍN CHỈ ====" << endl;
                    cout << "1. Thêm lớp tín chỉ" << endl;
                    cout << "2. Xóa lớp tín chỉ" << endl;
                    cout << "3. Hiệu chỉnh lớp tín chỉ" << endl;
                    cout << "4. In danh sách lớp tín chỉ" << endl;
                    cout << "0. Quay lại" << endl;
                    cout << "Chọn chức năng: ";
                    cin >> subChoice;

                    switch (subChoice) {
                        case 1: {
                            string id, name;
                            int credits;
                            cout << "Nhập mã lớp tín chỉ: ";
                            cin >> id;
                            cout << "Nhập tên lớp tín chỉ: ";
                            cin.ignore();
                            getline(cin, name);
                            cout << "Nhập số tín chỉ: ";
                            cin >> credits;

                            // Create a new CreditClass using the parameters
                            CreditClass newCreditClass(id, name, credits);
                            classList.addCreditClass(newCreditClass); // This should work now
                            break;
                        }
                        case 2: {
                            string classCode;
                            cout << "Nhập mã lớp tín chỉ cần xóa: ";
                            cin >> classCode;
                            classList.removeCreditClass(classCode); // Gọi phương thức xóa lớp tín chỉ
                            break;
                        }
                        case 3: {
                            string classCode;
                            string id, name;
                            int credits;
                            cout << "Nhập mã lớp tín chỉ cần hiệu chỉnh: ";
                            cin >> classCode;
                            cout << "Nhập thông tin lớp tín chỉ mới:" << endl;
                            cout << "Nhập mã lớp tín chỉ: ";
                            cin >> id;
                            cout << "Nhập tên lớp tín chỉ: ";
                            cin.ignore();
                            getline(cin, name);
                            cout << "Nhập số tín chỉ: ";
                            cin >> credits;

                            // Create a new CreditClass using the parameters
                            CreditClass updatedClass(id, name, credits);
                            classList.editCreditClass(classCode, updatedClass); // Gọi phương thức hiệu chỉnh lớp tín chỉ
                            break;
                        }
                        case 4: {
                            classList.printCreditClasses(); // Gọi phương thức in danh sách lớp tín chỉ
                            break;
                        }
                        case 0:
                            break;
                        default:
                            cout << "Lựa chọn không hợp lệ. Vui lòng thử lại." << endl;
                    }
                } while (subChoice != 0);
                break;
            }
            case 0:
                cout << "Thoát chương trình!" << endl;
                break;
            default:
                cout << "Lựa chọn không hợp lệ. Vui lòng thử lại." << endl;
        }
    } while (choice != 0);

    return 0;
}
