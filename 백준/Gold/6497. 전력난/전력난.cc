#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, n;
vector<pair<int, pair<int, int>>> path;
vector<int> parents;

int find(int u)
{
    if (parents[u] == u)
        return u;
    return parents[u] = find(parents[u]);
}

bool merge(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return false;
    parents[u] = v;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> results;
    while (true)
    {
        long long dist_sum = 0;
        int cnt = 0;
        cin >> m >> n;
        if(m==0 && n==0)
            break;
        parents = vector<int>(m, 0);
        for (int i = 0; i < m; i++)
        {
            parents[i] = i;
        }
        for (int i = 0; i < n; i++)
        {
            int x, y, z;
            cin >> x >> y;
            cin >> z;
            path.push_back({z, {x, y}});
            dist_sum += z;
        }
        sort(path.begin(), path.end());
        for (int i = 0; i < path.size(); i++)
        {
            int u = path[i].second.first;
            int v = path[i].second.second;
            int dist = path[i].first;

            if (merge(u, v))
            {
                dist_sum = dist_sum - dist;
                cnt++;
            }

            if (cnt == m - 1)
            {
                //cout << dist_sum << "\n";
                break;
            }
        }
        results.push_back(dist_sum);
        path.clear();
    }
    for(int num : results)
        cout << num << "\n";
    return 0;
}