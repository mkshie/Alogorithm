#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[1001][1001] = {0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        deque<int> card;
        for (int i = 0; i < N; i++)
        {
            int num;
            cin >> num;
            card.push_back(num);
        }
        int turn = N % 2;//turn 의 값이 짝수라면 즉 0 이라면 근우는 계속 짝수 
        //vector<vector<int>> dp(N, vector<int>(N, 0));
        //dp[i][j] == i ~ j 까지 카드가 있을때 A 의 최대 점수
        for (int len = 1; len <= N; ++len){
            for (int i = 0; i + len - 1 < N; ++i){
                int j = i + len - 1;
                if(turn == len % 2){ //근우의 차례
                    if(i==j)
                        dp[i][j] = card[i];
                    else{
                        dp[i][j] = max(dp[i + 1][j] + card[i], dp[i][j - 1] + card[j]); // 근우가 왼쪽을 뽑았으면 이후 명우가 오른쪽을 뽑기때문
                        //max(왼쪽을 선택했을 경우 , 오른쪽을 선택했을 경우) 즉 dp[i+1][j] => 명우가 선택하는 차례임
                    }
                }
                else{//명우의 차례
                    if(i==j)
                        dp[i][j] = 0;
                    else{
                        dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]); // 명우가 선택한건 점수에 포함되지 않음. 즉 이후 근우가 최소인 상태를 고르면 됨
                    }
                }
            }
        }
        cout << dp[0][N - 1] << "\n";
        memset(dp, 0, sizeof(dp));
    }
}