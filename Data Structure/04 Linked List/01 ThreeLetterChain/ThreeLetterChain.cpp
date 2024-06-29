#include<iostream>
using namespace std;
class ThreeLetterChain;
class ThreeLetterNode
{
    friend class ThreeLetterChain;
    private:
        string data[3];
        ThreeLetterNode *link;
};

class ThreeLetterChain
{
    private:
        ThreeLetterNode *first;
    public:
        ThreeLetterChain():first(nullptr){}
        void test();
        void Output();
};

void ThreeLetterChain::test()
{
    ThreeLetterNode *f = new ThreeLetterNode;
    f->data[0] = "BAT";
    f->data[1] = "CAT";
    f->data[2] = "WAT";
    f->link = 0;
    f->link = nullptr;
    first = f;
}

void ThreeLetterChain::Output()
{
    ThreeLetterNode *current = first;
    while (current != nullptr) 
    {
        for (int i = 0; i < 3; i++)
            cout << current->data[i] << endl;
        current = current->link;
    }
}

int main()
{
    ThreeLetterChain l;
    l.test();
    l.Output();
}