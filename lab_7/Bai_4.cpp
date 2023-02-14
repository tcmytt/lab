#include<iostream>
using namespace std;

template<class T>
class MyPair {
    private:
        T a, b;
    public:
        MyPair(T a, T b) {
            this->a = a;
            this->b = b;
        }
        void xuat() {
            cout << "First = " << this->a << ", Second = " << this->b << endl;
        }

        T max() {
            T max = this->a;
            return max < this->b ? max = this->b : max;
        }
};

int main() {
    MyPair<int> pair(1, 2);
    cout << "Max = " << pair.max();
    return 0;
}