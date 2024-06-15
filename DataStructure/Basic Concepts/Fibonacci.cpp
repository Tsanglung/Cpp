#include <iostream>
using namespace std;
int Fibonacci (int n)// ¶O¤ó¼Æ¦C
{
   if(n == 0) return 0; 
   else if(n == 1) return 1;
   else return Fibonacci(n - 1) + Fibonacci(n - 2);
} 

int main()
{
  int n;
  cout << "Input n : ";
  cin >> n;
  cout << "Fibonacci("  << n << ") is " << Fibonacci(n) << endl;
}
