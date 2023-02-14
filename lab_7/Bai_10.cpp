#include<iostream>
#include<cstring>
#include<iomanip>
#include<algorithm>
using namespace std;

class NhanVien {
    private:
        string ma;
        string hoten;
        float hsl;
        int ngaycong;
    public:
        friend istream &operator >> (istream& is, NhanVien& temp) {
            cout << "\t+ Nhap ma: ";
            fflush(stdin);
            getline(is, temp.ma);
            cout << "\t+ Nhap ho ten: ";
            getline(is, temp.hoten);
            cout << "\t+ Nhap he so luong: ";
            is >> temp.hsl;
            cout << "\t+ Nhap ngay cong: ";
            is >> temp.ngaycong;
            return is;
        }
        friend ostream &operator << (ostream& os, NhanVien temp) {
            os << setw(30) << left << temp.ma;
            os << setw(30) << left << temp.hoten;
            os << setw(30) << left << temp.hsl;
            os << setw(30) << left << temp.ngaycong;
            return os;
        }
        friend bool operator < (NhanVien a, NhanVien b) {
            return a.ngaycong < b.ngaycong;
        }
        friend bool operator > (NhanVien a, NhanVien b) {
            return a.ngaycong > b.ngaycong;
        }
        friend bool operator == (NhanVien a, NhanVien b) {
            return a.ngaycong == b.ngaycong;
        }
};

template<class T>
class arr {
    private:
        vector<T> a;
    public:
        arr(vector<T> a) {
            this->a = a;
        }
        void xuat() {
            for(T temp : a) {
                cout << temp << endl;
            }
        }
        int tong() {
            int dem = 0;
            for(T temp : a) {
                dem++;
            }
            return dem;
        }

        void sapxep() {
            sort(a.begin(), a.end(), [ ](T x, T y) {
                return x > y;
            });
        }
        void min() {
            T min = a[0];
            for (T temp : a) {
                if(temp < min) {
                    min = temp;
                }
            }
            for (T temp : a) {
                if(temp == min) {
                    cout << temp;
                }
            }
        }
};

int main() {
    int n;
    cout << "Nhap so luong nhan vien la: ";
    cin >> n;
    vector<NhanVien> nhanvien;
    for (int i = 0; i < n; i++) {
        NhanVien temp;
        cout << "Nhap thong tin thu " << i + 1 << " la: " << endl;
        cin >> temp;
        nhanvien.push_back(temp);
    }
    
    arr a(nhanvien);
    cout << "\nHien thi thong tin: " << endl;
    a.xuat();
    cout << "\nTong so luong phan tu: " << a.tong();
    cout << "\nHien thi phan tu nho nhat: " << endl;
    a.min();
    cout << "\nHien thi danh sach sau khi sap xep: " << endl;
    a.sapxep();
    a.xuat();
    return 0;
}