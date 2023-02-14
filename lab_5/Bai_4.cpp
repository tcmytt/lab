#include<iostream>
#include<cstring>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;

class STUDENT {
    private:
        string maSV;
        string hoTen;
        string gioiTinh;
    public:
        STUDENT() {
            this->maSV = "";
            this->hoTen = "";
            this->gioiTinh = "";
        }
        ~STUDENT() {}
        friend istream &operator >> (istream& is, STUDENT& st) {
            fflush(stdin);
            cout << "\t+ Nhap ma sinh vien: ";
            getline(is, st.maSV);
            cout << "\t+ Nhap ho ten sinh vien: ";
            getline(is, st.hoTen);
            cout << "\t+ Nhap gioi tinh: ";
            getline(is, st.gioiTinh);
            return is;
        }
        friend ostream &operator << (ostream& os, STUDENT st) {
            os << left << setw(30) << st.maSV;
            os << left << setw(30) << st.hoTen;
            os << left << setw(30) << st.gioiTinh;
            return os;
        }

        string getHoTen() {
            return this->hoTen;
        }

        string getGioiTinh() {
            return this->gioiTinh;
        }
};

class MONHOC {
    private:
        string maMon;
        string tenMon;
    public:
        MONHOC() {
            this->maMon = "";
            this->tenMon = "";
        }
        ~MONHOC() {}
        friend istream &operator >> (istream& is, MONHOC& mh) {
            cout << "\t+ Nhap ma mon hoc: ";
            getline(is, mh.maMon);
            cout << "\t+ Nhap ten mon hoc: ";
            getline(is, mh.tenMon);
            return is;
        }
        friend ostream &operator << (ostream& os, MONHOC mh) {
            os << left << setw(30) << mh.maMon;
            os << left << setw(30) << mh.tenMon;
            return os;
        }

        string getTenMon() {
            return this->tenMon;
        }
};

class DIEMMH : public virtual STUDENT, public virtual MONHOC {
    private:
        float diemThi;
    public:
        DIEMMH() {
            this->diemThi = 0;
        }
        ~DIEMMH() {}
        friend istream &operator >> (istream& is, DIEMMH& diem) {
            is >> (STUDENT&) diem;
            is >> (MONHOC&) diem;
            cout << "\t+ Nhap diem mon hoc: ";
            is >> diem.diemThi;
            return is;
        }
        friend ostream &operator << (ostream& os, DIEMMH diem) {
            os << (STUDENT&) diem;
            os << (MONHOC&) diem;
            os << left << setw(30) << diem.diemThi;
            return os;
        }

        float getDiemThi() {
            return this->diemThi;
        }
};

void tieuDe() {
    cout << left << setw(30) << "Ma Sinh Vien";
    cout << left << setw(30) << "Ho Ten";
    cout << left << setw(30) << "Gioi Tinh";
    cout << left << setw(30) << "Ma Mon";
    cout << left << setw(30) << "Ten Mon";
    cout << left << setw(30) << "Diem Thi" << endl;
}

bool cmp(DIEMMH a, DIEMMH b) {
    return a.getDiemThi() > b.getDiemThi();
}

int main() {
    int n;
    cout << "Nhap so luong cac doi tuong can quan ly la: ";
    do {
        cin >> n;
        if(n < 1) {
            cout << "Nhap sai! Yeu cau nhap lai: ";
        }
    } while(n < 1);
    vector<DIEMMH> diemmhs;
    for (int i = 0; i < n; i++) {
        DIEMMH temp;
        cout << "Nhap vao thong tin diem thu " << i + 1 << " la:" << endl;
        cin >> temp;
        diemmhs.push_back(temp);
    }
    cout << "Hien thi danh sach sinh vien da nhap la: " << endl;
    tieuDe();
    for(DIEMMH diemmh : diemmhs) {
        cout << diemmh << endl;
    }
    cout << "Danh sach sinh vien nam la: " << endl;
    for(DIEMMH diemmh : diemmhs) {
        string temp = diemmh.getGioiTinh();
        transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
        if(temp == "NAM") {
            cout << diemmh << endl;
        }
    }
    float sumDiem = 0;
    for(DIEMMH diemmh : diemmhs) {
        sumDiem += diemmh.getDiemThi();
    }
    cout << "Diem trung binh cua cac mon hoc la: " << (float) sumDiem / diemmhs.size() << endl;
    string x;
    fflush(stdin);
    cout << "Nhap ten sinh vien can tim la: ";
    getline(cin, x);
    string tenVar = x;
    transform(tenVar.begin(), tenVar.end(), tenVar.begin(), ::toupper);
    tieuDe();
    for(DIEMMH diemmh : diemmhs) {
        string temp = diemmh.getHoTen();
        transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
        if(temp == tenVar) {
            cout << diemmh << endl;
        }
    }
    float diemMin = 10;
    for (int i = 0; i < n; i++) {
        string temp = diemmhs[i].getTenMon();
        transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
        if(diemMin > diemmhs[i].getDiemThi() && temp == "TOAN") {
            diemMin = diemmhs[i].getDiemThi();
        }
    }
    cout << "Danh sach diem thi nho nhat mon toan la: ";
    for (int i = 0; i < n; i++) {
        string temp = diemmhs[i].getTenMon();
        transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
        if(diemMin == diemmhs[i].getDiemThi() && temp == "TOAN") {
            cout << diemmhs[i] << endl;
        }
    }
    sort(diemmhs.begin(), diemmhs.end(), cmp);
    cout << "Danh sach sinh vien sau khi sap xep la: " << endl;
    tieuDe();
    for(DIEMMH diemmh : diemmhs) {
        cout << diemmh << endl;
    }
    return 0;
}