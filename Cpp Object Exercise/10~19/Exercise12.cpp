/*
�ϥ��~�ӫإ߷s�����|���O�H�ק�push�Ppop���ƪ����D
*/
#include <iostream>
#include <cstdlib>
using namespace std;
class Stack
{
protected:
	int array[5]; //�s����|���
	int top; //��0�}�l, �O���}�C�U�@�ӥi�H�s���ƪ�index
public:
	Stack() { top = 0; }
	void push(int var) { array[top] = var; cout << array[top] << endl; top++; }
	void  pop() { top--; cout << array[top] << endl; }
};
class StackSon :public Stack //�~��
{
public:
	StackSon() { }
	void push(int var)
	{
		if (top < 5) Stack::push(var);
		else { cout << "���|�w��" << endl; }
	}
	void pop() {
		if (top > 0)  Stack::pop();
		else { cout << "���|�w��"; }
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
