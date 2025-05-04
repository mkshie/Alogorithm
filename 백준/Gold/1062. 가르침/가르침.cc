#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int answer = 0;
bool alpha[26] = {false};
vector<string> arr;

void DFS(int idx , int count){
    if(count == 0){ // 가르칠 수 있는게 더 없다면
        int cnt = 0;
        for(string str : arr){
            bool che = true;

            for(char c : str){
                if(!alpha[c-'a']){
                    che = false;
                    break;
                }
            }
            if(che)
            {
                cnt++;
            }
        }
        answer = max(answer, cnt);
    }

    for (int i = idx; i < 26;i++){
        if(alpha[i]) continue; // 이미 배운거면 넘어가기
        alpha[i] = true;
        DFS(i+1, count - 1);
        alpha[i] = false;
    }
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K; // N 개의 단어가 존재 , 가르칠 수 있는 K 개의 알파벳
    cin >> N >> K;
    for (int i = 0; i < N;i++){
        string str1;
        cin >> str1;
        arr.push_back(str1.substr(4,str1.length()-8));
    }
    if (K < 5)
        {
            cout << 0 << "\n";
            return 0;
        }
    if(K >= 26){
        cout << N << "\n";
        return 0;
    }

    alpha['a' - 'a'] = alpha['c' - 'a'] = 
    alpha['i' - 'a'] = alpha['n' - 'a'] = 
    alpha['t' - 'a'] = true;

    DFS(0, K - 5);

    cout << answer << "\n";
}