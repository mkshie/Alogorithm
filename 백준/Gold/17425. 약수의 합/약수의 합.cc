#include <iostream>

using namespace std;

long long int dp[1000001] = {0};
// 에라토스테네스의 체의 개념을 이용해서 푸는 문제
// 단순 계산으로는 너무 많은 계산이 소요.
// 즉 dp 를 사용해서 미리 계산해둬야함
// 원리는 1의 배수라면 모두 체크 2의 배수라면 모두 체크 3의 배수라면 모두 체크와 같은 방식으로 진행..
int main(){
    cin.tie(NULL);
    int N;
    cin >> N;
    for (int i = 1; i < 1000001; i++){
        for (int j = 1; j * i < 1000001;j++){
            dp[i * j] += i;
        }
        dp[i] += dp[i - 1];
    }
    while (N--){
        int T;
        cin >> T;
        cout << dp[T] << "\n";
    }
    return 0;
}