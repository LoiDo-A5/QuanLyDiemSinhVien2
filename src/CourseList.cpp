#include "CourseList.h"
#include <iostream>
#include "IsValid.h"
#include <fstream> // Để sử dụng ofstream
#include <sstream>

CourseList::CourseList() : root(nullptr) {}

void CourseList::insert(MonHoc course)
{
    // Tạo nút mới để chứa dữ liệu của môn học
    CourseNode *newNode = new CourseNode{course, nullptr, nullptr};
    // Nếu cây trống (root == nullptr), gán gốc của cây là newNode
    // chưa có phần tử nào trong cây), sẽ gán root bằng newNode.
    if (root == nullptr)
    {
        root = newNode;
    }
    else
    {
        CourseNode *current = root;
        CourseNode *parent = nullptr;

        while (true)
        {
            parent = current;

            // So sánh theo mã môn hoc
            if (course.MAMH < current->data.MAMH)
            {
                current = current->left; // nếu mã môn học nhỏ hơn mã trong nút hiện tại, di chuyển sang trái
                if (current == nullptr)
                {
                    parent->left = newNode; // parent là nút cha của current. Nếu current là nullptr, ta biết rằng parent chính là nút có thể chứa con trái trống.
                    return;
                }
            }
            else
            {
                current = current->right; // mã tên môn học lớn hơn hoặc bằng mã trong nút hiện tại, di chuyển sang phải
                if (current == nullptr)
                {
                    parent->right = newNode; // chèn vào bên phải
                    return;
                }
            }
        }
    }
}

void CourseList::printInOrder(CourseNode *node)
{
    if (node != nullptr)
    {
        printInOrder(node->left);
        std::cout << "Mã môn học: " << node->data.MAMH << ", Tên môn học: " << node->data.TENMH
                  << ", Số tín chỉ thực hành: " << node->data.STCLT << ", Số tín chỉ lý thuyết: " << node->data.STCTH << std::endl;
        printInOrder(node->right);
    }
}

CourseNode *CourseList::getRoot()
{
    return root;
}

void CourseList::updateCourse(const string &mamh)
{
    CourseNode *current = root;

    while (current != nullptr)
    {
        if (current->data.MAMH == mamh)
        {
            cout << "Nhập thông tin môn học mới:" << endl;
            MonHoc updatedCourse;

            cout << "Nhập mã môn học: ";
            cin >> updatedCourse.MAMH;
            isValidCode(updatedCourse.MAMH, 3);

            cout << "Nhập tên môn học: ";
            cin.ignore();
            isValidString(updatedCourse.TENMH);

            cout << "Nhập số tín chỉ lý thuyết: ";
            isValidNumber(updatedCourse.STCLT);

            cout << "Nhập số tín chỉ thực hành: ";
            isValidNumber(updatedCourse.STCTH);

            current->data = updatedCourse; // Cập nhật thông tin môn học
            std::cout << "Cập nhật môn học " << mamh << " thành công!" << std::endl;
            return;
        }
        else if (mamh < current->data.MAMH)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    std::cout << "Không tìm thấy môn học " << mamh << "." << std::endl;
}

bool CourseList::isCourseExisted(const string &maMH)
{
    CourseNode *currentNode = root;
    while (currentNode != nullptr)
    {
        if (root->data.MAMH == maMH)
        {
            return true; // Tìm thấy môn học
        }
        if (maMH < root->data.MAMH)
        {
            currentNode = root->left;
        }
        else
        {
            currentNode = root->right;
        }
    }
    return false;
}

void CourseList::saveToFile(const std::string &filename)
{
    std::ofstream outFile(filename); // Mở file để ghi dữ liệu

    if (!outFile)
    {
        return;
    }

    // Hàm đệ quy để ghi dữ liệu cây vào file
    std::function<void(CourseNode *)> saveNode = [&](CourseNode *node)
    {
        if (node == nullptr)
            return;

        // Ghi thông tin môn học theo một định dạng
        outFile << node->data.MAMH << " "
                << node->data.TENMH << " "
                << node->data.STCLT << " "
                << node->data.STCTH << std::endl;

        // Ghi thông tin các nút con
        saveNode(node->left);
        saveNode(node->right);
    };

    // Ghi toàn bộ cây bắt đầu từ nút gốc
    saveNode(root);

    outFile.close();
}

void CourseList::readFromFile(const std::string &filename)
{
    std::ifstream inFile(filename); // Mở file để đọc dữ liệu

    if (!inFile)
    {
        return;
    }

    root = nullptr; // Xóa cây hiện tại (nếu có)

    std::string line;
    while (std::getline(inFile, line))
    {
        std::istringstream stream(line);
        std::string maMH, tenMH, STCLT, STCTH;

        // Phân tích dữ liệu từ dòng
        std::getline(stream, maMH, ' ');
        std::getline(stream, tenMH, ' ');
        std::getline(stream, STCLT, ' ');
        std::getline(stream, STCTH);

        // Tạo một đối tượng MonHoc mới
        MonHoc course(maMH, tenMH, std::stoi(STCLT), std::stoi(STCTH));

        // Thêm môn học vào cây
        insert(course);
    }

    inFile.close();
}