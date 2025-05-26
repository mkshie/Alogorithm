#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;

    cin >> N >> M;
    vector<int> indegree(N + 1, 0);
    vector<vector<int>> graph(N + 1);

    for (int i = 0; i < M;i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        indegree[v]++; // 진입 차수 세어주기
    }
    queue<int> q;
    vector<int> answer;
    for (int i = 1; i <= N; i++)
    {
        if(indegree[i]==0) // 진입 차수가 0 이라면
            q.push(i);
    }
    while(!q.empty()){
        int cur_node = q.front();
        q.pop();
        answer.push_back(cur_node);
        for(int nxt_node : graph[cur_node]){
            indegree[nxt_node]--;
            if(indegree[nxt_node] == 0)
                q.push(nxt_node);
        }
    }
    for(int node : answer){
        cout << node << " ";
    }
    cout << "\n";
    return 0;
}