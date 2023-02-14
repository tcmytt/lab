#include<iostream.h>
#include<conio.h>
using namespace std;
template <class T>
T Nhap(T a[][100],int n,int m){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<"a["<<i<<"]"<<"["<<j<<"]: ";
			cin>>a[i][j];
			}
		}
}
template<typename T>
T Xuat(T a[][100],int n,int m){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<"\t"<<a[i][j]<<"\t";
			cout<<endl;
			}
		}
}
template<typename T>
T Max(T a[][100],int m,int n){
	T max=a[0][0];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(max<a[i][j]){
				max=a[i][j];
				}
			}
		}
		return max;
}
template<typename T>
T Sum(T a[][100],int m,int n){
	T sum=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(i==j){
				sum=sum+a[i][j];
				}
			}
		}
		return sum;
	}
template<typename T>
T Sort(T a[][100],int m,int n){
	int temp;
	for (int i=0;i<m;i++)
     for (int j=i+1;j<n;j++)
            if(a[i][i]>a[j][j])
           {
                 temp=a[i][i];
                a[i][i]=a[j][j];
                a[j][j]=temp;
           }
     cout<<Xuat(a,m,n);
	}
int main(){
	int a[100][100];
	int m,n;
	cout<<"Nhap so hang: ";
	cin>>m;
	cout<<"Nhap so cot: ";
	cin>>n;
	cout<<"Nhap ma tran: "<<Nhap(a,m,n)<<endl;
	cout<<"Xuat ma tran: "<<endl<<Xuat(a,m,n);
	cout<<"Phan tu lon nhat: "<<Max(a,m,n)<<endl;
	cout<<"Tong duong cheo chinh:"<<Sum(a,m,n)<<endl;
	cout<<"Mang sap xep theo duong cheo chinh tang dan"<<endl;
	cout<<Sort(a,m,n);
	getch();
	return 0;
}

