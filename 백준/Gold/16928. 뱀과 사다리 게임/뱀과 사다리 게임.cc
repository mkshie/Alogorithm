#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<int> graph[101];
    int visited[101] = {0};
    visited[1] = true;
    for (int i = 0; i < N; i++)
    { // 사라디
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    for (int i = 0; i < M; i++) //뱀
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    priority_queue<pair<int, int>> pq;
    int answer = 99999999;
    pq.push({0, 1});
    while(!pq.empty()){
        int cur_cnt = -1 * pq.top().first;
        int cur_pos = pq.top().second;
        pq.pop();
        if (cur_pos == 100)
        {
            answer = min(answer, cur_cnt);
            break;
        }
        for (int i = 6; i > 0;i--){

            int nxt_cnt = cur_cnt + 1;
            int nxt_pos = cur_pos + i;
            if(nxt_pos > 100)
                continue;
            if(!graph[nxt_pos].empty())
                nxt_pos = graph[nxt_pos][0];
            if(visited[nxt_pos] == 0){ // 방문한 적 없다면
                visited[nxt_pos] = nxt_cnt;
                pq.push({-1 * nxt_cnt, nxt_pos});
            }
        }
    }
    cout << answer << "\n";
    return 0;
}