#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int arr[1001] = {0};
int dp[1001] = {0};

//문제 목표 최대한 많은 돈을 지불해서 N개의 카드를 구매하려고 함

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N;i++){
        cin >> arr[i];
    }
    dp[1] = arr[1];
    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j < i;j++){
            dp[i] = max(arr[j] + arr[i - j], dp[i]);
        }
    }
    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            dp[i] = max(dp[j] + dp[i - j], dp[i]);
        }
    }
    cout << dp[N]<<"\n";
}