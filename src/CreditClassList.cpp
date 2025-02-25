#include "CreditClassList.h"
#include <iostream>
#include <fstream>

using namespace std;

// Constructor
CreditClassList::CreditClassList() : count(0) {}

// Thêm lớp tín chỉ
void CreditClassList::addCreditClass(const CreditClass &creditClass)
{
    if (count < 10000)
    {
        creditClasses[count++] = creditClass;
        cout << "DEBUG: Đã thêm lớp tín chỉ - Mã MH: " << creditClass.getMAMH()
             << ", Niên khóa: " << creditClass.getNienKhoa()
             << ", Học kỳ: " << creditClass.getHocKy()
             << ", Nhóm: " << creditClass.getNhom() << endl;
    }
    else
    {
        cout << "Danh sách lớp tín chỉ đã đầy!" << endl;
    }
}

// Xóa lớp tín chỉ theo mã
void CreditClassList::removeCreditClass(int malopTC)
{
    for (int i = 0; i < count; ++i)
    {
        if (creditClasses[i].getMALOPTC() == malopTC)
        {
            for (int j = i; j < count - 1; ++j)
            {
                creditClasses[j] = creditClasses[j + 1];
            }
            --count;
            return;
        }
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

// Hiển thị danh sách lớp tín chỉ
void CreditClassList::displayCreditClasses() const
{
    for (int i = 0; i < count; ++i)
    {
        cout << "Mã lớp: " << creditClasses[i].getMALOPTC()
             << " - Môn: " << creditClasses[i].getMAMH() << endl;
    }
}

// Hủy lớp tín chỉ không đủ sinh viên
void CreditClassList::cancelCreditClasses()
{
    for (int i = 0; i < count; ++i)
    {
        if (creditClasses[i].getSoLuongSinhVien() < creditClasses[i].getSoSvMin())
        {
            creditClasses[i].setHuyLop(true);
            cout << "Lớp " << creditClasses[i].getMALOPTC() << " đã bị hủy." << endl;
        }
    }
}

// Tìm lớp theo niên khóa và học kỳ
CreditClass *CreditClassList::findClassesByParams(const string &nienKhoa, int hocKy)
{
    for (int i = 0; i < count; ++i)
    {
        if (creditClasses[i].getNienKhoa() == nienKhoa && creditClasses[i].getHocKy() == hocKy)
        {
            return &creditClasses[i];
        }
    }
    return nullptr;
}

// Tìm lớp theo nhiều tham số
CreditClass *CreditClassList::findClass(const string &nienKhoa, int hocKy, int nhom, const string &maMH)
{
    for (int i = 0; i < count; ++i)
    {
        if (creditClasses[i].getNienKhoa() == nienKhoa &&
            creditClasses[i].getHocKy() == hocKy &&
            creditClasses[i].getNhom() == nhom &&
            creditClasses[i].getMAMH() == maMH)
        {
            cout << "DEBUG: Tìm thấy lớp tín chỉ!" << endl;
            return &creditClasses[i];
        }
    }
    cout << "DEBUG: Không tìm thấy lớp tín chỉ nào!" << endl;
    return nullptr;
}

// Đăng ký sinh viên vào lớp tín chỉ
bool CreditClassList::registerStudent(const std::string &maLopTC, const SinhVien &sinhVien)
{
    for (int i = 0; i < count; i++)
    {
        if (creditClasses[i].getMALOPTC() == stoi(maLopTC))
        {
            // Tạo đối tượng DangKyNode từ SinhVien
            DangKyNode newDangKy(sinhVien.getMASV(), 0.0, false);
            creditClasses[i].addStudent(newDangKy);
            return true;
        }
    }
    return false;
}

// Lưu danh sách lớp tín chỉ vào file
void CreditClassList::saveToFile(const string &filename) const
{
    ofstream outFile(filename);
    if (!outFile)
    {
        cerr << "Không thể mở file để ghi!" << endl;
        return;
    }
    for (int i = 0; i < count; ++i)
    {
        outFile << creditClasses[i].getMALOPTC() << " "
                << creditClasses[i].getMAMH() << " "
                << creditClasses[i].getNienKhoa() << " "
                << creditClasses[i].getHocKy() << " "
                << creditClasses[i].getNhom() << " "
                << creditClasses[i].getSoSvMin() << " "
                << creditClasses[i].getSoSvMax() << " "
                << creditClasses[i].isHuyLop() << endl;
    }
    outFile.close();
}

// Đọc danh sách lớp tín chỉ từ file
void CreditClassList::readFromFile(const string &filename)
{
    ifstream inFile(filename);
    if (!inFile)
    {
        cerr << "Không thể mở file để đọc!" << endl;
        return;
    }
    count = 0;
    while (!inFile.eof())
    {
        string maMH, nienKhoa;
        int hocKy, nhom, soSvMin, soSvMax;
        bool huyLop;

        inFile >> maMH >> nienKhoa >> hocKy >> nhom >> soSvMin >> soSvMax >> huyLop;

        if (inFile)
        {
            creditClasses[count++] = CreditClass(maMH, nienKhoa, hocKy, nhom, soSvMin, soSvMax);
        }
    }
    inFile.close();
}

// Tìm lớp theo mã sinh viên
CreditClass *CreditClassList::findClassesByMsv(const string &msv)
{
    for (int i = 0; i < count; ++i)
    {
        if (creditClasses[i].hasStudent(msv))
        {
            return &creditClasses[i];
        }
    }
    return nullptr;
}

// Lấy số lượng lớp tín chỉ
int CreditClassList::getCount() const
{
    return count;
}

// Hiển thị danh sách sinh viên đã đăng ký lớp tín chỉ theo các tham số
bool CreditClassList::displayStudentsInClass(const std::string &nienKhoa, int hocKy, int nhom, const std::string &maMH) const
{
    bool found = false;
    for (int i = 0; i < count; ++i)
    {
        if (creditClasses[i].getNienKhoa() == nienKhoa &&
            creditClasses[i].getHocKy() == hocKy &&
            creditClasses[i].getNhom() == nhom &&
            creditClasses[i].getMAMH() == maMH)
        {
            found = true;
            cout << "Danh sách sinh viên trong lớp tín chỉ " << creditClasses[i].getMAMH()
                 << " - Nhóm: " << nhom << ", Niên khóa: " << nienKhoa << ", Học kỳ: " << hocKy << ":\n";
            creditClasses[i].inDSSV();
        }
    }
    if (!found)
    {
        cout << "Không tìm thấy lớp tín chỉ nào với các tham số đã nhập!" << endl;
    }
    return found;
}
