#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

//한번에 하나의 알파벳만 수정 가능함.
//일단 target 이 vecotr 에 있는지 확인해야함
//인접배열 리스트로 가야하나? 갈 수 있는길이 map 사용해서 넣어야하나..? key -> value 로?
//어떤식으로 그래프를 만들어야하지? , 일단 모두 다 체크해본다고 가정하면
// 26 ^ n * m 인데 너무 커짐
// 그럼 갈 수 있는곳을 미리 정렬해둬야함 map 형식이 맞는듯 key -> value 형식으로
// 그리고 bfs 돌리자

//한글자 다른건 하나씩 다 해봐야할듯

unordered_map<string , vector<string>> graph;
unordered_map<string ,bool> visited;

bool oneCharDiff(const string& str1 , const string& str2){
    
    int diff = 0;
    for(int i=0; i< str1.size(); i++){
        if(str1[i] != str2[i]){
            diff++;
        }
        
        if(diff >= 2) return false;
    }
    return diff == 1;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    //먼저 target 이 있는지 찾자
    words.push_back(begin);
    
    if(find(words.begin() , words.end() , target) == words.end()){
        return answer;
    }
    
    // map 에 그래프 생성하기
    for(int i = 0 ; i< words.size() ; i++){
        for(int j =0; j < words.size(); j++){
            if(i == j ) continue;
            
            if(oneCharDiff(words[i] , words[j])){ // 갈 수 있다면
                graph[words[i]].push_back(words[j]); // 갈 수 있다고 표시
            }
        }
    }
    
    
    queue<pair<string , int>> q;
    
    q.push({begin , 0});
    visited[begin] = true;
    
    while(!q.empty()){
        string str = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(str == target){
            answer = cnt;
            break;
        }
        
        const vector<string> & next_nodes = graph[str];
        
        for(const string& next_node : next_nodes){
            //갈 수 있는지 확인하자.
            
            if(!visited[next_node]){ // 갈 수 있다면 go
                visited[next_node] = true;
                q.push({next_node , cnt + 1});
                
                //cout << "자리 횟수 " << next_node << " " << cnt + 1 << "\n";
            }
        }
    }
    
    
//     for (auto it = graph.begin(); it != graph.end(); ++it) {
//         vector<string> inner = (*it).second;
//         cout << "시작지 , 목적지 , 가능 여부 " << (*it).first << " ";
//         for(string str : inner){
//             cout << str << " ";
//         }
//         cout << "\n";
// }
    
// for (auto it = graph.begin(); it != graph.end(); ++it) {
//     auto& inner = (*it).second;
//     cout << "시작지 , 목적지 , 가능 여부 " << (*it).first << " ";
//     for (auto two = inner.begin(); two != inner.end(); ++two) {
//         cout<< (*two).first << " " << (*two).second;
//     }
//     cout << "\n";
// }
    
    
    
    return answer;
}