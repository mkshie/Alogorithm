#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// r은 행의 번호
// c는 열의 번호 -> 번호 시작 1부터

// (n-1 , n-1 ) 로이동시키는 방법의 경우의 수

// 가로인 경우 , 세로인 경우 , 대각선인 경우... -> 3가지의 경우의 수 존재

int N;
vector<vector<int>> arr;
int dp[17][17][3];

// dir -> 0 가로 1 세로 2 대각선

bool check_go(int r, int c, int dir, int will_dir)
{
    // 먼저 방향에서 그 방향으로 가능한지 check
    // 가로에서 -> 세로 x
    // 세로에서 -> 가로 x

    if (dir == 0 && will_dir == 1)
        return false;

    if (dir == 1 && will_dir == 0)
        return false;

    if (will_dir == 0)
    {
        if (c + 1 > N || arr[r][c + 1] == 1)
            return false;
        return true;
    }

    if (will_dir == 1)
    {
        if (r + 1 > N || arr[r + 1][c] == 1)
            return false;
        return true;
    }

    if (will_dir == 2)
    {
        if (r + 1 > N || c + 1 > N)
            return false;
        if (arr[r + 1][c] == 1 || arr[r][c + 1] == 1 || arr[r + 1][c + 1])
            return false;

        return true;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    arr = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int num;
            cin >> num;

            arr[i][j] = num;
        }
    }

    dp[1][2][0] = 1; // 머리가 1,2 이면서 0 가로 방향

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (dp[i][j][k] == 0)
                    continue;

                for (int p = 0; p < 3; p++)
                {
                    if (check_go(i, j, k, p))
                    {
                        if (p == 0)
                            dp[i][j + 1][p] += dp[i][j][k];
                        if (p == 1)
                            dp[i + 1][j][p] += dp[i][j][k];
                        if (p == 2)
                            dp[i + 1][j + 1][p] += dp[i][j][k];
                    }
                }
            }
        }
    }

    int answer = 0;

    for (int i = 0; i < 3; i++)
    {
        answer += dp[N][N][i];
    }

    cout << answer << "\n";
}