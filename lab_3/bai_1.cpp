#include<iostream>
using namespace std;

class SP {
    private:
        float thuc;
        float ao;
    public:
        friend istream& operator >> (istream& is, SP &temp) {
            cout << "\t +Nhap phan thuc: ";
            is >> temp.thuc;
            cout << "\t +Nhap phan ao: ";
            is >> temp.ao;
            return is;
        }
        friend ostream& operator << (ostream &os, SP temp) {
            os << temp.thuc << "*j + " << temp.ao;
            return os;
        }
};

int main() {
    SP a;
    SP b;
    cout << "Nhap so phuc thu 1 la: " << endl;
    cin >> a;
    cout << "Nhap so phuc thu 2 la: " << endl;
    cin >> b;
    cout << "Hien thi so phuc thu 1 la: " << a << endl;
    cout << "Hien thi so phuc thu 2 la: " << b << endl;
    return 0;
}