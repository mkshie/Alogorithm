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
    vector<bool> che_visit(100011, false);
    int cnt, cur_location;
    arr.push({0, N});
    che_visit[N] = true;
    while (!arr.empty())
    {
        cnt = arr.top().first;
        cur_location = arr.top().second;
        arr.pop();
        if(cur_location > 100010) continue;
        if (cur_location == K)
        {
            cout << cnt << "\n";
            break;
        }
        if (cur_location != 0)
        {
            if (cur_location * 2 <= 100010 && !che_visit[cur_location * 2])
            {
                arr.push({cnt, cur_location * 2});
                che_visit[cur_location * 2] = true;
            }
            if (!che_visit[cur_location - 1] && cur_location - 1 <= 100010)
            {
                arr.push({cnt + 1, cur_location - 1});
                che_visit[cur_location - 1] = true;
            }
        }
        if (cur_location + 1 <= 100000 && !che_visit[cur_location + 1])
        {
            arr.push({cnt + 1, cur_location + 1});
            che_visit[cur_location + 1] = true;
        }
    }
    return 0;
}
