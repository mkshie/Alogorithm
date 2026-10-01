#include <string>
#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

// 칸들로 이루어진 직사각형
// 그냥 1차 목표는 레버 -> visited 초기화 후 2차 목표는 탈출구 두번 dfs 하면 됨

using namespace std;

int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

int solution(vector<string> maps) {
    int answer = 0;
    
    vector<vector<bool>> visited (maps.size(),vector<bool> (maps[0].size(), false));// 초기 배열 false 
    
    queue<tuple<int,int,int>> q; //cnt , y, x; 
    
    int start_y , start_x;
    int rebber_y , rebber_x;
    int exit_y , exit_x;
    
    for(int i = 0 ; i < maps.size(); i++){
        const string &str = maps[i];
        for(int j = 0; j < str.size(); j++){
            const char& ch = str[j];
            if(ch == 'S'){
                start_y = i;
                start_x = j;
            }
            
            else if(ch == 'L'){
                rebber_y = i;
                rebber_x = j;
            }
            
            if(ch == 'E'){
                exit_y = i;
                exit_x = j;
            }
        }
    }
    
    q.push({0 , start_y , start_x});
    visited[start_y][start_x] = true;
    
    while(!q.empty()){
        
        auto [cnt , y , x] = q.front();
        q.pop();
        
        if(y == rebber_y && x == rebber_x){ // 탈출
            answer += cnt;
            break;
        }
        
        for(int i =0 ;i < 4; i++){
            int next_y = y + dy[i];
            int next_x = x + dx[i];
            
            
            if(next_y < 0 || next_y >= maps.size() || next_x < 0 || next_x >= maps[0].size())
                continue;
            
            //경계 확인 후 방문 처리
            
            if(!visited[next_y][next_x] && maps[next_y][next_x] != 'X'){
                
                cout << "레버 도착 " << cnt << " " << next_y << " " << next_x << "\n"; 
                visited[next_y][next_x] = true;
                q.push({cnt + 1 , next_y , next_x});
            }
        }
    }
    
    if(!visited[rebber_y][rebber_x]){
        return -1;
    }
        
        
        for(vector<bool>& vec : visited){
            fill(vec.begin() , vec.end() , false);
        }
    
    while (!q.empty()) {
        q.pop();
    }
        
    q.push({0 , rebber_y , rebber_x});
    visited[rebber_y][rebber_x] = true;
    
    while(!q.empty()){
        
        auto [cnt , y , x] = q.front();
        q.pop();
        
        if(y == exit_y && x == exit_x){ // 탈출
            answer += cnt;
            break;
        }
        
        for(int i =0 ;i < 4; i++){
            int next_y = y + dy[i];
            int next_x = x + dx[i];
            
            if(next_y < 0 || next_y >= maps.size() || next_x < 0 || next_x >= maps[0].size())
                continue;
            
            //경계 확인 후 방문 처리
            
            if(!visited[next_y][next_x] && maps[next_y][next_x] != 'X' ){
                visited[next_y][next_x] = true;
                q.push({cnt + 1 , next_y , next_x});
            }
        }
        
    }
    
    if(!visited[exit_y][exit_x]){
        return -1;
    }
    return answer;
}