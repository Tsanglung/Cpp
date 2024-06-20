#include<iostream>
#include <iomanip>
using namespace std;
int main() {
	double x1, y1, x2, y2, x3, y3, x4, y4;
	while (cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4) {
		if (x1 == x3 && y1 == y3)
			cout << fixed << setprecision(3) << (x2 + x4) - x1 << " " << (y2 + y4) - y1 << endl;
		else if (x1 == x4 && y1 == y4)
			cout << fixed << setprecision(3) << (x2 + x3) - x1 << " " << (y2 + y3) - y1 << endl;
		else if (x2 == x3 && y2 == y3)
			cout << fixed << setprecision(3) << (x1 + x4) - x2 << " " << (y1 + y4) - y2 << endl;
		else
			cout << fixed << setprecision(3) << (x1 + x3) - x2 << " " << (y1 + y3) - y2 << endl;
	}
	return 0;
}
/*#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int i, t;
	double x[4], y[4], ax, ay;

	while (cin >> x[0] >> y[0])//輸入測資 
	{
		ax = x[0];//全部的點相加 
		ay = y[0];//全部的點相加 

		for (i = 1; i < 4; i++)//輸入測資
		{
			cin >> x[i] >> y[i];
			ax += x[i];//全部點相加 
			ay += y[i];//全部點相加 
		}

		for (i = 1; i < 4; i++)
		{
			for (t = i + 1; t < 4; t++)
			{
				if (x[i] == x[t] && y[i] == y[t])//找到一樣的點 
				{
					cout << fixed << setprecision(3);//精確到小數點下三位 
					cout << ax - 3 * x[i] << " ";//輸出x座標 
					cout << ay - 3 * y[i] << endl;//輸出y座標 
				}
			}
		}
	}
	return 0;
}*/