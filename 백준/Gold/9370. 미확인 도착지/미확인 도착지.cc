#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>

using namespace std;

const int INF = 1e9;

vector<int> dijkstra(int start , int cnt , vector<pair<int,int>> graph[])
{
    vector<int> short_table(cnt + 1, INF);
    short_table[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while(!pq.empty()){
        int weight = pq.top().first;
        int cur_node = pq.top().second;

        pq.pop();

        if(short_table[cur_node] < weight)
            continue;
        for(pair<int,int> a : graph[cur_node]){
            int next_node = a.first;
            int next_weight = weight + a.second;
            if(short_table[next_node] > next_weight){
                short_table[next_node] = next_weight;
                pq.push({next_weight, next_node});
            }
        }
    }
    return short_table;
}

int T,n, m, t;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while (T--)
    {
        cin >> n >> m >> t; // 교차로(노드) , 도로(엣지) , 목적지 후보의 개수
        int s, g, h;
        cin >> s >> g >> h;                  // 출발지 , g 와 h 의 사이의 도로를 지나감
        vector<pair<int, int>> graph[n + 1]; // 인접리스트 방식
        for (int i = 0; i < m; i++)
        {
            int a, b, d;
            cin >> a >> b >> d;
            graph[a].push_back({b, d});
            graph[b].push_back({a, d});
        }
        set<int> list;
        for (int i = 0; i < t; i++)
        {
            int num;
            cin >> num;
            list.insert(num);
        }
        vector<int> dist_s = dijkstra(s, n, graph);
        vector<int> dist_g = dijkstra(g, n, graph);
        vector<int> dist_h = dijkstra(h, n, graph);

        int dist_g_h = dist_g[h];

        for(int num  : list){
            if(dist_s[num] == dist_s[g] + dist_g_h + dist_h[num]){
                cout << num << " ";
            }
            else if(dist_s[num] == dist_s[h] + dist_g_h + dist_g[num]){
                cout << num << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}