import java.util.*;

//N 개의 마을로 이루어진 나라 존재
//마을에는 1~N 까지 번호가 있고 도로마다 정해져있음.

class Solution {
    
    long INF = Long.MAX_VALUE / 4;
    
    public int solution(int N, int[][] road, int K) {
        
        int answer=0;
        
        List<int[]>[] graph = new ArrayList[N+1];
        
        //모두 추가해주기
        for(int i=1; i<=N;i++){
            graph[i] = new ArrayList<>();
        }
        
        for(int[] info : road){
            int from = info[0];
            int to = info[1];
            int dis = info[2];
            
            graph[from].add(new int[]{to , dis});
            graph[to].add(new int[]{from ,dis});
            
        }
        
        
        //마을의 거리는 모두 크게 해둘예정
        long[] dist = new long[N+1];       
        
        Arrays.fill(dist , INF);
        
        //최소힙
        PriorityQueue<long[]> pq = new PriorityQueue<>((a,b) -> Long.compare(a[0] , b[0]));
        //[거리 , 현재 node]
        
        pq.offer(new long[]{0L,1L}); //초기값.
        dist[1] = 0;
        
        while(!pq.isEmpty()){
            
            long[] cur = pq.poll();
            
            long dis = cur[0];
            //int 지워도 되는지 확인해보기
            int cur_node = (int) cur[1];
            
            if(dis > dist[cur_node]){
                continue;
            }
            
            for(int[] info : graph[cur_node]){
                
                int next_dis = info[1];
                int next_node = info[0];
                
                long next_dis_total = dis + next_dis;
                
                if(next_dis_total < dist[next_node]){
                    dist[next_node] = next_dis_total;
                    pq.offer(new long[]{next_dis_total , next_node});
                }
            }
            
        }
        
        for(long dis : dist){
            if(dis <= K){
                answer++;
            }
        }
        
        //다익스트라로 문제를 풀어보자
        
        
        return answer;
    }
}