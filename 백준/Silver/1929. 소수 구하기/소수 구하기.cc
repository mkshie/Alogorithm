#include <iostream>

using namespace std;

bool arr[1000001] = {0};

int main()
{
    cin.tie(NULL);
    int M, N;

    cin >> M >> N;
    for (int i = 2; i < 1000001; i++)
    {
        for (int j = 2; i * j <= N; j++)
        {
            arr[i * j] = true;
        }
    }
    arr[0] = arr[1] = true;

    for (int i = M; i <= N; i++)
    {
        if (!arr[i])
        {
            cout << i << "\n";
        }
    }

    return 0;
}