/*
建立一個房屋貸款類別, 其資料成員與成員函數如下:
(1) 定義private 資料成員loan,rate,year, 分別存放貸款總額, 貸款利率與貸款年數
(2) 定義建構子函數, 並設定所有資料成員的初值為0
(3) 定義public 成員函數set與get, 用來設定與取得loan, rate,year值
(4)定義public 成員函數term, payement分別計算期費=(1+年利率/12)12*年數與月付額=(貸款總額*(年利率/12)*期費)/(期費-1)
(5)在主程式撰寫一驅動程式, 輸入loan,rate,year,然後顯示月付額Ex. Loan=1000000, rate=0.02, year=20 =>月付額=5058.8
*/
#include<iostream>
#include<math.h>
using namespace std;
class HouseLoans{
private:
    int loan; double rate; int year;
public:
    HouseLoans(int l = 0,double r = 0,int y = 0):loan(l),rate(r),year(y){}
    void set(int l,double r, int y){loan = l; rate = r;year = y;};
    void get(){cout << "貸款總額 : " << loan << ",貸款利率 : " << rate << ",貸款年數 : " << year << endl;}
    double term();
    double payement();
};

double HouseLoans::term(){ return pow((1 + (rate / 12)) , (12 * year));}
double HouseLoans::payement(){ return ((loan * (rate / 12) * term())/(term()-1));}

int main(){
    int loan; double rate; int year;
    HouseLoans H;
    cout << "輸入貸款總額、貸款利率、貸款年數:";
    cin >> loan >> rate >> year;
    H.set(loan,rate,year);
    H.get();
    cout << "期費 : " << H.term() << " $ "<< endl;
    cout << "月付額 : " << H.payement() << " $ " << endl;
}