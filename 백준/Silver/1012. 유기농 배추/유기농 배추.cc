#include <iostream>
#include <vector>

using namespace std;

int carbage_num = 0;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int M, N;
bool graph[50][50] = {false};

void bfs(int y , int x){
    graph[y][x] = false;

    for (int i = 0; i < 4;i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(nx < 0 || ny < 0 || nx >= M || ny >= N)
            continue;
        if(graph[ny][nx])
            bfs(ny, nx);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;

    cin >> T;
    while (T--)
    {
        cin >> M >> N >> carbage_num;
        for (int i = 0; i < carbage_num; i++)
        {
            int X, Y;
            cin >> X >> Y;
            graph[Y][X] = true; // 배추가 있는 자리
        }

        int bug_num = 0;
        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < M; x++){
                if(graph[y][x] == true){
                    bug_num++;
                    bfs(y, x);
                }
            }
        }

        cout << bug_num << "\n";
        for (int i = 0; i < N;i++)
            for (int j = 0; j < M;j++)
                graph[i][j] = false;
    }
}