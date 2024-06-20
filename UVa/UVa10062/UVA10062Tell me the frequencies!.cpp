#include <iostream>
#include <string>
using namespace std;

int main()
{
	int i, t, r = 0;
	string ASCIIstr;
	bool Flag = false;

	while (getline(cin, ASCIIstr))//輸入測資 
	{
		if (Flag)//輸出下筆資料前換行 
		{
			cout << endl;
		}

		int ASCII[97] = { 0 }, count[97] = { 0 };

		for (i = 0; i < 96; i++)//產生ASCII的值 
		{
			ASCII[i] = i + 32;
		}

		for (i = 0; i < ASCIIstr.length(); i++)//計算輸入字串的ASCII出現次數 
		{
			count[ASCIIstr[i] - 32]++;
		}

		for (i = 0; i < 96; i++)//用氣泡排列法 
		{                 //依照題目要求排列 
			for (t = 0; t < 96 - i - 1; t++)
			{
				if (count[t] > count[t + 1])//數字較大在後面 
				{
					int temp = ASCII[t];
					ASCII[t] = ASCII[t + 1];
					ASCII[t + 1] = temp;
					temp = count[t];
					count[t] = count[t + 1];
					count[t + 1] = temp;
				}

				else if (count[t] == count[t + 1] && ASCII[t] < ASCII[t + 1])
				{//數字一樣時ASCII較大的在後面 
					int temp = ASCII[t];
					ASCII[t] = ASCII[t + 1];
					ASCII[t + 1] = temp;
				}

			}
		}
		for (i = 0; i < 96; i++)//輸出
		{
			if (count[i] != 0)
			{
				cout << ASCII[i] << " " << count[i] << endl;
			}
		}
		Flag = true;//第一筆資料後要換行 
	}
	return 0;
}