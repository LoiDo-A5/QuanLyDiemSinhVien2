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
        cout << "1. Menu lớp" << endl;
        cout << "2. Thêm môn học" << endl;
        cout << "3. In danh sách môn học" << endl;
        cout << "4. Cập nhật thông tin môn học" << endl;
        cout << "5. Menu lớp tín chỉ" << endl;
        cout << "0. Thoát" << endl;
        cout << "Chọn chức năng: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int subChoice;
            do
            {
                cout << "==== MENU LỚP ====" << endl;
                cout << "1. Thêm lớp" << endl;
                cout << "2. Xóa lớp" << endl;
                cout << "3. Chỉnh sửa lớp" << endl;
                cout << "4. In danh sách lớp" << endl;
                cout << "5. Thêm sinh viên" << endl;
                cout << "6. Xóa sinh viên" << endl;
                cout << "7. Chỉnh sửa sinh viên" << endl;
                cout << "0. Quay lại" << endl;
                cout << "Chọn chức năng: ";
                cin >> subChoice;
                switch (subChoice)
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
                    if (classList.getClassCount() == 0)
                    {
                        cout << "Không có lớp để xóa!" << endl;
                        break;
                    }
                    string malop;
                    classList.printClasses();
                    cout << "Nhập mã lớp cần xoá: ";
                    cin >> malop;
                    if (classList.removeClassByCode(malop))
                    {
                        cout << "Đã xóa thành công lớp có mã lớp là " << malop;
                    }
                    break;
                }
                case 3:
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

                case 4:
                {
                    classList.printClasses();
                    break;
                }
                case 5:
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

                case 6: // Xóa sinh viên
                {
                    string malop;
                    cout << "Nhập mã lớp: ";
                    cin >> malop;

                    string maSV;
                    cout << "Nhập mã sinh viên cần xóa: ";
                    cin >> maSV;

                    // Tìm lớp theo mã lớp
                    Lop *lop = classList.findClassByCode(malop);

                    if (lop == nullptr)
                    {
                        cout << "Lớp không tồn tại!" << endl;
                        break;
                    }

                    // Tìm sinh viên trong lớp
                    bool removed = lop->removeStudent(maSV);

                    if (removed)
                    {
                        cout << "Xóa sinh viên thành công!" << endl;
                    }
                    else
                    {
                        cout << "Không tìm thấy sinh viên với mã: " << maSV << endl;
                    }
                    break;
                }
                case 7: // Chỉnh sửa sinh viên
                {
                    string malop;
                    cout << "Nhập mã lớp: ";
                    cin >> malop;

                    string maSV;
                    cout << "Nhập mã sinh viên cần chỉnh sửa: ";
                    cin >> maSV;

                    // Tìm lớp theo mã lớp
                    Lop *lop = classList.findClassByCode(malop); // Giả sử classList có phương thức tìm lớp theo mã lớp

                    if (lop == nullptr)
                    {
                        cout << "Lớp không tồn tại!" << endl;
                        break;
                    }

                    // Tìm sinh viên trong lớp
                    SinhVien *student = lop->findStudent(maSV); // Giả sử Lop có phương thức findStudent để tìm sinh viên theo mã sinh viên

                    if (student == nullptr)
                    {
                        cout << "Không tìm thấy sinh viên với mã: " << maSV << endl;
                        break;
                    }

                    // Chỉnh sửa thông tin sinh viên
                    cout << "Nhập thông tin sinh viên mới:" << endl;
                    student->nhapThongTin(); // Nhập lại thông tin sinh viên

                    cout << "Chỉnh sửa sinh viên thành công!" << endl;
                    break;
                }

                default:
                    break;
                }
            } while (subChoice != 0); // Kết thúc vòng lặp con cho lớp tín chỉ
            break;
        }
        case 2:
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
        case 3:
        {
            courseList.printInOrder(courseList.getRoot());
            break;
        }
        case 4:
        {
            string mamh;
            cout << "Nhập mã môn học cần cập nhật: ";
            cin >> mamh;
            courseList.updateCourse(mamh);
            break;
        }
        case 5:
        { // Mở lớp tín chỉ
            int subChoice;
            do
            {
                cout << "==== MENU LỚP TÍN CHỈ ====" << endl;
                cout << "1. Thêm lớp tín chỉ" << endl;
                cout << "2. Xóa lớp tín chỉ" << endl;
                cout << "3. Hiệu chỉnh lớp tín chỉ" << endl;
                cout << "4. In danh sách sinh viên đăng ký theo lớp" << endl;
                cout << "5. In danh sách lớp tín chỉ" << endl;
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

                    // Tạo lớp tín chỉ mới
                    CreditClass *newCreditClass = new CreditClass(malopTC, maMH, tenLop, nienKhoa, hocKy, nhom, soSvMin, soSvMax);
                    creditClassList.addCreditClass(newCreditClass); // Thêm lớp tín chỉ vào danh sách

                    // // Nhập sinh viên vào lớp tín chỉ
                    // char addMoreStudents = 'y'; // Variable to control adding more students
                    // while (addMoreStudents == 'y' || addMoreStudents == 'Y')
                    // {
                    //     SinhVien newStudent;
                    //     cout << "Nhập thông tin sinh viên:" << endl;
                    //     newStudent.nhapThongTin();              // Nhập thông tin sinh viên (mã, họ tên, giới tính, CMND, điểm)
                    //     newCreditClass->addStudent(newStudent); // Thêm sinh viên vào lớp tín chỉ

                    //     cout << "Bạn có muốn thêm sinh viên khác không? (y/n): ";
                    //     cin >> addMoreStudents; // Ask user if they want to add another student
                    // }

                    // // Hiển thị danh sách sinh viên đăng ký sau khi thêm sinh viên
                    // vector<SinhVien> &students = newCreditClass->getDSSVDK(); // Giả sử đây là danh sách sinh viên
                    // if (students.empty())
                    // {
                    //     cout << "Danh sách sinh viên đăng ký: Chưa có sinh viên nào." << endl;
                    // }
                    // else
                    // {
                    //     cout << "Danh sách sinh viên đăng ký: " << endl;
                    //     for (const auto &student : students)
                    //     {
                    //         cout << student.getMaSV() << " - " << student.getHo() << " " << student.getTen() << endl;
                    //     }
                    // }
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
                    int malopTC;
                    cout << "Nhập mã lớp tín chỉ cần hiệu chỉnh: ";
                    cin >> malopTC;

                    // Tìm lớp tín chỉ theo mã lớp tín chỉ (malopTC)
                    CreditClass *creditClass = creditClassList.findCreditClassByMALOPTC(malopTC);
                    if (creditClass == nullptr)
                    {
                        cout << "Không tìm thấy lớp tín chỉ với mã: " << malopTC << endl;
                        break;
                    }

                    // Hiển thị thông tin hiện tại của lớp tín chỉ
                    cout << "Thông tin lớp tín chỉ hiện tại:" << endl;
                    cout << "Mã lớp tín chỉ: " << creditClass->getMALOPTC() << endl;
                    cout << "Mã môn học: " << creditClass->getMAMH() << endl;
                    cout << "Tên lớp: " << creditClass->getTenLop() << endl;
                    cout << "Niên khóa: " << creditClass->getNienKhoa() << endl;
                    cout << "Học kỳ: " << creditClass->getHocKy() << endl;
                    cout << "Nhóm: " << creditClass->getNhom() << endl;
                    cout << "Số sinh viên tối thiểu: " << creditClass->getSoSvMin() << endl;
                    cout << "Số sinh viên tối đa: " << creditClass->getSoSvMax() << endl;
                    cout << "Trạng thái hủy lớp: " << (creditClass->isHuyLop() ? "Có" : "Không") << endl;

                    // Cho phép người dùng nhập thông tin mới
                    cout << "\nNhập thông tin mới cho lớp tín chỉ:" << endl;
                    string maMH, tenLop, nienKhoa;
                    int hocKy, nhom, soSvMin, soSvMax;
                    bool huyLop;

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
                    cout << "Lớp này có bị hủy không? (1: Có, 0: Không): ";
                    cin >> huyLop;

                    // Cập nhật thông tin lớp tín chỉ
                    creditClass->setMAMH(maMH);
                    creditClass->setTenLop(tenLop);
                    creditClass->setNienKhoa(nienKhoa);
                    creditClass->setHocKy(hocKy);
                    creditClass->setNhom(nhom);
                    creditClass->setSoSvMin(soSvMin);
                    creditClass->setSoSvMax(soSvMax);
                    creditClass->setHuyLop(huyLop);

                    break;
                }
                case 4:
                {
                    // In danh sách sinh viên đăng ký theo niên khóa, học kỳ, nhóm, mã môn học
                    int malopTC;
                    cout << "Nhập mã lớp tín chỉ để in danh sách sinh viên: ";
                    cin >> malopTC;

                    // Tìm lớp tín chỉ theo mã lớp tín chỉ (malopTC)
                    CreditClass *creditClass = creditClassList.findCreditClassByMALOPTC(malopTC);

                    if (creditClass == nullptr)
                    {
                        cout << "Không tìm thấy lớp tín chỉ với mã: " << malopTC << endl;
                    }
                    else
                    {
                        // In các thông tin lớp tín chỉ (niên khóa, học kỳ, nhóm, mã môn học)
                        cout << "Thông tin lớp tín chỉ: " << endl;
                        cout << "Mã lớp tín chỉ: " << creditClass->getMALOPTC() << endl;
                        cout << "Mã môn học: " << creditClass->getMAMH() << endl;
                        cout << "Tên lớp: " << creditClass->getTenLop() << endl;
                        cout << "Niên khóa: " << creditClass->getNienKhoa() << endl;
                        cout << "Học kỳ: " << creditClass->getHocKy() << endl;
                        cout << "Nhóm: " << creditClass->getNhom() << endl;

                        // Lấy danh sách sinh viên đăng ký
                        vector<SinhVien> &students = creditClass->getDSSVDK();

                        if (students.empty())
                        {
                            cout << "Danh sách sinh viên đăng ký: Chưa có sinh viên nào." << endl;
                        }
                        else
                        {
                            cout << "Danh sách sinh viên đăng ký: " << endl;
                            for (const auto &student : students)
                            {
                                cout << student.getMaSV() << " - " << student.getHo() << " " << student.getTen() << endl;
                            }
                        }
                    }
                    break;
                }

                case 5:
                {
                    creditClassList.displayCreditClasses();
                    break;
                }

                default:
                    break;
                }
            } while (subChoice != 0); // Kết thúc vòng lặp con cho lớp tín chỉ
            break;
        }
        default:
            break;
        }
    } while (choice != 0);

    return 0;
}
