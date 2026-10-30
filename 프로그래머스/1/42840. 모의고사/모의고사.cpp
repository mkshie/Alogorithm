#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    vector<int> a1 = {1,2,3,4,5};
    vector<int> a2 = {2,1,2,3,2,4,2,5};
    vector<int> a3 = {3,3,1,1,2,2,4,4,5,5};
    
    int cnt1 =0,cnt2 =0,cnt3=0;
    
    for(int i=0;i<answers.size();++i){
        if(a1[i%a1.size()]==answers[i]) cnt1++;
        if(a2[i%a2.size()]==answers[i]) cnt2++;
        if(a3[i%a3.size()]==answers[i]) cnt3++;
    }
    int max_num = 0;
    max_num = max(cnt1,max(cnt2,cnt3));
    if(max_num == cnt1) answer.push_back(1);
    if(max_num == cnt2) answer.push_back(2);
    if(max_num == cnt3) answer.push_back(3);
    return answer;

}