// CreditClassList.cpp

#include "CreditClassList.h"
#include "CreditClass.h"
#include <iostream>
#include <fstream> // Để sử dụng ofstream
#include <sstream>

CreditClassList::CreditClassList() {}

void CreditClassList::addCreditClass(CreditClass *creditClass)
{
    creditClasses.push_back(creditClass);
}

void CreditClassList::displayCreditClasses()
{
    if (creditClasses.empty())
    {
        std::cout << "Danh sách lớp tín chỉ rỗng." << std::endl;
        return;
    }
    for (const auto &creditClass : creditClasses)
    {
        std::cout << "Mã lớp tín chỉ: " << creditClass->getMALOPTC()
                  << ", Mã môn học: " << creditClass->getMAMH()
                  << ", Tên lớp: " << creditClass->getTenLop()
                  << ", Niên khóa: " << creditClass->getNienKhoa()
                  << ", Học kỳ: " << creditClass->getHocKy()
                  << ", Nhóm: " << creditClass->getNhom()
                  << ", Số sinh viên tối thiểu: " << creditClass->getSoSvMin()
                  << ", Số sinh viên tối đa: " << creditClass->getSoSvMax()
                  << ", Trạng thái hủy lớp: " << (creditClass->isHuyLop() ? "Có" : "Không")
                  << std::endl;
    }
}

void CreditClassList::removeCreditClass(int malopTC)
{
    for (auto it = creditClasses.begin(); it != creditClasses.end(); ++it)
    {
        if ((*it)->getMALOPTC() == malopTC)
        {
            delete *it; // Free memory
            creditClasses.erase(it);
            std::cout << "Lớp tín chỉ với mã " << malopTC << " đã được xóa." << std::endl;
            return;
        }
    }
    std::cerr << "Không tìm thấy lớp tín chỉ với mã: " << malopTC << std::endl;
}

CreditClass *CreditClassList::findCreditClassByMALOPTC(int malopTC)
{
    for (const auto &creditClass : creditClasses)
    {
        if (creditClass->getMALOPTC() == malopTC)
        {
            return creditClass;
        }
    }
    return nullptr; // Return nullptr if not found
}

void CreditClassList::cancelCreditClasses()
{
    int soLopHuy = 0;
    for (auto &creditClass : creditClasses)
    {
        if (creditClass->getDSSVDK().size() < creditClass->getSoSvMin())
        {
            std::string luaChon;
            do
            {
                cout << "Đồng ý hủy lớp " << creditClass->getMALOPTC() << "?(Y/N)" << endl;
                cin >> luaChon;
                if (luaChon == "Y")
                {
                    soLopHuy++;
                    creditClass->setHuyLop(true); // Đặt trạng thái hủy
                    std::cout << "Lớp tín chỉ với mã " << creditClass->getMALOPTC() << " đã được hủy." << std::endl;
                }
            } while (luaChon != "Y" && luaChon != "N");
        }
    }
    if (soLopHuy == 0)
    {
        std::cout << "Không tìm được lớp không đủ điều kiện để hủy!" << std::endl;
    }
}

std::vector<CreditClass *> CreditClassList::findClassesByParams(const std::string &nienKhoa,
                                                                int hocKy)
{
    std::vector<CreditClass *> result;
    for (auto &creditClass : creditClasses)
    {
        if ((nienKhoa.empty() || creditClass->getNienKhoa() == nienKhoa) &&
            (hocKy == 0 || creditClass->getHocKy() == hocKy))
        {
            result.push_back(creditClass);
        }
    }
    return result;
}

bool CreditClassList::registerStudent(const std::string &maMH, const SinhVien &sinhVien)
{
    bool daDangKy = false;
    for (auto &creditClass : creditClasses)
    {
        if (maMH == creditClass->getMAMH())
        {
            creditClass->addStudent(sinhVien);
            daDangKy = true;
        }
    }
    return daDangKy;
}

void CreditClassList::saveToFile(const std::string &filename)
{
    std::ofstream outFile(filename); // Open file to save data

    if (!outFile)
    {
        return;
    }

    // Save credit classes
    for (const auto &creditClass : creditClasses)
    {
        if (creditClass == nullptr)
            continue;

        // Write class details
        outFile << creditClass->getMALOPTC() << " "
                << creditClass->getMAMH() << " "
                << creditClass->getTenLop() << " "
                << creditClass->getNienKhoa() << " "
                << creditClass->getHocKy() << " "
                << creditClass->getNhom() << " "
                << creditClass->getSoSvMin() << " "
                << creditClass->getSoSvMax() << " "
                << creditClass->isHuyLop() << std::endl;

        // Write student details
        const auto &students = creditClass->getDSSVDK();
        for (const auto &student : students)
        {
            outFile << student.toString() << std::endl; // Save student info
        }

        outFile << std::endl; // Mark the end of the class
    }

    outFile.close(); // Close file
}

void CreditClassList::readFromFile(const std::string &filename)
{
    std::ifstream inFile(filename); // Open file to read data

    if (!inFile)
    {
        return;
    }

    std::string line;
    while (std::getline(inFile, line))
    {
        if (line.empty())
            continue;

        std::istringstream classStream(line);

        // Read class details
        int MALOPTC, hocKy, nhom, soSvMin, soSvMax;
        std::string MAMH, tenLop, nienKhoa;
        bool huyLop;

        classStream >> MALOPTC >> MAMH >> tenLop >> nienKhoa >> hocKy >> nhom >> soSvMin >> soSvMax >> huyLop;

        // Create CreditClass instance
        auto *creditClass = new CreditClass(MALOPTC, MAMH, tenLop, nienKhoa, hocKy, nhom, soSvMin, soSvMax);

        // Read student details
        while (std::getline(inFile, line) && !line.empty())
        {
            SinhVien student;
            student.fromString(line);         // Parse student details
            creditClass->addStudent(student); // Add student to class
        }

        // Add class to the vector
        creditClasses.push_back(creditClass);
    }

    inFile.close(); // Close file
}