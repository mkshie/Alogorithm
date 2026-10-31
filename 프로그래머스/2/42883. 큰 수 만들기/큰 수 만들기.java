//stack 으로 해결할 수 있을 거 같음
//다음 숫자가 나보다 작다 -> stack 의 크기가 괜찮다 -> 넣기
//다음 숫자가 나보다 크다 -> 남은 숫자가 괜찮다 -> 빼기
//남은 숫자가 괜찮지 않다. -> 내가 들어가기

import java.util.*;

class Solution {
    public String solution(String number, int k) {
        String answer = "";
        
        Deque<Character> stack = new ArrayDeque<>();
        int max_size = number.length() - k;
        
        
        for(int i =0; i < number.length(); i++){
            char c = number.charAt(i);
            
            if(k==0) {
                stack.push(c);
                continue;
            }
            
            if(stack.isEmpty()) stack.push(c);
            else{
                if(stack.peek() < c){
                    //내가 더 큰 경우
                    while(k > 0 && !stack.isEmpty() && stack.peek() < c){
                        //k 가 0보다 크고 stack 이 비어있지 않다면
                        stack.pop();
                        k--;
                    }
                    stack.push(c);
                } else{
                    stack.push(c);
                }
            }
            
           // System.out.println(stack);
        }
        
        while(k > 0){
            stack.pop();
            k--;
        }
        StringBuilder sb = new StringBuilder();
        
        while(!stack.isEmpty()){
            sb.append(stack.pop());
        }
        answer = sb.reverse().toString();
        return answer;
    }
}