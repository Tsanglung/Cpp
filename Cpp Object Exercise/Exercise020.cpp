#include <iostream>
#include <cstdlib>
using namespace std;
const int length=10;  //設定堆疊最大空間
template<class S>
class Stack  //定義堆疊類別範本
{          S array[length];     int top;
  public: Stack() {top=0;}
              void push(int obj); //宣告推入資料函數原型
              void pop(); //宣告取回資料函數原型
};
template<class S>
void Stack<S>::push(int obj)
{ if(top==length) {cout<<"堆疊滿了!\n";} 
       else   {array[top]=obj;  top++;}
}
template<class S>
void  Stack<S>::pop()
{ if(top==0) {cout<<"堆疊空了!\n";} 
    else {top--; cout<<array[top]<<endl;}
 }
int main()
{
    int i;
    Stack<int> iStack;
    iStack.push(10);
    iStack.push(20);
    iStack.push(30);
    for (i = 2; i >= 0; i--)
        iStack.pop();

    Stack<char> cStack;
    cStack.push('a');
    cStack.push('b');
    cStack.push('c');
    for (i = 2; i >= 0; i--)
        cStack.pop();
    cout << endl;
    system("pause"); return 0;
}
