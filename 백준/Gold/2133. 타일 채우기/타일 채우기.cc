#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;

    long long dp[31] = {0};
    dp[0] = 1;
    dp[2] = 3;
    dp[3] = 0;
    dp[4] = 11;
    dp[6] = 41;

    for (int i = 4; i <= N;i++){
        if(i % 2 != 0) continue;
        dp[i] = dp[i - 2] * 3;
        for (int j = 4; i - j >= 0; j = j+ 2){
            dp[i] += dp[i - j] * 2;
        }
    }

    cout << dp[N] << "\n";
    return 0;
}