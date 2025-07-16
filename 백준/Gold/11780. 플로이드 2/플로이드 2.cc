#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int n, m; // 도시의 개수 , 버스의 개수
vector<vector<int>> graph;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    graph = vector<vector<int>>(n + 1, vector<int>(n + 1, INF));
    vector<int> root[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            root[i][j].push_back(i);
            root[i][j].push_back(j);
        }
    }

    for (int i = 0; i < m; i++)
    {
        int u, v, dist;
        cin >> u >> v >> dist;
        if (graph[u][v] > dist)
            graph[u][v] = dist;
    }
    for (int i = 1; i <= n; i++)
    {
        graph[i][i] = 0; // 자기 자신으로 가는 거리는 항상 0
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (graph[i][k] + graph[k][j] < graph[i][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j]; // 즉 경로 갱신
                    root[i][j] = root[i][k];
                    root[i][j].insert(root[i][j].end(), root[k][j].begin() + 1, root[k][j].end());
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (graph[i][j] == INF)
                cout << "0 ";
            else
                cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (graph[i][j] == INF || graph[i][j] == 0)
                cout << "0";
            else
            {
                cout << root[i][j].size()<< " ";
                for (int k = 0; k < root[i][j].size(); k++)
                    cout << root[i][j][k] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}