import java.util.*;
import java.io.*;



//

class Info{
    int op_start;
    int op_end;
    int pos;
    int video_len;
    
    public Info(String video_len , String pos , String op_start , String op_end){
        this.video_len = convert_int(video_len);
        this.pos = convert_int(pos);
        this.op_start = convert_int(op_start);
        this.op_end = convert_int(op_end);
        
        if(this.op_start <= this.pos && this.op_end >= this.pos) this.pos = this.op_end;
    }
    
    public int convert_int(String str){
        String[] arr = str.split(":");
        return Integer.parseInt(arr[0]) * 60 + Integer.parseInt(arr[1]);
    }
    
    public void cacl(String str){
        if(str.equals("next")){
            pos += 10;
            //경계값 확인
            if(pos > video_len) pos = video_len;
            //오프닝 값 확인
            if(this.op_start <= pos && this.op_end >= pos) this.pos = this.op_end;
        }
        else{
            pos -= 10;
            //경계값 확인
            if(pos < 0) pos = 0;
            //오프닝 값 확인
            if(this.op_start <= pos && this.op_end >= pos) this.pos = this.op_end;
        }
    }
    public String convert_time(){
        return String.format("%02d:%02d", pos / 60 , pos % 60);
    }
}

class Solution {
    public String solution(String video_len, String pos, String op_start, String op_end, String[] commands) {
        Info info = new Info(video_len , pos , op_start , op_end);
        for(String command : commands){
            info.cacl(command);
        }
        
        return info.convert_time();
    }
}