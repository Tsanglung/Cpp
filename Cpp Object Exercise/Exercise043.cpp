//µêÀÀÄ~©Ó
#include<iostream>
using namespace std;
class shape
{
protected:	
	double weight;
public: 
	void setweight(double w) { weight = w; }
};
class bed : virtual public shape
{
public:	
	void sleep() { cout << "sleep\n"; }
};

class sofa : virtual public shape
{
public:	
	void watchtv() { cout << "watch TV\n"; }
};

class sleepersofa : public bed, public sofa
{
public:	
	void fold() { cout << "fold out the sleepersofa\n"; }
	void getweight() { cout << weight << endl; }
};
int main()
{
	sleepersofa ss;
	ss.sleep();
	ss.fold();
	ss.watchtv();
	ss.setweight(3);
	ss.getweight();
	system("pause"); return 0;
}
