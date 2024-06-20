#include<iostream>
using namespace std;
int main() {
	int counter;
	cin >> counter;
	while (counter--) {
		int A, B;//Aㄢ钉だ计Bㄢ钉だ计
		int ansA, ansB;//ㄢ钉だ计
		cin >> A >> B;
		ansA = (A + B) / 2;
		ansB = A - ansA;
		//璝だ计搭だ计"┪"だ计籔搭だ计ぃ琌2计玥块"ぃ"
		if (A < B || ((A + B) % 2 != 0)) { cout << "impossible" << endl; }
		else { cout << ansA << " " << ansB << endl; }
	}

}