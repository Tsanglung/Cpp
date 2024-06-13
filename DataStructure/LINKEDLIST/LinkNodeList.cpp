#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;
struct Term {/*p.203*/
	int coef = 0;
	int exp = -1;
	Term set(int c, int e) { coef = c; exp = e; return *this; };
};
template<class T>
class LinkList;
template<class T>
class LinkNode {
	friend LinkList<T>;
private:
	T data;
	LinkNode<T>* next;
public:
	LinkNode(const T& _data = T(), LinkNode<T>* _next = NULL) {
		data = _data;
		next = _next;
	}
};
template<class T>
class LinkList {
private:
	LinkNode<T>* head;
public:
	LinkList() {
		head = new LinkNode<T>(T());
		head->next = head;
	}
	void InsertFront(const T& _data) {/*p.196*/
		LinkNode<T>* newNode = new LinkNode<T>(_data);
		LinkNode<T>* last = head;
		if (last) {
			newNode->next = last->next;
			last->next = newNode;
		}
		else {
			last = newNode;
			newNode->next = newNode;
		}
	}
};
int main() {
	LinkList<Term> Polya;
	Term temp;
	for (int n = 3; n > 0; n--) {
		Polya.InsertFront(temp.set(n + 2, n + 1));
	}
}
