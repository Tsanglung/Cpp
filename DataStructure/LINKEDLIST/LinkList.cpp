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
	void Insert(ChainNode* x, int NewData);
	void Delete(ChainNode* x, ChainNode* y);
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
		Insert(pointer, a[i]);
		pointer = pointer->link;
	}
	/*//create and set fields of second node
	ChainNode* second = new ChainNode(a[1], 0);

	//create and set fields of first node
	first = new ChainNode(a[0], second);*/
}

void Chain::Insert(ChainNode* x, int NewData)//Inserts a node after node x P182
{

	if (x == NULL)
	{
		cout << "No Data." << endl;
	}
	else
	{
		if (first)
		{
			//insert after x;
			x->link = new ChainNode(NewData, x->link);
		}
		else
		{
			//insert into empty list
			first = new ChainNode(NewData);
		}
	}
}

void Chain::Delete(ChainNode* x, ChainNode* y)//Delete node x from the chain P183
{
	if (x == NULL)
	{
		cout << "No Data." << endl;
	}
	else
	{
		if (x == first)
		{
			first = first->link;
		}
		else
		{
			y->link = x->link;
		}

		delete x;
	}
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
	//Delete不再裡面的值->輸出沒這個值
	int a, b;
	int d[5];
	Chain LS;
	cin >> d[0] >> d[1] >> d[2] >> d[3] >> d[4];

	LS.Create(d);
	LS.Print();

	while (cin >> a >> b)
	{
		if (b != -1)
		{
			LS.Insert(LS.Search(a), b);
		}
		else
		{
			LS.Delete(LS.Search(a), LS.Search(a, true));
		}
		LS.Print();
	}
}
