#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Date{
	private:
		int ngay,thang,nam;
	public:
		void Nhap();
		void Tang1Ngay();
		int NgayTrongThang();
		void TangKngay();
		void ChuanHoaNgay();
		int KhoangCach(Date x);
		int SoNgay();
		void Xuat();
};
int Date::SoNgay(){
	ChuanHoaNgay();
	int Sum = 0;
	int S= NgayTrongThang();
	nam = nam *365;
	for(int i=1;i<= thang;i++)
	{
		thang = thang * S;
	}
	Sum = nam + thang + ngay;
	return Sum;
}
int Date::KhoangCach(Date x)
{
	int NgayMoi = x.SoNgay();
	return NgayMoi - SoNgay();
}
void Date::TangKngay(){
	int k ;
	cout <<"Nhap vao k ngay can them: ";
	cin >> k;
	ngay +=k;
	ChuanHoaNgay();
}
void Date::Xuat(){
	cout <<ngay<<'/'<<thang<<'/'<<nam <<endl;
}
void Date::Tang1Ngay(){
	ngay++;
	ChuanHoaNgay();
}
void Date::ChuanHoaNgay(){
	int S = NgayTrongThang();
	if(ngay > S)
	{
		thang = thang + ngay/S;
		ngay = ngay% S;
	}
	if(thang > 12)
	{
		nam = thang /12;
		thang = thang %12;
	}
}
void Date::Nhap(){
	cout <<"Nhap ngay: ";cin >> ngay;
	if(ngay < 0)
	{
		while(ngay < 0)
		{
			cout <<"Nhap lai ngay: ";
			cin >> ngay;
		}
	}
	cout <<"Nhap thang: ";cin >> thang;
	if(thang < 0)
	{
		while(thang < 0)
		{
			cout <<"Nhap lai thang: ";
			cin >> thang;
		}
	}
	cout <<"Nhap nam: ";cin >> nam;
	if(nam < 0)
	{
		while(nam < 0)
		{
			cout <<"Nhap lai nam: ";
			cin >> nam;
		}
	}
}
int Date::NgayTrongThang(){
	if(thang == 1 or thang == 3 or thang == 5 or thang == 7 or thang == 8 or thang == 10 or thang ==12)
	return 31;
	else if(thang == 2)return 28;
	else return 30;
}
int main()
{
	Date a;
	a.Nhap();
	a.Xuat();
	a.Tang1Ngay();
	cout <<"Sau khi tang them 1 ngay: "<<endl;
	a.Xuat();
	a.TangKngay();
	cout <<"Sau khi tang k ngay: "<<endl;
	a.Xuat();
	Date x;
	x.Nhap();
	return 0;
}
