#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <iostream>

using namespace std;

int answer = 0;

void dfs(int curNode , int w , int s , vector<int>nextNode , vector<int> info , vector<vector<int>> v){
    //먼저 늑대와 양의 개수 파악
    if(info[curNode] == 1)
        w++;
    else
        s++;
    
    if(w >= s) return; // 늑대가 양보다 많다면 버려줌
    
    answer = max(answer , s);
    
    for(int i = 0; i < nextNode.size(); i++){
        //모든 갈 수 있는 경우의 수를 다 해봐야함 돌아갈수도 있기때문
        //하지만 내 구현방식에서는 돌아가는것이아닌 갈 수 있는곳들을 전부 도는 방식
        vector<int> next = nextNode;
        next.erase(next.begin() + i); //가는곳을 지워서 nextNode 로 사용하기
        for(int j = 0; j < v[nextNode[i]].size(); j++){
            next.push_back(v[nextNode[i]][j]);
        }
        dfs(nextNode[i] , w , s , next , info , v);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {

    
    vector<vector<int>> v(info.size());
    for(int i = 0; i < edges.size(); i++)  // 돌아갈필요 없음 결국 내가 갈 수 있는곳 현재 node 가 어디있는지 신경안쓰고 갈거임
        v[edges[i][0]].push_back(edges[i][1]);
    
    vector<int> nextNode;
    for(int i = 0; i < v[0].size();i++)
        nextNode.push_back(v[0][i]);
    
    dfs(0,0,0,nextNode,info,v);
    
    return answer;
    
}

// cout << sheep <<" " << wolf << " " << cur;