#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, R;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> R; // N 이 세로 , M 이 가로
    vector<int> arr[N];
    for (int i = 0; i < N;i++){
        for (int j = 0; j < M;j++){
            int num;
            cin >> num;
            arr[i].push_back(num);
        }
    }
    int cnt = min(N, M) / 2;
    vector<int> answer[cnt];
    int max_y = N, max_x = M;
    int min_y = 0, min_x = 0;
    int y = 0, x = 0;
    for (int i = 0; i < cnt; i++)
    {
        y = x = i;
        answer[i].push_back(arr[y][x]);
        for (int j = 0; j < 4; j++)
        {
            while(true){
                int ny = y + dy[j];
                int nx = x + dx[j];
                if(ny < min_y || nx < min_x || ny >= max_y || nx >= max_x){
                    break;
                }
                y = ny;
                x = nx;
                answer[i].push_back(arr[y][x]);
            }
        }
        answer[i].pop_back();
        max_y--;
        max_x--;
        min_y++;
        min_x++;
    }
    max_y = N, max_x = M;
    min_y = 0, min_x = 0;
    for (int i = 0; i < cnt; i++)
    {
        y = x = i;
        int arr_size = answer[i].size();
        int num = ((arr_size - R) % arr_size) + arr_size;
        num = num % arr_size;
        for (int j = 0; j < 4; j++)
        {
            while (true)
            {
                int ny = y + dy[j];
                int nx = x + dx[j];
                if (ny < min_y || nx < min_x || ny >= max_y || nx >= max_x)
                {
                    break;
                }
                y = ny;
                x = nx;
                num++;
                arr[y][x] = answer[i][(num) % answer[i].size()];
            }
        }
        //arr[y][x] = answer[i][num];
        max_y--;
        max_x--;
        min_y++;
        min_x++;
    }
    for(vector<int> row : arr){
        for(int num : row)
            cout << num << " ";
        cout << "\n";
    }
    return 0;
}