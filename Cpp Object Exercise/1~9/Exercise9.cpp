/*
撰寫一C++程式，由鍵盤輸入一個字串，於該字串裡尋找是否包含"the"，
若是有，請印出"the" 在字串中出現的位置。
*/
#include <iostream>
#include <cstdlib>
#include <string> 
using namespace std;
int main()
{
    string English,FindWord="the";
    int index = 0;
    getline(cin, English);
    while ((index = English.find(FindWord, index)) >= 0 && (index < English.length() ))
    {
        cout << index << endl;
        index++;
    }
    return 0;
}