#include <iostream>
#include <set>
using namespace std;

int main()
{
	int n, i, t, c = 1;

	while (cin >> n)//輸入數列數量 
	{
		int* b = new int[n];
		set<int> d;//set裡面不能放重複的數字
				   //以此來計算兩數的和是否重複 
		d.clear();//清空 

		for (i = 0; i < n; i++)//輸入數列 
		{
			cin >> b[i];
		}

		for (i = 0; i < n; i++)//判斷數列是否為B2 
		{
			if (b[i] < 1)//B2不能有負數或0
			{
				break;
			}
			else if (b[i - 1] >= b[i] && i - 1 > 0)//B2後項比前項大 
			{							//i-1如果小於0可能會出問題 
				break;
			}
			for (t = i; t < n; t++)//兩數相加 
			{
				d.insert(b[i] + b[t]);//將兩數和放入set裡面
									//set不會重複放 
			}
		}

		if (d.size() == (n + 1) * n / 2)//如果set有少的話就代表此數列非B2 
		{					   //size就是取得set裡面放的數量 
			cout << "Case #" << c << ": It is a B2-Sequence.";
		}
		else
		{
			cout << "Case #" << c << ": It is not a B2-Sequence.";
		}

		cout << endl << endl;//要換兩行 
		c++;//結束換下一筆測資 
	}
	return 0;
}