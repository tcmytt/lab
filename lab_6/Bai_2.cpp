#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;

class Nguoi {
    private:
        string hoten;
    public:
        Nguoi() {
            this->hoten = " ";
        }

        virtual void nhap() {
            cout << "\t+ Ho va ten: ";
            getline(cin, this->hoten);
        }

        virtual void xuat() {
            cout << left << setw(30) << this->hoten;
        }

        virtual int search() = 0;
};

class SinhVien : public Nguoi {
    private:
        float diemthi;
    public:
        SinhVien() : Nguoi() {
            this->diemthi = 0;
        }

        void nhap() {
            fflush(stdin);
            Nguoi::nhap();
            cout << "\t+ Nhap diem thi: ";
            cin >> this->diemthi;
        }

        void xuat() {
            Nguoi::xuat();
            cout << left << setw(30) << this->diemthi;
        }

        int search() {
            return this->diemthi > 8 ? 1 : 0;
        }
};

class GiangVien : public Nguoi {
    private:
        int sobaibao;
    public:
        GiangVien() : Nguoi() {
            this->sobaibao = 0;
        }

        void nhap() {
            fflush(stdin);
            Nguoi::nhap();
            cout << "\t+ Nhap so bai bao: ";
            cin >> this->sobaibao;
        }

        void xuat() {
            Nguoi::xuat();
            cout << left << setw(30) << this->sobaibao;
        }

        int search() {
            return this->sobaibao > 5 ? 1 : 0;
        }
};

int main() {
    vector<Nguoi *> nguoi;
    int n;
    cout << "Nhap so luong nguoi la: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int choose;
        do {
            system("cls");
            cout << "\t\tLua chon: \n";
            cout << "\t\t1. Sinh vien.\n";
            cout << "\t\t2. Giang vien.\n";
            cout << "Nhap lua chon: ";
            cin >> choose;
            if(choose != 1 && choose != 2) {
                cout << "Khong co lua chon nay!\n";
            }
        } while (choose != 1 && choose != 2);
        if(choose == 1) {
            Nguoi *temp1 = new SinhVien();
            temp1->nhap();
            nguoi.push_back(temp1);
        }
        if(choose == 2) {
            Nguoi *temp2 = new GiangVien();
            temp2->nhap();
            nguoi.push_back(temp2);
        }
    }

    cout << "Hien thi danh sach la: " << endl;
    for(Nguoi *ng : nguoi) {
        ng->xuat();
        cout << endl;
    }

    cout << "Danh sach doi tuong can tim la: " << endl;
    for(Nguoi *ng : nguoi) {
        if (ng->search() == 1) {
            ng->xuat();
            cout << endl;
        }
        
    }
    return 0;
}