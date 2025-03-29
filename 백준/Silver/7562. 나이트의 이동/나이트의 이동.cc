#include <queue>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int l;

int arr[300][300] = {0};
int finish_y, finish_x;

int bfs(int start_x , int start_y){
    if(start_x == finish_x && start_y == finish_y)
        return 0;
    queue<pair<int, int>> q;
    q.push({start_x,start_y});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 8;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= l || ny < 0 || ny >= l){ // 범위 넘어가는 경우
                continue;
            }
            if(arr[ny][nx] == 0) //처음 이동하는 곳인 경우
            {
                arr[ny][nx] = arr[y][x] + 1;
                q.push({nx, ny});
            }
        }
    }
    return arr[finish_y][finish_x];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> l;
        int start_y, start_x;
        cin >> start_y >> start_x;
        cin >> finish_y >> finish_x;
        cout << bfs(start_x, start_y)<<"\n";
        memset(arr, 0, sizeof(arr));
    }
}