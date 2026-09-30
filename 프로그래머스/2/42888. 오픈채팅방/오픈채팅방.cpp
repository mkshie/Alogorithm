#include <string>
#include <map>
#include <string>
#include <sstream>
#include <vector>

//map 을써서 uid -> name 으로 저장해두자.
//map 에서의 모든 내용을 담아두고 uuid , 내용의 형태로 정리해두자.


using namespace std;

vector<string> split(const string &s , char delimiter){
    vector<string> result;
    
    stringstream ss(s);
    string token;
    
    while(getline(ss,token,delimiter)){
        result.push_back(token);
    }
    
    return result;
}

map<string,string> m;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string,string>> sample;

    for(int i=0; i<record.size(); i++){
        vector<string> str = split(record[i] ,' ');
        
        //뭐가 됐든간에 sample 에는 uuid + 행동으로 기록해두자.
        if(str.size() == 2){//퇴장하는 경우 sample 에만 기록
            sample.push_back({str[1] , "님이 나갔습니다."});
        }
        else if(str[0] == "Enter"){ // 입장하는경우
            m[str[1]] = str[2];
            sample.push_back({str[1] , "님이 들어왔습니다."});
        }
        else{
            //닉네임 변경하는경우 map 만 수정해주고 나머진 그대로
            m[str[1]] = str[2];
        }
    }
    
    for(int i=0; i< sample.size();i++){
        answer.push_back(m[sample[i].first] + sample[i].second);
    }
    return answer;
}