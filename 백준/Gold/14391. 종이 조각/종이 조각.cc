#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
vector<vector<int>> arr;
vector<vector<bool>> visited;
vector<string> arr_str;

int sum = 0;
int answer = 0;

void rec(int dx , int dy , int cnt){
    if(cnt == N*M){
        for (string str : arr_str){
            sum += stoi(str);
        }
        answer = max(answer, sum);
        sum = 0;
        return;
    }
    for (int i = dy; i < N; i++){
        for (int j = dx; j < M; j++){
            if(!visited[i][j]){
                for (int k = 0; k + j < M; k++){
                    string str1 = "";
                    for (int p = 0; p <= k; p++)
                    {
                        if(visited[i][p+j]){ // 만약 중간에 방문했다면
                            break;
                        }
                        str1 += to_string(arr[i][p + j]);
                    }
                    if(str1.size() == k + 1){ // 만약 가로로 정한 크기를 다 채운경우
                        for (int p = 0; p <= k;p++)
                            visited[i][p + j] = true;
                        arr_str.push_back(str1);
                        rec(k + j + 1, i, cnt + k + 1);
                        for (int p = 0; p <= k; p++)
                            visited[i][p + j] = false;
                        arr_str.pop_back();
                    }
                }
                for (int k = 1; k + i < N; k++)
                {
                    string str1 = "";
                    for (int p = 0; p <= k; p++)
                    {
                        if (visited[i + p][j])
                        { // 만약 중간에 방문했다면
                            break;
                        }
                        str1 += to_string(arr[i + p][j]);
                    }
                    if (str1.size() == k + 1)
                    { // 만약 세로로 정한 크기를 다 채운경우
                        for (int p = 0; p <= k; p++)
                            visited[i + p][j] = true;
                        arr_str.push_back(str1);
                        rec(j + 1, i , cnt + k + 1);
                        for (int p = 0; p <= k; p++)
                            visited[i+p][j] = false;
                        arr_str.pop_back();
                    }
                }
            }
        }
        dx = 0;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    arr = vector<vector<int>>(N, vector<int>(M, 0));
    visited = vector<vector<bool>>(N, vector<bool>(M, false)); // false 가 방문하지 않은 상태
    for (int i = 0; i < N; i++)
    {
        string str1;
        cin >> str1;
        for (int j = 0; j < str1.size();j++)
            arr[i][j] = str1[j] - '0';
    }
    rec(0, 0, 0);
    cout << answer << "\n";
    return 0;
}