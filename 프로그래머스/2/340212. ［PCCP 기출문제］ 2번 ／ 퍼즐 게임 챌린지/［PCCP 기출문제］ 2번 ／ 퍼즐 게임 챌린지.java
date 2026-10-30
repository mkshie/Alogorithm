import java.util.*;
import java.io.*;

//n 개의 퍼즐(난이도 , 소요 시간) 숙련도에 따라서 틀리는 횟수가 달라짐
//숙련도가 더 높다면 그냥 품 , 반대라면 time_cur + time_prev * 틀린 횟수 + time_cur 만큼의 시간
//limit 내에 풀 수 있는 최소의 숙련도를 찾기

//모든 숙련도를 돌아볼 수 없음 10^15 즉 이분탐색으로 최소값의 숙련도를 찾기 
//필요한 함수는 해당 숙련도의 경우 걸리는 시간 left , mid , right 는 숙련도를 기반으로
//시간 복잡도는 이분탐색마다 diff 를 다 돌아야하니 30만 * log 10만 = 510만 이다.

class Solution {
    int[] diffs , times;
    long limit;
    public boolean check(int level){
        long sum = 0;
        
        for(int i=0; i<diffs.length; i++){
            if(diffs[i] <= level){
                sum += times[i];
            }
            else{
                sum += (diffs[i] - level) *(times[i-1] + times[i]) + times[i];
            }
        }
        
        if(limit < sum) return false;
        return true;
    }
    
    public int solution(int[] diffs, int[] times, long limit) {
        int answer = 0;
        
        this.diffs = diffs;
        this.times = times;
        this.limit = limit;
        
        int left = 1 , right = 100000;
        
        while(left <= right){
            int mid = (left + right) / 2;
            
            if(check(mid)){
                //limit 안에 들어온다면 최솟값을 찾아야하니 왼쪽으로 이동
                right = mid - 1;
            }
            else{
                //limit 안에 못끝내니 숙련도를 더 늘리자. 오른쪽으로 이동
                left = mid + 1;
            }
        }
        
        
        return answer = left;
    }
}