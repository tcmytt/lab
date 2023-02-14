#include<iostream>
#include<iomanip>
using namespace std;

class HCN {
	private:
		int cd;
		int cr;
	public:
		HCN() {
			this->cd = 0;
			this->cr = 0;
		}
		~HCN() {}
		void nhap() {
			cout << "\t Nhap chieu dai: ";
			cin >> this->cd;
			cout << "\t Nhap chieu rong: ";
			cin >> this->cr;
		}
		void in() {
			cout << left << setw(20) << this->cd;
			cout << left << setw(20) << this->cr;
		}
		int chuvi() {
			return (this->cd + this->cr) * 2;
		}
		int dientich() {
			return (this->cd * this->cr);
		}
};

int main() {
	HCN a[100];
	int n;
	cout << "Nhap n = ";
	cin >> n;
	for(int i = 0; i < n; i++) {
		cout << "Nhap hinh chu nhat thu " << i + 1 << " la:" << endl;
		a[i].nhap();
	}
	cout << "Danh sach hinh chu nhat da nhap: " << endl;
	cout << left << setw(20) << "CHIEU DAI";
	cout << left << setw(20) << "CHIEU RONG";
	cout << left << setw(20) << "CHU VI";
	cout << left << setw(20) << "DIEN TICH" << endl;
	for(int i = 0; i < n; i++) {
		a[i].in();
		cout << left << setw(20) << a[i].chuvi();
		cout << left << setw(20) << a[i].dientich() << endl;
	}
	int chuvimax = 0;
	int dientichmin = a[0].dientich();
	for(int i = 0; i < n; i++) {
		if(chuvimax < a[i].chuvi()) {
			chuvimax = a[i].chuvi();
		}
		if(dientichmin > a[i].dientich()) {
			dientichmin = a[i].dientich();
		}
	}
	cout << "Chu vi hinh chu nhat lon nhat la: " << chuvimax << endl;
	cout << "Dien tich hinh chu nhat nho nhat la: " << dientichmin << endl;
	return 0;
}