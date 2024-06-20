#include<iostream>
using namespace std;
int main() {
	int TestData;//代戈
	while (cin >> TestData && TestData) {//代戈
		int TestArray[1001];
		for (int i = 0; i < TestData; i++) {
			cin >> TestArray[i];
		}
		int temp = 0;
		for (int i = 0; i < TestData; i++) {//逼 
			for (int j = i + 1; j < TestData; j++) {
				if (TestArray[i] > TestArray[j]) {
					temp = TestArray[j];
					TestArray[j] = TestArray[i];
					TestArray[i] = temp;
				}
			}
		}
		int MaxMidNumber,MinMidNumber; //程い计程い计
		int Method; //ㄢい计丁ぶ俱计ㄤ计ぇい计
		if (TestData % 2 == 0) {//тい计
			MinMidNumber = TestArray[TestData / 2 - 1];//程い计
			MaxMidNumber = TestArray[TestData / 2];//程い计
			Method = MaxMidNumber - MinMidNumber + 1; //ㄢい计丁ぶ俱计ㄤ计ぇい计
		}
		else {//TestData计程い计单程い计
			MinMidNumber = TestArray[TestData / 2];
			MaxMidNumber = TestArray[TestData / 2];
			Method = 1;//程い计单程い计ㄢ计丁俱计Τ1
		}

		int counter = 0;
		for (int i = 0; i < TestData; i++) {
			//TestData计いΤ碭计籔い计(程or程)单
			if (MaxMidNumber == TestArray[i] || MinMidNumber == TestArray[i])counter++;
		}

		cout << MinMidNumber << " " << counter << " " << Method << endl;
	}
}