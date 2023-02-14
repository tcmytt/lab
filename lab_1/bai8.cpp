#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

struct NGAY
{
    int ngay, thang, nam;
};

class KH
{
private:
    char ht[30];
    NGAY ns;
    char cmt[10];
    char hk[50];

public:
    KH()
    {
        strcpy(this->ht, " ");
        ns.ngay = 1;
        ns.thang = 1;
        ns.thang = 1900;
        strcpy(this->cmt, " ");
        strcpy(this->hk, " ");
    }
    ~KH() {}
    void Nhap()
    {
        cout << "Nhap ho va ten:";
        cin.getline(this->ht, 30);
        cout << "Nhap ngay sinh:";
        cin >> ns.ngay;
        cout << "Nhap thang sinh:";
        cin >> ns.thang;
        cout << "Nhap nam sinh:";
        cin >> ns.nam;
        cout << "Nhap cmt:";
        fflush(stdin);
        cin.getline(this->cmt, 10);
        cout << "Nhap ho khau:";
        cin.getline(this->hk, 50);
    }
    void in()
    {
        cout << "Nhap ho va ten:" << this->ht << endl;
        cout << "Nhap ngay sinh:" << ns.ngay << endl;
        cout << "Nhap thang sinh:" << ns.thang << endl;
        cout << "Nhap nam sinh:" << ns.nam << endl;
        cout << "Nhap cmt:" << this->cmt << endl;
        cout << "Nhap ho khau:" << this->hk << endl;
    }
};
int main()
{
    KH x;
    x.Nhap();
    cout << "Hien thi thong tin cua khach hang la: " << endl;
    x.in();
    return 0;
}