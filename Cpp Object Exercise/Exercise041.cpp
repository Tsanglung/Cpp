#include<iostream>
using namespace std;
// 氣泡排序法，使用樣板
template<class T1,class T2>
T1 bubbleSort(T1 number[], T2 length) 
{ 
	int i, j, flag = 1;
	for (i = 0; i < length - 1 && flag == 1; i++) 
	{ 
		flag = 0;
		for (j = 0; j < length - i - 1; j++) 
		{ 
			if (number[j + 1] < number[j]) 
			{ 
				T1 tmp = number[j];
				number[j] = number[j + 1];
				number[j + 1] = tmp;
				flag = 1; 
			} 
		} 
	} 
	return *number;
}
int main() 
{
	int IntNumber[5] = {56,87,99,78,31};
	float FloatNumber[5] = {1.38,5.17,0.99,8.87,5.55};
	bubbleSort<int, int>(IntNumber, 5) ;     // 整數氣泡排序法
	for(int i=0;i<5;i++)
		cout << IntNumber[i] << ' ';
	cout << endl;

	bubbleSort<float, int>(FloatNumber, 5) ;// 浮點數氣泡排序
	for (int i = 0; i < 5; i++) 
		cout << FloatNumber[i] << ' ';
	cout << endl;

	system("pause");
	return 0;
}
