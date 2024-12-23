// ClassList.cpp
#include "ClassList.h"
#include "Node.h"
#include <iostream>
#include <fstream> // Để sử dụng ofstream
#include <sstream>
using namespace std;

ClassList::ClassList() : classCount(0) {}

int ClassList::getClassCount()
{
    return classCount;
}

void ClassList::addClass(const Lop &newClass)
{
    if (classCount < 1000)
    {
        classes[classCount++] = new Lop(newClass);
    }
    else
    {
        cout << "Danh sách lớp đã đầy!" << endl;
    }
}

void ClassList::printClasses()
{
    for (int i = 0; i < classCount; i++)
    {
        classes[i]->printClassInfo();
    }
}

void ClassList::updateClass(const string &malop, Lop updatedClass)
{
    for (int i = 0; i < classCount; i++)
    {
        if (classes[i]->getClassID() == malop)
        {
            for (int j = 0; j < classes[i]->getStudents().size(); j++)
            {
                updatedClass.addStudent(classes[i]->getStudents()[j]);
            }
            *classes[i] = updatedClass;
            cout << "Cập nhật lớp " << malop << " thành công!" << endl;
            return;
        }
    }
    cout << "Không tìm thấy lớp " << malop << "." << endl;
}

void ClassList::addStudentToClass(const string &malop, const SinhVien &newStudent)
{
    for (int i = 0; i < classCount; i++)
    {
        if (classes[i]->getClassID() == malop)
        {
            classes[i]->addStudent(newStudent);
            cout << "Thêm sinh viên " << newStudent.getMaSV() << " vào lớp " << malop << " thành công!" << endl;
            return;
        }
    }
    cout << "Không tìm thấy lớp " << malop << "." << endl;
}

Lop *ClassList::findClassByCode(const string &malop)
{
    for (int i = 0; i < classCount; i++)
    {
        if (classes[i]->getClassID() == malop) // So sánh mã lớp
        {
            return classes[i]; // Trả về con trỏ đến lớp tìm được
        }
    }
    return nullptr; // Không tìm thấy lớp, trả về nullptr
}

bool ClassList::removeStudent(const string &malop, const string &maSV)
{
    // Tìm lớp theo mã lớp
    Lop *lop = findClassByCode(malop);

    if (lop == nullptr)
    {
        cout << "Lớp không tồn tại!" << endl;
        return false;
    }

    // Xóa sinh viên trong lớp
    bool removed = lop->removeStudent(maSV);

    if (removed)
    {
        cout << "Xóa sinh viên thành công!" << endl;
        return true;
    }
    else
    {
        cout << "Không tìm thấy sinh viên với mã: " << maSV << endl;
        return false;
    }
}

bool ClassList::removeClassByCode(const std::string &malop)
{
    for (int i = 0; i < classCount; ++i)
    {
        if (classes[i] && classes[i]->getCode() == malop)
        {
            delete classes[i]; // Giải phóng bộ nhớ cho đối tượng lớp
            for (int j = i; j < classCount - 1; ++j)
            {
                classes[j] = classes[j + 1]; // Chuyển các lớp còn lại
            }
            classes[classCount - 1] = nullptr; // Xóa con trỏ cuối cùng
            --classCount;                      // Giảm số lượng lớp
            return true;                       // Cho biết thành công
        }
    }
    return false; // Trả về false nếu không tìm thấy lớp
}

SinhVien *ClassList::findSinhVienById(const std::string &maSV)
{
    for (int i = 0; i < classCount; ++i)
    {
        SinhVien *found = classes[i]->findStudent(maSV);
        if (found != nullptr)
        {
            return found;
        }
    }
    return nullptr; // Return nullptr if not found in any class
}

void ClassList::saveToFile(const std::string &filename)
{
    std::ofstream outFile(filename); // Open file to save data

    if (!outFile)
    {
        std::cerr << "Không thể mở file để lưu!" << std::endl;
        return;
    }

    // Lưu danh sách lớp
    for (int i = 0; i < classCount; ++i)
    {
        const Lop &classItem = *classes[i];
        outFile << classItem.getClassID() << " " << classItem.getClassName() << std::endl;

        // Lưu thông tin sinh viên trong lớp (nếu có)
        const auto &students = classItem.getStudents();
        for (const auto &student : students)
        {
            // Sử dụng phương thức toString() để lưu tất cả thông tin sinh viên
            outFile << student.toString() << std::endl;
        }

        outFile << std::endl; // Đánh dấu kết thúc thông tin lớp
    }

    outFile.close();
}

void ClassList::readFromFile(const std::string &filename)
{
    std::ifstream inFile(filename); // Open file to read data

    if (!inFile)
        return;

    classCount = 0;

    std::string line;
    while (std::getline(inFile, line))
    {
        // Read class ID and name
        std::istringstream classStream(line);
        std::string classID, className;
        classStream >> classID >> std::ws;
        std::getline(classStream, className);

        Lop *classItem = new Lop(classID, className);

        // Read students for this class
        while (std::getline(inFile, line) && !line.empty())
        {
            SinhVien student;
            student.fromString(line); // Assume `fromString` parses a student's details
            classItem->addStudent(student);
        }

        // Add the class to the list
        addClass(*classItem);
    }

    inFile.close();
}
