#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int, int>> graph[20001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E;
    cin >> V >> E;
    int start;
    cin >> start;
    for (int i = 0; i < E;i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    vector<int> short_table(V + 1, 999999999);
    short_table[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    while(!pq.empty()){
        int cur_weight = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();
        for(pair <int,int> street : graph[cur_node]){
            int nt_node = street.first;
            int nt_weigt = street.second;
            if(short_table[nt_node] > nt_weigt + cur_weight){
                short_table[nt_node] = nt_weigt + cur_weight;
                pq.push({nt_weigt + cur_weight, nt_node});
            }
        }
    }
    for (int i = 1; i <= V;i++){
        if(short_table[i] < 999999999)
            cout << short_table[i] << "\n";
        else
            cout << "INF\n";
    }
}