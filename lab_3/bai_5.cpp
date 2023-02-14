#include<iostream>
using namespace std;

class PS {
    private:
        int tuso, mauso;
    public:
        PS(int tuso = 0, int mauso = 0) {
            this->tuso = tuso;
            this->mauso = mauso;
        }
        ~PS() {}
        friend istream& operator >> (istream& is, PS& temp) {
            cout << "\t+ Nhap tu so: ";
            is >> temp.tuso;
            cout << "\t+ Nhap mau so: ";
            is >> temp.mauso;
            return is;
        }
        friend ostream& operator << (ostream& os, PS temp) {
            os << temp.tuso << "/" << temp.mauso;
            return os;
        }
        friend PS operator + (PS a, PS b) {
            PS add;
            add.tuso = a.tuso * b.mauso + a.mauso * b.tuso;
            add.mauso = a.mauso * b.mauso;
            return add;
        }
        friend PS operator - (PS a, PS b) {
            PS sub;
            sub.tuso = a.tuso * b.mauso - a.mauso * b.tuso;
            sub.mauso = a.mauso * b.mauso;
            return sub;
        }
        friend PS operator * (PS a, PS b) {
            PS mul;
            mul.tuso = a.tuso * b.tuso;
            mul.mauso = a.mauso * b.mauso;
            return mul;
        }
        friend PS operator / (PS a, PS b) {
            PS div;
            div.tuso = a.tuso * b.mauso;
            div.mauso = a.mauso * b.tuso;
            return div;
        }
};

int main() {
    PS ps1, ps2;
    cout << "Nhap phan so thu 1 la: " << endl;
    cin >> ps1;
    cout << "Nhap phan so thu 2 la: " << endl;
    cin >> ps2;
    cout << "Hien thi phan so thu 1 la: " << ps1 << endl;
    cout << "Hien thi phan so thu 2 la: " << ps2 << endl;
    cout << "Tong hai phan so la: " << ps1 + ps2 << endl;
    cout << "Hieu hai phan so la: " << ps1 - ps2 << endl;
    cout << "Tich hai phan so la: " << ps1 * ps2 << endl;
    cout << "Thuong hai phan so la: " << ps1 / ps2 << endl;
    return 0;
}