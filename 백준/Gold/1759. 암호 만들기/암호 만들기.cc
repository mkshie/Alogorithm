#include <iostream>
#include <algorithm>

using namespace std;

int L, C; // L 은 암호의 크기 , C 는 문자의 개수
vector<char> arr;
vector<char> answer;
char vowel[5] = {'a', 'e', 'i', 'o', 'u'};
int vowel_cnt = 0;
int cont_cnt = 0;


bool Is_vowel(char ch){
    for (int i = 0; i < 5;i++){
        if(vowel[i] == ch){
            return true; // 모음이라면 참
        }
    }
    return false; // 아니라면 거짓
}

void back_tracking(int size , int cnt){
    if(size == L){
        if(vowel_cnt >=1 && cont_cnt >=2){
            for(char c : answer)
                cout << c;
            cout << "\n";
        }
        return;
    }
    for (int i = cnt; i < C; i++){
        answer.push_back(arr[i]);
        if(Is_vowel(arr[i]))
            vowel_cnt++;
        else
            cont_cnt++;
        back_tracking(size + 1, i + 1);
        if (Is_vowel(arr[i]))
            vowel_cnt--;
        else
            cont_cnt--;
        answer.pop_back();
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> L >> C;
    arr = vector<char>(C,' ');
    for (int i = 0; i < C;i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    back_tracking(0, 0);
    return 0;
}