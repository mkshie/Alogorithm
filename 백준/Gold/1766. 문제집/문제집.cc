#include <queue>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;

    cin >> N >> M;
    vector<vector<int>> graph(N + 1);
    vector<int> indegree(N + 1, 0);
    for (int i = 0; i < M;i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        indegree[v]++;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= N;i++){
        if(indegree[i]==0)
            pq.push(i);
    }
    vector<int> answer;
    while (!pq.empty())
    {
        int cur_node = pq.top();
        pq.pop();
        answer.push_back(cur_node);
        for (int nxt_node : graph[cur_node])
        {
            indegree[nxt_node]--;
            if(indegree[nxt_node] == 0)
                pq.push(nxt_node);
        }
    }
    for(int node : answer)
        cout << node << " ";
    return 0;
}