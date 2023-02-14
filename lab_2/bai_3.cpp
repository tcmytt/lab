#include<iostream>
#include<cstring>
#include<iomanip>
#include<vector>
using namespace std;

class TS {
	private:
		string hoten;
		int toan;
		int van;
	public:
		TS() {
			this->hoten = " ";
			this->toan = 0;
			this->van = 0;
		}
		~TS() {}
		void input() {
			fflush(stdin);
			cout << "\tNhap ho va ten: ";
			getline(cin, this->hoten);
			cout <<  "\tNhap diem toan: ";
		 	cin >> this->toan;
		 	cout <<  "\tNhap diem van: ";
		 	cin >> this->van;
		}
		void output() {
			cout << left << setw(20) << this->hoten;
			cout << left << setw(20) << this->toan;
			cout << left << setw(20) << this->van << endl;
		}
		string gethoten() {
			return this->hoten;
		}
		int getdiemtoan() {
			return this->toan;
		}
		int getdiemvan() {
			return this->van;
		}
};

void delete_ts(TS *a, int &n, int pos) {
	if(n <= 0){
        return;
    }
    if(pos < 0){
        pos = 0;
    }
    else if(pos >= n){
        pos = n-1;
    }
    for(int i = pos; i < n - 1; i++){
        a[i] = a[i+1];
    }
    --n;
}

int main() {
	TS *a;
	int n;
	do {
		cout << "Nhap so luong thi sinh la: n = ";
		cin >> n;
		if(n <= 0) {
			cout << "Nhap sai!! Yeu cau nhap lai." << endl;
		}
	} while(n <= 0);
	a = new TS[n];
	for(int i = 0; i < n; i++) {
		cout << "Thong tin thi sinh thu " << i + 1 << " la:" << endl;
		a[i].input();
	}
	cout << "Hien thi danh sach thi sinh." << endl;
	cout << left << setw(20) << "HO TEN";
	cout << left << setw(20) << "DIEM TOAN";
	cout << left << setw(20) << "DIEM VAN" << endl;
	for(int i = 0; i < n; i++) {
		a[i].output();
	}
	string varhoten;
	cout << "Nhap ho ten thi sinh can tim la: ";
	getline(cin, varhoten);
	for(int i = 0; i < n; i++) {
		if(a[i].gethoten() == varhoten) {
			cout << "Da tim thay sinh vien. Hien thi diem:" << endl;
			cout << "\tDiem toan: " << a[i].getdiemtoan() << endl;
			cout << "\tDiem van: " << a[i].getdiemvan();
			delete_ts(a, n, i);
			break;
		}
	}
	cout << "\nDa xoa thanh cong." << endl;
	cout << "Danh sach sinh vien sau khi xoa la: " << endl;
	for(int i = 0; i < n; i++) {
		a[i].output();
	}
	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			if(a[i].gethoten() > a[j].gethoten()) {
				swap(a[i], a[j]);
			}
		}
	}
	cout << "Danh sach sinh vien sau khi sap xep la: " << endl;
	for(int i = 0; i < n; i++) {
		a[i].output();
	}
	cout << endl;
	delete []a;
	return 0;
}