#include<iostream>
using namespace std;
//�G�����Y��
int Binomial(int n,int m)
{   //recursive
    if (m == 0 || m == n) return 1; 
    else return Binomial(n - 1, m) + Binomial(n - 1, m - 1);
}
 
int main()
{
    int m , n;
    cout << "Input m , n : ";
    cin >> m >> n;
    cout<< "Binomial Coefficient(" << m << "," << n <<") = " << Binomial(m , n) << endl; 
}