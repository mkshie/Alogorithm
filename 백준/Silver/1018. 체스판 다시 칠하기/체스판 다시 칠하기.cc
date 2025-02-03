#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>

// 체스판 다시 칠하기 문제
// 규칙을 어기는 애들을 1 아닌 애들을 0 으로 두기
// 이후 모든 경우의 수를 찾아가면서 답을 구하기

using namespace std;

//체스판이 나올 수 있는 경우의 수는 두가지 방식뿐
//두가지 경우에서 제일 적은 상황이 정답
string WB[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"};
string BW[8] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"};

int N, M; // N 이 세로 M 이 가로
string arr[50]; // N 이 행 M 이 열
int cnt_BW(int x, int y){
    int cnt = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8;j++){
            if(BW[i][j] != arr[i+x][j+y])
                cnt++;
        }
    }
    return cnt;
}

int cnt_WB(int x,int y){
    int cnt = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (WB[i][j] != arr[i + x][j + y])
                cnt++;
        }
    }
    return cnt;
}

    int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int answer = 64;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < N - 7;i++){
        for (int j = 0; j < M - 7;j++){
            int tmp = min(cnt_BW(i, j), cnt_WB(i, j));
            if(tmp <= answer)
                answer = tmp;
        }
    }
    cout << answer << "\n";
    return 0;
}