#include "CourseList.h"
#include <iostream>

CourseList::CourseList() : root(nullptr) {}

void CourseList::insert(MonHoc course)
{
    CourseNode *newNode = new CourseNode{course, nullptr, nullptr};
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
            if (course.MAMH < current->data.MAMH)
            {
                current = current->left;
                if (current == nullptr)
                {
                    parent->left = newNode;
                    return;
                }
            }
            else
            {
                current = current->right;
                if (current == nullptr)
                {
                    parent->right = newNode;
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
        std::cout << "Mã môn học: " << node->data.MAMH << ", Tên môn học: " << node->data.TENMH << ", Số tín chỉ thực hành: " << node->data.STCLT << ", Số tín chỉ lí thuyết: " << node->data.STCTH << std::endl;
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
            cout << "Nhập tên môn học: ";
            cin.ignore();
            getline(cin, updatedCourse.TENMH);
            cout << "Nhập số tín chỉ lý thuyết: ";
            cin >> updatedCourse.STCLT;
            cout << "Nhập số tín chỉ thực hành: ";
            cin >> updatedCourse.STCTH;
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
