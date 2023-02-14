// 7.Vu Khuong Duy - DHTI14A1CL - Ma de: 3
// https://youtu.be/OxK9g0fUjig
#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
using namespace std;

class Dog {
    private:
        string ten;
        string mauLong;
        int tuoi;
        string tenChu;
    public:
        Dog(string ten, string mauLong, int tuoi, string tenChu) {
            this->ten = ten;
            this->mauLong = mauLong;
            this->tuoi = tuoi;
            this->tenChu = tenChu;
        }
        ~Dog() {}
        friend istream &operator >> (istream& is, Dog& temp) {
            fflush(stdin);
            cout << "\t +Nhap ten con cho: ";
            getline(is, temp.ten);
            cout << "\t +Nhap mau long: ";
            getline(is, temp.mauLong);
            cout << "\t +Nhap tuoi: ";
            is >> temp.tuoi;
            fflush(stdin);
            cout << "\t +Nhap ten chu cua con cho: ";
            getline(is, temp.tenChu);
            return is;
        }

        friend ostream &operator << (ostream& os, Dog temp) {
            cout << left << setw(30) << temp.ten;
            cout << left << setw(30) << temp.mauLong;
            cout << left << setw(30) << temp.tuoi;
            cout << left << setw(30) << temp.tenChu;
            return os;
        }

        string getMauLong() {
            return this->mauLong;
        }

        string getTenChu() {
            return this->tenChu;
        }

        int getTuoi() {
            return this->tuoi;
        }
};

void tieuDe() {
    cout << left << setw(30) << "Ten";
    cout << left << setw(30) << "Mau Long";
    cout << left << setw(30) << "Tuoi";
    cout << left << setw(30) << "Ten Chu" << endl;
}

void Nhap(int n, vector<Dog>& dogs) {
    for(int i = 0; i < n; i++) {
        cout << "Nhap thong tin con cho thu " << i + 1 << " la:" << endl;
        Dog temp(" ", " ", 0, " ");
        cin >> temp;
        dogs.push_back(temp);
    }
}

void SearchMauLongTuoi(int n, vector<Dog> dogs) {
    cout << "Danh sach con cho co mau long vang va tuoi bang 3 la:" << endl;
    bool check = false;
    for(Dog dog : dogs) {
        if(dog.getMauLong() == "Vang" && dog.getTuoi() == 3) {
            if(check == false) {
                tieuDe();
            }
            check = true;
            cout << dog << endl;
        }
    }
    if(check == false) {
        cout << "Con cho can tim khong co trong danh sach.";
    }
}

void SreachTenChu(int n, vector<Dog> dogs) {
    cout << "\nHien thi con cho khong phai cua chu nhan Huy la:" << endl;
    bool checkChuNhan = false;
    for(Dog dog : dogs) {
        if(dog.getTenChu() == "Huy") {
            if(checkChuNhan == false) {
                tieuDe();
            }
            checkChuNhan = true;
            cout << dog << endl;
        }
    }
    if(checkChuNhan == false) {
        cout << "Con cho can tim khong co trong danh sach.";
    }
}

void Delete(int n, vector<Dog>& dogs) {
    int k;
    cout << "\nNhap vi tri thu k can xoa la: ";
    do {
        cin >> k;
        if(k > dogs.size() || k <= 0) {
            cout << "Khong co vi tri nay trong danh sach." << endl;
            cout << "Moi ban nhap lai: ";
    }
    } while (k > dogs.size() || k <= 0);
    dogs.erase(dogs.begin() + k - 1);
    cout << "Danh sach sau khi xoa la:" << endl;
    tieuDe();
    for(Dog dog : dogs) {
        cout << dog << endl;
    }
}

int main() {
    int n;
    
    cout << "Nhap so luong con cho can luu tru la: ";
    do {
        cin >> n;
        if(n <= 0) {
            cout << "Nhap sai so luong. Moi ban nhap lai so luong: ";
        }
    } while (n <= 0);
    vector<Dog> dogs;
    Nhap(n, dogs);
    SearchMauLongTuoi(n, dogs);
    SreachTenChu(n, dogs);
    Delete(n, dogs);
    return 0;
}