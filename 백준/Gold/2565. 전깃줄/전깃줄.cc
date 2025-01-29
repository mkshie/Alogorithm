#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	vector<pair<int, int>> arr;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		arr.push_back({ x,y });
	}
	sort(arr.begin(), arr.end());
	vector<int> dp(N, 1);
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i].second > arr[j].second) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	int result = N - (*max_element(dp.begin(), dp.end()));
	cout << result;

}