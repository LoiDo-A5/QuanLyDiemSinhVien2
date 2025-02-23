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
        case 5:
        {
            string nienKhoa, maMH;
            int hocKy, nhom;
            bool found = false;

            do
            {
                cout << "Nhap nien khoa: ";
                cin.ignore();
                getline(cin, nienKhoa);
                cout << "Nhap hoc ky: ";
                cin >> hocKy;
                cout << "Nhap nhom: ";
                cin >> nhom;
                cout << "Nhap ma mon hoc: ";
                cin.ignore();
                getline(cin, maMH);

                found = classList.displayStudentsInClass(nienKhoa, hocKy, nhom, maMH);
                if (!found)
                {
                    cout << "Khong tim thay lop tin chi nao voi cac tham so da nhap! Vui long thu lai.\n";
                }
            } while (!found);

            break;
        }
        case 6: // Cập nhật sinh viên của lớp
        {
            int maloptc;
            cout << "Nhap ma lop tin chi: ";
            cin >> maloptc;
            cin.ignore();

            CreditClass *foundClass = classList.findCreditClassByMALOPTC(maloptc);
            if (!foundClass)
            {
                cout << "Khong tim thay lop tin chi!\n";
                break;
            }

            string masv, hoten;
            int svChoice;
            SinhVien *sv = nullptr; // Khai báo biến SinhVien* trước switch

            do
            {
                cout << "\n=== QUAN LY SINH VIEN CUA LOP ===\n";
                cout << "1. Them sinh vien\n";
                cout << "2. Xoa sinh vien\n";
                cout << "3. Hieu chinh thong tin sinh vien\n";
                cout << "4. Thoat\n";
                cout << "Lua chon: ";
                cin >> svChoice;
                cin.ignore();

                switch (svChoice)
                {
                case 1: // Thêm sinh viên
                    do
                    {
                        cout << "Nhap ma sinh vien (Nhap rong de dung): ";
                        getline(cin, masv);
                        if (masv.empty())
                            break;

                        cout << "Nhap ho ten sinh vien: ";
                        getline(cin, hoten);

                        SinhVien newSv(masv, hoten, "", "", "", ""); // Truyền đầy đủ 6 tham số
                        foundClass->addStudent(newSv);
                        cout << "Da them sinh vien!\n";
                    } while (!masv.empty());
                    break;

                case 2: // Xóa sinh viên
                    cout << "Nhap ma sinh vien can xoa: ";
                    getline(cin, masv);
                    if (foundClass->removeStudent(masv))
                    {
                        cout << "Da xoa sinh vien!\n";
                    }
                    else
                    {
                        cout << "Khong tim thay sinh vien!\n";
                    }
                    break;

                case 3: // Hiệu chỉnh sinh viên
                    cout << "Nhap ma sinh vien can hieu chinh: ";
                    getline(cin, masv);
                    sv = foundClass->findStudent(masv); // Sử dụng biến sv đã khai báo trước đó
                    if (sv)
                    {
                        cout << "Nhap ho ten moi: ";
                        getline(cin, hoten);
                        sv->setTEN(hoten);
                        cout << "Da cap nhat thong tin sinh vien!\n";
                    }
                    else
                    {
                        cout << "Khong tim thay sinh vien!\n";
                    }
                    break;

                case 4:
                    cout << "Thoat quan ly sinh vien!\n";
                    break;

                default:
                    cout << "Lua chon khong hop le!\n";
                }
            } while (svChoice != 4);
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
