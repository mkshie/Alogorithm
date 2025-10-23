#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

//네오 유저들의 아이디를 생성하는 업무
//새로 가입하는 유저들의 아이디가 규칙에 맞지 않다면 규칙에 맞는 아이디를 추천해줘야함
//아이디 규칙 -> 소문자 , - , _ , . 만 사용가능 하지만 . 는 처음과 끝에 사용 x + 연속으로 사용 불가능

//단계는 다음과 같음
// 대문자 -> 소문자로 변환
// 규칙에 맞지 않는 문자는 모두 제거
// .. -> . 로 치환하기
// . 이 맨앞이나 맨끝에 있다면 제거
// 빈 문자열이라면 a 대입
// 길이가 16 이상이면 첫 15개 빼고 문자 제거 끝이 . 라면 . 제거
// 길이가 2자 이하라면 마지막 문자를 길이가 3이 될때가지 끝에 반복해서 붙이기

using namespace std;



string solution(string new_id) {
    set<char> ch;
    ch.insert('-'); ch.insert('_'); ch.insert('.');
    
    //1단계 대문자 -> 소문자
    for(char &c : new_id){
        if('A' <= c && c <= 'Z') c = c - 'A' + 'a';
    }
    
    //2단계 규칙에 맞지 않는 문자는 모두 제거
    string fiterStr;
    for(int i =0; i < new_id.size() ; i ++){
        char c = new_id[i];
        if(('0' <= c && c <= '9') ||  ('a' <= c && c <= 'z') || ch.find(c) != ch.end()){ //올바른 문자라면
            fiterStr += c;
        }
    }
    //3단계 연속된 . 지우기
    for(int i=0; i<fiterStr.size(); i++){
        char c = fiterStr[i];
        if(c == '.'){
            int height = 0;
            while(fiterStr[i+height] == '.'){
                height++;
            }
            if(height != 0) //지우기
                fiterStr.erase(fiterStr.begin() + i + 1 ,fiterStr.begin() + i + height);
        }
    }
    //맨앞 맨 뒤 . 지우기
    if(fiterStr[0] == '.') fiterStr.erase(fiterStr.begin());
    if(fiterStr[fiterStr.size() - 1] == '.') fiterStr.erase(fiterStr.end() - 1);
    
    //비워져있다면
    if(fiterStr.empty()) fiterStr+='a';
    
    //16 이상이라면
    if(fiterStr.size() > 15) fiterStr.erase(15);
    if(fiterStr[fiterStr.size() - 1] == '.') fiterStr.erase(fiterStr.end() - 1);
    
    //2자 이하라면
    if(fiterStr.size() <= 2){
        char c = fiterStr[fiterStr.size() - 1];
        while(fiterStr.size() != 3)
            fiterStr+=c;
    }
    
    
    //cout << fiterStr <<"\n";
    
    string answer = fiterStr;
    return answer;
}