#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

int K;

void rec(int cnt ,int start, int dest){
    int rec_cnt = cnt;
    for (int i = 0; i < rec_cnt; i++)
    {
        int nxt_dest = 6 - (start + dest);
        if (cnt != 1)
        {
            rec(cnt - 1, start, nxt_dest);
        }
        cout << start << " " << dest << "\n";
        start = nxt_dest;
        cnt--;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    cin >> K;
    cout << (int)pow(2, K) - 1 << "\n";
    rec(K, 1, 3); // 목적지
    return 0;
}