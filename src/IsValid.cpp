#include <iostream>
#include "IsValid.h"

using namespace std;

// Hàm kiểm tra số hợp lệ
bool isValidNumber(int &num)
{
    cin >> num;
    while (cin.fail() || num < 0)
    {
        cin.clear();                                         // Xóa lỗi nhập
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Loại bỏ ký tự dư thừa trong buffer
        cout << "Giá trị không hợp lệ. Vui lòng nhập lại một số nguyên không âm: ";
        cin >> num;
    }
    return true;
}

bool isValidCode(std::string &code, int length)
{
    while (true)
    {
        // Đảm bảo chuỗi có chiều dài hợp lệ và bắt đầu bằng chữ cái
        if (code.length() >= length && isalpha(code[0]))
        {
            bool isValid = true;

            // Kiểm tra tất cả các ký tự trong chuỗi
            for (char c : code)
            {
                // Kiểm tra nếu ký tự không phải là chữ cái hoặc chữ số
                if (!isalnum(c))
                {
                    isValid = false;
                    break;
                }
            }

            // Nếu tất cả ký tự hợp lệ, trả về true
            if (isValid)
            {
                return true;
            }
        }

        // Nếu mã không hợp lệ, yêu cầu người dùng nhập lại
        std::cout << "Mã môn học không hợp lệ. Vui lòng nhập lại (ví dụ: cs101): ";
        std::cin >> code;
    }
}

// Hàm kiểm tra chuỗi không rỗng
bool isValidString(string &str)
{
    while (true)
    {
        // Đọc dòng nhập từ người dùng
        getline(cin, str);

        // Kiểm tra nếu chuỗi không rỗng
        if (!str.empty())
        {
            return true; // Nếu hợp lệ, trả về true
        }
        else
        {
            // Nếu chuỗi rỗng, yêu cầu người dùng nhập lại
            cout << "Chuỗi không thể rỗng, vui lòng nhập lại: ";
        }
    }
}

// Hàm kiểm tra định dạng niên khóa
bool isValidYear(string &year)
{
    while (true)
    {
        getline(cin, year);
        if (year.length() != 9 || year[4] != '-')
        {
            cout << "Định dạng niên khóa không hợp lệ, vui lòng nhập lại (YYYY-YYYY): ";
        }
        else
        {
            return true;
        }
    }
}
