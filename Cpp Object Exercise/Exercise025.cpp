/*
建立長方體物件，公開屬性成員有長、寬、高
體積、面積函數
*/
#include<iostream>
#include <cstdlib>
using namespace std;
class CBox
{
public:                          //設定為公開
	double L, W, H;  //屬性 長,寬,高
	//建構子
	CBox(double lv, double bv, double hv) {L = lv; W = bv; H = hv;}
	 //方法 計算體積
	double Volume() {return L * W * H;}
	//計算面積
	double area() {return 2 * (L * W + L * H + H * W);}
};

int main()
{
	CBox box(3, 2, 1); //建構物件box, 自動呼叫建構子CBox(double lv, double bv, double hv)     
	cout << endl << "volume of box=" << box.Volume() << endl;
	cout << endl << "area of box=" << box.area() << endl;
	system("pause"); return 0;
}
