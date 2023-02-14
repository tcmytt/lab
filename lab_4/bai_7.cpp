#include<iostream>
#include<cstring>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;

class HangHoa {
    private:
        string ma, tenhang;
        float dongia;
    public:
    HangHoa() {
        this->ma = "";
        this->tenhang = "";
        this->dongia = 0;
    }
    ~HangHoa() {}
    void nhap() {
        fflush(stdin);
        cout << "\t + Nhap ma hang: ";
        getline(cin, this->ma);
        cout << "\t + Nhap ten hang: ";
        getline(cin, this->tenhang);
        cout << "\t + Nhap don gia: ";
        cin >> this->dongia;
    }
    void xuat() {
        cout << left << setw(20) << this->ma;
        cout << left << setw(20) << this->tenhang;
        cout << left << setw(20) << this->dongia;
    }

    float getdongia() {
        return this->dongia;
    }

    string getma() {
        return this->ma;
    }

    string gettenhang() {
        return this->tenhang;
    }
};

class MT : public HangHoa {
    private:
        float tocdo;
        int sl;
    public:
        MT() : HangHoa() {
            this->tocdo = 0;
            this->sl = 0;
        }
        ~MT() {}
        friend istream& operator >> (istream& is, MT& temp) {
            temp.nhap();
            cout << "\t + Nhap toc do xu ly: ";
            is >> temp.tocdo;
            cout << "\t + Nhap so luong: ";
            is >> temp.sl;
            return is;
        }

        friend ostream& operator << (ostream& os, MT temp) {
            temp.xuat();
            os << left << setw(20) << temp.tocdo;
            os << left << setw(20) << temp.sl;
            return os;
        }

        float tinhtien() {
            return this->sl * this->getdongia();
        }

        float gettocdo() {
            return this->tocdo;
        }
};

class MTXT : public MT {
    private:
        float tl;
    public:
        MTXT() : MT() {
            this->tl = 0;
        }
        ~MTXT() {}
        float tinhphi() {
            return 0.05 * this->getdongia();
        }

        friend istream& operator >> (istream& is, MTXT& temp) {
            is >> (MT&) temp;
            cout << "\t + Nhap trong luong: ";
            is >> temp.tl;
            return is;
        }

        friend ostream& operator << (ostream& os, MTXT temp) {
            os << (MT&) temp;
            os << left << setw(20) << temp.tl;
            os << left << setw(20) << temp.tinhtien();
            os << left << setw(20) << temp.tinhphi();
            return os;
        }
};

void title() {
    cout << left << setw(20) << "Ma hang";
    cout << left << setw(20) << "Ten hang";
    cout << left << setw(20) << "Don gia";
    cout << left << setw(20) << "Toc do";
    cout << left << setw(20) << "So luong";
    cout << left << setw(20) << "Trong luong";
    cout << left << setw(20) << "Tinh tien";
    cout << left << setw(20) << "Tinh phi bao tri" << endl;
}

void menu() {
    cout << "\t\t\t" << "1.Hien thi danh sach." << endl;
    cout << "\t\t\t" << "2.Tim thong tin may tinh theo ma may." << endl;
    cout << "\t\t\t" << "3.Liet ke may tinh theo ten." << endl;
    cout << "\t\t\t" << "4.Tinh tong phi bao tri cua cac may tinh." << endl;
    cout << "\t\t\t" << "5.Tim may tinh xach tay co toc do nho nhat." << endl;
    cout << "\t\t\t" << "6.Sua thong tin mot may tinh xach tay." << endl;
    cout << "\t\t\t" << "7.Xoa mot may tinh theo ma cho truoc." << endl;
    cout << "\t\t\t" << "8.Chen them mot may tinh tai vi tri k." << endl;
    cout << "\t\t\t" << "9.Sap xep danh sach theo chieu tang dan cua ma may." << endl;
    cout << "\t\t\t" << "0.Thoat chuong trinh." << endl;
}

void case_1(vector<MTXT> mtxts) {
    cout << "Danh sach may tinh xach tay la:" << endl;
    title();
    for(MTXT temp : mtxts) {
        cout << temp << endl;
    }
}

void case_2(vector<MTXT> mtxts) {
    string maVar;
    fflush(stdin);
    cout << "Nhap ma may can tim la: ";
    getline(cin, maVar);
    cout << "Danh sach may tinh can tim la: " << endl;
    title();
    bool check = false;
    for(MTXT temp : mtxts) {
        if(temp.getma() == maVar) {
            cout << temp << endl;
            check = true;
        }
    }
    if(check == false) {
        cout << "Khong tim thay." << endl;
    }
}

