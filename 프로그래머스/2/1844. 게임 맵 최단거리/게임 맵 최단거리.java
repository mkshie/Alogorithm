//최대한 빨리 도착하는게 목표임
//1,1 에 있고

import java.util.*;

class Solution {
    
    int[] dr = {-1, 1, 0, 0};
    int[] dc = {0, 0, -1, 1};
    
    public int solution(int[][] maps) {
        int answer = -1;
        
        Queue<int[]> q = new ArrayDeque<>();
        
        //기본이 false
        //boolean[][] visited = new boolean[maps.length][maps[0].length];
        
        q.offer(new int[]{0,0,0});
        
        while(!q.isEmpty()){
            int[] cur = q.poll();
            
            int row = cur[0];
            int col = cur[1];
            int dis = cur[2];
            
            //System.out.println(row +" "+ col + " dis : " + dis);
            
            if(row == maps.length-1 && col == maps[0].length-1){
                answer = dis + 1;
                break;
            }
            
            for(int i=0; i< 4; i++){
                int n_row = row + dr[i];
                int n_col = col + dc[i];
                
                //구간 검사
                if(n_row < 0 || n_row >= maps.length || n_col < 0 || n_col >= maps[0].length)
                    continue;
                
                //지나온곳도 1로 채우자 그냥
                //벽인지 지나온곳인지 확인하기
                if(maps[n_row][n_col] == 0)
                    continue;
                else{
                    maps[n_row][n_col] = 0;
                    q.offer(new int[]{n_row,n_col,dis + 1});
                }
            }
        }
        
        return answer;
    }
}