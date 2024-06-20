#include <iostream>
using namespace std;

int main()
{
	int c, month, day;
	cin >> c;//块代戈计秖 

	while (c--)
	{
		cin >> month >> day;//块るら戳 

		for (int i = month - 1; i >= 1; i--)//盢るら戳传Θぱ计 
		{						//iぇ玡る 
			if (i == 2)//2る 
			{
				day = day + 28;
			}
			else if (i % 2 == 0)//案计る 
			{
				if (i >= 8)//るぇ 
				{
					day = day + 31;
				}
				else//る玡 
				{
					day = day + 30;
				}
			} 
			else if (i % 2 == 1)//计る 
			{
				if (i >= 8)//る 
				{
					day = day + 30;
				}
				else//る玡 
				{
					day = day + 31;
				}
			}
		}

		if (day % 7 == 1)//2011材ぱ琌琍戳せ 
		{
			cout << "Saturday" << endl;
		}
		else if (day % 7 == 2)
		{
			cout << "Sunday" << endl;
		}
		else if (day % 7 == 3)
		{
			cout << "Monday" << endl;
		}
		else if (day % 7 == 4)
		{
			cout << "Tuesday" << endl;
		}
		else if (day % 7 == 5)
		{
			cout << "Wednesday" << endl;
		}
		else if (day % 7 == 6)
		{
			cout << "Thursday" << endl;
		}
		else if (day % 7 == 0)
		{
			cout << "Friday" << endl;
		}
	}
	return 0;
}