#include <iostream>
#include <cstdlib>
using namespace std;

class ChainNode
{
	friend class Chain;
public:
	ChainNode(int element = 0, ChainNode* next = 0){ data = element; link = next;}
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
	void Output(void);
	ChainNode* Search(int n, bool beforeNode);
	int Length(void);
};

void Chain::Create(int* a)//P182
{
	ChainNode* p;
	//create and set fields of first node
	first = new ChainNode(a[0], 0);
	p = first;

	for (int i = 1; i < 5; i++)
	{
		Insert(p, a[i]);
		p = p->link;
	}
}

void Chain::Insert(ChainNode* x, int NewData)//Inserts a node after node x 
{

	if (x == NULL)	cout << "No Data." << endl;
	else
	{
		if (first)	x->link = new ChainNode(NewData, x->link);
		else	first = new ChainNode(NewData);
	}
}

void Chain::Delete(ChainNode* x, ChainNode* y)//Delete node x from the chain
{
	if (x == NULL)	cout << "No Data." << endl;
	else
	{
		if (x == first)	first = first->link;
		else	y->link = x->link;
		delete x;
	}
}

int Chain::Length(void)
{
	ChainNode* currentNode;
	int count = 0;
	currentNode = first;
	while (currentNode != NULL)
	{
		count++;
		currentNode = currentNode->link;
	}
	return count;
}

void Chain::Output(void)	// 輸出結果
{
	ChainNode* currentNode;
	currentNode = first;
	cout << "Data:";
	while (currentNode != NULL)
	{
		cout << currentNode->data;
		if (currentNode->link != NULL)	cout << "->";
		currentNode = currentNode->link;
	}
	cout << endl;
	cout << "Length:" << Length() << endl;
}

ChainNode* Chain::Search(int n, bool beforeNode = false) //搜尋 node
{
	ChainNode* currentNode, * beforeData;
	currentNode = first;
	beforeData = currentNode;

	while (currentNode->data != n)
	{
		beforeData = currentNode;
		currentNode = currentNode->link;
		if (currentNode == NULL)	return NULL;
	}
	if (beforeNode)
		return beforeData;

	return currentNode;
}

int main(void)
{
	int a, b;
	int *ChainArray = new int [100];
	Chain chain;
	for (int i = 0; i < 5; i++)
		cin >> ChainArray[i];

	chain.Create(ChainArray);
	chain.Output();

	while (cin >> a >> b)
	{
		if (b != -1) // 搜尋 nodo，若有則插入 b 在 a 後
			chain.Insert(chain.Search(a), b);
		else //b = -1 則刪除 node，若 node 存在
			chain.Delete(chain.Search(a), chain.Search(a, true));
		chain.Output();
	}
	delete [] ChainArray;
}
