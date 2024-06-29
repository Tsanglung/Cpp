#include<iostream>
using namespace std;

template<class T>
class Chain;

template<class T>
class ChainNode
{
    friend class Chain<T>;
    private:
        T data;
        ChainNode<T> *link;
    public:
        ChainNode<T>(T element = 0, ChainNode<T> *next = 0):data(element) , link(next){}
};

template<class T>
class Chain
{
    private:
        ChainNode<T> *first;
    public:
        Chain():first(nullptr){}
        ChainNode<T> *GetNode(T data);//取得 node 如果存在
        void Create(T e);
        void Insert(T e,ChainNode<T> *x);//插入在 x 之後，如果 x 存在
        void Delete(ChainNode<T> *x , ChainNode<T> *y); //將 x 刪除，y 接續在 x 前一個節點
        void Output();
};

template<class T>
ChainNode<T> *Chain<T>::GetNode(T data)
{
    ChainNode<T>* current = first;
    while (current != nullptr && current->data != data) 
        current = current->link;
    return current;
}

template <class T>
void Chain<T>::Create(T data){first = new ChainNode<T>(data,0);}

template<class T>
void Chain<T>::Insert(T newData,ChainNode<T> *x)
{
    if(first)   x->link = new ChainNode<T>(newData , x->link);
    else    first = new ChainNode<T>(newData);
}

template<class T>
void Chain<T>::Delete(ChainNode<T> *x, ChainNode<T> *y)
{
    if(x == first) first = first->link;
    else y->link = x->link;
    delete x;
}

template<class T>
void Chain<T>::Output()
{
    ChainNode<T> *current = first;
    while(current != NULL)
    {
        cout << current->data;
        if(current->link != NULL) cout << "->";
        current = current->link;
    }
    cout << endl;
}

int main()
{
    Chain<int> Chain1;
    Chain1.Create(10);
    Chain1.Output();
    ChainNode<int>* preNode = Chain1.GetNode(10);
    Chain1.Insert(20, preNode);
    Chain1.Output();
    Chain1.Insert(30, preNode);
    Chain1.Output();
    Chain1.Delete(Chain1.GetNode(30),Chain1.GetNode(10));
    Chain1.Output();
    preNode = Chain1.GetNode(20);
    Chain1.Insert(20, preNode);
    Chain1.Output();
    Chain1.Insert(100, preNode);
    Chain1.Output();
}