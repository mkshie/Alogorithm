#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int, int>> graph[801];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E;
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    int A, B;
    cin >> A >> B;
    vector<long long> short_table(V + 1, 999999999);
    vector<long long> short_table_A_V(V + 1, 999999999);
    vector<long long> short_table_B_V(V + 1, 999999999);
    short_table[1] = 0;
    short_table_A_V[A] = 0;
    short_table_B_V[B] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    while (!pq.empty())
    {
        int cur_weight = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();
        for (pair<int, int> street : graph[cur_node])
        {
            int nt_node = street.first;
            int nt_weigt = street.second;
            if (short_table[nt_node] > nt_weigt + cur_weight)
            {
                short_table[nt_node] = nt_weigt + cur_weight;
                pq.push({nt_weigt + cur_weight, nt_node});
            }
        }
    }
    pq.push({0, A});
    while (!pq.empty())
    {
        int cur_weight = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();
        for (pair<int, int> street : graph[cur_node])
        {
            int nt_node = street.first;
            int nt_weigt = street.second;
            if (short_table_A_V[nt_node] > nt_weigt + cur_weight)
            {
                short_table_A_V[nt_node] = nt_weigt + cur_weight;
                pq.push({nt_weigt + cur_weight, nt_node});
            }
        }
    }
    pq.push({0, B});
    while (!pq.empty())
    {
        int cur_weight = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();
        for (pair<int, int> street : graph[cur_node])
        {
            int nt_node = street.first;
            int nt_weigt = street.second;
            if (short_table_B_V[nt_node] > nt_weigt + cur_weight)
            {
                short_table_B_V[nt_node] = nt_weigt + cur_weight;
                pq.push({nt_weigt + cur_weight, nt_node});
            }
        }
    }
    long long int answer = min(short_table[A] + short_table_A_V[B] + short_table_B_V[V],
     short_table[B] + short_table_B_V[A] + short_table_A_V[V]);
    if (answer > 99999999)
        cout << -1 << "\n";
    else
        cout << answer << "\n";
    return 0;
}