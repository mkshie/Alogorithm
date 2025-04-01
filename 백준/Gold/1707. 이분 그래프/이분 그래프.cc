#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int K, V, E;
vector<int> arr[20001];
bool answer = false;
int visited[20001] = {0}; // 1 이 빨강 2가 파랑

void dfs(int num , int color){

    for (int next : arr[num])
    {
        if(answer)
            return;
        if (visited[next] == 0)
        {
            visited[next] = (color == 1) ? 2 : 1;
            dfs(next, (color == 1) ? 2 : 1 );
        }
        else if(visited[next] == color){ //next 가 방문한적이 있는데 만약 내 색깔과 같다면?
            answer = true;
            return;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> K;
    while(K--){
        cin >> V >> E;
        for (int i = 1; i <= V; i++)
        {
            arr[i].clear(); // 그래프 초기화
        }
        for (int i = 0; i < E;i++){
            int x, y;
            cin >> x >> y;
            arr[x].push_back(y);
            arr[y].push_back(x);
        }
        for (int i = 1; i <= V; i++)
        {
            if (visited[i] == 0)
            { // 방문하지 않은 노드라면
                visited[i] = 1;
                dfs(i, 1);
            }
        }
        if(!answer){
            cout << "YES\n";
        }
        else
            cout << "NO\n";
        answer = false;
        memset(visited, 0, sizeof(visited));
    }
    return 0;
}