#include <iostream>

using namespace std;

template <class T> class Queue {
private:
	struct QNode {
		T _data;
		QNode* next;
		QNode* prev;
	
		QNode() {}
		
		QNode (T data) {
			_data = data;
			next = NULL;
		}
	};
	typedef QNode* QNodePtr;

	QNodePtr qHead, qTail;

	void resetQPtr() {
		qHead = qTail = NULL;
	}

	QNodePtr createNode(T& data) {
		QNodePtr n = new QNode(data);
		return n;
	}
public:
	Queue<T> () {
		this->resetQPtr();
	}
	~Queue<T> () {
		while (qHead) {
			QNodePtr q = qHead;
			qHead = qHead->next;
			delete q;
		}
		this->resetQPtr();
	}

	T pop() {
		if (qHead == NULL) { // danh sach rong
			throw "List empty";
		}
		QNodePtr q = qHead;
		qHead = qHead->next;
		T s = q->_data;
		delete q;
		return s;
	}

	void push(T& data) {
		QNodePtr q = this->createNode(data);
		if (qTail == NULL) { // danh sach rong
			qHead = qTail = q;
			return;
		}
		qTail->next = q;
		qTail = q;
	}
//	void Enqueue(T &data){
		
//		}
};

class Sach {
private:
	string ma, ten, tacGia;
	int soBanIn;

public:
	void nhap() {
		fflush(stdin);
		cout<<"Nhap ma:";
		getline(cin,ma);
		cout<<"Nhap ten sach: ";
		getline(cin,ten);
		cout<<"Nhap tac gia: ";
		getline(cin,tacGia);
	}

	void xuat() {
		cout<<"Ma:"<<ma<<endl;
		cout<<"Ten sach:"<<ten<<endl;
		cout<<"Tacgia:"<<tacGia<<endl;
		
		
	}
};

int main() {
	Queue<Sach> q;
	int n ;
	cout<<"Nhap so luong sach: ";
	cin>>n;

	for (int i = 0; i < n; ++i) {
		Sach a;
		a.nhap();
		q.push(a);
	}

	Sach top = q.pop();
	top.xuat();
	
	return 0;
}
