
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	string act;

	while (cin >> n && n != 0)//輸入動作次數 
	{
		int p[3][4] = { 0 }, t;

		p[1][0] = 1;//設定好初始值 
		p[1][1] = 4;
		p[1][2] = 6;
		p[1][3] = 3;
		p[0][0] = 2;
		p[2][0] = 5;

		while (n--)
		{
			cin >> act;
			if (act == "north")//向北轉 
			{
				t = p[0][0];
				p[0][0] = p[1][0];
				p[1][0] = p[2][0];
				p[2][0] = p[1][2];
				p[1][2] = t;
			}
			else if (act == "east")//東 
			{
				t = p[1][0];
				p[1][0] = p[1][3];
				p[1][3] = p[1][2];
				p[1][2] = p[1][1];
				p[1][1] = t;
			}
			else if (act == "south")//南 
			{
				t = p[2][0];
				p[2][0] = p[1][0];
				p[1][0] = p[0][0];
				p[0][0] = p[1][2];
				p[1][2] = t;
			}
			else if (act == "west")//西 
			{
				t = p[1][0];
				p[1][0] = p[1][1];
				p[1][1] = p[1][2];
				p[1][2] = p[1][3];
				p[1][3] = t;
			}

		}
		cout << p[1][0] << endl;
	}
	return 0;
}
