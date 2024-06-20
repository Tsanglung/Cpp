#include <iostream>
using namespace std;

int main()
{
	int Data, Case = 1, i, number_counter, number, cn1, re, cost[36];

	cin >> Data;//輸入測資數 
	while (Case <= Data)
	{
		cout << "Case " << Case << ":" << endl;//輸出第幾組 

		for (i = 0; i < 36; i++)//輸入花費 
		{
			cin >> cost[i];
		}

		cin >> number_counter;//輸入數字數量 
		while (number_counter--)
		{
			cin >> number;//輸入數字 

			int min = 0, de[37] = { 0 };//歸零 

			for (i = 2; i <= 36; i++)//計算每個進位的價錢 
			{
				cn1 = number;//原本的數字不能動所以用其他變數 
				int sum = 0;//歸零 

				while (cn1 > 0)//利用短除法將十進位轉成任何進位 
				{
					re = cn1 % i;//取得餘數就是該進位要轉的數字 
					sum = sum + cost[re];//計算價錢 
					cn1 = cn1 / i;
				}

				if (min == 0 || sum <= min)//紀錄最少的花費 
				{
					de[i] = sum;
					min = sum;
				}
			}

			cout << "Cheapest base(s) for number " << number << ":";//輸出 

			for (i = 2; i <= 36; i++)
			{
				if (de[i] == min)//輸出花費最少的進位 
				{
					cout << " " << i;
				}
			}
			cout << endl;
		}

		if (Case < Data)//最後一組測資不用換行 
		{
			cout << endl;
		}
		Case++;
	}
	return 0;
}