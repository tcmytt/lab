#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

bool nam_nhuan(int year)
{
    if (year % 100 == 0)
     
    {
        if (year % 400 == 0){
            return true;
        }
        else{
            return false;
        }
    }
    else if (year % 4 == 0) {
        return true;
    }
    else{
        return false;
    }
}

class NgayThi {
    private:
        int ngay, thang, nam;
    public:
        void nhap() {
            cout << "\t+ Nhap nam: ";
            do {
                cin >> this->nam;
                if (this->nam < 1) {
                    cout << "\t=>Nhap sai yeu cau nhap lai: ";
                }
            } while (this->nam < 1);
            cout << "\t+ Nhap thang: ";
            do {
                cin >> this->thang;
                if (this->thang < 1 && this->thang > 12) {
                    cout << "\t=>Nhap sai yeu cau nhap lai: ";
                }
            } while (this->thang < 1 && this->thang > 12);
            cout << "\t+ Nhap ngay: ";
            switch (this->thang) {
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    do {
                        cin >> this->ngay;
                        if (this->ngay < 1 && this->ngay > 31) {
                            cout << "\t=>Nhap sai yeu cau nhap lai: ";
                        }
                    } while (this->ngay < 1 && this->ngay > 31);
                    break;
                case 4:
                case 6:
                case 9:
                case 11:
                    do {
                        cin >> this->ngay;
                        if (this->ngay < 1 && this->ngay > 30) {
                            cout << "\t=>Nhap sai yeu cau nhap lai: ";
                        }
                    } while (this->ngay < 1 && this->ngay > 30);
                    break;
                case 2:
                    if (nam_nhuan(this->nam)) {
                        do {
                            cin >> this->ngay;
                            if (this->ngay < 1 && this->ngay > 29) {
                                cout << "\t=>Nhap sai yeu cau nhap lai: ";
                            }
                        } while (this->ngay < 1 && this->ngay > 29);
                    } else {
                        do {
                            cin >> this->ngay;
                            if (this->ngay < 1 && this->ngay > 28) {
                                cout << "\t=>Nhap sai yeu cau nhap lai: ";
                            }
                        } while (this->ngay < 1 && this->ngay > 28);
                    }
            }
        }
        void xuat() {
            cout << this->ngay << "/" << this->thang << "/" << this->nam;
        }
};

class VLEAGUE {
    public:
        virtual void nhap() = 0;
        virtual void xuat() = 0;
};

class Cauthu : public VLEAGUE {
    private:
        int cmnd;
        string hoten;
        string quoctich;
        int ngaysinh;
        int chieucao;
        int cannang;
        string vitri;
    public:
        void nhap() {
            cout << "\t+ Nhap cmnd: ";
            cin >> this->cmnd;
            cout << "\t+ Nhap ho ten: ";
            getline(cin, this->hoten);
            cout << "\t+ Nhap quoc tich: ";
            getline(cin, this->quoctich);
            cout << "\t+ Nhap ngay sinh: ";
            cin >> this->ngaysinh;
            cout << "\t+ Nhap chieu cao: ";
            cin >> this->chieucao;
            cout << "\t+ Nhap can nang: ";
            cin >> this->cannang;
            cout << "\t+ Nhap vi tri: ";
            getline(cin, this->vitri);
        }

        void xuat() {
            cout << "CMND: " << this->cmnd << ", HOTEN: " << this->hoten << ", QUOCTICH: " << this->quoctich;
            cout << ", NGAYSINH: " << this->quoctich << ", CHIEUCAO: " << this->chieucao << ", CANNANG: " << this->cannang << endl;
        }
};

class Doibong : public VLEAGUE, Cauthu {
    private:
        string tendoi;
        string diaphuong;
        string huanluyen;
        Cauthu dscauthu;
    public:
        void nhap() {
            cout << "\t+ Nhap ten doi bong: ";
            getline(cin, this->tendoi);
            cout << "\t+ Nhap dia phuong: ";
            getline(cin, this->diaphuong);
            cout << "\t+ Nhap huan luyen vien: ";
            getline(cin, this->huanluyen);
            dscauthu.nhap();
        }
};

class TranDau : public VLEAGUE {
    private:
        NgayThi ngayThi;
        string santhi;
        string tendbong1;
        string tendbong2;
        int ts1;
        int ts2;
    public:
        void nhap() {
            ngayThi.nhap();
            cout << "\t+ Nhap san thi dau: ";
            getline(cin, this->santhi);
            cout << "\t+ Nhap ten doi bong 1: ";
            getline(cin, this->tendbong1);
            cout << "\t+ Nhap ten doi bong 2: ";
            getline(cin, this->tendbong2);
            cout << "\t+ Nhap ti so 1: ";
            cin >> this->ts1;
            cout << "\t+ Nhap ti so 2: ";
            cin >> this->ts2;
        }
        void xuat() {
            cout << "Ngay thi: ";
            this->ngayThi.xuat();
            cout << ", ten san thi dau: " << this->santhi << ", ten 2 doi bong: " << this->tendbong1 << " - " << this->tendbong2;
            cout << ", ti so: " << this->ts1 << " - " << this->ts2;
        }
};

int main() {

    return 0;
}