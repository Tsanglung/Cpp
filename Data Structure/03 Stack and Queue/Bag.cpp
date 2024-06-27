#include<iostream>
using namespace std;
template<class T>
class Bag
{
private:
    T *array;
    int top , capacity;
public:
    Bag(int bagCapacity = 10);
    ~Bag() {delete [] array;}
    int Size() const {return top + 1;}
    bool IsEmpty() const {return top == -1;};
    T &Element() const {return array[top];};
    void ChangeSize1D(T*& a,const int oldSize,int newSize)
    {
        T *temp = new T [newSize];
        int number = min(oldSize,newSize);
        copy(a , a + number , temp);
        delete [] a;
        a = temp;
    }
    void Push(const T &);
    void Pop();
};

template<class T>
Bag<T>::Bag(int bagCapacity) : capacity(bagCapacity)
{
    array = new T [capacity];
    top = -1;
}

template<class T>
void Bag<T>::Push(const T& t)
{
    if(capacity - 1 == top) 
    {
        ChangeSize1D(array , capacity , capacity * 2);
        capacity *= 2;
    }
    array[++top] = t;
}

template<class T>
void Bag<T>::Pop(){if (top >= 0)   array[top--].~T();}

int main()
{
    Bag<char> charBag(10);
    charBag.Push('A');
    charBag.Push('C');
    charBag.Pop();
    cout << charBag.Element() << endl;
    charBag.Push('d');
    cout << charBag.Element() << endl;
    charBag.Push('b');
    charBag.Push('H');
    charBag.Push('G');
    cout << charBag.Element() << endl;
    charBag.Push('z');
    charBag.Push('y');
    charBag.Push('X');
    charBag.Push('p');
    charBag.Pop();
    cout << charBag.Element() << endl;
    charBag.Pop();
    charBag.Pop();
    cout << charBag.Element() << endl;
}


