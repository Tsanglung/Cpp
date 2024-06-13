#include <iostream>
#include <cstdlib>
using namespace std;

class ChainNode //P181
{
	friend class Chain;

public:
	ChainNode(int element = 0, ChainNode* next = 0)//0 is the default value for element and next
	{
		data = element;
		link = next;
	}

private:
	int data;
	ChainNode* link;
};

class Chain
{
private:
	ChainNode* first;
public:
	void Create(int* a);
	void Push(int NewData);
	void Pop();
	void Print(void);
	ChainNode* Search(int n, bool beforeNode);
	int Length(void);
};

void Chain::Create(int* a)//P182
{
	ChainNode* pointer;
	//create and set fields of first node
	first = new ChainNode(a[0], 0);
	pointer = first;

	for (int i = 1; i < 5; i++)
	{
		Push(a[i]);
		pointer = pointer->link;
	}
	/*//create and set fields of second node
	ChainNode* second = new ChainNode(a[1], 0);

	//create and set fields of first node
	first = new ChainNode(a[0], second);*/
}

void Chain::Push(int NewData)//Inserts a node after node x P182
{
	ChainNode* pointer;
	pointer = first;
	while (pointer->link != NULL)
	{
		pointer = pointer->link;
	}
	if (first)
	{
		//insert after x;
		pointer->link = new ChainNode(NewData, NULL);
	}
	else
	{
		//insert into empty list
		first = new ChainNode(NewData);
	}
}

void Chain::Pop()//Pop node x from the chain P183
{
	ChainNode* pointer;
	pointer = first;
	while (pointer->link->link != NULL)
	{
		pointer = pointer->link;
	}
	delete pointer->link;
	pointer->link = NULL;

}

int Chain::Length(void)
{
	ChainNode* pointer;
	int count = 0;
	pointer = first;
	while (pointer != NULL)
	{
		count++;
		pointer = pointer->link;
	}
	return count;
}

void Chain::Print(void)
{
	ChainNode* pointer;
	pointer = first;
	cout << "Data:";
	while (pointer != NULL)
	{
		cout << pointer->data;
		if (pointer->link != NULL)
		{
			cout << "->";
		}
		pointer = pointer->link;
	}
	cout << endl;
	cout << "Length:" << Length() << endl;
}

ChainNode* Chain::Search(int n, bool beforeNode = false)
{
	ChainNode* pointer, * beforePointer;
	pointer = first;
	beforePointer = pointer;

	while (pointer->data != n)
	{
		beforePointer = pointer;
		pointer = pointer->link;
		if (pointer == NULL)
		{
			return NULL;
		}
	}
	if (beforeNode)
	{
		return beforePointer;
	}
	return pointer;
}

void main(void)
{
	//統一輸入五個值
	//Pop不再裡面的值->輸出沒這個值
	int a, b;
	int d[5];
	Chain LS;
	cin >> d[0] >> d[1] >> d[2] >> d[3] >> d[4];

	LS.Create(d);
	LS.Print();

	while (cin >> a)
	{
		if (a != -1)
		{
			LS.Push(a);
		}
		else
		{
			LS.Pop();
		}
		LS.Print();
	}
}
