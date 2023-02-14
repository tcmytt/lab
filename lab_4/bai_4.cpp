#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

class Anpham {
    private:
        string ten;
        float giathanh;
    public:
        void nhap() {
            fflush(stdin);
            cout << "\t + Nhap ten: ";
            getline(cin, this->ten);
            cout << "\t + Nhap gia thanh: ";
            cin >> this->giathanh;
        }
        void xuat() {
            cout << left << setw(30) << this->ten;
            cout << left << setw(30) << this->giathanh;
        }
        string getten() {
            return this->ten;
        }
};

class Sachkethua : public Anpham {
    private:
        int sotrang;
    public:
        void nhap() {
            Anpham::nhap();
            cout << "\t + Nhap so trang: ";
            cin >> this->sotrang;
        }
        void xuat() {
            Anpham::xuat();
            cout << left << setw(30) << this->sotrang;
        }

        int gettrang() {
            return this->sotrang;
        }
};

class DiaCD : public Anpham {
    private:
        int sophut;
    public:
        void nhap() {
            Anpham::nhap();
            cout << "\t + Nhap so phut: ";
            cin >> this->sophut;
        }
        void xuat() {
            Anpham::xuat();
            cout << left << setw(30) << this->sophut;
        }
};

void NhapSach() {
    int n;
    vector<Sachkethua> s;
    cout << "Nhap so quyen sach la: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        Sachkethua temp;
        cout << "Thong tin quyen sach thu " << i + 1 << " la: " << endl;
        temp.nhap();
        s.push_back(temp);
    }
    bool check = false;
    cout << "Hien thi nhung quyen sach co so trang > 500 la: " << endl;
    for(Sachkethua temp : s) {
        if(temp.gettrang() > 500) {
            temp.xuat();
            cout << endl;
            check = true;
        }
    }
    if(check == false) {
        cout << "Khong co quyen sach nao co so trang > 500." << endl;
    }
}

void NhapDia() {
    int n;
    vector<DiaCD> s;
    cout << "Nhap so dia CD la: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        DiaCD temp;
        cout << "Thong tin dia CD thu " << i + 1 << " la: " << endl;
        temp.nhap();
        s.push_back(temp);
    }
    bool check = false;
    string st;
    fflush(stdin);
    cout << "Nhap ten dia CD can tim la: ";
    getline(cin, st);
    for(DiaCD dia : s) {
        if(dia.getten() == st) {
            dia.xuat();
            check = true;
        }
    }
    if(check == false) {
        cout << "Khong tim thay dia CD ten la: " << st << endl;
    } 
}

int main() {
    NhapSach();
    NhapDia();
    return 0;
}