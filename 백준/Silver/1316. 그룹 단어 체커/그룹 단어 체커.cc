#include <iostream>
#include <cstring>

//그룹 단어 체커 문제
//그룹 단어란 다른 알파벳이 다른곳에서 연속적이지 않게 나오면 안됨
//즉 한 번 나온 알파벳은 뒤에 나오면 안된다는 의미

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    string str1;
    bool arr[26] = {}; //중복확인 이전에 없었던 애들은 false
    bool cnt; // 해당루프에서 한번이라도 중복이 있었는지 확인
    int answer = 0;

    cin >> N;

    while(N--){
        memset(arr, false, sizeof(arr)); //매 단어마다 초기화 해주기
        cnt = true;
        cin >> str1;
        char A =str1[0];
        arr[A - 97] = true; // 처음 나온 단어는 true 처리 해주기
        for (int i = 1; i < str1.size(); i++)
        {
            if (A == str1[i])
            {
                continue;
            }
            else {
                if(arr[str1[i]-97])
                    {
                        i = str1.size(); // for 문 통과
                        cnt = false;
                    }
                else
                {
                    A = str1[i];
                    arr[A - 97] = true;
                }
            }
        }
        if(cnt)
            answer++;
    }
    cout << answer << "\n";
    return 0;
}