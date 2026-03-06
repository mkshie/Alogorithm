#include <iostream>
#include <algorithm>
#include <sstream>
#include <queue>
#include <vector>

using namespace std;

// 중요 조건 끝타임이 시간이 작아야함.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    priority_queue<int, vector<int>, greater<int>> classrooms;

    for (int i = 0; i < N; i++)
    {
        int s, t;

        cin >> s >> t;

        pq.push({s, t});
    }

    classrooms.push(pq.top().second);
    pq.pop();

    while (!pq.empty())
    {

        int st_time = pq.top().first, end_time = pq.top().second;

        pq.pop();

        int cur_end_time = classrooms.top();

        if (cur_end_time <= st_time)
        {
            // 넣을 수 있다면
            classrooms.pop();
        }
        classrooms.push(end_time);
    }

    cout << classrooms.size() << "\n";

    return 0;
}