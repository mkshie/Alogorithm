import java.util.*;
import java.io.*;


//자동차 건설 N*N 정사각형 격자 , 0 = 비어있음 1 = 장애물
//우선순위 큐..? 아니면 그냥 큐여도 방문여부를 파악하는게 아니라 최소값 여부를 파악하면 되지않을까..
//그냥 큐로 가는대신에 방문 여부를 비용으로 판단하자

//직선 과 곡선을 판단해야함
class Solution {
    
    int dy[] = {0,1,0,-1};
    int dx[] = {1,0,-1,0};
    
    class Node{
        int dir; //방향 1,2,3,4 동남서북 (0인경우 이전 내용이 없는것)
        int cnt; //지금까지 비용
        int y , x;
        public Node(int dir, int y, int x , int cnt){
            this.dir = dir;
            this.y = y;
            this.x = x;
            this.cnt = cnt;
        }
        
        public String toString(){
            return "Node: " + y + " " + x + " " + dir + "cnt : " + cnt;
        }
        
        public static int cal(int a, int b){
            if(a == 0 || b == 0) return 0;
            else if(a != b) return 500;
            
            return 0;

        }
        
    }
    
    public int solution(int[][] board) {
        int answer = 999999;
        
        Queue <Node> queue = new ArrayDeque<>();
        
        int[][][] cost = new int[board.length][board[0].length][5];
        
        for(int[][] row : cost){
            for(int []dirs: row){
            Arrays.fill(dirs, 999999); //초기값은 10만정도로 넣어두기
            }
        }
        
        queue.offer(new Node(0,0,0,0));
        cost[0][0][0] = 0;
        
        while(!queue.isEmpty()){
            //시작해보자
            
            Node curnode = queue.poll();
            
            //System.out.println(curnode);
            
            int y = curnode.y;
            int x = curnode.x;
            int dir = curnode.dir;
            int cnt = curnode.cnt;
            
            if(y == board.length -1  && x == board.length - 1){
                answer = Math.min(cnt , answer);
                continue;   
            }
            
            for(int i=0; i< 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                
                if(ny < 0 || nx < 0 || ny >= board.length || nx >= board.length) continue;
                if(board[ny][nx] == 1) continue; // 벽이면 pass
                
                int ndir;
                
                // int dy[] = {0,1,0,-1};
                // int dx[] = {1,0,-1,0};
                // 동남서북 1,2,3,4
                //이제 방향별로 돈이 얼마나 추가되는지 확인해보고 더 작으면 queue 에 넣자
                
                if(i == 0) ndir = 1;
                else if(i == 1) ndir = 2;
                else if(i==2) ndir = 3;
                else ndir =4;
                
                int ncnt = Node.cal(dir , ndir) + 100 + cnt;
                // if(y == 1 && x == 0) {
                //         System.out.println("좌표" + y + " " + x );
                //         System.out.println("총 " + ncnt + " " + cnt );
                //         System.out.println("ndir " + ndir);
                //         System.out.println(cost[ny][nx]);
                // }
                if(ncnt < cost[ny][nx][ndir]){
                    //더 작거나 같다면
                    cost[ny][nx][ndir] = ncnt;
                    queue.offer(new Node(ndir , ny , nx , ncnt));
                }
                
            }
        }
        
        
        return answer;
        
    }
}