#include <string>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <unordered_map>

//철수는 롤케이크를 잘라서 나눠먹으려고함.
//롤케이크 크기보다 토핑의 종류가 핵심
//먹는 종류의 개수가 같아야함...


//map 으로 해보자.
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    unordered_map<int,int> left;
    unordered_map<int,int> right;
    
    //먼저 right 에 모든값들을 넣어주자.
    
    for(int i : topping){
        right[i]++;
    }
    
    for(int i = 0; i < topping.size(); i++){
        
        left[topping[i]]++;
        
        if(right.find(topping[i]) != right.end()){
            right[topping[i]]--;
            
            if(right[topping[i]] == 0) right.erase(topping[i]);
        }
        
        if(left.size() == right.size()){ // 서로의 가짓수가 같으면 더해주자
            answer++;
        }
    }
    
    return answer;
}