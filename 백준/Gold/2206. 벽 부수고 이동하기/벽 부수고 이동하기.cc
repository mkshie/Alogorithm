#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

int N, M;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    vector<vector<int>> graph(N+1,vector<int>(M+1,0)); //내가 지금 방문한곳은 -1 벽을 부순상태라면 방문한곳을 -2 로 표기
    int visited[1001][1001][2] = {0};
    for (int i = 1; i <= N; i++)
    {
        string str1;
        cin >> str1;
        for (int j = 1; j <= M; j++)
        {
            graph[i][j] = str1[j-1] - '0';
        }
    }
    queue<tuple<int, int,int>> pq;
    pq.push({1, 1, 0});
    visited[1][1][0] = 1; // 1,1 에 거리 1
    while (!pq.empty())
    {
        auto [y, x, broken] = pq.front();
        pq.pop();
        if (y == N && x == M)
            break;
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny > N || nx > M || ny < 1 || nx < 1)
                continue;
            if(graph[ny][nx] == 0 && visited[ny][nx][broken] == 0){ //벽이 아닌 길이라면 그냥 진행(대신 방문한적 없어야함)
                visited[ny][nx][broken] = visited[y][x][broken] + 1;
                pq.push({ny, nx, broken});
            }
            else if (graph[ny][nx] == 1 && broken == 0 && visited [ny][nx][1] == 0) // 벽이고 내가 벽을 뚫은적 없고 방문한적없어야함
            {
                visited[ny][nx][1] = visited[y][x][broken] + 1;
                pq.push({ny, nx, 1});
            }
        }
    }
    if(visited[N][M][0] != 0 || visited[N][M][1] != 0){ // 둘중하나라도 도착했다면
        if(visited[N][M][0] == 0)
          cout << visited[N][M][1] << "\n";
        else if(visited[N][M][1] == 0)
            cout << visited[N][M][0] << "\n";
        else
            cout << min(visited[N][M][0], visited[N][M][1]) << "\n";
    }
    else{ // 둘다 0인경우
        cout << "-1\n";
    }
    return 0;
}