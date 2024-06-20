#include <bits/stdc++.h>
using namespace std;

string input;

int main() {
    
    while (getline(cin, input)) {  // 讀取一行輸入
        int count = 0;
        bool wordStart = false;
        for (char c : input) {  // 迭代該行的每個字元
            //isalpha函數檢查給定字符是否為字母表
            if (isalpha(c) && !wordStart) {  // 如果是字母且還未開始新單字
                count++;  // 新單字計數器加一
                wordStart = true;  // 設置開始新單字
            } else if (!isalpha(c)) {  // 如果不是字母
                wordStart = false;  //結束單字
            }
        }
        cout << count << endl;  // 輸出該行單字數
    }
    return 0;
}
