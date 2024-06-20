#include <iostream>
#include <string>
using namespace std;

int main()
{
	string TeX;//輸入用字串 
	int i = 0; 
	int side = 0;//side為0代表現在是左邊的雙引號
			   //side為1就是右邊 
	while (getline(cin, TeX))//輸入資料 
	{

		for (i = 0; i < TeX.length(); i++)
		{
			if (TeX[i] == '"' && side == 0)//左邊的雙引號 
			{
				cout << "``";
				side = 1;
			}
			else if (TeX[i] == '"' && side == 1)//右邊雙引號 
			{
				cout << "''";
				side = 0;
			}
			else//沒雙引號 
			{
				cout << TeX[i];
			}
		}
		cout << endl;//換行 
	}
	return 0;
}