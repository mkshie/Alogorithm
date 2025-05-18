#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    priority_queue<int , vector<int> , greater<int>> pq; //낮은수부터 하게끔 오름차순 정리
    int arr[10001] = {0};
    arr[0] = 1;

    for (int i = 0; i < N;i++){
        int num;
        cin >> num;
        pq.push(num);
    }
    for (int i = 0; i < N;i++){
        int c = pq.top();
        pq.pop();
        for (int j = c; j <= K; j++){
            arr[j] += arr[j - c];
        }
    }
    cout << arr[K] << "\n";
    return 0;
}