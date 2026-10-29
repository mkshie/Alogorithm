// 귤 수확 후 상자에 담아 판매
// 귤을 map 에 담고 List 로 변환 후 정렬한 다음 더해서 개수로 끝

import java.util.*;
import java.io.*;


class Solution {
    public int solution(int k, int[] tangerine) {
        int answer = 0;
        Map<Integer , Integer> map = new HashMap<>();
        
        for(int i=0; i< tangerine.length; i++){
            map.put(tangerine[i] , map.getOrDefault(tangerine[i] , 0) + 1);
        }
        
        List<Integer> list = new ArrayList<>(map.values());
        list.sort(Comparator.reverseOrder());
        
        int sum = 0;
        for(int i=0; i<list.size();i++){
            sum += list.get(i);
            
            if(sum >= k){
                answer = i + 1;
                break;
            }
        }
        
        return answer;
    }
}