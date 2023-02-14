#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

class SV {
	private:
		int sbd;
		string hoten;
		float toan;
		float ly;
		float hoa;
		float tongdiem;
	public:
		SV() {
			this->sbd = 0;
			this->hoten = "";
			this->toan = 0;
			this->ly = 0;
			this->hoa = 0;
			this->tongdiem = 0;
		}
		SV(int sbd, string hoten, int toan, int ly, int hoa, int tongdiem) {
			this->sbd = sbd;
			this->hoten = hoten;
			this->toan = toan;
			this->ly = ly;
			this->hoa = hoa;
			this->tongdiem = tongdiem;
		}
		~SV() {}
		void nhap() {
			cout << "\t Nhap so bao danh: ";
			cin >> this->sbd;
			fflush(stdin);
			cout << "\t Nhap ho ten: ";
			getline(cin, this->hoten);
			cout << "\t Nhap diem toan: ";
			cin >> this->toan;
			cout << "\t Nhap diem ly: ";
			cin >> this->ly;
			cout << "\t Nhap diem hoa: ";
			cin >> this->hoa;
			this->tongdiem = this->toan + this->ly + this->hoa;
		}
		void in() {
			cout << left << setw(20) << this->sbd;
			cout << left << setw(20) << this->hoten;
			cout << left << setw(20) << this->toan;
			cout << left << setw(20) << this->ly;
			cout << left << setw(20) << this->hoa;
			cout << left << setw(20) << this->tongdiem << endl;
		}
		float gettongdiem() {
			return this->tongdiem;
		}
};

void tieude() {
	cout << left << setw(20) << "SBD";
	cout << left << setw(20) << "HO TEN";
	cout << left << setw(20) << "TOAN";
	cout << left << setw(20) << "LY";
	cout << left << setw(20) << "HOA";
	cout << left << setw(20) << "TONG DIEM" << endl;
}

int main() {
	SV *a;
	int n;
	cout << "Nhap so luong sinh vien la: ";
	cin >> n;
	a = new SV[n];
	for(int i = 0; i < n; i++) {
		cout << "Nhap thong tin sinh vien thu " << i + 1 << " la:" << endl;
		a[i].nhap();
	}
	cout << "Hien thi danh sach sinh vien la: " << endl;
	tieude();
	for(int i = 0; i < n; i++) {
		a[i].in();
	}
	cout << "Danh sach sinh vien trung tuyen la: " << endl;
	tieude();
	for(int i = 0; i < n; i++) {
		if(a[i].gettongdiem() >= 20) {
			a[i].in();
			cout << endl;
		}
	}
	SV maxtongdiem = a[0];
	cout << "Sinh vien thu khoa la: " << endl;
	tieude();
	for(int i = 0; i < n; i++) {
		if(a[i].gettongdiem() >= 20) {
			if(maxtongdiem.gettongdiem() < a[i].gettongdiem()) {
				maxtongdiem = a[i];
			}
		}
	}
	if(maxtongdiem.gettongdiem() == a[0].gettongdiem() && a[0].gettongdiem() <= 20) {
		cout << "Khong co sinh vien nao trung tuyen.";
	}
	else {
		maxtongdiem.in();
	}
	return 0;
}