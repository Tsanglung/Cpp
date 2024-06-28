#include <iostream>
using namespace std;
int RFibonacci (int n)// �O��ƦC
{ //recursive
   if(n == 0) return 0; 
   else if(n == 1) return 1;
   else return RFibonacci(n - 1) + RFibonacci(n - 2);
} 

void Fibonacci(int n)
{ //iterative
  if( n <= 1) cout << n << endl;
  else {
    int fn,fn1 = 1,fn2 = 0;
    for(int i = 2; i <= n ; i++){
      fn = fn1 + fn2;
      fn2 = fn1;
      fn1 = fn;
    }
    cout << "Fibonacci("  << n << ") is " << fn << endl;
  }
}

int main() 
{
  int n;
  cout << "Input n : ";
  cin >> n;
  cout << "Fibonacci("  << n << ") is " << RFibonacci(n) << endl;
  Fibonacci(n);
}
