#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int arr[1001] = {0}, dp[1001] = {0};
    for (int i = 1; i <= N; ++i)
    {
        cin >> arr[i];
        dp[i] = arr[i];
    }
    dp[2] = min(dp[1] * 2, dp[2]);
    for (int i = 3; i <= N; i++){
        for (int j = 0; j < i; j++){
            dp[i] = min(dp[j] + dp[i - j], dp[i]);
        }
    }
    cout << dp[N] << "\n";
}