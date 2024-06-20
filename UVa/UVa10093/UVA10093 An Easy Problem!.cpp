#include <iostream>
#include<string>
using namespace std;

int main() {
    int sum, mx, temp;
    string CinR;
    while (getline(cin, CinR)) {
        sum = 0;//轉10進位
        mx = 1;
        int i;
        for (i = 0; i < CinR.size(); i++) {
            if (CinR[i] >= '0' && CinR[i] <= '9') { //0~9 10個數字
                temp = CinR[i] - '0';
            }
            else if (CinR[i] >= 'A' && CinR[i] <= 'Z') { //A~Z 26字母
                temp = CinR[i] - 'A' + 10; //+10 前有0~9，10個數字
            }
            else if (CinR[i] >= 'a' && CinR[i] <= 'z') {
                temp = CinR[i] - 'a' + 36; //+36 前有0~9，A~Z，36個字元
            }
            if (mx < temp)
                mx = temp;
            sum += temp;
        }
        for (i = mx; i < 62; i++) //mx是當前進制到62進制
            if (!(sum % i)) {//若轉成10進制可以被(N-1)進制整除
                cout << i + 1 << "\n";//被(N-1)整除的最小N進制
                break;
            }

        if (i == 62)
            cout << "such number is impossible!\n";
    }
    return 0;
}