#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
using namespace std;

class MAYTINH {
    private:
        string mahang;
        string tenhang;
        float dongia;
        int ram;
        float trongluong;
    public:
        MAYTINH(string mahang = " ", string tenhang = " ", float dongia = 0, int ram = 0, float trongluong = 0) {
            this->mahang = mahang;
            this->tenhang = tenhang;
            this->dongia = dongia;
            this->ram = ram;
            this->trongluong = trongluong;
        }
        ~MAYTINH() {}
        friend istream& operator >> (istream& is, MAYTINH& temp) {
            fflush(stdin);
            cout << "\t+ Nhap ma hang: ";
            getline(cin, temp.mahang);
            cout << "\t+ Nhap ten hang san suat: ";
            getline(cin, temp.tenhang);
            cout << "\t+ Nhap don gia: ";
            cin >> temp.dongia;
            cout << "\t+ Nhap dung luong bo nho RAM: ";
            cin >> temp.ram;
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

        friend ostream& operator << (ostream& os, MAYTINH temp) {
            cout << left << setw(30) << temp.mahang;
            cout << left << setw(30) << temp.tenhang;
            cout << left << setw(30) << temp.dongia;
            cout << left << setw(30) << temp.ram;
            cout << left << setw(30) << temp.trongluong;
            cout << left << setw(30) << temp.tinhTien();
            return os;
        }

        int getRam() {
            return this->ram;
        }

        string getTenHang() {
            return this->tenhang;
        }
};

int main() {
    int n;
    cout << "Nhap so luong may tinh can luu tru la: ";
    cin >> n;
    vector<MAYTINH> mts(n);
    for (int i = 0; i < n; i++) {
        cout << "Thong tin may tinh thu " << i + 1 << " la:" << endl;
        cin >> mts[i];
    }
    bool checkRam = false;
    cout << "Hien thi danh sach may tinh co dung luong bo nho RAM = 16 la: " << endl;
    for(MAYTINH mt : mts) {
        if(mt.getRam() == 16) {
            cout << mt << endl;
            checkRam = true;
        }
    }
    if(!checkRam) {
        cout << "Khong co may tinh nao co dung luong bo nho RAM = 16." << endl;
    }
    bool checkTenHang = false;
    string setTenHang;
    fflush(stdin);
    cout << "Nhap vao ten hang san suat can tim la: ";
    getline(cin, setTenHang);
    int j = 0;
    for(MAYTINH mt : mts) {
        if(mt.getTenHang() == setTenHang) {
            mts.erase(mts.begin() + j);
            checkTenHang = true;
        }
        j++;
    }
    if(!checkTenHang) {
        MAYTINH temp;
        cout << "Nhap thong tin can chen la: " << endl;
        cin >> temp;
        mts.insert(mts.begin(), temp);
        for(MAYTINH mt : mts) {
            cout << mt << endl;
        }
    }
    return 0;
}