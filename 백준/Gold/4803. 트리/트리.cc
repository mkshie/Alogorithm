#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<bool> visited(501, false);
bool has_cycle = false;

void dfs(int cur_node, int par_node, vector<vector<int>> &tree)
{
    visited[cur_node] = true;
    for (int next_node : tree[cur_node])
    {
        if(next_node == par_node) continue;
    
        if(!visited[next_node]){
           dfs(next_node, cur_node, tree);
        }
        else{ // 부모 노드가 아닌데 방문한 적 있다면
            has_cycle = true;
            continue;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    int while_count = 1;
    while (cin >> n >> m, n || m)
    {
        vector<vector<int>> tree(n+1);
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if(!visited[i]){
                has_cycle = false;
                dfs(i, 0, tree);
                if(!has_cycle)
                    cnt++;
            }
        }
        if (cnt == 0)
        {
            cout << "Case " << while_count << ": No trees.\n";
        }
        else if (cnt == 1)
        {
            cout << "Case " << while_count << ": There is one tree.\n";
        }
        else
        {
            cout << "Case " << while_count << ": A forest of " << cnt << " trees.\n";
        }
        fill(visited.begin(), visited.end(), false);
        while_count++;
    }
    return 0;
}