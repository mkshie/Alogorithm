#include <iostream>

using namespace std;

// <M : N > 카잉달력의 마지막 해를 의미

// 첫번째 풀이로 먼저 대가리 박기를 해보자.
// 실패 시간초과
// 두번째 풀이 어차피 두 숫자는 M 과 N 으로 나누어지기전엔 같은 숫자였고
// 최소공배수가 넘어간다면 그 해는 없는해가 됨 찾아보니 중국인의 나머지 정리에 기반해서 문제를 푸는 사람들도 존재했지만
// 나는 결국 같은 수엿다는거에 집중하고 x 와 y 에 M 과 N 을 넣어보며 같은 값이 되지 않거나. 최소공배수가 아닌 두 수의 곱 (최소공배수 보단 크지만 시간 초과는 안날듯)
// 까지만 검토를 하는 방식으로 문제를 품

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T, M, N, x, y;
    cin >> T;
    while(T--){
        cin >> M >> N >> x >> y; // M : x 의 최대 , N : y 의 최대
        int cnt_x = x, cnt_y = y; // 초기값
        while(true){
            if(cnt_x == cnt_y){
                cout << cnt_x << "\n";
                break;
            }
            else if(cnt_x > M * N){
                cout << -1 << "\n";
                break;
            }

            if(cnt_x > cnt_y)
                cnt_y += N;
            else
                cnt_x += M;
        }
    }
    return 0;
}