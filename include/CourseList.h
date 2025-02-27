#ifndef COURSELIST_H
#define COURSELIST_H

#include "Course.h"

struct CourseNode //  là một cấu trúc (struct) dùng để đại diện cho một nút trong cây nhị phân tìm kiếm
{
    MonHoc data;       // Dữ liệu của môn học
    CourseNode *left;  // Con trỏ trái - Các giá trị nhỏ hơn sẽ ở bên trái của nút cha.
    CourseNode *right; // Con trỏ phải - Các giá trị lớn hơn hoặc bằng sẽ ở bên phải của nút cha.
};

class CourseList
{
private:
    // biến con trỏ là để lưu trữ địa chỉ bộ nhớ của một đối tượng hoặc biến
    // con trỏ là một biến lưu trữ địa chỉ bộ nhớ của đối tượng hoặc biến. Vì vậy, có thể sử dụng con trỏ để truyền đạt hoặc thay đổi giá trị của đối tượng mà nó trỏ đến. Điều này có nghĩa là bạn có thể thay đổi giá trị của đối tượng thông qua con trỏ.
    CourseNode *root; // Cây nhị phân tìm kiếm

public:
    CourseList();
    void printInOrder(CourseNode *node);   // In danh sách môn học theo thứ tự
    CourseNode *getRoot();                 // Lấy gốc cây
    void saveToFile(const std::string &filename);
    void readFromFile(const std::string &filename);
    int getTotalCredit(const string &maMH);

    void insert(MonHoc course);                                         // Thêm môn học
    bool removeCourse(string maMH);                                     // Xóa môn học
    void updateCourse(const string &mamh, const MonHoc &updatedCourse); // Cập nhật môn học
    void printCoursesSortedByName();                                    // In danh sách môn học theo tên
    bool isCourseExisted(const string &maMH);   
    void inOrderTraversal(CourseNode *root);                        // Kiểm tra môn học đã tồn tại chưa
};

#endif
