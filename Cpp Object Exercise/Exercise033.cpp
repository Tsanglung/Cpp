/*
Joseph Problem : 
人們站在一個等待被處決的圈子裡。 
計數從圓圈中的指定點開始，並沿指定方向圍繞圓圈進行。 
在跳過指定數量的人之後，處刑下一個人。 對剩下的人重複該過程，
從下一個人開始，朝同一方向跳過相同數量的人，直到只剩下一個人，並被釋放。
即，給定人數、起點、方向和要跳過的數字，選擇初始圓圈中的位置以避免被處決。
*/
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int J(int n)
{
	if (n == 1) return 1; //遞迴結束條件
	else if (n % 2 == 0) return 2 * J(n / 2) - 1;
	else return 2 * J(n / 2) + 1;
}

int main() {
    int n;
    cout << "請輸入囚犯人數:";
    while (cin >> n && n)
    {
        vector<int> v;
        for (int i = 1; i <= n; i++)
            v.push_back(i);
        int  pos = 0; //下一個刪除之vector index
        while (v.size() > 1) {
            pos = (pos + 1) % v.size(); //使能如環狀般計數
            v.erase(v.begin() + pos);
        }
        cout << "非遞迴執行結果 : " << endl;
        cout << "存活者為:" << v[0] << "號" << endl;
        cout << "請輸入囚犯人數:";

        cout << "遞迴執行結果 : " << endl;
        cout << "存活者為:" << J(n) << "號" << endl;
		cout << "請輸入囚犯人數:";
    }
}