#include<iostream>
using namespace std;
int main() {
	int a, b;//輸入兩數
	int counter;//測資數
	cin >> counter;
	int Case = 0;
	for (int i = 0; i < counter; i++) {
		cin >> a >> b;
		int sum = 0;
		for (int j = a; j <= b; j++) {
			if (j % 2 != 0) { //求奇數
				sum += j;
			}
		}
		Case++;
		cout << "Case " << Case << ": " << sum << endl;
	}
}