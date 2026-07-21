import java.util.*;

//n 명이 기다리고있음. 심사관마다 걸리는 시간이 다름.
//심사대에선 동시에 한 명만 심사가 가능함.
// 맨 앞에 있는 사람은 비어 있는 심사대로 가서 검사를 받음 하지만 더 빨리 끝나느 심사대가 있으면 거기에가서 받을 수 있음
//최소한으로 시간을 단축시키고 싶음.

class Solution {
    public long solution(int n, int[] times) {
        long answer = 0;
        
        int fastest = times[0];

        for (int time : times) {
            fastest = Math.min(fastest, time);
        }
        
        long left = 1, right= (long)fastest * n;
        
        while(left <= right){
            long mid = (left + right) / 2;
            
            System.out.println(mid);
            
            //mid 의 시간에 몇명을 처리하는지
            long result_people = count_people(mid , times);
            
            //처리한 사람들의 숫자가 n 명보다 더 적은경우 시간을 늘려야함.
            if(n > result_people){
                left = mid + 1;
            }
            else{
                right = mid - 1;
                answer = mid;
                System.out.println(answer);
            }
        }
        
        System.out.println(answer);
        
        return answer;
    }
    
    private long count_people(long time , int[] times){
        long sum = 0L;
        
        for(int i : times){
            sum += time / i ;
        }
        
        return sum;
    }
}