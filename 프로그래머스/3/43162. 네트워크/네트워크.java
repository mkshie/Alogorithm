import java.util.*;

//네트워크의 개수를 파악하는 문제.
//즉 모든 node 를 돌면서 visited 처리하면 된다.
//bfs , dfs 다 상관없음

class Solution {
    public int solution(int n, int[][] computers) {
        int answer = 0;
        
        //visited 배열 완성 초기값은 0
        int[] visited = new int[computers.length];
        
        // for(int[] i : visited){
        //     for(int j : i){
        //         System.out.println(j);
        //     }
        // }
        
        //모두 다 넣자 일단
        
        Queue<Integer> q = new ArrayDeque<>();
        
        
        for(int i=0;i<n;i++){
            //방문한적 없다면
            if(visited[i] == 0){
                answer++;
                
                q.offer(i);
                
                while(!q.isEmpty()){
                   int cur = q.poll();
                    
                    for(int j = 0; j < computers[0].length; j++){
                        //같은 node 가 아니고 , 방문한적 없다면 , 네트워크 연결이 되어있다면
                        if(cur != j && visited[j] == 0 && computers[cur][j] == 1){
                            q.offer(j);
                            visited[j] = 1;
                        }
                    }
                }
            }
        }
        
        return answer;
    }
}