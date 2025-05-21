#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define offset 40000

//문제가 생각보다 어려웠다. 음수를 표현하기 위해 offset 을 두고 시작을하려고 했지만 한쪽을 기준으로 두고 절댓값으로 값을 표현하게 되면 문제를 쉽게
//해결할 수 있다. 또한 경우의 수가 세가지로 나뉜다고 해도 가방문제에서는 상관이 없었다. 해당 문제에서는 가방의 무게가 중요하지 않다. 왜냐하면
//만들 수 있냐 없냐를 따지는 문제이기때문에 즉 가방에 얼마나 많이 넣냐 문제에선 무게의 최대값이 존재하기 때문에 그 안에서 처리를 해야했지만
//이 문제는 무게를 만들 수 있냐 문제이기때문에 왼쪽 추에 놓던지 아니면 오른쪽 추에 놓던지 사용하지 않던지 이 세가지 경우만 추론해주면 된다.

bool dp[31][offset+1] = {false};
int weghit[31] = {0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T, N;
    cin >> T;
    for (int i = 1; i <= T;i++){
        int num;
        cin >> num;
        weghit[i] = num;
    }
    dp[0][0] = true;
    for (int i = 1; i <= T; i++)
    {
        int we = weghit[i];
        for (int w = 0; w <= offset; w++)
        {
            if(dp[i-1][w]){ // 이전에 사용한 추의 무게가 true 인 경우
                dp[i][w] = true; // 사용하지 않는 경우
                dp[i][w + we] = true; // 오른쪽에 둬서 무게가 증가한 경우
                dp[i][abs(w - we)] = true; // 왼쪽에 둬서 무게가 감소했지만 음수라면 절댓값으로 저장
            }
        }
    }
    cin >> N;
    for (int i = 0; i < N;i++){
        int num;
        cin >> num;
        if(dp[T][num])
            cout << "Y ";
        else
            cout << "N ";
    }
    return 0;
}