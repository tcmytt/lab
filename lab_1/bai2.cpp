#include <iostream>
using namespace std;
class DaThuc
{
	private:
		int a, b, c;
	
	public:
		DaThuc(int a = 0, int b = 0, int c = 0)
		{
			this->a = 0;
			this->b = 0;
			this->c = 0;
		}
		~DaThuc() {}
		void In();
		DaThuc tong(DaThuc dt1);
};
void DaThuc ::In()
{
	cout << a << "x^2"<< "+" << b << "x"<< c;
	
}
DaThuc DaThuc::tong(DaThuc dt1)
{
	DaThuc d;
	d.a = a + dt1.a;
	d.b = b + dt1.b;
	d.c = c + dt1.c;
	return d;
}
int main()
{
	int a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>e>>f;
	
	DaThuc dt1(a, b, c);
	DaThuc dt2(d, e, f);
	DaThuc tong2;
	tong2 = dt1.tong(dt2);
	cout << "Tong cua hai da thuc :";
	tong2.In();
	cout << endl;
	return 0;
}
