#include<iostream>
#include<cstring>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;

class MonHoc {
    private:
        string tenMonHoc;
        int soTiet;
    public:
        MonHoc() {
            this->tenMonHoc = "";
            this->soTiet = 0;
        }
        MonHoc(string tenMonHoc, int soTiet) {
            this->tenMonHoc = tenMonHoc;
            this->soTiet = soTiet;
        }
        ~MonHoc() {}
        void output() {
            cout << left << setw(30) << this->tenMonHoc;
            cout << left << setw(30) << this->soTiet;
        }
};

class Nguoi {
    private:
        string hoTen;
        int namSinh;
    public:
        Nguoi() {
            this->hoTen = "";
            this->namSinh = 0;
        }
        Nguoi(string hoTen, int namSinh) {
            this->hoTen = hoTen;
            this->namSinh = namSinh;
        }
        ~Nguoi() {}
        void output() {
            cout << left << setw(30) << this->hoTen;
            cout << left << setw(30) << this->namSinh;
        }
};

class GiaoVien : public MonHoc, public Nguoi {
    private:
        string boMon;
    public:
        GiaoVien() : MonHoc(), Nguoi() {
            this->boMon = "";
        }
        GiaoVien(string hoTen, int namSinh, string tenMonHoc, int soTiet, string boMon) : MonHoc(tenMonHoc, soTiet), Nguoi(hoTen, namSinh) {
            this->boMon = boMon;
        }
        ~GiaoVien() {}
        void output() {
            Nguoi::output();
            MonHoc::output();
            cout << left << setw(30) << this->boMon;
        }
};

int main() {
    string hoTen, tenMonHoc, boMon;
    int namSinh, soTiet;
    cout << "Nhap ten giao vien: ";
    getline(cin, hoTen);
    cout << "Nhap nam sinh: ";
    cin >> namSinh;
    fflush(stdin);
    cout << "Nhap ten mon hoc: ";
    getline(cin, tenMonHoc);
    cout << "Nhap so tiet: ";
    cin >> soTiet;
    fflush(stdin);
    cout << "Nhap bo mon: ";
    getline(cin, boMon);
    GiaoVien gv(hoTen, namSinh, tenMonHoc, soTiet, boMon);
    gv.output();
    return 0;
}