#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E;
    cin >> V >> E;
    vector<vector<int>> graph(V + 1, vector<int>(V + 1, INF));
    // for (int i = 1; i <= V;i++){
    //     graph[i][i] = 0;
    // }
    for (int i = 0; i < E;i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }

    int answer = INF;

    for (int k = 1; k <= V;k++){
        for (int i = 1; i <= V;i++){
            for (int j = 1; j <= V;j++) // 플로이드 워셜 알고리즘수행
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
        }
    }

    for (int i = 1; i <= V;i++){
        // for (int j = 1; j <= V;j++){
        //     if(i==j) continue;
        //     if(graph[i][j] != INF && graph[j][i] != INF){
        //         answer = min(answer, graph[i][j] + graph[j][i]);
        //     }
        // }
        if (graph[i][i] < answer)
        {
            answer = graph[i][i];
        }
    }
    if(answer ==INF)
        cout << "-1\n";
    else{
        cout << answer << "\n";
    }
    return 0;
}