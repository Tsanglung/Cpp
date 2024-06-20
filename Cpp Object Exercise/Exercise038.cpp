#include<iostream>
using namespace std;
//抽象類別
class shape
{
protected:	int color;
public:	
	  shape(int color) { this->color = color; }
	  virtual void draw() { cout << "draw shape---do nothing" << endl; };
	  //virtual void draw()=0;
	  void print() { cout << "test" << endl; }
};

class rectangle :public shape
{
public:	rectangle(double l, double w, int color) : shape(color)
{
	length = l; width = w;
}
	  void draw() { cout << "draw a rectangle\n"; }
private: double length, width;
};

class circle :public shape
{
public:	circle(double r, int color) : shape(color)
{
	radius = r;
}
	  void draw() { cout << "draw a circle\n"; }
private: double radius;
};

void output(shape& object) //注意: 不可寫為void output(shape object)
{
	object.draw();
}

int main()
{
	shape a_shape(1);
	a_shape.print();
	rectangle a_rectangle(3.5, 2.0, 3);
	circle   a_circle(2.4, 2);
	output(a_circle);
	output(a_rectangle);
	system("pause"); return 0;
}
