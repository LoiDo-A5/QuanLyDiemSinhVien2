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
            string mamh, nienkhoa;
            int hocKy, nhom, soSvMin, soSvMax;

            cout << "Nhap ma mon hoc: ";
            getline(cin, mamh);
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

            CreditClass newClass(mamh, nienkhoa, hocKy, nhom, soSvMin, soSvMax);
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
                string mamh, nienkhoa;
                int hocKy, nhom, soSvMin, soSvMax;
                cout << "Nhap ma mon hoc moi: ";
                cin.ignore();
                getline(cin, mamh);
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
            cout << "Nhap nien khoa: ";
            cin >> nienKhoa;
            cout << "Nhap hoc ky: ";
            cin >> hocKy;
            cout << "Nhap nhom: ";
            cin >> nhom;
            cout << "Nhap ma mon hoc: ";
            cin.ignore();
            getline(cin, maMH);

            if (!classList.displayStudentsInClass(nienKhoa, hocKy, nhom, maMH))
                cout << "Khong tim thay lop tin chi voi cac tham so da nhap!\n";

            break;
        }
        case 6:
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
            cout << "Nhap ma sinh vien: ";
            getline(cin, masv);
            cout << "Nhap ho ten sinh vien: ";
            getline(cin, hoten);

            SinhVien newSv(masv, hoten, "", "", "");
            if (classList.registerStudent(to_string(maloptc), newSv))
            {
                cout << "Da them sinh vien!\n";
            }
            else
            {
                cout << "Khong the them sinh vien!\n";
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
