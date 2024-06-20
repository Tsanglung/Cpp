
#include<iostream>
using namespace std;
int GCD(int i, int j) //―程そ计
{
	if (j == 0) { return i; }
	else { return GCD(j, i % j); }
}
int main()
{
	int N, i, j;
	cin >> N;//块
	while (N != 0)
	{
		int G = 0;
		for (i = 1; i < N; i++)
		{
			for (j = i + 1; j <= N; j++)
			{
				G += GCD(i, j);
			}
		}
		cout << G << endl;//1~N–计程そ计㎝
		cin >> N;
	}
}
