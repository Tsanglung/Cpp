/*
建立一個時間（Time）類別，其資料成員與成員函數:
定義private資料成員hour、minute、second，分別存放時、分、秒。
定義建立者（constructor）函數，並設定所有資料成員的初值為0。
定義public成員函數set與get，用來設定與取得hour、minute、second值。
定義public成員函數addsec、addmin、addhr，增加hour、minute、second。
撰寫一個驅動程式顯示時間，每隔1秒(#include <Windows.h> ...   Sleep(1000);) 則second加1，每隔60秒則minute加1，每隔60分則hour加1。
*/
#include<iostream>
#include<windows.h>
using namespace std;
class Time{
private:
    int hour,minute,second;
public:
    Time(){hour = minute = second = 0;}
    void set(int h,int m,int s){hour = h; minute = m; second = s;}
    void get(){cout << hour << " : " << minute << " : " << second;};
    void addhr();
    void addmin();
    void addsec();
};

void Time::addhr(){
    if(hour >= 0 && hour < 24) {
        if(minute == 60){
            minute = 0;
            hour++;
        }
    }
    else hour = 0;
}

void Time::addmin(){
    if(minute >= 0 && minute < 60) {
        if(second == 60){
            second = 0;
            minute++;
        }
    }
    else minute = 0;
}

void Time::addsec(){
    if(second >= 0 && second < 60)  second++;
    else second = 0;
}

int main(){
    Time T;
    T.set(0,0,0);
    while(true){
        Sleep(1000);
        system("cls");
        T.addsec();
        T.addmin();
        T.addhr();
        T.get();
    }
}