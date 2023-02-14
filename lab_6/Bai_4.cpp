#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<cmath>
using namespace std;

class Hinhve {
    public:
        virtual void nhap() = 0;
        virtual void xuat() = 0;
};

class Haichieu : public Hinhve {
    public:
        void nhap() {}
        void xuat() {}
        virtual float ChuVi() = 0;
        virtual float DienTich() = 0;
};

class Tron : public Haichieu {
    private:
        float r;
    public:
        void nhap() {
            cout << "\t+ Nhap ban kinh: ";
            cin >> this->r;
        }
        void xuat() {
            cout << "Hinh tron co ban kinh la: " << this->r << endl;
            cout << "\t Chu vi la: " << ChuVi() << endl;
            cout << "\t Dien tich la: " << DienTich() << endl;
        }
        float ChuVi() {
            return 2 * 3.14 * r;
        }
        float DienTich() {
            return 4 * 3.14 * r * r;
        }
};

class Chunhat : public Haichieu {
    private:
        float d, r;
    public:
        void nhap() {
            cout << "\t+ Nhap chieu dai: ";
            cin >> this->d;
            cout << "\t+ Nhap chieu rong: ";
            cin >> this->r;
        }
        void xuat() {
            cout << "Hinh chu nhat co chieu dai, chieu rong lan luot la: " << this->d << ", " << this->r << endl;
            cout << "\t Chu vi la: " << ChuVi() << endl;
            cout << "\t Dien tich la: " << DienTich() << endl;
        }
        float ChuVi() {
            return 2 * (this->d + this->r);
        }
        float DienTich() {
            return this->d * this->r;
        }
};

class Vuong : public Haichieu {
    private:
        float a;
    public:
        void nhap() {
            cout << "\t+ Nhap canh a: ";
            cin >> this->a;
        }
        void xuat() {
            cout << "Hinh chu nhat co canh la: " << this->a << endl;
            cout << "\t Chu vi la: " << ChuVi() << endl;
            cout << "\t Dien tich la: " << DienTich() << endl;
        }
        float ChuVi() {
            return 4 * this->a;
        }
        float DienTich() {
            return this->a * this->a;
        }
};

class Bachieu : public Hinhve {
    public:
        void nhap() {}
        void xuat() {}
        virtual float TheTich() = 0;
};

class Cau : public Bachieu {
    private:
        float r;
    public:
        void nhap() {
            cout << "\t+ Nhap ban kinh: ";
            cin >> this->r;
        }
        void xuat() {
            cout << "Hinh cau co ban kinh la: " << this->r << endl;
            cout << "\t The tich la: " << TheTich() << endl;
        }
        float TheTich() {
            return 3.14 * 4 * r * r * r / 3;
        }
};

class Lapphuong : public Bachieu {
    private:
        float a;
    public:
        void nhap() {
            cout << "\t+ Nhap canh a: ";
            cin >> this->a;
        }
        void xuat() {
            cout << "Hinh lap phuong co canh a la: " << this->a << endl;
            cout << "\t The tich la: " << TheTich() << endl;
        }
        float TheTich() {
            return a * a * a * 1.0;
        }
};

int main() {
    vector<Hinhve *> a;
    int n;
    cout << "Nhap so luong hinh la: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int choose;
        do {
            system("cls");
            cout << "\t\tLua chon: \n";
            cout << "\t\t1. Hinh tron.\n";
            cout << "\t\t2. Hinh chu nhat.\n";
            cout << "\t\t3. Hinh vuong.\n";
            cout << "\t\t4. Khoi cau.\n";
            cout << "\t\t5. Khoi lap phuong.\n";
            cout << "Nhap lua chon: ";
            cin >> choose;
        } while (choose < 1 || choose > 5);
        switch (choose) {
            case 1:
            {
                Hinhve *temp1 = new Tron();
                temp1->nhap();
                a.push_back(temp1);
                break;
            }
            case 2:
            {
                Hinhve *temp2 = new Chunhat();
                temp2->nhap();
                a.push_back(temp2);
                break;
            }
            case 3:
            {
                Hinhve *temp3 = new Vuong();
                temp3->nhap();
                a.push_back(temp3);
                break;
            }
            case 4:
            {
                Hinhve *temp4 = new Cau();
                temp4->nhap();
                a.push_back(temp4);
                break;
            }
            case 5:
            {
                Hinhve *temp5 = new Lapphuong();
                temp5->nhap();
                a.push_back(temp5);
                break;
            }
        }
    }
    for(Hinhve *temp : a) {
        temp->xuat();
    }
    return 0;
}