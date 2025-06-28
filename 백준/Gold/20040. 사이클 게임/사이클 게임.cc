#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int find(int u)
{
    if (parent[u] == u)
        return u;
    return parent[u] = find(parent[u]); // 아니라면 재귀적으로 부모 노드를 업데이트 하기
    // 시간 단축에 매우 좋음.
}

void merge(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return;
    parent[u] = v;
}

int main(){
    int n, m;
    cin >> n >> m;

    parent = vector<int>(n, 0);
    for (int i = 0; i < n;i++)
        parent[i] = i;
    for (int i = 0; i < m;i++){
        int u, v;
        cin >> u >> v;
        if(find(u) != find(v))
            merge(u, v);
        else{
            cout << i + 1 << "\n";
            return 0;
        }
    }
    cout << "0\n";
    return 0;
}