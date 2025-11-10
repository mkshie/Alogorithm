#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

int totalGas=0;


//dfs 시 고려해야할 점 방문 여부, 해당 부분이 석유인지 , 

void dfs(int cnt,int y , int x , vector<vector<pair<int,int>>> &arr , const vector<vector<int>> &land){
    //첫번째로 고려해야 할 점
    //범위 판단 범위 벗어나면 return
    if(y <0 || x <0 || y >= arr.size() || x >= arr[0].size()) return;
    
    
    
    if(arr[y][x].first == -1 && land[y][x] == 1){ // 석유가 있고 처음 방문한 칸이라면
        //순회 후 벡터에 만들어주기
        arr[y][x].first = cnt;
        totalGas++;
        for(int i = 0 ; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            dfs(cnt , ny , nx , arr , land);
        }
        //arr[y][x].second = totalGas;
        
    } else{
        return;
    }
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    
    int ysize = land.size();
    int xsize = land[0].size();
    
    vector<vector<pair<int,int>>> arr(ysize , vector<pair<int,int>>(xsize, {-1,0})); // 몇번째 석유인지 , 크기가 몇인지
    //구현해야하는것 전체를 돌면서 해당 블록이 몇인지 적어두기
    
    int cnt = 0; // 몇번째 석유인지
    
    map<int,int> m;
    
    //전체 순회하기
    for(int y = 0; y < ysize ; y++){
        for(int x =0; x<xsize; x++){
            if(arr[y][x].first == -1 && land[y][x] == 1) // 석유이면서 방문한 적 없으면 dfs 출발
            {
                dfs(cnt , y , x , arr , land);
                //updatedfs(cnt,y,x,arr);
                m[cnt] = totalGas;
                //cout << y << " " << x  <<" " << cnt<< "\n";
                totalGas = 0;
                cnt++;
            }
        }
    }
     
    for(int x = 0; x<xsize; x++){
        int sum = 0;
        set<int> s; // 석유 번호들 저장해두는곳
        
        for(int y = 0 ; y<ysize;y++){
            if(s.find(arr[y][x].first) == s.end()){ //해당 부분이 set 에 없다면
                sum += m[arr[y][x].first];
                s.insert(arr[y][x].first);
            }
            else continue;
        }
        answer = max(sum , answer);
        s.clear();
    }
    
    return answer;
    
}