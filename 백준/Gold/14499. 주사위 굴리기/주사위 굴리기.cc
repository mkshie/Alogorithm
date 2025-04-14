#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dice[4][3] = {0};
int dx[5] = {0,1, -1, 0, 0};
int dy[5] = {0,0, 0, -1, 1};

void mov_dice(int num){ //1 동 2 서 3 북 4 남
    int copy_num;
    if (num == 1)
    {
        copy_num = dice[3][1];
        dice[3][1] = dice[1][2];
        dice[1][2] = dice[1][1];
        dice[1][1] = dice[1][0];
        dice[1][0] = copy_num;
    }
    else if(num == 2){
        copy_num = dice[3][1];
        dice[3][1] = dice[1][0];
        dice[1][0] = dice[1][1];
        dice[1][1] = dice[1][2];
        dice[1][2] = copy_num;
    }
    else if(num == 3){
        copy_num = dice[3][1];
        dice[3][1] = dice[0][1];
        dice[0][1] = dice[1][1];
        dice[1][1] = dice[2][1];
        dice[2][1] = copy_num;
    }
    else
    {
        copy_num = dice[3][1];
        dice[3][1] = dice[2][1];
        dice[2][1] = dice[1][1];
        dice[1][1] = dice[0][1];
        dice[0][1] = copy_num;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    int x, y;
    int K; // 명령의 개수
    cin >> N >> M;
    vector<vector<int>> arr(N, vector<int>(M, 0));
    cin >> y >> x;
    cin >> K;
    for (int i = 0; i < N;i++){
        for (int j = 0; j < M;j++){
            int num;
            cin >> num;
            arr[i][j] = num;
        }
    }
    while(K--){
        //1단계 현재 위치에서 이동해도 괜찮은지를 파악
        int order;
        cin >> order;
        int nx = x + dx[order];
        int ny = y + dy[order];
        if(nx < 0 || ny < 0 || nx >= M || ny >= N){ // 만약 범위를 넘어선다면
            continue;
        }
        //2단계 주사위의 위치를 수정
        mov_dice(order);
        //3단계 주사위의 맨 아랫면과 지도의 값을 비교해 값을 수정
        if(arr[ny][nx] == 0){
            arr[ny][nx] = dice[3][1];
        }
        else{
            dice[3][1] = arr[ny][nx];
            arr[ny][nx] = 0;
        }
        y = ny;
        x = nx;
        cout << dice[1][1] << "\n";
    }
    return 0;
}