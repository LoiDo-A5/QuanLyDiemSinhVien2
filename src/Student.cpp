#include "../include/Student.h"

SinhVien::SinhVien() : MASV(""), HO(""), TEN(""), GIOITINH(""), CMND(""), SODT(""), dsdangky(nullptr) {}

SinhVien::SinhVien(const string &masv, const string &ho, const string &ten,
                   const string &gioitinh, const string &cmnd, const string &sodt)
    : MASV(masv), HO(ho), TEN(ten), GIOITINH(gioitinh), CMND(cmnd), SODT(sodt), dsdangky(nullptr) {}

string SinhVien::getMASV() const { return MASV; }
string SinhVien::getHO() const { return HO; }
string SinhVien::getTEN() const { return TEN; }
string SinhVien::getGIOITINH() const { return GIOITINH; }
string SinhVien::getCMND() const { return CMND; }
string SinhVien::getSODT() const { return SODT; }

void SinhVien::setMASV(const string &masv) { MASV = masv; }
void SinhVien::setHO(const string &ho) { HO = ho; }
void SinhVien::setTEN(const string &ten) { TEN = ten; }
void SinhVien::setGIOITINH(const string &gioitinh) { GIOITINH = gioitinh; }
void SinhVien::setCMND(const string &cmnd) { CMND = cmnd; }
void SinhVien::setSODT(const string &sodt) { SODT = sodt; }

void SinhVien::capNhatDiem(const string &maMH, float diemMoi)
{
    DIEM[maMH] = diemMoi;
}

float SinhVien::getDiem(const string &maMH) const
{
    auto it = DIEM.find(maMH);
    return (it != DIEM.end()) ? it->second : -1; // Trả về -1 nếu không tìm thấy điểm
}

void SinhVien::inThongTin() const
{
    cout << "Mã SV: " << MASV << ", Họ: " << HO << ", Tên: " << TEN
         << ", Giới tính: " << GIOITINH << ", CMND: " << CMND
         << ", Số điện thoại: " << SODT << endl;
}

void SinhVien::inDiem() const
{
    cout << "Điểm các môn của " << MASV << ":\n";
    for (const auto &pair : DIEM)
    {
        cout << "Môn: " << pair.first << ", Điểm: " << pair.second << endl;
    }
}

void SinhVien::themDangKy(float diem, bool huy)
{
    DangKy *moi = new DangKy(MASV, diem, huy);
    moi->next = dsdangky;
    dsdangky = moi;
}

void SinhVien::inDanhSachDangKy() const
{
    DangKy *current = dsdangky;
    while (current)
    {
        cout << "Mã SV: " << current->MASV << ", Điểm: " << current->DIEM
             << ", Hủy đăng ký: " << (current->huyDangKy ? "Có" : "Không") << endl;
        current = current->next;
    }
}

SinhVien::~SinhVien()
{
    while (dsdangky)
    {
        DangKy *temp = dsdangky;
        dsdangky = dsdangky->next;
        delete temp;
    }
}

string SinhVien::toString() const
{
    stringstream ss;
    ss << MASV << " " << HO << " " << TEN << " " << GIOITINH << " " << CMND << " " << SODT;
    return ss.str();
}

void SinhVien::fromString(const string &str)
{
    istringstream ss(str);
    ss >> MASV >> HO >> TEN >> GIOITINH >> CMND >> SODT;
}
