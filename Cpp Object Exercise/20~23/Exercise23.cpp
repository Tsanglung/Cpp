/*
建立一個字串運算（CString）類別，其資料成員與成員函數如下
a)定義private資料成員str，用來存放C型態字串。
b)多載算術運算符號+=，作為串接二個C型態字串的運算符號。
c)多載輸入、輸出運算符號>>、<<，來輸入與輸出C型態字串資料。
d)撰寫main() 函數，由鍵盤輸入二筆字串資料，呼叫多載+= 運算符號，將二個字串串接在一起。
*/
#include<iostream>
using namespace std;
class CString{
    friend istream& operator>>(istream& is, CString& c);
    friend ostream& operator<<(ostream&os, const CString& c);
private:
    string str;
public:
    CString operator+=(const CString c);
};

istream &operator>>(istream& is, CString& c){is >> c.str; return is;}
ostream &operator<<(ostream& os,const CString& c){os << c.str <<endl; return os;}

CString CString::operator+=(const CString c){this->str += c.str; return *this;}

int main(){
    CString A,B;
    cout << "first string : ";
    cin >> A;
    cout << "second string : ";
    cin >> B;
    A += B;
    cout <<"串接後 : ";
    cout << A << endl;
}


