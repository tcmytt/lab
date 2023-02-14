#include<iostream>
#include<cstring>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;

class BenhNhan {
    private:
        string ten;
        string que;
        int nam;
    public:
        void nhap() {
            fflush(stdin);
            cout << "\t + Nhap ho ten: ";
            getline(cin, this->ten);
            cout << "\t + Nhap que quan: ";
            getline(cin, this->que);
            cout << "\t + Nhap nam sinh: ";
            cin >> this->nam;
        }
        void xuat() {
            cout << left << setw(30) << this->ten;
            cout << left << setw(30) << this->que;
            cout << left << setw(30) << this->nam;
        }
        int getnam() {
            return this->nam;
        }
};

class BenhAn : public BenhNhan {
    private:
        string tenbenhan;
        float tien;
    public:
        void nhap() {
            BenhNhan::nhap();
            fflush(stdin);
            cout << "\t + Nhap ten benh an: ";
            getline(cin, this->tenbenhan);
            cout << "\t + Nhap so tien vien phi: ";
            cin >> this->tien;
        }
        void xuat() {
            BenhNhan::xuat();
            cout << left << setw(30) << this->tenbenhan;
            cout << left << setw(30) << this->tien << endl;
        }
        int tinhtuoi() {
            return 2022 - this->getnam();
        }

        float gettien() {
            return this->tien;
        }
};

void title() {
    cout << left << setw(30) << "Ho ten";
    cout << left << setw(30) << "Que quan";
    cout << left << setw(30) << "Nam sinh";
    cout << left << setw(30) << "Ten benh an";
    cout << left << setw(30) << "Tien vien phi" << endl;
}

bool sosanh(BenhAn a, BenhAn b) {
    if(a.tinhtuoi() > b.tinhtuoi()) {
        return true;
    }
    return false;
}

int main() {
    int n;
    cout << "Nhap so luong benh an la: ";
    cin >> n;
    vector<BenhAn> a;
    for (int i = 0; i < n; i++) {
        BenhAn temp;
        cout << "Nhap thong tin benh an thu " << i + 1 << " la:" << endl;
        temp.nhap();
        a.push_back(temp);
    }
    sort(a.begin(), a.end(), sosanh);
    cout << "Danh sach sau khi sap xep la:" << endl;
    title();
    for(BenhAn temp : a) {
        temp.xuat();
    }
    cout << "Danh sach benh an cua benh nhan co tuoi > 50 la:" << endl;
    for(BenhAn temp : a) {
        if(temp.tinhtuoi() > 50) {
            temp.xuat();
        }
    }
    float max = 0;
    for (int i = 0; i < n; i++)
    {
        if(max < a[i].gettien()) {
            max = a[i].gettien();
        }
    }
    cout << "Hien thi benh an co vien phi lon nhat la:" << endl;
    title();
    for(BenhAn temp : a) {
        if(max == temp.gettien()) {
            temp.xuat();
        }
    }
    return 0;
}