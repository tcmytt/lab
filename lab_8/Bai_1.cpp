#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
using namespace std;

class Basic
{
	protected:
	int thoigiangoi;
	int luuluong;
	public:
	Basic()
	{
		thoigiangoi=0;
		luuluong=0;
	}
	Basic(int thoigiangoi, int luuluong)
	{
		thoigiangoi=thoigiangoi;
		luuluong=luuluong;
	}
	~Basic()
	{}
	
	virtual void nhap()
	{
		cout<<"nhap thoi gian goi: ";	cin>>thoigiangoi;
		cout<<"nhap luu luong: ";	cin>>luuluong;
	}
	
	virtual void xuat()
	{
		cout<<"thoi gian goi: "<<thoigiangoi<<endl;
		cout<<"luu luong: "<<luuluong<<endl;
	}
	
	virtual int cuocdienthoai()
	{
		return thoigiangoi * 1000; 
	}
	
	virtual int cuocluuluong()
	{
		return luuluong * 200;
	}
	
	virtual int cuoctong()
	{
		int tong=0;
		tong = cuocdienthoai() + cuocluuluong();
		return tong + tong*(10/100);
	}
	
	// void sudung(int x,  int y)
//	{//
	//	thoigiangoi = x;//
	//	luuluong = y;//
//	}//
	
};	

class DataFix : public Basic
{
	public:
	int cuocluuluong()
	{
		return 1000000;
	}
	int cuocdienthoai()
	{
		return (luuluong * 200) *90/100;
	}
	void xuat()
	{
		Basic::xuat();
		cout<<"goi cuoc luu luong: "<<cuocluuluong()<<endl;
		cout<<"goi cuoc dien thoai: "<<cuocdienthoai()<<endl;
	}
};

class DataFree : public Basic
{
	private:
	int cuocthuebao;
	int luuluongfree;
	public:
	DataFree()
	{
		cuocthuebao=0;
		luuluongfree=0;
	}
	int cuocluuluong()
	{
		if(luuluong < luuluongfree)
		{
			return cuocthuebao;
		}
		else
		{
			return cuocthuebao + (luuluong - luuluongfree)*200;
		}
	}
	void nhap()
	{
		Basic::nhap();
		cout<<"nhap cuoc thue bao: ";	cin>>cuocthuebao;
		cout<<"nhap luu luong free: ";	cin>>luuluongfree;
	}
	void xuat()
	{
		Basic::xuat();
		cout<<"cuoc thue bao: "<<cuocthuebao<<endl;
		cout<<"luu luong free: "<<luuluongfree<<endl;
		cout<<"cuoc dien thoai: "<<cuocdienthoai()<<endl;
		cout<<"cuoc phai tra : "<<cuocluuluong()<<endl;
	
	}
};

class KhachHang
{
	private:
	char hoten[30];
	char cmnd[15];
	char diachi[30];
	Basic *goicuoc;
	public:
	KhachHang()
	{
		strcpy(hoten,"");
		strcpy(cmnd,"");
		strcpy(diachi,"");
		goicuoc=0;
	}
	KhachHang(char hoten[], char cmnd[], char diachi[], Basic *goicuoc)
	{
		strcpy(hoten,hoten);
		strcpy(cmnd,cmnd);
		strcpy(diachi,diachi);
		goicuoc = goicuoc;
	}	
	~KhachHang()
	{}
	void nhap()
	{
		fflush(stdin);
		cout<<"nhap ho va ten: ";	cin.getline(hoten,30);
		cout<<"nhap cmnd: ";		cin.getline(cmnd,15);
		cout<<"nhap dia chi: ";		cin.getline(diachi,30);
		cout<<"1. Datafix"<<endl;
		cout<<"2. Datafree"<<endl;
		int chon;
		cout<<"nhap lua chon cua ban: ";	cin>>chon;
		if(chon==1)
		{
			goicuoc = new DataFix();
			goicuoc->nhap();
		}
		else if(chon==2)
		{
			goicuoc= new DataFree();
			goicuoc->nhap();
		}
	}

	virtual int tinhcuochangthang()
	{
		goicuoc ->cuoctong();
	}
	
	void xuat()
	{
		cout<<"ho va ten: ";	cout<<hoten<<endl;
		cout<<"cmnd: ";		cout<<cmnd<<endl;
		cout<<"dia chi: ";	cout<<diachi<<endl;
		goicuoc->xuat();
		cout<<"cuoc tong phai dong la: "<<tinhcuochangthang()<<endl;
	}
	
	char * gethoten()
	{
		return hoten;
	}
		
};

int main()
{
	KhachHang kh[30];
	int n;
	cout<<"nhap so luong khach hang: ";	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"nhap thong tin khach hang thu: "<<i+1<<endl;
		kh[i].nhap();
	}
	cout<<"====================="<<endl;
	cout<<"Danh Sach thong tin khach hang la: "<<endl;
	for(int i=0;i<n;i++)
	{
		kh[i].xuat();
	}
	cout<<"====================="<<endl;
	KhachHang moi;
	cout<<"nhap thong tin khach hang can dang ky moi: "<<endl;
	moi.nhap();
	for(int i=0;i<n;i++)
	{
		if(strcmpi(kh[i].gethoten(), moi.gethoten())==0)
		{
			kh[i] = moi;
		}
	}
	
	cout<<"cuoc cuoi thang cua cac vi khach hang la: "<<endl;
	for(int i=0;i<n;i++)
	{
		kh[i].xuat();
	}
	
}
