#include <iostream>
using namespace std;

class Rectangle
{	//�x��
	friend ostream& operator<< (ostream& os, Rectangle& Rectabgle);
private:
	int x, y, h, w;

public:
	Rectangle(int x = 0, int y = 0, int height = 0, int width = 0) : x(x), y(y), h(height), w(width) { }//�غc�l
	~Rectangle() {}	//�Ѻc�l
	int GetH() { return h; };//��
	int GetW() { return w; };//�e
	bool operator==(const Rectangle& s)//overloading operator ==
	{	// ����⪫��O�_�۵�
		if (this == &s) return true;
		else if ((x == s.x) && (y == s.y) && (h == s.h) && (w == s.w))	return true;
		return false;
	}
};

ostream& operator<<(ostream& os, Rectangle& Rectabgle)//overloading operator <<
{
	os << "Position(x , y) : (" << Rectabgle.x << " , " << Rectabgle.y << ") " << endl;
	os << "Height : " << Rectabgle.h << endl;
	os << "Width : " << Rectabgle.w << endl;
	return os;
}

int main()
{
	Rectangle r(1, 1, 3, 4);
	Rectangle s(2, 4, 6, 8);
	Rectangle* t = &s; //�� s �}��ȵ� t�A�q�L t �X�ݩΧ�� s ���󪺦���

	if (r.GetH() * r.GetW() > t->GetH() * t->GetW())
		cout << r;
	else cout << s;
}
