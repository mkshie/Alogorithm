#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

int N; // 세로
int M; // 가로

// 문제 접근을 아예 잘못함 다시 풀어야할듯 (bfs 로 다시 풀어보자) -> 가로막혀있는 블록은 0블록이 있어도 안됨.

vector<vector<int>> arr;
stack<pair<int, int>> st;

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    arr = vector<vector<int>>(N, vector<int>(M, 0));
    vector<vector<int>> cheese(N, vector<int>(M, 0));

    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int num;
            cin >> num;

            arr[i][j] = num;
            if (num)
            {
                cnt++;
            }
        }
    }

    queue<pair<int, int>> q;

    int answer = cnt;
    int answer_time = 0;

    while (cnt != 0)
    {
        q.push({0, 0});
        cheese[0][0] = 1;
        while (!q.empty())
        {
            int y = q.front().first, x = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny >= N || ny < 0 || nx >= M || nx < 0)
                    continue;

                if (cheese[ny][nx])
                    continue;

                cheese[ny][nx] = 1;

                if (arr[ny][nx] == 1)
                {
                    st.push({ny, nx});
                }
                else
                {
                    q.push({ny, nx});
                }
            }
        }

        cnt = cnt - st.size();
        if (cnt != 0)
        {
            answer = cnt;
        }
        answer_time++;

        while (!st.empty())
        {
            arr[st.top().first][st.top().second] = 0;
            st.pop();
        }

        cheese.assign(N, vector<int>(M, 0));
    }

    cout << answer_time << "\n"
         << answer << "\n";
}