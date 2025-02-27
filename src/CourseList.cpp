#include "CourseList.h"
#include <iostream>
#include "IsValid.h"
#include <fstream> // Để sử dụng ofstream
#include <sstream>
#include <functional>

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

            // So sánh theo tên môn hoc
            if (course.TENMH < current->data.TENMH)
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

int CourseList::getTotalCredit(const string &maMH)
{
    CourseNode *currentNode = root;
    while (currentNode != nullptr)
    {
        if (root->data.MAMH == maMH)
        {
            return root->data.STCLT + root->data.STCTH;
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
    return -1;
}

bool CourseList::removeCourse(string maMH)
{
    CourseNode **current = &root, *parent = nullptr;
    while (*current && (*current)->data.MAMH != maMH)
    {
        parent = *current;
        if (maMH < (*current)->data.MAMH)
            current = &((*current)->left);
        else
            current = &((*current)->right);
    }

    if (!(*current))
        return false;

    CourseNode *toDelete = *current;
    if (!toDelete->left)
        *current = toDelete->right;
    else if (!toDelete->right)
        *current = toDelete->left;
    else
    {
        CourseNode **successor = &(toDelete->right);
        while ((*successor)->left)
            successor = &((*successor)->left);
        toDelete->data = (*successor)->data;
        CourseNode *temp = *successor;
        *successor = (*successor)->right;
        delete temp;
    }
    delete toDelete;
    return true;
}

void CourseList::updateCourse(const string &mamh, const MonHoc &updatedCourse)
{
    CourseNode *current = root;
    while (current)
    {
        if (mamh == current->data.MAMH)
        {
            current->data.TENMH = updatedCourse.TENMH;
            current->data.STCLT = updatedCourse.STCLT;
            current->data.STCTH = updatedCourse.STCTH;
            return;
        }
        else if (mamh < current->data.MAMH)
            current = current->left;
        else
            current = current->right;
    }
}

void CourseList::printCoursesSortedByName()
{
    inOrderTraversal(root);
}

// Hàm đệ quy để duyệt cây theo thứ tự in-order (trái -> gốc -> phải)
void CourseList::inOrderTraversal(CourseNode *root)
{
    if (root == nullptr)
        return;

    inOrderTraversal(root->left);     // Duyệt cây con bên trái
    cout << root->data.TENMH << endl; // In tên môn học
    inOrderTraversal(root->right);    // Duyệt cây con bên phải
}
