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
	int PushNumber;
	cout << endl << "��J�npush�X�Ӽ�:";
	cin >> PushNumber;
	for (int i = 0; i < PushNumber; i++) {
		s.push(i);
	}
	int PopNumber;
	cout << endl << "��J�npop�X�Ӽ�:";
	cin >> PopNumber;
	for (int i = 0; i < PopNumber; i++) {
		s.pop();
	}
	cout << endl;
	system("pause"); return 0;
}
