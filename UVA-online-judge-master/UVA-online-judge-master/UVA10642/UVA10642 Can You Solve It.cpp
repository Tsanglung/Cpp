#include <iostream>
using namespace std;

int main()
{

	int n, x1, y1, x2, y2, i;

	cin >> n;//輸入測資數量 
	for (i = 1; i <= n; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;//輸入測資
		int count = 0;


		count += (y1 + x1 + 1 + y2 + x2) * (y2 + x2 - y1 - x1) / 2;//計算從起始的線到最後的線的步數 
		count += (x2 - x1);//調整誤差

		cout << "Case " << i << ": " << count << endl;//輸出 
	}
	return 0;
}