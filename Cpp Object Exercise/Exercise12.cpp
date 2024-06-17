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
	int PushNumber;
	cout << endl << "輸入要push幾個數:";
	cin >> PushNumber;
	for (int i = 0; i < PushNumber; i++) {
		s.push(i);
	}
	int PopNumber;
	cout << endl << "輸入要pop幾個數:";
	cin >> PopNumber;
	for (int i = 0; i < PopNumber; i++) {
		s.pop();
	}
	cout << endl;
	system("pause"); return 0;
}
