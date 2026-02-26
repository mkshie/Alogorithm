#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < N; i++)
    {
        int num;

        cin >> num;

        pq.push(num);
    }

    int answer = 0;

    while (pq.size() != 1)
    {
        int num = pq.top();
        pq.pop();

        num += pq.top();
        pq.pop();

        answer += num;

        pq.push(num);
    }

    cout << answer << "\n";

    return 0;
}