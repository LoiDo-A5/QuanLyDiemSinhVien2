#include "CourseList.h"
#include <iostream>
using namespace std;

CourseList::CourseList() : root(nullptr) {}

void CourseList::insert(MonHoc course) {
    CourseNode* newNode = new CourseNode();
    newNode->data = course;
    newNode->left = nullptr;
    newNode->right = nullptr;

    if (root == nullptr) {
        root = newNode;
    } else {
        CourseNode* current = root;
        CourseNode* parent = nullptr;
        
        while (true) {
            parent = current;
            if (course.MAMH < current->data.MAMH) {
                current = current->left;
                if (current == nullptr) {
                    parent->left = newNode;
                    return;
                }
            } else {
                current = current->right;
                if (current == nullptr) {
                    parent->right = newNode;
                    return;
                }
            }
        }
    }
}

void CourseList::printInOrder(CourseNode* node) {
    if (node != nullptr) {
        printInOrder(node->left);
        // In thông tin môn học
        cout << "Mã môn học: " << node->data.MAMH << ", Tên môn học: " << node->data.TENMH << endl;
        printInOrder(node->right);
    }
}

CourseNode* CourseList::getRoot() {
    return root;
}

void CourseList::updateCourse(const string& mamh, const MonHoc& updatedCourse) {
    CourseNode* current = root;
    while (current != nullptr) {
        if (current->data.MAMH == mamh) {
            current->data = updatedCourse; // Cập nhật thông tin môn học
            cout << "Cập nhật môn học " << mamh << " thành công!" << endl;
            return;
        }
        if (mamh < current->data.MAMH) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    cout << "Không tìm thấy môn học với mã: " << mamh << endl;
}
