#include <iostream>
using namespace std;

int main()
{
	long long s, d;//數字很大用long long 
					//s為第一組旅行團人數
					//d為第d天查找入住酒店的旅行團人數
	while (cin >> s >> d)//輸入測資 
	{
		while (d > 0)//d一直減s直到d小於等於0 
		{		  //這時s就是答案 
			d = d - s;
			s++;
		}
		//輸出在第D天入住的旅行團人數
		cout << s - 1 << endl;//因為d小於0的那次迴圈
						//s仍會加1所以必須減回來 
	}
	return 0;
}