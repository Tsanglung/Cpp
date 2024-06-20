#include<iostream>
using namespace std;

int Algorithm(int i,int j) 
{
	int temp;//ユ传
	if (i > j) //璝玡计计玥ユ传琵计耕
	{
		temp = i;
		i = j;
		j = temp;
	}
	int counter;//璸计琘计玻ネcycle计
	int max = 0;//程cycle计
	for (i; i <= j; i++) {
		counter = 1;
		int n = i;
		while (n != 1) { //砏玥
			if (n % 2 == 0) {
				n /= 2;
			}
			else if (n % 2 != 0) {
				n = 3 * n + 1;
			}
			counter++;//璸计玻ネcycle
		}
		if (counter > max) { max = counter; }//璝眔穝程cycle玥蠢传
	}
	return max;
}

int main() 
{
	int i, j;
	while (cin >> i >> j && i && j) {
		cout << i << ' ' << j << ' ' << Algorithm(i,j) << endl;
	}
}