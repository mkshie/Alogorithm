import java.util.*;
import java.io.*;

//문자열의 n 번째 글자를 기준으로 오름차순 정렬

class Solution {
    public String[] solution(String[] strings, int n) {
        String[] answer = {};
        
        Arrays.sort(strings , (a,b) -> {
            if(a.charAt(n) == b.charAt(n)){
                return a.compareTo(b);
            }
            return Character.compare(a.charAt(n), b.charAt(n));
        });
            
        answer = strings;
        return answer;
    }
}