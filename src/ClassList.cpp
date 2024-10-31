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
