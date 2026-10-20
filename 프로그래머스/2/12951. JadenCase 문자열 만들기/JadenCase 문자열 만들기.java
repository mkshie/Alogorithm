//모든 첫 문자가 대문자 , 그 외에 알파벳은 소문자

//

import java.util.*;
import java.io.*;

class Solution {
    public String solution(String s) {
        String answer = "";
        
        String[] arr = s.split(" ",-1);
        
        //System.out.println(Arrays.toString(arr));
        
        StringBuilder answer_cp = new StringBuilder();
        
        for(int i = 0; i < arr.length; i++){
            
            StringBuilder sb = new StringBuilder(arr[i]);
            //먼저 맨앞의 단어가 뭔지 판단하기
            //숫자인지 판단해보자.
            for(int j = 0; j < sb.length(); j++){
                char c = sb.charAt(j);
                if(!Character.isDigit(c)){
                    //숫자가 아니라면
                    if(Character.isLowerCase(c) && j == 0){
                        //소문자라면
                        sb.setCharAt(0,Character.toUpperCase(c));
                        //대문자로 변경해주자.
                    }

                    else if(Character.isUpperCase(c) && j != 0){
                        sb.setCharAt(j , Character.toLowerCase(c));
                    }
                }
            }
            arr[i] = sb.toString();
        }
        
        answer = String.join(" ", arr);
        return answer;
    }
}