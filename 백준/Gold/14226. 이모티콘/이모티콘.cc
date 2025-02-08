#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

//이번 문제는 pair 로 풀기에는 너무 복잡해진다.
//tuple 자료형을 사용해서 현재 이모티콘 개수 , 클립보드 , 시간초 이렇게 세개를 한번에 다뤄서 문제를 풀어야 편하게 풀 수 있다.
//그게 아니라면 해당 지점에 도착했을때의 클립보드 별로 나눠야하기때문에 2차원 벡터를 사용해서 방문 여부를 파악해줘야한다.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;

    cin >> n;

    vector<bool> visit(3001, false);

    queue<tuple<int, int, int>> q;

    q.push({1, 0, 0});

    while (!q.empty())
    {

        auto qCh = q.front();
        int cur = get<0>(qCh);
        int prev = get<1>(qCh);
        int third = get<2>(qCh);
        q.pop();

        if (cur == n)
        {
            cout << third;
            return 0;
        }

        if (!visit[cur])
        {
            visit[cur] = 1;
            q.push({cur, cur, third + 1});
        }

        if (cur + prev <= 3000)
        {
            q.push({cur + prev, prev, third + 1});
        }

        if (cur - 1 >= 0)
        {
            q.push({cur - 1, prev, third + 1});
        }
    }
    return 0;
}