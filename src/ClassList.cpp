#include "ClassList.h"
#include <iostream>
#include <fstream> // Để sử dụng ofstream
#include <sstream>
using namespace std;
#include <vector>    // Bổ sung thư viện vector
#include <algorithm> // Cần cho std::sort

ClassList::ClassList() : classCount(0) {}

int ClassList::getClassCount()
{
    return classCount;
}

bool ClassList::addClass(const Lop &newClass)
{
    if (classCount < 1000)
    {
        // Thêm lớp vào danh sách
        classes[classCount++] = newClass; // Không cần new vì đối tượng đã có sẵn trong tham số
        return true;
    }
    return false;
}

void ClassList::printClasses()
{
    if (classCount == 0)
    {
        cout << "Không có lớp học nào!" << endl;
    }
    else
    {
        for (int i = 0; i < classCount; i++)
        {
            classes[i].printClassInfo(); // Không cần dùng con trỏ vì lớp đã được tạo sẵn
        }
    }
}

void ClassList::updateClass(const string &malop, Lop updatedClass)
{
    for (int i = 0; i < classCount; i++)
    {
        if (classes[i].getClassID() == malop)
        {
            // Giữ lại sinh viên của lớp cũ bằng cách duyệt qua danh sách sinh viên
            SinhVienNode *current = classes[i].getStudents(); // Lấy danh sách sinh viên của lớp hiện tại
            updatedClass.setStudents(current);
            // Cập nhật lớp mới vào danh sách lớp
            classes[i] = updatedClass;
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
        if (classes[i].getClassID() == malop)
        {
            classes[i].addStudent(newStudent); // Thêm sinh viên vào lớp
            cout << "Thêm sinh viên " << newStudent.getMASV() << " vào lớp " << malop << " thành công!" << endl;
            return;
        }
    }
    cout << "Không tìm thấy lớp " << malop << "." << endl;
}

Lop *ClassList::findClassByCode(const string &malop)
{
    for (int i = 0; i < classCount; i++)
    {
        if (classes[i].getClassID() == malop)
        {
            return &classes[i]; // Trả về con trỏ đến lớp tìm được
        }
    }
    return nullptr; // Không tìm thấy lớp
}

bool ClassList::removeStudent(const string &malop, const string &maSV)
{
    Lop *lop = findClassByCode(malop); // Tìm lớp

    if (lop == nullptr)
    {
        cout << "Lớp không tồn tại!" << endl;
        return false;
    }

    bool removed = lop->removeStudent(maSV); // Xóa sinh viên trong lớp

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

bool ClassList::removeClassByCode(const string &malop)
{
    for (int i = 0; i < classCount; ++i)
    {
        if (classes[i].getClassID() == malop)
        {
            // Xóa lớp bằng mã lớp
            for (int j = i; j < classCount - 1; ++j)
            {
                classes[j] = classes[j + 1]; // Dịch chuyển lớp còn lại
            }
            --classCount; // Giảm số lượng lớp
            return true;  // Thành công
        }
    }
    return false; // Không tìm thấy lớp
}

SinhVien *ClassList::findSinhVienById(const string &maSV)
{
    for (int i = 0; i < classCount; ++i)
    {
        SinhVien *found = classes[i].findStudent(maSV); // Tìm sinh viên trong lớp
        if (found != nullptr)
        {
            return found;
        }
    }
    return nullptr; // Không tìm thấy sinh viên
}

void ClassList::saveToFile(const string &filename)
{
    ofstream outFile(filename); // Mở file để lưu dữ liệu

    if (!outFile)
    {
        cerr << "Không thể mở file để lưu!" << endl;
        return;
    }

    // Lưu danh sách lớp
    for (int i = 0; i < classCount; ++i)
    {
        outFile << classes[i].getClassID() << " " << classes[i].getClassName() << endl;

        // Lưu sinh viên trong lớp bằng cách duyệt qua danh sách liên kết
        const SinhVienNode *current = classes[i].getStudents(); // Sử dụng const vì danh sách là không thay đổi
        while (current != nullptr)
        {
            outFile << current->student.toString() << endl; // Gọi phương thức toString() của sinh viên
            current = current->next;                        // Di chuyển đến sinh viên tiếp theo
        }

        outFile << endl; // Đánh dấu kết thúc lớp
    }

    outFile.close(); // Đóng file
}

void ClassList::readFromFile(const string &filename)
{
    ifstream inFile(filename); // Mở file để đọc

    if (!inFile)
    {
        return;
    }

    classCount = 0;
    string line;

    while (getline(inFile, line))
    {
        istringstream classStream(line);
        string classID, className;
        classStream >> classID >> ws; // Đọc mã lớp và tên lớp
        getline(classStream, className);

        Lop classItem(classID, className);

        // Đọc sinh viên cho lớp
        while (getline(inFile, line) && !line.empty())
        {
            SinhVien student;
            student.fromString(line); // Giả sử phương thức fromString() để parse thông tin sinh viên
            classItem.addStudent(student);
        }

        addClass(classItem); // Thêm lớp vào danh sách
    }

    inFile.close(); // Đóng file
}

void ClassList::nhapSinhVienVaoLop()
{
    std::string malop;
    std::cout << "Nhập mã lớp: ";
    std::cin >> malop;
    std::cin.ignore(); // Loại bỏ ký tự xuống dòng tránh lỗi getline()

    Lop *lop = findClassByCode(malop);
    if (lop == nullptr)
    {
        std::cout << "Không tìm thấy lớp!" << std::endl;
        return;
    }

    while (true)
    {
        std::string masv;
        std::cout << "Nhập mã sinh viên (Nhập rỗng để dừng): ";
        std::getline(std::cin, masv); // Dùng getline để tránh lỗi nhập liệu
        if (masv.empty())
            break; // Thoát vòng lặp nếu nhập rỗng

        // Kiểm tra nếu sinh viên đã tồn tại trong lớp
        SinhVien *existingStudent = lop->findStudent(masv);
        if (existingStudent)
        {
            std::cout << "Sinh viên đã tồn tại! Bạn có muốn chỉnh sửa? (y/n): ";
            char choice;
            std::cin >> choice;
            std::cin.ignore(); // Loại bỏ newline để tránh lỗi nhập tiếp theo

            if (choice == 'y' || choice == 'Y')
            {
                // Cập nhật thông tin sinh viên mà không yêu cầu nhập lại mã sinh viên
                existingStudent->nhapThongTin();
                std::cout << "Cập nhật thông tin sinh viên thành công!\n";
            }
        }
        else
        {
            SinhVien newStudent;
            newStudent.setMASV(masv);  // Đảm bảo mã sinh viên chỉ nhập một lần
            newStudent.nhapThongTin(); // Chỉ yêu cầu nhập thông tin còn lại
            lop->addStudent(newStudent);
            std::cout << "Thêm sinh viên thành công!\n";
        }
    }
}

void ClassList::inDanhSachSVTheoAlphabet(const std::string &malop)
{
    Lop *lop = findClassByCode(malop);
    if (lop == nullptr)
    {
        std::cout << "Không tìm thấy lớp!" << std::endl;
        return;
    }

    std::vector<SinhVien> dsSV;
    SinhVienNode *current = lop->getStudents();
    while (current != nullptr)
    {
        dsSV.push_back(current->student);
        current = current->next;
    }

    std::sort(dsSV.begin(), dsSV.end(), [](const SinhVien &a, const SinhVien &b)
              { return a.getTEN() + a.getHO() < b.getTEN() + b.getHO(); });

    std::cout << "Danh sách sinh viên theo thứ tự alphabet:\n";
    for (const auto &sv : dsSV)
    {
        sv.inThongTin();
    }
}