#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N, K;

long long num = 1000000000;

long long dp[201][201] = {0}; //dp[a][b] = a를 b개의 정수개로 만들 수 있는 경우의 수 dp[a][b] = dp[a][b-1] + dp[a-1][b-1] ... + dp[0][b-1] 과 같다.
long long sum = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for (int i = 0; i < 201;i++){
        dp[0][i] = 1;
        dp[i][1] = 1;
    }
    dp[1][1] = 1;
    for (int i = 1; i <= N;i++){
        for (int j = 2; j <= K;j++){
            for (int k = 0; k <= i;k++){
                dp[i][j] = (dp[i][j] + dp[k][j-1]) % num;
            }
        }
    }
    cout << dp[N][K] << "\n";
}