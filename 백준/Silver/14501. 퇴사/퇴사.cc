#include <iostream>
//#include <vector>
#include <algorithm>

//dp 개념으로 푼 문제
//그림으로 해당 배열에 어떤값이 들어가면 문제가 해결되는지 그리니 생각보다 쉽게 풀렸다.

using namespace std;

int N;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    vector<pair<int, int>> arr(16, {0, 0}); // 날짜 , 돈
    for (int i = 1; i <= N;i++){
        cin >> arr[i].first >> arr[i].second;
    }
    //vector<vector<int>> dp(16, vector<int>(16, 0));
    vector<int> dp(17, 0);
    for (int i = 1; i <= N; i++)
    {
        dp[i + 1] = max(dp[i + 1], dp[i]);
        if (i + arr[i].first <= N + 1)
        {
            int num = dp[i] + arr[i].second;
            dp[i + arr[i].first] = max(dp[i + arr[i].first], num);
        }
        else{
            dp[N + 1] = max(dp[N + 1], dp[i]);
        }
    }

    cout << dp[N + 1] << "\n";
}