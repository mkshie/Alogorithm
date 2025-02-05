#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int N, M, V; // 노드 , 간선 , 시작 노드
int arr[1001][1001] = {0};
bool visit_node[1001] = {false};

//인접리스트

void DFS(int snode){
    visit_node[snode] = true;
    cout << snode << " ";

    for (int i = 1; i <= N; i++){
        if (arr[snode][i] == 1 && !visit_node[i]){
            visit_node[i] = false;
            DFS(i);
        }
    }
}
void BFS(int snode){
    queue<int> que;
    que.push(snode);
    visit_node[snode] = true;
    while (!que.empty())
    {
        int node = que.front();
        que.pop();
        cout << node << " ";
        for (int i = 1; i <= N; i++)
        {
            if(arr[node][i] == 1 && !visit_node[i]){
                que.push(i);
                visit_node[i] = true;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> V;
    int x, y;
    for (int i = 0; i < M; i++)
    {
        cin >> x >> y;
        arr[x][y] = arr[y][x] = 1;
    }
    DFS(V);
    cout << "\n";
    memset(visit_node, false, sizeof(visit_node));
    BFS(V);
}