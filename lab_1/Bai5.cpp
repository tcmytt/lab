#include <iostream>
#include <cmath>
using namespace std;

float UCLN(float a, float b)
{
	a = abs(a);
	b = abs(b);
	while (a != b)
	{
		if (a > b)
		{
			a = a - b;
		}
		else
		{
			b = b - a;
		}
	}
	return a;
}

class phanso
{
private:
	float tuso, mauso;

public:
	phanso(float ts = 0, float ms = 1)
	{
		this->tuso = ts;
		this->mauso = ms;
	}
	~phanso() {}
	void nhap()
	{
		cout << "Nhap tu so: ";
		cin >> this->tuso;
		do
		{
			cout << "Nhap mau so: ";
			cin >> this->mauso;
			if (this->mauso == 0)
			{
				cout << "Mau so phai khac 0!!" << endl;
			}
		} while (this->mauso == 0);
	}

	void in()
	{
		cout << this->tuso << "/" << this->mauso;
	}
	phanso tong(phanso p1)
	{
		phanso p;
		float k;
		p.tuso = (this->tuso * p1.mauso) + (this->mauso * p1.tuso);
		p.mauso = this->mauso * p1.mauso;
		k = UCLN(p.gettuso(), p.getmauso());
		p.tuso = p.tuso / k;
		p.mauso = p.mauso / k;
		return p;
	}

	float gettuso()
	{
		return this->tuso;
	}
	float getmauso()
	{
		return this->mauso;
	}
};

int main()
{
	phanso p1(1, 3);
	phanso p2(2, 5);
	phanso tong;
	tong = p1.tong(p2);
	cout << "Tong 2 phan so la: ";
	tong.in();
	return 0;
}