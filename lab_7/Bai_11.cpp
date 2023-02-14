#include<iostream>
#include<cstring>
#include<iomanip>
#include<stack>
using namespace std;

class MayTinh {
    private:
        string tenhang;
        string mausac;
        int dungluong;
        float tocdo;
    public:
        friend istream &operator >> (istream &is, MayTinh &temp) {
            cout << "\n\t+ Nhap ten hang: ";
            fflush(stdin);
            getline(is, temp.tenhang);
            cout << "\t+ Nhap mau sac: ";
            getline(is, temp.mausac);
            cout << "\t+ Nhap dung luong: ";
            is >> temp.dungluong;
            cout << "\t+ Nhap toc do: ";
            is >> temp.tocdo;
            return is;
        }

        friend ostream &operator << (ostream &os, MayTinh temp) {
            os << setw(30) << left << temp.tenhang;
            os << setw(30) << left << temp.mausac;
            os << setw(30) << left << temp.dungluong;
            os << setw(30) << left << temp.tocdo << endl;
            return os;
        }
};

template<class T>
void input(stack<T> &stack, int n) {
    for (int i = 0; i < n; i++) {
        T temp;
        cout << "Phan tu thu " << i + 1 << " la: ";
        cin >> temp;
        stack.push(temp);
    }
}

template<class T>
void output(stack<T> stack) {
    cout << "\t";
    while (!stack.empty()) {
        cout << stack.top() << "\t";
        stack.pop();
    }
}

void tieude() {
    cout << setw(30) << left << "\tTen hang";
    cout << setw(30) << left << "Mau sac";
    cout << setw(30) << left << "Dung luong";
    cout << setw(30) << left << "Toc do" << endl;
}

int main() {
    stack<int> stack1;
    stack<float> stack2;
    stack<MayTinh> stack3;
    int n;
    cout << "Nhap so luong phan tu la: ";
    cin >> n;
    input(stack1, n);
    output(stack1);
    cout << endl;
    input(stack2, n);
    output(stack2);
    cout << endl;
    input(stack3, n);
    tieude();
    output(stack3);
    return 0;
}