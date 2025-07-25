#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int N, R, Q; // 정점의 개수 , 루트 노드 , 쿼리의 개수

unordered_map<int, vector<int>> um;
vector<vector<int>> tree;
vector<bool> visited;
vector<int> dp;

int dfs(int node)
{
    tree[node] = um[node];
    visited[node] = true;
    int subtree_size = 0; // 서브트리 size 계산
    for (int i = 0; i < tree[node].size(); i++)
    {
        int next_child = tree[node][i];
        if (!visited[next_child]) // 방문한적 없다면 들어가기
            subtree_size += dfs(tree[node][i]);
    }
    dp[node] = subtree_size + 1;

    return dp[node];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> R >> Q;

    tree.resize(N + 1);
    dp.resize(N + 1, 0);
    visited.resize(N + 1, false);

    // 문제 root 를 임의로 정해주기 때문에 어떤게 부모이고 자식인지를 입력시에 따로 확인을 해줘야함
    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        um[u].push_back(v);
        um[v].push_back(u);
    }
    dfs(R);
    for (int i = 0; i < Q; i++)
    {
        int num;
        cin >> num;
        cout << dp[num] << "\n";
    }

    return 0;
}
