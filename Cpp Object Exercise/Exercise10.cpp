//設計一父類別ClassA內含兩個public整數資料成員numA與numB
/*設計一子類別ClassB,繼承自ClassA類別,
並加入set_num()函數,用來設定從父類別繼承而來的成員numA與numB,
與show()函數,用來顯示numA與numB的值
*/
//在主程式main()裡宣告ClassB類別的變數bdata,
//利用set_num()函數將numA設值為55, numB設值為88,
//再以show()印出成員之值
#include<iostream>
using namespace std;
class A{
public:
    int numA,numB;
};

class B:public A{
public:
    void set_num(int a,int b){numA = a; numB = b;}
    void show(){cout << "numA = " << numA << ", numB = " << numB<<endl;}
};

int main(){
    B bdata;
    bdata.set_num(55,88);
    bdata.show();
}