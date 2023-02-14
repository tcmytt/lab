#include<iostream>
#include<cstring>
#include<iomanip>
#include<vector>
using namespace std;

class NgayGD {
    private:
        int ngay, thang, nam;
    public:
        void setNgay(int ngay) {
            this->ngay = ngay;
        }
        void setThang(int thang) {
            this->thang = thang;
        }
        void setNam(int nam) {
            this->nam = nam;
        }
        int getNgay() {
            return this->ngay;
        }
        int getThang() {
            return this->thang;
        }
        int getNam() {
            return this->nam;
        }
};

class NhaDat {
    private:
        string magd;
        NgayGD ngayGD;
        float dongia;
    public:
        virtual void nhap() {
            fflush(stdin);
            cout << "\t+ Nhap ma giao dich: ";
            getline(cin, this->magd);
            do {
                int ngay;
                cout << "\t+ Nhap ngay giao dich: ";
                cin >> ngay;
                ngayGD.setNgay(ngay);
                if (ngayGD.getNgay() < 1 || ngayGD.getNgay() > 31) {
                    cout << "\t\tNhap sai!!! Yeu cau nhap lai.";
                }
                
            } while (ngayGD.getNgay() < 1 || ngayGD.getNgay() > 31);
            do {
                int thang;
                cout << "\t+ Nhap thang giao dich: ";
                cin >> thang;
                ngayGD.setThang(thang);
                if (ngayGD.getThang() < 1 || ngayGD.getThang() > 12) {
                    cout << "\t\tNhap sai!!! Yeu cau nhap lai.";
                }
                
            } while (ngayGD.getThang() < 1 || ngayGD.getThang() > 12);
            do {
                int nam;
                cout << "\t+ Nhap nam giao dich: ";
                cin >> nam;
                ngayGD.setNam(nam);
                if (ngayGD.getNam() < 1) {
                    cout << "\t\tNhap sai!!! Yeu cau nhap lai.";
                }
            } while (ngayGD.getNam() < 1);
            cout << "\t+ Nhap don gia: ";
            cin >> this->dongia;
        }
        virtual void xuat() {
            cout << left << setw(30) << this->magd;
            cout << left << setw(30) << this->ngayGD.getNgay() << "/" << this->ngayGD.getThang() << "/" << this->ngayGD.getNam();
            cout << left << setw(30) << this->dongia;
        }
        virtual float thanhtien() = 0;
        virtual int ID() = 0;
        float getdongia() {
            return this->dongia;
        }
        int getthang() {
            return this->ngayGD.getThang();
        }
        int getnam() {
            return this->ngayGD.getNam();
        }
};

class Dat : public NhaDat {
    private:
        string loaidat;
        float dientich;
    public:
        void nhap() {
            NhaDat::nhap();
            cout << "\t+ Chon loai dat: 1.A     2.B     3.C.";
            int choose;
            do {
                cout << "\n\t\tMoi ban nhap lua chon: ";
                cin >> choose;
                if (choose < 1 || choose > 3) {
                    cout << "\t\tNhap sai!!! Yeu cau nhap lai.";
                }
            } while (choose < 1 || choose > 3);
            switch (choose) {
                case 1:
                    this->loaidat = "A";
                    break;
                case 2:
                    this->loaidat = "B";
                    break;
                default:
                    this->loaidat = "C";
                    break;
            }
            do {
                cout << "\t+ Nhap dien tich: ";
                cin >> this->dientich;
                if (this->dientich < 1) {
                    cout << "\t\tNhap sai!!! Yeu cau nhap lai.";
                }
            } while (this->dientich < 1);
        }
        void xuat() {
            NhaDat::xuat();
            cout << left << setw(30) << this->loaidat;
            cout << left << setw(30) << this->dientich;
            cout << left << setw(30) << this->thanhtien();
        }
        float thanhtien() {
            return this->loaidat == "A" ? this->dientich * this->getdongia() * 1.5 : this->dientich * this->getdongia();
        }
        int ID() {
            return 1;
        }
};

class Nha : public NhaDat {
    private:
        string loainha;
        string diachi;
        float dientich;
    public:
        void nhap() {
            NhaDat::nhap();
            cout << "\t+ Chon loai nha: 1.Cao cap     2.Thuong.";
            int choose;
            do {
                cout << "\n\t\tMoi ban nhap lua chon: ";
                cin >> choose;
                if (choose < 1 || choose > 3) {
                    cout << "\t\tNhap sai!!! Yeu cau nhap lai.";
                }
            } while (choose < 1 || choose > 3);
            switch (choose) {
                case 1:
                    this->loainha = "cao cap";
                    break;
                default:
                    this->loainha = "thuong";
                    break;
            }
            fflush(stdin);
            cout << "\t+ Nhap dia chi: ";
            getline(cin, this->diachi);
            do {
                cout << "\t+ Nhap dien tich: ";
                cin >> this->dientich;
                if (this->dientich < 1) {
                    cout << "\t\tNhap sai!!! Yeu cau nhap lai.";
                }
            } while (this->dientich < 1);
        }
        void xuat() {
            NhaDat::xuat();
            cout << left << setw(30) << this->loainha;
            cout << left << setw(30) << this->dientich;
            cout << left << setw(30) << this->thanhtien();
        }
        float thanhtien() {
            return this->loainha == "thuong" ? this->dientich * this->getdongia() * 0.9 : this->dientich * this->getdongia();
        }
        int ID() {
            return 2;
        }
};

int main() {
    vector<NhaDat *> a;
    int n;
    cout << "Nhap so luong nha dat: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin nha dat thu " << i + 1 << " la:" << endl;
        cout << "Lua chon:" << endl;
        cout << "\t1. Giao dich dat." << endl;
        cout << "\t2. Giao dich nha." << endl;
        int choose;
        do {
            cout << "Moi ban nhap lua chon: ";
            cin >> choose;
            if (choose < 1 || choose > 2) {
                cout << "Nhap sai!!! Yeu cau nhap lai.";
            }
        } while (choose < 1 || choose > 2);
        if (choose == 1) {
            NhaDat *temp1 = new Dat();
            temp1->nhap();
            a.push_back(temp1);
        } else {
            NhaDat *temp2 = new Nha();
            temp2->nhap();
            a.push_back(temp2);
        }
    }
    int sumNha = 0;
    int sumDat = 0;
    for(NhaDat *temp : a) {
        temp->ID() == 1 ? sumDat++ : sumNha++;
    }
    cout << "So luong giao dich nha la: " << sumNha << endl;
    cout << "So luong giao dich dat la: " << sumDat << endl;
    float Sumthanhtien = 0;
    for(NhaDat *temp : a) {
        if (temp->ID() == 1) {
            Sumthanhtien += temp->thanhtien();
        }
    }
    cout << "Trung binh thanh tien cua giao dich dat la: " << Sumthanhtien << endl;
    cout << "Xuat ra cac giao dich cua thang 9 nam 2013 la: " << endl;
    for (NhaDat *temp : a) {
        if (temp->getthang() == 9 && temp->getnam() == 2013) {
            temp->xuat();
        }
    }
    return 0;
}