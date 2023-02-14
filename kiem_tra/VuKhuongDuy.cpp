#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<fstream>

using namespace std;

struct HSD {
    int dd, mm, yy;
};

class SANPHAM {
    private:
        string maSanPham, tenSanPham;
        float donGia;
    public:
        SANPHAM(string maSanPham = " ", string tenSanPham = " ", float donGia = 0) {
            this->maSanPham = maSanPham;
            this->tenSanPham = tenSanPham;
            this->donGia = donGia;
        }
        ~SANPHAM() {}
        friend istream &operator >> (istream& is, SANPHAM& temp) {
            cout << "\t+ Nhap ma san pham: ";
            fflush(stdin);
            getline(is, temp.maSanPham);
            cout << "\t+ Nhap ten san pham: ";
            getline(is, temp.tenSanPham);
            cout << "\t+ Nhap don gia: ";
            is >> temp.donGia;
            return is;
        }
        friend ostream &operator << (ostream& os, SANPHAM temp) {
            os << setw(30) << left << temp.maSanPham;
            os << setw(30) << left << temp.tenSanPham;
            os << setw(30) << left << temp.donGia;
            return os;
        }
        float getDonGia() {
            return this->donGia;
        }
        string getTenSanPham() {
            return this->tenSanPham;
        }
};

class BANH : public SANPHAM {
    private:
        HSD hsd;
        string thanhPhan;
    public:
        BANH(string maSanPham = " ", string tenSanPham = " ", float donGia = 0, int dd = 0, int mm = 0, int yy = 0, string thanhPhan = " ") : SANPHAM(maSanPham, tenSanPham, donGia) {
            this->hsd.dd = dd;
            this->hsd.mm = mm;
            this->hsd.yy = yy;
            this->thanhPhan = thanhPhan;
        }
        ~BANH() {}
        friend istream &operator >> (istream& is, BANH& temp) {
            is >> (SANPHAM&) temp;
            cout << "\t+ Nhap han su dung: " << endl;
            cout << "\t  + Ngay: ";
            is >> temp.hsd.dd;
            cout << "\t  + Thang: ";
            is >> temp.hsd.mm;
            cout << "\t  + Nam: ";
            is >> temp.hsd.yy;
            cout << "\t+ Nhap thanh phan: ";
            fflush(stdin);
            getline(is, temp.thanhPhan);
            return is;
        }
        float giaSauThue() {
            return this->getDonGia() + this->getDonGia() * 0.1;
        }
        friend ostream &operator << (ostream& os, BANH temp) {
            os << (SANPHAM&) temp;
            os << temp.hsd.dd << "/" << temp.hsd.mm << "/" << setw(30) << left << temp.hsd.yy;
            os << setw(30) << left << temp.thanhPhan;
            return os;
        }

        int getDD() {
            return this->hsd.dd;
        }
        int getMM() {
            return this->hsd.mm;
        }
        int getYY() {
            return this->hsd.yy;
        }
};

void menu() {
    cout << "1. Nhap va in ra danh sach cac banh da nhap o dang bang." << endl;
    cout << "2. In ra danh sach cac banh co ten Danisa theo thu tu tang dan cua don gia." << endl;
    cout << "3. Tim trong danh sach banh co ten banh la Chocopie chua,"
            << " neu chua co, chen 1 doi tuong banh nay vao sau vi tri thu k (k nhap tu ban phim) trong danh sach." << endl;
    cout << "4. Xoa khoi danh sach cac banh da het han su dung tinh den ngay 20/10/2021." << endl;
}

void nhap(vector<BANH> &banh, int &n) {
    cout << "--------Nhap danh sach cac banh da nhap o dang bang--------" << endl;
    cout << "Nhap so luong banh: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        BANH temp(" ", " ", 0, 0, 0, 0, " ");
        cout << "Nhap thong tin banh thu " << i + 1 << " la: " << endl;
        cin >> temp;
        banh.push_back(temp);
    }
}

