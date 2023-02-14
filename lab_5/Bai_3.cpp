#include<iostream>
#include<cstring>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;

class MayIn {
    private:
        string soHieu;
        int soLuong;
    public:
        void input() {
            fflush(stdin);
            cout << "\t Nhap so hieu: ";
            getline(cin, this->soHieu);
            cout << "\t Nhap so luong: ";
            cin >> this->soLuong;
        }
        void output() {
            cout << left << setw(30) << this->soHieu;
            cout << left << setw(30) << this->soLuong;
        }
        void nhapKho(int q) {
            this->soLuong += q;
        }
        void xuatKho(int q) {
            this->soLuong -= q;
        }
};

class MayLaser : public virtual MayIn {
    private:
        int dpi;
    public:
        void input() {
            MayIn::input();
            cout << "\t Nhap dpi: ";
            cin >> this->dpi;
        }
        void output() {
            MayIn::output();
            cout << left << setw(30) << this->dpi;
        }
};

class MayMau : public virtual MayIn {
    private:
        int bangMau;
    public:
        void input() {
            MayIn::input();
            cout << "\t Nhap bang mau: ";
            cin >> this->bangMau;
        }
        void output() {
            MayIn::output();
            cout << left << setw(30) << this->bangMau;
        }
        int getBangMau() {
            return this->bangMau;
        }
};

class MayLaserMau : public MayLaser, public MayMau {
    public:
        void inputMayLaserMau() {
            MayLaser::input();
            MayMau::input();
        }
        void outputMayLaserMau() {
            MayLaser::input();
            cout << left << setw(30) << this->getBangMau();
        }
};

int main() {
    MayLaser laser;
    laser.input();
    MayMau mau;
    mau.input();
    MayLaserMau laserMau;
    laserMau.inputMayLaserMau();
    laser.output();
    cout << endl;
    mau.output();
    cout << endl;
    laserMau.outputMayLaserMau();
    return 0;
}