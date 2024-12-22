#ifndef ISVALID_H
#define ISVALID_H

#include <iostream>
#include <string>
#include <limits>

// Các hàm kiểm tra hợp lệ
bool isValidNumber(int &num);                        // Kiểm tra số nguyên hợp lệ
bool isValidFloat(float &num);                       // Kiểm tra số hợp lệ
bool isValidString(std::string &str);                // Kiểm tra chuỗi hợp lệ (không rỗng)
bool isValidCode(std::string &code, int length = 5); // Kiểm tra mã hợp lệ (mặc định chiều dài là 5)
bool isValidYear(std::string &year);                 // Kiểm tra năm hợp lệ (ví dụ năm hiện tại)
bool isValidCMND(std::string &str);

#endif // ISVALID_H
