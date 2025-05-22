#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <deque>
#include <algorithm>

using namespace std;

int N, M , R;
vector<int> grahp[100001];
int answer[100001] = {0};
deque<int> dq;
int cnt = 2;

void bfs(){
    answer[R] = 1;
    cnt = 2;
    dq.push_front(R);
    while (!dq.empty())
    {
        int idx = dq.front();
        dq.pop_front();
        for (int i = 0; i < grahp[idx].size(); i++)
        {
            if (answer[grahp[idx][i]] == 0)
            { // 방문하지 않은곳이라면
                answer[grahp[idx][i]] = cnt++;
                dq.push_back(grahp[idx][i]);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> R;
    for (int i = 0; i < M;i++){
        int u, v;
        cin >> u >> v;
        grahp[u].push_back(v);
        grahp[v].push_back(u); // 단방향 그래프
    }
    for(vector<int> &arr : grahp){
        sort(arr.begin(), arr.end()); // 오름차순으로 정렬해주기
    }
    bfs();
    for (int i = 1; i <= N;i++)
        cout << answer[i] << "\n";
    return 0;
}