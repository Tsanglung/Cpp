/*
定義一個運算（Calculate）類別，其資料成員與成員函數
(a)定義private資料成員x，用來存放運算值。
(b)定義建立者（constructor）函數，並設定x的初值為0。
(c)定義public成員函數add、sub、mul與div，處理加、減、乘、除四則計算。
(d)撰寫一個驅動程式，先選擇加、減、乘、除運算，再輸入二數值後執行所選擇的運算並輸出運算結
*/
#include<iostream>
using namespace std;
class Calcula{
private:
    double x;
public:
    Calcula(){ x = 0; }
    int add(double a, double b){return x = a + b;}
    int sub(double a, double b){return x = a - b ;}
    int mul(double a, double b){return x = a * b;}
    double div(double a, double b){return x = a / b;}
};

int main(){
    Calcula C;
    char sign;double a ,b;
    cout << "選擇四則運算 : ";
    cin >> sign;
    switch (sign)
    {
    case '+':
        cout << "Input two number : ";
        cin >> a >> b;
        cout << a << sign << b << " = " << C.add(a , b) <<endl;
        break;
    case '-':
        cout << "Input two number : ";
        cin >> a >> b;
        cout << a << sign << b << " = " << C.sub(a , b) <<endl;
        break;
    case '*':
        cout << "Input two number : ";
        cin >> a >> b;
        cout << a << sign << b << " = " << C.mul(a , b) <<endl;
        break;
    case '/':
        cout << "Input two number : ";
        cin >> a >> b;
        cout << a << sign << b << " = " << C.div(a , b) <<endl;
        break;
    default:
        break;
    }
}