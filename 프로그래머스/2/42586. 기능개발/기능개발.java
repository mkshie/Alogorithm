import java.util.*;

//각 기능은 진도가 100퍼일때 반영할 수 있음.
// 서로 다름. 순서 상관없음. 뒤에있는애가 먼저 완성되도 앞에있는 기능이 배포될때 함께 배포됨
//먼저 배포되어야하는 순서가 있는 배열이 존재. 작업의 개발속도가 있는 speeds 가 있음.

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        
        int[] result;
        
        List<Integer> list = new ArrayList<>();
        
        Queue <Integer> queue = new ArrayDeque<>();
        
        for(int num : progresses){
            queue.offer(num);
        }
        
        int idx = 0;
        for(int i=1; i <= 100; i++){ //i 는 날짜
            int num = queue.peek();
            if(num + speeds[idx] * i >= 100){
                //배포 가능
                int cnt = 1;
                queue.poll();
                //계산해보자 뒤에 애들까지 i 는 올리지 말고
                idx++; //뒤에 애 가르키기
                while(idx < progresses.length){
                    int nxt = queue.peek();
                    
                    if(nxt + i * speeds[idx] >= 100){
                        cnt++;
                        idx++;
                        queue.poll();
                    }
                    else break;
                }
                
                list.add(cnt);
                if(queue.isEmpty()) break;
            }
        }
        return result = list.stream().mapToInt(i -> i).toArray();
    }
}