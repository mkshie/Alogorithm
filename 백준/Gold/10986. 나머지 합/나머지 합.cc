#include <iostream>
#include <vector>

using namespace std;

//vector<int> number;
long long N, M;
long long answer = 0;
//접근의 방식이 잘못됨 처음에는 누적합을 만들고 값이 넘어가지 않게 mod 연산을 해줬지만 
//시간 복잡도가 O(n^2) 으로 10^6 부터는 값이 넘어감
//하지만 arr[end] - arr[start-1] 의 값이 같다면 나누어떨어진다는 걸 떠올리고
//해당 구간이 어디인지 파악할 필요가 없다는 것을 토대로 접근하면 문제가 O(N+M) 의 복잡도를 가지게 됨
// void DFS(int idx , int cnt){
//     if(cnt == 2){
//         int start = number[0];
//         int end = number[1];
//         if((arr[end]-arr[start-1] + M) % M == 0){
//             answer++;
//         }
//         return;
//     }
//     for (int i = idx; i <= N;i++){
//         number.push_back(i);
//         DFS(i + 1, cnt + 1);
//         number.pop_back();
//     }
// }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<long long> arr;
    arr.push_back(0);
    cin >> N >> M;
    vector<long long> prefix(M+1,0);
    for (int i = 1; i <= N; i++)
    {
        int num;
        cin >> num;
        arr.push_back((arr[i-1]+num) % M); //arr 배열은 누적합
        if(arr[i]==0)
            answer++;
        prefix[arr[i]]++;
    }
    //DFS(1, 0);
    for (int i = 0; i <= M;i++){
        if(prefix[i] >=2){
            answer += prefix[i] * (prefix[i] - 1) / 2;
        }
    }
    cout << answer << "\n";
}