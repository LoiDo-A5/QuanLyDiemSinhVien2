#include <iostream>
#include "ClassList.h"
#include "CourseList.h"
#include "Student.h"
#include "CreditClass.h"
#include "Class.h"
#include "CreditClassList.h"
#include "IsValid.h"

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
                    isValidCode(malop);

                    cin.ignore();
                    cout << "Nhập tên lớp: ";
                    isValidString(tenlop);
                    Lop newClass(malop, tenlop);
                    classList.addClass(newClass);
                    classList.saveToFile("classList.txt");
                    break;
                }
                case 2: // Xóa lớp
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
                    isValidCode(malop);
                    if (classList.removeClassByCode(malop))
                    {
                        cout << "Đã xóa thành công lớp có mã lớp là " << malop << endl;
                        classList.saveToFile("classList.txt"); // Lưu sau khi xóa lớp
                    }
                    break;
                }
                case 3: // Chỉnh sửa lớp
                {
                    string malop;
                    Lop updatedClass;
                    cout << "Nhập mã lớp cần cập nhật: ";
                    cin >> malop;
                    isValidCode(malop);
                    cout << "Nhập thông tin lớp mới:" << endl;
                    updatedClass.nhapThongTin();
                    classList.updateClass(malop, updatedClass);

                    classList.saveToFile("classList.txt"); // Lưu sau khi chỉnh sửa lớp
                    break;
                }

                case 4: // In danh sách lớp
                {
                    classList.printClasses();
                    break;
                }
                case 5: // Thêm sinh viên
                {
                    string malop;
                    cout << "Nhập mã lớp: ";
                    cin >> malop;
                    isValidCode(malop);

                    SinhVien newStudent;
                    cout << "Nhập thông tin sinh viên:" << endl;
                    newStudent.nhapThongTin();
                    classList.addStudentToClass(malop, newStudent);

                    classList.saveToFile("classList.txt"); // Lưu sau khi thêm sinh viên
                    break;
                }
                case 6: // Xóa sinh viên
                {
                    string malop;
                    cout << "Nhập mã lớp: ";
                    cin >> malop;
                    isValidCode(malop);

                    string maSV;
                    cout << "Nhập mã sinh viên cần xóa: ";
                    cin >> maSV;
                    isValidCode(maSV);

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
                        classList.saveToFile("classList.txt"); // Lưu sau khi xóa sinh viên
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
                    isValidCode(malop);

                    string maSV;
                    cout << "Nhập mã sinh viên cần chỉnh sửa: ";
                    cin >> maSV;
                    isValidCode(maSV);

                    // Tìm lớp theo mã lớp
                    Lop *lop = classList.findClassByCode(malop);

                    if (lop == nullptr)
                    {
                        cout << "Lớp không tồn tại!" << endl;
                        break;
                    }

                    // Tìm sinh viên trong lớp
                    SinhVien *student = lop->findStudent(maSV);

                    if (student == nullptr)
                    {
                        cout << "Không tìm thấy sinh viên với mã: " << maSV << endl;
                        break;
                    }

                    // Chỉnh sửa thông tin sinh viên
                    cout << "Nhập thông tin sinh viên mới:" << endl;
                    student->nhapThongTin(); // Nhập lại thông tin sinh viên

                    cout << "Chỉnh sửa sinh viên thành công!" << endl;
                    classList.saveToFile("classList.txt"); // Lưu sau khi chỉnh sửa sinh viên
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
            isValidCode(newCourse.MAMH);
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
                cout << "6. Đăng ký tín chỉ" << endl;
                cout << "7. Huỷ các lớp tín chỉ không đủ sinh viên" << endl;
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

                case 6:
                {
                    string maSV;
                    cout << "Nhập mã sinh viên để đăng ký tín chỉ: ";
                    cin >> maSV;
                    SinhVien *sv = classList.findSinhVienById(maSV);
                    if (sv == nullptr)
                    {
                        cout << "Không tìm thấy sinh viên" << endl;
                    }
                    else
                    {
                        sv->inThongTin();
                        string nienKhoa;
                        int hocKy;
                        cout << "Nhập niên khóa, học kỳ để tìm môn học phù hợp: ";
                        cin >> nienKhoa >> hocKy;
                        vector<CreditClass *> classes = creditClassList.findClassesByParams(nienKhoa, hocKy);
                        if (classes.size() == 0)
                        {
                            cout << "Không tìm thấy lớp tín chỉ phù hợp!" << endl;
                        }
                        else
                        {
                            for (const auto &creditClass : classes)
                            {
                                cout << "Mã môn học: " << creditClass->getMAMH()
                                     << ", Tên môn học: " << creditClass->getTenLop()
                                     << ", Nhóm: " << creditClass->getNhom()
                                     << ", Số sinh viên đã đăng ký: " << creditClass->getDSSVDK().size()
                                     << ", Số slot còn trống: " << creditClass->getSoSvMax() - creditClass->getDSSVDK().size()
                                     << endl;
                            }
                            string maMH;
                            cout << "Nhập mã môn học cần đăng ký: ";
                            cin >> maMH;
                            bool ketQuaDangKy = creditClassList.registerStudent(maMH, *sv);
                            if (ketQuaDangKy == true)
                            {
                                cout << "Đăng ký thành công" << endl;
                            }
                            else
                            {
                                cout << "Mã môn học không hợp lệ!" << endl;
                            }
                        }
                    }
                }

                case 7:
                {
                    creditClassList.cancelCreditClasses();
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
