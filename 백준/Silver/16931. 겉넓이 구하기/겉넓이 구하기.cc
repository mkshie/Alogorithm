#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<int> arr[N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int num;
            cin >> num;
            arr[i].push_back(num);
        }
    }
    int answer = N * M;
    for (int i = 0; i < N; i++) // 가로의 넓이
    {
        int right_max = arr[i][0];
        answer += right_max;
        for (int j = 1; j < M; j++)
        {
            if(arr[i][j] > arr[i][j-1]){
                answer += arr[i][j] - arr[i][j - 1];
                right_max = max(right_max, arr[i][j]);
            }
        }
    }
    for (int j = 0; j < M; j++) //세로의 넓이
    {
        int left_max = arr[0][j];
        answer += left_max;
        for (int i = 1; i < N;i++){
            if (arr[i][j] > arr[i -1][j])
            {
                answer += arr[i][j] - arr[i -1][j];
                left_max = max(left_max, arr[i][j]);
            }
        }
    }
    cout << answer * 2 << "\n";
    return 0;
}