#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 1e9;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++)
    {
        graph[i][i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if (graph[u][v] > w) // 출발 정점과 도착정점 사이에 길이 여러개가 존재할 수 있음(최소값만 저장하기)
            graph[u][v] = w;
    }
    for (int k = 1; k <= n; k++)
    { // 플로이드 워셜 알고리즘 실행 k 는 중간지점 , i 출발 , j 도착 정점
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (graph[i][k] + graph[k][j] < graph[i][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            if(graph[i][j] == INF)
                cout << "0 ";
            else
                cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}