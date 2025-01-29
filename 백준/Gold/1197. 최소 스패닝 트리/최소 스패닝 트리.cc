#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

//struct Compare {
//	bool operator()(pair<int, pair<int, int>>p1, pair<int, pair<int, int>>p2) {
//		return p1.first > p2.first;
//	}
//};

priority_queue <pair<int, pair< int,int >>,vector<pair<int,pair<int ,int>>>,greater<pair<int,pair<int,int>>>> arr;
int parent[10001] = { 0 };

int find(int x) {
	if (parent[x] != x) return parent[x] = find(parent[x]);
	else
	{
		return x;
	}
}

bool uni(int a , int b) {
	int x = find(a);
	int y = find(b);
	if (x==y) return false;
	else
	{
		parent[x] = y;
		return true;
	}
}



int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int V, E;
	cin >> V >> E;
	int A, B, C;
	int answer=0;
	for (int i = 1; i < V + 1; i++) {
		parent[i] = i;
	}
	while (E--) {
		cin >> A >> B >> C;
		arr.push({ C,{A,B} }); // 간선과 두 정점을 입력 // 우선순위 queue 라 간선의 값이 작은것부터 맨 앞으로 정렬됨
	}
	while (!arr.empty()) {
		int edge = arr.top().first;
		int nodeA = arr.top().second.first, nodeB = arr.top().second.second;
		arr.pop();
		if (uni(nodeA,nodeB)) {
			/*cycle[nodeA] = true; cycle[nodeB] = true;*/
			answer += edge;
		}
		
	}
	cout << answer;
	return 0;
}