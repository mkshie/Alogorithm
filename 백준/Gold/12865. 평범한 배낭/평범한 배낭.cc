#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, K;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	vector<pair<int, int>> arr(N+1, { 0,0 });
	for (int i = 1; i <= N; i++) {
		cin >> arr[i].first;
		cin >> arr[i].second;
	}
	vector<vector<int>> dp (N + 1, vector<int>(K + 1, 0));//[i][w] => i 번째 물건을 담을때 w 는 가방의 용량의 최대 가치.
	for (int i = 1; i <= N; i++) {
		int iw = arr[i].first; // 무게
		int iv = arr[i].second; // 가치
		for (int w = 1; w <= K; w++) {
			if (iw > w) { // 해당 물건이 현재 배낭보다 크다면?
				dp[i][w] = dp[i - 1][w];
			}
			else if (iw <= w) {
				dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - iw]+iv); // 해당 물건을 넣지 않는경우와 해당 물건을 넣었을때를 비교(물건을 넣으려면 가방에서 그만 큼 무게를 뺏을때의
				//최대값으로 비교해야하기때문
			}
		}
	}
	cout << dp[N][K];
}