#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, S;
vector<long long> arr_sum;

int find_minimum_sum(int i)
{ // 최소 길이의 값을 찾는 것

    if (S > arr_sum[N] - arr_sum[i - 1])
    { // 해당 행에서의 최대값보다 S 가 크다면 해당 행은 S 를 넘는 값이 없다는 의미
        return 0;
    }

    // 이분탐색 구현

    int left = i, right = N;
    int mid = (left + right) / 2;

    int min_size = 9999999;

    while (left <= right)
    {
        mid = (left + right) / 2;
        long long num = arr_sum[mid] - arr_sum[i - 1]; // i~mid 까지의 합

        if (num == S)
        {
            return mid - i + 1;
        }
        else if (num > S)
        {
            min_size = min(min_size, mid - i + 1);
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return min_size;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> S;

    // N길이의 수열에서 S 이상이 되는것중 가장 짧은 것의 길이를 구하기
    vector<int> arr;
    arr_sum = vector<long long>(N + 1, 0);

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        if (num >= S)
        {
            cout << "1\n";
            return 0;
        }

        arr.push_back(num);

        if (i == 0)
        {
            arr_sum[i + 1] = arr[i];
        }
        else
        {
            arr_sum[i + 1] = arr_sum[i] + arr[i];
        }
    }

    int answer = 0;

    for (int i = 1; i <= N; i++)
    {
        int num = find_minimum_sum(i);

        if (answer == 0)
            answer = num;
        else
        {
            if (num == 0)
                continue;
            else
                answer = min(answer, num);
        }
    }

    cout << answer << "\n";
    return 0;
}