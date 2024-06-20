#include <iostream>
#include<string>
using namespace std;
int main() {
	string Sa, Sb;
	int ASCIISa[26], ASCIISb[26];
	while (getline(cin,Sa)) {
		getline(cin, Sb);
		for (int i = 0; i < 26; i++) {//a~z字母出現次數，初始皆設為0
			ASCIISa[i] = 0;
			ASCIISb[i] = 0;
		}
		for (int i = 0; i < Sa.length(); i++) {//紀錄Sa字串每個字母(a~z)出現次數
			ASCIISa[Sa[i] - 'a']++;
		}
		for (int i = 0; i < Sb.length(); i++) {//紀錄Sb字串每個字母(a~z)出現次數
			ASCIISb[Sb[i] - 'a']++;
		}
		for (int i = 0; i < 26; i++) {
			for (int j = min(ASCIISa[i], ASCIISb[i]); j > 0; j--) { //min取交集(即2字串在26個字母中，出現頻率同時大於1者
				cout << (char)('a' + i);//轉換為字元
			}
		}
		cout << "\n";
	}
}

/*
寫法2
string Sa,Sb;
	while (getline(cin, Sa)) {
		getline(cin, Sb);
		string store[101] = { "" };//儲存2字串相同的字元
		int La = Sa.length();//a字串長度
		int Lb = Sb.length();//b字串長度
		for (int i = 0; i < La; i++) {
			for (int j = 0; j < Lb; j++) {
				if (Sa[i] == Sb[j]) {
					store[i] = Sa[i];//紀錄相同字元
					Sb.erase(j, 1);//清除已查找到的相同字元，避免重複找查
					break;//直接結束第二個迴圈， 理由同上
				}
			}
		}

		sort(store, store + 1000);//紀錄下來的字元，依照a~z排序

		for (int k = 0; k < 1000; k++) {
			cout << store[k];//輸出
		}
		cout << endl;
	}
*/