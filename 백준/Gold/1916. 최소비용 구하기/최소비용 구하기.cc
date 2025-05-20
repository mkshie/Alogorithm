#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>


//노드의 개수가 1000개가 넘어가게 된다면 dfs 로는 시간초과가 날 가능성이 높다. 
//가중치가 모두 양수라면 다익스트라를 이용해서 최단경로를 찾는게 훨씬 효율적이다.
//음수가 들어가게 되면 벨만포드 알고리즘을 사용하자

//출발지와 도착지가 같은 버스가 여러개 존재가 가능
using namespace std;

#define INF 1e9

int N, M;
int start, dest;
vector<vector<int>> graph;
vector<int> short_table(1001, INF);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    graph = vector<vector<int>>(N+1, vector<int>(N+1, -1));
    for (int i = 0; i < M; i++)
    {
        int st, end, cost;
        cin >> st >> end >> cost;
        if(graph[st][end] == -1)
            graph[st][end] = cost;
        else{
            graph[st][end] = min(graph[st][end], cost);
        }
    }
    cin >> start >> dest;
    priority_queue<pair<int, int>, vector<pair<int, int>> ,greater<pair<int, int>>> pq; //최소 힙
    pq.push({0, start});

    short_table[start] = 0; // 시작지점 초기화

    while(!pq.empty()){
        int cur_cost = pq.top().first;
        int cur_location = pq.top().second;

        pq.pop();

        if(short_table[cur_location] < cur_cost) continue;

        for (int next = 1; next <= N;next++){
            if(graph[cur_location][next] != -1){ // 갈 수 있다면
                if(cur_cost + graph[cur_location][next] < short_table[next]) // 다음번의 지역으로 가는 비용이 지금 저장된 테이블보다 작다면
                {
                    short_table[next] = cur_cost + graph[cur_location][next];
                    pq.push({short_table[next], next}); // 우선순위 큐에 삽입해준다.
                }
            }
        }
    }
    cout << short_table[dest] << "\n";
}