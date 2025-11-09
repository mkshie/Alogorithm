#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = LLONG_MAX;
    
    //dp 로 해결하는 문제는 아닌 거 같음 , 그리디? 매 순간 최선을 다하면 되나.... 근데; w 에 채우는게
    // 남은 금양과 은양을 갖고 시간을 단축시켜 보자.
    long long left = 0 , right = 1e16;
    while(left <= right){
        
        long long mid = (left + right) / 2;
        long long gold = 0;
        long long silver = 0;
        long long weight = 0;
        
        for(int i =0 ; i < g.size(); i++){
            long long cnt = (mid + t[i]) / (t[i] * 2);
            
            gold += min(w[i] * cnt , (long long)g[i]);
            silver += min(w[i] * cnt , (long long)s[i]);
           // cout << "i : " << i << " silver : " << w[i] * cnt << " "<< s[i] <<"\n";
           // cout << silver<<"\n";
            weight += min(w[i] * cnt , (long long) (g[i] + s[i]));
            
        }
        
        if(weight >= a + b && gold >= a && silver >= b){
                answer = min(answer , mid);
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
    
    }

    return answer;
}