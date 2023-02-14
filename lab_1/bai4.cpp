#include <iostream>
using namespace std;

class VecTor3
{
private:
    int a, b, c;

public:
    VecTor3()
    {
        a = 0;
        b = 0;
        c = 0;
    }
    ~VecTor3() {}
    friend istream &operator>>(istream &is, VecTor3 &vt);
    friend ostream &operator<<(ostream &os, VecTor3 vt);
    VecTor3 operator+(VecTor3 x)
    {
        VecTor3 kq;
        kq.a = a + x.a;
        kq.b = b + x.b;
        kq.c = c + x.c;
        return kq;
    }
    VecTor3 operator-(VecTor3 x)
    {
        VecTor3 kq;
        kq.a = a - x.a;
        kq.b = b - x.b;
        kq.c = c - x.c;
        return kq;
    }
};

istream &operator>>(istream &is, VecTor3 &vt)
{
    cout << "Nhap toa do vector (a, b, c): " << endl;
    is >> vt.a;
    is >> vt.b;
    is >> vt.c;
    return is;
}

ostream &operator<<(ostream &os, VecTor3 vt)
{
    os << "(" << vt.a << ", " << vt.b << ", " << vt.c << ")";
    return os;
}

int main()
{
    VecTor3 vector[2];

    for (int i = 0; i < 2; i++)
    {
        cout << "\nVector thu " << i + 1 << endl;
        cin >> vector[i];
    }

    cout << "\n\nCac vector da nhap: " << endl;
    for (int i = 0; i < 2; i++)
    {
        cout << vector[i] << endl;
    }

    vector[2] = vector[0];
    for (int i = 1; i < 2; i++)
    {
        vector[2] = vector[2] + vector[i];
    }
    cout << "\n\nTong cac vector la: ";
    cout << vector[2];
    vector[2] = vector[0];
    for (int i = 1; i < 2; i++)
    {
        vector[2] = vector[2] - vector[i];
    }
    cout << "\n\nHieu cac vector la: ";
    cout << vector[2];
    return 0;
}