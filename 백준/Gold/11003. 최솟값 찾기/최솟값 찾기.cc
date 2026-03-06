#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, L;

    cin >> N >> L;

    vector<int> arr;

    for (int i = 0; i < N; i++)
    {
        int num;

        cin >> num;

        arr.push_back(num);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> answer;

    for (int i = 0; i < arr.size(); i++)
    {
        int left = i - L + 1, right = i;

        pq.push({arr[i], i});

        while (pq.top().second < left || pq.top().second > right)
        {
            pq.pop();
        }

        answer.push_back(pq.top().first);
    }

    for (int num : answer)
    {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}