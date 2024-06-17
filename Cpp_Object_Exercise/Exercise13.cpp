//Point、Circle 與 Cylinder 間接繼承類別
/*
(a) Point類別：保護區含radius資料變數，公用區含二個參數的Point建立者、setpoint() 函數將鍵盤輸入資料存入radius、getradius () 函數傳回radius值。
(b) Circle類別：以public型態繼承Point，保護區含area()  const函數計算圓面積，公用區含二參數的Circle建立者、getarea() const函數傳回area() 值。
(c) Cylinder類別：以public型態繼承Circle類別，保護區含volume()  const函數與height資料變數，公用區含三參數的Cylinder建立者、setheight () 與getheight () 設定與傳回height值、getvolume() const傳回volume() 值。
(d) 寫一main() 函數，首先利用建立者起始radius, height值，然後計算並輸出radius, height值、pi*radius^2面積與height*pi*radius^2的體積。再利用鍵盤輸入radius, height值，然後計算並輸出面積與體積。
(e) 將此題改用包含（Composition）重新設計
*/
#include <cstdlib>
#include <iostream>
#include <math.h>
using namespace std;
class Point
{
protected:	int radius;
public: 	Point(int r)
{
	radius = r;
}
	  void setradius(int r1) { radius = r1; }
	  int getradius() { return radius; }
};
class Circle : public Point
{
protected:	double area() { return 3.1415926 * pow(radius, 2); }
public:	Circle(int r2) : Point(radius)
{
	setradius(r2);
}
	  double getarea()
	  {
		  return area();
	  }
};
class Cylinder : public Circle
{
protected:	int height;
		 double volume() { return area() * height; }
public:	Cylinder(int r3, int h3) : Circle(radius)
{
	setradius(r3);	height = h3;
}
	  void setheight(int h3) { height = h3; }
	  int getheight() { return height; }
	  double getvolume() { return volume(); }
};
int main()
{
	Cylinder c1(5, 8);
	cout << "半徑 = " << c1.getradius() << " 公分" << endl << "高度 = " << c1.getheight() << " 公分" << endl << "圓面積 = " << c1.getarea() << " 平方公分" << endl << "圓柱面積 = " << c1.getvolume() << " 立方公分" << endl;
	int a, b;
	cout << "\n請輸入半徑與高：";
	cin >> a >> b;
	Cylinder c2(a, b);
	cout << "半徑 = " << c2.getradius() << " 公分" << endl << "高度 = " << c2.getheight() << " 公分" << endl
		<< "圓面積 = " << c2.getarea() << " 平方公分" << endl << "圓柱面積 = " << c2.getvolume() << " 立方公分" << endl;
	cout << endl;
	system("Pause");
	return 0;
}
