#include <iostream>
#include <string>
#include <iomanip>  //setprecision 精確取值用
#include <cmath>    //數學運算
using namespace std;

int main()
{

    double a, s, r = 6440, pi = 3.14159265359;//r是題目給的地球半徑 
    string an;

    while (cin >> s >> a >> an)//輸入測資
    {
        if (an == "min")//角度轉換 
        {            //1(deg)等於60(min) 
            a /= 60;
        }
        while (a >= 360)//超過360度就換成小的同位角 
        {
            a -= 360;

        }
        if (a > 180)//超過180度要用另一邊的角度 
        {
            a = 360 - a;
        }
        cout << fixed << setprecision(6);//精確到小數點下六位
        cout << (s + r) * a * pi / 180 << " ";//輸出弧長(角度換成弧度) 
        cout << (s + r) * sin(a / 2 * pi / 180) * 2 << "\n";//輸出直線距離
                                            //利用中垂線法找到直線距離 
    }
    return 0;
}