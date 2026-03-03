#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 최대 치킨집 개수가 주어짐

// 현재 치킨집개수를 확인하는게 우선?
// 모든 경우의 수 돌려도 괜찮을 듯 함
// 치킨 집 벡터 (이차원)
// 집 벡터 (이차원)
// 치킨집과 집 사이의 거리 벡터 이차원벡터

int N, M; // M 은 집의 개수

vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<vector<int>> chicken_dist; // 치킨 거리 모음 chicken_dist[i][j] = i 번째 집과 j 번째 집과의 치킨 거리

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int num;
            cin >> num;

            if (num == 1)
            {
                house.push_back({i, j});
            }
            else if (num == 2)
            {
                chicken.push_back({i, j});
            }
        }
    }

    chicken_dist.resize(house.size());

    for (int i = 0; i < house.size(); i++)
    {
        int cur_y = house[i].first;
        int cur_x = house[i].second;
        for (int j = 0; j < chicken.size(); j++)
        {
            int chi_y = chicken[j].first;
            int chi_x = chicken[j].second;
            int dist = abs(cur_y - chi_y) + abs(cur_x - chi_x);
            chicken_dist[i].push_back(dist);
        }
    }

    vector<int> per(chicken.size(), 0);
    for (int i = 0; i < M; i++)
    {
        per[i] = 1;
    }

    sort(per.begin(), per.end());

    int answer = 99999999;
    do
    {
        // 여기서 치킨 거리들을 확인해야함
        int sum = 0;
        for (int i = 0; i < chicken_dist.size(); i++)
        {
            int min_chi = 9999999;
            for (int j = 0; j < chicken_dist[i].size(); j++)
            {
                if (per[j] == 0)
                    continue;

                min_chi = min(min_chi, chicken_dist[i][j]);
            }
            sum += min_chi;
        }
        answer = min(answer, sum);

    } while (next_permutation(per.begin(), per.end()));

    cout << answer << "\n";
    return 0;
}