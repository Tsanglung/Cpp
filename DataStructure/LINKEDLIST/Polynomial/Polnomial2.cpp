#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
class LinkedList;
class ListNode
{
	friend LinkedList;
private:
	int Coef, Exp;		//儲存常數&幾次方
	ListNode* next;		//下一個node
public:
	ListNode() { Coef = Exp = 0; next = 0; };  //空節點
	ListNode(int c, int x) {			     //只有資料的node
		Coef = c; //常數
		Exp = x;  //幾次方
		next = 0;
	};
	void setNode(int c, int x, ListNode* next) { //設定node內的資料
		Coef = c;
		Exp = x;
		this->next = next;
	}
	ListNode* nextnode(ListNode* now) {		//存到下一個node
		return now->next;
	}
	int getCoef() {		//傳回係數
		return Coef;
	}
	int getExp() {		//傳回次方
		return Exp;
	}
};
class LinkedList {		//儲存空間設定
private:
	ListNode* head;		//headnode
	static ListNode* LIst;	//可用串列
public:
	LinkedList() {			//預設空串列
		head = new ListNode();
		head->next = head;
	};
	~LinkedList() {	//解構子，將headnode以外的node移到可用串列中
		if (head != NULL) {
			ListNode* current = head;
			while (current->next != head)
				current = current->next;
			current = LIst;
			LIst = head->next;
			head = NULL;
		}
	}
	bool Isempty() {		//判斷串列是否為空
		return head == head->next;
	}
	ListNode* begin() const {	//回傳指標位址
		return head->next;
	}
	ListNode* end() const {		//回傳headnode的node
		return head;
	}
	ListNode* getNode() {	//從可用串列取得node，可用串列為空就建立新node
		ListNode* ret;
		if (LIst == NULL) {
			ret = new ListNode();
		}
		else {
			ret = LIst;
			LIst = LIst->next;
		}
		return ret;
	}
	void Push_back(int c, int x) {			//在串列尾插入資料
		ListNode* newNode = getNode();
		newNode->setNode(c, x, head);
		if (head->next == head) {			//空串列
			head->next = newNode;
			return;
		}
		ListNode* current = head->next;
		while (current->next != head) {		//找到原本的串列尾
			current = current->next;
		}
		current->next = newNode;
	}
	void Pop_back() {		//將最後一個串列放到可用串列
		ListNode* beforeNode = head, * current = head;
		while (beforeNode->next->next != head) {
			beforeNode = beforeNode->next;
		}
		beforeNode->next->next = LIst;
		LIst = beforeNode->next;
		beforeNode->next = head;
	}
	void clear() {			//清空所有
		while (!Isempty())
			Pop_back();
	}
};
ListNode* LinkedList::LIst = NULL;  //初始可用串列
class Polynomial {		//多項式
private:
	LinkedList Poly;
public:
	Polynomial() {}
	friend istream& operator>>(istream& is, Polynomial& t);
	friend ostream& operator<<(ostream& os, Polynomial& t);
	Polynomial(const Polynomial& a) {	//複製建構子
		Poly.clear();	//清空原有資料
		Poly = a.Poly;
	}
	~Polynomial() {	//解構子
		Poly.~LinkedList();
	}
	Polynomial& operator=(const Polynomial& a) {	//多載=運算子
		Poly = a.Poly;
		return *this;
	}
	Polynomial operator+(const Polynomial& b) const {
		ListNode* ai = Poly.begin(), * bi = b.Poly.begin();	//分別指向兩個多項式的頭
		Polynomial ret;		//儲存結果
		while (ai != Poly.end() && bi != b.Poly.end()) {	//有一邊到結尾就停止
			if (ai->getExp() == bi->getExp()) {			//次方項相等時
				int sum = ai->getCoef() + bi->getCoef();
				if (sum != 0) {			//相加不為0才存入
					ret.Poly.Push_back(sum, ai->getExp());
				}
				ai = ai->nextnode(ai);	bi = bi->nextnode(bi);
				continue;
			}
			else if (ai->getExp() > bi->getExp()) {	//左邊次方大於右邊次方
				ret.Poly.Push_back(ai->getCoef(), ai->getExp());
				ai = ai->nextnode(ai);
				continue;
			}
			else {	//左邊次方小於右邊次方
				ret.Poly.Push_back(bi->getCoef(), bi->getExp());
				bi = bi->nextnode(bi);
			}
		}
		while (ai != Poly.end()) {	//處理左邊剩下的項目
			ret.Poly.Push_back(ai->getCoef(), ai->getExp());
			ai = ai->nextnode(ai);
		}
		while (bi != b.Poly.end()) {//處理右邊剩下的項目
			ret.Poly.Push_back(bi->getCoef(), bi->getExp());
			bi = bi->nextnode(bi);
		}
		return ret;  //回傳結果
	}
	Polynomial operator-(const Polynomial& b) const {
		ListNode* ai = Poly.begin(), * bi = b.Poly.begin();	//分別指向兩個多項式的最前端
		Polynomial ret;		//儲存結果
		while (ai != Poly.end() && bi != b.Poly.end()) {	//有一邊到最後就停止
			if (ai->getExp() == bi->getExp()) {	//次方項相等時
				int diff = ai->getCoef() - bi->getCoef();
				if (diff != 0) {	//相減不為0才存入
					ret.Poly.Push_back(diff, ai->getExp());
				}
				ai = ai->nextnode(ai);	bi = bi->nextnode(bi);
				continue;
			}
			else if (ai->getExp() > bi->getExp()) {	     //左邊次方大於右邊次方
				ret.Poly.Push_back(ai->getCoef(), ai->getExp());
				ai = ai->nextnode(ai);
				continue;
			}
			else {									//左邊次方小於右邊次方
				if (bi->getCoef() > 0)				//右邊係數如果為正數就加負號
					ret.Poly.Push_back(-(bi->getCoef()), bi->getExp());
				else
					ret.Poly.Push_back(bi->getCoef(), bi->getExp());
				bi = bi->nextnode(bi);
			}
		}
		while (ai != Poly.end()) {	//處理左邊剩下的項目
			ret.Poly.Push_back(ai->getCoef(), ai->getExp());
			ai = ai->nextnode(ai);
		}
		while (bi != b.Poly.end()) {	//處理右邊剩下的項目
			if (bi->getCoef() > 0)
				ret.Poly.Push_back(-(bi->getCoef()), bi->getExp());//右邊係數如果為正數就加負號
			else
				ret.Poly.Push_back(bi->getCoef(), bi->getExp());
			bi = bi->nextnode(bi);
		}
		return ret;
	}
	float evaluate(const float& x) const {	//代入x計算結果
		float ret = 0;
		ListNode* current = Poly.begin();
		for (; current != Poly.end(); current = current->nextnode(current)) {
			ret += current->getCoef() * pow(x, current->getExp());
		}
		return ret;
	}
};
istream& operator>>(istream& is, Polynomial& t) {	//多載>>運算子
	cout << "共有幾項 ";
	int n;
	is >> n;
	cout << "先輸入係數再輸入次方且用空格隔開，次方由大→小" << endl;
	for (n; n != 0; n--) {
		int Coef, Exp;
		is >> Coef >> Exp;
		t.Poly.Push_back(Coef, Exp);
	}
	return is;
}
ostream& operator<<(ostream& os, Polynomial& t) {	//多載<<運算子
	ListNode* current = t.Poly.begin();
	if (t.Poly.Isempty()) {	//串列為空輸出0
		cout << 0;
		return os;
	}

	cout << current->getCoef() << "X^" << current->getExp();	//第一項不用印出"+"
	current = current->nextnode(current);
	for (; current != t.Poly.end(); ) {

		if (current->getExp() != 0) {	//不為0次方時
			cout << "+" << current->getCoef() << "X^" << current->getExp();
		}
		else {	//常數項次方為0，印出常數即可
			cout << "+" << current->getCoef();
		}
		current = current->nextnode(current);
	}
	return os;
}
int main() { //主程式(呼叫用)
	Polynomial Pa, Pb, Pc;
	cout << "輸入第一個多項式" << endl;
	cin >> Pa;
	cout << "Pa= " << Pa << endl;
	cout << "輸入第二個多項式" << endl;
	cin >> Pb;
	cout << "Pb= " << Pb << endl;
	cout << "--------------------------" << endl;
	Pc = Pa + Pb;
	cout << "Pa + Pb = " << Pc << endl;
	system("pause");
}
