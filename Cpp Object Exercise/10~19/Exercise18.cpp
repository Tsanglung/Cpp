/*
有一class employee, 此class有一virtual function 為getsalary(); 
employee有subclass
(1)pieceworker薪水計算公式為工作件數*200；
(2) hourlyworker薪水計算公式為工作時數*800；
(3)boss薪水計算公式為工作件數*10000
*/
#include<iostream>
using namespace std;
class Employee{
protected:
    int pieces , hour; string Name;
public:
    Employee(int p,string N,int h):pieces(p),Name(N),hour(h) {}
    virtual double getSalary() const = 0;
    virtual string getName() const = 0;
};

class Pieceworker : public Employee{
public:
    Pieceworker(int p,string n) : Employee(p, n , 0){}
    double getSalary() const {return pieces * 200;}
    string getName() const {return Name;}
};

class Hourlyworker : public Employee{
public:
    Hourlyworker(int h,string n):Employee(0 ,n, h) {}
    double getSalary() const {return hour * 800;}
    string getName() const {return Name;}
};

class Boss : public Employee{
public:
    Boss(int p,string n) : Employee(p , n , 0) {}
    double getSalary() const {return pieces * 10000;}
    string getName() const {return Name;}
};

int main(){
    Employee* employees[3];

    employees[0] = new Pieceworker(50,"han");  // 50 件工作
    employees[1] = new Hourlyworker(40,"john"); // 40 小時工作
    employees[2] = new Boss(5,"judy");          // 5 件工作

    for (int i = 0; i < 3; ++i) {
        cout << "Employee " << employees[i]->getName() << " salary: " << employees[i]->getSalary() << "元" << endl;
    }

    // ?放?存
    for (int i = 0; i < 3; ++i) delete  employees[i];
}