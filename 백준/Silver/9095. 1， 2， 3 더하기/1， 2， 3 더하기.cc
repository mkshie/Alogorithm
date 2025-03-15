#include <iostream>
#include <vector>

using namespace std;
//dp 로 푸는 방식
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T, n;
    cin >> T;

    vector<int> dp(12, 0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i < 12; i++)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

    for (int i = 0; i < T; i++)
    {
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}

// 아래에는 내가 푼 방식 재귀로 품 N 과 M 풀이 방식과 유사

// int answer = 0;

// void check(int n){
//     for (int i = 1; i < 4;i++){
//         if(n - i > 0){
//             check(n - i);
//         }
//         else if(n - i == 0){
//             answer++;
//             return;
//         }
//         else{
//             return;
//         }
//     }   
// }

// int main(){
//     cin.tie(NULL);
//     ios::sync_with_stdio(false);
//     int T, n;
//     cin >> T;
//     while(T--){
//         cin >> n;
//         answer = 0;
//         check(n);
//         cout << answer << "\n";
//     }
// }
