#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, i, t;
	string note;
	cin >> n;
	getline(cin, note);//cin接getlne會出問題，所以多用一次 
	while (n--)//輸入動作次數 
	{
		getline(cin, note);//輸入會有空白所以用getline 
		int f[10] = { 0 }, now[10] = { 0 }, last[10] = { 0 };
		for (i = 0; i < note.length(); i++)
		{
			for (t = 0; t < 10; t++)
			{
				last[t] = now[t];//紀錄上次是否有按 
				now[t] = 0;//清空 
			}

			if (note[i] >= 'c' && note[i] <= 'g')//處理 "c"到"g"
			{
				for (t = 1; t <= 3; t++)
				{
					now[t] = 1;
				}
				for (t = 6; t <= 9 - (note[i] - 'c'); t++)
				{
					now[t] = 1;
				}
			}
			else if (note[i] == 'a')//"a" 
			{
				now[1] = 1;
				now[2] = 1;
			}
			else if (note[i] == 'b')//"b"
			{
				now[1] = 1;
			}
			else if (note[i] == 'C')//"C"
			{
				now[2] = 1;
			}
			else if (note[i] >= 'D' && note[i] <= 'F')//"D"到"F" 
			{
				for (t = 0; t <= 3; t++)
				{
					now[t] = 1;
				}
				for (t = 6; t <= 8 - (note[i] - 'D'); t++)
				{
					now[t] = 1;
				}
			}
			else if (note[i] == 'G')//"G"
			{
				for (t = 0; t < 4; t++)
				{
					now[t] = 1;
				}
			}
			else if (note[i] == 'A')//"A"
			{
				for (t = 0; t < 3; t++)
				{
					now[t] = 1;
				}
			}
			else if (note[i] == 'B')//"B"
			{
				for (t = 0; t < 2; t++)
				{
					now[t] = 1;
				}
			}

			for (t = 0; t < 10; t++)
			{
				if (last[t] == 0 && now[t] == 1)//上次沒按這次有按才算一次 
				{
					f[t]++;
				}
			}
		}

		for (t = 0; t < 10; t++)//輸出 
		{
			cout << f[t];
			if (t != 9)//最後一個數字不用空白 
			{
				cout << " ";
			}
		}
		cout << endl;//記得換行 
	}
	return 0;
}