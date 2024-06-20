#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n, i;

	while (cin >> n)//块计 
	{
		int em = 1, cn1 = n, cn2 = 0;

		for (i = 2; i <= sqrt(n); i++)//耞块计琌借计 
		{
			if (n % i == 0)//ぃ琌借计 
			{
				em = 0;
				break;
			}
		}

		if (em == 1)//狦块计琌借计碞陆锣ウ 
		{		 //耞陆锣计琌ぃ琌借计 
			while (cn1 > 0)//陆锣计 
			{
				cn2 = cn2 * 10 + cn1 % 10;
				cn1 = cn1 / 10;
			}

			if (cn2 != n)//陆锣计ぃ㎝セ妓 
			{
				em = 2;
				for (i = 2; i <= sqrt(cn2); i++)//耞赣计琌借计 
				{
					if (cn2 % i == 0)
					{
						em = 1;
						break;
					}
				}
			}
		}

		if (em == 2)//ㄢ计(ㄓ计 and 陆锣计)常琌借计 
		{
			cout << n << " is emirp." << endl;
		}
		else if (em == 1)//ㄓ计琌借计 
		{
			cout << n << " is prime." << endl;
		}
		else//ㄢ常ぃ琌 
		{
			cout << n << " is not prime." << endl;
		}
	}
	return 0;
}