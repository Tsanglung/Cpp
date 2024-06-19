/*
建立一個圓形（Circle）類別，其資料成員與成員函數:
定義private資料成員radius，存放圓的半徑。
定義建立者（constructor）函數，並設定radius的初值為1。
定義public成員函數set與get，分別用來設定與取得radius值。
定義public成員函數perimeter與area，分別用來計算圓周長與圓面積。
撰寫main() 函數，由鍵盤輸入資料並存入radius中，然後計算並顯示圓周長與圓面積
*/
#include<iostream>
using namespace std;
class Circle{
private:
    double radius;
public:
    Circle(){ radius = 1;}
    void set(int r); // 設定 r
    double get(); // 取得 r
    double perimeter();   // 圓周長
    double area();    //圓面積
};

void Circle::set(int r){ radius = r; }
double Circle::get(){ return radius;}
double Circle::perimeter(){ return 2 * radius * 3.14;}
double Circle::area(){ return radius * radius * 3.14;}

int main(){
    Circle C1;
    int radius;
    cout << "輸入半徑 : ";
    cin >> radius;
    C1.set(radius);
    cout << "半徑 : " << C1.get() << endl;
    cout << "圓周長 : " << C1.perimeter() << endl;
    cout << "園面積 : " << C1.area() << endl;
}