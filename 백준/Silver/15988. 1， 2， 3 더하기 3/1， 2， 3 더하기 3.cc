#include <iostream>
#include <vector>

using namespace std;

// dp 로 푸는 방식

long long num = 1000000009;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T, n;
    cin >> T;
    
    vector<long long> dp(10000001, 0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i < 1000001; i++)
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3])%num;

    for (int i = 0; i < T; i++)
    {
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}