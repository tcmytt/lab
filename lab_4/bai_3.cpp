#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

class Mathang {
    private:
        string mahang, tenhang;
        float dongia;
    public:
        Mathang() {
            this->mahang = "";
            this->tenhang = "";
            this->dongia = 0.0;
        }
        Mathang(string mahang, string tenhang, float dongia) {
            this->mahang = mahang;
            this->tenhang = tenhang;
            this->dongia = dongia;
        }
        ~Mathang() {}
        friend istream &operator >> (istream& is, Mathang& temp) {
            fflush(stdin);
            cout << "\t + Nhap ma hang: ";
            getline(is, temp.mahang);
            cout << "\t + Nhap ten hang: ";
            getline(is, temp.tenhang);
            cout << "\t + Nhap don gia: ";
            is >> temp.dongia;
            return is;
        }
        string getmahang() {
            return this->mahang;
        }
        string gettenhang() {
            return this->tenhang;
        }
        float getdongia() {
            return this->dongia;
        }
};

class Banhkeo : public Mathang {
    private:
        string noisanxuat;
    public:
        Banhkeo() : Mathang() {
            this->noisanxuat = "";
        }
        Banhkeo(string mahang, string tenhang, float dongia, string noisanxuat) : Mathang(mahang, tenhang, dongia) {
            this->noisanxuat = noisanxuat;
        }
        float tinhchietkhau() {
            return this->getdongia() * 0.01;
        }
        friend istream &operator >> (istream& is, Banhkeo& temp) {
            is >> (Mathang&)temp;
            fflush(stdin);
            cout << "\t + Nhap noi san xuat: ";
            getline(is, temp.noisanxuat);
            return is;
        }
        friend ostream &operator << (ostream& os, Banhkeo temp) {
            os << left << setw(30) << temp.getmahang();
            os << left << setw(30) << temp.gettenhang();
            os << left << setw(30) << temp.getdongia();
            os << left << setw(30) << temp.noisanxuat;
            return os;
        }
        friend bool operator > (Banhkeo a, Banhkeo b) {
            return a.getdongia() > b.getdongia();
        }
        bool operator != (string a) {
            return this->getmahang() != a;
        }
        bool operator == (string a) {
            return this->getmahang() == a;
        }
        string getnoisanxuat() {
            return this->noisanxuat;
        }
};

void title() {
    cout << left << setw(30) << "Ma hang";
    cout << left << setw(30) << "Ten hang";
    cout << left << setw(30) << "Don gia";
    cout << left << setw(30) << "Noi san xuat" << endl;
}

bool tmp(Banhkeo a, Banhkeo b) {
    return a > b;
}

int main() {
    int n;
    cout << "Nhap so luong doi tuong banh keo la: ";
    cin >> n;
    vector<Banhkeo> bk;
    for (int i = 0; i < n; i++) {
        Banhkeo temp;
        cout << "Nhap thong tin banh keo thu " << i + 1 << " la: " << endl;
        cin >> temp;
        bk.push_back(temp);
    }
    cout << "Danh sach banh keo vua nhap la: " << endl;
    title();
    for(Banhkeo temp : bk) {
        cout << temp << endl;
    }
    cout << "Danh sach banh keo co ma khac MO1 la: " << endl;
    for(Banhkeo temp : bk) {
        if(temp != "MO1")
        cout << temp << endl;
    }
    string st;
    cout << "Nhap ma hang can tim la: ";
    getline(cin, st);
    cout << "Danh sach ma hang can tim la: " << endl;
    title();
    for(Banhkeo temp : bk) {
        if(temp == st)
        cout << temp << endl;
    }
    int count = 0;
    for(Banhkeo temp : bk) {
        if(temp == "Banh ngot" && temp.getnoisanxuat() == "Bac Ninh")
        count ++;
    }
    cout << "So luong mat hang co ten la Banh ngot va san xuat o Bac Ninh la: " << count << endl;
    sort(bk.begin(), bk.end(), tmp);
    cout << "Danh sach sau khi sap xep la: " << endl;
    title();
    for(Banhkeo temp : bk) {
        cout << temp << endl;
    }
    return 0;
}