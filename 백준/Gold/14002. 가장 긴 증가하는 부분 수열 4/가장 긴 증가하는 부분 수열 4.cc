#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;
    vector<int> arr;
    vector<vector<int>> answer(N);
    for (int i = 0; i < N;i++){
        int num;
        cin >> num;
        arr.push_back(num);
        answer[i].push_back(num);
    }
    vector<int> dp(N, 1);
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++){
            if(arr[i] > arr[j]){
                if(dp[i] < dp[j]+1){ // 실제로 커서 바껴야 된다면??
                    answer[i] = answer[j];
                    answer[i].push_back(arr[i]);
                }
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int answer_max = 0;
    int idx = 0;
    for (int i = 0; i < N; i++)
    {
        if(answer_max < dp[i]){
            answer_max = dp[i];
            idx = i;
        }
    }
    cout << answer_max << "\n";
    for (int i = 0; i < answer[idx].size(); i++)
    {
        cout << answer[idx][i] << " ";
    }
    cout << "\n";
}