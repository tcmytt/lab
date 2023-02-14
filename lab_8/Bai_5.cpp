#include<iostream>
#include<cstring>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;

class NgayHoaDon {
    private:
        int ngay, thang, nam;
    public:
        void nhapNgayHoaDon() {
            cout << "\t+ Nhap ngay hoa don: ";
            cin >> this->ngay;
            cout << "\t+ Nhap thang hoa don: ";
            cin >> this->thang;
            cout << "\t+ Nhap nam hoa don: ";
            cin >> this->nam;
        }
        void xuatNgayHoaDon() {
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

class KhachHang {
    private:
        string maKhachHang, hoTen;
        float donGia, soLuong;
        NgayHoaDon ngayHoaDon;
    public:
        virtual void nhap() {
            fflush(stdin);
            cout << "\t+ Nhap ma khach hang: ";
            getline(cin, this->maKhachHang);
            cout << "\t+ Nhap ten khach hang: ";
            getline(cin, this->hoTen);
            this->ngayHoaDon.nhapNgayHoaDon();
            cout << "\t+ Nhap so luong: ";
            cin >> this->soLuong;
            cout << "\t+ Nhap don gia: ";
            cin >> this->donGia;
        }
        virtual void xuat() {
            cout << setw(30) << left << this->maKhachHang;
            cout << setw(30) << left; this->ngayHoaDon.xuatNgayHoaDon();
            cout << setw(30) << left << this->soLuong;
            cout << setw(30) << left << this->donGia;
        }

        virtual float thanhTien() = 0;
};

void menuDoiTuong() {
    cout << "\t\t1. Sinh hoat.";
    cout << "\n\t\t2. Kinh doanh.";
    cout << "\n\t\t3. San xuat.";
}

class KHVietNam : public KhachHang {
    private:
        string doiTuong;
        float dinhMuc;
    public:
        void nhap() {
            KhachHang::nhap();
            int choose;
            menuDoiTuong();
            cout << "\n\t+ Nhap luu chon: ";
            do {
                cin >> choose;
                if (1 > choose && choose > 3) {
                    cout << "\tKhong co lua chon nay. Moi ban nhap lai.";
                }
                
            } while (1 > choose && choose > 3);
            if (choose == 1) {
                this->doiTuong = "Sinh hoat";
            } else if(choose == 2) {
                this->doiTuong = "Kinh doanh";
            } else {
                this->doiTuong = "San xuat";
            }
            cout << "\t+ Nhap dinh muc: ";
            cin >> this->dinhMuc;
        }

        void xuat() {
            KhachHang::xuat();
            cout << setw(30) << left << this->doiTuong;
            cout << setw(30) << left << this->dinhMuc;
        }

        float thanhTien() {
            
        }
};

class KHNuocNgoai : public KhachHang {
    private:
        
    public:
};

int main() {
    return 0;
}