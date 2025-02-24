#include <iostream>
#include "CreditClassList.h"

using namespace std;

void menu()
{
    cout << "\n===== QUAN LY LOP TIN CHI =====\n";
    cout << "1. Them lop tin chi\n";
    cout << "2. Xoa lop tin chi\n";
    cout << "3. Hieu chinh lop tin chi\n";
    cout << "4. Hien thi danh sach lop tin chi\n";
    cout << "5. Hien thi danh sach sinh vien theo lop tin chi\n";
    cout << "6. Cap nhat sinh vien cua lop\n";
    cout << "7. Thoat\n";
    cout << "Lua chon: ";
}

int main()
{
    CreditClassList classList;
    int choice;

    do
    {
        menu();
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            int maloptc, hocKy, nhom, soSvMin, soSvMax;
            string mamh, tenlop, nienkhoa;
            cout << "Nhap ma lop tin chi: ";
            cin >> maloptc;
            cin.ignore();
            cout << "Nhap ma mon hoc: ";
            getline(cin, mamh);
            cout << "Nhap ten lop: ";
            getline(cin, tenlop);
            cout << "Nhap nien khoa: ";
            getline(cin, nienkhoa);
            cout << "Nhap hoc ky: ";
            cin >> hocKy;
            cout << "Nhap nhom: ";
            cin >> nhom;
            cout << "Nhap so sinh vien toi thieu: ";
            cin >> soSvMin;
            cout << "Nhap so sinh vien toi da: ";
            cin >> soSvMax;

            CreditClass newClass(maloptc, mamh, tenlop, nienkhoa, hocKy, nhom, soSvMin, soSvMax);
            classList.addCreditClass(newClass);
            cout << "Them lop tin chi thanh cong!\n";
            break;
        }
        case 2:
        {
            int maloptc;
            cout << "Nhap ma lop tin chi can xoa: ";
            cin >> maloptc;
            classList.removeCreditClass(maloptc);
            cout << "Xoa lop tin chi thanh cong!\n";
            break;
        }
        case 3:
        {
            int maloptc;
            cout << "Nhap ma lop tin chi can hieu chinh: ";
            cin >> maloptc;
            CreditClass *foundClass = classList.findCreditClassByMALOPTC(maloptc);
            if (foundClass)
            {
                string mamh, tenlop, nienkhoa;
                int hocKy, nhom, soSvMin, soSvMax;
                cout << "Nhap ma mon hoc moi: ";
                cin.ignore();
                getline(cin, mamh);
                cout << "Nhap ten lop moi: ";
                getline(cin, tenlop);
                cout << "Nhap nien khoa moi: ";
                getline(cin, nienkhoa);
                cout << "Nhap hoc ky moi: ";
                cin >> hocKy;
                cout << "Nhap nhom moi: ";
                cin >> nhom;
                cout << "Nhap so sinh vien toi thieu moi: ";
                cin >> soSvMin;
                cout << "Nhap so sinh vien toi da moi: ";
                cin >> soSvMax;

                foundClass->setMAMH(mamh);
                foundClass->setTenLop(tenlop);
                foundClass->setNienKhoa(nienkhoa);
                foundClass->setHocKy(hocKy);
                foundClass->setNhom(nhom);
                foundClass->setSoSvMin(soSvMin);
                foundClass->setSoSvMax(soSvMax);
                cout << "Hieu chinh lop tin chi thanh cong!\n";
            }
            else
            {
                cout << "Khong tim thay lop tin chi!\n";
            }
            break;
        }
        case 4:
            classList.displayCreditClasses();
            break;
        case 5: // In danh sách sinh viên đã đăng ký lớp tín chỉ
        {
            string nienKhoa, maMH;
            int hocKy, nhom;
            bool found = false;

            // Yêu cầu người dùng nhập thông tin về niên khóa, học kỳ, nhóm và mã môn học
            cout << "Nhập niên khóa: ";
            cin >> nienKhoa;
            cout << "Nhập học kỳ: ";
            cin >> hocKy;
            cout << "Nhập nhóm: ";
            cin >> nhom;
            cout << "Nhập mã môn học: ";
            cin.ignore();
            getline(cin, maMH);

            // Gọi phương thức để hiển thị danh sách sinh viên theo các tham số đã nhập
            found = classList.displayStudentsInClass(nienKhoa, hocKy, nhom, maMH);
            if (!found)
            {
                cout << "Không tìm thấy lớp tín chỉ nào với các tham số đã nhập!\n";
            }

            break;
        }

        case 6: // Cập nhật sinh viên của lớp tín chỉ
        {
            int maloptc;
            cout << "Nhập mã lớp tín chỉ: ";
            cin >> maloptc;
            cin.ignore();

            CreditClass *foundClass = classList.findCreditClassByMALOPTC(maloptc);
            if (!foundClass)
            {
                cout << "Không tìm thấy lớp tín chỉ!\n";
                break;
            }

            string masv, hoten;
            int svChoice;
            SinhVien newSv;
            SinhVien *sv = nullptr; // Khai báo biến sv ở ngoài switch

            do
            {
                cout << "\n=== QUẢN LÝ SINH VIÊN CỦA LỚP ===\n";
                cout << "1. Thêm sinh viên\n";
                cout << "2. Xóa sinh viên\n";
                cout << "3. Hiệu chỉnh thông tin sinh viên\n";
                cout << "4. Thoát\n";
                cout << "Lựa chọn: ";
                cin >> svChoice;
                cin.ignore();

                switch (svChoice)
                {
                case 1: // Thêm sinh viên
                    do
                    {
                        cout << "Nhập mã sinh viên (Nhập rỗng để dừng): ";
                        getline(cin, masv);
                        if (masv.empty())
                            break;

                        cout << "Nhập họ tên sinh viên: ";
                        getline(cin, hoten);
                        newSv = SinhVien(masv, hoten, "", "", "", ""); // Tạo đối tượng sinh viên mới

                        // Đăng ký sinh viên vào lớp tín chỉ
                        if (classList.registerStudent(foundClass->getMAMH(), newSv))
                        {
                            cout << "Đã thêm sinh viên!\n";
                        }
                    } while (!masv.empty());
                    break;

                case 2: // Xóa sinh viên
                    cout << "Nhập mã sinh viên cần xóa: ";
                    getline(cin, masv);
                    if (foundClass->removeStudent(masv))
                    {
                        cout << "Đã xóa sinh viên!\n";
                    }
                    else
                    {
                        cout << "Không tìm thấy sinh viên!\n";
                    }
                    break;

                case 3: // Hiệu chỉnh sinh viên
                    cout << "Nhập mã sinh viên cần hiệu chỉnh: ";
                    getline(cin, masv);
                    sv = foundClass->findStudent(masv); // Sử dụng biến sv đã khai báo trước đó
                    if (sv)
                    {
                        cout << "Nhập họ tên mới: ";
                        getline(cin, hoten);
                        sv->setTEN(hoten);
                        cout << "Đã cập nhật thông tin sinh viên!\n";
                    }
                    else
                    {
                        cout << "Không tìm thấy sinh viên!\n";
                    }
                    break;

                case 4:
                    cout << "Thoát quản lý sinh viên!\n";
                    break;

                default:
                    cout << "Lựa chọn không hợp lệ!\n";
                }
            } while (svChoice != 4);

            // Sau khi đã nhập/xóa/sửa sinh viên, in danh sách sinh viên
            string nienKhoa, maMH;
            int hocKy, nhom;
            bool found = false;

            cout << "Nhập niên khóa: ";
            cin >> nienKhoa;
            cout << "Nhập học kỳ: ";
            cin >> hocKy;
            cout << "Nhập nhóm: ";
            cin >> nhom;
            cout << "Nhập mã môn học: ";
            cin.ignore();
            getline(cin, maMH);

            found = classList.displayStudentsInClass(nienKhoa, hocKy, nhom, maMH); // Hiển thị danh sách sinh viên đã đăng ký
            if (!found)
            {
                cout << "Không tìm thấy lớp tín chỉ nào với các tham số đã nhập!\n";
            }

            break;
        }

        case 7:
            cout << "Thoat chuong trinh!\n";
            break;
        default:
            cout << "Lua chon khong hop le!\n";
        }
    } while (choice != 7);

    return 0;
}
