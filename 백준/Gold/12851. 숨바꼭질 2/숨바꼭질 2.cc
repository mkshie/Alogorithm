#include <iostream>
#include <algorithm>
#include <stack>
#include <deque>
#include <queue>

using namespace std;

// BFS 의 기본문제 우선순위 큐를 사용해서 거리가 적은 순부터 먼저 처리하게 끔 코딩하면 구현하기 매우 쉽다.
// BFS 는 정점으로 부터 가까운 애들부터 처리하기 때문 하지만 이 문제같은 경우는 cnt 가 동일하게 증가하기때문에 우선순위 큐를 사용하지 않더라도
// 똑같이 풀 수 있을듯 함

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K; // N 은 수빈 K 는 동생
    cin >> N >> K;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> arr;
    vector<int> che_visit(100010, 0); // 0 은 도착한적 없음 이후 숫자는 몇번만에 왔는지를 적어둠 이 숫자보다 크다면 pass 
    //두번째 인자는 도달한 횟수
    int cnt, cur_location;
    arr.push({0, N});
    int count_num = 0; // 목적지에 최단거리로 도착한 경우의 수
    int three[3] = {1, -1, 2};
    che_visit[N] = 1;
    while (!arr.empty())
    {
        cnt = arr.top().first;
        cur_location = arr.top().second;
        arr.pop();
        if (cur_location == K)
        {
            count_num++;
            continue;
        }
        for (int i = 0; i < 3;i++){
            int fut_location;
            if (i == 2)
                fut_location = cur_location * three[i];
            else
                fut_location = cur_location + three[i];
            if(0<= fut_location && fut_location <=100000){

                if (che_visit[fut_location] == 0)
                { // 첫 방문 시
                    che_visit[fut_location] = che_visit[cur_location] + 1;
                    arr.push({cnt + 1, fut_location});
                }
                else if(che_visit[fut_location] == (che_visit[cur_location]+1)){
                    arr.push({cnt + 1, fut_location});
                }
            }
        }
    }
    cout << che_visit[K] - 1 << "\n";
    cout << count_num << "\n";
    return 0;
}
