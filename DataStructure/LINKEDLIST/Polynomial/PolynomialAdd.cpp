#include<iostream>
#include<algorithm>
using namespace std;
class Polynomial;
class Term {
    friend Polynomial;
private:
    float coef;//係數
    int exp;//次方項
};
class Polynomial {
private:
    Term* termArray;//非零項陣列
    int capacity;//陣列大小
    int terms;//非零項
public:
    Polynomial(int t = 0) {
        terms = t;//輸入的項
        capacity = terms + 1;//陣列大小
        termArray = new Term[capacity];//創建陣列
    }
    Polynomial Add(Polynomial b);
    void NewTerm(const float theCoeff, const int theExp);
    void Input() {//輸入
        int nPos = 0;//當前位置
        while (nPos < terms) {
            cin >> this->termArray[nPos].coef;
            cin >> this->termArray[nPos].exp;
            nPos++;
        }
    }
    void Output() {//輸出
        int nPos = 0;//當前位置
        while (nPos < terms) {
            cout << this->termArray[nPos].coef << this->termArray[nPos].exp << " ";
            nPos++;
        }
    }
};
void Polynomial::NewTerm(const float theCoeff, const int theExp)
{//建立一個新的陣列
    if (terms == capacity)
    {
        capacity *= 2;//空間預設為，兩個多項是沒有任何一樣的次方項，所以*2
        Term* temp = new Term[capacity];//建立新的陣列
        copy(termArray, termArray + terms, temp);//複製
        delete[] termArray;//解除記憶體分配
        termArray = temp;
    }
    termArray[terms].coef = theCoeff;
    termArray[terms++].exp = theExp;
}
Polynomial Polynomial::Add(Polynomial b)
{/*回傳多項式加總後的結果，*this 和 b.*/
    Polynomial c;/*建立c=a+b*/
    int aPos = 0, bPos = 0;/*現在的陣列位置*/
    while ((aPos < terms) && (bPos < b.terms))/*將a陣列與b陣列依序巡視*/
        if ((termArray[aPos].exp == b.termArray[bPos].exp)) {
            /*如果指數次方一樣，進行相加t=a係數+b係數*/
            float t = termArray[aPos].coef + b.termArray[bPos].coef;
            /*創建新的c陣列，並且依照次方數放入t值*/
            if (t)c.NewTerm(t, termArray[aPos].exp);
            aPos++; bPos++;
        }
        else if ((termArray[aPos].exp < b.termArray[bPos].exp)) {
            /*如果進行加法時，b的次方次方比a還大，將b直接存入c*/
            c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
            bPos++;
        }
        else {
            /*如果進行加法時，a的次方次方比b還大，將a直接存入c*/
            c.NewTerm(this->termArray[aPos].coef, termArray[aPos].exp);
            aPos++;
        }
    for (; aPos < terms; aPos++)/*若a的次方項沒有與b相同的，其餘直接放入c*/
        c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
    for (; bPos < b.terms; bPos++)/*若b的次方項沒有與a相同的，其餘直接放入c*/
        c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
    return c;
}
int main()
{
    int t;
    cin >> t;//輸入
    Polynomial a(t), b(t), c;
    a.Input();//依序輸入係數 次方
    b.Input();//依序輸入係數 次方
    c = a.Add(b);//c=a+b的答案
    cout << endl;
    c.Output();//輸出答案
    return 0;
}
