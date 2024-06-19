/*
設計一計數器類別內有一整數屬性值
及下列4個方法：
inc(int i):將計數器的值加i
dec(int i):將計數器的減i
reset() :將計數器的值歸0
print():印出計數器的值
利用繼承修改上述計數器類別設計出有上、下限的計數器，(物件建立時給定此物件之上限與下限，inc與dec運算時若值超過上下限則部與執行)。
*/
#include <iostream>
#include <cstdlib>
using namespace std;
class counter
{
protected: 
    int value;
public: 
    counter(int n) { cout << "parent constructor is called\n"; value = n; }
    void inc(int i) { value += i; } //將計數器的值加 n
    void dec(int i) {value -= i;} //將計數器的減 n
    void reset() { value = 0; } //將計數器的值歸0
    void print() { cout << "The value in counter is:" << value << endl; }
};
class limited_counter : public counter//繼承
{
public:
	limited_counter(int v, int u, int d):counter(v){
        cout << "son constructor is called\n"; 
        value = v;
        up = u; 
        down = d; 
    }
	void inc(int n) { if ((value + n <= up) && (value + n >= down)) value += n; }
    void dec(int n) { if ((value - n <= up) && (value - n >= down)) value -= n; }
private:
	int up, down;
};
int main()
{
	limited_counter a_counter(1, 8, -5);
	for (int i = 1; i <= 10; i++)
        a_counter.inc(i);
	a_counter.inc(-3); 
    a_counter.print();
	system("pause");
	return 0;
}
