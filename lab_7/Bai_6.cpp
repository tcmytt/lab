#include<iostream>
#include<vector>
using namespace std;

template<class T>
class array {
    private:
        vector<T> a;
        int n;
    public:
        array(vector<T> a, int n) {
            this->a = a;
            this->n = n;
        }
        void xuat() {
            for (int i = 0; i < this->n; i++) {
                cout << this->a[i] << "\t";
            }
        }
        T tong() {
            T tong = 0;
            for (int i = 0; i < this->n; i++) {
                tong += this->a[i];
            }
            return tong;
        }
};

int main() {
    vector<float> a = {3, 2, 1.6, 4, 5};
    array<float> arr(a, 5);
    cout << "Danh sach mang: ";
    arr.xuat();
    cout << "\nTong: " << arr.tong() << endl;
    return 0;
}