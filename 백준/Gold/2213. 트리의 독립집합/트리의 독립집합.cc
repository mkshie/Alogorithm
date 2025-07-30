#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr;
vector<vector<int>> tree;
vector<bool> visited;
vector<vector<int>> dp;
// vector<int> trace;
vector<vector<int>> trace;

void slove(int node)
{
    visited[node] = true;     // 방문처리
    dp[node][1] += arr[node]; // 우수 마을인경우 dp 값에 더해주기
    // trace[node].push_back(node); // 자기자신의 값은 넣지 말자...
    vector<int> arr2;

    for (int i = 0; i < tree[node].size(); i++)
    {
        int nxt_node = tree[node][i];
        if (visited[nxt_node])
            continue;
        slove(nxt_node);
        dp[node][0] += max(dp[nxt_node][0], dp[nxt_node][1]); // 우수마을이 아닌경우 둘중 최대를 더해주기
        dp[node][1] += dp[nxt_node][0];                       // 자식들이 우수마을이 아닌경우의 최대값을 더해주기
        // if (dp[nxt_node][0] < dp[nxt_node][1])
        //     arr2.push_back(nxt_node);
    }
}

void dp_trace(int node, int selected) // node 와 해당 dp 에선 0 이였는지 1 이였는지
{
    visited[node] = true;
    if (selected == 1) // 자기 자신 1 이라면 추가해주기
    {
        trace[0].push_back(node);
    }

    for (int i = 0; i < tree[node].size(); i++)
    {
        int nxt_node = tree[node][i];
        if (visited[nxt_node])
            continue;
        if (selected == 1)
        {
            dp_trace(nxt_node, 0);
        }
        else if (dp[nxt_node][0] < dp[nxt_node][1])
        {
            dp_trace(nxt_node, 1);
        }
        else
        {
            dp_trace(nxt_node, 0);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    arr.push_back(0);

    tree.resize(N + 1);
    visited.resize(N + 1, false);
    dp.resize(N + 1, vector<int>(2, 0));
    trace.resize(N + 1);

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    slove(1);

    cout << max(dp[1][1], dp[1][0]) << "\n";
    visited.clear();
    visited.resize(N + 1, false);

    if (dp[1][1] > dp[1][0])
    {
        dp_trace(1, 1);
    }
    else
        dp_trace(1, 0);
    sort(trace[0].begin(), trace[0].end());
    for (int num : trace[0])
        cout << num << " ";
    cout << "\n";
    return 0;
}