void case_3(vector<MTXT> mtxts) {
    string tenhangVar;
    fflush(stdin);
    cout << "Nhap ten may can tim la: ";
    getline(cin, tenhangVar);
    cout << "Danh sach may tinh can tim la: " << endl;
    title();
    bool check = false;
    for(MTXT temp : mtxts) {
        if(temp.gettenhang() == tenhangVar) {
            cout << temp << endl;
            check = true;
        }
    }
    if(check == false) {
        cout << "Khong tim thay." << endl;
    }
}
void case_4(vector<MTXT> mtxts) {
    cout << "Tong phi bao tri cua cac may tinh la: ";
    float sum = 0;
    for(MTXT temp : mtxts) {
        sum += temp.tinhphi();
    }
    cout << sum << endl;
}
void case_5(vector<MTXT> mtxts, int n) {
    float min = mtxts[0].gettocdo();
    for(int i = 1; i < n; i++) {
        if(min > mtxts[i].gettocdo()) {
            min = mtxts[i].gettocdo();
        }
    }
    cout << "Danh sach may tinh xach tay co toc do nho nhat la: " << endl;
    title();
    for(MTXT temp : mtxts) {
        if(temp.gettocdo() == min) {
            cout << temp << endl;
        }
    }
}
void case_6(vector<MTXT>& mtxts, int n) {
    int vitri;
    cout << "Nhap vi tri can sua la: ";
    cin >> vitri;
    if(vitri < 0 || vitri > n) {
        cout << "Khong tim thay vi tri vua nhap." << endl;
    }
    else {
        cout << "Thong tin can sua la: " << endl;
        cin >> mtxts[vitri];
        cout << "Danh sach may tinh sau khi sua la:" << endl;
        title();
        for(MTXT temp : mtxts) {
            cout << temp << endl;
        }
    }
    
}
void case_7(vector<MTXT>& mtxts) {
    string maVar;
    fflush(stdin);
    cout << "Nhap ma hang can xoa la: ";
    getline(cin, maVar);
    int i = 0;
    bool check = false;
    for(MTXT temp : mtxts) {
        if(temp.getma() == maVar) {
            mtxts.erase(mtxts.begin() + i);
            check = true;
        }
        i++;
    }
    if(check == false) {
        cout << "Khong tim thay ma hang vua nhap." << endl;
    }
    else {
        cout << "Danh sach may tinh sau khi xoa la:" << endl;
        title();
        for(MTXT temp : mtxts) {
            cout << temp << endl;
        }
    }
}
void case_8(vector<MTXT>& mtxts, int& n) {
    int vitri;
    cout << "Nhap vi tri can chen la: ";
    cin >> vitri;
    if(vitri < 0 || vitri > n) {
        cout << "Khong tim thay vi tri vua nhap." << endl;
    }
    else {
        MTXT temp;
        cout << "Thong tin can them la: " << endl;
        cin >> temp;
        mtxts.insert(mtxts.begin() + vitri, temp);
        cout << "Danh sach may tinh sau khi them la:" << endl;
        title();
        for(MTXT temp : mtxts) {
            cout << temp << endl;
        }
    }
}

bool cmp(MTXT a, MTXT b) {
    return a.getma() < b.getma();
}

void case_9(vector<MTXT>& mtxts) {
    sort(mtxts.begin(), mtxts.end(), cmp);
    cout << "Danh sach may tinh xach tay sau khi sap xep la:" << endl;
    title();
    for(MTXT temp : mtxts) {
        cout << temp << endl;
    }
}


int main() {
    int n;
    cout << "Nhap so luong may tinh xac tay la: ";
    cin >> n;
    vector<MTXT> mtxts;
    for (int i = 0; i < n; i++) {
        MTXT temp;
        cout << "Thong tin may tinh xach tay thu " << i + 1 << " la:" << endl;
        cin >> temp;
        mtxts.push_back(temp);
    }
    int choose;
    do {
        menu();
        cout << "Moi ban nhap lua chon: ";
        cin >> choose;
        if(0 > choose || choose > 9) {
            cout << "Lua chon khong dung." << endl;
        }
        switch(choose) {
            case 1:
                case_1(mtxts);
                break;
            case 2:
                case_2(mtxts);
                break;
            case 3:
                case_3(mtxts);
                break;
            case 4:
                case_4(mtxts);
                break;
            case 5:
                case_5(mtxts, n);
                break;
            case 6:
                case_6(mtxts, n);
                break;
            case 7:
                case_7(mtxts);
                break;
            case 8:
                case_8(mtxts, n);
                break;
            case 9:
                case_9(mtxts);
                break;
            case 0:
                cout << "Da dung chuong trinh.";
                break;
        }
        if(choose == 0) {
            break;
        }
    } while(0 < choose || choose > 9);
    return 0;
}