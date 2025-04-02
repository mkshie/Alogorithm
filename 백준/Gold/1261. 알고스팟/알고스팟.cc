#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int arr[101][101] = {-1};
int wall[101][101] = {0}; // 벽의 유무

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M; // N 이 가로 M 이 세로
    for (int y = 1; y <= M; y++){
        string str1;
        cin >> str1;
        for (int x = 0; x < N; x++)
        {
            wall[y][x+1] = str1[x] - '0';
        }
    }
    queue<pair<int, int>> q;
    memset(arr, -1, sizeof(arr));
    arr[1][1] = 0;
    q.push({1, 1});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        if(y == M && x == N) // 목적지에 도달한경우 탈출
            continue;
        for (int i = 0; i < 4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny <=0 || nx <=0 || ny > M || nx > N) // 경계값 검사
                continue;
            if(ny == 1 && nx == 1) continue;
            if(arr[ny][nx] == -1){ // 처음 도달한 곳이라면
                arr[ny][nx] = (wall[ny][nx] == 1) ? arr[y][x] + 1 : arr[y][x]; // 벽이 있다면 +1 아니라면 그냥 통과
                q.push({nx, ny});
            }
            else{ // 처음 도달한게 아니라면?
                int cnt = (wall[ny][nx] == 1) ? arr[y][x] + 1 : arr[y][x];
                if(cnt < arr[ny][nx]){ //벽을 더 적게 부셨다면
                    arr[ny][nx] = cnt;
                    q.push({nx, ny});
                }
            }
        }
    }
    cout << arr[M][N] << "\n";
    return 0;
}