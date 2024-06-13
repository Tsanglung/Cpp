#include<iostream>
using namespace std;

class Poly
{
private:
	int a, b, c;
public:
	Poly() { a = 0, b = 0,c = 0; }//constructor
	Poly(int a,int b,int c):a(a),b(b),c(c) {}

	int Eval(int x) 
	{
		int Ans;
		Ans = x * x * a + x * b + c;
		return Ans;
	}

	friend istream& operator>>(istream& is, Poly& A);//overloading >>
	friend ostream& operator<<(ostream& os, Poly& A);//overloading <<
	
	Poly operator+(const Poly& s) //Add
	{
		Poly Add;
		Add.a = a + s.a;
		Add.b = b + s.b;
		Add.c = c + s.c;
		return Add;
	}
};

istream& operator>>(istream& is, Poly& A)
{
	is >> A.a >> A.b >> A.c;
	return is;
}

ostream& operator<<(ostream& os, Poly& A)
{
	if (A.a == 0) { os << A.b << "x+" << A.c;}
	else if (A.b == 0) { os << A.a << "x^2+" << A.c; }
	else if (A.c == 0) { os << A.a << "x^2" << A.b << "x"; }
	else if (A.a == 0 and A.b == 0) { os << A.c; }
	else if (A.a == 0 and A.c == 0) { os << A.b<<"x"; }
	else if (A.b == 0 and A.c == 0) { os << A.a << "x^2"; }
	else { os << A.a << "x^2+" << A.b << "x+" << A.c; }
	return os;
}

int main() 
{
	Poly P1, P2;
	cin >> P1;
	cin >> P2;
	cout << "P1: " << P1 << endl;
	cout << "P2: " << P2 << endl;
	Poly P3 = P1 + P2;
	cout << "P1+P2: " << P3;
	cout << endl;
	cout << "Input x value of Polynomial: ";
	int x; cin >> x;
	cout << P3.Eval(x);
}
