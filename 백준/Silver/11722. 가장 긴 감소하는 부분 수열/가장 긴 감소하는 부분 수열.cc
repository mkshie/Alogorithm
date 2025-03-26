#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> arr;
    vector<int> dp(N, 1);
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] < arr[j]) // j 보다 arr[i] 가 더 작다면
            {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    int lis = *(max_element(dp.begin(), dp.end()));
    cout << lis << "\n";
}