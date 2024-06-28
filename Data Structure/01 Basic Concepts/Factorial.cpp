#include<iostream>
using namespace std;

int RFactorial(int n)//»¼°j¶¥­¼
{
    if(n <= 1) return 1;
    else return n * RFactorial(n - 1);
} 
 
int Factorial(int n)
{
    int F = 1;
    for(int i = n;i > 0;i--) F *= i;
    return F;
}

int main()
{
    int n;
    cin >> n;
    cout << n << "! = " << RFactorial(n) << endl;
    cout << n << "! = " << Factorial(n) << endl;
}