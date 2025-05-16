#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

//해당 코드가 되는 이유는 가방 무게가 오름차순으로 정렬을 했기때문에 우선순위 큐에서 가장 큰 값이 아니더라도 즉 해당 가방에 그 보석을 넣는다고 선택을 하지 않게된다면
// 그 뒤에 가방에도 들어 갈 수 있기때문이다. 즉 idx = 1 의 가방에 들어갈 수 있는 보석이라면 그 뒤에 가방에는 무조건 들어갈 수 있다는 성질을 이용해
//시간복잡도를 매우 효율적으로 줄인 문제이다. 문제 자체가 어렵진 않지만 아이디어를 떠올리려면 생각을 더 해야할 거 같다.

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K; // N개의 보석 , K 개의 가방
    cin >> N >> K;
    vector<pair<int, int>> arr;
    for (int i = 0; i < N; i++)
    {
        int M, V;
        cin >> M >> V; // 무게 , 가격
        arr.push_back({M, V});
    }
    vector<int> v2;
    for (int i = 0; i < K;i++){
        int C;
        cin >> C;
        v2.push_back(C);
    }
    sort(arr.begin(), arr.end());
    sort(v2.begin(), v2.end()); // 가방과 보석들을 크기순으로 오름차순으로 정렬한 뒤
    priority_queue<int> pq;
    int j_idx = 0;
    long long ans = 0;
    //즉 무게가 낮은 친구들 부터 가방의 무게가 적은 애들끼리 비교하기 즉 해당 가방에 들어갈 수 있는 모든 보석들을 넣은 뒤 그때 그때 최대값을 pop 해서
    //더해주면 되는 문제
    
    for (int i = 0; i < K; i++)
    {
        while(j_idx < N && arr[j_idx].first <= v2[i]) // 즉 해당 가방에 넣을 수 있는 보석들은 다 넣은 뒤에 비교하자. 
            pq.push(arr[j_idx++].second);
        if(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << "\n";
    return 0;
}