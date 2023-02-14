#include<iostream>
#include<vector>
using namespace std;

class ISP {
    public:
        virtual void nhap() = 0;
        virtual void xuat() = 0;
        virtual double Tongtien() = 0;
        virtual int id() = 0;
};

class DialUp : public ISP {
    private:
        int p;
    public:
        void nhap() {
            cout << "\t+ Nhap so phut: ";
            cin >> p;
        }
        void xuat() {
            cout << "\t+ Thue bao Dial Up co so phut: " << this->p << ", tong tien phai tra la: " << Tongtien() << endl;
        }
        double Tongtien() {
            return 30000 + this->p * 30;
        }
        int id() {
            return 1;
        }
};

class ADSL : public ISP {
    private:
        int mb;
    public:
        void nhap() {
            cout << "\t+ Nhap so MB: ";
            cin >> mb;
        }
        void xuat() {
            cout << "\t+ Thue bao ADSL co so MB: " << this->mb << ", tong tien phai tra la: " << Tongtien() << endl;
        }
        double Tongtien() {
            return 50000 + this->mb * 50;
        }
        int id() {
            return 2;
        }
};

class T1 : public ISP {
    public:
        void nhap() {}
        void xuat() {
            cout << "\t+ Thue bao T1 co tong tien phai tra la: " << Tongtien() << endl;
        }
        double Tongtien() {
            return 2000000;
        }
        int id() {
            return 3;
        }
};

int main() {
    vector<ISP *> a;
    int n;
    cout << "Nhap so luong thue bao la: ";
    cin >> n;
    for(int i = 0; i < n; i++) {
        cout << "Thong tin thue bao thu " << i + 1 << " la:" << endl;
        int choose;
        do {
            system("cls");
            cout << "\t\t1. Dial Up\n";
            cout << "\t\t2. ADSL\n";
            cout << "\t\t3. T1\n";
            cout << "Moi ban nhap lua chon: ";
            cin >> choose;
        } while (choose < 1 || choose > 3);
        system("cls");
        switch (choose) {
            case 1:
                {
                    ISP *temp1 = new DialUp();
                    temp1->nhap();
                    a.push_back(temp1);
                    break;
                }
            case 2:
                {
                    ISP *temp2 = new ADSL();
                    temp2->nhap();
                    a.push_back(temp2);
                    break;
                }
            case 3:
                {
                    ISP *temp3 = new T1();
                    temp3->nhap();
                    a.push_back(temp3);
                    break;
                }
        }
    }
    cout << "Tong tien cuoc cua tung loai thue bao: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Tong tien cuoc thue bao thu " << i + 1 << " la:" << a[i]->Tongtien() << endl;
    }
    double sum;
    for (ISP *temp : a) {
        sum += temp->Tongtien();
    }
    cout << "Tong tien cua tat ca cac thue bao la: " << sum << endl;
    double maxADSL = a[0]->Tongtien();
    for (ISP *temp : a) {
        if (temp->id() == 2 && maxADSL < temp->Tongtien()) {
            maxADSL = temp->Tongtien();
        }
    }
    cout << "Thong tin thue bao ADSL co tien cuoc lon nhat la: " << endl;
    for (ISP *temp : a) {
        if (temp->id() == 2 && maxADSL == temp->Tongtien()) {
            temp->xuat();
        }
    }
    return 0;
}