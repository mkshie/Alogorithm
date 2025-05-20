#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int T, K;
vector<int> arr;
int dp[501][501] = {0};
int sum[501] = {0};

int rec_dp(int i , int j){
    if (i == j)
        return 0; //하나만 있을때는 비용이 들지 않음
    if(dp[i][j] != 0) //이미 최솟값이 정해졌다는 의미
        return dp[i][j];
    else{
        if(j - i == 1){
            dp[i][j] = arr[i] + arr[j];
        }
        else{
            for (int t = i; t < j;t++){
                if(dp[i][j] == 0){
                    dp[i][j] = rec_dp(i, t) + rec_dp(t + 1, j) + sum[j] - sum[i - 1];
                }
                else{
                    int result = rec_dp(i, t) + rec_dp(t + 1, j) + sum[j] - sum[i - 1];
                    dp[i][j] = min(dp[i][j], result);
                }
            }
        }
    }
    return dp[i][j];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;

    while(T--){
        cin >> K;
        for (int i = 0; i < K;i++){
            int num;
            cin >> num;
            arr.push_back(num);
            if(i==0)
                sum[i] = num;
            else
                sum[i] = sum[i - 1] + num;
        }
        cout << rec_dp(0, K - 1) << "\n";
        memset(dp, 0, sizeof(dp));
        while(!arr.empty())
            arr.pop_back();
    }
}