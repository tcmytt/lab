#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
using namespace std;

class OTO {
    private:
        string mahang;
        string tenhang;
        float dongia;
        float xilanh;
        float trongluong;
    public:
        OTO(string mahang = " ", string tenhang = " ", float dongia = 0, float xilanh = 0, float trongluong = 0) {
            this->mahang = mahang;
            this->tenhang = tenhang;
            this->dongia = dongia;
            this->xilanh = xilanh;
            this->trongluong = trongluong;
        }
        ~OTO() {}
        friend istream& operator >> (istream& is, OTO& temp) {
            fflush(stdin);
            cout << "\t+ Nhap ma hang: ";
            getline(cin, temp.mahang);
            cout << "\t+ Nhap ten hang san suat: ";
            getline(cin, temp.tenhang);
            cout << "\t+ Nhap don gia: ";
            cin >> temp.dongia;
            cout << "\t+ Nhap dung luong bo nho xilanh: ";
            cin >> temp.xilanh;
            cout << "\t+ Nhap trong luong: ";
            cin >> temp.trongluong;
            return is;
        }

        float tinhTien() {
            if(this->trongluong > 2) {
                return 100000;
            }
            else if(this->trongluong > 1 && this->trongluong <= 2) {
                return 50000;
            }
            return 30000;
        }

        friend ostream& operator << (ostream& os, OTO temp) {
            cout << left << setw(30) << temp.mahang;
            cout << left << setw(30) << temp.tenhang;
            cout << left << setw(30) << temp.dongia;
            cout << left << setw(30) << temp.xilanh;
            cout << left << setw(30) << temp.trongluong;
            cout << left << setw(30) << temp.tinhTien();
            return os;
        }

        float getxilanh() {
            return this->xilanh;
        }

        string getTenHang() {
            return this->tenhang;
        }

        friend bool operator == (OTO a, OTO b) {
            return (a.getxilanh() == b.getxilanh());
        }
};

int main() {
    float n;
    cout << "Nhap so luong may tinh can luu tru la: ";
    cin >> n;
    vector<OTO> otos(n);
    for (float i = 0; i < n; i++) {
        cout << "Thong tin may tinh thu " << i + 1 << " la:" << endl;
        cin >> otos[i];
    }
    bool checkxilanh = false;
    cout << "Hien thi danh sach may tinh co dung luong bo nho xilanh = 16 la: " << endl;
    for(OTO oto : otos) {
        if(oto.getxilanh() == 2.5) {
            cout << oto << endl;
            checkxilanh = true;
        }
    }
    if(!checkxilanh) {
        cout << "Khong co may tinh nao co dung luong bo nho xilanh = 16." << endl;
    }
    bool checkTenHang = false;
    string setTenHang;
    fflush(stdin);
    cout << "Nhap vao ten hang san suat can tim la: ";
    getline(cin, setTenHang);
    float j = 0;
    for(OTO oto : otos) {
        if(oto.getTenHang() == setTenHang) {
            otos.erase(otos.begin() + j);
            checkTenHang = true;
        }
        j++;
    }
    if(!checkTenHang) {
        OTO temp;
        cout << "Nhap thong tin can chen la: " << endl;
        cin >> temp;
        otos.insert(otos.begin(), temp);
        for(OTO oto : otos) {
            cout << oto << endl;
        }
    }
    return 0;
}