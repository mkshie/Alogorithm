// 14336번: 이모티콘
// 모르겠다 ......
/*

2<=S<=1000

*/

#include <iostream>
#include <queue>
using namespace std;

int s;

int dist[2001][2001]; // 넉넉하게 2000으로함.
bool che_visit[2001][2001];
queue<pair<int, int>> q;

void bfs()
{

    dist[1][0] = 0;
    che_visit[1][0] = true;
    q.push(make_pair(1, 0));

    while (!q.empty())
    {
        int cur_display = q.front().first;
        int cur_clip = q.front().second;
        q.pop();

        for (int i = 0; i < 3; i++)
        {
            int next_display, next_clip;

            if (i == 0)
            { // 1.화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장 (a,b)->(a,a)
                next_display = cur_display;
                next_clip = cur_display;
            }
            else if (i == 1)
            { // 2. 클립보드에 있는 모든 이모티콘을 화면에 붙여넣기 한다 (a,b)->(a+b,b)
                next_display = cur_display + cur_clip;
                next_clip = cur_clip;
            }
            else
            { // 3. 화면에 있는 이모티콘 중 하나를 삭제한다. (a,b)->(a-1,b)
                next_display = cur_display - 1;
                next_clip = cur_clip;
            }

            if (next_display >= 0 && next_clip >= 0 && next_display <= 2000 && next_clip <= 2000)
            {
                if (che_visit[next_display][next_clip] == false)
                {
                    dist[next_display][next_clip] = dist[cur_display][cur_clip] + 1;
                    che_visit[next_display][next_clip] = true;
                    q.push(make_pair(next_display, next_clip));
                }
            }
        }
    }
}

int main()
{
    cin >> s;
    bfs();
    int answer = -1;
    for (int i = 0; i < 2000; i++)
    {
        if (che_visit[s][i] == true)
        {
            if (answer == -1 || answer > dist[s][i])
            {
                answer = dist[s][i];
            }
        }
    }

    cout << answer << "\n";
}