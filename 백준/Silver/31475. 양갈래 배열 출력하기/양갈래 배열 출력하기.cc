#include <iostream>
#include <vector>

using namespace std;

int N; // 세로
int M; // 가로

// 방향은 처음과 같음 결국엔

vector<vector<int>> arr;

vector<vector<int>> dy(2, vector<int>(4));
vector<vector<int>> dx(2, vector<int>(4));

char start_point;

void dfs(int num, int y, int x, int dir, int idx)
{
    if (y >= N || y < 0 || x >= M || x < 0)
    {
        return;
    }
    if (arr[y][x] != 0)
    {
        return;
    }

    while (true)
    {
        arr[y][x] = num;
        num++;

        y += dy[dir][idx];
        x += dx[dir][idx];

        if (y >= N || y < 0 || x >= M || x < 0)
            break;
        if (arr[y][x] != 0)
            break;
    }

    y -= dy[dir][idx];
    x -= dx[dir][idx];

    idx++;

    if (idx >= 4)
        idx = 0;

    y += dy[dir][idx];
    x += dx[dir][idx];

    dfs(num, y, x, dir, idx);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    cin >> start_point;

    arr = vector<vector<int>>(N, vector<int>(M, 0));

    int start_x, start_y;
    int mid_x, mid_y;
    int mid_num;

    if (start_point == 'U')
    {
        start_x = M / 2;
        start_y = 0;
        mid_y = N - 1, mid_x = start_x;
        mid_num = N;

        dy[0] = {1, 0, -1, 0};
        dy[1] = {1, 0, -1, 0};
        dx[0] = {0, 1, 0, -1};
        dx[1] = {0, -1, 0, 1};
    }
    else if (start_point == 'D')
    {
        start_x = M / 2;
        start_y = N - 1;
        mid_x = start_x, mid_y = 0;
        mid_num = N;

        dy[0] = {-1, 0, 1, 0};
        dy[1] = {-1, 0, 1, 0};
        dx[0] = {0, 1, 0, -1};
        dx[1] = {0, -1, 0, 1};
    }
    else if (start_point == 'R')
    {
        start_x = M - 1;
        start_y = N / 2;
        mid_x = 0, mid_y = start_y;
        mid_num = M;

        dy[0] = {0, 1, 0, -1};
        dy[1] = {0, -1, 0, 1};
        dx[0] = {-1, 0, 1, 0};
        dx[1] = {-1, 0, 1, 0};
    }
    else if (start_point == 'L')
    {
        start_x = 0;
        start_y = N / 2;
        mid_x = M - 1, mid_y = start_y;
        mid_num = M;

        dy[0] = {0, 1, 0, -1};
        dy[1] = {0, -1, 0, 1};
        dx[0] = {1, 0, -1, 0};
        dx[1] = {1, 0, -1, 0};
    }

    dfs(1, start_y, start_x, 0, 0);
    arr[mid_y][mid_x] = 0;
    dfs(mid_num, mid_y, mid_x, 1, 0);

    for (vector<int> ar : arr)
    {
        for (int num : ar)
        {
            cout << num << " ";
        }
        cout << "\n";
    }

    return 0;
}