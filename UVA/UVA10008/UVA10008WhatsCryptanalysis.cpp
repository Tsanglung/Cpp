#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int n, len, temp;
    while (cin >> n)
    {
        int count[26] = { 0 };//計數某字母出現幾次之陣列
        char c_temp;
        char english[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";//26個由小到大排序英文字母大寫
        char input[256];//輸入字串
        for (int i = 0; i <= n; i++)
        {
            cin.getline(input, 256);//輸入字串
            len = strlen(input);//字串長度
            for (int j = 0; j <= len; j++)
            {
                //若字串出現不同大小寫視為同字母，例如A=a
                if (input[j] <= 90 && 65 <= input[j])//ASCII碼 大寫判斷
                    count[input[j] - 65]++;//計數，例input[j]=A，A的ASCII碼為65 =>count[0]++;
                else if (input[j] <= 122 && 97 <= input[j])//ASCII碼 小寫判斷
                    count[input[j] - 97]++;//計數，例input[j]=a，a的ASCII碼為97 =>count[0]++;
            }
        }
        for (int i = 0; i <= 25; i++)
        {
            for (int j = 0; j <= 24; j++)
            {
                if (count[j] < count[j + 1]) //如果前項大於後項的話交換，出現最多次的字母先輸出
                {
                    temp = count[j];
                    c_temp = english[j];
                    count[j] = count[j + 1];
                    english[j] = english[j + 1];
                    count[j + 1] = temp;
                    english[j + 1] = c_temp;
                }
            }
        }
        for (int i = 0;; i++)
        {
            if (count[i] == 0)
                break;
            else
                cout << english[i] << " " << count[i] << endl;
        }
    }
    return 0;
}