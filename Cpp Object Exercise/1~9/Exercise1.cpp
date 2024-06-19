/**
级糶inlineㄧ计bool primeQ(int n)ノㄓ俱计n琌借计
璝琌玥肚true玥肚false祘Αいノㄧ计т100┮Τ借计
**/
#include <iostream>
#include <cstdlib>
using namespace std;
inline bool PrimeQ(int n)
{
	int counter = 0;
	for (int i = n; i > 0; i--) {
		if (n % i == 0) counter++;
	}
	if (counter == 2)return true;
	else return false;
}

int main()
{
	int n;

	cout << "块俱计:";
	cin >> n;

	if (PrimeQ(n))cout << n << "琌借计" << endl;
	else cout << n << "ぃ琌借计" << endl;

	int PrimeArray[101]; int counter = 0;
	int NotPrimeArray[101]; int Notcounter = 0;
	for (int i = 1; i <= 100; i++) {
		if (PrimeQ(i)) {
			PrimeArray[counter++] = i;
		}
		else {
			NotPrimeArray[Notcounter++] = i;
		}
	}
	cout << "借计: " ;
	for (int i_counter = 0; i_counter < counter; i_counter++) {
		cout << PrimeArray[i_counter] << ' ';
	}
	cout << endl;
	cout << "獶借计: " ;
	for (int i_counter = 0; i_counter < Notcounter; i_counter++) {
		cout << NotPrimeArray[i_counter] << ' ';
	}
	
	system("pause");
	return 0;
}