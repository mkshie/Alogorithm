import java.util.*;




class Solution {
    static final int INF = Integer.MAX_VALUE;

    class Edge{
        
        int to;
        int cost;
        
        public Edge(int to , int cost){
            this.to = to;
            this.cost = cost;
        }
    }
    
    public int solution(int N, int[][] road, int K) {
        int answer = 0;
        
        int[] dist = new int[N];
        
        Arrays.fill(dist , INF);
        
        List<List<Edge>> list = new ArrayList<>();
        
        for(int i=0; i<N;i++){
            list.add(new ArrayList<>());
        }
        
        for(int i=0; i<road.length; i++){
            int start = road[i][0] - 1;
            int to  = road[i][1] - 1;
            int cost = road[i][2];
            
            list.get(start).add(new Edge(to , cost));
            list.get(to).add(new Edge(start , cost));
        }
        
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b) -> Integer.compare(a[1] , b[1]));
        dist[0] = 0;
        pq.offer(new int[]{0,0}); //node , cost
        
        while(!pq.isEmpty()){
            int[] cur = pq.poll();
            
            int cur_node = cur[0];
            int cur_cost = cur[1];
            
            if(dist[cur_node] < cur_cost) continue;
            
            for(int i=0; i<list.get(cur_node).size(); i++){
                Edge next = list.get(cur_node).get(i);
                
                int next_node = next.to;
                int next_cost = next.cost;
                
                if(cur_cost + next_cost < dist[next_node]){
                    dist[next_node] = cur_cost + next_cost;
                    pq.offer(new int[]{next_node , cur_cost + next_cost});
                }
            }
             
        }
        
        for(int num : dist){
            if(num <= K) answer++;
        }
        return answer;
    }
}