#include <iostream>
#include <vector>

using namespace std;

int result = 0;

void bfs(int start , vector<bool> &visited , vector<int> graph[]){
    visited[start] = true;
    for (int i = 0; i < graph[start].size();i++){
        int next_node = graph[start][i];
        if (!visited[next_node]) // 방문하지 않았다면
        {
            result++;
            bfs(next_node, visited, graph);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> graph[N + 1];
    vector<bool> visited(N + 1, false);
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bfs(1,visited,graph);

    cout << result << "\n";
}
