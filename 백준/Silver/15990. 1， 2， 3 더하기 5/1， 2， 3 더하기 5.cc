#include <iostream>
#include <vector>

using namespace std;

//vector<vector<long int>> arr(100001, vector<int>(4, 0));
long long int arr[100001][4] = {{0}};
int dp[100001] = {0};
long long int num = 1000000009;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    arr[1][1] = 1;
    arr[2][2] = 1;
    arr[3][1] = arr[3][2] = arr[3][3] = 1; //arr[3][0] 의 맨 오른쪽 숫자들이 어떻게 포진되어 있는지 나타낸 배열
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 3;
    for (int i = 4; i < 100001;i++){
        for (int j = 1; j < 4; j++){
            for (int k = 1; k < 4;k++){
                if(k != j)
                {
                    arr[i][j] += arr[i - j][k];
                    arr[i][j] = arr[i][j] % num;
                }
            }
        }
    }
    while (T--)
    {
        int n;
        cin >> n;
        cout << (arr[n][1] + arr[n][2] + arr[n][3])%num << "\n";
    }
    return 0;
}