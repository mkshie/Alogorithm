#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// N * N 의 크기의 공간에 물고기 M 마리와 아기 상어 1마리가 존재함 . 공간은 1*1 크기의 정사각형 칸으로 존재
//  아기 상어는 자신보다 크기가 큰 물ㄱ기는 먹을 수 없음. 하지만 크기가 각거나 작은 애들은 지나가거나 먹ㄷ을 수 있음

// 아기상어의 이동 방법
// 더 이상 먹을 수 없다면 도움 요청
// 물고기가 1마리라면 그 물고기를 먹ㄷ으러감
// 1마리보다 많다면 거리가 가장 가까운 물고기를 먹으러 감 --> 거리는 아기 상어가 있는 칸에서 지나가야하는 칸의 개수의 최솟값
// 가까운 물고기 여러마리라면 위에 있고 그중 제일 왼쪽의 물고기를 먹음
// 또한 아기상어의 크기가 2라면 물고기를 2마리 먹어야 3이 된다.

// 즉 이동방향은 위 -> 왼 -> 오 - > 아래 순으로 이동하는게 좋을 듯..? 내가 이동한곳이라면 넣지 말고...
// 우선순위 큐 사용해서 dfs 를 계속 돌리는 방식으로 하면 안되나?

// 즉 먼저 시작점을 두고 dfs 시작 dfs 는 우선순위 큐를 사용
// 위 , 왼 , 오 , 아래 순으로 순회를 돌면서 제일 가까운 곳에 내가 먹을 수 있는 물고기가 존재한다면 해당 물고기를 먹음
// 물고기를 먹고나면 큐 초기화후 현재 위치를 넣고 다시 dfs 시작하는 방식 visited 도 초기화 하기

int N;                 // 바다의 크기 최대 20
int babySharksize = 2; // 기본 아기상어의 크기
int needCnt = 2;       // 아기 상어가 더 커지기 위해 남은 물고기 수

int answer = 0;

int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, -1, 1, 0};

struct Cmp
{
    bool operator()(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b)
    {
        // ture a 의 우선순위가 낮다는 뜻 즉 작은값이 top 에 오게 됨
        if (a.first == b.first)
        {
            if (a.second.first == b.second.first)
                return a.second.second > b.second.second;
            return a.second.first > b.second.first;
        }
        return a.first > b.first;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    vector<vector<int>> arr(N, vector<int>(N, 0));

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<bool>> visited(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 9)
            {
                pq.push({0, {i, j}}); // 초기 위치 삽입
                visited[i][j] = true;
                arr[i][j] = 0;
            }
        }
    }

    // cout << "\n";

    while (!pq.empty())
    { // q 가 비어있지 않는 이상 계속 돌기
        int y, x, cnt;
        cnt = abs(pq.top().first);
        y = pq.top().second.first;
        x = pq.top().second.second;

        pq.pop();

        if (arr[y][x] < babySharksize && arr[y][x] != 0) // 현재 위치가 내가 먹을 수 있는 곳이라면
        {
            // 우선순위 큐 초기화
            pq = priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>();
            // 방문 위치 초기화
            for (int j = 0; j < N; j++)
            {
                fill(visited[j].begin(), visited[j].end(), false);
            }
            arr[y][x] = 0;
            answer = max(abs(cnt), answer);
            needCnt--;

            if (needCnt == 0)
            {
                babySharksize += 1;
                needCnt = babySharksize;
            }

            pq.push({cnt, {y, x}});
            visited[y][x] = true;

            continue;
        }

        int next_cnt = cnt + 1;
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= N || nx >= N || ny < 0 || nx < 0) // 범위 벗어나면 pass
                continue;

            if (visited[ny][nx])
                continue; // 이미 지나온 곳이라면 pass

            if (arr[ny][nx] > babySharksize) // 나보다 큰 물고기라면 pass
                continue;

            else if (arr[ny][nx] == babySharksize || arr[ny][nx] == 0)
            {
                visited[ny][nx] = true;
                pq.push({next_cnt, {ny, nx}});
            }
            else if (arr[ny][nx] < babySharksize)
            {

                pq.push({next_cnt, {ny, nx}}); // 먹을 수 있는 곳이여도 위의 제일 왼쪽이 있을 수 있으니 넣어두기만 하기
                visited[ny][nx] = true;

                // for (vector<int> check : arr)
                // {
                //     for (int num : check)
                //     {
                //         cout << num << " ";
                //     }
                //     cout << "\n";
                // }
                // cout << "이번에 먹은 위치 : " << ny << " " << nx << " " << answer << " " << babySharksize << "\n";
            }
        }
    }

    cout << answer << "\n";
}