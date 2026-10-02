#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//n 명이 줄 서서 대기중
// 모두 비어있고 하나에 한명씩 자리가 비어있어도 결과적으로 더 빨리 끝나는곳이 있으면 거기에서 심사
// 입국 심사를 기다리는 사람 수 n  한명이 심사하는데 걸리는 times 전체 간을 구한다면?

long long solution(int n, vector<int> times) {
    long long answer = 99999999999;
    
    //사람이 10억명 즉 그냥하면 안됨. 
    //시간을 기준으로 만족하는지 이분탐색
    //왜 시간 기다리는 조건이 의미가 없냐 어차피 최대를 구하는거기때문에
    
    long long left = 1; long long right = 1LL * *max_element(times.begin(), times.end()) * n;;
    
    while(left < right){
        long long mid = (left + right) / 2 ;
        
        long long sum_people = 0;
        for(int i =0; i< times.size(); i++){
            sum_people += mid / times[i];
        }
        
        //cout << sum_people << "\n";
        
        if(sum_people >= n){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    
    return answer = left;
}