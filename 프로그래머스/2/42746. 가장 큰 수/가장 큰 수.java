import java.util.*;

class Solution {
    public String solution(int[] numbers) {
        String answer = "";
        
        String[] values = new String[numbers.length];
        
        for(int i= 0 ; i <numbers.length; i++){
            values[i] = String.valueOf(numbers[i]);
        }
        
        StringBuilder result = new StringBuilder();
        
        Arrays.sort(values , (a,b) -> { 
            String ab = a+b;
            String ba = b+a;
            
            return ba.compareTo(ab);
        });
        
        for(String value : values){
            
            if(result.length() == 1 && value.equals("0")){
                continue;
            }
            
            result.append(value);
        }
        
        
        return result.toString();
    }
}