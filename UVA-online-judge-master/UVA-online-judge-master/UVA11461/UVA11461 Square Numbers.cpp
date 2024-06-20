#include<iostream>
#include<cmath>//使用sqrt函式
using namespace std;
int main() {
	int a, b;
	while (cin >> a >> b && a && b) {
		if (a == 0 && b == 0)break;//測資皆為0結束程式
		int num = 0;
		int i, j, sq;
		for (i = a; i <= b; i++) {
			sq = sqrt(i);//sqrt開根號
			if (sq * sq == i)num++;//判斷是否為完全平方數
		}
		cout << num << endl;
	}
}
