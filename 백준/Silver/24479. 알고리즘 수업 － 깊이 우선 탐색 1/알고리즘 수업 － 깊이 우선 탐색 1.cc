#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, R;
vector<int> graph[100001];
int visited[100001] = {0};
int cnt = 1;
void dfs(int idx)
{
    if(visited[idx] == 0){
        visited[idx] = cnt++;
        for (int i = 0; i < graph[idx].size(); i++)
        {
            if(visited[graph[idx][i]] == 0) dfs(graph[idx][i]); //방문하지 않았을경우에만 방문해주기
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> R;
    for (int i = 0; i < M;i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v); // 무방향 그래프이기 때문에  양옆으로 방분해주기
        graph[v].push_back(u);
    }
    for (vector<int> &arr : graph){
        sort(arr.begin(), arr.end());
    }
    //visited[R] = 1;
    dfs(R);
    for (int i = 1; i <= N;i++)
        cout << visited[i] << "\n";
}