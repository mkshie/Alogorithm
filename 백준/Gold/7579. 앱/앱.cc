#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//헷갈리다면 배낭문제를 다시 풀어보자

int N, M; // N 은 활성화 되어있는 앱의 수 , M 은 확보애햐나는 메모리양
int weight[101] = {0};
int value[101] = {0};
int dp[101][10001] = {0};




int main()
{
    int sum = 0;
    cin >> N >> M;
    for (int i = 1; i <= N;i++){
        int num;
        cin >> num;
        weight[i] = num;
    }
    for (int i = 1; i <= N; i++)
    {
        int num;
        cin >> num;
        value[i] = num;
        sum += num;
    }
    vector<int> arr;
    for (int i = 1; i <= N; i++)
    {
        for (int w = 0; w <=sum; w++){
            if(w < value[i]) // 현재 메모리 최대값 보다 메모리가 높다면 pass
            {
                dp[i][w] = dp[i - 1][w];
            }
            else if(w >= value[i]){
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - value[i]] + weight[i]);
            }
            if(dp[i][w] >= M){
                arr.push_back(w);
            }
        }
    }
    sort(arr.begin(), arr.end());
    cout << arr[0] << "\n";
    return 0;
}