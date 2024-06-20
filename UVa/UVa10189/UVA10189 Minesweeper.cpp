#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	int i, t, j, m, n, c = 1;

	while (cin >> n >> m && (n != 0 && m != 0))//輸入行列數 
	{
		if (c > 1)//輸出下一筆資料前換行 
		{
			cout << endl;
		}
		cout << "Field #" << c << ":" << endl;//照格式輸出

		string s1[n + 2] = { "" };

		getline(cin, s1[0]);//cin接getline會有問題要多打一次 

		for (i = 1; i <= n; i++)//輸入測資 
		{
			getline(cin, s1[i]);
			s1[i] = "0" + s1[i] + "0";//怕有超出陣列的範圍的問題 
								//多加一圈0在外面 
		}
		for (i = 0; i < m + 2; i++)//多加一圈0 
		{
			s1[0] += "0";
			s1[n + 1] += "0";
		}

		for (i = 1; i <= n; i++)//計算地雷數 
		{
			for (t = 1; t <= m; t++)
			{
				if (s1[i][t] == '.')//只要檢查"." 
				{
					int count = 0;
					stringstream ss;//把數字轉成字串用 
					ss.clear();//怕出錯先清空 

					for (j = -1; j < 1; j++)//j不能等於1不然會重複檢查 
					{				 //下面的正負號也要注意好 
						if (s1[i - 1][t + j] == '*')//檢查上面有沒有地雷 
						{
							count++;
						}
						if (s1[i + j][t + 1] == '*')//右邊
						{
							count++;
						}
						if (s1[i + 1][t - j] == '*')//下面
						{
							count++;
						}
						if (s1[i - j][t - 1] == '*')//左邊 
						{
							count++;
						}
					}

					ss << count;//數字轉字串 
					ss >> s1[i][t];
				}
			}
		}

		for (i = 1; i <= n; i++)
		{
			s1[i].assign(s1[i], 1, m);//把0去掉

			//srt1.assign(str2,b,l)用法為把str2字串中
			//從b開始將l長度附值str1 

			cout << s1[i] << endl;//輸出 
		}

		c++;//換下一筆測資 
	}
	return 0;
}