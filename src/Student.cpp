#include "Student.h"
#include "CreditClass.h"

SinhVien::SinhVien() : MASV(""), HO(""), TEN(""), GIOITINH(""), SODT("") {}

SinhVien::SinhVien(const string &masv, const string &ho, const string &ten,
                   const string &gioitinh, const string &sodt)
    : MASV(masv), HO(ho), TEN(ten), GIOITINH(gioitinh), SODT(sodt) {}

// Getter methods
string SinhVien::getMASV() const { return MASV; }
string SinhVien::getHO() const { return HO; }
string SinhVien::getTEN() const { return TEN; }
string SinhVien::getGIOITINH() const { return GIOITINH; }
string SinhVien::getSODT() const { return SODT; }

// Setter methods
void SinhVien::setMASV(const string &masv) { MASV = masv; }
void SinhVien::setHO(const string &ho) { HO = ho; }
void SinhVien::setTEN(const string &ten) { TEN = ten; }
void SinhVien::setGIOITINH(const string &gioitinh) { GIOITINH = gioitinh; }
void SinhVien::setSODT(const string &sodt) { SODT = sodt; }

// In thông tin sinh viên
void SinhVien::inThongTin() const
{
    cout << "Mã SV: " << MASV << ", Họ: " << HO << ", Tên: " << TEN
         << ", Giới tính: " << GIOITINH
         << ", Số điện thoại: " << SODT << endl;
}

// Thêm đăng ký môn học
void SinhVien::themDangKy(float diem, bool huy)
{
    DangKyNode *moi = new DangKyNode(MASV, diem, huy);
    moi->next = nullptr; // Không có danh sách liên kết trong SinhVien
}

// In danh sách đăng ký môn học (chỉ hiển thị)
void SinhVien::inDanhSachDangKy() const
{
    cout << "Sinh viên " << MASV << " không lưu danh sách đăng ký trực tiếp.\n";
}

// Destructor
SinhVien::~SinhVien() {}

// Chuyển đổi SinhVien sang chuỗi
string SinhVien::toString() const
{
    stringstream ss;
    ss << MASV << " " << HO << " " << TEN << " " << GIOITINH << " " << SODT;
    return ss.str();
}

// Tạo SinhVien từ chuỗi
void SinhVien::fromString(const string &str)
{
    istringstream ss(str);
    ss >> MASV >> HO >> TEN >> GIOITINH >> SODT;
}
