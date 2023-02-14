#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class SHAPE {
    public:
        SHAPE() {}
        virtual void nhap() = 0;
        virtual void xuat() = 0;
        virtual float chuvi() = 0;
        virtual float dientich() = 0;
};

class ROUND : public SHAPE {
    private:
        float r;
    public:
        ROUND() : SHAPE() {}
        void nhap() {
            cout << "\t+ Nhap ban kinh: ";
            cin >> this->r;
        }
        float chuvi() {
            return 2 * 3.14 * r;
        }
        float dientich() {
            return 4 * 3.14 * r * r;
        }
        void xuat() {
            cout << "Hinh tron co ban kinh la: " << this->r << endl;
            cout << "\t Chu vi la: " << chuvi() << endl;
            cout << "\t Dien tich la: " << dientich() << endl;
        }
};

class REC : public SHAPE {
    private:
        float d, r;
    public:
        REC() : SHAPE() {}
        void nhap() {
            cout << "\t+ Nhap chieu dai: ";
            cin >> this->d;
            cout << "\t+ Nhap chieu rong: ";
            cin >> this->r;
        }
        float chuvi() {
            return 2 * (this->d + this->r);
        }
        float dientich() {
            return this->d * this->r;
        }
        void xuat() {
            cout << "Hinh chu nhat co chieu dai, chieu rong lan luot la: " << this->d << ", " << this->r << endl;
            cout << "\t Chu vi la: " << chuvi() << endl;
            cout << "\t Dien tich la: " << dientich() << endl;
        }
};

class TRI : public SHAPE {
    private:
        float a, b, c;
    public:
        TRI() : SHAPE() {}
        void nhap() {
            do {
                cout << "\t+ Nhap canh a: ";
                cin >> this->a;
                cout << "\t+ Nhap canh b: ";
                cin >> this->b;
                cout << "\t+ Nhap canh c: ";
                cin >> this->c;
                if((a + b <= c) || (a + c <= b) || (b + c <= a)) {
                    cout << "Day khong phai la hinh tam giac. Moi ban nhap lai." << endl;
                }
            } while((a + b <= c) || (a + c <= b) || (b + c <= a));
        }
        float chuvi() {
            return this->a + this->b + this->c;
        }
        float dientich() {
            float p = (float) chuvi() / 2;
            float h = ((float) 2 / a) * (sqrt(p * (p - a) * (p - b) * (p - c)));
            float max = a;
            if(max < b) {
                max = b;
            }
            if(max < c) {
                max = c;
            }
            return 0.5 * h * max;
        }
        void xuat() {
            cout << "Hinh chu nhat co canh a, canh b, canh c lan luot la: " << this->a << ", " << this->b << ", " << this->c << endl;
            cout << "\t Chu vi la: " << chuvi() << endl;
            cout << "\t Dien tich la: " << dientich() << endl;
        }
};

int main() {
    vector<SHAPE *> a;
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
            cout << "\t\t3. Hinh tam giac.\n";
            cout << "Nhap lua chon: ";
            cin >> choose;
            if(choose != 1 && choose != 2 && choose != 3) {
                cout << "Khong co lua chon nay!\n";
            }
        } while (choose != 1 && choose != 2 && choose != 3);
        if(choose == 1) {
            SHAPE *temp1 = new ROUND();
            temp1->nhap();
            a.push_back(temp1);
        }
        if(choose == 2) {
            SHAPE *temp2 = new REC();
            temp2->nhap();
            a.push_back(temp2);
        }
        if(choose == 3) {
            SHAPE *temp3 = new TRI();
            temp3->nhap();
            a.push_back(temp3);
        }
    }
    float sumchuvi = 0;
    float sumdientich = 0;
    for(SHAPE * temp : a) {
        sumchuvi += temp->chuvi();
        sumdientich += temp->dientich();
    }
    cout << "Tong chu vi la: " << sumchuvi << endl;
    cout << "Tong dien tich la: " << sumdientich << endl;
    return 0;
}