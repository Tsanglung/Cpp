#include<iostream>
using namespace std;

long long int subresult(long long int self, long long int enermy) {
	return abs(self - enermy);//相減取絕對值
}

int main() {
	long long int selfarmy, enermy;//自己人、敵軍
	while (cin >> selfarmy >> enermy && selfarmy &&enermy) {
		cout << subresult(selfarmy, enermy) << endl;
	}
}