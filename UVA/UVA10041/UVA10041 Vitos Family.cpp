
#include<iostream>
using namespace std;
int main() {
    int i, j, k, datas, rowNum, tmp, ans, home;
    int rows[500] = { 0 };

    cin >> datas;//資料數
    for (i = 0; i < datas; i++)
    {
        cin >> rowNum;//有幾個號碼
        for (j = 0; j < rowNum; j++)  
            cin >> rows[j];

        for (j = 0; j < rowNum; j++)//排序
        {
            for (k = 1; k < rowNum; k++)
            {
                if (rows[k] < rows[k - 1])
                {
                    tmp = rows[k];
                    rows[k] = rows[k - 1];
                    rows[k - 1] = tmp;
                }
            }
        }
        home = rows[rowNum / 2];//找中位數
        ans = 0;

        for (j = 0; j < rowNum; j++)
        {
            ans = ans + abs(rows[j] - home);//abs取絕對值(每個號碼與中位數距離差)相加得出最短距離
        }
        cout << ans << endl;
    }
}
