#include "ClassList.h"
#include "Node.h"
#include <iostream>
using namespace std;

ClassList::ClassList() : classCount(0) {}

void ClassList::addClass(const Lop &newClass)
{
    if (classCount < 1000)
    {
        classes[classCount++] = new Lop(newClass); // Giả sử Lop có constructor
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
        classes[i]->printClassInfo(); // In thông tin lớp
    }
}

void ClassList::updateClass(const string &malop, const Lop &updatedClass)
{
    for (int i = 0; i < classCount; i++)
    {
        if (classes[i]->getClassID() == malop)
        {                               // Sử dụng getter
            *classes[i] = updatedClass; // Cập nhật thông tin lớp
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
        {                                       // Sử dụng getter
            classes[i]->addStudent(newStudent); // Thêm sinh viên thông qua phương thức
            cout << "Thêm sinh viên " << newStudent.getMaSV() << " vào lớp " << malop << " thành công!" << endl;
            return;
        }
    }
    cout << "Không tìm thấy lớp " << malop << "." << endl;
}
