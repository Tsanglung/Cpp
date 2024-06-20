// 傳遞參數到基礎類別
#include <iostream>
#include <cstdlib>
using namespace std;
class Point
{
protected:
	int x, y;
public:
	Point(int n, int m) {	// Point 建立者
		x = n; y = m;
	}
	void showpoint() {
		cout << "p(" << x << ", " << y << ')' << endl;
	}
};
class Area : public Point
{
public:
	Area(int x, int y) : Point(x, y) {   // Area 建立者,並傳遞 x, y 參數到 Point
	}								void showarea() {
		cout << "length = " << x << "\twidth = " << y << "\tarea = " << x * y << endl;
	}
};
int main()
{
	Point p(3, 4);	// x=3, y=4
	Area a(5, 6);	// x=5, y=6
	cout << "利用基礎類別物件顯示點：";
	p.showpoint();	 // 顯示 p(3, 4)
	cout << endl;
	cout << "利用衍生類別物件顯示面積：";
	a.showarea();	// 顯示 area = 12
	cout << endl;
	system("pause"); return 0;
}
