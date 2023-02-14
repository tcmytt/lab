//lap7 bai8
#include<iostream>
#include<ctime>
#define clear_console system("cls")
using namespace std;
template<class TYPE>
void nhap(TYPE *a,int n)
{
	srand(time(NULL));
	for(int i =0;i<n;i++)
	{
		a[i] = rand() % 100;
	}
}
template <class TYPE>
void xuat(TYPE *a,int n)
{
	for(int i =0;i<n-1;i++)
	{
		cout<<a[i]<<",";
	}
	cout<<a[n-1]<<endl;
	
}
template<class TYPE>
TYPE tong(TYPE *a,int n)
{
	TYPE _tong = 0;
	for(int i = 0;i<n;i++)
	{
		_tong += a[i];
	}
	return _tong;
}
template<class TYPE>
void sapxep(TYPE *a,int n)
{
	for(int i =0;i<n;i++)
	
		for(int j = 0;j<n;j++)
		
			if(a[i]>a[j])
			swap(a[i],a[j]);
		
	xuat(a,n);
}
template <class TYPE>
TYPE max(TYPE *a,int n)
{
	TYPE max = a[0];
	for(int i = 0;i<n;i++)
	{
		if(a[i]>max)
		max = a[i];
	}
	return max;
}
template<class TYPE>
int counter(TYPE *a,int n,int x)
{
	int _counter = 0;
	for(int i =0;i<n;i++)
	{
		if(a[i]!=x)
		_counter++;
	}
	return _counter;
}
template<class TYPE>
int tim(TYPE *a,int n,int x)
{
	int pos;
	for(int i =0;i<n;i++)
	{
		if(a[i] == x)
		pos = i;
	}
	return pos;
}
template<class TYPE>
void themphantu(TYPE *a,int &n,int k,int &pos)
{
	if(pos<0)
	pos=0;
	else if(pos>n)
	pos =n;
	for(int i =n;i>pos;i--)
	{
		a[i] = a[i-1];
	}
	a[pos] = k;
	n++;
}
template<class TYPE>
void xoaphantu(TYPE *a,int &n,int k)
{
	for(int i = 0;i<n;i++)
	{
		if(a[i] != k)
		{
			break;
		}
		else{
			a[i] =a[i+1];
			n--;
		}
	}
}
int main()
{
	int n;
	do
	{
		cout<<"nhap so luong phan tu:";
		cin>>n;
		if(n <= 0)
		clear_console;
	}while(n<=0);
	int *a = new int [n];
	nhap(a,n);
	clear_console;
	cout<<"mang vua nhap :";
	xuat(a,n);
	cout<<"tong cac phan tu trong mang :"<<tong(a,n)<<endl;
	cout<<"mang sau khi sap xep :";
	sapxep(a,n);
	int x;
	cout<<"nhap phan tu :";
	cin>>x;
	cout<<"Co"<<counter(a,n,x)<<"khac"<<x<<"trong mang"<<endl;
	cout<<"nhap phan tu can tim :";
	cin>>x;
	cout<<"phan tu"<<x<<"nam o vi tri"<<tim(a,n,x)<<endl;
	int k,pos;
	cout<<"nhap vi tri can them :";
	cin>>pos;
	cout<<"nhap phan tu can them :";
	cin>>k;
	cout<<"mang sau khi them phan tu"<<k<<"vao vi tri"<<pos<<":";
	themphantu(a,n,k,pos);
	xuat(a,n);
	cout<<"nhap phan tu can xoa :";
	cin>>k;
	xoaphantu(a,n,k);
	cout<<"mang sau khi xoa phan tu "<<k<<":";
	xuat(a,n);
	return 0;
	
}