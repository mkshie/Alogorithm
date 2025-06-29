#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

map<int, int> parent;
unordered_map<int, pair<double, double>> graph; // 1~100 번째까지의 노드들을 저장해주는 곳 // 노드 길이 정보 담을때 활용
vector<pair<double,pair<int,int>>> path_vector;
double answer = 0;

int find(int u){
    if(parent[u]==u)
        return u;
    return parent[u] = find(parent[u]);
}

void merge(int u,int v){
    u = find(u);
    v = find(v);
    parent[u] = v;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    //vector<pair<double, double>> graph;

    for (int i = 1; i <= n; i++)
    {
        double x, y;
        cin >> x >> y;
        if(graph.size()!=0){ // 그래프의 사이즈가 0 이 아니라면
            for(auto a : graph){
                double dist = sqrt(pow(x - a.second.first, 2) + pow(y - a.second.second,2));
                dist = round(dist * 100) / 100.0; // 소수 둘째짜리까지 올림
                path_vector.push_back({dist, {i, a.first}}); // i 번에서 a.first 로 가는 길 저장
            }
        }
        graph[i] = {x, y}; // 해당 정보 그래프에 추가하기
        parent[i] = i; // union-find 를 위한 초기값 설정
    }
    sort(path_vector.begin(), path_vector.end()); // 오름차순으로 정렬해주기
    int cnt = 0;
    for (int i = 0; i < path_vector.size();i++){
        if(cnt == n - 1){
            cout << answer << "\n";
            break;
        }
        int start, end;
        double dist;
        start = path_vector[i].second.first; // 출발 좌표
        end = path_vector[i].second.second; // 도착 좌표
        dist = path_vector[i].first;
        if(find(start) != find(end)){
            merge(start, end);
            answer += dist;
            cnt++;
        }
    }
}