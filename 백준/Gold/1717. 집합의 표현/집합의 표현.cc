#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int find(int u){
    if(parent[u] == u)
        return u;
    return parent[u] = find(parent[u]);
}

void merge(int u , int v){
    u = find(u);
    v = find(v);
    if(u == v)
        return;
    parent[u] = v;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;
    parent = vector<int>(n+1, 0);
    for (int i = 0; i < n + 1;i++){
        parent[i] = i;
    }
    for (int i = 0; i < m;i++){
        int num, u, v;
        cin >> num >> u >> v;
        if(num == 1){
            if(find(u) == find(v))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else{
            merge(u, v);
        }
    }
}