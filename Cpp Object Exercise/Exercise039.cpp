#include<iostream>
using namespace std;
//抽象類別的進位轉換
class DEC //10進位
{
protected:
	int data;
public:
	DEC() { data = 0; }
	void set_data(int value) { data = value; }
	virtual void Transform() = 0 ; //{ cout << "data in decimal is :" << dec << data << endl; }
	/*virtual void Transform() {//虛擬函數輸出進位轉換
		cout << "data in decimal is :" << dec << data << endl;
	}*/
	void print() { cout << "data in dec is" << data << endl; }
};
class OCT :public DEC
{//8進位
public:
	OCT() {}
	void Transform() {//虛擬函數輸出進位轉換
		cout << "data in oct is :" << oct << data << endl;
	}
};
class HEX :public DEC
{//16進位
public:
	HEX() {}
	void Transform() {//虛擬函數輸出進位轉換
		cout << "data in hec is :" << hex << data << endl;
	}
};
void show_data(DEC* data) {
	data->Transform();
}
int main()
{
	//DEC d; //十進位 d //抽象類別無法建立物件
	OCT o; //八進位物件 o
	HEX h; //十六進位物件 h
	int value;
	cout << "Enter an integer data:";
	cin >> value; //設輸入 100
	//d.set_data(value);
	o.set_data(value);
	h.set_data(value);
	//show_data(&d);//data in dec is 100
	show_data(&o);//輸出 "data in oct is 144"
	show_data(&h); //輸出"data in hex is 64"
	system("pause"); return 0;
}