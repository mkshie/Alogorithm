#include <string>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string ,priority_queue<pair<int,int>>> m; //<장르,재생횟수,노래번호(음수)>
    priority_queue<pair<int,string>> q; // 최대 장르애들 모아둔 qeueu
    //1. 장르별 노래합 구분 -> 장르별 노래들을 모아둔 뒤 다 더해주기 
    //2. 장르별 최대 노래들 -> map 의 value 값에 우선순위 큐를 넣으면 됨 or
    for(int i=0;i<genres.size();i++){
        m[genres[i]].push({plays[i],-1*i}); //동일 재생 횟수인경우 고유번호가 작은애가
        //앞으로 가야하기때문에 우선순위큐는 내림차순임을 고려해 고유번호는 음수로 작성
    }
    for(auto it : m){
        int sum =0;
        priority_queue<pair<int,int>> temp = it.second;
        while(!temp.empty()){
            sum += temp.top().first;
            temp.pop();
        }
        q.push({sum,it.first});
    }
    while(!q.empty()){
        string gen = q.top().second; // 현재 큐에서 합이 제일 큰 노래 장르
        auto& aut = m[gen]; //해당 노래 장르의 노래 큐를 받아옴
        for(int i=0; i<2;i++){
            if(aut.size()<2) 
            {
                answer.push_back(abs(aut.top().second));
                break;
            }
            else {
                answer.push_back(abs(aut.top().second));
                aut.pop();
                 }
        }
        q.pop();
    }
    return answer;
    
}