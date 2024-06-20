// 多重繼承
#include <iostream>
#include <cstdlib>
using namespace std;
class PointXY
{
protected:	int x, y;
public:      void setxy(int n, int m) { x = n; y = m; }                  PointXY(int n, int m) { cout << "呼叫PointXY 建構子\n"; x = n; y = m; }
};
class PointZ
{
protected:	int z;
public:	void setz(int o) { z = o; }
	  PointZ(int  o) { cout << "呼叫PointZ 建構子\n"; z = o; }
};
class Cube : public PointXY, public PointZ		// 以 public 繼承 PointXY 類別,以 public 繼承 PointZ 類別
{
public:          void showxy() { cout << "平面座標 : p(" << x << ", " << y << ") " << endl; }
	  void showxyz() { cout << "空間座標 : s(" << x << ", " << y << ", " << z << ") " << endl; }
	  void showarea() { cout << "面積 = " << x * y << endl; }
	  void showcube() { cout << "體積 = " << x * y * z << endl; }
	  Cube(int a, int b, int c) : PointXY(a, b), PointZ(c) { cout << "呼叫Cube 建構子\n"; }

};
int main()
{
	Cube p(1, 2, 3);
	//p.setxy(2,5);	// 直接呼叫基礎類別1成員
	p.showxy();	// 直接呼叫衍生類別成員
	p.showarea();	// 直接呼叫衍生類別成員
	cout << endl;
	//p.setz(8);	// 直接呼叫基礎類別2成員
	p.showxyz();	// 直接呼叫衍生類別成員
	p.showcube();	// 直接呼叫衍生類別成員
	cout << endl;
	system("pause"); return 0;
}
