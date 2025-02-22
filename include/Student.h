#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include <map>

using namespace std;

class SinhVien
{
private:
    string MASV;
    string HO;
    string TEN;
    string GIOITINH;
    string CMND;
    string SODT;
    map<string, float> DIEM;

    struct DangKy
    {
        string MASV;
        float DIEM;
        bool huyDangKy;
        DangKy* next;

        DangKy(string masv, float diem, bool huy)
            : MASV(masv), DIEM(diem), huyDangKy(huy), next(nullptr) {}
    };
    DangKy* dsdangky;

public:
    SinhVien(const string &masv, const string &ho, const string &ten, 
             const string &gioitinh, const string &cmnd, const string &sodt)
        : MASV(masv), HO(ho), TEN(ten), GIOITINH(gioitinh), CMND(cmnd), SODT(sodt), dsdangky(nullptr) {}

    string getMASV() const { return MASV; }
    string getHO() const { return HO; }
    string getTEN() const { return TEN; }
    string getGIOITINH() const { return GIOITINH; }
    string getCMND() const { return CMND; }
    string getSODT() const { return SODT; }

    void setMASV(const string &masv) { MASV = masv; }
    void setHO(const string &ho) { HO = ho; }
    void setTEN(const string &ten) { TEN = ten; }
    void setGIOITINH(const string &gioitinh) { GIOITINH = gioitinh; }
    void setCMND(const string &cmnd) { CMND = cmnd; }
    void setSODT(const string &sodt) { SODT = sodt; }

    void capNhatDiem(const string &maMH, float diemMoi) {
        DIEM[maMH] = diemMoi;
    }

    float getDiem(const string &maMH) const {
        auto it = DIEM.find(maMH);
        if (it != DIEM.end()) {
            return it->second;
        }
        return -1.0f;
    }

    void inDiem() const {
        for (const auto &entry : DIEM) {
            cout << "Môn học: " << entry.first << " - Điểm: " << entry.second << endl;
        }
    }

    void themDangKy(float diem, bool huy) {
        DangKy* newDangKy = new DangKy(MASV, diem, huy);
        newDangKy->next = dsdangky;
        dsdangky = newDangKy;
    }

    void inDanhSachDangKy() const {
        DangKy* temp = dsdangky;
        while (temp != nullptr) {
            cout << "Mã SV: " << temp->MASV << ", Điểm: " << temp->DIEM 
                 << ", Hủy đăng ký: " << (temp->huyDangKy ? "Có" : "Không") << endl;
            temp = temp->next;
        }
    }

    ~SinhVien() {
        while (dsdangky != nullptr) {
            DangKy* temp = dsdangky;
            dsdangky = dsdangky->next;
            delete temp;
        }
    }
};

#endif // STUDENT_H
