//문제 풀기
// 스코빌 지수를 K 이상으로 만들고싶음. 가장 낮은 두개의 음식 섞기 -> 가장 낮음 +  두번째로 납음 * 2  가 됨.
//최소값이 K 이상일데ㅐ까지 섞기. 최소 횟수 return 해주기

import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        for(int i : scoville){
            pq.offer(i);
        }
        
        while(pq.peek() < K){
            if(pq.size() < 2){
                return -1;
            }
            
            int a = pq.poll();
            int b = pq.poll();
            
            pq.offer(a + b * 2);
            //System.out.println(pq.peek());
            answer++;
        }
        return answer;
    }
}