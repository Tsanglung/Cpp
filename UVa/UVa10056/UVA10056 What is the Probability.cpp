#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
int main() {
	int TestData; //測資
	cin >> TestData;
	int Players;//玩家數量
	int Nplayer;//第N個玩家
	double Probability;//勝率
	while (TestData--) {
		cin >> Players >> Probability >> Nplayer;
		double NowProbablity = 1;//當前勝率
		double AnsProbablity = 0;//最後結果勝率
		int Round = 0;//回合數
		do {
			NowProbablity = pow(1 - Probability, Round * Players) *
				pow((1 - Probability), Nplayer - 1) * Probability;
			//pow(1 - Probability, Round* Players)是玩到第Round + 1輪的機率
			//pow((1- Probability),Nplayer - 1)是該輪前面的人輸的機率
			//Probability 是自己勝率的機率
			AnsProbablity += NowProbablity;
			Round++;
		} while (NowProbablity > 0.000000000000001);
		cout << fixed << setprecision(4) << AnsProbablity << endl;//取到小數後四位
	}
}



