#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
// 노드의 개수가 1000개가 넘어가게 된다면 dfs 로는 시간초과가 날 가능성이 높다.
// 가중치가 모두 양수라면 다익스트라를 이용해서 최단경로를 찾는게 훨씬 효율적이다.
// 음수가 들어가게 되면 벨만포드 알고리즘을 사용하자

// 출발지와 도착지가 같은 버스가 여러개 존재가 가능

//경로를 알아내기 위해서 해당 경로를 출발지로 부터 몇번째만에 가는지를 저장해둔 뒤 
//단방향 그래프이기때문에 역방향 그래프를 만들어주고 해당 그래프에서 경로값의 차이와 몇번만에 도달했는지의 차이를 두어 경로를 추론할 수 있게끔 했다.
using namespace std;

#define INF 999999999

int N, M;
int start, dest;
vector<pair<int,int>> short_table(1001, {INF,0});
vector<pair<int, int>> graph[1001]; //인접리스트 방식
vector<pair<int, int>> invers_graph[1001]; // 인접리스트 방식

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int st, end, cost;
        cin >> st >> end >> cost;
        graph[st].push_back({end, cost}); // 도착지점과 비용을 입력
    }
    cin >> start >> dest;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 최소 힙
    pq.push({0, start});

    short_table[start] = {0,0}; // 시작지점 초기화

    while (!pq.empty())
    {
        int cur_cost = pq.top().first;
        int cur_location = pq.top().second;
        int cur_cnt = short_table[cur_location].second;

        pq.pop();

        if (short_table[cur_location].first < cur_cost)
            continue;

        for (int next = 0; next < graph[cur_location].size(); next++)
        {    // 갈 수 있다면
            int nxt_node = graph[cur_location][next].first;  // 인접 노드 번호
            int nxt_dist = graph[cur_location][next].second; // 경로 비용
            if (cur_cost + nxt_dist < short_table[nxt_node].first)
            // 다음번의 지역으로 가는 비용이 지금 저장된 테이블보다 작다면
            {
                short_table[nxt_node].first = cur_cost + nxt_dist;
                //최단경로로 왔을때의 횟수 역시 수정해줘야함
                short_table[nxt_node].second = cur_cnt + 1;
                pq.push({short_table[nxt_node].first, nxt_node}); // 우선순위 큐에 삽입해준다.
            }
        }
    }
    cout << short_table[dest].first << "\n" << short_table[dest].second + 1 <<"\n";

    
    for (int i = 1; i <= N; i++) // 방향 반대인 그래프 만들어주기
    {
        for(pair<int,int> node_cost : graph[i]){
            invers_graph[node_cost.first].push_back({i, node_cost.second});
        }
    }
    stack<int> root;
    int cur_location = dest;
    root.push(dest);
    while(cur_location != start){ // 시작지점이 아니라면 계속 돌기
        int cnt = short_table[cur_location].second;
        for (int next = 0; next < invers_graph[cur_location].size(); next++){
            int nxt_node = invers_graph[cur_location][next].first; // 인접 노드 번호
            int nxt_dist = invers_graph[cur_location][next].second; // 경로 비용
            if (short_table[nxt_node].first == short_table[cur_location].first - nxt_dist &&
                short_table[nxt_node].second == cnt - 1) //방문횟수가 하나 줄어들고 경로 값의 차가 맞다면 이전 경로임
            {
                root.push(nxt_node);
                cur_location = nxt_node;
                break;
            }
        }
    }
    while(!root.empty()){
        cout << root.top() << " ";
        root.pop();
    }
    cout << "\n";
}