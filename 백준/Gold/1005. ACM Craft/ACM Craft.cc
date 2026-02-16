#include <iostream>
#include <algorithm>

using namespace std;

int T;       // 총 테스트 케이스 수
int N, K, W; // 건물의 개수 , 순서 규칙 , 지어야되는 건물
vector<int> build_time;
vector<vector<int>> build_option;
vector<int> dp;

int cal_dp(int x)
{
    if (dp[x] != -1) // 이미 계산해둔곳
        return dp[x];

    if (build_option[x].size() == 0)
    {
        dp[x] = build_time[x]; // 조건이 없다면 바로 짓고 돌려보내기
        return dp[x];
    }

    int max_time = 0;

    for (int i = 0; i < build_option[x].size(); i++)
    {
        int pre_building = build_option[x][i]; // 이전에 지어야하는 건물
        max_time = max(max_time, cal_dp(pre_building));
    }

    dp[x] = max_time + build_time[x];

    return dp[x];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    while (T--)
    {
        cin >> N >> K;

        build_time.assign(N + 1, 0);
        build_option.assign(N + 1, {});
        dp.assign(N + 1, -1);

        for (int i = 0; i < N; i++)
        {
            cin >> build_time[i + 1];
        }

        for (int i = 0; i < K; i++)
        {
            int X, Y;
            cin >> X >> Y;

            build_option[Y].push_back(X); // 인접 리스트
        }
        cin >> W;

        cout << cal_dp(W) << "\n";

        // W 를 짓기위해서 필요한 애들중 최대값만 더해주면 됨(5번을 짓기위해서 )
        // top-down 형식으로 구현해보자
    }

    return 0;
}