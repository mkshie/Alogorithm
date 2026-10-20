class Solution {
    public boolean solution(String s) {
        boolean answer = true;
        
        
        if(s.length() == 4 || s.length() == 6){
            for(int i = 0; i < s.length(); i++){
                char c = s.charAt(i);
                if(c >= '0' &&  c <= '9'){
                }
                else answer = false;
            }
        }
        else answer= false;
        
        
        return answer;
    }
}