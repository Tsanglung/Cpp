//建立圓柱體(Cylinder)類別
#include<iostream>
using namespace std;
class Cylinder //圓柱體類別
{
private:
	double radius,heigh,PI=3.14;//私有成員 半徑 高 圓周率
public:
	Cylinder(double ,double ,double PI=3.14);
	double area();//面積
	double vol();//體積
	void print();//半徑輸出
};
Cylinder::Cylinder(double r,double h,double PI) 
{
	radius = r;
	heigh = h;
}
double Cylinder::area()
{
	return (2 * PI * radius * radius + 2 * PI * radius * heigh);
}
double Cylinder::vol()
{
	return (PI * radius * radius * heigh);
}
void Cylinder::print()
{
	cout << "圓柱體半徑:" << radius << endl;
}
void main()
{
	Cylinder object(10, 2);//設定圓柱體半徑10，高2
	cout << "圓柱體面積:" << object.area() << endl;
	cout << "圓柱體體積:" << object.vol() << endl;
	object.print();//印出半徑
}