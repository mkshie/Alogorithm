#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int arr[10] = {0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int current_ch = 100;
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M;i++){
        int num;
        cin >> num;
        arr[num] = 1; // 고장난 버튼 표시
    }

    if(current_ch == N) {
        cout << 0 << "\n";
        return 0;
    }

    int answer = abs(current_ch - N); // 처음 +/- 로 가능경우의 수
    string num = to_string(N);
    queue<pair<int,int>> q; // 현재 숫자 , 자리수
    q.push({0, 0});
    while(!q.empty()){
        current_ch = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (cnt != 0)
        {
            answer = min(answer, abs(N - current_ch) + cnt);
        } // 비교후 정답 수정해주기
        if (cnt == num.size()+1)
        {
            continue;
        }
        else{
            int prev_num = num[cnt] - '0'; // char 형 숫자로 변환
            int num2 = current_ch;
            for (int i = 0; i < 10; i++)
            {
                int num2 = current_ch;
                if(arr[i] != 1){
                    num2 = num2 * 10 + i;
                    q.push({num2, cnt + 1});
                }
            }
        }
    }

    cout << answer << "\n";
    return 0;

    //문제가 헷갈릴때는 경우의 수를 작성해보자.
    //처음 숫자에서 + / - 로 해당 목표에 도달하는경우
    //새로운 숫자를 입력해서 도달하는 경우
    //새로운 숫자를 입력한 후  + / - 로 도달하는 경우 

    //총 세가지 경우가 존재 
}