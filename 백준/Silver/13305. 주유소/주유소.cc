#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//문제를 잘 읽으면 풀 수 있음....
//해석방법을 달리 해보자 먼저 내가 도착한곳의 기름값이 더 비싸다면 이전에서 충전해온걸로 하는 방식 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<pair<long long, long long>> arr(N, {0,0}); // 도로의 길이와 가격
    for (int i = 0; i < N -1;i++){
        cin >> arr[i].second; // 도로의 거리
    }
    for (int i = 0; i < N ;i++){
        cin >> arr[i].first; // 도시의 기름 가격
    }
    long long int answer = 0;
    long long min_price = arr[0].first;
    for (int i = 0; i < N - 1; i++)
    {
        //일단 다음 길이까지의 거리를 더하자
        min_price = min(min_price, arr[i].first);
        answer += min_price * arr[i].second;
    }
    cout << answer << "\n";
}