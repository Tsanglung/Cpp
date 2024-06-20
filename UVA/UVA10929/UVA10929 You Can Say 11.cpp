#include<iostream>
#include<string>
using namespace std;

int main() {
	string num;
	while (getline(cin,num)) {
		int i;
		int len = num.size();
		if (len == 1 && num[0] == '0')break;//块0玥挡
		int odd = 0, even = 0;
		for (i = 0; i < len; i++) {
			if (i % 2 == 0) {
				odd += (num[i] - '0');//盢﹃锣计
			}
			else even += (num[i] - '0');//盢﹃锣计
		}
		if ((odd - even) % 11 == 0) { //(num计羆㎝-案计羆㎝/11)单011计
			cout << num << " is a multiple of 11." << endl;
		}
		else cout << num << " is not a multiple of 11." << endl;
	}
}
