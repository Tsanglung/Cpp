#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	int i, n, t;
	string Cs1, Cs2;//測資會有30位所以用字串 

	cin >> n;//輸入測資數量 
	for (t = 1; t <= n; t++)
	{
		cin >> Cs1 >> Cs2;//輸入測資
		cout << "Pair #" << t << ": ";//照格式輸出 

		int cn1 = 0, cn2 = 0, dig;//將輸入轉成十進制用

		for (i = 0; i < Cs1.length(); i++)//將第一組數字轉成十進位 
		{
			dig = Cs1[i] - '0';//先取得該位數的數字 
			cn1 += dig * pow(2, Cs1.length() - i - 1);//在乘上它的位數的值 
		}

		for (i = 0; i < Cs2.length(); i++)//將第二組數字轉成十進位 
		{
			dig = Cs2[i] - '0';
			cn2 += dig * pow(2, Cs2.length() - i - 1);
		}

		if (cn2 > cn1)//因為要用輾轉相除法 
		{		   //所以先找到比較大的數 
			dig = cn2;
			cn2 = cn1;
			cn1 = dig;
		}

		do//利用輾轉相除法找公因數 
		{
			dig = cn1 % cn2;
			cn1 = cn2;
			cn2 = dig;

		} while (dig != 0 && dig != 1);//若餘數為0表示有公因數 
							   //若為1表示兩數互質 
		if (dig == 0)//輸出格式
		{
			cout << "All you need is love!" << endl;
		}
		else
		{
			cout << "Love is not all you need!" << endl;
		}
	}
	return 0;
}