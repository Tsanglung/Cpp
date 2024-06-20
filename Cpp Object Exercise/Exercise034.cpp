/*
進位轉換，多型
*/
#include<iostream>
using namespace std;
class DEC 
{
protected:
	int data;
public:
	DEC() { data = 0; }
	void set_data(int value){data=value;}
	virtual void Transform() {
		cout << "data in decimal is :" << dec << data << endl;
	}
};
class OCT :public DEC
{
public:
	OCT() {}
	virtual void Transform() {
		cout << "data in oct is :" << oct << data << endl;
	}
};
class HEX :public DEC
{
public:
	HEX(){}
	virtual void Transform() {
		cout << "data in hec is :" << hex << data << endl;
	}
};
void show_data(DEC *data){
	data->Transform();
}
int main()
{
	DEC d;  //十進位物件 d
	OCT o; //八進位物件 o
	HEX h; //十六進位物件 h
	int value;
	cout << "Enter an integer data:";
	cin >> value; //設輸入 100
	d.set_data(value);
	o.set_data(value);
	h.set_data(value);
	show_data(&d); //輸出 "data in decimal is 100" 
	show_data(&o);//輸出 "data in oct is 144"
	show_data(&h); //輸出"data in hex is 64"
	system("pause"); return 0;
}
