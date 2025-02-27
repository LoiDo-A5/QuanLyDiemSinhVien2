#include "CreditClassList.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Constructor
CreditClassList::CreditClassList() : count(0) {}

// Tìm lớp tín chỉ theo mã lớp tín chỉ
CreditClass *CreditClassList::findCreditClassByMALOPTC(int malopTC)
{
    for (int i = 0; i < count; ++i)
    {
        if (creditClasses[i]->getMALOPTC() == malopTC)
        {
            return creditClasses[i];
        }
    }
    return nullptr;
}

// // Hiển thị danh sách lớp tín chỉ
// void CreditClassList::displayCreditClasses() const
// {
//     for (int i = 0; i < count; ++i)
//     {
//         cout << "Mã lớp: " << creditClasses[i].getMALOPTC() << " - Môn: " << creditClasses[i].getMAMH() << endl;
//     }
// }

// // Hủy lớp tín chỉ không đủ sinh viên
// void CreditClassList::cancelCreditClasses()
// {
//     for (int i = 0; i < count; ++i)
//     {
//         if (creditClasses[i].getSoLuongSinhVien() < creditClasses[i].getSoSvMin())
//         {
//             creditClasses[i].setHuyLop(true);
//             cout << "Lớp " << creditClasses[i].getMALOPTC() << " đã bị hủy." << endl;
//         }
//     }
// }

// // Tìm lớp theo niên khóa và học kỳ
// CreditClass *CreditClassList::findClassesByParams(const string &nienKhoa, int hocKy)
// {
//     for (int i = 0; i < count; ++i)
//     {
//         if (creditClasses[i].getNienKhoa() == nienKhoa && creditClasses[i].getHocKy() == hocKy)
//         {
//             return &creditClasses[i];
//         }
//     }
//     return nullptr;
// }

// // Tìm lớp theo nhiều tham số
// CreditClass *CreditClassList::findClass(const string &nienKhoa, int hocKy, int nhom, const string &maMH)
// {
//     for (int i = 0; i < count; ++i)
//     {
//         if (creditClasses[i].getNienKhoa() == nienKhoa &&
//             creditClasses[i].getHocKy() == hocKy &&
//             creditClasses[i].getNhom() == nhom &&
//             creditClasses[i].getMAMH() == maMH)
//         {
//             cout << "DEBUG: Tim thay lop tin chi!" << endl;
//             return &creditClasses[i];
//         }
//     }
//     cout << "DEBUG: Khong tim thay lop tin chi nao!" << endl;
//     return nullptr;
// }

// // Đăng ký sinh viên vào lớp tín chỉ
// bool CreditClassList::registerStudent(const string &maMH, const SinhVien &sinhVien)
// {
//     for (int i = 0; i < count; ++i)
//     {
//         if (creditClasses[i].getMAMH() == maMH)
//         {
//             creditClasses[i].addStudent(sinhVien); // Thêm sinh viên vào lớp tín chỉ
//             cout << "Sinh viên " << sinhVien.getHO() << " " << sinhVien.getTEN() << " đã đăng ký lớp tín chỉ "
//                  << maMH << " thành công!" << endl;
//             return true;
//         }
//     }
//     cout << "Không tìm thấy lớp tín chỉ với mã môn học: " << maMH << endl;
//     return false;
// }

// // Lưu danh sách lớp tín chỉ vào file
// void CreditClassList::saveToFile(const string &filename) const
// {
//     ofstream outFile(filename);
//     if (!outFile)
//     {
//         cerr << "Không thể mở file để ghi!" << endl;
//         return;
//     }
//     for (int i = 0; i < count; ++i)
//     {
//         outFile << creditClasses[i].getMALOPTC() << " "
//                 << creditClasses[i].getMAMH() << " "
//                 << creditClasses[i].getNienKhoa() << " "
//                 << creditClasses[i].getHocKy() << " "
//                 << creditClasses[i].getNhom() << " "
//                 << creditClasses[i].getSoSvMin() << " "
//                 << creditClasses[i].getSoSvMax() << " "
//                 << creditClasses[i].isHuyLop() << endl;
//     }
//     outFile.close();
// }

