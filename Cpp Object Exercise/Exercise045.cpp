#include <iostream>
#include <cstdlib>
using namespace std;
//間接繼承
class TwoD
{
protected:	int x, y;
public: void setxy(int n, int m) { x = n; y = m; }
	  void showxy() { cout << "平面座標 : p(" << x << ", " << y << ") " << endl; }
};

class ThreeD : public TwoD	// 以 public 繼承 TwoD 類別
{
protected:	int z;
public:	void setz(int o) { z = o; }
	  void showxyz() { cout << "空間座標 : s(" << x << ", " << y << ", " << z << ") " << endl; }
};

class Cube : public ThreeD	// 以 public 繼承 ThreeD 類別
{											// 間接繼承 TwoD 類別
public:	void showarea() { cout << "面積 = " << x * y << endl; } // 間接存取 x, y 值
	  void showcube() { cout << "體積 = " << x * y * z << endl; }	// 間接存取 x y, 直接存取 z
};

int main()
{
	Cube p;
	p.setxy(2, 5);				//直接呼叫基礎類別成員
	p.showxy();				// 直接呼叫基礎類別成員
	p.showarea();				// 直接呼叫衍生類別2成員
	cout << endl;
	p.setz(8);				// 直接呼叫衍生類別1成員
	p.showxyz();				// 直接呼叫衍生類別1成員
	p.showcube();				// 直接呼叫衍生類別2成員
	cout << endl;
	system("pause");
}
