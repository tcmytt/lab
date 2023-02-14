#include<iostream>
using namespace std;

template<class T>

T max(T a, T b, T c) {
    T max = a;
    if(max < b) {
        max = b;
    }
    if(max < c) {
        max = c;
    }
    return max;
}

int main() {
    cout << "So nguyen lon nhat la: " << max((int) 3, (int) 4, (int) 5) << endl;
    cout << "So thuc lon nhat la: " << max((float) 3.4, (float) 5, (float) 2.1) << endl;
    return 0;
}