void tieuDe() {
    cout << setw(30) << left << "MA SAN PHAM";
    cout << setw(30) << left << "TEN SAN PHAM";
    cout << setw(30) << left << "DON GIA";
    cout << setw(30) << left << "NGAY HET HAN";
    cout << setw(30) << left << "THANH PHAN" << endl;
}

void xuat(vector<BANH> banh) {
    cout << "--------Xuat danh sach cac banh da nhap o dang bang--------" << endl;
    tieuDe();
    for(BANH b : banh) {
        cout << b << endl;
    }
}

bool cmp(BANH a, BANH b) {
    return a.getDonGia() < b.getDonGia();
}

void sortDanisa(vector<BANH> banh) {
    cout << "--------In ra danh sach cac banh co ten Danisa theo thu tu tang dan cua don gia--------" << endl;
    tieuDe();
    sort(banh.begin(), banh.end(), cmp);
    for(BANH b : banh) {
        string s = b.getTenSanPham();
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        if (s == "DANISA"){
            cout << b << endl;
        }
    }
}

void sreachChocopie(vector<BANH> &banh) {
    cout << "--------In ra danh sach cac banh co ten Chocopie--------" << endl;
    bool check = false;
    for(BANH b : banh) {
        string s = b.getTenSanPham();
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        if (s == "CHOCOPIE"){
            if(check == false) {
                tieuDe();
            }
            check = true;
            cout << b << endl;
        }
    }
    if (check == false) {
        BANH temp;
        cout << "->Khong tim thay banh Chocopie.";
        cout << "Nhap thong tin banh Chocopie can them: " << endl;
        string s;
        do {
            cin >> temp;
            s = temp.getTenSanPham();
            transform(s.begin(), s.end(), s.begin(), ::toupper);
            if (s != "CHOCOPIE") {
                cout << "Ban phai nhap ten banh la Chocopie. Moi ban nhap lai: " << endl;
            }
        } while(s != "CHOCOPIE");
        int size = banh.size();
        int k;
        cout << "Nhap vi tri can chen: ";
        do {
            cin >> k;
            if (!(1 <= k && k <= size + 1)) {
                cout << "Khong co vi tri nay. Moi ban nhap lai: ";
            }
        } while (!(1 <= k && k <= size + 1));
        banh.insert(banh.begin() + k - 1, temp);
        cout << "Da them thanh cong!" << endl;
    }
}

bool checkdate(int a, int b, int c) {
    if(a < 2021) {
        return true;
    } else if(a == 2021) {
        if(b < 10) {
            return true;
        } else if(b == 10) {
            if(c <= 20) {
                return true;
            }
        }
    }
    return false;
}

void deleteBanh(vector<BANH> &banh) {
    cout << "--------Xoa khoi danh sach cac banh da het han su dung tinh den ngay 20/10/2021--------" << endl;
    bool check = false;
    int size = banh.size();
    for(int i = 0; i < size; i++) {
        if (checkdate(banh[i].getYY(), banh[i].getMM(), banh[i].getDD())) {
            banh.erase(banh.begin() + i);
            check = true;
            i--;
        }
    }
    if (check == false) {
        cout << "Khong co banh nao het su dung." << endl;
    } else {
        cout << "Da xoa het cac banh het han su dung." << endl;
    }
}

void ghiFile(vector<BANH> banh, ofstream &fileout) {
    fileout << "--------Danh sach luu file-------" << endl;
    for(BANH b : banh) {
        fileout << b << endl;
    }
}

int main() {
    menu();
    vector<BANH> banh;
    int n;
    int choose;

    do {
        cout << "Nhap lua chon cua ban: ";
        cin >> choose;
        switch (choose) {
            case 1:
                nhap(banh, n);
                xuat(banh);
                break;
            case 2:
                sortDanisa(banh);
                break;
            case 3:
                sreachChocopie(banh);
                break;
            case 4:
                deleteBanh(banh);
                break;
            case 5:
                xuat(banh);
                break;
            case 0:
                //ofstream fileout("output.txt");
                ofstream fileout;
                fileout.open("output.txt");
                ghiFile(banh, fileout);
                cout << "Da luu chuong trinh vao tep output.txt.";
                break;
        }

    } while(choose != 0);
    return 0;
}
