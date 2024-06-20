/*
建立 Point 類別，私有成員 整數 x,y座標
公開成員函數:建構子、多載+、++運算子
getxy() 取得座標、setxy 設定座標
*/
#include<cstdlib>
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
class Point
{
private:
	int x, y;
public:
	Point();
	Point operator+(Point); //多載+二元運算子
	Point operator+(int);	//多載+二元運算子
	Point operator++();	//多載+一元運算子(前置運算);
	void getxy();
	void setxy(int, int);
};
Point::Point() { x = 0; y = 0; }
Point Point::operator+(Point obj)
{
	Point t;
	t.x = x + obj.x;
	t.y = y + obj.y;
	return t;
}
Point Point::operator+(int n)
{
	Point t;
	t.x = x + n;
	t.y = y + n;
	return t;
}
Point Point::operator++()
{
	x = x + 1;
	y = y + 1;
	return *this;
}
void Point::getxy()
{
	cout << x << "," << y << endl;
}
void Point::setxy(int x1, int y1)
{
	x = x1 + 1;
	y = y1 + 1;
}
int main() {
	Point p1, p2, p3;
	p1.setxy(10, 20);
	cout << "P1座標:";
	p1.getxy();
	p2.setxy(15, 23);
	cout << "P2座標:";
	p2.getxy();
	p3.setxy(0, 0);
	cout << "P3座標:";
	p3.getxy();
	p3 = p1 + p2;
	cout << "P3=(P1+P2)座標:";
	p3.getxy();
	p3 = p3 + 6;
	cout << "P3+6後座標:";
	p3.getxy();
	++p3;
	cout << "P3+1後座標座標:";
	p3.getxy();
	system("pause");
	return EXIT_SUCCESS;
}