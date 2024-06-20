#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
	int n;
	cin >> n;
	map<string, int> num;//國家名稱為索引, int用來統計該國人數 
	//map<string, int> ::iterator iter;	
	//cin.ignore();//去掉換行符號 
	string others;//儲存後面的人名 
	while (n--)
	{
		string country;//儲存每列的國家名稱 
		cin >> country >> others >> others; //讀入國家名字
		//getline(cin, others);//讀入人名	
		num[country]++; //放入map的key並遞增其相對之value
	}
	/*for (iter = num.begin(); iter != num.end(); iter++)
		// map預設會自動依據索引字母的順序排序 
	{
		cout << iter->first << " "; //取得國名
		cout << iter->second << endl; //取得人數
	}*/
	for (const auto i : num) {
		cout << i.first << " " << i.second << endl;
	}
	return 0;
}
/*
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
	int n;
	cin >> n;
	map <string, int> mp;
	string temp;
	while (n--) {
		string contry;
		cin >> contry >> temp >> temp;
		mp[contry]++;
	}
	for (auto i : mp)
		cout << i.first << ' ' << i.second << endl;
return 0;
}
*/