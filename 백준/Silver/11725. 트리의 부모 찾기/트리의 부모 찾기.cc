#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> parent_node(100001 , 0);
bool visited[100001] = {false};

void dfs(int parent , vector<int> tree[]){
    for (int i = 0; i < tree[parent].size();i++){
        int child = tree[parent][i];
        if(parent_node[child] == 0){
            parent_node[child] = parent;
            dfs(child, tree);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;

    vector<int> tree[N + 1];

    for (int i = 0; i < N-1;i++){
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    parent_node[1] = 1;
    dfs(1, tree);
    for (int i = 2; i <= N;i++){
        cout << parent_node[i] << "\n";
    }
    return 0;
}