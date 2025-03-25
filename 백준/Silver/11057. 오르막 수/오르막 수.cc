#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int mod = 10007;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    long long dp[1001][10] = {0};
    for (int i = 1; i < 1001;i++){
        dp[i][0] = 1;
    }
    for (int i = 0; i < 10;i++){
        dp[1][i] = 1;
    }
    for (int i = 2; i <= N;i++){
        for (int j = 1; j < 10;j++){
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod; // dp[i][j] = 왼쪽 + 위쪽 dp 의 합과 같음 
        }
    }
    long long answer = 0;
    for (int i = 0; i < 10;i++)
        answer = (answer + dp[N][i]) % mod;
    cout << answer << "\n";
}