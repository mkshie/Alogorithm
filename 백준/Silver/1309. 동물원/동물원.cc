#include <iostream>
#include <algorithm>

using namespace std;

int num = 9901;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;

    int dp[100001][2] = {0};
    dp[1][0] = dp[1][1] = 1;
    dp[2][0] = 3;
    dp[2][1] = 2;
    for (int i = 3; i <= N;i++){
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] * 2)%num;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % num;
    }
    cout << (dp[N][0] + dp[N][1] * 2) % num << "\n";
    return 0;
}