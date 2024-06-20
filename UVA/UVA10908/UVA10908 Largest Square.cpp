#include <iostream>
#include <string>
using namespace std;

int i, t, j;
int m;//輸入m串字串
int n;//一串有n個字元
int q;//輸入q行，輸入格式為(row col)，一行有2數，前者為row，後者為col
int row;//矩陣列
int col;//矩陣行

int main()
{
	cin >> t;//輸入測資數量 
	while (t--)
	{
		cin >> m >> n >> q;//輸入測資 
		cout << m << " " << n << " " << q << endl;//照格式輸出

		if (m < n)//取得較小的數 
		{
			n = m;
		}
		int flag[n + 1];//判斷最大的正方形是多少 
		string is1[m + 2] = { "" };//怕出錯所以多宣告兩個 
							 //基本上會在輸入的矩陣外圈多加一圈空白 
		getline(cin, is1[0]);//cin之後getline會出錯所以要多打一次 

		for (i = 1; i < m + 1; i++)//輸入矩陣 
		{
			getline(cin, is1[i]);
			is1[i] = " " + is1[i] + " ";//左右多加空白 
		}

		for (i = 0; i < is1[1].length(); i++)//上下多加空白 
		{
			is1[0] += " ";
			is1[m + 1] += " ";
		}

		while (q--)
		{
			for (i = 0; i <= n; i++)//重製 
			{
				flag[i] = 1;
			}

			cin >> row >> col;//輸入中心點 
			row += 1;//因為矩陣外圈多加空白所以加1 
			col += 1;

			for (i = 1; flag[i - 1] == 1; i++)//從中心一圈一圈判斷 
			{						 //i代表第幾圈 
				for (j = -i; j <= i; j++)
				{
					if (is1[row][col] != is1[row - i][col + j])//比較上排的字 
					{
						flag[i] = 0;
						break;
					}
					if (is1[row][col] != is1[row + j][col + i])//右邊 
					{
						flag[i] = 0;
						break;
					}
					if (is1[row][col] != is1[row + i][col + j])//下面 
					{
						flag[i] = 0;
						break;
					}
					if (is1[row][col] != is1[row - j][col - i])//左邊 
					{
						flag[i] = 0;
						break;
					}
				}
			}

			for (i = 1; i <= n; i++)//輸出 
			{
				if (flag[i] == 0)
				{
					cout << 1 + (i - 1) * 2 << endl;
					break;
				}
			}
		}
	}
	return 0;
}