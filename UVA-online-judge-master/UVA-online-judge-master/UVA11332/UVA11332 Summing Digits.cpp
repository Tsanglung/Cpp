#include<iostream>
#include<string>
using namespace std;

int Sum(int temp) { //持續運算直到剩下個位數
	int sum = 0;
	while (temp > 0) { 
		sum += temp % 10;
		temp /= 10;
	}
	if (sum > 9)return Sum(sum);
	else return sum;
}

int main() {
	string CinNumber;
	string Zero = {'0'};
	while (getline(cin,CinNumber)) {
		int temp = 0;//儲存輸入字串每一字元相加結果
		if (CinNumber == Zero)break;//若輸入字串為0，結束迴圈
		int lenght = CinNumber.length(); //字串長度
		if (lenght >= 2) {//若字串長度大於等於2，也就是百位數(含)以上
			for (int i = 0; i < lenght; i++) {
				temp += CinNumber[i] - '0'; //將字串每一個字元轉成數字相加
			}
			cout << Sum(temp) << endl;
		}
		else cout << CinNumber << endl;
	}
}