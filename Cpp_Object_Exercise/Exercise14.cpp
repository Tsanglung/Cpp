//車價由輪子,車架成本構成, 再加上每台車組裝成本500元,  首先運用繼承概念設計輪子(Wheel)及車架(Frame)等組件(Component)
//並利用static variable count紀錄已組合的小摺總數, 
#include <iostream>
#include <string>
using namespace std;
class Component {
protected:	
    string id;	double cost;
public:	
    Component(){}
    Component(const string n, double cost) 
    {
        cout << "call Component(string n, double cost)" << endl;  
        id = n; this->cost = cost; 
    }
    double getcost() { return cost; }
};
class Frame : public Component
{
public:	
    Frame(const string n, string t, double c) //完成後面程式碼
    {
        id = n;
        type = t;
        cost = c;
    }
private:          
    string type;
};

class Wheel : public Component
{
public:	
    Wheel(const string n, int s, double c) //完成後面程式碼
    {
        id = n;
        size = s;
        cost = c;
    }
private: 
    int size;
};
class Bicycle
{
public: 
      static int count;
      Bicycle(Wheel w1, Frame f1) :w(w1), f(f1) { count++; }
      void changeWheel(Wheel w2) { w = w2; }
      void changeFrame(Frame f2) { f = f2; }
      double getcost()  //完成後面程式碼
      { 
          return w.getcost() + f.getcost() + 500; 
      }
private: 
      Wheel w; Frame f;
};
int Bicycle::count = 0;//紀錄已組合的小摺總數
int main()
{
    //輪子有兩種選擇,注意輪子皆是成雙,如w1即包含前後兩輪子
    Wheel w1("16吋", 16, 2000);
    Wheel w2("20吋", 20, 3000);
    //車架有三種選擇
    Frame f1("Giant", "iron", 2000);
    Frame f2("Merida", "iron", 3000);
    Frame f3("Argon 18", "alloy", 5000);
    //組合第一台,輪子為16吋,車架為a牌經濟型的小摺
    Bicycle b1(w1, f1);
    cout << "第一台價格為:" << b1.getcost() << endl;
    //組合第二台,輪子為20吋,車架為a牌經濟型的小摺
    Bicycle b2(w2, f1);
    cout << "第二台價格為:" << b2.getcost() << endl;
    //第一台換成20吋的輪子, 並列印出更換後的車子價格
    b1.changeWheel(w2); cout << "第一台換輪子後的價格為:" << b1.getcost() << endl;
    //列印目前售出的小摺總數
    cout << "目前總共組了:" << Bicycle::count << "台小摺\n";
    system("pause");
    return 0;
}
