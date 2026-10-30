#include <string>
#include <vector>

using namespace std;

vector<float> currentDegree;    // 현재 시침, 분침, 초침의 각도를 저장하기 위한 벡터
vector<float> nextDegree;       // 1초 뒤의 각 시계침의 각도를 저장하기 위한 벡터

// 시간에 따른 시계침 각도를 return
vector<float> getDegree(int time)
{
    // 입력된 초 시간을 시, 분, 초로 분리
    int h = time / 3600;
    int m = (time % 3600) / 60;
    int s = (time % 3600) % 60;
    
    // 시, 분, 초에 따른 시계침 각도 계산
    float h_degree = (s * (1 / 120.0)) + (m * 0.5) + ((h % 12) * 30.0);
    float m_degree = (s * 0.1) + (m * 6.0);
    float s_degree = s * 6.0;
    
    return vector<float> {h_degree, m_degree, s_degree};
}

//시침과 초침의 겹침 감지
bool checkHourCondition()
{    
    // 현재 시간의 초침이 59초를 가리키고 있을 때 & 시침이 초침보다 앞에 있을 때 겹침이 발생
    if(currentDegree[2] == 354 && currentDegree[0] > 354) return true;
    
    // 현재 시간의 초침이 시침보다 뒤에 있고, 1초 뒤의 초침이 시침을 앞지를 때 겹침이 발생
    if(currentDegree[0] > currentDegree[2] && nextDegree[0] <= nextDegree[2]) return true;
    
    return false;
}

// 분침과 초침의 겹침 감지
bool checkMinuteCondition()
{
    // 위와 같은 원리로 작동
    if(currentDegree[2] == 354 && currentDegree[1] > 354) return true;
        
    if(currentDegree[1] > currentDegree[2] && nextDegree[1] <= nextDegree[2]) return true;
    
    return false;
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;
    int total_h1 = h1 * 3600 + m1 * 60 + s1;
    int total_h2 = h2 * 3600 + m2 * 60 + s2;
    
    if(total_h1 == 0 || total_h1 == 43200) answer++;    // 시작 시간이 00:00:00 이거나 12:00:00 일 때 시작과 동시에 겹침
    
    for(int i = total_h1; i < total_h2; i++)    // 마지막 초는 계산하지 않음. 현재 시계와 1초 뒤의 시계를 비교하기 때문
    {
        currentDegree = getDegree(i);
        nextDegree = getDegree(i + 1);
        
        bool hCondition = checkHourCondition();
        bool mCondition = checkMinuteCondition();
        
        // 초침이 시침과 분침에 함께 겹쳤을 때
        if(hCondition && mCondition)
        {
            if(nextDegree[0] == nextDegree[1]) answer++;    // 시침과 분침이 이미 겹쳐있다면 +1
            else answer += 2;   // 겹치지 않고 차이가 있다면 +2
        }
        
        else if(hCondition || mCondition) answer++; // 둘 중 하나만 겹친 경우
    }
    
    return answer;
}