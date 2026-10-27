import java.util.*;
import java.io.*;
//hh:mm
//먼저 우선순위 queue 로 정렬하자.
class Solution {
    public String[] solution(String[][] plans) {
        String[] answer = new String[plans.length];
        
        int idx = 0;
        
        PriorityQueue<Task> pq = new PriorityQueue<>(
            (a, b) -> { return Integer.compare(a.start, b.start); }
        );
        
        Deque <Task> stack = new ArrayDeque<>();
        
        for(int i=0; i < plans.length;i++){
            pq.offer(new Task(plans[i][0] , plans[i][1] , plans[i][2]));
        }
        
//         while(!pq.isEmpty()){
//             System.out.println(pq.poll());
//         }
        
//         System.out.println();
        
        //이제 하나씩 구현해보자. 우선순위 큐에 시간이 순차적으로 들어가있음
        //1 꺼내기 -> 다음작업 있는지확인 2 시간 비교하기 3 시간 남는지 , 딱 맞는지 , 부족한지 체크
        
        
        while(!pq.isEmpty()){
            Task cur = pq.poll(); //현재 해야하는것
            
            //System.out.println("시작하는 task " + cur);
            
            if(pq.isEmpty()) // 다음 작업이 있는지 확인
            {
                //없다면 그대로 탈출하기
                answer[idx] = cur.name;
                idx++;
                break;
            }
            
            //다음 작업이 존재한다면
            
            Task nt = pq.peek();
            
            //두 task 간의 시간차이
            int diff = nt.start - cur.start - cur.duration;
            
            if(diff == 0){
                //딱 맞는경우
                answer[idx] = cur.name;
                idx++;
            }
            else if(diff > 0){
                //현재 작업을 하고도 시간이 남은 경우
                //남은 시간동안 stack 에 있는 작업 처리하기
                
                answer[idx] = cur.name;
                idx++;
                
                while(!stack.isEmpty() && diff > 0){
                    //남아있는 일이 없거나 diff 가 0이되면 나가기
                    
                    Task delayTask = stack.pop();
                    if(delayTask.duration <= diff){ 
                        //작업의 남은시간이 남은시간보다 작다면
                        answer[idx] = delayTask.name;
                        idx++;
                        diff -= delayTask.duration;
                    }
                    else{
                        //남은시간보다 작업 시간이 더 길면 다시 stack 에 넣어주기
                        delayTask.duration -= diff;
                        stack.push(delayTask);
                        diff = 0;
                    }
                }
            }
            else{
                //시간이 부족한 경우
                cur.duration = cur.duration - (nt.start - cur.start);
                stack.push(cur);
            }
        }
        
        while(!stack.isEmpty()){
            answer[idx] = stack.pop().name;
            idx++;
        }
        
        return answer;
    }
    
    class Task{
        String name;
        int start;
        int duration;
        
        public Task(String name , String start , String duration){
            this.name = name;
            String[] str = start.split(":");
            this.start = Integer.parseInt(str[0]) * 60 + Integer.parseInt(str[1]);
            this.duration = Integer.parseInt(duration);   
        }
        
        public String toString() {
            return name + " " + start + " " + duration;
        }
    }
}