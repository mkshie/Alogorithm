#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr;
vector<vector<int>> tree;
vector<bool> visited;
vector<vector<int>> dp;

void slove(int node)
{
    visited[node] = true;     // 방문처리
    dp[node][1] += arr[node]; // 우수 마을인경우 dp 값에 더해주기

    for (int i = 0; i < tree[node].size(); i++)
    {
        int nxt_node = tree[node][i];
        if (visited[nxt_node])
            continue;
        slove(nxt_node);
        dp[node][1] += dp[nxt_node][0];                       // 자식들이 우수마을이 아닌경우의 최대값을 더해주기
        dp[node][0] += max(dp[nxt_node][0], dp[nxt_node][1]); // 우수마을이 아닌경우 둘중 최대를 더해주기
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
    // 1.우수 마을의 조건 인접한 두 마을이 모두 우수 마을이면 안된다.
    // 2.우수 마을이 아니라면 인접한 마을에 우수마을이 있어야한다.(적어도 하나의 마을은 우수마을이여야함)
    // 3.값이 최대가 되게끔 해야함.
    // 일단 내가 우수 마을이 아니라면 주변에 최소 하나는 우수 마을이여야한다는 조건은 무시해도 될 것 같다. 최대값을 구하는 문제이기 때문에
    // dp 를 구하는 과정에서 따로 조건을 만들어두지 않더라도 최소 하나는 우수 마을이 있게 된다는게 내 생각... 아니라면 다시 구현을 생각해봐야겠다.
    slove(1);
    cout << max(dp[1][1], dp[1][0]) << "\n";
    return 0;
}