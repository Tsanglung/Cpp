#include<iostream>
using namespace std;
int main() {
	int a, b;//块ㄢ计
	int counter;//代戈计
	cin >> counter;
	int Case = 0;
	for (int i = 0; i < counter; i++) {
		cin >> a >> b;
		int sum = 0;
		for (int j = a; j <= b; j++) {
			if (j % 2 != 0) { //―计
				sum += j;
			}
		}
		Case++;
		cout << "Case " << Case << ": " << sum << endl;
	}
}