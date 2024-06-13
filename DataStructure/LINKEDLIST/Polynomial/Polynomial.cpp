#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;
struct Term{	//儲存多項式每項的係數與次方值
	int coef = 0, exp = -1;
	Term set(const int& c, const int& e) {
		coef = c; exp = e;
		return *this;
	}
};
template<class T>
class LinkList;
template<class T>
class LinkNode {
	friend LinkList<T>;
private:
	T data;	//資料
	LinkNode<T>* next,*pre; //下一個節點位置 , 前一個節點位置
public:
	LinkNode(const T& _data = T(), LinkNode<T>* _next = NULL, LinkNode<T>* _pre = NULL) {
		data = _data;
		next = _next;
		pre = _pre;
	}
	void setNode(const T& _data, LinkNode<T>* _next = NULL, LinkNode<T>* _pre = NULL) {
		data = _data;
		next = _next;
		pre = _pre;
	}
};
template<class T>
class LinkList {
private:
	LinkNode<T> *root;	//串列的根
	static LinkNode<T>* av;	//串列中的可用串列的頭
public:
	class iterator {	//迭代器
	private:
		LinkNode<T>* current;
	public:
		iterator(LinkNode<T>* n = NULL) {
			current = n;
		}
		iterator& operator++() {
			current = current->next;
			return *this;
		}
		iterator operator++(int) {
			iterator temp = *this;
			++* this;
			return temp;
		}
		const T& operator*() const {
			return current->data;
		}
		const T* operator->() const {
			return &(current->data);
		}
		bool operator==(const iterator& a) const {
			return current == a.current;
		}
		bool operator!=(const iterator& a) const {
			return current != a.current;
		}
	};
	LinkList() {	//預設建構子
		root = new LinkNode<T>(T());
		root->next = root;
		root->pre = root;
	}
	LinkList(const LinkList<T>& a) {	//複製建構子
		iterator iter;
		for (iter = a.begin(); iter != a.end(); iter++) {
			pushBack(*iter);
		}
	}
	~LinkList() {	//解構子，將除了根以外的NODE都移到可用串列中
		if (root) {	
			root->pre->next = av;
			av = root->next;
			root = NULL;
		}
	}
	bool isEmpty() {	//回傳串列是否為空
		return root == root->next;
	}
	iterator begin() const {	//傳回串列開頭的迭代器
		return iterator(root->next);
	}
	iterator end() const {		//傳回串列結尾的下一個(根)的迭代器
		return iterator(root);
	}
	void pushBack(const T& _data) {	//在根的前一個放資料
		LinkNode<T>* temp = getNode();
		temp->setNode(_data, root, root->pre);
		temp->next->pre = temp;
		temp->pre->next = temp;
	}
	void popBack() {	//將根的前一個節點移到可用串列
		LinkNode<T>* deleteNode = root->pre;
		deleteNode->pre->next = root;
		root->pre = deleteNode->pre;
		deleteNode->next = av;
		av = deleteNode;
	}
	const LinkList<T>& operator=(const LinkList<T>& a) {	//多載=運算子
		clear();	//先將=左邊的串列清空
		iterator iter;
		for (iter = a.begin(); iter != a.end(); iter++) {
			pushBack(*iter);
		}
		return *this;
	}
	LinkNode<T>* getNode() {	//從可用串列中拿節點，可用串列為空就建立新節點
		LinkNode<T>* ret;
		if (av == NULL) {
			ret = new LinkNode<T>();
		}
		else {
			ret = av;
			av = av->next;
		}
		return ret;
	}
	void clear() {	//清空串列中除了根以外的節點
		while (!isEmpty()) {
			popBack();
		}
	}
};
template<class T>
LinkNode<T>* LinkList<T>::av = NULL;	//靜態函數的初始值

