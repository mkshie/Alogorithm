import java.util.*;
import java.io.*;

class Solution {
    boolean solution(String s) {
        
        Deque<Character> stack = new ArrayDeque<>();
        boolean answer = true;
        
        for(int i=0; i< s.length();i++){
            char ch = s.charAt(i);
            
            if(ch == '('){
                stack.push(ch);
            }
            else{
                if(stack.isEmpty()){
                    answer = false;
                    break;
                }
                stack.pop();
            }
        }
        
        if(!stack.isEmpty() && answer) answer = false;
        return answer;
    }
}