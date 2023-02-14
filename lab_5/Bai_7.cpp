#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

class SV {
    private:
        char lop[10], hoten[30];
    public:
        SV() {
            strcpy(this->lop, " ");
            strcpy(this->hoten, " ");
        }
        SV(char *lop, char *hoten) {
            strcpy(this->lop, lop);
            strcpy(this->hoten, hoten);
        }
        void display() {
            cout << left << setw(30) << this->hoten;
            cout << left << setw(30) << this->lop;
        }
};

class SVSP : public SV {
    private:
        float dtb;
    public:
        SVSP() : SV() {
            this->dtb = 0;
        }
        SVSP(char *lop, char *hoten, float dtb) : SV(lop, hoten) {
            this->dtb = dtb;
        }
        void display() {
            SV::display();
            cout << left << setw(30) << this->dtb;
        }

        float getdtb() {
            return this->dtb;
        }
};

class SVTC : public SV {
    private:
        int hocphi;
    public:
        SVTC() : SV() {
            this->hocphi = 0;
        }
        SVTC(char *lop, char *hoten, int hocphi) : SV(lop, hoten) {
            this->hocphi = hocphi;
        }
        void display() {
            SV::display();
            cout << left << setw(30) << this->hocphi;
        }
        int gethocphi() {
            return this->hocphi;
        }
};

class SVCN : public virtual SVSP, public virtual SVTC {
    public:
        SVCN(char lop[], char hoten[], float dtb, int hocphi) : SVSP(lop, hoten, dtb), SVTC(lop, hoten, hocphi) {}
        float hocbong() {
            if(this->getdtb() > 8.5) {
                return 10;
            }
            if(7.0 < this->getdtb() <= 8.5) {
                return 5;
            }
            return 0;
        }
        void display() {
            SVSP::display();
            cout << left << setw(30) << this->gethocphi();
        }
};

void Title() {
    cout << left << setw(30) << "Lop";
    cout << left << setw(30) << "Ho ten";
    cout << left << setw(30) << "Diem trung binh";
    cout << left << setw(30) << "Hoc phi" << endl;
}

int main() {
    SVCN *a[5];
    for (int i = 0; i < 5; i++) {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << " la:" << endl;
        char lop[10], hoten[30];
        float dtb;
        int hocphi;
        cout << "\t + Nhap ten lop: ";
        fflush(stdin);
        cin.getline(lop, 10);
        cout << "\t + Nhap ho ten: ";
        cin.getline(hoten, 30);
        cout << "\t + Nhap diem trung binh: ";
        cin >> dtb;
        cout << "\t + Nhap hoc phi: ";
        cin >> hocphi;
        a[i] = new SVCN(lop, hoten, dtb, hocphi);
    }
    cout << "Danh sach sinh vien la: "<< endl;
    Title();
    for (int i = 0; i < 5; i++) {
        a[i]->display();
        cout << endl;
    }
    int count = 0;
    for (int i = 0; i < 5; i++) {
        if(a[i]->hocbong() != 0) {
            count++;
        }
    }
    cout << "Danh sach hoc bong la: " << count << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (a[i]->getdtb() < a[j]->getdtb()) {
                swap(a[i], a[j]);
            }
            
        }
    }
    cout << "Danh sach da sap xep la: " << endl;
    Title();
    for (int i = 0; i < 5; i++) {
        a[i]->display();
        cout << endl;
    }
    return 0;
}