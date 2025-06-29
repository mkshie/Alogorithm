#include <iostream>
#include <vector>

using namespace std;
vector<int> parent;
int T;

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

    cin >> T;

    while(T--){
        int N, M;
        cin >> N >> M;
        parent = vector<int>(N + 1, 0);
        for (int i = 1; i <= N;i++)
            parent[i] = i;
        vector<pair<int, int>> path;
        for (int i = 0; i < M;i++){
            int a, b;
            cin >> a >> b;
            path.push_back({a, b});
        }
        int real_cnt = 0;
        for (pair<int, int> root : path)
        {
            if(find(root.first) != find(root.second)){
                merge(root.first, root.second);
                real_cnt++;
            }
            if(real_cnt == N - 1)
                break;
        }
        cout << real_cnt << "\n";
    }
}