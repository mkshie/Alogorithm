import java.util.*;

class Solution {
    //마라톤 참여함
    // participant -> 마라톤에 참여한 선수들의 이름
    // completion -> 완주한 선수들 이름
    // 문제에선 완주하지 못한 선수의 이름을 return 하자
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        
        HashMap<String,Integer> map = new HashMap<>();
        
        for(String str : participant){
            map.put(str , map.getOrDefault(str , 0) + 1);
        }
        
        for(String str : completion){
            map.put(str , map.get(str) - 1);
        }
        
        for(String str : participant){
            if(map.get(str) == 1){
                answer = str;
                break;
            }
        }
        return answer;
    }
}