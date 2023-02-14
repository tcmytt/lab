#include<iostream>
#include<cstring>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;

class Person {
    private:
        char name[50], address[40];
        int phone;
    public:
        Person() {
            strcpy(this->name, "");
            strcpy(this->address, "");
            this->phone = 0;
        }
        Person(char name[], char address[], int phone) {
            strcpy(this->name, name);
            strcpy(this->address, address);
            this->phone = phone;
        }
        ~Person() {}

        char* getName() {
            return this->name;
        }
        void setName(char name[]) {
            strcpy(this->name, name);
        }
        char* getAddress() {
            return this->address;
        }
        void setAddress(char address[]) {
            strcpy(this->address, address);
        }
        int getPhone() {
            return this->phone;
        }
        void setPhone(int phone) {
            this->phone = phone;
        }
};

class Officer : public virtual Person {
    private:
        float salary;
    public:
        Officer() : Person() {
            this->salary = 0;
        }
        Officer(char name[], char address[], int phone, float salary) : Person(name, address, phone) {
            this->salary = salary;
        }
        ~Officer() {}

        float getSalary() {
            return this->salary;
        }
};

class Student : public virtual Person {
    private:
        float fee;
    public:
        Student() : Person() {
            this->fee = 0;
        }
        Student(char name[], char address[], int phone, float fee) : Person(name, address, phone) {
            this->fee = fee;
        }
        ~Student() {}

        float getFee() {
            return this->fee;
        }
};

void tieuDe() {
    cout << left << setw(30) << "Name";
    cout << left << setw(30) << "Address";
    cout << left << setw(30) << "Phone";
    cout << left << setw(30) << "Salary";
    cout << left << setw(30) << "Fee" << endl;
}

class OffStudent : public Officer, public Student {
    public:
        OffStudent(char name[], char address[], int phone, float salary, float fee) : Person(name, address, phone), Officer(name, address, phone, salary), Student(name, address, phone, fee) {}
        void OutScreen() {
            cout << left << setw(30) << this->getName();
            cout << left << setw(30) << this->getAddress();
            cout << left << setw(30) << this->getPhone();
            cout << left << setw(30) << this->getSalary();
            cout << left << setw(30) << this->getFee();
        }
};

bool cmp(OffStudent a, OffStudent b) {
    return a.getName() < b.getName();
}

int main() {
    int n;
    vector<OffStudent> offstudents;
    cout << "Nhap so luong doi tuong can luu tru la: ";
    do {
        cin >> n;
        if(n < 1) {
            cout << "Nhap sai! Yeu cau nhap lai: ";
        }
    } while(n < 1);
    for (int i = 0; i < n; i++) {
        cout << "Thong tin doi tuong thu " << i + 1 << " la:" << endl;
        char newName[50];
        cout << "\t+ Nhap ho ten: ";
        fflush(stdin);
        cin.getline(newName, 50);
        char newAddress[40];
        cout << "\t+ Nhap dia chi: ";
        cin.getline(newAddress, 40);
        int newPhone;
        cout << "\t+ Nhap phone: ";
        cin >> newPhone;
        int newSalary;
        cout << "\t+ Nhap salary: ";
        cin >> newSalary;
        int newFee;
        cout << "\t+ Nhap fee: ";
        cin >> newFee;
        OffStudent temp(newName, newAddress, newPhone, newSalary, newFee);
        offstudents.push_back(temp);
    }
    cout << "Hien thi danh sach la:" << endl;
    tieuDe();
    for(OffStudent temp : offstudents) {
        temp.OutScreen();
        cout << endl;
    }
    cout << "Danh sach doi tuong co luong 5 trieu la:" << endl;
    tieuDe();
    for(OffStudent temp : offstudents) {
        if(temp.getSalary() == 5000) {
            temp.OutScreen();
            cout << endl;
        }
    }
    sort(offstudents.begin(), offstudents.end(), cmp);
    cout << "Hien thi danh sach sau khi sap xep la:" << endl;
    tieuDe();
    for(OffStudent temp : offstudents) {
        temp.OutScreen();
        cout << endl;
    }
    return 0;
}