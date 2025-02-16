#include "Student.h"
#include "IsValid.h"
#include <sstream>
#include <stdexcept>

// Constructor mặc định
SinhVien::SinhVien() : MASV(""), HO(""), TEN(""), GIOITINH(""), CMND(""), DIEM(0.0) {}

// Constructor có tham số
SinhVien::SinhVien(const string &masv, const string &ho, const string &ten, const string &gioiTinh, const string &cmnd)
    : MASV(masv), HO(ho), TEN(ten), GIOITINH(gioiTinh), CMND(cmnd), DIEM(0.0) {}

// Hàm nhập thông tin sinh viên
void SinhVien::nhapThongTin()
{
    cout << "Nhập mã sinh viên: ";
    cin >> MASV;
    isValidCode(MASV);

    cin.ignore(); // Để xóa ký tự xuống dòng từ mục nhập trước đó

    cout << "Nhập họ: ";
    isValidString(HO);

    cout << "Nhập tên: ";
    isValidString(TEN);

    cout << "Nhập giới tính: ";
    isValidString(GIOITINH);

    cout << "Nhập số CMND: ";
    cin >> CMND;
    isValidCMND(CMND);
}

// Hàm in thông tin sinh viên
void SinhVien::inThongTin() const
{
    cout << "Mã sinh viên: " << MASV << ", Họ: " << HO << ", Tên: " << TEN
         << ", Giới tính: " << GIOITINH << ", CMND: " << CMND << ", Điểm: " << DIEM << endl;
}

// Hàm lấy mã sinh viên
string SinhVien::getMaSV() const
{
    return MASV;
}

// Hàm lấy tên sinh viên (họ và tên)
string SinhVien::getName() const
{
    return HO + " " + TEN; // Trả về họ và tên
}

// Hàm lấy họ
string SinhVien::getHo() const
{
    return HO;
}

// Hàm lấy tên
string SinhVien::getTen() const
{
    return TEN;
}

// Hàm lấy điểm của sinh viên
float SinhVien::getDiem() const
{
    return DIEM; // Trả về điểm tổng kết của sinh viên
}

// Hàm cập nhật điểm sinh viên
void SinhVien::capNhatDiem(float diemMoi)
{
    DIEM = diemMoi;
}

// Hàm lấy giới tính
string SinhVien::getGioiTinh() const
{
    return GIOITINH; // Trả về giới tính
}

// Hàm lấy CMND
string SinhVien::getCMND() const
{
    return CMND; // Trả về CMND
}

// Hàm chuyển thông tin sinh viên thành chuỗi
string SinhVien::toString() const
{
    return MASV + " " + HO + " " + TEN + " " + GIOITINH + " " + CMND + " " + to_string(DIEM);
}

void SinhVien::fromString(const string &data)
{
    istringstream stream(data); // Tạo một string stream từ dữ liệu đầu vào

    // Trích xuất từng trường dữ liệu từ chuỗi
    stream >> MASV >> HO >> TEN >> GIOITINH >> CMND >> DIEM;

    if (stream.fail()) // Kiểm tra lỗi khi trích xuất
    {
        throw runtime_error("Định dạng dữ liệu không hợp lệ cho SinhVien");
    }
}

// Hàm lấy điểm cao nhất của sinh viên cho một môn học
float SinhVien::getDiemCaoNhat(const string &monHoc) const
{
    auto it = diemMonHoc.find(monHoc); // Tìm môn học trong map
    if (it != diemMonHoc.end())
    {
        return it->second; // Trả về điểm của môn học
    }
    else
    {
        return -1; // Nếu không tìm thấy, trả về -1 để chỉ không có điểm cho môn này
    }
}

// Hàm thêm điểm cho một môn học
void SinhVien::themDiemMonHoc(const string &monHoc, float diem)
{
    diemMonHoc[monHoc] = diem; // Thêm hoặc cập nhật điểm cho môn học
}
