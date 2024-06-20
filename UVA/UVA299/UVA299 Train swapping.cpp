#include <iostream>
using namespace std;

void swap(int* a, int* b)//ユ传ㄧΑ 
{
	int t = *a;
	*a = *b;
	*b = t;
}

int main()
{
	int i, t, n, l;

	while (cin >> n)//块代戈计秖 
	{

		while (n--)
		{
			cin >> l;//块计兜计 
			int num[l] = { 0 }, count = 0;

			for (i = 0; i < l; i++)//块计 
			{
				cin >> num[i];

			}

			for (i = 0; i < l; i++)//獁逼猭 
			{
				for (t = 0; t < l - i - 1; t++)
				{
					if (num[t] > num[t + 1])
					{
						swap(&num[t], &num[t + 1]);//ユ传 
						count++;//璸衡Ω计 
					}
				}
			}

			cout << "Optimal train swapping takes " << count << " swaps." << endl;//块
		}
	}
	return 0;
}