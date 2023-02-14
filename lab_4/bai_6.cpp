#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;

class PET {
    private:
        int tuoi;
        float cannang;
    public:
        void settuoi(int tuoi) {
            this->tuoi = tuoi;
        }
        void setcannang(float cannang) {
            this->cannang = cannang;
        }
        int gettuoi() {
            return this->tuoi;
        }
        float getcannang() {
            return this->cannang;
        }
};

class DOG : public PET {
    private:
        string maumat, sothich;
    public:
        friend istream& operator >> (istream& is, DOG& obj) {
            int tuoiVar;
            cout << "\t + Nhap tuoi: ";
            is >> tuoiVar;
            obj.settuoi(tuoiVar);
            float cannangVar;
            cout << "\t + Nhap can nang: ";
            is >> cannangVar;
            obj.setcannang(cannangVar);
            fflush(stdin);
            cout << "\t + Mau mat: ";
            getline(is, obj.maumat);
            cout << "\t + So thich: ";
            getline(is, obj.sothich);
            return is;
        }
        friend ostream& operator << (ostream& os, DOG obj) {
            os << left << setw(30) << obj.gettuoi();
            os << left << setw(30) << obj.getcannang();
            os << left << setw(30) << obj.maumat;
            os << left << setw(30) << obj.sothich;
            return os;
        }
        bool operator < (DOG b) {
            return this->getcannang() < b.getcannang();
        }
};

bool cmp(DOG a, DOG b) {
    return a < b;
}

int main() {
    int n;
    cout << "Nhap so luong doi tuong dog la: ";
    cin >> n;
    vector<DOG> d;
    for (int i = 0; i < n; i++) {
        DOG temp;
        cout << "Nhap thong tin cua doi tuong dog thu " << i + 1 << " la:" << endl;
        cin >> temp;
        d.push_back(temp);
    }
    cout << "Danh sach sau khi sap xep theo chieu tang dan cua can nang la:" << endl;
    sort(d.begin(), d.end(), cmp);
    for(DOG temp : d) {
        cout << temp << endl;
    }
    bool check = false;
    cout << "Danh sach doi tuong dog co tuoi tu 2 den 5 tuoi la: " << endl;
    for(DOG temp : d) {
        if(2 <= temp.gettuoi() && temp.gettuoi() <= 5) {
            cout << temp << endl;
            check = true;
        }
    }
    if(check == false) {
        cout << "Khong co doi tuong dog nao thoa man." << endl;
    }
    float sum = 0;
    for(DOG temp : d) {
        sum += temp.getcannang();
    }
    cout << "Tong can nang cua tat ca doi tuong dog la: " << sum << endl;
    return 0;
}