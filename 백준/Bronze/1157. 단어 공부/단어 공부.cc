#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
//#include <cctype>
//백준 단어 공부 문제
//단어가 몇번 나오는지만 체크하면 쉽게 풀 수 있음
//대문자로 바꿔주는 내장함수와 (toupper) #include cctype 을 사용해주고
// 어느부분이 최대인지 아니면 최대가 몇번 나오는지를 알려주면 된다.
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[26] = {};
    memset(arr, 0, sizeof(arr));
    string str1;
    cin >> str1;
    
    //대문자로 모두 변환
    for (int i = 0; i < str1.size();i++){
        str1[i] = toupper(str1[i]);
        arr[(int)str1[i] - 65] += 1; // 배열에 해당 문자가 나올때마다 값 추가해주기
    }
    int max = -1;
    int cnt = 0;
    int answer = 0;
    for (int i = 0; i < 26; i++)
    {
        if(arr[i]>max)
        {
            max = arr[i];
            cnt = 0;
            answer = i;
        }
        else if(arr[i]==max && max!=0)
        {
            cnt++;
        }
    }
    if(cnt!=0){
        cout << "?\n";
        return 0;
    }
    cout << char(answer + 65) << "\n";
    return 0;
}