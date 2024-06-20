#include<iostream>
using namespace std;

int main() {
	int T, N, row, col, Tcnt = 1;
	char dummy[10];
	long long int matrix[100][101];//矩陣

	cin >> T;//測資數量
	while (T--) {
		cin >> dummy >> dummy >> N;//輸入格式 N = ?(int)

		for (row = 0; row < N; row++)
			for (col = 0; col < N; col++)
				cin >> matrix[row][col];

		//判斷矩陣是否對稱
		for (row = 0; row < N; row++)
			for (col = 0; col <= row; col++) {
				int rev_row = N - 1 - row, rev_col = N - 1 - col;
				if (matrix[row][col] < 0 || matrix[rev_row][rev_col] < 0 ||
					matrix[row][col] != matrix[rev_row][rev_col]) row = col = N;
			}
		cout << "Test #" << Tcnt++ << ": ";//計算測資數
		if (row == N)cout << "Symmetric." << endl;
		else cout << "Non-symmetric." << endl;
	}

	return 0;
}
