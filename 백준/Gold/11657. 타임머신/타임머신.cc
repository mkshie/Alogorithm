#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

const long long INF = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E;
    cin >> V >> E;
    vector<long long> dist(V + 1, INF);
    vector<tuple<int, int, int>> graph;
    for (int i = 0; i < E;i++){
        int u, v, c;
        cin >> u >> v >> c;
        graph.push_back({u, v, c});//시작점 , 도착점 , 비용
    }
    dist[1] = 0;
    for (int i = 0; i < V-1;i++){ //모든 정점에 대하여 반복
        for (int j = 0; j < E; j++){
            auto [cur_node, next_node, cost] = graph[j];
            if(dist[cur_node] != INF && dist[cur_node] + cost < dist[next_node]){ // 현재 간선을 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
                dist[next_node] = dist[cur_node] + cost;
            }
        }
    }
    for (int j = 0; j < E; j++) //음수 사이클이 있는지 측정
    {
        auto [cur_node, next_node, cost] = graph[j];
        if (dist[cur_node] != INF && dist[cur_node] + cost < dist[next_node])
        { // 현재 간선을 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
            cout << "-1\n";
            return 0;
        }
    }
    for (int i = 2; i <= V; i++)
    {
        if(dist[i]!=INF)
            cout << dist[i] << "\n";
        else
            cout << "-1\n";
    }
    return 0;
}