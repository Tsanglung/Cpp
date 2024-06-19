/*
建立Point、Square、Circle、Cylinder類別，其類別定義、資料成員與成員函數如下：
a)Point類別：保護區含r, h二個資料變數，公用區含二參數的Point建立者、setpoint() 函數將鍵盤輸入存入r,  h、getR() 與getH() 函數傳回r值與h值。
b)Square類別：以public型態繼承Point，保護區含area() const函數計算正方形面積，公用區含一參數的Square建立者、getArea() const函數傳回area() 值。
c)Circle類別：以public型態繼承Point，保護區含area()  const函數計算圓面積，公用區含一參數的Circle建立者、getArea()  const函數傳回area() 值。
d)Cylinder類別：以public型態繼承Square與Circle類別，保護區含volume() const函數與height資料變數，公用區含二參數的Cylinder建立者、getVolume() const函數傳回圓柱體的volume() 值。
寫一main() 函數，首先利用建立者起始r, h值，然後計算並輸出r, h值、正方形面積、圓形面積、與圓柱體體積
*/
#include <iostream>
#include <cmath>
using namespace std;
class Point {// Point 類別
protected:
    double r, h;//保護區含r, h二個資料變數
public:
    Point(double r = 0, double h = 0) : r(r), h(h) {}//二參數的Point建立者
    void setPoint(double r, double h) { this->r = r; this->h = h; }//二參數的setpoint() 函數
    double getR() const { return r; }
    double getH() const { return h; }
};

class Square : public Point {// Square 類別
protected:
    double area() const { return r * r; }
public:
    Square(double r) : Point(r, 0) {}
    double getArea() const { return area(); }
};

class Circle : public Point {// Circle 類別
protected:
    double area() const { return M_PI * r * r; }
public:
    Circle(double r) : Point(r, 0) {}
    double getArea() const { return area(); }
};

class Cylinder : public Square, public Circle {// Cylinder 類別
protected:
    double volume() const { return Circle::area() * height; }
    double height;
public:
    Cylinder(double r, double h) : Square(r), Circle(r), height(h) {}
    double getVolume() const { return volume(); }
};

int main() {
    double r, h;

    cout << "輸入半徑 (r)、高度 (h): ";
    cin >> r >> h;
    // 使用建立者起始 r 和 h 值
    Point p(r, h);
    Square s(r);
    Circle c(r);
    Cylinder cy(r, h);

    cout << "半徑 (r): " << p.getR() << ", 高度 (h): " << p.getH() << endl;
    cout << "正方形面積: " << s.getArea() << endl;
    cout << "圓面積: " << c.getArea() << endl;
    cout << "圓柱體體積: " << cy.getVolume() << endl;

    return 0;
}
