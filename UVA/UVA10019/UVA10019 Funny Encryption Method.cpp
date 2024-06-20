#include<iostream>
#include<math.h>
using namespace std;

int DEC_Transform_Binary(int M) {//10進位轉2進位
	int counter = 0;//計數有幾個1
	int Binary_M;//轉換二進位之數
	while (M != 0) {
		Binary_M = M % 2;
		if (Binary_M == 1)counter++;
		M /= 2;
	}
	return counter;
}

int HEC_Transform_Binary(int M) {//16進位轉2進位
	int i = 0;
	int HECToDEC_M;//16進位轉10進位
	int DEC_M = 0;//16進位轉10進位
	while (M > 0) {
		HECToDEC_M = M % 10;
		DEC_M += (HECToDEC_M * pow(16, i));//16進位轉10進位
		M /= 10;
		i++;
	}
	//10進位轉2進位
	/*int counter = 0;//計數有幾個1
	int Binary_M;//轉換二進位之數
	while (DEC_M != 0) {
		Binary_M = DEC_M % 2;
		if (Binary_M == 1)counter++;
		DEC_M /= 2;
	}
	return counter;//計數有幾個1*/
	//10進位轉2進位
	return DEC_Transform_Binary(DEC_M);
}
/*int Encryption(int m, int b1, int b2) {//原文規則第8.
	return m xor (b1 * b2);
}*/

int main()
{
	int n;
	cin >> n;
	int M;
	for (int i = 0; i < n; i++) {
		cin >> M;
		cout << DEC_Transform_Binary(M) << ' ' << HEC_Transform_Binary(M) << endl;
		//cout << Encryption(M, DEC_Transform_Binary(M), HEC_Transform_Binary(M)) << endl;
	}
}