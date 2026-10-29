//

import java.util.*;
import java.io.*;
//map 으로 의상 종류별로 개수하고 -> 경우의 수 return 
class Solution {
    
    public int solution(String[][] clothes) {
        int answer = 1;
        Map<String,Integer> map = new HashMap<>();
        
        for(String[] clothe : clothes){
            map.put(clothe[1] , map.getOrDefault(clothe[1] , 0) + 1);
        }
        
        for (int count : map.values()) {
            answer *= (count + 1);
        }
        
        return answer - 1;
    }
    

}