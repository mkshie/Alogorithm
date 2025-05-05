#include <iostream>
#include <algorithm>

using namespace std;

int N, M, K;
char arr[2001][2001];
int answer = 99999999;
int sumB[2001][2001] = {0}; //행 // 열
int sumW[2001][2001] = {0};

void cheB(char c){
    char start_char = c;
    for (int i = 1; i <= N; i++) // 행
    {
        char cur_char = start_char;
        int sum = 0;
        for (int j = 1; j <= M; j++)
        {
            if(arr[i][j] != cur_char){
                sumB[i][j]  += sum + sumB[i - 1][j]  + 1;
                sum++;
            }
            else{
                sumB[i][j]  = sum + sumB[i-1][j] ;
            }
            cur_char = (cur_char == 'B') ? 'W' : 'B';
        }
        start_char = (start_char == 'B') ? 'W' : 'B';
    }
}

void cheW(char c)
{
    char start_char = c;
    for (int i = 1; i <= N; i++) // 행
    {
        int sum = 0;
        char cur_char = start_char;
        for (int j = 1; j <= M; j++)
        {
            if (arr[i][j] != cur_char)
            {
                sumW[i][j]  += sum + sumW[i - 1][j]  + 1;
                sum++;
            }
            else
            {
                sumW[i][j]  = sum+ sumW[i-1][j] ;
            }
            cur_char = (cur_char == 'B') ? 'W' : 'B';
        }
        start_char = (start_char == 'B') ? 'W' : 'B';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K; // 행 열 체스판 크기
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M;j++){
            cin >> arr[i][j];
        }
    }
    if(K == 1){
        cout << "0";
        return 0;
    }
    cheB('B');
    cheW('W');
    for (int i = 1; i + K - 1 <= N;i++){
        for (int j = 1; j + K - 1 <= M;j++){
            int resultB = sumB[i-1][j-1]  + sumB[i-1+K][j-1+K]  - sumB[i-1][j+K-1]  - sumB[i-1+K][j-1] ;
            int resultW = sumW[i-1][j-1]  + sumW[i-1+K][j-1+K]  - sumW[i-1][j+K-1]  - sumW[i-1+K][j-1] ;
            resultB = min(resultB, resultW);
            answer = min(resultB, answer);
        }
    }

    cout << answer << "\n";
}