#include<iostream>
#include<vector>
using namespace std;

class DaThuc3 {
    private:
        int a, b, c, d;
    public:
        DaThuc3() {
            this->a = 0;
            this->b = 0;
            this->c = 0;
            this->d = 0;
        }

        friend istream& operator >> (istream& is, DaThuc3& temp) {
            cout << "\t Nhap he so bac 3: ";
            is >> temp.a;
            cout << "\t Nhap he so bac 2: ";
            is >> temp.b;
            cout << "\t Nhap he so bac 1: ";
            is >> temp.c;
            cout << "\t Nhap he so bac 0: ";
            is >> temp.d;
            return is;
        }

        friend ostream& operator << (ostream& os, DaThuc3 temp) {
            os << temp.a << "x3 + " << temp.b << "x2 + " << temp.c << "x + " << temp.d;
            return os;
        }

        friend DaThuc3 operator + (DaThuc3 x, DaThuc3 y) {
            DaThuc3 temp;
            temp.a = x.a + y.a;
            temp.b = x.b + y.b;
            temp.c = x.c + y.c;
            temp.d = x.d + y.d;
            return temp;
        }

        friend DaThuc3 operator - (DaThuc3 x, DaThuc3 y) {
            DaThuc3 temp;
            temp.a = x.a - y.a;
            temp.b = x.b - y.b;
            temp.c = x.c - y.c;
            temp.d = x.d - y.d;
            return temp;
        }
};

int main() {
    vector<DaThuc3> a(2);
    for(int i = 0; i < 2; i++) {
        cout << "Nhap he so da thuc thu " << i + 1 << " la: " << endl;
        cin >> a[i];
        a.push_back(a[i]);
    }
    cout << "Tong cua hai da thuc la: " << a[1] + a[2] << endl;
    cout << "Hieu cua hai da thuc la: " << a[1] - a[2] << endl;
    return 0;
}