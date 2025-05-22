#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int dz[2] = {1, -1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N, H;
    cin >> M >> N >> H; // M 은 가로 N 은 세로 H 는 높이
    int tomato_num = 0;
    vector<vector<int>> tomato(H * N, vector<int>(M, 0));
    deque<pair<int, int>> dq;
    for (int i = 0; i < H * N; i++)
    {
        for (int j = 0; j < M;j++){
            int num;
            cin >> num;
            tomato[i][j] = num;
            if(num == 0){
                tomato_num++; // 익지 않은 토마토 개수 세기
            }
            if(num==1)
                dq.push_back({i, j}); // 익은 토마토의 위치 알아두기
        }
    }
    if (tomato_num == 0){
        cout << 0 << "\n"; // 익지않은 토마토가 없다면 0을 출력하고 종료
        return 0;
    }
    int day = 1;
    while (!dq.empty())
    {
        int y = dq.front().first;
        int x = dq.front().second;
        dq.pop_front();

        day = max(day, tomato[y][x]); // 최대값 day 구해주기

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            int cur_floor = y / N;
            int max_y = N + cur_floor * N;
            int min_y = cur_floor * N;

            if(ny >= N + cur_floor * N || ny < cur_floor * N || nx >= M || nx  < 0) // 경계값 검사
                continue;
            if (tomato[ny][nx] == 0)
            { // 다음 위치의 토마토가 익지 않았을경우
                tomato[ny][nx] = tomato[y][x] + 1;
                tomato_num--;
                dq.push_back({ny, nx}); // 삽입해주기
            }
        }
        if(H<2) continue;
        for (int i = 0; i < 2; i++) //상하도 처리해줘야함
        {
            int ny = y + N * dz[i]; //더하거나 빼거나
            int nx = x;
            if (ny >= H * N || ny < 0 || nx >= M || nx < 0) // 경계값 검사
                continue;
            if (tomato[ny][nx] == 0)
            { // 다음 위치의 토마토가 익지 않았을경우
                tomato[ny][nx] = tomato[y][x] + 1;
                tomato_num--;
                dq.push_back({ny, nx}); // 삽입해주기
            }
        }
    }
    if(tomato_num != 0){
        cout << -1 << "\n"; // 익지않은 토마토가 있다면 -1 출력하기
        return 0;
    }
    cout << day - 1<< "\n";
    return 0;
}