class Polynomial {	//多項式
private:
	LinkList<Term> poly;
public:
	Polynomial() {}	//預設建構子
	Polynomial(const Polynomial& a) {	//複製建構子
		poly.clear();	//先將要複製到的清空
		poly = a.poly;
	}
	~Polynomial() {	//解構子
		poly.~LinkList();
	}
	friend istream& operator>>(istream& is, Polynomial& t);
	friend ostream& operator<<(ostream& os, Polynomial& t);
	const Polynomial& operator=(const Polynomial& b){	//多載=運算子
		poly.clear();	//先將=左邊的清空
		poly = b.poly;
		return *this;
	}
	Polynomial operator+(const Polynomial& b) const {	//多載加法運算子
		Term term;	//為了使用set
		Polynomial ret;	//儲存計算結果
		LinkList<Term>::iterator aiter, biter;	//+號 左邊的迭代器, 右邊的迭代器
		aiter = poly.begin(); biter = b.poly.begin();
		while (aiter != poly.end() || biter != b.poly.end()) {	//兩個都還沒有到結尾時
			if (aiter->exp == biter->exp) {	//兩個次方項相等時
				if (aiter->coef + biter->coef) {	//相加不等於0時
					ret.poly.pushBack(term.set(aiter->coef + biter->coef, aiter->exp));
				}
				aiter++; biter++;
			}
			else if (aiter->exp > biter->exp) {	//+號左邊的次方向大於右邊的次方項
				ret.poly.pushBack(term.set(aiter->coef, aiter->exp));
				aiter++;
			}
			else {	//+號左邊的次方向小於右邊的次方項
				ret.poly.pushBack(term.set(biter->coef, biter->exp));
				biter++;
			}
		}
		return ret;
	}
	Polynomial operator-(const Polynomial& b) const {	//多載減法運算子，跟多載加法運算子 95%一樣
		Term term;
		Polynomial ret;
		LinkList<Term>::iterator aiter, biter;
		aiter = poly.begin(); biter = b.poly.begin();
		while (aiter != poly.end() || biter != b.poly.end()) {
			if (aiter->exp == biter->exp) {
				if (aiter->coef - biter->coef) {	//相減不為0時
					ret.poly.pushBack(term.set(aiter->coef - biter->coef, aiter->exp));
				}
				aiter++; biter++;
			}
			else if (aiter->exp > biter->exp) {
				ret.poly.pushBack(term.set(aiter->coef, aiter->exp));
				aiter++;
			}
			else {
				ret.poly.pushBack(term.set(-biter->coef, biter->exp));
				biter++;
			}
		}
		return ret;
	}
	Polynomial operator*(const Polynomial& b) const {	//多載乘法運算子
		Term term;
		Polynomial ret, temp;	//回傳, 每次計算完暫時儲存
		LinkList<Term>::iterator aiter, biter;
		for(aiter = poly.begin();aiter != poly.end(); aiter++){	//乘法就是很多次的加法
			for (biter = b.poly.begin(); biter != b.poly.end(); biter++) {
				temp.poly.pushBack(term.set(aiter->coef * biter->coef, aiter->exp + biter->exp));
			}
			ret = ret + temp;
			temp.poly.clear();	//暫時串列清空
		}
		return ret;
	}
	float evaluate(const float& x) const {	//計算x代入某數的值
		float ret = 0;
		LinkList<Term>::iterator iter;
		for (iter = poly.begin(); iter != poly.end(); iter++) {
			ret += iter->coef * pow(x, iter->exp);
		}
		return ret;
	}
};

istream& operator>>(istream& is, Polynomial& t) {	//多載>>運算子
	cout << "請輸入有幾項 ";
	int n;
	is >> n;
	cout << "請由次方大輸入到次方小，先輸入係數再輸入次方並用空格隔開" << endl;
	Term temp;
	while (n--) {
		int coef, exp;
		is >> coef >> exp;
		t.poly.pushBack(temp.set(coef, exp));
	}
	return is;
}

ostream& operator<<(ostream& os, Polynomial& t) {	//多載<<運算子
	LinkList<Term>::iterator iter = t.poly.begin();
	if (t.poly.isEmpty()) {	//串列為空時
		cout << 0;
		return os;
	}
	printf("%dx^%d", iter->coef, iter->exp);	//第一項不用輸出+號
	for (iter++; iter != t.poly.end(); ++iter) {
		if (iter->exp != 0) {	//不為常數項時
			printf("%+dx^%d", iter->coef, iter->exp);
		}
		else {	//常數項
			printf("%+d", iter->coef);
		}
	}
	return os;
}

int main() {
	Polynomial polya, polyb, polyc;
	cin >> polya;
	cout << polya << endl;
	cin >> polyb;
	cout << polyb << endl;
	polyc = polya + polyb;
	cout << "polya + polyb = " << polyc << endl;
	polyc = polya - polyb;
	cout << "polya - polyb = " << polyc << endl;
	polyc = polya * polyb;
	cout << "polya * polyb = " << polyc << endl;
	cout << "請輸入X的數值 ";
	float x;
	cin >> x;
	cout << "x = " << x << " 代入 " << polya << " = " << polya.evaluate(x) << endl;
	cout << "x = " << x << " 代入 " << polyb << " = " << polyb.evaluate(x) << endl;
}
