#include<iostream>
using namespace std;
//Exercise 2.1.4
//複數，加、減、乘、除
class Complex
{
private:
	double a = 0, bi = 0; double den;
public:
	Complex() {}//建構子
	Complex(double a,double bi):a(a),bi(bi) {}	//copy

	friend istream& operator>>(istream& is, Complex& A);//overloading >>
	friend ostream& operator<<(ostream& os, Complex& A);//overloading <<
	
	Complex operator+(const Complex& s) //add
	{
		Complex Add;
		Add.a = a + s.a;
		Add.bi = bi + s.bi;
		Add.den = 1;
		return Add;
	}

	Complex operator-(const Complex& s) //sub
	{
		Complex Sub;
		Sub.a = a - s.a;
		Sub.bi = bi - s.bi;
		Sub.den = 1;
		return Sub;
	}

	Complex operator*(const Complex& s) //mul
	{
		//(a+bi)*(s.a+s.bi)
		Complex Mul;
		Mul.a = a * s.a - bi * s.bi;
		Mul.bi = a * s.bi + s.a * bi;
		Mul.den = 1;
		return Mul;
	}

	Complex operator/(const Complex& s) //div
	{
		//(a+bi)/(s.a+s.bi)
		Complex Div;
		Div.a = a * s.a - bi * (-s.bi);
		Div.bi = a * (-s.bi) + s.a * bi;
		Div.den = s.a * s.a - s.bi * (-s.bi);
		return Div;
	}
};

istream& operator>>(istream& is, Complex& A)
{
	is >> A.a >> A.bi;
	return is;
}

ostream& operator<<(ostream& os, Complex& A)
{
	if (A.den == 1) 
	{
		if (A.bi < 0) 
			os << A.a << A.bi << 'i' << endl;
		else 
			os << A.a << '+' << A.bi << 'i' << endl; 
	}
	else
	{
		if (A.bi < 0) 
			os << '(' << A.a << A.bi << 'i)/' << A.den << endl;
		else
			os << '(' <<  A.a << '+' << A.bi << "i)/" << A.den << endl; 
	}
	return os;
}

int main() 
{
	Complex C1, C2;
	cin >> C1;
	cin >> C2;
	Complex C3 = C1 + C2;
	cout << C3;
	Complex C4 = C1 - C2;
	cout << C4;
	Complex C5 = C1 * C2;
	cout << C5;
	Complex C6 = C1 / C2;
	cout << C6;
}
