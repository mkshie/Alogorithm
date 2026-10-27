import java.io.*;
import java.util.*;

//트럭이 일차선 다리를 정해진 순으로 건너야함
//다리에 올라갈 수 있는 트럭의 개수와 무개가 정해져있음

class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;
        
        Queue <truck> queue = new ArrayDeque<>();
        
        int idx = 0;
        
        for(int i = 1; i <= 100000000 ; i++){
            
            
            if(!queue.isEmpty() && i - queue.peek().start == bridge_length){
                //나갈 수 있는 트럭이 있다면
                truck t = queue.poll();
                truck.sum_weight -= t.weight;
            }
            
            if(truck.sum_weight + truck_weights[idx] <= weight){
                //다리에 무게가 아직 괜찮다면?
                //queue 에 트럭 올리기
                queue.offer(new truck(i , truck_weights[idx]));
                truck.sum_weight += truck_weights[idx];
                
                // System.out.println("시간 : " + i + "트럭총 무게" + truck.sum_weight + "들어간 트럭 " + i +" " +
                //                   truck_weights[idx]);
                idx++;
            }
            
            if(idx == truck_weights.length){
                answer += i + bridge_length;
                break;
            }
        }
            
        return answer;
    }
    
    public class truck{
        static int sum_weight = 0;
        int start;
        int weight;
        
        public truck(int start , int weight){
            this.start = start;
            this.weight = weight;
        }
    }
}