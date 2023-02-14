#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
class GV
{
	private:
		char ht[30];
		int t;
		char bc[15];
		char cn[20];
		float bl;

	public:
		GV() {}
		~GV() {}
		void Nhap()
		{
			fflush(stdin);
			cout << "Nhap ho va ten:";
			cin.getline(this->ht, 30);
			cout << "Nhap bang cap:";
			cin.getline(this->bc, 15);
			cout << "Nhap chuyen nganh:";
			cin.getline(this->cn, 20);
			cout << "Nhap tuoi giao vien:";
			cin >> this->t;
			cout << "Nhap vao bac luong:";
			cin >> this->bl;
		}
		float TienLuong()
		{
			return this->bl * 1490;
		}
		void Xuat()
		{
			cout << setw(20) << "Ho ten" << setw(15) << "Tuoi" << setw(20) << "Bang cap" << setw(20) << "Chuyen nganh";
			cout << setw(15) << "Bac luong" << setw(15) << "Tien luong" << endl;
			cout << setw(20) << this->ht << setw(15) << this->t << setw(20) << this->bc << setw(20) << this->cn;
			cout << setw(15) << this->bl << setw(15) << TienLuong() << endl;
		}
};
int main()
{
	GV x;
	x.Nhap();
	x.Xuat();
	return 0;
}