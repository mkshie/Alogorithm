#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;                               // N이 세로 , M이 가로
int arr[10][10];                        // 섬을 나타내는 배열i
bool visited[10][10] = {false};         // 섬 검사시 확인할 배열
vector<int> parents;                    // 부모가 몇번인지 나타내는 백터
vector<pair<int, pair<int, int>>> path; // 다리의 종류
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void dfs(int y, int x, int cnt)
{
    arr[y][x] = cnt;
    visited[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= M) // 경계 검사
            continue;
        if (arr[ny][nx] == 0 || arr[ny][nx] == cnt) // 만약 섬이 아닌 부분이거나 , 이미 내가 원하는 값으로 수정이 되어있는 경우에는 갈 필요 없음
            continue;
        dfs(ny, nx, cnt);
    }
}

void buildBridge(int y, int x)
{
    visited[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= M) // 경계 검사
            continue;
        if (arr[ny][nx] == 0)
        { // 한쪽 방향이 비어있다면.
            int nny = ny + dy[i];
            int nnx = nx + dx[i];
            for (int j = 1; j <= 8; j++)
            {                                               // j 는 다리의 길이
                if (nny < 0 || nnx < 0 || nny >= N || nnx >= M) // 경계 검사
                    break;
                if(j==1 && arr[nny][nnx] != 0) // 다리의 길이가 1인데 섬을 만났다면 해당 다리는 존재하면 안됨
                    break;
                if (arr[nny][nnx] != 0)
                {                                                    // 섬이라면
                    path.push_back({j, {arr[y][x], arr[nny][nnx]}}); // 길 삽입해주기
                    break;
                }
                nny += dy[i];
                nnx += dx[i];
            }
        }
        if (arr[ny][nx] == 0 || visited[ny][nx]) // 섬이 아니거나 이미 방문한곳이라면 갈 필요 없음
            continue;
        buildBridge(ny, nx);
    }
}

int find(int u)
{
    if (parents[u] == u)
        return u;
    return parents[u] = find(parents[u]);
}

bool merge(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return false;
    parents[u] = v;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int num = 0;
            cin >> num;
            if(num == 1)
                arr[i][j] = 9;
            else
                arr[i][j] = num;
        }
    }
    // 문제 푸는 방식 고민
    // 먼저 각각의 섬들을 숫자를 매기자.
    int cnt = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] == 9 && !visited[i][j])
            {
                dfs(i, j, cnt);
                cnt++;
            }
        }
    }
    parents = vector<int>(cnt, 0); // cnt 값 즉 하나 더 크게 만들어짐
    for (int i = 1; i < cnt; i++)
    {
        parents[i] = i; // 초기값 설정
    }

    for (int i = 0; i < 10; i++) // 방문 배열 초기화
        for (int j = 0; j < 10; j++)
            visited[i][j] = false;

    for (int i = 0; i < N; i++) // 다리 만드는 과정
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] != 0 && !visited[i][j])
                buildBridge(i, j);
        }
    }
    sort(path.begin(), path.end());
    cnt--;
    int edge_num = 0;
    int result = 0;
    for (int i = 0; i < path.size(); i++)
    {
        if (edge_num == cnt - 1)
            break;
        int u = path[i].second.first;
        int v = path[i].second.second;
        int dist = path[i].first;
        if (merge(u, v))
        {
            result += dist;
            edge_num++;
        }
    }
    int parent = find(1);
    for (int i = 2; i <= cnt; i++)
    {
        if (parent != find(i))
        {
            cout << "-1\n";
            return 0;
        }
    }
    cout << result << "\n";
    return 0;
}