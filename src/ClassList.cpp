#include "ClassList.h"
#include "Node.h"
#include <iostream>
using namespace std;

ClassList::ClassList() : classCount(0) {}

void ClassList::addClass(const Lop &newClass)
{
    if (classCount < 1000)
    {
        classes[classCount++] = new Lop(newClass); // Assume Lop has a copy constructor
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
        classes[i]->printClassInfo(); // Print class information
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