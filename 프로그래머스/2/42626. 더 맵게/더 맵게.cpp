#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>


using namespace std;

// 모든 스코빌 지수를 K 이상으로 만들고 싶음
// 가장 낮은애 + 두번째로 낮은애 * 2 = 섞은 음식

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int , vector<int> , greater<int>> pq;
    for(int i : scoville){
        pq.push(i);
    }
    
    // while(!pq.empty()){
    //     cout << pq.top() << " ";
    //     pq.pop();
    // }
    
    while(!pq.empty()){
        //queue 가 다 없어질때까지
        
        if(pq.top()>= K) break;
        
        if(pq.size() == 1 && pq.top() < K){ //만들 수 없음
            return -1;
        } 
        
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        
        pq.push(first + second * 2);
        answer++;
    }
    return answer;
}