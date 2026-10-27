import java.util.*;
import java.io.*;

//stack 두개 만들어서 하기?

class Solution
{
    public int solution(String s)
    {
        int answer = -1;
        
        Deque <Character> stack1 = new ArrayDeque<>();
        Deque <Character> stack2 = new ArrayDeque<>();
        
        for(int i=0; i < s.length();i++){
            stack1.push(s.charAt(i));
        }
        
        while(!stack1.isEmpty()){
            if(stack2.isEmpty()){
                stack2.push(stack1.pop());
            }
            else{
                char ch1 = stack1.peek();
                char ch2 = stack2.peek();
                
                if(ch1 == ch2){
                    stack1.pop();
                    stack2.pop();
                }
                else{
                    stack2.push(stack1.pop());
                }
            }
        }
        
        if(!stack2.isEmpty()){
            answer = 0;
        }else answer = 1;

        return answer;
    }
}