#include<iostream.h>
 
class Quay
{
private:
int soThuTu;
int dienTich;
protected:
double doanhThu;
virtual double tinhThueDoanhThu()=0;
virtual double tinhTienDichVu()
 {
 return 0;
}
double tinhTienThueQuay()
 {
 return 400000000 * dienTich;
}
public:
virtual double tinhTienPhaiDong()
{
 return tinhTienThueQuay() + tinhTienDichVu() +
tinhThueDoanhThu();

}
virtual void nhap(istream & is)
{
cout << "Nhap so thu tu: ";
is >> soThuTu;
cout << "Nhap dien tich: ";
is >> dienTich;
cout << "Nhap doanh thu: ";
is >> doanhThu;
}
virtual void xuat()
{
cout << "\n So thu tu: ";
cout << soThuTu;
cout << "\nDien tich: ";
cout<< dienTich;
cout <<"\nDoanh thu: ";
cout<< doanhThu;
}
virtual int check() = 0;
int Getdt()
{
return dienTich;
}
};

class QuayThucPham : public Quay
{
private:
double tienDichVu;
protected:
double tinhThueDoanhThu()
 {
return doanhThu * 5;
 }
double tinhTienDichVu()
 {
return tienDichVu;
 }
virtual double tinhTienPhaiDong()
{
 return tinhTienThueQuay() + tinhTienDichVu() +
tinhThueDoanhThu();
}
virtual void nhap(istream & is)
 {
Quay::nhap(is);
cout << " Nhap tien dich vu: ";
is>>tienDichVu;
}
virtual void xuat()
{
Quay::xuat();
cout << "\nTien dich vu: ";
cout << tienDichVu;
cout << "\nThue doanh thu: ";
cout << QuayThucPham::tinhThueDoanhThu();
cout<<"\nTien phai dong:"<<QuayThucPham::tinhTienPhaiDong();
}
virtual int check(){return 1; }
};
class QuayQuanAo : public Quay
{
	protected : 
	
	double tinhThueDoanhThu()
	{
		return doanhThu*10;
	}	
	double tinhTienPhaiDong()
	{
		return tinhThueDoanhThu();
	}
	virtual void nhap(istream & is)
 {
	Quay::nhap(is);
	cout << " Nhap tien doanh thu : ";
	is>>doanhThu;
	}
	virtual void xuat()
	{
	Quay::xuat();
	cout << "\nTien doanh thu : ";
	cout << "\nThue doanh thu: ";
	cout << QuayQuanAo::tinhThueDoanhThu();
	cout<<"\nTien phai dong:"<<QuayQuanAo::tinhTienPhaiDong();
	}
	virtual int check(){return 1; }
	};
	
	main()
	{
	Quay *a[100];
	int n;
	cout<<"Nhap n: ";
	cin>>n;
	cout<<"Danh sach cac quay ";
	for(int i=0;i<n;i++)
	{
     a[i].nhap();
	a[i].xuat();
	}	
	};
	