import java.util.*;
import java.io.*;

//피로도 시스템 존재 , 일정 피로도 사용하면 던전 돌 수 있음
//던전은 최소 필요 피로도 , 소모 피로도 존재
//최대 던전수를 찾아라 
//DFS 를 통해서 다 돌아보면서 제일 많이 돌았던 경우의 수를 반환하면 됨
//왜 DFS 냐? 

class Solution {
    int answer = 0;
    
    public int solution(int k, int[][] dungeons) {
        
        boolean [] visited = new boolean[dungeons.length];
        dfs(dungeons , visited , 0 , k);
        
        return answer;
    }
    
    
    public void dfs(int [][] dungeons , boolean [] visited , int cnt , int k){
        answer = Math.max(cnt , answer);
        
        for(int i=0; i < visited.length ; i++){
            if(visited[i]) continue; //방문한곳이면 pass
            else{
                //방문하지 않았다면 피로도 계산하기
                int enter = dungeons[i][0];
                int minus = dungeons[i][1];
                
                if(k - enter < 0) continue;
                visited[i] = true;
                dfs(dungeons , visited , cnt + 1 , k - minus);
                visited[i] = false;
            }
            
        }
    }
}