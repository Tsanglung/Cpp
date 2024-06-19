/*
建立一個複數四則運算（Complex）類別，其資料成員與成員函數如下
a)定義private資料成員real、imaginary存放實數、虛數部分。
b)多載算術運算符號+、-、*、/，來執行複數的四則運算。
c)多載輸入、輸出運算符號>>、<<，來輸入與輸出複數資料。
d)撰寫main() 函數，由鍵盤輸入二筆複數，執行加、減、乘、除後輸出。
*/
#include<iostream>
#include<cmath>
using namespace std;
class Complex{
    friend istream& operator>>(istream& is, Complex t){is >> t.real >> t.imaginary; return is;}
    friend ostream& operator<<(ostream& os, Complex t){os << t.real << " + "<< t.imaginary <<"i"; return os;}
private:
    double real,imaginary;
public:
    Complex(double r = 0, double i = 0) { real = r; imaginary = i; }//建構子
    Complex operator+(const Complex& t) { Complex Add; Add.real = real + t.real; Add.imaginary = imaginary + t.imaginary; return Add; }//加
    Complex operator-(const Complex& t) { Complex Sub; Sub.real = real - t.real; Sub.imaginary = imaginary - t.imaginary; return Sub; }//減
    Complex operator*(const Complex& t)//乘
    {
        Complex Mul;
        Mul.real = real * t.real - imaginary * t.imaginary;
        Mul.imaginary = real * t.imaginary + imaginary * t.real;
        return Mul;
    }
    Complex operator/(const Complex& t)//除
    {
        Complex Div;
        if((pow(t.real, 2) + pow(t.imaginary,2)) != 0){
            Div.real = ((real * t.real + imaginary * t.imaginary)) / (pow(t.real, 2) + pow(t.imaginary,2));
            Div.imaginary = ((imaginary * t.real) - (real * t.imaginary)) / (pow(t.real, 2) + pow(t.imaginary,2));
        }
        return Div;
    }
    bool operator==(const Complex& t){if(real == t.real && imaginary == t.imaginary) return true;else return false;}
    bool operator!=(const Complex& t){if(real != t.real || imaginary != t.imaginary) return true;else return false;}
};

int main(){
    int a,b,c,d;
    cout<<"Enter first complex number y in the form: a + bi:";
    cin >> a >> b;
    Complex A(a,b);
    cout<<"Enter first complex number y in the form: c + di:";
    cin >> c >> d;
    Complex B(c,d);

    if(A == B) cout << "complex A and B is Same complex" << endl;
    else cout << "complex A and B is not same" << endl;

    Complex C;
    C = A + B;
    cout << "(" << A << ") + (" << B << ") = " << C << endl;
    C = A - B;
    cout << "(" << A << ") - (" << B << ") = " << C << endl;
    C = A * B;
    cout << "(" << A << ") * (" << B << ") = " << C << endl;
    C = A / B;
    cout << "(" << A << ") / (" << B << ") = " << C << endl;
}