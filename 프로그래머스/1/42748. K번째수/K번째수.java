import java.util.*;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        
        //array 에서 j 번째까지 자르고 정렬 후 k 번째에 있는 수 구하기.
        int[] answer = new int[commands.length];
        
        for(int i = 0; i<commands.length; i++){
            int[] arr = commands[i];
            
            int[] cp_array = Arrays.copyOfRange(array , arr[0] - 1 , arr[1]);
            Arrays.sort(cp_array);
            
            // for(int k : cp_array)
            //     System.out.println(k);
            
            answer[i] = cp_array[arr[2] -1];
            
        }
        return answer;
    }
}