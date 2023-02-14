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
T min(T a[], int n) {
    T min = a[0];
    for (int i = 1; i < n; i++) {
        if (min > a[i]){
            min = a[i];
        }
        
    }
    return min;
}

int main() {
    int a[30], n;
    cout << "\n Nhap n = ";
    cin >> n;
    nhap(a, n);
    xuat(a, n);
    cout << "\n Ket qua min mang nguyen: " << min(a, n);
    float b[30];
    nhap(b, n);
    xuat(b, n);
    cout << "\n Ket qua min mang thuc: " << min(b, n);
    return 0;
}