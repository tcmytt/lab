#include<iostream>
#include<cstring>
using namespace std;

class VT {
    private:
        int n;
        float *v;
    public:
        VT() {
            int i;
            cout << "So chieu: ";
            cin >> n;
            v = new float[n];
        }
        VT(VT& b) {
            int i;
            v = new float[b.n];
            for (int i = 0; i < n; i++) {
                v[i] = b[i];
            }
        }
        int length() {
            return n;
        }
        VT operator= (VT &b) {
            if(this!=&b) {
                delete v;
                v = new float[b.n];
                for (int i = 0; i < n; i++) {
                    v[i] = b.v[i];
                }
            }
            return *this;
        }
        float& operator[] (int i) {
            return v[i];
        }
        ~VT() {
            delete v;
        }
};

void nhap(VT& s) {
    for (int i = 0; i < s.length(); i++) {
        cout << "Toa do thu " << i + 1 << ": ";
        cin >> s[i];
    }
}

void in(VT& s) {
    cout << "So chieu: " << s.length() << endl;
    for (int i = 0; i < s.length(); i++) {
        cout << s[i] << " ";
    }
    cout << endl;
}

int main() {
    VT s1, s2;
    cout << "Nhap cac toa do cua s1: " << endl;
    nhap(s1);
    cout << "\nIn thong tin ve s1: " << endl;
    in(s1);
    s2 = s1;
    cout << "\nIn thong tin ve s2: " << endl;
    in(s2);
    return 0;
}