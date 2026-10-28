// 너비우선탐색 -> 최단 거리
// BFS 로 구현하면 됨 우선순위 큐 사용해도 되고 그냥 queue 사용해도 됨

import java.util.*;


class Solution {
    
    int dy[] = {0,0,1,-1};
    int dx[] = {1,-1,0,0};
    
    public int solution(int[][] maps) {
        int answer = -1;
        
        //queue 준비 
        Queue<int[]> queue = new ArrayDeque<>();
        
        queue.offer(new int[]{0,0,1});
        maps[0][0] = 0;
        
        while(!queue.isEmpty()){
            int[] cur = queue.poll();
            
            int y = cur[0];
            int x = cur[1];
            int cnt = cur[2];
            
            //System.out.println("현재 위치 " + y + " " + x + " " + cnt);
            
            if(y == maps.length - 1 && x == maps[0].length - 1){
                answer = cnt;
                break;
            }
            
            for(int i=0 ;i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                
                if(ny < 0 || nx < 0 || ny >= maps.length || nx >= maps[0].length) continue;
                
                if(maps[ny][nx] == 0) continue;
                
                maps[ny][nx] = 0;
                queue.offer(new int[]{ny, nx , cnt + 1});
            }
            
            
        }
        
        return answer;
    }
}