#include <iostream>
#include "ClassList.h"
#include "CourseList.h"
#include "Student.h"
#include "CreditClass.h"
#include "Class.h"
#include "CreditClassList.h"

using namespace std;

int main()
{
    ClassList classList;             // Danh sách lớp
    CourseList courseList;           // Danh sách môn học
    CreditClassList creditClassList; // Tạo một thể hiện của CreditClassList

    int choice;
    do
    {
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

        switch (choice)
        {
        case 1:
        {
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
        case 2:
        {
            classList.printClasses();
            break;
        }
        case 3:
        {
            string malop;
            cout << "Nhập mã lớp: ";
            cin >> malop;
            SinhVien newStudent;
            cout << "Nhập thông tin sinh viên:" << endl;
            newStudent.nhapThongTin();
            classList.addStudentToClass(malop, newStudent);
            break;
        }
        case 4:
        {
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
        case 5:
        {
            courseList.printInOrder(courseList.getRoot());
            break;
        }
        case 6:
        {
            string malop;
            Lop updatedClass;
            cout << "Nhập mã lớp cần cập nhật: ";
            cin >> malop;
            cout << "Nhập thông tin lớp mới:" << endl;
            updatedClass.nhapThongTin();
            classList.updateClass(malop, updatedClass);
            break;
        }
        case 7:
        {
            string mamh;
            MonHoc updatedCourse;
            cout << "Nhập mã môn học cần cập nhật: ";
            cin >> mamh;
            cout << "Nhập thông tin môn học mới:" << endl;
            courseList.updateCourse(mamh, updatedCourse);
            break;
        }
        case 8:
        { // Mở lớp tín chỉ
            int subChoice;
            do
            {
                cout << "==== MENU LỚP TÍN CHỈ ====" << endl;
                cout << "1. Thêm lớp tín chỉ" << endl;
                cout << "2. Xóa lớp tín chỉ" << endl;
                cout << "3. Hiệu chỉnh lớp tín chỉ" << endl;
                cout << "4. In danh sách sinh viên đăng ký" << endl;
                cout << "0. Quay lại" << endl;
                cout << "Chọn chức năng: ";
                cin >> subChoice;

                switch (subChoice)
                {
                case 1:
                {
                    int malopTC, hocKy, nhom, soSvMin, soSvMax;
                    string maMH, nienKhoa, tenLop;
                    cout << "Nhập mã lớp tín chỉ: ";
                    cin >> malopTC;
                    cout << "Nhập mã môn học: ";
                    cin >> maMH;
                    cout << "Nhập tên lớp: ";
                    cin.ignore();
                    getline(cin, tenLop);
                    cout << "Nhập niên khóa: ";
                    cin >> nienKhoa;
                    cout << "Nhập học kỳ: ";
                    cin >> hocKy;
                    cout << "Nhập nhóm: ";
                    cin >> nhom;
                    cout << "Nhập số sinh viên tối thiểu: ";
                    cin >> soSvMin;
                    cout << "Nhập số sinh viên tối đa: ";
                    cin >> soSvMax;

                    CreditClass *newCreditClass = new CreditClass(malopTC, maMH, tenLop, nienKhoa, hocKy, nhom, soSvMin, soSvMax);
                    creditClassList.addCreditClass(newCreditClass); // Sử dụng instance creditClassList
                    break;
                }
                case 2:
                {
                    int malopTC;
                    cout << "Nhập mã lớp tín chỉ cần xóa: ";
                    cin >> malopTC;
                    creditClassList.removeCreditClass(malopTC); // Sử dụng instance creditClassList
                    break;
                }
                case 3:
                {
                    // Hiệu chỉnh lớp tín chỉ - cần viết logic tương tự như trên
                    break;
                }
                case 4:
                {
                    // In danh sách sinh viên đăng ký - cần viết logic tương tự như trên
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
            break;
        default:
            cout << "Lựa chọn không hợp lệ. Vui lòng thử lại." << endl;
        }
    } while (choice != 0);

    return 0;
}
