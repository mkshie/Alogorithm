#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int graph[501][501] = {0};
        vector<int> indegree(N + 1, 0);
        vector<int> past;
        for (int i = 0; i < N;i++){
            int num;
            cin >> num;
            past.push_back(num);
        }
        for (int i = 0; i < N;i++){
            for (int j = i + 1; j < N;j++){
                graph[past[i]][past[j]] = 1; // 모든 순위에 대해서 간선을 만들어 주자.
                indegree[past[j]]++;
            }
        }
        int m;
        cin >> m;
        for (int i = 0; i < m;i++){
            int u, v;
            cin >> u >> v;
            if(graph[u][v] == 1){
                graph[u][v] = 0;
                graph[v][u] = 1;
                indegree[v]--;
                indegree[u]++;
            }
            else{
                graph[u][v] = 1;
                graph[v][u] = 0;
                indegree[u]--;
                indegree[v]++;
            }
        }
        queue<int> q;
        vector<int> answer;
        for (int i = 1; i <= N; i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            if(q.size() >=2){ // 큐의 사이즈가 두개 이상이라면 즉 진입차수가 0 이 된 노드가 두개 이상이면 순위가 여러개가 나올 수 있다는 의미
                cout << "?\n";
                return 0;
            }
            int node = q.front();
            answer.push_back(node);
            q.pop();
            for (int i = 1; i <= N;i++){
                if(graph[node][i] == 1){
                    indegree[i]--;
                    if(indegree[i]==0)
                        q.push(i);
                }
            }
        }
        if(answer.size() < N){
            cout << "IMPOSSIBLE";
        }
        else{
            for(int num : answer)
                cout << num << " ";
        }
        cout << "\n";
    }
    return 0;
}