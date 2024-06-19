/*
建立一多型繼承階層：基礎類別Shape為抽象類別，
由Shape類別衍生出球Ball類別與Cynlinder類別，
Ball類別體積vol(): 4/3*3.14* r^3，
Cynlinder類別體積vol():3.14* r^2*h；
output為外部函數，用於測試Ball與Cylinder之vol函數
*/
#include<iostream>
#include<math.h>
#include <complex>
using namespace std;
class Shape{
protected:
    double radius;
public:
    Shape(){radius = 1;}
    void set(double r){radius = r;}
    virtual void vol() = 0;
};

class Ball:public Shape{
public:
    Ball(){}
    void vol(){ cout << "Ball 體積 : " << (4 / 3) * 3.14 * pow(radius,3) << endl;}
};

class Cynlinder:public Shape{
private:
    double heigh;
public:
    Cynlinder(){}
    void set(double r,double h) {radius = r; heigh = h;}
    void vol(){ cout << "Cynlinder 體積 : " << 3.14 * pow(radius,2) * heigh << endl;}
};

void output(Shape *radius){radius->vol();}

int main(){
    Ball B;
    Cynlinder C;
    B.set(3);
    C.set(2.3,5);
    output(&B);
    output(&C);
}