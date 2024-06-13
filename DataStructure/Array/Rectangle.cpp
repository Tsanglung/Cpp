#include <iostream>
using namespace std;

class Rectangle
{
	friend ostream& operator<< (ostream& os, Rectangle& r);
public:

	//Definition of a constructor
	Rectangle(int x = 0, int y = 0, int height = 0, int width = 0) : x1(x), y1(y), h(height), w(width) { }
	~Rectangle() {}
	int GetH() { return h; };
	int GetW() { return w; };
	bool operator==(const Rectangle& s)//overloading operator ==
	{
		if (this == &s) return true;
		else if ((x1 == s.x1) && (y1 == s.y1) && (h == s.h) && (w == s.w))
			return true;
		return false;
	}


private:
	int x1, y1, h, w;
};

ostream& operator<<(ostream& os, Rectangle& r)//overloading operator <<
{
	os << "Position is: " << r.x1 << " ";
	os << r.y1 << endl;
	os << "Height is: " << r.h << endl;
	os << "Width is: " << r.w << endl;
	return os;
}

void main()
{
	Rectangle r(1, 1, 3, 4);
	Rectangle s(2, 4, 6, 8);
	Rectangle* t = &s;
	//use . to access members of class objects
	//use -> to access members of class objects through pointers.
	if (r.GetH() * r.GetW() > t->GetH() * t->GetW())
		cout << r;
	else cout << s;
}
