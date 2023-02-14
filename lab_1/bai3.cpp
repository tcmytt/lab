#include<iostream>
using namespace std;

class SP {
	private:
		int pt, pa;
	public:
		SP(int a = 0, int b = 0) {
			this->pt = a;
			this->pa = b;
		}
		~SP() {}
		void in() {
			if(this->pa > 0) {
				cout << this->pt << "+" << this->pa << "*j";
			}
			else {
				cout << this->pt << this->pa << "*j";
			}
		}
		SP operator + (SP b) {
			SP c;
			c.pt = this->pt + b.pt;
			c.pa = this->pa + b.pa;
			return c;
		}
};

int main() {
	SP p1(5, -8);
	SP p2(-7, 3);
	cout << "tong 2 so phuc la: ";
	(p1 + p2).in();
	cout << endl;
	return 0;
}