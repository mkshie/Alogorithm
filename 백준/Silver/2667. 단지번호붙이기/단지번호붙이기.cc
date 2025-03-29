#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int arr[25][25] = {0};
vector<int> answers;
int cnt = 0;
int mx[4] = {1, 0, -1, 0}; // 열
int my[4] = {0, 1, 0, -1}; //행

void dfs(int y, int x){
    if(arr[y][x] == 0)
        return;
    arr[y][x] = 0;
    cnt++;
    for (int i = 0; i < 4;i++){
        if (y + my[i] < N && y + my[i] >= 0 && x + mx[i] < N && x + mx[i] >=0){
            dfs(y + my[i], x + mx[i]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N;i++){
        string str1;
        cin >> str1;
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = str1[j] - '0';
        }
    }
    for (int dx = 0; dx < N; dx++)
    {
        for (int dy = 0; dy < N; dy++)
        {
            if(arr[dy][dx] != 0)
            {
                dfs(dy, dx);
                answers.push_back(cnt);
            }
            cnt = 0;
        }
    }
    sort(answers.begin(), answers.end());
    cout << answers.size() << "\n";
    for (int answer : answers)
        cout << answer << "\n";
    cout << "\n";
}