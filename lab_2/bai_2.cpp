#include<iostream>
using namespace std;

int ucln(int a, int b) {
	if(a % b == 0) {
		return b;
	}
	return ucln(a, a % b);
}

class PS {
	private:
		int tuso;
		int mauso;
	public:
		PS() {
			this->tuso = 0;
			this->mauso = 1;
		}
		~PS() {}
		void nhap() {
			cout << "\t Nhap tu so: ";
			cin >> this->tuso;
			cout << "\t Nhap mau so: ";
			cin >> this->mauso;
		}
		void hienthi() {
			cout << this->tuso << "/" << this->mauso;
		}
		PS tong(PS ps2) {
			this->tuso = this->tuso * ps2.mauso + ps2.tuso * this->mauso;
			this->mauso = this->mauso * ps2.mauso;
			return *this;
		}
		PS tich(PS ps2) {
			this->tuso = this->tuso * ps2.tuso;
			this->mauso = this->mauso * ps2.mauso;
			return *this;
		}
		PS rutgon() {
			int temp = ucln(this->tuso, this->mauso);
			this->tuso = this->tuso / temp;
			this->mauso = this->mauso / temp;
			return *this;
		}
};

int main() {
	PS *a;
	int n;
	cout << "Nhap so luong phan so la: ";
	cin >> n;
	a = new PS[n];
	for(int i = 0; i < n; i++) {
		cout << "Nhap phan so thu " << i + 1 << " la:" << endl;
		a[i].nhap();
	}
	for(int i = 0; i < n; i++) {
		cout << "\nThong tin cua phan so thu " << i + 1 << " la:" << endl;
		a[i].rutgon();
		a[i].hienthi();
	}
	cout << endl;
	PS total = a[0];
	PS vartich = a[0];
	for(int i = 1; i < n; i++) {
		total.tong(a[i]);
		vartich.tich(a[i]);
	}
	cout << "Tong cua tat ca phan so la: " << endl;
	total.rutgon();
	total.hienthi();
	cout << endl;
	cout << "Tich cua tat ca phan so la: " << endl;
	vartich.hienthi();
	cout << endl;
	return 0;
}