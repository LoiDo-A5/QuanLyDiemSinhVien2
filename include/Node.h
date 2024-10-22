#ifndef NODE_H
#define NODE_H

#include "Student.h"

struct Node {
    SinhVien data;   // Dữ liệu sinh viên
    Node* next;      // Con trỏ tới nút tiếp theo trong danh sách liên kết

    // Constructor
    Node(const SinhVien& sv) : data(sv), next(nullptr) {}
};

#endif
