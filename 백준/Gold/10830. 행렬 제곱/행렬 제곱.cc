#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long int N, B;
vector<vector<int>> A;

vector<vector<int>> matrix_mul(vector<vector<int>> A , vector<vector<int>> B){
    vector<vector<int>> result(N, vector<int>(N, 0));
    for (int i = 0; i < N;i++){ // 행
        for (int j = 0; j < N;j++){ //열
            for (int k = 0; k < N;k++){ // 곱하는곳의 열
                result[i][j] += (A[i][k] * B[k][j]) % 1000;
                result[i][j] = result[i][j] % 1000;
            }
        }
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> B;
    A = vector<vector<int>>(N, vector<int>(N, 0));
    for (int i = 0; i < N;i++){
        for (int j = 0; j < N;j++){
            cin >> A[i][j];
        }
    }
    vector<vector<int>> answer(5, vector<int>(5, 0));
    for (int i = 0; i < N;i++)
    {
        answer[i][i] = 1;
    }
    while(B > 0){
        if(B % 2 == 1){ // 해당 값을 곱해줘야한다면?
            answer = matrix_mul(answer, A);
        }
        A = matrix_mul(A, A);
        B = B / 2;
    }
    for (int i = 0; i < N;i++){
        for (int j = 0; j < N;j++){
            cout << answer[i][j] << " ";
        }
        cout << "\n";
    }
        return 0;
}