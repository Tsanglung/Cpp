#include<iostream>
#include<climits>
#include<algorithm>
#include<list>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class Graph {
protected:
	int n, e;	//目前點的數量，邊的數量
public:
	bool isEmpty() const {
		return n == 0;
	}
	int numberOfVertices() const {
		return n;
	}
	int numberOfEdges() const {
		return e;
	}
	virtual void insertVertex(int v) = 0;
	virtual void insertEdge(int u, int v,int w) = 0;
	virtual int Degree(int u) const = 0;
	virtual bool existsEdge(int u, int v) const = 0;
	virtual void deleteVertex(int v) = 0;
	virtual void deleteEdge(int u, int v) = 0;
};	
class LinkedWDirectGraph :public Graph {	//有權重有向圖
protected:
	vector<list<pair<int,int>>> vertices;	//紀錄點與此點所連結的點和權重。串列為連結的點，儲存的pair為點與權重
	bool *visit;	//後續演算法需要的是否拜訪過變數
	vector<int>* dfn, *low;	//biconnected需要的變數
	int num;	//biconnected要計算DFN與LOW的變數
	stack<pair<int, pair<int, int>>> s;	//biconnected需要的堆疊
public:
	LinkedWDirectGraph(int v = 1) {	//建構子
		e = 0;
		n = v;
		vertices.resize(v, list<pair<int, int>>());
	}
	LinkedWDirectGraph(LinkedWDirectGraph& l) {	//複製建構子
		e = l.e;
		n = l.n;
		vertices.resize(l.n, list<pair<int, int>>());
		for (int i = 0; i < l.n; i++) {
			list<pair<int, int>>::iterator iter = l.vertices[i].begin();
			for (; iter != l.vertices[i].end(); iter++) {
				this->vertices[i].push_back(*iter);
			}
		}
	}
	void insertVertex(int v) {	//新增點
		if (v > vertices.size()) {	//因為還沒想到要怎樣改，所以新增的點大於目前的最大點就擴大到那樣
			vertices.resize(v, list<pair<int, int>>());
			n = v;
		}
	}
	void insertEdge(pair<int, pair<int, int>> edge) {	//新增邊。第一個pair的first代表起點
		pair<int, int> temp = edge.second;				//將edge的second存起來，temp的first代表終點，scond代表權重
		if (find(vertices[edge.first].begin(), vertices[edge.first].end(), temp) == vertices[edge.first].end()) {	//此點是否連接過了
			vertices[edge.first].push_back(temp);	//還沒的話增加
			e++;
		}
	}
	void insertEdge(int u, int v, int w = 1) {	//新增邊。起點。終點。權重預設1
		pair<int, int> temp(v, w);
		if (find(vertices[u].begin(), vertices[u].end(), temp) == vertices[u].end()) {
			vertices[u].push_back(temp);
			e++;
		}
	}
	int Degree(int u) const {	//目標點的Degree
		return vertices[u].size();
	}
	bool existsEdge(int u, int v) const {	//在兩點中是否存在邊
		list<pair<int, int>>::const_iterator iter = vertices[u].begin();
		for (; iter != vertices[u].end();iter++) {
			pair<int, int> temp = *iter;
			if (temp.first == v) {
				return true;
			}
		}
		return false;
	}
	void deleteVertex(int v) {	//刪除點
		vertices[v] = list<pair<int, int>>();	//將此點所連結的邊刪除
		for (int i = 0; i < n; i++) {	//將其他友連結此點的邊刪除
			list<pair<int, int>>::iterator iter = vertices[i].begin();
			for (; iter != vertices[i].end(); iter++) {
				pair<int, int> temp = *iter;
				if (temp.first == v) {
					iter = vertices[i].erase(iter);
				}
			}
		}
		n--;
	}
	void deleteEdge(int u, int v) {
		list<pair<int, int>>::iterator iter = vertices[u].begin();
		for (; iter != vertices[u].end(); iter++) {
			pair<int, int> temp = *iter;
			if (temp.first == v) {
				vertices[u].remove(*iter);
				e--;
				break;
			}
		}
	}
	void DFS() {	//DFS驅動
		visit = new bool[n];	//紀錄是否拜訪過
		fill(visit, visit + n, false);	//初始化visit
		cout << "DFS: ";
		DFS(0);	//以0為起點
		cout << "\n--------------------" << endl;
		delete[] visit;
	}
	void BFS(int v) {
		queue<int> q;	//紀錄還有哪些點要跑
		visit = new bool[n];	//紀錄是否拜訪過
		fill(visit, visit + n, false);
		cout << "BFS: ";
		q.push(v);
		visit[v] = true;
		while (!q.empty()) {
			v = q.front();
			q.pop();
			list<pair<int,int>>::iterator iter = vertices[v].begin();
			for (; iter != vertices[v].end(); iter++) {
				pair<int, int> temp = *iter;
				if (!visit[temp.first]) {
					q.push(temp.first);
					visit[temp.first] = true;
					cout << temp.first << " ,";
				}
			}
		}
		cout << "\n--------------------" << endl;
		delete[] visit;
	}
	void components() {	//輸出這張圖有幾個連通單元
		visit = new bool[n];	//是否拜訪過
		fill(visit, visit + n, false);
		int count = 1;	//記錄有幾個連通單元
		for (int i = 0; i < n; i++) {
			if (!visit[i]) {
				cout << "component " << count++ << " : ";
				DFS(i);
				cout << endl;
			}
		}
		cout << "--------------------" << endl;
		delete[] visit;
	}
	void biconnected() {	//計算此圖的雙連通單元的驅動
		num = 1;
		dfn = new vector<int>(n, 0);
		low = new vector<int>(n, 0);
		biconnected(0, -1);
		cout << "--------------------" << endl;
		dfn->clear();
		low->clear();
		while (!s.empty()) {
			s.pop();
		}
	}
	void spanningTrees(int u = 0) {	//以某點開始做展開樹
		visit = new bool[n];
		fill(visit, visit + n, false);
		cout << "SpanningTrees with root " << u << " edges: "<<endl;
		DFS(u,-1);
		cout << "--------------------" << endl;
		delete[] visit;
	}
	void minimumCostSpanningTreeKruskal() {	//Kruskal
		LinkedWDirectGraph ldg = *this, mcs(n);	//將原本的樹複製一份。產生的最小消耗展開樹
		pair<int, pair<int, int>> lcEdge;	//紀錄選擇到的邊
		vector<int> set(n, 0);	//Set紀錄
		for (int i = 0; i < n; i++) { set[i] = i; }
		while (mcs.numberOfEdges() < (n - 1) && ldg.e > 0) {
			lcEdge = ldg.lowestCostEdge();	//選邊
			ldg.deleteEdge(lcEdge.first, lcEdge.second.first);
			if (set[lcEdge.first] != set[lcEdge.second.first]) {	//更新Set狀態
				for (int i = 0; i < n; i++) {
					if (set[i] == set[lcEdge.second.first] && i != lcEdge.second.first) {
						set[i] = set[lcEdge.first];
					}
				}
				set[lcEdge.second.first] = set[lcEdge.first];
				mcs.insertEdge(lcEdge);
			}
		}
		if (mcs.numberOfEdges() < n - 1) {
			cout << "no spanning tree" << endl;
			return;
		}
		mcs.showGraph();
	}
	void showGraph() {	//將圖印出
		cout << "node: links(weight)"<<endl;
		for (int i = 0; i < n; i++) {
			cout << i << ": ";
			list<pair<int, int>>::iterator iter = vertices[i].begin();
			for (; iter != vertices[i].end(); iter++) {
				pair<int, int> temp = *iter;
				cout << temp.first << "(" << temp.second << ") ";
			}
			cout << endl;
		}
		cout << "--------------------" << endl;
	}
protected:
	pair<int, pair<int, int>> lowestCostEdge() {	//尋找可使用的最小消耗邊
		pair<int, pair<int, int>> min = pair<int, pair<int, int>>(0, pair<int, int>(0, INT_MAX));	//記錄當前的最小邊，預設權重為最大整數。
		for (int i = 0; i < n; i++) {
			list<pair<int, int>>::iterator iter = vertices[i].begin();
			for (; iter != vertices[i].end(); iter++) {
				if ((*iter).second < min.second.second) {
					min = pair<int, pair<int, int>>(i,*iter);
				}
			}
		}
		return min;
	}
	void DFS(const int& v) {	//DFS本體
		visit[v] = true;
		cout << v << " ,";
		list<pair<int,int>>::iterator iter = vertices[v].begin();
		for (; iter != vertices[v].end(); iter++) {
			if (!visit[(*iter).first]) {
				DFS((*iter).first);
			}
		}
	}
	void DFS(const int& v,int x) {	//DFS for spanningtree
		visit[v] = true;
		list<pair<int,int>>::iterator iter = vertices[v].begin();
		for (; iter != vertices[v].end(); iter++) {
			if (!visit[(*iter).first]) {
				cout << v << " - " << (*iter).first << " weight: " << (*iter).second << endl;
				DFS((*iter).first);
			}
		}
	}
	void biconnected(const int& u, const int& v) {	//計算此圖的雙連通單元的本體
		dfn->at(u) = low->at(u) = num++;
		list<pair<int, int>>::iterator iter = vertices[u].begin();
		for (; iter != vertices[u].end(); iter++) {
			if (v != (*iter).first && (dfn->at((*iter).first) < dfn->at(u))) {
				s.push(pair<int, pair<int,int>>(u, *iter));
			}
			if (dfn->at((*iter).first) == 0) {
				biconnected((*iter).first, u);
				low->at(u) = min(low->at(u), low->at((*iter).first));
				if (low->at((*iter).first) >= dfn->at(u)) {
					cout << "New Biconnected Component Edge: ";
					pair<int, pair<int, int>> temp;
					do {
						temp = s.top();
						s.pop();
						cout << temp.first << "-" << temp.second.first << "(" << temp.second.second<<") ";
					} while (temp != pair<int, pair<int, int>>(u, *iter));
					cout << endl;
				}
			}	
			else if ((*iter).first != v) {
				low->at(u) = min(low->at(u), dfn->at((*iter).first));
			}
		}
	}
};
class LinkedWGraph : public LinkedWDirectGraph {	//有權重的無向圖
public:
	LinkedWGraph(int v = 1) :LinkedWDirectGraph(v) { }
	void insertEdge(pair<int, pair<int, int>> edge) {
		LinkedWDirectGraph::insertEdge(edge);
		pair<int, pair<int, int>> temp = pair<int, pair<int, int>>(edge.second.first, pair<int, int>(edge.first, edge.second.second));
		LinkedWDirectGraph::insertEdge(temp);
		e--;
	}
	void insertEdge(int u, int v, int w = 1) {
		LinkedWDirectGraph::insertEdge(u, v, w);
		LinkedWDirectGraph::insertEdge(v, u, w);
		e--;
	}
	void deleteEdge(int u, int v) {
		LinkedWDirectGraph::deleteEdge(u, v);
		LinkedWDirectGraph::deleteEdge(v, u);
		e++;
	}
	void minimumCostSpanningTreeKruskal() {	//Kruskal
		LinkedWGraph ldg = *this, mcs(n);
		pair<int, pair<int, int>> lcEdge;
		vector<int> set(n, 0);
		for (int i = 0; i < n; i++) { set[i] = i; }
		while (mcs.numberOfEdges() < (n - 1) && ldg.e > 0) {
			lcEdge = ldg.lowestCostEdge();
			ldg.deleteEdge(lcEdge.first, lcEdge.second.first);
			if (set[lcEdge.first] != set[lcEdge.second.first]) {	//更新Set狀態
				for (int i = 0; i < n; i++) {
					if (set[i] == set[lcEdge.second.first] && i != lcEdge.second.first) {
						set[i] = set[lcEdge.first];
					}
				}
				set[lcEdge.second.first] = set[lcEdge.first];
				mcs.insertEdge(lcEdge);
			}
		}
		if (mcs.numberOfEdges() < n - 1) {
			cout << "no spanning tree" << endl;
			return;
		}
		mcs.showGraph();
	}
	void showGraph() {	//將圖印出
		cout << "node: links " << endl;
		for (int i = 0; i < n; i++) {
			cout << i << ": ";
			list<pair<int, int>>::iterator iter = vertices[i].begin();
			for (; iter != vertices[i].end(); iter++) {
				pair<int, int> temp = *iter;
				cout << temp.first << " ";
			}
			cout << endl;
		}
		cout << "--------------------" << endl;
	}
};
int main() {
	LinkedWGraph G1(10),G2(7);
	G1.insertEdge(0, 1);
	G1.insertEdge(1, 2);
	G1.insertEdge(1, 3);
	G1.insertEdge(2, 4);
	G1.insertEdge(3, 4);
	G1.insertEdge(3, 5);
	G1.insertEdge(5, 6);
	G1.insertEdge(5, 7);
	G1.insertEdge(6, 7);
	G1.insertEdge(7, 8);
	G1.insertEdge(7, 9);
	cout << "G1的連結串列: " << endl;
	G1.showGraph();
	cout << "G1做DFS的順序: " << endl;
	G1.DFS();
	cout << "G1的BFS 0開始的順序: " << endl;
	G1.BFS(1);
	cout << "G1的連通單元: " << endl;
	G1.components();
	cout << "G1的雙連通單元: " << endl;
	G1.biconnected();
	cout << "G1的最小消耗樹: " << endl;
	G1.minimumCostSpanningTreeKruskal();
	G2.insertEdge(0, 1, 28);
	G2.insertEdge(0, 5, 10);
	G2.insertEdge(1, 2, 16);
	G2.insertEdge(1, 6, 14);
	G2.insertEdge(2, 3, 12);
	G2.insertEdge(3, 4, 22);
	G2.insertEdge(3, 6, 18);
	G2.insertEdge(4, 5, 25);
	G2.insertEdge(4, 6, 24);
	cout << "G2的連結串列: " << endl;
	G2.showGraph();
	cout << "G2做DFS的順序: " << endl;
	G2.DFS();
	cout << "G2的BFS 0開始的順序: " << endl;
	G2.BFS(1);
	cout << "G2的連通單元: " << endl;
	G2.components();
	cout << "G2的雙連通單元: " << endl;
	G2.biconnected();
	cout << "G2的最小消耗樹: " << endl;
	G2.minimumCostSpanningTreeKruskal();
	system("pause");
}
