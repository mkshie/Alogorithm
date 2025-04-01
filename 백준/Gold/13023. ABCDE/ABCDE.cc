#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
vector<int> adj[2000];
int visited[2000] = {0};
bool answer = false;

bool dfs(int num , int cnt){

    if(cnt == 4){
        answer = true;
        return true;
    }

    for (int next : adj[num]){
        if(visited[next] == 0){
            visited[next] = 1;
            if(dfs(next, cnt + 1))
                return true;
            visited[next] = 0;
        }
    }

    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M;i++){
        int y, x;
        cin >> y >> x;
        adj[y].push_back(x);
        adj[x].push_back(y);
    }
    for (int i = 0; i < N;i++){
        visited[i] = 1;
        dfs(i, 0);
        if (answer)
        {
            cout << 1 << "\n";
            return 0;
        }
        visited[i] = 0;
    }
    cout << 0 << "\n";
    return 0;
}