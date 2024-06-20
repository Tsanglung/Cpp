#include<bits/stdc++.h>
using namespace std;
int main(){
	int h1,h2,m1,m2;
	int m;
	while(cin>>h1>>m1>>h2>>m2){
		if(h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0) break;
		m = (h2 - h1) * 60 + (m2 - m1);
		if(m < 0) m += 24 * 60;
		cout<<m<<endl;
	}
}

