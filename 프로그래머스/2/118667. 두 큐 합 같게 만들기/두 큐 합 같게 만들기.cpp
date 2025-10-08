#include <string>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//먼저 되는지 확인부터

vector<int> all_que;
long half_num = 0;
bool che = false;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;

    long sum  = 0;
    long left_sum = 0 , right_sum = 0;
    queue<int> queue3 , queue4;

    for(int num : queue1){
        all_que.push_back(num);
        queue3.push(num);
        left_sum += num;
        sum += num;
    }
    for(int num : queue2){
        all_que.push_back(num);
        queue4.push(num);
        right_sum +=num;
        sum += num;
    }
    half_num = sum / 2;
    
    if(sum % 2 != 0) return -1; // 합이 홀수라면 만들 수 없음
    if(left_sum == right_sum) return 0;
    
    int maxCal = queue1.size() * 3;
    int cnt = 0;
    while(cnt <= maxCal){
        int num;
        if(left_sum > half_num){
            num = queue3.front();
            queue3.pop();
            queue4.push(num);
            left_sum -= num;
            right_sum += num;
        }
        else{
            num = queue4.front();
            queue4.pop();
            queue3.push(num);
            left_sum += num;
            right_sum -= num;
        }
        cnt++;
        if(left_sum == half_num)
            return cnt;
    }
    return -1;
}
