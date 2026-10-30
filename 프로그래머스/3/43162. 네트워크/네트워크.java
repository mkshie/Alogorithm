//union-find 로 문제를 풀어보자
//네트워크 개수를 확인해야함
import java.util.*;

class Solution {
    
    int[] nodes;
    
    public int solution(int n, int[][] computers) {
        int answer = 0;
        
        nodes = new int[computers.length];
        for(int i=0 ; i < nodes.length; i++){
            nodes[i] = i;
        }
        
        for(int i=0; i< computers.length; i++){
            for(int j=0; j < computers[i].length; j++){
                if(i != j && computers[i][j] == 1){
                    union(i,j);
                }
            }
        }
        
        Set<Integer> set = new HashSet<>();
        //System.out.println(Arrays.toString(nodes));
        for(int num : nodes){
            set.add(find(num));
        }
        
        answer = set.size();
        
        return answer;
    }
    
    int find(int x){
        if(x == nodes[x]) return x;
        return nodes[x] = find(nodes[x]);
    }
    
    boolean union(int x , int y){
        if(find(x) == find(y)){
            //서로 같은 네트워크
            return false;
        }
        
        nodes[find(x)] = find(y);
        return true;
    }
    
    
}