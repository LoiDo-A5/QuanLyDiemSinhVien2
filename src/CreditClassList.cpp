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
        cout << "Mã lớp: " << creditClasses[i].getMALOPTC() << " - Môn: " << creditClasses[i].getMAMH() << endl;
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
        if (creditClasses[i].getNienKhoa() == nienKhoa && creditClasses[i].getHocKy() == hocKy &&
            creditClasses[i].getNhom() == nhom && creditClasses[i].getMAMH() == maMH)
        {
            return &creditClasses[i];
        }
    }
    return nullptr;
}

// Đăng ký sinh viên vào lớp tín chỉ
bool CreditClassList::registerStudent(const string &maMH, const SinhVien &sinhVien)
{
    for (int i = 0; i < count; ++i)
    {
        if (creditClasses[i].getMAMH() == maMH)
        {
            creditClasses[i].addStudent(sinhVien);
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
        int malopTC, hocKy, nhom, soSvMin, soSvMax;
        string maMH, tenLop, nienKhoa;
        bool huyLop;

        // Đọc dữ liệu từ file
        inFile >> malopTC >> maMH >> tenLop >> nienKhoa >> hocKy >> nhom >> soSvMin >> soSvMax >> huyLop;

        // Kiểm tra nếu có dữ liệu hợp lệ
        if (inFile)
        {
            creditClasses[count++] = CreditClass(malopTC, maMH, tenLop, nienKhoa, hocKy, nhom, soSvMin, soSvMax);
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
            cout << "Danh sach sinh vien trong lop " << creditClasses[i].getTenLop() << ":\n";
            creditClasses[i].inDSSV();
        }
    }
    if (!found)
    {
        cout << "Khong tim thay lop tin chi nao voi cac tham so da nhap!\n";
    }

    return found; // Thêm câu lệnh return để đảm bảo hàm có giá trị trả về
}
