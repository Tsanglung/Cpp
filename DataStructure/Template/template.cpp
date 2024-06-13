#include <iostream>
#include <algorithm>
using namespace std;
template <class T>
void ChangeSize1D(T*& a, const int oldSize, const int newSize)
{
	if (newSize < 0) throw "New length must be >= 0";//新陣列大小<0傳錯誤訊息
	T* temp = new T[newSize];//創建新的陣列
	int number = min(oldSize, newSize);//要copy的數量
	copy(a, a + number, temp);//將原陣列資料複製到temp
	delete[]a;//釋放舊記憶體空間
	a = temp;//指向新的陣列空間
}
int main() {
	int size, * a, num, times = 0;
	cin >> size;//輸入陣列大小
	a = new int[size];//創建新的陣列,大小為size
	cin >> num;//輸入資料數量
	for (int i = 0; i < num; i++)
	{
		if (i >= size)//如果資料滿了,則擴充空間
		{
			ChangeSize1D(a, size, 2 * size);
			times++;
			size *= 2;//參照課本program 3.5 Push程式碼
		}
		a[i] = i;
	}
	cout << times;//輸出呼叫changesize1D次數
}
