//建立兩overloading的exchange函數，再將此兩exchange函數改成函數樣版
#include <iostream>
using namespace std;
template<class T>
void Exchange(T &a, T &b){//函數樣版
    T tmp = a;
    a = b;
    b = tmp;
    cout << a << " , " << b << endl;
}

void Exchange(int &a,int &b){//overloading
    int tmp = a;
    a = b;
    b = tmp;
    cout << a << " , " << b << endl;
}

void Exchange(double &a, double &b){//overloading
    double tmp = a;
    a = b;
    b = tmp;
    cout << a << " , " << b << endl;
}

int main(void)
{
    int a, b;
    cin >> a >> b;
    Exchange(a,b);
    Exchange<int>(a,b);

    double x, y;
    cin >> x >> y;
    Exchange(x,y);
    Exchange<double>(x,y);
}
