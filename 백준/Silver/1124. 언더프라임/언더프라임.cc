#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr(100001, 1);
vector<int> answer(100001, 1);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 2; i < 50001; i++)
    {
        for (int j = 2; i * j <= 100000; j++)
        {
            arr[i * j] = max(j, arr[i * j]); // arr[i] == 1 이라면 소수라는 뜻
        }
    }

    arr[1] = 0;

    for (int i = 4; i <= 100000; i++)
    {
        int n = i;
        int cnt = 0;
        for (int j = 2; j * j <= n; j++)
        {
            while (n % j == 0)
            {
                cnt++;
                n /= j;
            }
        }
        if (n > 1)
            cnt++;

        answer[i] = cnt;
    }

    int A, B;

    cin >> A >> B;

    int sum = 0;

    for (int i = A; i <= B; i++)
    {
        if (arr[answer[i]] == 1)
        {
            sum++;
        }
    }

    cout << sum << "\n";

    return 0;

    // 소인수 분해... 소인수 분해 후 길이가 소수인지를 확인해야함
}