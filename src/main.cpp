#include <iostream>
#include "ClassList.h"
#include "CourseList.h"
#include "Student.h"
#include "CreditClass.h"
#include "Class.h"
#include "CreditClassList.h"
#include "IsValid.h"
#include <iomanip>
#include <ncurses.h> // Thư viện hỗ trợ di chuyển con trỏ trên console

using namespace std;

const std::string COURSES_FILE = "courses.txt";
const std::string CLASSES_FILE = "classes.txt";
const std::string CREDIT_CLASSES_FILE = "credit_classes.txt";

// In danh sách sinh viên với con trỏ
void hienThiDanhSach(vector<SinhVien> &ds, int pos)
{
    clear(); // Xóa màn hình

    // Hiển thị tiêu đề cột
    printw("%-5s %-10s %-10s %-10s %-6s\n", "STT", "MASV", "HO", "TEN", "DIEM");
    printw("------------------------------------------------\n");

    // Hiển thị danh sách sinh viên
    for (size_t i = 0; i < ds.size(); i++)
    {
        if (i == pos)
        {                      // Hiển thị dòng được chọn
            attron(A_REVERSE); // Đảo màu dòng hiện tại
        }

        // In thông tin sinh viên
        printw("%-5zu %-10s %-10s %-10s %-6.2f\n", i + 1, ds[i].getMaSV().c_str(), ds[i].getHo().c_str(),
               ds[i].getTen().c_str(), ds[i].getDiem());

        if (i == pos)
        {
            attroff(A_REVERSE); // Tắt đảo màu
        }
    }

    refresh(); // Cập nhật màn hình
}

// Hàm nhập điểm cho sinh viên khi chọn dòng
void nhapDiem(vector<SinhVien> &ds, int pos)
{
    echo(); // Hiện ký tự nhập
    float diemMoi;
    move(pos + 2, 40); // Di chuyển con trỏ đến cột "DIEM"
    // cin >> diemMoi;
    scanw("%f", &diemMoi);
    if (diemMoi >= 0 && diemMoi <= 10)
    {
        ds[pos].capNhatDiem(diemMoi);
    }
    else
    {
        printw("\nĐiểm không hợp lệ!");
    }
    noecho(); // Tắt hiện ký tự nhập
}

