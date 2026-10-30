#include <string>
#include <sstream>
#include <map>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> split_ws(const string &s){
    stringstream iss(s);
    vector<string> out_vec;
    string tok;
    while(iss >> tok){
        out_vec.push_back(tok);
    }
    return out_vec;
}

//선물을 적게 받은 사람이 선물을 많이 받은 사람에게 보냄
//선물 개수가 똑같다면 지수가 작은 사람이 -> 지수 큰사람에게 선물을 보냄
//선물지수 계산법 =  준 선물 - 받은 선물 
//지수까지 같다면 선물 주지않음

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    map<string , int> frimap;
    //map 을 사용해서 name 별 idx 찾기
    for(int i=0;i<friends.size();i++){
        frimap.insert({friends[i],i});
        // cout<<frimap[friends[i]] <<" ";
    }
    //주고 받은 선물의 개수를 정리하는 vecotor 필요
    //vec[i][j] = i 가 j 에게 선물을 준 횟수
    vector<vector<int>> giftrecord (friends.size(), vector<int>(friends.size() , 0));
    vector<int> giftscore(friends.size(),0);
    for(int i=0;i<gifts.size();i++){
        vector<string> two_name = split_ws(gifts[i]);
        int Aidx = frimap[two_name[0]];
        int Bidx = frimap[two_name[1]];
        //준 선물 횟수 계산 A -> B 에게
        giftrecord[Aidx][Bidx]++;
        //선물 지수 계산
        giftscore[Aidx]++;
        giftscore[Bidx]--;
    }
    vector<int> nxtgift(friends.size() , 0);
    for(int i=0; i < friends.size() ; i++){
        for(int j = i+1 ; j <friends.size();j++){ //i보다 작은애들은 이미 이전에 검사함
            //i 가 j 에게 선물을 받을 수 있는지 확인하자. 
            //case 1 i 가 선물을 더 많이 준 경우
            if(giftrecord[i][j] > giftrecord[j][i]){
                nxtgift[i]++;
            }
            else if(giftrecord[i][j] < giftrecord[j][i]){
                nxtgift[j]++;
            }
            else{
                //서로의 주고 받은 개수가 똑같은 경우
                if(giftscore[i] > giftscore[j])
                    nxtgift[i]++;
                else if(giftscore[i] < giftscore[j])
                    nxtgift[j]++;
            }
        }
    }
    
    for(int i=0;i<friends.size();i++){
        answer = max(answer , nxtgift[i]);
    }
    
    
    
    
    return answer;
}