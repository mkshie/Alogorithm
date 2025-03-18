#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//여러가지 시행착오가 많았던 문제
//1. 최대값을 구하라해서 초기값을 0 으로 잡았지만 음수가 최대가 되는 경우 존재
//2. 방문여부 체크시 bool 배열을 이용함으로 만약 두번 방문한곳이라면 값이 뒤바뀌게되는 경우가 존재.

int N, M, K;
int mv_x[5] = {0, 1, 0, -1, 0};
int mv_y[5] = {0, 0, -1, 0, 1};
vector<vector<int>> arr;
vector<vector<int>> visitt; // 방문하면 true
long long int answer = -999999999;
long long int sum = 0;

void visit_check(int x , int y ,int value){
    for (int i = 0; i < 5; i++)
    {
        if (y + mv_y[i] >= 0 && y + mv_y[i] < N && x + mv_x[i] >= 0 && x + mv_x[i] < M)
        { // 경계 검사
            visitt[y + mv_y[i]][x + mv_x[i]] += value;
        }
    }
}

void rec(int dx , int dy , int size){
    if(size == K){
        answer = max(answer, sum);
        return;
    }

    for (int y = dy; y < N;y++){
        for (int x = dx; x < M;x++){
            if(visitt[y][x] != 0) // 인접했거나 이미 넣었던 곳이라면
                continue;
            sum += arr[y][x];
            visit_check(x, y, 1);
            if (x == M - 1)
            {
                rec(0, y + 1, size + 1);
            }
            else{
                rec(x + 1, y, size + 1);
            }
            //rec(0, y, size + 1);
            visit_check(x, y, -1);
            sum -= arr[y][x];
        }
        dx = 0;
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    arr = vector<vector<int>>(N, vector<int>(M, 0));
    visitt = vector<vector<int>>(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M;j++){
            cin >> arr[i][j];
        }
    }
    rec(0, 0, 0);
    cout << answer << "\n";
    return 0;
}