#ifndef _IOSTREAM_H
#include <iostream>
#include<vector>
#define _IOSTREAM_H
#endif
using namespace std;

class ThreadedTree;

class ThreadedNode {
friend class ThreadedTree;
friend class ThreadedInorderIterator;
private:
    bool LeftThread;
    ThreadedNode *LeftChild;
    char data;
    ThreadedNode *RightChild;
    bool RightThread;

    ThreadedNode() {LeftChild = RightChild = 0;};
    ThreadedNode(char ch) { data = ch;};
    ThreadedNode(char ch, ThreadedNode *lefty, ThreadedNode *righty,
		 bool lthread, bool rthread)
    { data = ch; LeftChild = lefty; RightChild = righty;
      LeftThread = lthread;  RightThread = rthread;};
};

class ThreadedTree {
friend class ThreadedInorderIterator;
private:
    ThreadedNode *root;
public:
    void setup();
    ThreadedTree() {
	root = new ThreadedNode;
	root->RightChild = root->LeftChild = root;
	root->LeftThread = true; root->RightThread = false;
    };
    void InsertRight(ThreadedNode*, char);
    ThreadedNode* InorderSucc(ThreadedNode*);
};

ThreadedNode* ThreadedTree::InorderSucc(ThreadedNode *current)
{
    ThreadedNode *temp = current->RightChild;
    if (! current->RightThread)
       while (! temp->LeftThread) temp = temp->LeftChild;
    return temp;
}


void ThreadedTree::InsertRight(ThreadedNode *s, char ch)
// Create node @r@; store @ch@ in @r@; insert @r@ as the right child of @s@
{
    ThreadedNode *r = new ThreadedNode(ch);
    r->RightChild = s->RightChild;
    r->RightThread = s->RightThread;
    r->LeftChild = s;
    r->LeftThread = true; // \fILeftChild\fR is a thread
    s->RightChild = r; // attach @r@ to @s@
    s->RightThread = false;
    if (! r->RightThread) {
	ThreadedNode *temp = InorderSucc(r); // returns the inorder successor of @r@
	temp->LeftChild = r;
    }
}

class ThreadedInorderIterator {
public:
   void Inorder();
   char *Next();
   ThreadedInorderIterator(ThreadedTree tree): t (tree) {
       CurrentNode = t.root;
   };
private:
   ThreadedTree t;
   ThreadedNode *CurrentNode;
};

char* ThreadedInorderIterator::Next()
// Find the inorder successor of \fICurrentNode\fR in a threaded binary tree
{
    ThreadedNode *temp = CurrentNode->RightChild;
    if (! CurrentNode->RightThread)
       while (! temp->LeftThread) temp = temp->LeftChild;
    CurrentNode = temp;
    if (CurrentNode == t.root) return 0; // all tree nodes have been traversed
    else return &CurrentNode->data;
}

void ThreadedInorderIterator::Inorder()
{
    for (char *ch = Next(); ch; ch = Next()) cout << *ch << endl;
}



void ThreadedTree::setup()
{
    ThreadedNode *A, *B, *C, *D, *E, *F, *G, *H, *I;

    root->LeftChild = A = new ThreadedNode('A', 0, 0, false, true);
    root->LeftThread = false;

    A->LeftChild = B = new ThreadedNode('B', 0, 0, false, false);
    A->RightChild = C = new ThreadedNode('C', 0, 0, false, false);

    B->LeftChild = D = new ThreadedNode('D', 0, 0, false, false);
    B->RightChild = E = new ThreadedNode('E', 0, 0, true, true);

    D->LeftChild = H = new ThreadedNode('H', 0, 0, true, true);
    D->RightChild = I = new ThreadedNode('I', 0, 0, true, true);

    C->LeftChild = F = new ThreadedNode('F', 0, 0, true, true);
    C->RightChild = G = new ThreadedNode('G', 0, 0, true, true);

    H->LeftChild = root; H->RightChild = D;
    I->LeftChild = D; I->RightChild = B;
    E->LeftChild = B; E->RightChild = A;
    F->LeftChild = A; F->RightChild = C;
    G->LeftChild = C; G->RightChild = root;

    InsertRight(A, 'X');
    InsertRight(E, 'Y');
}



int main()
{
    ThreadedTree t;
    t.setup();
    ThreadedInorderIterator ti(t);
    ti.Inorder();
}

