#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
vector<pair<int, int>> arr;
int dp[501][501] = {0};
int N;

int rec(int i , int j){
    if(i==j)
        return 0;
    if (dp[i][j] == 0)
    {// 처음 들어온 경우라면
        if(j - i == 1){ //차이가 1이 나는 경우라면 값 바로 구할 수 있음
            dp[i][j] = arr[i].first * arr[j].first * arr[j].second;
            return dp[i][j];
        }
        else{ // 차이가 2 이상이라면
            int cnt = j - i;
            for (int t = 0; t < cnt; t++){
                if(t==0){ // 첫번째 계산이라면 일단 넣어주기
                    dp[i][j] = rec(i,i+t) + rec(i + t + 1,j) + 
                        arr[i].first * arr[i+t+1].first * arr[j].second;
                }
                else{ //그다음부턴 계산해주기
                    dp[i][j] = min(dp[i][j],
                        rec(i, i + t) + rec(i + t + 1, j) + arr[i].first * arr[i+t+1].first * arr[j].second);
                }
            }
        }
    }
    else
        return dp[i][j];
    return dp[i][j];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int num1, num2;
        cin >> num1 >> num2;
        arr.push_back({num1, num2});
    }
    cout << rec(0, N-1) << "\n";
    return 0;
}