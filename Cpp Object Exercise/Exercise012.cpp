/*
使用繼承建立新的堆疊類別以修改push與pop兩函數的問題
*/
#include <iostream>
#include <cstdlib>
using namespace std;
class Stack
{
protected:
	int array[5]; //存放堆疊資料
	int top; //由0開始, 記錄陣列下一個可以存放資料的index
public:
	Stack() { top = 0; }
	void push(int var) { array[top] = var; cout << array[top] << endl; top++; }
	void  pop() { top--; cout << array[top] << endl; }
};
class StackSon :public Stack //繼承
{
public:
	StackSon() { }
	void push(int var)
	{
		if (top < 5) Stack::push(var);
		else { cout << "堆疊已滿" << endl; }
	}
	void pop() {
		if (top > 0)  Stack::pop();
		else { cout << "堆疊已空"; }
	}

};
int main()
{
	StackSon s;
	cout << "push : " << endl;
	s.push(5);
	s.push(6);
	s.push(7);
	s.push(8);
	s.push(9);
	s.push(10);
	cout << "pop :" << endl;
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	cout << endl;
	return 0;
}
