#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main() {
	string CInKeyboard;
	string keyboardstr = { "`1234567890-=qwertyuiop[]|asdfghjkl;'zxcvbnm,./" };
	int lenght = keyboardstr.length();
	char hash[256];
	for (int i = 0; i < 256; i++) {
		hash[i] = i;
	}
	for (int i = 2; i < lenght; i++) { //將誤差丟入hash
		hash[keyboardstr[i]] = keyboardstr[i - 2];
	}
	while (getline(cin, CInKeyboard)) { //輸入
		for (int i = 0; i < CInKeyboard.length(); i++) {
			if (CInKeyboard[i] >= 'A' && CInKeyboard[i] <= 'Z')//大寫換成小寫 
			{
				CInKeyboard[i] = CInKeyboard[i] + 32;
			}
		}
		for (int i = 0; i < CInKeyboard.length(); i++) {//輸出結果
			cout << hash[CInKeyboard[i]];
		}
		cout << endl;
	}
}