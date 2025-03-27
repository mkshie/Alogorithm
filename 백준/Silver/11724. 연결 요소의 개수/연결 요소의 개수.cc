#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M; // 정점의 개수 , 간선의 개수
vector<vector<int>> arr;
vector<bool> visited; // false 가 아직 도달하지 않은 곳.
int answer = 0;

void bfs(int start){
    if(!visited[start]){
        visited[start] = true;
        for (int i = 1; i <= N;i++){
            if(arr[start][i] != 0){ // 갈 수 있다면?
                bfs(i);
            }
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    arr = vector<vector<int>> (N + 1, vector<int>(N + 1, 0));
    visited = vector<bool>(N + 1, false);
    for (int i = 1; i <= M; i++)
    {
        int one, two;
        cin >> one >> two;
        arr[one][two] = 1;
        arr[two][one] = 1;
    }
    for (int i = 1; i <= N;i++){
        if(!visited[i])
        {
            bfs(i);
            answer++;
        }
    }
    cout << answer << "\n";
}