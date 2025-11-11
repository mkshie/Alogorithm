#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include <deque>
#include <sstream>

using namespace std;

vector<string> delimeter(string str , char del){
    stringstream s(str);
    string tok;
    vector<string> arr;
    
    while(getline(s,tok,del)){
        arr.push_back(tok);
    }
    
    return arr;
}

// map 을 통해서 in , out 출차시간 확인하고 해당 값을 통해서 계산하는 함수 제작
// string -> int or double 형으로 변환

int calc(string in , string out , const vector<int> &fees){
    vector<string> inTime = delimeter(in , ':');
    vector<string> outTime = delimeter(out, ':');
    
    int inTimeTotal = stoi(inTime[0]) * 60 + stoi(inTime[1]);
    int outTimeTotal = stoi(outTime[0]) * 60 + stoi(outTime[1]);
    
    int TotalTime = outTimeTotal - inTimeTotal;
    
    return TotalTime;
    
    //cout << TotalTime << "\n";
    

}

    // if(TotalTime <= fees[0]){//기본 시간보다 작다면
    //     return fees[1];
    // }else{
    //     int realTime = (int)ceil((TotalTime - fees[0]) / (fees[2] * 1.0));
    //     return realTime * fees[3];
    // } 

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<vector<string>> splitstr(records.size());
    for(int i=0; i < records.size(); i++){
        splitstr[i] = delimeter(records[i] , ' ');
    }
    
    map<string , string> in; //차 번호 , 시간
    //map<string , deque<string> out;//차 번호 , 시간
    
    map<string,int> result;
    
    for(int i =0 ; i < splitstr.size(); i++){
        
        string time = splitstr[i][0];
        string carNumber = splitstr[i][1];
        if(splitstr[i][2] == "IN"){
            in[carNumber] = time;
        }
        else{
            //out 이면 그냥 바로 계산해주자
            auto it = in.find(carNumber);
            result[carNumber] += calc(it->second , time , fees);
            
            //cout << carNumber <<" " << result[carNumber] <<"\n";
            in.erase(it);
        }
    }
    
    
    
    for(auto it = in.begin() ; it != in.end(); it++){
        string carNumber = it->first;
        string time = it->second;
        //cout << carNumber <<" ";
        result[carNumber] += calc(time , "23:59" , fees);
    }
    
    for(auto it = result.begin(); it != result.end(); it++){
        int TotalTime = it->second;
        
        cout << it->first <<" " << it->second<<"\n";
        if(TotalTime <= fees[0]){
            answer.push_back(fees[1]);
        }else{
            int realTime = (int)ceil((TotalTime - fees[0]) / (fees[2] * 1.0));
            answer.push_back(fees[1] + realTime * fees[3]);
        }
    }
    
    return answer;
}