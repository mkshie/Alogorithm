#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long count(long long x, long long N) {
    long long sum = 0;
    for (int i = 1; i < N+1; i++) {
        sum += min(x / i, N);
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, k;
    cin >> N >> k;

    long long left = 1, right = N * N;
    long long mid;
    while (left <= right) {
        mid = (left + right) / 2;
        long long cnt = count(mid,N);
        if (k > cnt) {
            left = mid + 1;
        }
        else if(k <= cnt)
        {
            right = mid - 1;
        }
    }
    cout << left;

    return 0;
}
