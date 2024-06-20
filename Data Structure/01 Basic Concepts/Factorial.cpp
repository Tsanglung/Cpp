#include<iostream>
using namespace std;

int RFactorial(int n)//»¼°j¶¥­¼
{
    if(n <= 1) return 1;
    else return n * RFactorial(n - 1);
} 

int main()
{
    int n;
    cin >> n;
    cout << n << "! = " << RFactorial(n) << endl;
}