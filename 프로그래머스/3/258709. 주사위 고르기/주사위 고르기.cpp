#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;
//A 와 B 가 n 개의 주사위를 갖고 게임을 함
//1~n 까지의 번호를 갖고 있음 주사위에 쓰인 수의 구성은 다름
//각각 주사위를 선택함 2/n 개를 A 가 먼저 선택 , 나온 수들을 모두 합해서 점수 계산시 점수가 더 큰 쪽이 승리, 같다면 무승부
//A 의 승리 확률이 가장 높아지도록 주사위를 가져가야함.

//최대 주사위가 10개 즉 10C5 = 252
//주사위 5개에서 승패가 존재하는 경우의 수 6^5^2 가 됨... 
//brute froce 방식으로는 조금 어려움..
//lower_bound 를 사용한다면? -> 이분탐색... 

int sizet;

vector<int> diceA;
vector<int> diceB;
vector<bool> diceChe;
vector<int> answer;
vector<int> result(3,0);// 0 승리 , 1 무승부 , 2 패배
vector<vector<int>> realDice;
int maxNum = 0;
int cheNum2 = 1;

void choiceDiceB();
void calc();
void calcdiceA(vector<int>& , int , int);
void calcdiceB(vector<int>& , int , int);

void choiceDiceA(int cnt , int idx){
    if(sizet == cnt){
        choiceDiceB();
        return;
    }
    
    for(int i = idx; i < sizet * 2 ; i++){
        diceA.push_back(i);
        diceChe[i] = true;
        choiceDiceA(cnt + 1 , i + 1);
        diceChe[i] = false;
        diceA.pop_back();
    }
}

void choiceDiceB(){
    for(int i = 0 ; i < sizet * 2 ; i++){
        if(!diceChe[i])
            diceB.push_back(i);
    }
    // for(int i = 0 ; i < diceB.size(); i ++){
    //     cout << diceB[i] << " ";
    // }
    // cout << "\n";
    // cout << "cheNum2 : " << cheNum2 << "\n";
    
    calc();
    diceB.clear();
    return;
}

void calc(){
    vector<int> sumA , sumB;
    calcdiceA(sumA , 0 , 0);
    calcdiceB(sumB , 0 , 0);
    sort(sumA.begin() , sumA.end());
    sort(sumB.begin() , sumB.end());
    int sizeA = sumA.size();
    int sizeB = sumB.size();
    
    
    for(int i = 0 ; i < sizeA ; i ++){
        int num = sumA[i];
        //auto idx1 = upper_bound(sumB.begin() , sumB.end() , num);
        auto idx2 = lower_bound(sumB.begin() , sumB.end() , num);
        result[0] += idx2 - sumB.begin();
    }
    //cout << result[0] << "\n";
    if(result[0] > maxNum){
        maxNum  = result[0];
        answer.clear();
        for(int i = 0 ; i < sizet * 2 ; i++){
            if(diceChe[i])  // A 인 주사위만 넣어주기
                answer.push_back(i+1);
        }
    }
    result[0] = 0;
    
}

void calcdiceA(vector<int> &A , int sum , int cnt){
    if(cnt == diceA.size()){
        A.push_back(sum);
        return;
    }
    
    for(int i = 0; i < 6; i++){
        calcdiceA(A , sum + realDice[diceA[cnt]][i] , cnt + 1 );
    }
}
void calcdiceB(vector<int> &B , int sum , int cnt){
    if(cnt == diceB.size()){
        B.push_back(sum);
        return;
    }
    
    for(int i = 0; i < 6; i++){
        calcdiceB(B , sum + realDice[diceB[cnt]][i] , cnt + 1 );
    }
}



vector<int> solution(vector<vector<int>> dice) {

    diceChe = vector<bool>(dice.size() , false); //false 인 애들은 B
    realDice = dice;
    sizet = dice.size() / 2;
    choiceDiceA(0 , 0);
    
    sort(answer.begin() , answer.end());
    
    return answer;
}