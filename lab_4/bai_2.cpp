#include<iostream>
#include<cstring>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;

class mydate {
    private:
        int d, m, y;
    public:
        mydate() {
            this->d = 0;
            this->m = 0;
            this->y = 0;
        }
        mydate(int d, int m, int y) {
            this->d = d;
            this->m = m;
            this->y = y;
        }
        ~mydate() {}
        void nhap() {
            cout << "\t + Nhap ngay: ";
            cin >> this->d;
            cout << "\t + Nhap thang: ";
            cin >> this->m;
            cout << "\t + Nhap nam: ";
            cin >> this->y;
        }
        void xuat() {
            cout << this->d << "/" << this->m << "/" << this->y << "            ";
        }
        int getnam() {
            return this->y;
        }
};

class person : public mydate {
    private:
        string name, address;
        int phone;
    public:
        person() : mydate() {
            this->name = "";
            this->address = "";
            this->phone = 0;
        }
        person(int d, int m, int y, string name, string address, int phone) : mydate(d, m, y) {
            this->name = name;
            this->address = address;
            this->phone = phone;
        }
        ~person() {}
        void nhap() {
            fflush(stdin);
            cout << "\t + Nhap ten: ";
            getline(cin, this->name);
            mydate::nhap();
            fflush(stdin);
            cout << "\t + Nhap dia chi: ";
            getline(cin, this->address);
            cout << "\t + Nhap sdt: ";
            cin >> this->phone;

        }
        void xuat() {
            cout << left << setw(30) << this->name;
            mydate::xuat();
            cout << left << setw(30) << this->address;
            cout << left << setw(30) << this->phone << endl;
        }
        friend bool operator > (person a, person b) {
            if(a.getnam() > b.getnam()) {
                return true;
            }
            return false;
        }
};

void title() {
    cout << left << setw(30) << "Ho ten";
    cout << left << setw(30) << "Ngay/thang/nam";
    cout << left << setw(30) << "Dia chi";
    cout << left << setw(30) << "So dien thoai" << endl;
}

bool tmp(person a, person b) {
    return a > b;
}

int main() {
    int n;
    vector<person> p;
    cout << "Nhap so luong nguoi can luu tru la: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        person temp;
        temp.nhap();
        p.push_back(temp);
    }
    cout << "Danh sach sau khi nhap la: " << endl;
    title();
    for(person temp : p) {
        temp.xuat();
    }
    cout << "Danh sach sau khi sap xep la: " << endl;
    sort(p.begin(), p.end(), tmp);
    title();
    for(person temp : p) {
        temp.xuat();
    }
    return 0;
}