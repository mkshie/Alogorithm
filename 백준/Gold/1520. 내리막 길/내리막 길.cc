#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int arr[501][501] = {0};
vector<pair<int, int>> course;
int dp[501][501] = {-1};
int M, N;

void dfs(int x, int y){
    if (y == M - 1 && x == N - 1)
    {
        return;
    }

    dp[y][x] = 0; // 방문 체크

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= N || ny >= M || nx < 0 || ny < 0) // 경게값 확인
            continue;
        if(arr[y][x] > arr[ny][nx]) // 내리막길이라면
        {
            if(dp[ny][nx] >= 0){ //방문한적 있다면
                dp[y][x] += dp[ny][nx];
                continue;
            }
            else{ // 방문한적 없다면
                dfs(nx, ny);
                dp[y][x] += dp[ny][nx];
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> M >> N; // 세로가 M  가로가 N
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N;j++){
            int num;
            cin >> num;
            arr[i][j] = num;
        }
    }
    memset(dp, -1, sizeof(dp));
    dp[M - 1][N - 1] = 1;
    dfs(0, 0);
    cout << dp[0][0] << "\n";
    return 0;
}