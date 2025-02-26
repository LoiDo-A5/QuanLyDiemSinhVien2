#include "CreditClassList.h"
#include <iostream>
#include <fstream>

using namespace std;

// Constructor
CreditClassList::CreditClassList() : count(0) {}

// Thêm lớp tín chỉ
void CreditClassList::addCreditClass(CreditClass &creditClass)
{
    if (count < 10000)
    {
        creditClass.setMaLopTC(++count);
        creditClasses[count - 1] = creditClass;
        cout << "DEBUG: Da them lop tin chi - Ma MH: " << creditClass.getMAMH()
             << ", Nien khoa: " << creditClass.getNienKhoa()
             << ", Hoc ky: " << creditClass.getHocKy()
             << ", Nhom: " << creditClass.getNhom() << endl;
    }
    else
    {
        cout << "Danh sach lop tin chi da day!" << endl;
    }
}

// Tìm lớp tín chỉ theo mã lớp tín chỉ
CreditClass *CreditClassList::findCreditClassByMALOPTC(int malopTC)
{
    for (int i = 0; i < count; ++i)
    {
        if (creditClasses[i].getMALOPTC() == malopTC)
        {
            return &creditClasses[i];
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

void CreditClassList::addCreditClass(const CreditClass &creditClass)
{
    if (count < 10000) // Kiểm tra số lượng lớp tín chỉ tối đa
    {
        creditClasses[count] = creditClass;
        creditClasses[count].setMaLopTC(count + 1); // Gán mã lớp tự động tăng
        count++;
        cout << "Thêm lớp tín chỉ thành công!" << endl;
    }
    else
    {
        cout << "Danh sách lớp tín chỉ đã đầy!" << endl;
    }
}

bool CreditClassList::removeCreditClass(int malopTC)
{
    for (int i = 0; i < count; i++)
    {
        if (creditClasses[i].getMALOPTC() == malopTC)
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

bool CreditClassList::updateCreditClass(int malopTC, const CreditClass &updatedClass)
{
    for (int i = 0; i < count; i++)
    {
        if (creditClasses[i].getMALOPTC() == malopTC)
        {
            // Giữ nguyên danh sách sinh viên đăng ký cũ
            DangKyNode *oldDSSV = creditClasses[i].getDSSVDK();

            // Cập nhật thông tin lớp tín chỉ
            creditClasses[i] = updatedClass;
            creditClasses[i].setMaLopTC(malopTC);  // Đảm bảo mã lớp không thay đổi
            creditClasses[i].capNhatDSSV(oldDSSV); // Giữ danh sách sinh viên cũ

            cout << "Cập nhật lớp tín chỉ thành công!" << endl;
            return true;
        }
    }
    cout << "Không tìm thấy lớp tín chỉ có mã: " << malopTC << endl;
    return false;
}
