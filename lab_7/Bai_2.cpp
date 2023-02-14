#include<iostream>
using namespace std;

template<class T>
void nhap(T a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

template<class T>
void xuat(T a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
}

template<class T>
T tong(T a[], int n) {
    T tong = 0;
    for (int i = 0; i < n; i++) {
        tong += a[i];
    }
    return tong;
}

int main() {
    int a[30], n;
    cout << "\n Nhap n = ";
    cin >> n;
    nhap(a, n);
    xuat(a, n);
    cout << "\n Ket qua tong mang nguyen: " << tong(a, n) << endl;
    float b[30];
    nhap(b, n);
    xuat(b, n);
    cout << "\n Ket qua tong mang thuc: " << tong(b, n);
    return 0;
}