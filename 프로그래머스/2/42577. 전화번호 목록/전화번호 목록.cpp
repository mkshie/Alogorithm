#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;

//풀었던 문제인데 기억이 안나네;
//그냥 이정도 복잡도면 흠.. index 0 에 있는애들 이게 순서는 상관없는 거 같음
//먼저 자기 전체를 넣어서 있는지 확인 후에 없으면 자기 자신을 크기순으로 잘게 잘라서 넣음
//이거 반복하면 될듯?

//처음에 간과한점 set 의 find 는 정렬형태라서 O(log N) 의 복잡도 즉 잦은 find 는 unordered_set 사용해야함

bool solution(vector<string> phone_book) {
    bool answer;
    
    unordered_set<string> s;
    //그냥 먼저 set 에 다 넣고 이후에 하나씩 쪼개서 찾아볼까..?
    
    //sort(phone_book.rbegin() , phone_book.rend());
    
    for(string& str : phone_book){
        s.insert(str);
    }
    
    for(string& str : phone_book){
        string cp ="";
        for(int i=0; i<str.size();i++){
            cp += str[i];
            
            if(cp != str && s.find(cp) != s.end()){
                answer = false;
                return answer;
            }
            
        }
        
    }
    
    answer = true;
    
    return answer;
}