#include <iostream>
#include <cctype>
#include <string>
#include <sstream>
using namespace std;
int main()
{
	string English, temp;
	getline(cin,English);
	for (int i = 0; i < English.length(); i++) 
	{
		if (isalpha(English[i]) == 0) //isalpha()判斷是否為英文字母，是則回傳非0值，否則傳回0
		{
			English[i] = ' ';
		}
		if (islower(English[i])) //islower()判斷是否為小寫 是則傳回1，否則傳回0
		{
			English[i] = toupper(English[i]);//小寫轉大寫
		}
	}
	stringstream EnglishWord(English);//將字串，以空格分割
	while (EnglishWord >> temp) {
		cout << temp << endl;
	}
}