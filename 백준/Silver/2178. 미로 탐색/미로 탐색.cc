#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

int N,M;
int arr[101][101] = {0};
int answer = 999999;
int cnt = 0;
int mx[4] = {1, 0, -1, 0}; // 열
int my[4] = {0, 1, 0, -1}; // 행

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        string str1;
        cin >> str1;
        for (int j = 0; j < M; j++)
        {
            arr[i][j] = str1[j] - '0';
        }
    }
    priority_queue<tuple<int,int,int>> pq;
    pq.push({-1, 0, 0});
    arr[0][0] = 0;
    while (!pq.empty())
    {
        int cnt = abs(get<0>(pq.top()));
        int y = get<1>(pq.top());
        int x = get<2>(pq.top());
        pq.pop();
        if(y == N-1 && x == M-1){
            answer = min(answer, cnt);
            continue;
        }
        for (int i = 0; i < 4; i++)
        {
            if (y + my[i] < N && y + my[i] >= 0 && x + mx[i] < M && x + mx[i] >= 0)
            {
                if(arr[y+my[i]][x+mx[i]] == 1){
                    pq.push({-1*(cnt + 1), y + my[i], x + mx[i]});
                    arr[y + my[i]][x + mx[i]] = 0;
                }
            }
        }
    }
    cout << answer << "\n";
}