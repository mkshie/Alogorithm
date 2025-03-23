#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
vector<int> dp(100001, 9999);

int rec(int n){
    if(dp[n] == 9999){ // 아직 답을 모른다면?
        if(sqrt(n) == int(sqrt(n))) // 만약 제곱근이 정수라면
        {
            dp[n] = 1;
            return dp[n];
        }
        int num = sqrt(n);
        for (int i = 1; i <= num; i++){
            dp[n] = min(dp[n],dp[i*i] + rec(n - i*i));
        }
    }
    return dp[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    //memset(dp, -1, sizeof(dp));
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 1;
    cout << rec(N) << "\n";
}