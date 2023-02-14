#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

class NGUOI {
	private:
		string hoten;
		int tuoi;
		string nghenghiep;
		string quoctich;
	public:
		NGUOI() {
	 		this->hoten = "";
	 		this->tuoi = 0;
	 		this->nghenghiep = "";
	 		this->quoctich = "";
		}
		NGUOI(string hoten, int tuoi, string nghenghiep, string quoctich) {
			this->hoten = hoten;
	 		this->tuoi = tuoi;
	 		this->nghenghiep = nghenghiep;
	 		this->quoctich = quoctich;
		}
		~NGUOI() {}
		void nhap() {
			fflush(stdin);
			cout << "\t Nhap ho ten: ";
			getline(cin, this->hoten);
			cout << "\t Nhap tuoi: ";
			cin >> this->tuoi;
			fflush(stdin);
			cout << "\t Nhap nghe nghiep: ";
			getline(cin, this->nghenghiep);
			cout << "\t Nhap quoc tich: ";
			getline(cin, this->quoctich);
		}
		void in() {
			cout << left << setw(30) << this->hoten;
			cout << left << setw(30) << this->tuoi;
			cout << left << setw(30) << this->nghenghiep;
			cout << left << setw(30) << this->quoctich << endl;
		}
		string gethoten() {
			return this->hoten;
		}
		string getnghenghiep() {
			return this->nghenghiep;
		}
		string getquoctich() {
			return this->quoctich;
		}
		int gettuoi() {
			return this->tuoi;
		}
};

int main() {
	NGUOI a[50];
	int n;
	cout << "Nhap so luong nguoi can luu tru la: ";
	cin >> n;
	for(int i = 0; i < n; i++) {
		cout << "Nhap thong tin nguoi thu " << i + 1 << " la: " << endl;
		a[i].nhap();
	}
	cout << "Hien thi danh sach da sap xep la: " << endl;
	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			if(a[i].gethoten() > a[j].gethoten()) {
				swap(a[i], a[j]);
			}
		}
	}
	for(int i = 0; i < n; i++) {
		a[i].in();
	}
	bool checkbacsi = false;
	cout << "Danh sach nguoi ca nghe nghiep la bac si." << endl;
	for(int i = 0; i < n; i++) {
		if(a[i].getnghenghiep() == "bac si") {
			a[i].in();
			checkbacsi = true;
		}
	}
	if(checkbacsi == false) {
		cout << "Khong co ai co nghe la bac si." << endl;
	}
	for(int i = 0; i < n; i++) {
		if(a[i].getquoctich() == "campuchia") {
			
			for(int j = i; j < n - 1; j++) {
				a[j] = a[j + 1];
			}
			i--;
			n = n - 1;
		}
	}
	for(int i = 0; i < n; i++) {
		a[i].in();
	}
	bool check = false;
	for(int i = 0; i < n; i++) {
		if(a[i].gethoten() == "Le Dai Nghia") {
			check = true;
			a[i].in();
		}
	}
	if(check == 0) {
		n++;
		cout << "Khong tim thay nguoi co ten Le Dai Nghia.\nNhap thong tin can chen la: " << endl;
		a[n - 1].nhap();
		cout << "Danh sach nguoi sau khi them la: " << endl;
		for(int i = 0; i < n; i++) {
			a[i].in();
		}
	}
	NGUOI max = a[0];
	NGUOI min = a[0];
	for(int i = 1; i < n; i++) {
		if(max.gettuoi() < a[i].gettuoi()) {
			max = a[i];
		}
		if(min.gettuoi() > a[i].gettuoi()) {
			min = a[i];
		}
	}
	cout << "Nguoi co tuoi lon nhat la: " << endl;
	max.in();
	cout << "Nguoi co tuoi nho nhat la: " << endl;
	min.in();
	return 0;
}