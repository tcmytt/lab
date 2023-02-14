#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;

class DocGia {
    private:
        string ma, ho, ten;
        int sthl;
    public:
        virtual void Nhap() {
            cout << "\t+ Nhap ma: ";
            getline(cin, this->ma);
            cout << "\t+ Nhap ho: ";
            getline(cin, this->ho);
            cout << "\t+ Nhap ten: ";
            getline(cin, this->ten);
            cout << "\t+ Nhap so thang hieu luc: ";
            cin >> this->sthl;
        }
        virtual void Xuat() {
            cout << left << setw(30) << this->ma;
            cout << left << setw(30) << this->ho;
            cout << left << setw(30) << this->ten;
            cout << left << setw(30) << this->sthl;
        }

        int getsthl() {
            return this->sthl;
        }

        virtual float TienThe() = 0;
        virtual int Tim() = 0;
};

class DGTre : public DocGia {
    private:
        int ns;
    public:
        void Nhap() {
            fflush(stdin);
            DocGia::Nhap();
            cout << "\t+ Nhap nam sinh: ";
            cin >> this->ns;
        }

        void Xuat() {
            DocGia::Xuat();
            cout << left << setw(30) << this->ns;
        }

        float TienThe() {
            return getsthl() * 20000;
        }

        int Tim() {
            return getsthl() < 10 ? 1 : 0;
        }
};

class DGLon : public DocGia {
    private:
        string nn;
    public:
        void Nhap() {
            fflush(stdin);
            DocGia::Nhap();
            cout << "\t+ Nhap nghe nghiep: ";
            getline(cin, this->nn);
        }

        void Xuat() {
            DocGia::Xuat();
            cout << left << setw(30) << this->nn;
        }

        float TienThe() {
            return getsthl() * 30000;
        }

        int Tim() {
            string temp = this->nn;
            transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
            return temp == "GIANG VIEN" ? 1 : 0;
        }
};

int main() {
    vector<DocGia *> dgs;
    int n;
    cout << "Nhap so luong doc gia la: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int choose;
        do {
            system("cls");
            cout << "\t\tLua chon: \n";
            cout << "\t\t1. Doc gia tre em.\n";
            cout << "\t\t2. Doc gia nguoi lon.\n";
            cout << "Nhap lua chon: ";
            cin >> choose;
            if(choose != 1 && choose != 2) {
                cout << "Khong co lua chon nay!\n";
            }
        } while (choose != 1 && choose != 2);
        if(choose == 1) {
            DocGia *temp1 = new DGTre();
            temp1->Nhap();
            dgs.push_back(temp1);
        }
        if(choose == 2) {
            DocGia *temp2 = new DGLon();
            temp2->Nhap();
            dgs.push_back(temp2);
        }
    }
    for(DocGia *dg : dgs) {
        dg->Xuat();
        cout << endl;
    }

    int sum = 0;
    for(DocGia *dg : dgs) {
        sum += dg->TienThe();
    }
    cout << "Tong tien lam theo cua tat ca doc gia la: " << sum << endl;
    cout << "Danh sach da tim thay: " << endl;
    for(DocGia *dg : dgs) {
        if (dg->Tim() == 1) {
            dg->Xuat();
            cout << endl;
        }
    }
    return 0;
}