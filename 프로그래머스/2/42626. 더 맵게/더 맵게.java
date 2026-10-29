//문제 풀기
// 모든 음식의 스코빌 지수를 K 이상으로 , 가장 낮은 두개의 음식을 섞어서 새로 만듦
//우선순위 큐 -> 아래 두개 꺼내서 다시 넣기 이후 맨 위가 K 이상이면 끝


import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        for(int num : scoville){
            pq.offer(num);
        }
        int sum = 0;
        while(pq.size() != 1 && pq.peek() < K){
            int first = pq.poll();
            int second = pq.poll();
            
            pq.offer(first + second * 2);
            sum++;
        }
        
        if(pq.peek() < K) answer = -1;
        else answer = sum;
        
        return answer;
    }
}