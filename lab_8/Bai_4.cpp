#include<iostream>
#include<cstring>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;

class NgayGiaoDich {
    private:
        int ngay, thang, nam;
    public:
        void nhapNgayGiaoDich() {
            cout << "\t+ Nhap ngay giao dich: ";
            cin >> this->ngay;
            cout << "\t+ Nhap thang giao dich: ";
            cin >> this->thang;
            cout << "\t+ Nhap nam giao dich: ";
            cin >> this->nam;
        }
        void xuatNgayGiaoDich() {
            cout << this->ngay << "/" << this->thang << "/" << this->nam;
        }
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

class GiaoDich {
    private:
        string maGiaoDich;
        NgayGiaoDich ngayGiaoDich;
        float donGia;
        int soLuong;
    public:
        virtual void nhap() {
            fflush(stdin);
            cout << "\t+ Nhap ma giao dich: ";
            getline(cin, this->maGiaoDich);
            this->ngayGiaoDich.nhapNgayGiaoDich();
            cout << "\t+ Nhap don gia: ";
            cin >> this->donGia;
            cout << "\t+ Nhap so luong: ";
            cin >> this->soLuong;
        }

        virtual void xuat() {
            cout << setw(30) << left << this->maGiaoDich;
            cout << setw(30) << left; this->ngayGiaoDich.xuatNgayGiaoDich();
            cout << setw(30) << left << this->donGia;
            cout << setw(30) << left << this->soLuong;
        }

        virtual float thanhTien() = 0;

        int getSoLuong() {
            return this->soLuong;
        }

        float getDonGia() {
            return this->donGia;
        }

        string getNgayGiaoDich() {
            return to_string(this->ngayGiaoDich.getNgay()) + "/" + to_string(this->ngayGiaoDich.getThang()) + "/" + to_string(this->ngayGiaoDich.getNam());
        }

        virtual int id() = 0;
};

class GiaoDichVang : public GiaoDich {
    private:
        string loaiVang;
    public:
        void nhap() {
            GiaoDich::nhap();
            fflush(stdin);
            cout << "\t Nhap loai vang: ";
            getline(cin, this->loaiVang);
        }
        void xuat() {
            GiaoDich::xuat();
            cout << setw(30) << left << this->loaiVang;
        }
        float thanhTien() {
            return this->getSoLuong() * this->getDonGia();
        }
        int id() {
            return 1;
        }
};

class GiaoDichTienTe : public GiaoDich {
    private:
        float tiGia;
        string loaiTienTe;
    public:
        void nhap() {
            GiaoDich::nhap();
            cout << "\t+ Nhap ti gia: ";
            cin >> this->tiGia;
            bool check = true;
            fflush(stdin);
            cout << "\t+ Nhap loai tien(VietNam, USD, Euro): ";
            while(check == true) {
                getline(cin, this->loaiTienTe);
                transform(this->loaiTienTe.begin(), this->loaiTienTe.end(), this->loaiTienTe.begin(), ::toupper);
                if (this->loaiTienTe != "VIETNAM" && this->loaiTienTe != "USD" && this->loaiTienTe != "EURO") {
                    cout << "Loai tien vua nhap khong co! Moi ban nhap lai: ";
                } else {
                    check = false;
                }
            }
        }
        void xuat() {
            GiaoDich::xuat();
            cout << setw(30) << left << this->tiGia;
            cout << setw(30) << left << this->loaiTienTe;
        }

        float thanhTien() {
            if (this->loaiTienTe == "VIETNAM") {
                return this->getDonGia() * this->getSoLuong();
            } else {
                return this->getDonGia() * this->getSoLuong() * this->tiGia;
            }
        }
        int id() {
            return 2;
        }
};

void menu() {
        cout<<"-------------------------------------------------------"<<endl;
		cout<<"								MENU					"<<endl;
		cout<<"1.Nhap xuat danh sach cac loai giao dich."<<endl;
		cout<<"2.Tinh tong so luong cho tung loai."<<endl;
		cout<<"3.Tinh trung binh thanh tien cua giao dich tien te."<<endl;
		cout<<"4.Xuat ra cac giao dich co don gia > 1 ty."<<endl;
		cout<<"5.Dem nhung giao dich vang ngay 20/3/2015."<<endl;
		cout<<"6.Sap xep danh sach theo chieu giam cua ngay giao dich."<<endl;
		cout<<"7.Them giao dich vao cuoi danh sach."<<endl;
		cout<<"8.Xoa giao dich vang ngay 20/5/2010."<<endl;
		cout<<"--------------------------------------------------------"<<endl;
		cout<<endl;
}

void nhapGiaoDich(vector<GiaoDich*> &gd) {
    int n;
    cout << "Nhap so luong giao dich: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin giao dich thu " << i + 1 << " la:" << endl;
        int choose;
        cout << "1. Chon giao dich vang." << endl;
        cout << "2. Chon giao dich tien te." << endl;
        cout << "Moi ban nhap lua chon: ";
        do {
            cin >> choose;
            if (choose != 1 && choose != 2) {
                cout << "Nhap sai! Yeu cau nhap lai: ";
            }
        } while (choose != 1 && choose != 2);
        if (choose == 1) {
            GiaoDich *temp = new GiaoDichVang();
            temp->nhap();
            gd.push_back(temp);
        } else {
            GiaoDich *temp = new GiaoDichTienTe();
            temp->nhap();
            gd.push_back(temp);
        }
    }
}

