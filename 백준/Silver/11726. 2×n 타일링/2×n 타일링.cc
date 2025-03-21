#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

//알고보니 피보나치 수열임

bool arr[2][1001] = {false};
int dp[1001] = {0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for (int i = 4; i <= N; i++){
        dp[i] = (dp[i - 2] + dp[i - 1]) % 10007;
    }
    cout << dp[N] << "\n";
}