int main()
{
    ClassList classList;             // Danh sách lớp
    CourseList courseList;           // Danh sách môn học
    CreditClassList creditClassList; // Tạo một thể hiện của CreditClassList
    classList.readFromFile(CLASSES_FILE);
    courseList.readFromFile(COURSES_FILE);
    creditClassList.readFromFile(CREDIT_CLASSES_FILE);
    int choice;
    do
    {
        cout << "==== MENU ====" << endl;
        cout << "1. Menu lớp" << endl;
        cout << "2. Thêm môn học" << endl;
        cout << "3. In danh sách môn học" << endl;
        cout << "4. Cập nhật thông tin môn học" << endl;
        cout << "5. Menu lớp tín chỉ" << endl;
        cout << "0. Thoát" << endl;
        cout << "Chọn chức năng: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int subChoice;
            do
            {
                cout << "==== MENU LỚP ====" << endl;
                cout << "1. Thêm lớp" << endl;
                cout << "2. Xóa lớp" << endl;
                cout << "3. Chỉnh sửa lớp" << endl;
                cout << "4. In danh sách lớp" << endl;
                cout << "5. Thêm sinh viên" << endl;
                cout << "6. Xóa sinh viên" << endl;
                cout << "7. Chỉnh sửa sinh viên" << endl;
                cout << "0. Quay lại" << endl;
                cout << "Chọn chức năng: ";
                cin >> subChoice;
                switch (subChoice)
                {
                case 1:
                {
                    string malop, tenlop;
                    cout << "Nhập mã lớp: ";
                    cin >> malop;
                    isValidCode(malop);

                    cin.ignore();
                    cout << "Nhập tên lớp: ";
                    isValidString(tenlop);
                    Lop newClass(malop, tenlop);
                    classList.addClass(newClass);
                    classList.saveToFile(CLASSES_FILE);
                    break;
                }
                case 2: // Xóa lớp
                {
                    if (classList.getClassCount() == 0)
                    {
                        cout << "Không có lớp để xóa!" << endl;
                        break;
                    }
                    string malop;
                    classList.printClasses();
                    cout << "Nhập mã lớp cần xoá: ";
                    cin >> malop;
                    isValidCode(malop);
                    if (classList.removeClassByCode(malop))
                    {
                        cout << "Đã xóa thành công lớp có mã lớp là " << malop << endl;
                        classList.saveToFile(CLASSES_FILE); // Lưu sau khi xóa lớp
                    }
                    break;
                }
                case 3: // Chỉnh sửa lớp
                {
                    string malop;
                    Lop updatedClass;
                    cout << "Nhập mã lớp cần cập nhật: ";
                    cin >> malop;
                    isValidCode(malop);
                    cout << "Nhập thông tin lớp mới:" << endl;
                    updatedClass.nhapThongTin();
                    classList.updateClass(malop, updatedClass);

                    classList.saveToFile(CLASSES_FILE); // Lưu sau khi chỉnh sửa lớp
                    break;
                }

                case 4: // In danh sách lớp
                {
                    classList.printClasses();
                    break;
                }
                case 5: // Thêm sinh viên
                {
                    string malop;
                    cout << "Nhập mã lớp: ";
                    cin >> malop;
                    isValidCode(malop);

                    SinhVien newStudent;
                    cout << "Nhập thông tin sinh viên:" << endl;
                    newStudent.nhapThongTin();
                    classList.addStudentToClass(malop, newStudent);

                    classList.saveToFile(CLASSES_FILE); // Lưu sau khi thêm sinh viên
                    break;
                }
                case 6: // Xóa sinh viên
                {
                    string malop;
                    cout << "Nhập mã lớp: ";
                    cin >> malop;
                    isValidCode(malop);

                    string maSV;
                    cout << "Nhập mã sinh viên cần xóa: ";
                    cin >> maSV;
                    isValidCode(maSV);

                    // Tìm lớp theo mã lớp
                    Lop *lop = classList.findClassByCode(malop);

                    if (lop == nullptr)
                    {
                        cout << "Lớp không tồn tại!" << endl;
                        break;
                    }

                    // Tìm sinh viên trong lớp
                    bool removed = lop->removeStudent(maSV);

                    if (removed)
                    {
                        cout << "Xóa sinh viên thành công!" << endl;
                        classList.saveToFile(CLASSES_FILE); // Lưu sau khi xóa sinh viên
                    }
                    else
                    {
                        cout << "Không tìm thấy sinh viên với mã: " << maSV << endl;
                    }
                    break;
                }
                case 7: // Chỉnh sửa sinh viên
                {
                    string malop;
                    cout << "Nhập mã lớp: ";
                    cin >> malop;
                    isValidCode(malop);

                    string maSV;
                    cout << "Nhập mã sinh viên cần chỉnh sửa: ";
                    cin >> maSV;
                    isValidCode(maSV);

                    // Tìm lớp theo mã lớp
                    Lop *lop = classList.findClassByCode(malop);

                    if (lop == nullptr)
                    {
                        cout << "Lớp không tồn tại!" << endl;
                        break;
                    }

                    // Tìm sinh viên trong lớp
                    SinhVien *student = lop->findStudent(maSV);

                    if (student == nullptr)
                    {
                        cout << "Không tìm thấy sinh viên với mã: " << maSV << endl;
                        break;
                    }

                    // Chỉnh sửa thông tin sinh viên
                    cout << "Nhập thông tin sinh viên mới:" << endl;
                    student->nhapThongTin(); // Nhập lại thông tin sinh viên

                    cout << "Chỉnh sửa sinh viên thành công!" << endl;
                    classList.saveToFile(CLASSES_FILE); // Lưu sau khi chỉnh sửa sinh viên
                    break;
                }

                default:
                    break;
                }
            } while (subChoice != 0); // Kết thúc vòng lặp con cho lớp tín chỉ
            break;
        }
        case 2:
        {
            MonHoc newCourse;
            cout << "Nhập mã môn học: ";
            cin >> newCourse.MAMH;
            isValidCode(newCourse.MAMH, 3);

            cout << "Nhập tên môn học: ";
            cin.ignore();
            isValidString(newCourse.TENMH);

            cout << "Nhập số tín chỉ lý thuyết: ";
            isValidNumber(newCourse.STCLT);

            cout << "Nhập số tín chỉ thực hành: ";
            isValidNumber(newCourse.STCTH);

            courseList.insert(newCourse);
            courseList.saveToFile(COURSES_FILE);
            break;
        }
        case 3:
        {
            courseList.printInOrder(courseList.getRoot());
            break;
        }
        case 4:
        {
            string mamh;
            cout << "Nhập mã môn học cần cập nhật: ";
            cin >> mamh;
            courseList.updateCourse(mamh);
            courseList.saveToFile(COURSES_FILE);
            break;
        }
        case 5:
        {
            int subChoice;
            do
            {
                cout << "==== MENU LỚP TÍN CHỈ ====" << endl;
                cout << "1. Thêm lớp tín chỉ" << endl;
                cout << "2. Xóa lớp tín chỉ" << endl;
                cout << "3. Hiệu chỉnh lớp tín chỉ" << endl;
                cout << "4. In danh sách sinh viên đăng ký theo lớp" << endl;
                cout << "5. In danh sách lớp tín chỉ" << endl;
                cout << "6. Đăng ký tín chỉ" << endl;
                cout << "7. Huỷ các lớp tín chỉ không đủ sinh viên" << endl;
                cout << "8. Nhập điểm theo lớp" << endl;
                cout << "9. In bảng điểm môn học" << endl;
                cout << "10. In bảng điểm trung bình" << endl;
                cout << "11. In bảng điểm tổng kết" << endl;
                cout << "0. Quay lại" << endl;
                cout << "Chọn chức năng: ";
                cin >> subChoice;

                switch (subChoice)
                {
                case 1:
                {
                    int malopTC, hocKy, nhom, soSvMin, soSvMax;
                    string maMH, nienKhoa, tenLop;

                    cout << "Nhập mã lớp tín chỉ: ";
                    isValidNumber(malopTC);

                    cout << "Nhập mã môn học: ";
                    cin >> maMH;
                    isValidCode(maMH, 3);

                    if (courseList.isCourseExisted(maMH))
                    {
                        cout << "Nhập tên lớp: ";
                        cin.ignore();
                        isValidString(tenLop);

                        cout << "Nhập niên khóa: ";
                        isValidYear(nienKhoa);

                        cout << "Nhập học kỳ: ";
                        isValidNumber(hocKy);

                        cout << "Nhập nhóm: ";
                        isValidNumber(nhom);

                        cout << "Nhập số sinh viên tối thiểu: ";
                        isValidNumber(soSvMin);

                        cout << "Nhập số sinh viên tối đa: ";
                        isValidNumber(soSvMax);

                        // Tạo lớp tín chỉ mới
                        CreditClass *newCreditClass = new CreditClass(malopTC, maMH, tenLop, nienKhoa, hocKy, nhom, soSvMin, soSvMax);
                        creditClassList.addCreditClass(newCreditClass); // Thêm lớp tín chỉ vào danh sách
                        creditClassList.saveToFile(CREDIT_CLASSES_FILE);
                    }
                    else
                    {
                        cout << "Không tìm thấy môn học " << maMH << "." << endl;
                    }
                    break;
                }

                case 2:
                {
                    int malopTC;
                    cout << "Nhập mã lớp tín chỉ cần xóa: ";
                    isValidNumber(malopTC);
                    creditClassList.removeCreditClass(malopTC); // Sử dụng instance creditClassList
                    creditClassList.saveToFile(CREDIT_CLASSES_FILE);
                    break;
                }
                case 3:
                {
                    int malopTC;
                    cout << "Nhập mã lớp tín chỉ cần hiệu chỉnh: ";
                    isValidNumber(malopTC);

                    // Tìm lớp tín chỉ theo mã lớp tín chỉ (malopTC)
                    CreditClass *creditClass = creditClassList.findCreditClassByMALOPTC(malopTC);
                    if (creditClass == nullptr)
                    {
                        cout << "Không tìm thấy lớp tín chỉ với mã: " << malopTC << endl;
                        break;
                    }

                    // Hiển thị thông tin hiện tại của lớp tín chỉ
                    cout << "Thông tin lớp tín chỉ hiện tại:" << endl;
                    cout << "Mã lớp tín chỉ: " << creditClass->getMALOPTC() << endl;
                    cout << "Mã môn học: " << creditClass->getMAMH() << endl;
                    cout << "Tên lớp: " << creditClass->getTenLop() << endl;
                    cout << "Niên khóa: " << creditClass->getNienKhoa() << endl;
                    cout << "Học kỳ: " << creditClass->getHocKy() << endl;
                    cout << "Nhóm: " << creditClass->getNhom() << endl;
                    cout << "Số sinh viên tối thiểu: " << creditClass->getSoSvMin() << endl;
                    cout << "Số sinh viên tối đa: " << creditClass->getSoSvMax() << endl;
                    cout << "Trạng thái hủy lớp: " << (creditClass->isHuyLop() ? "Có" : "Không") << endl;

                    // Cho phép người dùng nhập thông tin mới
                    cout << "\nNhập thông tin mới cho lớp tín chỉ:" << endl;
                    string maMH, tenLop, nienKhoa;
                    int hocKy, nhom, soSvMin, soSvMax;
                    bool huyLop;

                    // Kiểm tra mã môn học
                    cout << "Nhập mã môn học: ";
                    cin >> maMH;
                    while (!isValidCode(maMH, 3))
                    {
                        cout << "Mã môn học không hợp lệ. Vui lòng nhập lại: ";
                        cin >> maMH;
                    }

                    // Kiểm tra tên lớp
                    cout << "Nhập tên lớp: ";
                    cin.ignore(); // Để bỏ qua newline còn lại trong bộ đệm
                    while (!isValidString(tenLop))
                    {
                        cout << "Tên lớp không hợp lệ. Vui lòng nhập lại: ";
                        getline(cin, tenLop);
                    }

                    // Kiểm tra niên khóa
                    cout << "Nhập niên khóa (YYYY-YYYY): ";
                    while (!isValidYear(nienKhoa))
                    {
                        cout << "Niên khóa không hợp lệ. Vui lòng nhập lại: ";
                        cin >> nienKhoa;
                    }

                    // Kiểm tra học kỳ
                    cout << "Nhập học kỳ: ";
                    while (!isValidNumber(hocKy))
                    {
                        cout << "Học kỳ không hợp lệ. Vui lòng nhập lại: ";
                    }

                    // Kiểm tra nhóm
                    cout << "Nhập nhóm: ";
                    while (!isValidNumber(nhom) || nhom <= 0)
                    {
                        cout << "Nhóm phải là số nguyên dương. Vui lòng nhập lại: ";
                    }

                    // Kiểm tra số sinh viên tối thiểu
                    cout << "Nhập số sinh viên tối thiểu: ";
                    isValidNumber(soSvMin);
                    // Kiểm tra số sinh viên tối đa
                    cout << "Nhập số sinh viên tối đa: ";
                    isValidNumber(soSvMax);
                    while (soSvMin <= 0 || soSvMax <= 0 || soSvMin > soSvMax)
                    {
                        cout << "Số sinh viên tối thiểu và tối đa không hợp lệ. Vui lòng nhập lại:\n";
                        cout << "Số sinh viên tối thiểu: ";
                        cin >> soSvMin;
                        cout << "Số sinh viên tối đa: ";
                        cin >> soSvMax;
                    }

                    // Kiểm tra trạng thái hủy lớp
                    cout << "Lớp này có bị hủy không? (1: Có, 0: Không): ";
                    cin >> huyLop;
                    while (huyLop != 0 && huyLop != 1)
                    {
                        cout << "Trạng thái hủy lớp không hợp lệ. Vui lòng nhập lại (1: Có, 0: Không): ";
                        cin >> huyLop;
                    }

                    // Cập nhật thông tin lớp tín chỉ
                    creditClass->setMAMH(maMH);
                    creditClass->setTenLop(tenLop);
                    creditClass->setNienKhoa(nienKhoa);
                    creditClass->setHocKy(hocKy);
                    creditClass->setNhom(nhom);
                    creditClass->setSoSvMin(soSvMin);
                    creditClass->setSoSvMax(soSvMax);
                    creditClass->setHuyLop(huyLop);

                    cout << "Cập nhật thông tin lớp tín chỉ thành công!" << endl;
                    break;
                }
                case 4:
                {
                    // In danh sách sinh viên đăng ký theo niên khóa, học kỳ, nhóm, mã môn học
                    int malopTC;
                    cout << "Nhập mã lớp tín chỉ để in danh sách sinh viên: ";
                    isValidNumber(malopTC);

                    // Tìm lớp tín chỉ theo mã lớp tín chỉ (malopTC)
                    CreditClass *creditClass = creditClassList.findCreditClassByMALOPTC(malopTC);

                    if (creditClass == nullptr)
                    {
                        cout << "Không tìm thấy lớp tín chỉ với mã: " << malopTC << endl;
                    }
                    else
                    {
                        // In các thông tin lớp tín chỉ (niên khóa, học kỳ, nhóm, mã môn học)
                        cout << "Thông tin lớp tín chỉ: " << endl;
                        cout << "Mã lớp tín chỉ: " << creditClass->getMALOPTC() << endl;
                        cout << "Mã môn học: " << creditClass->getMAMH() << endl;
                        cout << "Tên lớp: " << creditClass->getTenLop() << endl;
                        cout << "Niên khóa: " << creditClass->getNienKhoa() << endl;
                        cout << "Học kỳ: " << creditClass->getHocKy() << endl;
                        cout << "Nhóm: " << creditClass->getNhom() << endl;

                        // Lấy danh sách sinh viên đăng ký
                        vector<SinhVien> &students = creditClass->getDSSVDK();

                        if (students.empty())
                        {
                            cout << "Danh sách sinh viên đăng ký: Chưa có sinh viên nào." << endl;
                        }
                        else
                        {
                            cout << "Danh sách sinh viên đăng ký: " << endl;
                            for (const auto &student : students)
                            {
                                cout << student.getMaSV() << " - " << student.getHo() << " " << student.getTen() << endl;
                            }
                        }
                    }
                    break;
                }

                case 5:
                {
                    creditClassList.displayCreditClasses();
                    break;
                }

                case 6:
                {
                    string maSV;
                    cout << "Nhập mã sinh viên để đăng ký tín chỉ: ";
                    cin >> maSV;
                    isValidCode(maSV);
                    SinhVien *sv = classList.findSinhVienById(maSV);
                    if (sv == nullptr)
                    {
                        cout << "Không tìm thấy sinh viên" << endl;
                    }
                    else
                    {
                        sv->inThongTin();
                        string nienKhoa;
                        int hocKy;
                        cout << "Nhập niên khóa, học kỳ để tìm môn học phù hợp: ";
                        cin >> nienKhoa >> hocKy;
                        vector<CreditClass *> classes = creditClassList.findClassesByParams(nienKhoa, hocKy);
                        if (classes.size() == 0)
                        {
                            cout << "Không tìm thấy lớp tín chỉ phù hợp!" << endl;
                        }
                        else
                        {
                            for (const auto &creditClass : classes)
                            {
                                cout << "Mã môn học: " << creditClass->getMAMH()
                                     << ", Tên môn học: " << creditClass->getTenLop()
                                     << ", Nhóm: " << creditClass->getNhom()
                                     << ", Số sinh viên đã đăng ký: " << creditClass->getDSSVDK().size()
                                     << ", Số slot còn trống: " << creditClass->getSoSvMax() - creditClass->getDSSVDK().size()
                                     << endl;
                            }
                            string maMH;
                            cout << "Nhập mã môn học cần đăng ký: ";
                            cin >> maMH;
                            bool ketQuaDangKy = creditClassList.registerStudent(maMH, *sv);
                            creditClassList.saveToFile(CREDIT_CLASSES_FILE);
                            if (ketQuaDangKy == true)
                            {
                                cout << "Đăng ký thành công" << endl;
                            }
                            else
                            {
                                cout << "Mã môn học không hợp lệ!" << endl;
                            }
                        }
                    }
                    break;
                }

                case 7:
                {
                    creditClassList.cancelCreditClasses();
                    creditClassList.saveToFile(CREDIT_CLASSES_FILE);
                    break;
                }

                case 8:
                {
                    string nienKhoa, maMH;
                    int hocKy, nhom;
                    cout << "Nhập niên khóa: ";
                    cin >> nienKhoa;
                    cout << "Nhập học kỳ: ";
                    cin >> hocKy;
                    cout << "Nhập nhóm: ";
                    cin >> nhom;
                    cout << "Nhập mã môn học: ";
                    cin >> maMH;
                    CreditClass *creditClass = creditClassList.findClass(nienKhoa, hocKy, nhom, maMH);
                    vector<SinhVien> dssv = creditClass->getDSSVDK();
                    if (dssv.size() > 0)
                    {
                        initscr();            // Khởi tạo ncurses
                        keypad(stdscr, TRUE); // Bật phím mũi tên
                        noecho();             // Tắt nhập ký tự trên màn hình
                        int pos = 0;          // Vị trí dòng hiện tại
                        int key;
                        bool dangChinhSua = true;
                        while (dangChinhSua)
                        {
                            hienThiDanhSach(dssv, pos);

                            key = getch(); // Đọc phím nhập
                            switch (key)
                            {
                            case KEY_UP:
                                if (pos > 0)
                                    pos--; // Di chuyển lên
                                break;
                            case KEY_DOWN:
                                if (pos < dssv.size() - 1)
                                    pos++; // Di chuyển xuống
                                break;
                            case '\n': // Nhấn Enter để nhập điểm
                                nhapDiem(dssv, pos);
                                break;
                            case 27: // Nhấn ESC để thoát
                                dangChinhSua = false;
                                break;
                            }
                        }
                        move(0, 0);
                        refresh();
                        endwin();
                        cin.ignore();
                        creditClass->capNhatDSSV(dssv);
                        creditClassList.saveToFile(CREDIT_CLASSES_FILE);
                    }
                    else
                    {
                        cout << "Lớp trống hoặc không tìm thấy lớp!" << endl;
                    }
                    break;
                }
                case 9:
                { // Case mới cho việc in bảng điểm môn học
                    string nienKhoa, maMH;
                    int hocKy, nhom;

                    // Nhập thông tin lớp tín chỉ
                    cout << "Nhập niên khóa: ";
                    cin >> nienKhoa;
                    cout << "Nhập học kỳ: ";
                    cin >> hocKy;
                    cout << "Nhập nhóm: ";
                    cin >> nhom;
                    cout << "Nhập mã môn học: ";
                    cin >> maMH;

                    // Tìm lớp tín chỉ theo các thông tin nhập vào
                    CreditClass *creditClass = creditClassList.findClass(nienKhoa, hocKy, nhom, maMH);
                    if (creditClass == nullptr)
                    {
                        cout << "Không tìm thấy lớp tín chỉ với thông tin trên!" << endl;
                    }
                    else
                    {
                        // Lấy danh sách sinh viên trong lớp tín chỉ
                        vector<SinhVien> dssv = creditClass->getDSSVDK();
                        if (dssv.empty())
                        {
                            cout << "Lớp trống, không có sinh viên nào!" << endl;
                        }
                        else
                        {
                            // In thông tin bảng điểm
                            cout << "BẢNG ĐIỂM MÔN HỌC " << creditClass->getTenLop() << endl;
                            cout << "Niên khóa: " << nienKhoa << " Học kỳ: " << hocKy << " Nhóm: " << nhom << endl;
                            cout << "\nSTT\tMASV\tHO\tTEN\t\tDIEM" << endl;

                            int stt = 1;
                            for (const auto &sv : dssv)
                            {
                                cout << stt++ << "\t";
                                cout << sv.getMaSV() << "\t";
                                cout << sv.getHo() << "\t";
                                cout << sv.getTen() << "\t";
                                // Sử dụng getDiem từ SinhVien để lấy điểm
                                cout << sv.getDiem() << endl; // In điểm của sinh viên
                            }
                        }
                    }
                    break;
                }
                case 10:
                {
                    // Nhập thông tin lớp tín chỉ
                    string nienKhoa, maMH;
                    int hocKy, nhom;

                    cout << "Nhập niên khóa: ";
                    cin >> nienKhoa;
                    cout << "Nhập học kỳ: ";
                    cin >> hocKy;
                    cout << "Nhập nhóm: ";
                    cin >> nhom;
                    cout << "Nhập mã môn học: ";
                    cin >> maMH;

                    // Tìm lớp tín chỉ theo các thông tin nhập vào
                    CreditClass *creditClass = creditClassList.findClass(nienKhoa, hocKy, nhom, maMH);
                    if (creditClass == nullptr)
                    {
                        cout << "Không tìm thấy lớp tín chỉ với thông tin trên!" << endl;
                    }
                    else
                    {
                        // Lấy danh sách sinh viên trong lớp tín chỉ
                        vector<SinhVien> dssv = creditClass->getDSSVDK();
                        if (dssv.empty())
                        {
                            cout << "Lớp trống, không có sinh viên nào!" << endl;
                        }
                        else
                        {
                            // In thông tin bảng thống kê điểm trung bình
                            cout << "BẢNG THỐNG KÊ ĐIỂM TRUNG BÌNH KHÓA HỌC" << endl;
                            cout << "Lớp: " << creditClass->getTenLop() << endl;
                            cout << "\nSTT\tMASV\tHO\tTEN\tĐiểm TB" << endl;

                            int stt = 1;
                            for (const auto &sv : dssv)
                            {
                                cout << stt++ << "\t";
                                cout << sv.getMaSV() << "\t";
                                cout << sv.getHo() << "\t";
                                cout << sv.getTen() << "\t";

                                // Tính điểm trung bình kết thúc khóa học
                                // Giả sử lớp tín chỉ có một số tín chỉ, bạn cần cập nhật hàm tính điểm trung bình
                                float diemTB = sv.getDiem(); // Lấy điểm của sinh viên, có thể thay đổi nếu tính điểm trung bình từ nhiều môn
                                cout << diemTB << endl;
                            }
                        }
                    }
                    break;
                }

                case 11:
                {
                    // Nhập thông tin lớp tín chỉ
                    string nienKhoa, maMH;
                    int hocKy, nhom;

                    cout << "Nhập niên khóa: ";
                    cin >> nienKhoa;
                    cout << "Nhập học kỳ: ";
                    cin >> hocKy;
                    cout << "Nhập nhóm: ";
                    cin >> nhom;
                    cout << "Nhập mã môn học: ";
                    cin >> maMH;

                    // Tìm lớp tín chỉ theo các thông tin nhập vào
                    CreditClass *creditClass = creditClassList.findClass(nienKhoa, hocKy, nhom, maMH);
                    if (creditClass == nullptr)
                    {
                        cout << "Không tìm thấy lớp tín chỉ với thông tin trên!" << endl;
                    }
                    else
                    {
                        // Lấy danh sách sinh viên trong lớp tín chỉ
                        vector<SinhVien> dssv = creditClass->getDSSVDK();
                        if (dssv.empty())
                        {
                            cout << "Lớp trống, không có sinh viên nào!" << endl;
                        }
                        else
                        {
                            // In thông tin bảng điểm tổng kết
                            cout << "BẢNG ĐIỂM TỔNG KẾT" << endl;
                            cout << "Lớp: " << creditClass->getTenLop() << endl;

                            // In tên cột bảng điểm
                            cout << "\nSTT\tMã SV\tHọ Tên\t";
                            vector<string> danhSachMonHoc = creditClass->getDanhSachMonHoc();

                            // In các mã môn học trong bảng
                            for (const string &monHoc : danhSachMonHoc)
                            {
                                cout << monHoc << "\t";
                            }
                            cout << endl;

                            int stt = 1;
                            for (const auto &sv : dssv)
                            {
                                cout << stt++ << "\t";
                                cout << sv.getMaSV() << "\t";
                                cout << sv.getHo() << " " << sv.getTen() << "\t";

                                // Lấy điểm cao nhất cho từng môn học của sinh viên
                                for (const string &monHoc : danhSachMonHoc)
                                {
                                    // Lấy điểm cao nhất của sinh viên cho mỗi môn học
                                    float diemCaoNhat = sv.getDiemCaoNhat(monHoc);
                                    cout << diemCaoNhat << "\t"; // Hiển thị điểm của sinh viên
                                }
                                cout << endl;
                            }
                        }
                    }
                    break;
                }

                default:
                    break;
                }
            } while (subChoice != 0); // Kết thúc vòng lặp con cho lớp tín chỉ
            break;
        }
        default:
            break;
        }
    } while (choice != 0);

    return 0;
}