void xuatGiaoDich(vector<GiaoDich*> gd) {
    for(GiaoDich *temp : gd) {
        temp->xuat();
        cout << endl;
    }
}

void tinhTongTungLoai(vector<GiaoDich*> gd) {
    int sumGiaoDichVang = 0;
    int sumGiaoDichTienTe = 0;
    for (GiaoDich* temp : gd) {
        if (temp->id() == 1) {
            sumGiaoDichVang ++;
        } else {
            sumGiaoDichTienTe ++;
        }
    }
    cout << "Tong so luong giao dich vang la: " << sumGiaoDichVang << endl;
    cout << "Tong so luong giao dich tien te la: " << sumGiaoDichTienTe << endl;
}

float tinhTrungBinhGDTienTe(vector<GiaoDich*> gd) {
    float tinhTrungBinhGDTienTe = 0;
    int sumGiaoDichTienTe = 0;
    for(GiaoDich *temp : gd) {
        if (temp->id() == 2) {
            sumGiaoDichTienTe ++;
            tinhTrungBinhGDTienTe += temp->thanhTien();
        }
    }
    return tinhTrungBinhGDTienTe * 1.0 / sumGiaoDichTienTe;
}

void xuatGiaoDichDonGiaLonHon1Ty(vector<GiaoDich*> gd) {
    for(GiaoDich *temp : gd) {
        if (temp->getDonGia() > 1000) {
            temp->xuat();
            cout << endl;
        }
    }
}

int demGiaoDichVangNgay20032015(vector<GiaoDich*> gd) {
    int dem = 0;
    for(GiaoDich *temp : gd) {
        if(temp->getNgayGiaoDich() == "20/03/2015") {
            dem++;
        }
    }
    return dem;
}

bool cmp(GiaoDich *a, GiaoDich *b) {
    if(a->getNgayGiaoDich() < b->getNgayGiaoDich()) {
        return false;
    }
    return true;
}

void sapXep(vector<GiaoDich*> &gd) {
    sort(gd.begin(), gd.end(), cmp);
    cout << "Danh sach sau khi sap xep." << endl;
    xuatGiaoDich(gd);
}

void themGiaoDich(vector<GiaoDich*> &gd) {
    cout << "Them giao dich vao cuoi danh sach." << endl;
    int choose;
        cout << "1. Chon giao dich vang." << endl;
        cout << "2. Chon giao dich tien te." << endl;
        cout << "Moi ban nhap lua chon: ";
        do {
            cin >> choose;
            if (choose != 1 && choose != 2) {
                cout << "Nhap sai! Yeu cau nhap lai: ";
            }
        } while (choose != 1 && choose != 2);
        if (choose == 1) {
            GiaoDich *temp = new GiaoDichVang();
            temp->nhap();
            gd.push_back(temp);
        } else {
            GiaoDich *temp = new GiaoDichTienTe();
            temp->nhap();
            gd.push_back(temp);
        }
        cout << "Da them thanh cong.";
}

void xoaGiaoDich(vector<GiaoDich*> &gd) {
    int vitri = 0;
    for(GiaoDich *temp : gd) {
        if (temp->getNgayGiaoDich() == "20/05/2010") {
            break;
        }
        vitri++;
    }
    gd.erase(gd.erase(gd.begin() + vitri));
    cout << "Da xoa thanh cong." << endl;
}

int main() {
    vector<GiaoDich*> gd;
    menu();
    int choose;
    bool check = true;
    while (check) {
        cout << "Moi ban nhap lua chon: ";
        cin >> choose;
        switch (choose) {
            case 0:
                cout << "Da thoat chuong trinh." << endl;
                check = false;
                break;
            case 1:
                nhapGiaoDich(gd);
                break;
            case 2:
                tinhTongTungLoai(gd);
                break;
            case 3:
                cout << "Tinh trung binh thanh tien cua giao dich tien te la: " << tinhTrungBinhGDTienTe(gd);
                break;
            case 4:
                xuatGiaoDichDonGiaLonHon1Ty(gd);
                break;
            case 5:
                cout << "Dem nhung giao dich vang ngay 20/03/2015 la: " << demGiaoDichVangNgay20032015(gd);
                break;
            case 6:
                sapXep(gd);
                break;
            case 7:
                themGiaoDich(gd);
                break;
            case 8:
                xoaGiaoDich(gd);
                break;
            default:
                cout << "Nhap sai moi ban nhap lai.";
                break;
        }
    }
    return 0;
}