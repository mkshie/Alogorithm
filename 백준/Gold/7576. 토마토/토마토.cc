#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int M, N;
queue<pair<int, int>> q;
int arr[1001][1001] = {0};
int dx[4] = {1, 0, -1, 0}; // 열
int dy[4] = {0, 1, 0, -1}; // 행
int cnt = 0;
int day = 0;
int total_cnt;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M; //y 가 M 이고 x 는 N
    total_cnt = N * M;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N;j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1){
                cnt++;
                q.push({i, j}); //익은 토마토들의 위치는 알아두기
            }
            else if(arr[i][j] == -1)
                total_cnt--;
        }
    }
    if(cnt == total_cnt)
    { // 처음부터 모든 토마토가 익어있으면 return
        cout << 0 << "\n";
        return 0;
    }
    day = 0;
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        day = max(day, arr[y][x]);
        q.pop();
        for (int i = 0; i < 4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M){ // 범위 값 검사
                continue;
            }
            if(arr[ny][nx] >= 1 || arr[ny][nx] == -1) // 이미 익었거나 해당 자리에 토마토가 없는 경우 패스
                continue;
            else{
                arr[ny][nx] = arr[y][x] + 1;
                q.push({ny, nx});
                cnt++;
            }
        }
    }
    if(cnt == total_cnt){
        cout << day - 1 << "\n";
    }
    else{
        cout << -1 << "\n";
    }
    return 0;
}