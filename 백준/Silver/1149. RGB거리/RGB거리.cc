#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector <vector<int>> arr(2, vector<int>(3, 0));
int N;
//1번 집은 2번집의 색과 같지 않아야한다.
//N번 집은 N-1 번집과 색이 같지 않아야한다.
//i번 집의 색은 i-1 번 i+1 번 집과 색이 달라야한다.
//비용의 최소값을 고르자.
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	arr.resize(N,vector<int>(3,0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}
	vector<vector<int>> dp(N, vector<int>(3, 0));
	dp[0][0] = arr[0][0];
	dp[0][1] = arr[0][1];
	dp[0][2] = arr[0][2];
	for (int i = 1; i < N; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
	}
	cout << min({ dp[N - 1][0], dp[N - 1][1], dp[N - 1][2] }) << "\n";
	return 0;
	
}