// // Đọc danh sách lớp tín chỉ từ file
// void CreditClassList::readFromFile(const string &filename)
// {
//     ifstream inFile(filename);
//     if (!inFile)
//     {
//         cerr << "Không thể mở file để đọc!" << endl;
//         return;
//     }
//     count = 0;
//     while (!inFile.eof())
//     {
//         int malopTC, hocKy, nhom, soSvMin, soSvMax;
//         string maMH, tenLop, nienKhoa;
//         bool huyLop;

//         // Đọc dữ liệu từ file
//         inFile >> malopTC >> maMH >> tenLop >> nienKhoa >> hocKy >> nhom >> soSvMin >> soSvMax >> huyLop;

//         // Kiểm tra nếu có dữ liệu hợp lệ
//         if (inFile)
//         {
//             creditClasses[count++] = CreditClass(malopTC, maMH, tenLop, nienKhoa, hocKy, nhom, soSvMin, soSvMax);
//         }
//     }
//     inFile.close();
// }

// // Tìm lớp theo mã sinh viên
// CreditClass *CreditClassList::findClassesByMsv(const string &msv)
// {
//     for (int i = 0; i < count; ++i)
//     {
//         if (creditClasses[i].hasStudent(msv))
//         {
//             return &creditClasses[i];
//         }
//     }
//     return nullptr;
// }

// // Lấy số lượng lớp tín chỉ
// int CreditClassList::getCount() const
// {
//     return count;
// }

// // Hiển thị danh sách sinh viên đã đăng ký lớp tín chỉ theo các tham số: niên khóa, học kỳ, nhóm, mã môn học
// bool CreditClassList::displayStudentsInClass(const std::string &nienKhoa, int hocKy, int nhom, const std::string &maMH) const
// {
//     bool found = false;
//     // Duyệt qua tất cả các lớp tín chỉ
//     for (int i = 0; i < count; ++i)
//     {
//         // Kiểm tra các tham số niên khóa, học kỳ, nhóm và mã môn học
//         if (creditClasses[i].getNienKhoa() == nienKhoa &&
//             creditClasses[i].getHocKy() == hocKy &&
//             creditClasses[i].getNhom() == nhom &&
//             creditClasses[i].getMAMH() == maMH)
//         {
//             found = true;
//             // Hiển thị danh sách sinh viên trong lớp tín chỉ
//             cout << "Danh sách sinh viên trong lớp tín chỉ " << creditClasses[i].getTenLop() << " ("
//                  << creditClasses[i].getMAMH() << ") - Nhóm: " << nhom << ", Niên khóa: "
//                  << nienKhoa << ", Học kỳ: " << hocKy << ":\n";
//             creditClasses[i].inDSSV(); // In danh sách sinh viên đã đăng ký trong lớp tín chỉ
//         }
//     }

//     // Nếu không tìm thấy lớp tín chỉ phù hợp
//     if (!found)
//     {
//         cout << "Không tìm thấy lớp tín chỉ nào với các tham số đã nhập!" << endl;
//     }

//     return found;
// }

void CreditClassList::addCreditClass(CreditClass *creditClass) // Thêm const
{
    if (count < 10000)
    {
        creditClasses[count] = creditClass;
        creditClasses[count]->setMaLopTC(count + 1); // Gán mã lớp tín chỉ tự động tăng
        cout << "Da them lop tin chi - MaLopTC: " << creditClasses[count]->getMALOPTC()
             << ", Ma MH: " << creditClasses[count]->getMAMH()
             << ", Nien khoa: " << creditClasses[count]->getNienKhoa()
             << ", Hoc ky: " << creditClasses[count]->getHocKy()
             << ", Nhom: " << creditClasses[count]->getNhom() << endl;
        count++;
    }
    else
    {
        cout << "Danh sach lop tin chi da day!" << endl;
    }
}

