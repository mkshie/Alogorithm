#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int N;
vector<vector<int>> tree;
vector<vector<int>> dp;
vector<bool> visited;

void dfs(int node)
{
    visited[node] = true; // 방문 처리
    dp[node][1] = 1;

    for (int i = 0; i < tree[node].size(); i++)
    {
        int next_node = tree[node][i];
        if (visited[next_node]) // 부모노드라면 이미 지나친곳이므로 pass
            continue;
        dfs(next_node);
        dp[node][0] += dp[next_node][1];                        // 내가 얼리어답터가 아니라면 자식이 모두 얼리어답터여야함
        dp[node][1] += min(dp[next_node][0], dp[next_node][1]); // 내가 얼리어답터라면 자식노드 상관없음
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    tree.resize(N + 1);
    visited.resize(N + 1, false);
    dp.resize(N + 1, vector<int>(2, 0)); // dp[node][0] = 내가 얼리어답터가 아닌 경우 , dp[node][1] = 얼리어답터 인경우
    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1);
    cout << min(dp[1][1], dp[1][0]) << "\n";
    return 0;
}