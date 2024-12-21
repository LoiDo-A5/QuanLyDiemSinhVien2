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

// Hàm kiểm tra số thực không âm
bool isValidFloat(float &num)
{
    while (cin.fail() || num < 0.0f) // Kiểm tra lỗi nhập và số âm
    {
        cin.clear();                                         // Xóa trạng thái lỗi
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Loại bỏ ký tự dư thừa trong buffer
        cout << "Giá trị không hợp lệ. Vui lòng nhập lại một số thực không âm: ";
        cin >> num;
    }
    return true;
}

// Hàm kiểm tra chuỗi CMND có hợp lệ không
bool isValidCMND(std::string &str)
{
    while (true)
    {
        // Kiểm tra nếu độ dài không phải 9 hoặc 12 ký tự
        if (str.length() == 9 || str.length() == 12)
        {
            bool isValid = true;

            // Kiểm tra tất cả các ký tự phải là chữ số
            for (char c : str)
            {
                if (!isdigit(c))
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

        // Nếu chuỗi không hợp lệ, yêu cầu người dùng nhập lại
        std::cout << "CMND không hợp lệ. Vui lòng nhập lại (CMND phải có 9 hoặc 12 chữ số): ";
        std::cin >> str;
    }
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
        std::cout << "Mã không hợp lệ. Vui lòng nhập lại (ví dụ: cs101): ";
        std::cin.clear();                                         // Xóa trạng thái lỗi
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Loại bỏ ký tự thừa trong bộ đệm
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

        // Kiểm tra nếu chuỗi không rỗng và không dài hơn 30 ký tự
        if (!str.empty() && str.length() <= 30)
        {
            return true; // Nếu hợp lệ, trả về true
        }
        else
        {
            if (str.empty())
            {
                // Nếu chuỗi rỗng
                cout << "Chuỗi không thể rỗng, vui lòng nhập lại: ";
            }
            else if (str.length() > 30)
            {
                // Nếu chuỗi quá dài
                cout << "Chuỗi không được dài hơn 30 ký tự, vui lòng nhập lại: ";
            }
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
