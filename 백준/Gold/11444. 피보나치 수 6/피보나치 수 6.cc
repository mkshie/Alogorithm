#include <algorithm>
#include <iostream>

using namespace std;

long int mod_num = 1000000007;

vector<vector<long long int>> matrix_mul(vector<vector<long long int>> A, vector<vector<long long int>> B)
{
    vector<vector<long long int>> result(2, vector<long long int>(2, 0));
    for (int i = 0; i < 2; i++)
    { // 행
        for (int j = 0; j < 2; j++)
        { // 열
            for (int k = 0; k < 2; k++)
            { // 곱하는곳의 열
                result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % mod_num;
                //result[i][j] = result[i][j] % mod_num;
            }
        }
    }
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long int n;
    cin >> n;

    vector<vector<long long int>> arr = {{1, 1}, {1, 0}};
    vector<vector<long long int>> answer = {{1, 0}, {0, 1}};
    while (n > 0)
    {
        if(n % 2 == 1){
            answer = matrix_mul(answer, arr);
        }
        arr = matrix_mul(arr, arr);
        n = n / 2;
    }

    cout << answer[1][0] << "\n";

    return 0;
}