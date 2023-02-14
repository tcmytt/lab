#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;

class Truong {
    private:
        int ma;
        string ten, diaChi;
    public:
        Truong() {
            this->ma = 0;
            this->ten = "";
            this->diaChi = "";
        }
        ~Truong() {}
        void nhap() {
            cout << "\t+ Nhap ma: ";
            cin >> this->ma;
            fflush(stdin);
            cout << "\t+ Nhap ten: ";
            getline(cin, this->ten);
            cout << "\t+ Nhap dia chi: ";
            getline(cin, this->diaChi);
        }
        void xuat() {
            cout << left << setw(30) << this->ma;
            cout << left << setw(30) << this->ten;
            cout << left << setw(30) << this->diaChi;
        }

        void setTen(string tenNew) {
            this->ten = tenNew;
        }

        int getMa() {
            return this->ma;
        }
};

class DaiHoc : public Truong {
    private:
        int nam, soGiangVien;
    public:
        DaiHoc() : Truong() {
            this->nam = 0;
            this->soGiangVien = 0;
        }
        ~DaiHoc() {}
        bool checkNam() {
            return this->nam < 1990;
        }
        bool operator > (DaiHoc a) {
            return this->soGiangVien > a.soGiangVien;
        }
        friend istream &operator >> (istream& is, DaiHoc& temp) {
            temp.nhap();
            cout << "\t+ Nhap nam thanh lap: ";
            is >> temp.nam;
            cout << "\t+ Nhap so giang vien: ";
            is >> temp.soGiangVien;
            return is;
        }
        friend ostream &operator << (ostream& os, DaiHoc temp) {
            temp.xuat();
            os << left << setw(30) << temp.nam;
            os << left << setw(30) << temp.soGiangVien;
            return os;
        }

        int getNam() {
            return this->nam;
        }

        int getSoGiangVien() {
            return this->soGiangVien;
        }
};

bool cmp(DaiHoc a, DaiHoc b) {
    return (a.getSoGiangVien() < b.getSoGiangVien());
}

int main() {
    int n;
    vector<DaiHoc> daihocs;
    cout << "Nhap so luong giao vien can luu la: ";
    do {
        cin >> n;
        if(n < 1) {
            cout << "Nhap sai. Yeu cau nhap lai: ";
        }
    } while(n < 1);
    for (int i = 0; i < n; i++) {
        
        cout << "Nhap thong tin giao vien thu " << i + 1 << " la:" << endl;
        DaiHoc daihoc;
        cin >> daihoc;
        daihocs.push_back(daihoc);
    }
    for(DaiHoc daihoc : daihocs) {
        cout << daihoc << endl;
    }
    int count = 0;
    for(DaiHoc daihoc : daihocs) {
        if(daihoc.getNam() < 1990) {
            count++;
        }
    }
    cout << "So luong truong co nam thanh lap truoc 1990 la: " << count << endl;
    sort(daihocs.begin(), daihocs.end(), cmp);
    cout << "Danh sach sau khi sap xep la:" << endl;
    for(DaiHoc daihoc : daihocs) {
        if(daihoc.getNam() < 1950) {
            cout << daihoc << endl;
        }
    }
    int maVar;
    string tenVar;
    bool checkMa = false;
    cout << "Nhap ma can sua la: ";
    cin >> maVar;
    fflush(stdin);
    cout << "Nhap ten truong: ";
    getline(cin, tenVar);
    for(DaiHoc& daihoc : daihocs) {
        if(daihoc.getMa() == maVar) {
            checkMa = true;
            daihoc.setTen(tenVar);
            cout << "Da sua thanh cong!!";
            cout << "Danh sach sau khi sua la:" << endl;
            for(DaiHoc daihoc : daihocs) {
                cout << daihoc << endl;
            }
            break;
        }
    }
    if(!checkMa) {
        cout << "Khong tim thay ma can sua.";
    }
    return 0;
}