#include<iostream>
#include<cstring>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;

class person {
    private:
        string name,address;
        int phone;
    public:
        person() {
            this->name = "";
            this->address = "";
            this->phone = 0;
        }
        person(string name, string address, int phone) {
            this->name = name;
            this->address = address;
            this->phone = phone;
        }
        string getName() {
            return this->name;
        }
        string getAddress() {
            return this->address;
        }
        int getPhone() {
            return this->phone;
        }
};

class officer : public person {
    private:
        float salary;
    public:
        officer() : person() {
            this->salary = 0;
        }
        officer(string name, string address, int phone, float salary) : person(name, address, phone) {
            this->salary = salary;
        }
        float getSalary() {
            return this->salary;
        }
};

class manager : public officer {
    private:
        float extra;
    public:
        manager() : officer() {
            this->extra = 0;
        }
        manager(string name, string address, int phone, float salary, float extra) : officer(name, address, phone, salary) {
            this->extra = extra;
        }
        void xuat() {
            cout << left << setw(30) << this->getName();
            cout << left << setw(30) << this->getAddress();
            cout << left << setw(30) << this->getPhone();
            cout << left << setw(30) << this->getSalary();
            cout << left << setw(30) << this->extra;
        }
};

void title() {
    cout << left << setw(30) << "Ten";
    cout << left << setw(30) << "Dia chi";
    cout << left << setw(30) << "SDT";
    cout << left << setw(30) << "Luong";
    cout << left << setw(30) << "Extra" << endl;
}

int main() {
    int n;
    cout << "Nhap so luong doi tuong manager la: ";
    cin >> n;
    vector<manager> m;
    for(int i = 0; i < n; i++) {
        cout << "Nhap thong tin manager thu " << i + 1 << " la:" << endl;
        string nameVar;
        fflush(stdin);
        cout << "\t + nhap ten: ";
        getline(cin, nameVar);
        string addressVar;
        cout << "\t + nhap dia chi: ";
        getline(cin, addressVar);
        int phoneVar;
        cout << "\t + nhap sdt: ";
        cin >> phoneVar;
        float salaryVar;
        cout << "\t + nhap luong: ";
        cin >> salaryVar;
        float extraVar;
        cout << "\t + nhap extra: ";
        cin >> extraVar;
        manager manager(nameVar, addressVar, phoneVar, salaryVar, extraVar);
        m.push_back(manager);
    }
    cout << "Danh sach sau khi nhap la: " << endl;
    title();
    for(manager temp : m) {
        temp.xuat();
        cout << endl;
    }
    bool check = false;
    cout << "Danh sach doi tuong o Ha Noi va co luong khac 10tr la: ";
    for(manager temp : m) {
        if(temp.getAddress() == "Ha Noi" && temp.getSalary() != 10000) {
            temp.xuat();
            cout << endl;
            check = true;
        }
    }
    if(check == false) {
        cout << "Khong co doi tuong nao.";
    }
    return 0;
}