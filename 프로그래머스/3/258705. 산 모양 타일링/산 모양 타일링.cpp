#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> dp;

const int MOD = 10007;

int solution(int n, vector<int> tops) {
    int answer = 0;
    
    dp = vector<vector<int>> (n , vector<int> (4,0));
    dp[0][0] = dp[0][1] = dp[0][2] = 1;
    //0 삼각형 1 왼 2 오 3 위
    
    if(tops[0] == 1) dp[0][3] = 1;
    
    for(int i = 1 ; i < n ; i ++){
        dp[i][0] = (dp[i][0] + dp[i-1][0] + dp[i-1][1] + dp[i-1][2] + dp[i-1][3]) % MOD;
        dp[i][1] = (dp[i][1] + dp[i-1][0] + dp[i-1][1] + dp[i-1][3] ) % MOD;
        dp[i][2] = dp[i][0];
        if(tops[i] == 1){
            dp[i][3] = dp[i][0];
        }
        else{
            dp[i][3] = 0;
        }
    }
    
    for(int num : dp[n-1])
        answer = (answer + num) % MOD;
    
    return answer;
}