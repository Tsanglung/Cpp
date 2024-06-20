#include<iostream>
using namespace std;
int main() {
	int n; 
	while (cin >> n && n) {
		int counter = 0; int array[10]; int number[10];
		for (int i = 0; i < n; i++) {
			cin >> array[i];
		}
		for (int i = 0, j = i + 1; i < n && j < n; i++,j++) {
			number[counter] =abs(array[i] - array[j]);//相鄰兩數相差取絕對值	
			counter++;	
		}
		int temp;
		//差值由小到大排序
		for (int i = 0; i < counter; i++) {
			for (int j = i + 1; j < counter; j++) {
				if (number[i] > number[j]) {
					temp = number[j];
					number[j] = number[i];
					number[i] = temp;
				}
			}
		}
		int num = 0;
		for (int i = 0; i < n - 1; i++) {
			if (number[i] == i + 1)num++;
		}
		if (num == n - 1)cout << "Jolly" << endl;
		else cout << "Not jolly" << endl;
	}
}