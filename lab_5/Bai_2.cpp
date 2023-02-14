#include<iostream>
#include<cstring>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;

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
        friend istream &operator >> (istream& is, Nguoi& ng) {
            fflush(stdin);
            cout << "\t+ Nhap ho ten: ";
            getline(is, ng.hoTen);
            cout << "\t+ Nhap nam sinh: ";
            is >> ng.namSinh;
            return is;
        }

        friend ostream &operator << (ostream& os, Nguoi ng) {
            os << left << setw(30) << ng.hoTen;
            os << left << setw(30) << ng.namSinh;
            return os;
        }
};

class SV {
    private:
        string hanhKiem;
        float diem;
    public:
        SV() {
            this->hanhKiem = "";
            this->diem = 0;
        }
        SV(string hanhKiem, int diem) {
            this->hanhKiem = hanhKiem;
            this->diem = diem;
        }
        ~SV() {}
        friend istream &operator >> (istream& is, SV& ng) {
            fflush(stdin);
            cout << "\t+ Nhap hanh kiem: ";
            getline(is, ng.hanhKiem);
            cout << "\t+ Nhap diem: ";
            is >> ng.diem;
            return is;
        }

        friend ostream &operator << (ostream& os, SV ng) {
            os << left << setw(30) << ng.hanhKiem;
            os << left << setw(30) << ng.diem;
            return os;
        }

        string getHanhKiem() {
            return this->hanhKiem;
        }

        float getDiem() {
            return this->diem;
        }
};

class SVTC : public Nguoi, public SV {
    private:
        float hocPhi;
    public:
        SVTC() : Nguoi(), SV() {
            this->hocPhi = 0;
        }
        SVTC(string hoTen, int namSinh, string hanhKiem, int diem, int hocPhi) : Nguoi(hoTen, namSinh), SV(hanhKiem, diem) {
            this->hocPhi = hocPhi;
        }
        ~SVTC() {}
        friend istream &operator >> (istream& is, SVTC& svtc) {
            is >> (Nguoi&) svtc;
            is >> (SV&) svtc;
            cout << "\t+ Nhap hoc phi: ";
            is >> svtc.hocPhi;
            return is;
        }

        friend ostream &operator << (ostream& os, SVTC svtc) {
            os << (Nguoi) svtc;
            os << (SV) svtc;
            os << left << setw(30) << svtc.hocPhi;
            return os;
        }
        
        int tinhHocBong() {
            string temp = this->getHanhKiem();
            transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
            if(temp == "TOT" && this->getDiem() >= 8.0) {
                return 5000000;
            }
            if(temp == "KHA" && this->getDiem() >= 7.0) {
                return 3000000;
            }
            return 0;
        }
};

void TieuDe() {
    cout << left << setw(30) << "Ho Ten";
    cout << left << setw(30) << "Nam Sinh";
    cout << left << setw(30) << "Hanh Kiem";
    cout << left << setw(30) << "Diem";
    cout << left << setw(30) << "Hoc phi";
    cout << left << setw(30) << "Hoc bong" << endl;
}

bool cmp(SVTC a, SVTC b) {
    return a.getDiem() < b.getDiem();
}

int main() {
    int n;
    cout << "Nhap so luong sinh vien tai chuc la: ";
    do {
        cin >> n;
        if(n < 1) {
            cout << "Nhap sai! Moi ban nhap lai: ";
        }
    } while(n < 1);
    vector<SVTC> svtcs;
    for(int i = 0; i < n; i++) {
        SVTC temp;
        cout << "Nhap thong tin sinh vien tai chuc thu " << i + 1 << " la:" << endl;
        cin >> temp;
        svtcs.push_back(temp);
    }
    cout << "Hien thi danh sach sinh vien vua nhap la:" << endl;
    TieuDe();
    for(SVTC svtc : svtcs) {
        cout << svtc;
        cout << left << setw(30) << svtc.tinhHocBong() << endl;
    }
    cout << "Hien thi danh sach sinh vien co hoc bong la:" << endl;
    TieuDe();
    for(SVTC svtc : svtcs) {
        if(svtc.tinhHocBong() != 0) {
            cout << svtc;
            cout << left << setw(30) << svtc.tinhHocBong() << endl;
        }
    }
    sort(svtcs.begin(), svtcs.end(), cmp);
    cout << "Hien thi danh sach sinh vien sau khi sap xep la:" << endl;
    TieuDe();
    for(SVTC svtc : svtcs) {
        cout << svtc;
        cout << left << setw(30) << svtc.tinhHocBong() << endl;
    }
    return 0;
}