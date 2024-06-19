/*
使用繼承建立新的堆疊類別以修改push與pop兩函數的問題
*/
#include <iostream>
#include <cstdlib>
using namespace std;
class Stack{
protected:	
		 int* array;
		 int top, num;
public:
	Stack(int n) { num = n; top = 0; array = new int[num]; }
	~Stack() { delete[]array; cout << "動態配置記憶體已清除" << endl; }
	void push(int var) { array[top] = var; top++; }
	void pop() { top--; cout << array[top] << endl; }
};

class StacSon :public Stack{
public:
	StacSon(int n) :Stack(n) { }
	void push(int var)
	{
		if (top < num) Stack::push(var);
		else { cout << "堆疊已滿" << endl; }
	}
	void pop()
	{
		if (top > 0) Stack::pop();
		else { cout << "堆疊已空"; }
	}
};

int main()
{
	StacSon s(5);
	s.push(5);
	s.push(6);
	s.push(7);
	s.push(8);
	s.push(9);
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	cout << endl;
}