#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>
#include <vector>

using namespace std;

// 슬라이딩 윈도우 기법으로 문제를 풀어보자 우선순위큐는 출제자의 의도와 조금 다름
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

    deque<pair<int, int>> dq;
    vector<int> answer;

    for (int i = 0; i < arr.size(); i++)
    {
        int left = i - L + 1, right = i;

        if (!dq.empty())
        {
            while (!dq.empty() && dq.back().first > arr[i])
            {
                dq.pop_back();
            }
            dq.push_back({arr[i], i});
        }
        else
        { // 비어있다면 일단 넣어주기
            dq.push_back({arr[i], i});
        }

        if (dq.front().second < left || dq.front().second > right)
        {
            dq.pop_front();
        }

        cout << dq.front().first << " ";
    }
    cout << "\n";

    return 0;
}

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int N, L;

//     cin >> N >> L;

//     vector<int> arr;

//     for (int i = 0; i < N; i++)
//     {
//         int num;

//         cin >> num;

//         arr.push_back(num);
//     }

//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

//     vector<int> answer;

//     for (int i = 0; i < arr.size(); i++)
//     {
//         int left = i - L + 1, right = i;

//         pq.push({arr[i], i});

//         while (pq.top().second < left || pq.top().second > right)
//         {
//             pq.pop();
//         }

//         answer.push_back(pq.top().first);
//     }

//     for (int num : answer)
//     {
//         cout << num << " ";
//     }
//     cout << "\n";

//     return 0;
// }