#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
class CN
{
	private:
		char ht[30];
		int t;
		char qq[30];
		float bl;

	public:
		CN(char ht[] = " ", char qq[] = " ", int t = 0, float bl = 0)
		{
			ht = ht;
			qq = qq;
			t = t;
			bl = bl;
		}
		~CN()
		{
		}
		void Nhap()
		{
			fflush(stdin);
			cout << "Nhap vao ten cong nhan:";
			cin.getline(ht, 30);
			cout << "Nhap vao que quan:";
			cin.getline(qq, 30);
			cout << "Nhap vao tuoi:";
			cin >> t;
			cout << "Nhap vao bac luong:";
			cin >> bl;
		}
		float Tienluong()
		{
			return bl * 2500 * ((bl * 20) / 100);
		}
		void Xuat()
		{
			cout << setw(15) << "Ten" << setw(15) << "Que quan" << setw(15) << "Tuoi" << setw(15) << "Bac luong" << setw(15) << "Tien" << endl;
			cout << setw(15) << ht << setw(15) << qq << setw(15) << t << setw(15) << bl << setw(15) << Tienluong() << endl;
		}
};
int main()
{
	CN a;
	a.Nhap();
	a.Xuat();
	return 0;
}