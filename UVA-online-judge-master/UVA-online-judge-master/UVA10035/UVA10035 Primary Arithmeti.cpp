#include <iostream>
using namespace std;
int main()
{
    long int a, b;
    while (cin >> a >> b && a && b)
    {
        if (a == 0 && b == 0) { break; }
        int c = 0, counter = 0;
        while (a != 0 || b != 0)    //檢查到兩者最高位
        {
            if ((a % 10 + b % 10 + c) >= 10) {
                counter++;//計數進位次數
                c = 1;//進位
            }
            else { c = 0; }
            a = a / 10;
            b = b / 10;
        }
        if (counter == 0) { cout << "No carry operation." << endl; }
        else if (counter == 1) { cout << "1 carry operation." << endl; }
        else { cout << counter << " carry operations." << endl; }
    }
    return 0;
}