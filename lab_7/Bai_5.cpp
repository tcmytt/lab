#include<iostream>
using namespace std;

template<class T>
class calculator {
    private:
        T a, b;
    public:
        calculator(T a, T b) {
            this->a = a;
            this->b = b;
        }
        void xuat() {
            cout << "Hai so la: " << this->a << " va " << this->b << endl;
            cout << "Cong: " << cong() << endl;
            cout << "Tru: " << tru() << endl;
            cout << "Nhan: " << nhan() << endl;
            cout << "Chia: " << chia() << endl;
            cout << "So lon nhat: " << max() << endl;
        }
        T cong() {
            return this->a + this->b;
        }
        T tru() {
            return this->a - this->b;
        }
        T nhan() {
            return this->a * this->b;
        }
        T chia() {
            return this->a / this->b;
        }
        T max() {
            T max = this->a;
            return max < this->b ? max = this->b : max;
        }
};

int main() {
    calculator<int> cal(2, 3);
    cal.xuat();
    return 0;
}