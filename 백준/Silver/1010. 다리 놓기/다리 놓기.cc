#include <iostream>
#include <vector>
using namespace std;

// 동적 프로그래밍을 사용하여 조합 계산
unsigned long long nCr(int n, int r) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;
    
    vector<vector<unsigned long long>> C(n + 1, vector<unsigned long long>(r + 1, 0));
    
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= min(i, r); ++j) {
            if (j == 0 || j == i) {
                C[i][j] = 1;
            } else {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
    }
    
    return C[n][r];
}

int main() {
    int T;
    cin >> T;  // 테스트 케이스 수 입력
    
    while (T--) {
        int N, M;
        cin >> N >> M;  // 서쪽의 사이트 수 N, 동쪽의 사이트 수 M
        
        // 조합을 계산하여 출력
        cout << nCr(M, N) << endl;
    }
    
    return 0;
}
