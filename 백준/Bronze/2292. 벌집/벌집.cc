#include <iostream>

//백준 벌꿀집 문제 간단한 규칙 찾기

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long N;
    cin >> N;
    int cnt = 1;
    int add = 6;
    int left = 2, right = 7;
    if (N == 1)
    {
        cout << "1";
        return 0;
    }
    while(true){
        if(left <= N && N <= right){
            break;
        }
        left = left + add * cnt;
        right = right + add * (cnt+1);
        cnt++;
    }
    cout << cnt+1<<"\n";
    return 0;
}