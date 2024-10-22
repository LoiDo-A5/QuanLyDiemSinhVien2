#ifndef COURSELIST_H
#define COURSELIST_H

#include "Course.h"

struct CourseNode {
    MonHoc data;               // Dữ liệu của môn học
    CourseNode* left;          // Con trỏ trái
    CourseNode* right;         // Con trỏ phải
};

class CourseList {
private:
    CourseNode* root;          // Cây nhị phân tìm kiếm
    
public:
    CourseList();
    void insert(MonHoc course); // Thêm môn học
    void printInOrder(CourseNode* node); // In danh sách môn học theo thứ tự
    CourseNode* getRoot();      // Lấy gốc cây
    void updateCourse(const string& mamh, const MonHoc& updatedCourse); // Cập nhật thông tin môn học
};

#endif