bool CreditClassList::removeCreditClass(int malopTC)
{
    for (int i = 0; i < count; i++)
    {
        if (creditClasses[i]->getMALOPTC() == malopTC)
        {
            // Dịch chuyển các lớp còn lại để giữ danh sách liên tục
            for (int j = i; j < count - 1; j++)
            {
                creditClasses[j] = creditClasses[j + 1];
            }
            count--;
            cout << "Đã xóa lớp tín chỉ có mã: " << malopTC << endl;
            return true;
        }
    }
    cout << "Không tìm thấy lớp tín chỉ với mã: " << malopTC << endl;
    return false;
}

bool CreditClassList::updateCreditClass(int malopTC, CreditClass *updatedClass)
{
    for (int i = 0; i < count; i++)
    {
        if (creditClasses[i]->getMALOPTC() == malopTC)
        {
            // Giữ nguyên danh sách sinh viên đăng ký cũ
            DangKyNode *oldDSSV = creditClasses[i]->getDSSVDK();

            // Cập nhật thông tin lớp tín chỉ
            creditClasses[i] = updatedClass;
            creditClasses[i]->setMaLopTC(malopTC);  // Đảm bảo mã lớp không thay đổi
            creditClasses[i]->capNhatDSSV(oldDSSV); // Giữ danh sách sinh viên cũ

            cout << "Cập nhật lớp tín chỉ thành công!" << endl;
            return true;
        }
    }
    cout << "Không tìm thấy lớp tín chỉ có mã: " << malopTC << endl;
    return false;
}

void CreditClassList::displayStudentsInClass(const std::string &nienKhoa, int hocKy, int nhom, const std::string &maMH, const ClassList &classList) const
{
    bool found = false;

    for (int i = 0; i < count; ++i)
    {
        if (creditClasses[i]->getNienKhoa() == nienKhoa &&
            creditClasses[i]->getHocKy() == hocKy &&
            creditClasses[i]->getNhom() == nhom &&
            creditClasses[i]->getMAMH() == maMH)
        {
            found = true;
            cout << "\nDanh sách sinh viên đăng ký lớp tín chỉ: " << creditClasses[i]->getMALOPTC() << endl;
            cout << "---------------------------------------------------------" << endl;
            cout << setw(10) << left << "MASV"
                 << setw(15) << left << "Họ"
                 << setw(10) << left << "Tên"
                 << setw(8) << left << "Giới tính"
                 << setw(12) << left << "Số ĐT"
                 << setw(8) << left << "Điểm"
                 << setw(12) << left << "Hủy ĐK" << endl;
            cout << "---------------------------------------------------------" << endl;

            // Duyệt danh sách sinh viên đăng ký
            DangKyNode *current = creditClasses[i]->getDSSVDK();
            int countSV = 0;
            while (current != nullptr)
            {
                // Tìm sinh viên theo mã
                SinhVien *sv = const_cast<ClassList &>(classList).findSinhVienById(current->MASV);
                if (sv != nullptr)
                {
                    cout << setw(10) << left << sv->getMASV()
                         << setw(15) << left << sv->getHO()
                         << setw(10) << left << sv->getTEN()
                         << setw(8) << left << sv->getGIOITINH()
                         << setw(12) << left << sv->getSODT()
                         << setw(8) << left << current->DIEM
                         << setw(12) << left << (current->huyDangKy ? "Có" : "Không") << endl;
                }
                else
                {
                    cout << setw(10) << left << current->MASV
                         << setw(15) << left << "Không tìm thấy"
                         << setw(10) << left << "Không tìm thấy"
                         << setw(8) << left << "N/A"
                         << setw(12) << left << "N/A"
                         << setw(8) << left << current->DIEM
                         << setw(12) << left << (current->huyDangKy ? "Có" : "Không") << endl;
                }

                current = current->next;
                countSV++;
            }

            cout << "---------------------------------------------------------" << endl;
            cout << "Tổng số sinh viên đăng ký: " << countSV << endl;
        }
    }

    if (!found)
    {
        cout << "Không tìm thấy lớp tín chỉ phù hợp!" << endl;
    }
}
