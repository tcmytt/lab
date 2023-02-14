#include<iostream>
#include<cstring>
#include<iomanip>
#include<vector>
using namespace std;

class QuanLy {
    private:
        string msc, httaixe;
        int soxe;
    public:
        virtual void nhap() {
            fflush(stdin);
            cout << "\t+ Nhap vao ma so chuyen: ";
            getline(cin, this->msc);
            cout << "\t+ Nhap vao ho ten tai xe: ";
            getline(cin, this->httaixe);
            cout << "\t+ Nhap vao so xe: ";
            cin >> this->soxe;
        }
        virtual void xuat() {
            cout << "\n\t+ Ma so chuyen: " << this->msc;
            cout << "\n\t+ Ho ten tai xe: " << this->httaixe;
            cout << "\n\t+ So xe: " << this->soxe;
        }
        virtual int id() = 0;
        virtual double getDoanhThu() = 0;
        virtual float getSokm() = 0;
};

class NoiThanh : public QuanLy {
    private:
        int sotuyen;
        float sokm;
        double doanhthu;
    public:
        void nhap() {
            QuanLy::nhap();
            cout << "\t+ Nhap so tuyen: ";
            cin >> this->sotuyen;
            cout << "\t+ Nhap so km di duoc: ";
            cin >> this->sokm;
            cout << "\t+ Nhap doanh thu: ";
            cin >> this->doanhthu;
        }

        void xuat() {
            QuanLy::xuat();
            cout << "\n\t+ So tuyen: " << this->sotuyen;
            cout << "\n\t+ So km di duoc: " << this->sokm;
            cout << "\n\t+ Doanh thu: " << this->doanhthu;
        }
        int id() {
            return 1;
        }
        double getDoanhThu() {
            return this->doanhthu;
        }
        float getSokm() {
            return this->sokm;
        }
};

class NgoaiThanh : public QuanLy {
    private:
        string noiden;
        int songay;
        double doanhthu;
    public:
        void nhap() {
            QuanLy::nhap();
            fflush(stdin);
            cout << "\t+ Nhap noi den: ";
            getline(cin, this->noiden);
            cout << "\t+ Nhap so ngay di duoc: ";
            cin >> this->songay;
            cout << "\t+ Nhap doanh thu: ";
            cin >> this->doanhthu;
        }
        void xuat() {
            QuanLy::xuat();
            cout << "\n\t+ Noi den: " << this->noiden;
            cout << "\n\t+ So ngay di duoc: " << this->songay;
            cout << "\n\t+ Doanh thu: " << this->doanhthu;
        }
        int id() {
            return 2;
        }
        double getDoanhThu() {
            return this->doanhthu;
        }
        float getSokm() {
            return 0;
        }
};

int main() {
    vector<QuanLy *> quanly;
    int n;
    cout << "Nhap vao so luong chuyen xe: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Nhap vao thong tin thu " << i + 1 << " la:" << endl;
        fflush(stdin);
        cout << "1. Chuyen xe noi thanh.\n";
        cout << "2. Chuyen xe ngoai thanh.\n";
        int choose;
        cout << "Nhap lua chon: ";
        do {
            cin >> choose;
            if (choose != 1 && choose != 2) {
                cout << "Nhap sai yeu cau nhap lai: ";
            }
        } while (choose != 1 && choose != 2);
        if (choose == 1) {
            QuanLy *temp = new NoiThanh();
            temp->nhap();
            quanly.push_back(temp);
        } else {
            QuanLy *temp = new NgoaiThanh();
            temp->nhap();
            quanly.push_back(temp);
        }
    }
    cout << "Danh sach quan ly chuyen xe la:" << endl;
    int count = 0;
    for(QuanLy *temp : quanly) {
        cout << "Thong tin chuyen xe thu " << ++count << endl;
        temp->xuat();
        cout << endl;
    }
    double sumNoiThanh = 0, sumNgoaiThanh = 0;
    for(QuanLy *temp : quanly) {
        if(temp->id() == 1) {
            sumNoiThanh += temp->getDoanhThu();
        } else {
            sumNgoaiThanh += temp->getDoanhThu();
        }
    }
    cout << "Tong doanh thu noi thanh: " << sumNoiThanh << endl;
    cout << "Tong doanh thu ngoai thanh: " << sumNgoaiThanh << endl;
    int minkm = 0;
    for(QuanLy *temp : quanly) {
        if(temp->id() == 1 && temp->getSokm() < minkm) {
            minkm = temp->getSokm();
        }
    }
    cout << "Danh sach chuyen xe noi dia co so km nho nhat la:" << endl;
    for(QuanLy *temp : quanly) {
        if(temp->id() == 1 && temp->getSokm() == minkm) {
            temp->xuat();
        }
    }
    return 0;
}