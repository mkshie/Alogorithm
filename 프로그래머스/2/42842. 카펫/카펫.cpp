#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
//#include <iostream>

using namespace std;

vector<pair<int,int>> arr;

void test(int x){
    int y = sqrt(x);
    for(int i=1;i<=y;i++){
        if(x%i ==0) arr.push_back({x/i , i});
    }
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    test(brown+yellow);
    for(int i=0;i<arr.size();i++){
        int x = arr[i].first;
        int y = arr[i].second;
        if((x+y)*2 - 4 == brown) {
            answer.push_back(x);
            answer.push_back(y);
            break;
            }
    }
    
    return answer;
}