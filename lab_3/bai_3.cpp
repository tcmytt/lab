#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
#include<cmath>
using namespace std;

class GV {
    private:
        char ht[30];
        int t;
        char bc[15];
        char cn[20];
        float bl;
    public:
        friend istream& operator >> (istream& is, GV& temp) {
            fflush(stdin);
            cout << "\t+ Nhap ho ten: ";
            is.getline(temp.ht, 30);
            cout << "\t+ Nhap tuoi: ";
            is >> temp.t;
            cout << "\t+ Nhap bang cap: ";
            fflush(stdin);
            is.getline(temp.bc, 15);
            cout << "\t+ Nhap chuyen nganh: ";
            is.getline(temp.cn, 20);
            cout << "\t+ Nhap bac luong: ";
            is >> temp.bl;
            return is;
        }
        friend ostream& operator << (ostream& os, GV temp) {
            os << left << setw(30) << temp.ht;
            os << left << setw(30) << temp.t;
            os << left << setw(30) << temp.bc;
            os << left << setw(30) << temp.cn;
            os << left << setw(30) << temp.bl;
            os << left << setw(30) << temp.tienLuong();
            return os;
        }

        float tienLuong() {
            return this->bl * 610;
        }

        char* get_ht() {
            return this->ht;
        }
};

bool scpi(char* a, char* b) {
    int n1 = strlen(a);
    int n2 = strlen(b);
    if(n1 != n2) {
        return false;
    }
    for(int i = 0; i < n1; i++) {
        if(tolower(a[i]) != tolower(b[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    vector<GV> gvs;
    cout << "Nhap so luong giao vien can luu tru: ";
    cin >> n;
    gvs.resize(n);

    for(int i = 0; i < n; i++) {
        cout << "Thong tin giao vien thu " << i + 1 << " la:" << endl;
        cin >> gvs[i];
    }
    bool checkLuong = false;
    cout << "Danh sach giao vien co tien luong nho hon 2000 la:" << endl;
    for(GV gv : gvs) {
        if(gv.tienLuong() < 2000) {
            checkLuong = true;
            cout << gv << endl;
        }
    }
    if(!checkLuong) {
        cout << "\t Khong co giao vien nao co tien luong < 2000.";
    }
    bool checkTen = false;
    char sethoten[30];
    fflush(stdin);
    cout << "\nNhap ho ten giao vien can tim la: ";
    cin.getline(sethoten, 30);
    for(GV gv : gvs) {
        if(scpi(gv.get_ht(), sethoten) == true) {
            checkTen = true;
            cout << gv << endl;
        }
    }
    if(!checkTen) {
        GV temp;
        cout << "Khong tim thay ten giao vien nay." << endl;
        cout << "Moi ban nhap thong tin giao vien can them: "<< endl;
        cin >> temp;
        gvs.push_back(temp);
        cout << "Danh sach giao vien sau khi them la: " << endl;
        for(GV gv : gvs) {
            cout << gv << endl;
        }
    }
    return 0;
}