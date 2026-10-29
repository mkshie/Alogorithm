//오픈채팅방 

import java.util.*;
import java.io.*;

// 

class Solution {
    public String[] solution(String[] record) {
        
        String[][] split_record = new String[record.length][];
        
        Map<String , String> map = new HashMap<>();
        List<String[]> list = new ArrayList<>();
        
        for(int i=0; i< record.length; i++){
            split_record[i] = record[i].split(" ");
        }
        
        //System.out.println(Arrays.deepToString(split_record));
        
        for(String[] split : split_record){
            
            if(split[0].equals("Enter")){
                //enter 인 경우 list 추가
                map.put(split[1] , split[2]);
                list.add(new String[]{split[1] , "님이 들어왔습니다."});
            }
            else if(split[0].equals("Leave")){
                //leave 인 경우 추가
                map.put(split[0] , split[1]);
                list.add(new String[]{split[1] , "님이 나갔습니다."});          
            } else{
                map.put(split[1] , split[2]);
            }
        }
        String[] answer = new String[list.size()];
        for(int i=0; i < list.size(); i++){
            answer[i] = map.get(list.get(i)[0]) + list.get(i)[1];
        }
        
        
        return answer;
    }
}