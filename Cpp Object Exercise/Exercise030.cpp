#include <iostream>
#include <vector>
#include <list>
using namespace std;
int main()
{
	vector<int> a;
	cout << "測試 vector" << endl;
	a.push_back(3);  a.push_back(4); a.push_back(8);   a.push_back(9);      //　a = 3 4 8 9
	a.pop_back(); // a= 3 4 8
	a.front() = 9;                           //　b = 9 4 8
	cout << a.front() << "  " << a.back() << endl; //輸出 9 8
	cout << "測試 list" << endl;
	list<int>   b;
	b.push_back(3);  b.push_back(4);   b.push_back(8);        //　b = 3 4 8 
	b.push_front(5); b.push_front(7);       //　b = 7 5 3 4 8 
	b.pop_front(); b.pop_back();            //　b = 5 3 4
	b.front() = 9;                           //　b = 9 3 4
	cout << b.front() << "  " << b.back() << endl; //輸出 9 4 
	system("pause");
}
