#include <string>
#include <vector>
#include <set>

using namespace std;

bool solution(vector<string> phone_book) {
    set<string> s;
    for(string str : phone_book){
        s.insert(str);
    }
    for(auto it = s.begin(); it != s.end();it++){
        string cur_str = *it; //현재 원소
        auto next_it = next(it); // 다음 원소
        if(next_it != s.end()){
            string next_str = *next_it;
            if(cur_str.compare(next_str.substr(0,cur_str.size()))==0)
            {
                return false;
            }
        }
    }
    bool answer = true;
    return answer;
}