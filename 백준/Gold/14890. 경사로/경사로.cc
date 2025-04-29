#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, L; // 거리 크기 , 경사로 크기
vector<vector<int>> arr(100, vector<int>(100, 0)); // 지도
bool visited[100][100] = {true};
int answer = 0;

void row_check(int row ,int col){
    int cur_row = row;
    int cur_col = col;
    int ne_row = row;
    int ne_col = col + 1;
    while (true)
    {
        if(col == N-1){
            answer++;
            break;
        }
        if(col >= N || col < 0 || ne_col >= N || ne_col < 0) // 경계값 검사
            break;
        if (arr[row][col] == arr[row][ne_col]) // 높이가 같은지
        {
            col = ne_col;
            ne_col = col + 1;
            continue;
        }
        else if(abs(arr[row][col] - arr[row][ne_col]) == 1){ // 높이차가 1인 경우
            int num = arr[row][col] - arr[row][ne_col];
            if(num == 1){ // 나보다 다음칸이 작은 경우
                for (int i = 1; i < L;i++){
                    if(ne_col+i >= N) // 만약 경사로를 설치해야하는데 넘어간다면 return
                        return;
                    if (arr[row][ne_col + i - 1] == arr[row][ne_col + i]) // 높이가 같다면 다음 블록들 검사
                        continue;
                    else // 경사로 설치 검사를 하는데 높이가 다르다면 return
                        return;
                }
                col = col + L; // 경사로 길이만큼 다음칸
                for (int i = 0; i < L; i++)
                {
                    visited[row][col - i] = false;
                }
                ne_col = col + 1;
            }
            else{ // 나보다 다음칸이 높은 경우
                for (int i = 1; i < L;i++){
                    if(col - i < 0)
                        return;
                    if(arr[row][col - i + 1] == arr[row][col - i] && visited[row][col-i+1] && visited[row][col-i])
                        continue;
                    else
                        return;
                }
                if(L == 1 && !visited[row][col])
                    return;
                for (int i = 0; i < L; i++)
                {
                    visited[row][col - i] = false;
                }
                col = ne_col;
                ne_col = col + 1;
            }
        }
        else{ // 높이차가 1이 아닌경우
            return;
        }

    }
    return;
}
void col_check(int row , int col){
    int cur_row = row;
    int cur_col = col;
    int ne_row = row + 1;
    int ne_col = col;
    while (true)
    {
        if (row == N - 1)
        {
            answer++;
            break;
        }
        if (row >= N || row < 0 || ne_row >= N || ne_row < 0) // 경계값 검사
            break;
        if (arr[row][col] == arr[ne_row][col]) // 높이가 같은지
        {
            row = ne_row;
            ne_row = row + 1;
            continue;
        }
        else if (abs(arr[row][col] - arr[ne_row][col]) == 1)
        { // 높이차가 1인 경우
            int num = arr[row][col] - arr[ne_row][col];
            if (num == 1)
            { // 나보다 다음칸이 작은 경우
                for (int i = 1; i < L; i++)
                {
                    if (ne_row + i >= N) // 만약 경사로를 설치해야하는데 넘어간다면 return
                        return;
                    if (arr[ne_row + i - 1][col] == arr[ne_row + i][col]) // 높이가 같다면 다음 블록들 검사
                        continue;
                    else // 경사로 설치 검사를 하는데 높이가 다르다면 return
                        return;
                }
                row = row + L; // 경사로 길이만큼 다음칸
                for (int i = 0; i < L; i++)
                {
                    visited[row - i][col] = false;
                }
                ne_row = row + 1;
            }
            else
            {
                for (int i = 1; i < L; i++)
                {
                    if (row - i < 0)
                        return;
                    if (arr[row - i + 1][col] == arr[row - i][col] && visited[row-i+1][col] && visited[row-i][col])
                        continue;
                    else
                        return;
                }
                if (L == 1 && !visited[row][col])
                    return;
                for (int i = 0; i < L;i++){
                    visited[row - i][col] = false;
                }
                row = ne_row;
                ne_row = row + 1;
            }
        }
        else
        { // 높이차가 1이 아닌경우
            return;
        }
    }
    return;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> L;
    for (int i = 0; i < N;i++){
        for (int j = 0;j<N;j++){
            cin >> arr[i][j];
        }
    }
    fill(&visited[0][0], &visited[0][0] + 100 * 100, true);
    for (int i = 0; i < N;i++){
        row_check(i,0);
    }
    fill(&visited[0][0], &visited[0][0] + 100 * 100, true);
    for (int i = 0; i < N; i++)
    {
        col_check(0, i);
    }
    cout << answer << "\n";
}