#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;

// 存儲最小heap節點的數據結構
struct PriorityQueue
{
private:
    // 用於存儲heap元素的vector
    vector<int> A;

    // 返回 A[i] 的父節點
    // 如果 i 已經是根節點，則不要調用此函數
    int PARENT(int i) {
        return (i - 1) / 2;
    }

    // 返回 A[i] 的左子節點
    int LEFT(int i) {
        return (2 * i + 1);
    }

    // 返回 A[i] 的右子節點
    int RIGHT(int i) {
        return (2 * i + 2);
    }

    // 遞迴的 heapify-down 算法。
    // 索引 i 處的節點及其兩個直接子節點
    // 違反heap屬性
    void heapify_down(int i)
    {
        // 在索引 i 處獲取節點的左右子節點
        int left = LEFT(i);
        int right = RIGHT(i);

        int smallest = i;

        // 比較 A[i] 和它的左右子節點，並找到最小值
        if (left < size() && A[left] < A[i]) {
            smallest = left;
        }

        if (right < size() && A[right] < A[smallest]) {
            smallest = right;
        }

        // 與價值較小的孩子交換
        // 在子節點上調用 heapify-down
        if (smallest != i)
        {
            swap(A[i], A[smallest]);
            heapify_down(smallest);
        }
    }

    // 遞歸的 heapify-up 算法
    void heapify_up(int i)
    {
        // 檢查索引 i 處的節點及其父節點是否違反堆屬性
        if (i && A[PARENT(i)] > A[i])
        {
            // 如果違反了heap屬性，則交換兩者
            swap(A[i], A[PARENT(i)]);

            // 在父節點上調用 heapify-up
            heapify_up(PARENT(i));
        }
    }

public:
    // 返回heap的大小
    unsigned int size() {
        return A.size();
    }

    // 檢查heap是否為空的函數
    bool empty() {
        return size() == 0;
    }

    // 向堆中插入key
    void push(int key)
    {
        // 在vector末尾插入一個新元素
        A.push_back(key);

        // 獲取元素索引並調用 heapify-up 過程
        int index = size() - 1;
        heapify_up(index);
    }

    // 刪除優先級最低的元素(存在於根)的函數
    void pop()
    {
        try {
            // 如果堆中沒有元素，則拋出異常
            if (size() == 0)
            {
                throw out_of_range("Vector<X>::at() : "
                    "index is out of range(Heap underflow)");
            }

            // 用最後一個元素替換堆的根
            // vector的
            A[0] = A.back();
            A.pop_back();

            // 在根節點上調用 heapify-down
            heapify_down(0);
        }
        // 捕獲並打印異常
        catch (const out_of_range& oor) {
            cout << endl << oor.what();
        }
    }

    // 函數返回具有最低優先級的元素(存在於根)
    int top()
    {
        try {
            // 如果堆中沒有元素，則拋出異常
            if (size() == 0)
            {
                throw out_of_range("Vector<X>::at() : "
                    "index is out of range(Heap underflow)");
            }

            // 否則，返回頂部(第一個)元素
            return A.at(0);        // 或返 return A[0];
        }
        // 捕獲並打印異常
        catch (const out_of_range& oor) {
            cout << endl << oor.what();
        }
    }
};

// C++ 中的最小堆實現
int main()
{
    PriorityQueue pq;

    // 元素的值決定優先級
    int x;
    for (int i = 0; i < 5; i++) { //輸入heap元素
        cin >> x;
        pq.push(x);//push
    }

    int heap_size = pq.size();//heap的大小

    for (int i = 0; i < heap_size; i++) {
        cout << pq.top() << " ";//輸出最上層最小值
        pq.pop();//pop
    }

    cout << endl << boolalpha<< "vector is empty?" << pq.empty();

    pq.top();    // 空堆上的頂部操作
    pq.pop();    // 空堆上的彈出操作

    return 0;
}
