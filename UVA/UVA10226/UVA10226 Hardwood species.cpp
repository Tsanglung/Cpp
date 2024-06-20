#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
	int i, n;
	vector<string> vs;//vector儲存輸入
	string is1;

	cin >> n;//輸入測資數量 
	getline(cin, is1);//cin接getline會有問題，要多打一次 
	getline(cin, is1);//取得空一行 

	while (n--)//輸入測資數量 
	{
		vs.clear();//重製陣列 
		double sum = 0, count = 1, p;

		while (getline(cin, is1) && is1 != "")//輸入測資 
		{
			vs.push_back(is1);
		}

		sort(vs.begin(), vs.end());//首字母A~Z排列 
		sum = vs.size();//取得總數 

		for (i = 0; i < sum; i++)
		{
			if (vs[i] == vs[i + 1])//如果相同的名字不用輸出 
			{
				count++;//計算次數加1 
			}
			else if (vs[i] != vs[i + 1])//不同名字，計算面積比例並輸出 
			{
				p = (count / sum) * 100;//計算面積比例 
				cout << fixed << setprecision(4);//精確到小數點下四位 
				cout << vs[i] << " " << p << endl;//輸出 
				count = 1;//重製 
			}
		}

		if (n != 0)//最後一組測資不用換行 
		{
			cout << endl;
		}
	}
	return 0;
}