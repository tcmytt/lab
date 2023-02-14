#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

class Mytime {
    private:
        int h, m, s;
    public:
        Mytime(int h = 0, int m = 0, int s = 0) {
            this->h = h;
            this->m = m;
            this->s = s;
        }
        void display() {
            cout << this->h << ":" << this->m << ":" << this->s  << "\t";
        }

        int getH() {
            return this->h;
        }
        int getM() {
            return this->m;
        }
        int getS() {
            return this->s;
        }
};

class Mydate {
    private:
        int d, mo, y;
    public:
        Mydate(int d = 0, int mo = 0, int y = 0) {
            this->d = d;
            this->mo = mo;
            this->y = y;
        }
        void display() {
            cout << this->d << "-" << this->mo << "-" << this->y;
        }
        int getd() {
            return this->d;
        }
        int getMo() {
            return this->mo;
        }
        int getY() {
            return this->y;
        }
};

class Myfile : public Mytime, public Mydate {
    private:
        char filename[255];
        int filesize;
    public:
        Myfile(char filename[] = " ",int filesize = 0, int h = 0, int m = 0, int s = 0, int d = 0, int mo = 0, int y = 0) 
        : Mytime(h, m, s), Mydate(d, mo, y) {
            strcpy(this->filename, filename);
            this->filesize = filesize;
        }
        void display() {
            cout << "Ten file: " << this->filename;
            cout << "Kich thuoc file: " << this->filesize << "\t";
            Mytime::display();
            Mydate::display();
        }
        bool operator > (Myfile b) {
            if(b.filesize > this->filesize) {
                return true;
            }
            return false;
        }
};

int main() {
    Myfile *file[5];
    for (int i = 0; i < 5; i++) {
        cout << "Nhap thong tin file thu " << i + 1 << "la: " << endl;
        char varname[255];
        cout << "\t+ Ten file: ";
        fflush(stdin);
        cin.getline(varname, 255);
        int varsize;
        cout << "\t+ Kich thuoc file: ";
        cin >> varsize;
        int h, m, s;
        cout << "\t+ Nhap giay: ";
        cin >> s;
        cout << "\t+ Nhap phut: ";
        cin >> m;
        cout << "\t+ Nhap gio: ";
        cin >> h;
        int d, mo, y;
        cout << "\t+ Nhap ngay: ";
        cin >> d;
        cout << "\t+ Nhap thang: ";
        cin >> mo;
        cout << "\t+ Nhap nam: ";
        cin >> y;
        file[i] = new Myfile(varname, varsize, h, m, s, d, mo, y);
    }
    cout << "Danh sach file da nhap la: " << endl;
    for (int i = 0; i < 5; i++) {
        file[i]->display();
        cout << endl;
    }
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        if(file[i]->getH() == 20 && file[i]->getM() == 15 && file[i]->getS() == 30 && file[i]->getd() == 10 && file[i]->getMo() == 10 && file[i]->getY() == 2000) {
            count ++;
        }
    }
    cout << "So luong doi tuong myfile co thoi gian yeu cau la: " << count;
    for (int i = 0; i < 5; i++) {
        for (int j = i+1; j < 5; j++) {
            if(file[i] > file[j]) {
                swap(file[i], file[j]);
            }
        }
    }
    cout << "\nDanh sach sau khi sap xep la: " << endl;
    for (int i = 0; i < 5; i++) {
        file[i]->display();
        cout << endl;
    }
    return 0;
}