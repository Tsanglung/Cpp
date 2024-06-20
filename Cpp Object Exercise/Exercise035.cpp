#include<iostream>
using namespace std;
//多型(虛擬函數達成動態連結2)
class CBox               // Base class
{
public:
    // Function to show the volume of an object
// Function to calculate the volume of a CBox object
    virtual double Volume()
    {
        return m_Length * m_Breadth * m_Height;
    }
    // Constructor
    CBox(double lv = 1.0, double bv = 1.0, double hv = 1.0) :m_Length(lv), m_Breadth(bv), m_Height(hv) {}
protected:
    double m_Length;
    double m_Breadth;
    double m_Height;
};
class CGlassBox : public CBox       // Derived class
{
public:
    // Function to calculate volume of a CGlassBox
    // allowing 15% for packing
    virtual double Volume()
    {
        return 0.85 * m_Length * m_Breadth * m_Height;
    }
    // Constructor
    CGlassBox(double lv, double bv, double hv) : CBox(lv, bv, hv) {}
};
void test(CBox& test_box) {
    cout << test_box.Volume() << endl;//多型, 同名異式
}
int main()
{
    CBox myBox(2.0, 3.0, 4.0);              // Declare a base box
    CGlassBox myGlassBox(2.0, 3.0, 4.0);    // Declare derived box - same size

    test(myBox);                     // Display volume of base box
    test(myGlassBox);                // Display volume of derived box

    cout << endl;
    system("pause"); return 0;
}
