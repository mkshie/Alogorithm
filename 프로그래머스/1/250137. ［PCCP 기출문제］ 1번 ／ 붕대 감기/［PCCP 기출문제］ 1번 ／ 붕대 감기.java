//붕대감기라는 기술
//t초동안 1초마다 x 회복 이후 연속으로 감는다면 y 만큼의 추가 회복.
//최대 체력이 존재
//시전 시간 , 초당 회복량 , 추가 회복량
//최대 체력

class Solution {
    public int solution(int[] bandage, int health, int[][] attacks) {
        int answer = -1;
        
        int use_time = bandage[0];
        int sec_heal = bandage[1];
        int add_heal = bandage[2];
        
        int max_health = health;
        
        int max_time = attacks[attacks.length - 1][0];
        
        int idx = 0;
        int cnt = 0;
        for(int i=1; i <= max_time; i++){
            //이번턴에 공격인지부터 먼저 확인
            if(attacks[idx][0] == i){
                //공격이라면 피 감소시켜야함
                health -= attacks[idx][1];
                //회복도 초기화
                cnt = 0;
                idx++;
            }
            else{
                health += sec_heal;
                
                cnt++;
                
                if(cnt == use_time) {health += add_heal; cnt = 0;}
                
                health = Math.min(max_health , health);
            }
            
            //System.out.println("시간 : " + i  + "현재 체력: " + health);
            if(health <= 0) break;
        }
        if(health > 0) answer = health;
        return answer;
    }
}