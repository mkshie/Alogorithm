#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

vector<vector<int>> arr;
vector<vector<bool>> che;

//뭐가 정석 방법인지는 모르겠음
//일단 브루트 포스로 모든 경우의 수를 다 돌아서 확인
//if 문을 통해서 경계범위를 체크 , 이전에 넣었던 정사각형이라면 들어가지 못하게 설정

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
int N, M;
int answer = 0;

void rec_tetris(int x,int y,int size,int sum){
    if(size == 4){
        answer = max(sum, answer);
        return;
    }
    for (int i = 0; i < 4;i++){
        che[y][x] = false;
        if(y+dy[i] >=0 && y+dy[i]<N && x+dx[i] >=0 && x+dx[i]<M && che[y+dy[i]][x+dx[i]])
            rec_tetris(x + dx[i], y + dy[i], size + 1, sum + arr[y+dy[i]][x+dx[i]]);
        che[y][x] = true;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    arr = vector<vector<int>>(N, vector<int>(M, 0)); // N행 M열이고 초기값이 0 인 벡터 생성
    che = vector<vector<bool>>(N, vector<bool>(M, true));
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            cin >> arr[y][x];
        }
    }
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M;x++){
            rec_tetris(x,y,0,0);
        }
    }
    for (int y = 0; y < N;y++){
        for (int x = 0; x < M;x++){
            for (int i = 0; i < 4; i++)
            {
                int sum = arr[y][x];
                for (int j = 0; j < 4;j++){
                    if(i==j) continue;
                    int ny = y + dy[j];
                    int nx = x + dx[j];
                    if(ny >=0 && ny < N && nx >=0 && nx < M)
                        sum += arr[ny][nx];
                }
                answer = max(answer, sum);
            }
        }
    }
        cout << answer << "\n";
}