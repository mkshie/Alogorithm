#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//문제 자체는 dfs 방식으로 푸는게 더 코드상에서 편해보임
//끝까지 들어갔을때 값이 맞다면... 되는것 지금 문에서는 음.. 2^20 1024 * 1024 니까 충분함
int answer = 0;

void dfs(vector<int> &num , int sum , int idx , int target){
    if(idx == num.size()){
        if(sum ==target) answer++; //결과가 같으면 answer++
    }
    else{
        for(int i=0;i<2;i++){
            sum = sum + ( i == 0 ? num[idx] : -1 * num[idx]);
            dfs(num , sum , idx+1 , target);
            sum = sum - ( i == 0 ? num[idx] : -1 * num[idx]);
        }
    }
}


int solution(vector<int> numbers, int target) {
    
    dfs(numbers , 0 , 0 , target);
    return answer;
}