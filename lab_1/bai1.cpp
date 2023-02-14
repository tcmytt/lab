#include <iostream>
using namespace std;
class HCN
{
	private:
		float cd;
		float cr;
	public:
		HCN()
		{
			this->cd = cd;
			this->cr = cr;
		}
		~HCN() {}
		void Nhap()
		{
			cout << "+ Nhap chieu dai hinh chu nhat:";
			cin >> this->cd;
			cout << "+Nhap chieu rong hinh chu nhat:";
			cin >> this->cr;
		}
		void Xuat()
		{
			cout << "\n+ Chieu dai hinh chu nhat:" << this->cd << endl;
			cout << "\n+ Chieu rong hinh chu nhat:" << this->cr << endl;
		}
		float CV()
		{
			return (this->cd + this->cr) * 2;
		}
		float DT()
		{
			return this->cd * this->cr;
		}
};

int main()
{
	HCN a;
	a.Nhap();
	a.Xuat();
	cout << "Chu vi hinh chu nhat:" << a.CV() << endl;
	cout << "Dien tich hinh chu nhat:" << a.DT() << endl;
	return 0;
}