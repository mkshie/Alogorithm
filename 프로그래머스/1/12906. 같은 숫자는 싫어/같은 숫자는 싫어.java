import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        int[] answer;
        
        List<Integer> list = new ArrayList<>();
        
        for(int i =0; i<arr.length; i++){
            int n = arr[i];
            
            list.add(n);
            
            int k = i + 1;
            while(k < arr.length && arr[k] == n){
                i++;
                k++;
            }
        }
        
        answer = list.stream().mapToInt(i -> i).toArray();
        return answer;
    }
}