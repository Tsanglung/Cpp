#include <bits/stdc++.h>
using namespace std;

int main() {
    int num;
    while(cin>>num){
        int sum = 0;
        if(num == 0) break;
        for(int i = 1;i <= num;i++)
            sum += pow(i,2);
        cout<<sum<<endl;
    }
    return 0;
}

