#include<iostream>
using namespace std;
int main() {
	long int a, b;
	while (cin >> a >> b) {
		if (a < 2 || b < 2) { cout << "Boring!" << endl; continue; }
		int array[1001]; //陣列儲存結果
		int x = 0; 
		int last;
		while (a % b == 0) { //計算a是否為b的次方數並求出b的0次，b的1次~b的n次
			array[x] = a;
			a = a / b;
			x++;
		}
		if (a != 1) { cout << "Boring!" << endl; }//a不為b的次方數
		else { //若是，則輸出b的0次~b的n次方數
			for (int w = 0; w < x; w++) { cout << array[w] << " "; }
			cout << "1" << endl;
		}
	}
}
