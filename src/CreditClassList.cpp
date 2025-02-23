#include "CreditClassList.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// Constructor
CreditClassList::CreditClassList() : count(0) {}

// Thêm lớp tín chỉ
void CreditClassList::addCreditClass(CreditClass *creditClass)
{
    if (count < 10000)
    {
        creditClasses[count++] = *creditClass;
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
void CreditClassList::displayCreditClasses()
{
    for (int i = 0; i < count; ++i)
    {
        cout << "Mã lớp: " << creditClasses[i].getMALOPTC() << " - Môn: " << creditClasses[i].getMAMH() << endl;
    }
}

// Hủy lớp tín chỉ không đủ sinh viên
void CreditClassList::cancelCreditClasses()
{
    int soLopHuy = 0;
    for (int i = 0; i < count; ++i)
    {
        if (creditClasses[i].getSoLuongSinhVien() < creditClasses[i].getSoSvMin()) // Sử dụng hàm mới
        {
            std::string luaChon;
            do
            {
                std::cout << "Đồng ý hủy lớp " << creditClasses[i].getMALOPTC() << "? (Y/N)" << std::endl;
                std::cin >> luaChon;
                if (luaChon == "Y")
                {
                    soLopHuy++;
                    creditClasses[i].setHuyLop(true);
                    std::cout << "Lớp " << creditClasses[i].getMALOPTC() << " đã bị hủy." << std::endl;
                }
            } while (luaChon != "Y" && luaChon != "N");
        }
    }
    if (soLopHuy == 0)
    {
        std::cout << "Không có lớp nào bị hủy." << std::endl;
    }
}

// Tìm lớp theo tham số
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
    bool daDangKy = false;
    for (int i = 0; i < count; ++i)
    {
        if (maMH == creditClasses[i].getMAMH())
        {
            creditClasses[i].addStudent(sinhVien);
            daDangKy = true;
        }
    }
    return daDangKy;
}

// Lưu vào file
void CreditClassList::saveToFile(const string &filename)
{
    ofstream outFile(filename);
    if (!outFile)
    {
        return;
    }
    for (int i = 0; i < count; ++i)
    {
        outFile << creditClasses[i].getMALOPTC() << " "
                << creditClasses[i].getMAMH() << " "
                << creditClasses[i].getTenLop() << " "
                << creditClasses[i].getNienKhoa() << " "
                << creditClasses[i].getHocKy() << " "
                << creditClasses[i].getNhom() << " "
                << creditClasses[i].getSoSvMin() << " "
                << creditClasses[i].getSoSvMax() << " "
                << creditClasses[i].isHuyLop() << endl;
    }
    outFile.close();
}

// Đọc từ file
void CreditClassList::readFromFile(const string &filename)
{
    ifstream inFile(filename);
    if (!inFile)
    {
        cerr << "Không thể mở file!" << endl;
        return;
    }
    count = 0;
    while (!inFile.eof())
    {
        int malopTC, hocKy, nhom, soSvMin, soSvMax;
        string maMH, tenLop, nienKhoa;
        bool huyLop;
        inFile >> malopTC >> maMH >> tenLop >> nienKhoa >> hocKy >> nhom >> soSvMin >> soSvMax >> huyLop;
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
        SinhVienNode *current = creditClasses[i].getDSSVDK();
        while (current)
        {
            if (current->student.getMASV() == msv)
            {
                return &creditClasses[i];
            }
            current = current->next;
        }
    }
    return nullptr;
}
