#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 야간 아르바이트
//5원을 거슬러줌 , 1 , 2 ,5 원 존재
//1 원 다섯번
//1원 세번 , 2원 1번
// 1원 1번 2 원 두번
// 5원 한번

const int MODNUM = 1000000007;
int answer = 0;
//작은것부터 채워나가는게 맞음 
// 100,000 을 만드는 방식을 dp 로 저장해서 했던 기억이 남

vector<int> dp(100001 , 0); //dp[i] = 해당 금액을 만들 수 있는 방법


int solution(int n, vector<int> money) {
    
    sort(money.begin() , money.end());
    auto it = upper_bound(money.begin() , money.end() , n); 
    //만약 금액보다 큰 화폐가 존재한다면 지우기
    if(it != money.end()){
        money.erase(remove_if(money.begin() , money.end() , [n](int num) { return num > n;}),money.end());
    }
    
    dp[0] = 1;
    
    for(int num : money){
        for(int i = 1; i <= n ; i ++){
            if(i - num < 0) continue;
            dp[i] += dp[i - num];
        }
    }
    
    answer = dp[n];
    
    return answer;
}