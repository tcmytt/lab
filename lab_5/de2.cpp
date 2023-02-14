#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
using namespace std;

class Oto {
    private:
        string hangXe, mau;
        int soGhe;
    public:
        Oto(string hangXe, string mau, int soGhe) {
            this->hangXe = hangXe;
            this->mau = mau;
            this->soGhe = 0;
        }
        ~Oto() {}
        friend istream &operator >> (istream& is, Oto& temp) {
            fflush(stdin);
            cout << "\t +Nhap ten hang xe: ";
            getline(is, temp.hangXe);
            cout << "\t +Nhap mau xe: ";
            getline(is, temp.mau);
            cout << "\t +Nhap so ghe: ";
            is >> temp.soGhe;
            return is;
        }

        friend ostream &operator << (ostream& os, Oto temp) {
            cout << left << setw(30) << temp.hangXe;
            cout << left << setw(30) << temp.mau;
            cout << left << setw(30) << temp.soGhe;
            return os;
        }

        int getSoGhe() {
            return this->soGhe;
        }

        string getMau() {
            return this->mau;
        }
};

void tieuDe() {
    cout << left << setw(30) << "Hang Xe";
    cout << left << setw(30) << "Mau";
    cout << left << setw(30) << "So Ghe" << endl;
}

void Nhap(int n, vector<Oto>& otos) {
    for(int i = 0; i < n; i++) {
        cout << "Nhap thong tin o to thu " << i + 1 << " la:" << endl;
        Oto temp(" ", " ", 0);
        cin >> temp;
        otos.push_back(temp);
    }
}

void SreachSoGhe(int n, vector<Oto> otos) {
    bool checkSoGhe = false;
    cout << "Danh sach o to co so ghe la 4:" << endl;
    for(Oto oto : otos) {
        if(oto.getSoGhe() == 4) {
            if(checkSoGhe == false) {
                tieuDe();
            }
            checkSoGhe = true;
            cout << oto << endl;
        }
    }
    if(checkSoGhe == false) {
        cout << "Khong co o to nao co so ghe bang 4." << endl;
    }
}

void SreachMauGhe(int n, vector<Oto> otos) {
    bool checkMau = false;
    cout << "Danh sach o to mau do la:" << endl;
    for(Oto oto : otos) {
        if(oto.getMau() == "Do") {
            if(checkMau == false) {
                tieuDe();
            }
            checkMau = true;
            cout << oto << endl;
        }
    }
    if(checkMau == false) {
        cout << "Khong co o to nao mau do." << endl;
    }
}

void ThemOto(int n, vector<Oto>& otos) {
    int k;
    cout << "\nNhap vi tri thu k can them la: ";
    do {
        cin >> k;
        if(k > otos.size() || k <= 0) {
            cout << "Khong co vi tri nay trong danh sach." << endl;
            cout << "Moi ban nhap lai: ";
        }
    } while (k > otos.size() || k <= 0);
    Oto temp(" ", " ", 0);
    cout << "Thong tin o to can them la:" << endl;
    cin >> temp;
    otos.insert(otos.begin() + k - 1, temp);
    cout << "Danh sach sau khi them la:" << endl;
    tieuDe();
    for(Oto oto : otos) {
        cout << oto << endl;
    }
}

int main() {
    int n;
    cout << "Nhap so luong o to can luu tru la: ";
    do {
        cin >> n;
        if(n < 0) {
            cout << "Nhap sai. Yeu cau nhap lai: ";
        }
    } while(n < 0);
    vector<Oto> otos;
    Nhap(n, otos);
    SreachSoGhe(n, otos);
    SreachMauGhe(n, otos);
    ThemOto(n, otos);
    return 0;
}