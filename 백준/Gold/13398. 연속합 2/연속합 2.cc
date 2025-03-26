#include <iostream>
#include <algorithm>
#include <vector>

//음수만 삭제하는 경우를 체크하면 문제를 풀 수 없음. 양수도 삭제하는 경우로 세야 모든 경우를 셀 수 있음

using namespace std;

int dp[100001][2] = {0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int answer = arr[0];
    dp[0][0] = arr[0];
    dp[0][1] = 0;
    for (int i = 1; i < n;i++){
        dp[i][0] = max(arr[i], dp[i - 1][0] + arr[i]);
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]); // 이번에 제거하는 경우 , 이전에 제거했을때의 최대값
        answer = max(answer , max(dp[i][0], dp[i][1]));
    }
        cout << answer << "\n";
    return 0;
}