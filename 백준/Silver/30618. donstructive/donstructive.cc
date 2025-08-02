#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;

    vector<int> arr(N + 1, 0);

    int start_point = N / 2 + 1;

    int num = N;

    // 경계는 1 ~ N 까지
    int cnt = 1;
    while (num != 0)
    {
        arr[start_point] = num;
        num--;
        start_point = start_point + (pow(-1, cnt) * cnt);
        cnt++;
    }
    for (int i = 1; i <= N; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}