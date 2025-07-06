#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <map>

using namespace std;

map<int, pair<int, int>> nodeToCoord;
vector <pair<long double, pair<int, int>>> path;
vector<int> parents;

int find(int u){
    if(parents[u] == u)
        return u;
    return parents[u] = find(parents[u]);
}

bool merge(int u , int v){
    u = find(u);
    v = find(v);
    if(u==v)
        return false;
    parents[u] = v;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N;
    cin >> N >> M; // 우주신들의 개수 , 이미 연결된 애들
    for (int i = 1; i <= N;i++){
        int X, Y;
        cin >> X >> Y;
        for (int j = 1; j < i; j++)
        {
            int pre_X = nodeToCoord[j].first;
            int pre_Y = nodeToCoord[j].second;
            long long dx = pre_X - X;
            long long dy = pre_Y - Y;
            long double dist = sqrt(static_cast<long double>(dx * dx + dy * dy));
            path.push_back({dist, {i, j}});
        }
        nodeToCoord[i] = {X, Y};
    }
    parents = vector<int>(N + 1, 0);
    for (int i = 1; i <= N;i++){
        parents[i] = i; //초기 부모 노드 설정해주기
    }
    for (int i = 0; i < M;i++){
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }
    int cnt = M;
    // if(cnt >= N-1){
    //     cout << "0.00\n";
    //     return 0;
    // }
    long double answer = 0.0;
    sort(path.begin(), path.end());
    for (int i = 0; i < path.size();i++){
        long double dist = path[i].first;
        int u = path[i].second.first;
        int v = path[i].second.second;
        if(merge(u,v)){
            answer += dist;
            cnt++;
        }
    }
    cout << fixed << setprecision(2) << answer << "\n";
    return 0;
}