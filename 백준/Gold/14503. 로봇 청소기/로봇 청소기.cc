#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[50][50] = {0};
int dx[4] = {0, 1, 0, -1}; // 북 동 남 서
int dy[4] = {-1, 0, 1, 0}; 
int answer = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    int x, y, d;
    cin >> y >> x >> d; //초기 위치 , 바라보는 방향  0 북쪽 , 1 동쪽 , 2 남쪽 , 3 서쪽
    for (int i = 0; i < N;i++){
        for (int j = 0; j < M;j++){
            cin >> arr[i][j];
        }
    }

    while(true){
        // 1. 현재칸 청소하기
        if(arr[y][x] == 0){
            answer++;
            arr[y][x] = -1;
        }
        //2. 주변의 빈 칸 있는지 찾기
        bool che = false; // 초기값은 빈칸이 없는경우다
        for (int i = 0; i < 4; i++)
        {
            d = (d + 3) % 4;
            int ny = y + dy[d];
            int nx = x + dx[d];
            if(ny < 0 || nx < 0 || ny >= N || nx >= M){ //경계값 검사
                continue;
            }
            if(arr[ny][nx] == 1 || arr[ny][nx] == -1){ // 벽이거나 이미 청소한곳이라면
                continue;
            }
            if(arr[ny][nx] == 0){ // 청소할곳이 남아있다면
                y = ny;
                x = nx;
                che = true;
                break;
            }
        }
        if(!che){ //3. 빈칸이 없는 경우 후진하기
            int ny = y + dy[(d + 2) % 4];
            int nx = x + dx[(d + 2) % 4];
            if(arr[ny][nx] == 1){ // 후진할 수 없다면 작동 멈추기
                break;
            }
            y = ny;
            x = nx;
        }
    }
    cout << answer << "\n";
}
