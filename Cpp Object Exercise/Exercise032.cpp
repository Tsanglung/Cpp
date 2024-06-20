//字串動態配置
#include <iostream>
#include <cstdlib>
using namespace std;
void transfer(char[]);
int main()
{
	int n;
	cout << "請輸入字串大小:";
	cin >> n;
	char* p = new char[n + 1];
	cin.get();
	cout << "\n輸入字串內容:";
	cin.getline(p, n + 1);
	transfer(p);
	cout << "\n轉換後,字串內容:";
	cout << p << endl;
	delete[]p;
	system("pause");

}

void transfer(char a[])
{
	int i = 0;
	while (a[i] != '\0')
	{
		if (islower(a[i]))//islower() 判斷字元是否為小寫
			a[i] = toupper(a[i]);//toupper() 將小寫字元轉換成大寫
		else a[i] = tolower(a[i]);//tolower() 將大寫字元轉換成小寫
		i++;
	}
}
